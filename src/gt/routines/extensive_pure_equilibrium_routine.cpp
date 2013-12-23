/**
 * @file      gt/routines/extensive_pure_equilibrium_routine.cpp
 * @brief     Defines GT::Routines::ExtensivePureEquilibriumRoutine methods.
 * @copyright (C) 2013-2014
 * @author    Mateusz Kubuszok
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero
 * General Public License as published by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License along with this program. If not,
 * see [http://www.gnu.org/licenses/].
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "gt/routines/inner_common.hpp"

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using boost::dynamic_pointer_cast;

using Model::ExtensiveDataAccessor;
using Model::ExtensiveDataAccessorPtr;
using Model::ExtensiveDataNode;
using Model::ExtensiveDataNodes;
using Model::ExtensiveGamePositionsHelper;
using Model::PlainDataPiece;
using Model::StrategicGamePositionsHelper;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExtensivePureEquilibriumRoutine : public Routine {
// public:

ResultPtr ExtensivePureEquilibriumRoutine::findResultFor(
    const GamePtr       game,
    const ConditionsPtr
) const {
    const ExtensiveDataAccessorPtr data =
        dynamic_pointer_cast<ExtensiveDataAccessor>(game->getData());

    if (!data) {
        static Identifier extensiveGameName("Extensive Game");
        throw ExceptionFactory::getInstance().invalidGameType(extensiveGameName);
    }

    const StrategicGamePositionsHelper strategicPositionsHelper(data->getPlayers());
    const ExtensiveGamePositionsHelper extensivePositionsHelper(data->getRoot());
    const ExtensiveDataNode&           root = *data->getRoot();
    ExtensivePureStrategyPath          resultPath(game->getPlayers());

    NumbersPtr finalPayoff = getBestPayoffWhen(
        strategicPositionsHelper,
        extensivePositionsHelper,
        root,
        resultPath
    );


    ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();

    static const IdentifierPtr pureStrategiesName = createIdentifierPtr("Pure Strategies");
    ResultBuilderPtr pureStrategiesResult = ResultFactory::getInstance().buildResult();
    for (const ExtensivePureStrategyPath::PlayersChoices::value_type& playerChoices :
        resultPath.getPlayersChoices()) {
        const IdentifierPtr playerName = createIdentifierPtr(playerChoices.first);

        ResultBuilderPtr playerChoiceResult = ResultFactory::getInstance().buildResult();
        for (const Positions::value_type& position : playerChoices.second) {
            const IdentifierPtr informationSet = createIdentifierPtr(position.first);
            const MessagePtr    strategy       = createMessagePtr(position.second);
            playerChoiceResult->addResult( informationSet, strategy );
        }
        const MessagePtr decisions = createMessagePtr(playerChoiceResult->build()->getResult());

        pureStrategiesResult->addResult( playerName, decisions );
    }
    const MessagePtr pureStrategies = createMessagePtr(pureStrategiesResult->build()->getResult());
    resultBuilder->addResult( pureStrategiesName, pureStrategies );

    static const IdentifierPtr finalPayoffName = createIdentifierPtr("Payoff");
    const MessagePtr finalPayoffResult = createMessagePtr(
        PlainDataPiece(game->getPlayers(), finalPayoff).toString()
    );
    resultBuilder->addResult( finalPayoffName, finalPayoffResult );

    return resultBuilder->build();
}

Message ExtensivePureEquilibriumRoutine::toString() const {
    return Message("ExtensivePureEquilibriumRoutine");
}

// private:

NumbersPtr ExtensivePureEquilibriumRoutine::getBestPayoffWhen(
    const StrategicGamePositionsHelper& strategicPositionsHelper,
    const ExtensiveGamePositionsHelper& extensivePositionsHelper,
    const ExtensiveDataNode&            checkedNode,
    ExtensivePureStrategyPath&          optimalChoices
) const {
    NumbersPtr bestPayoff = createNumbersPtr();

    if (checkedNode.isLeaf()) {
        static const Positions emptyPositions;
        bestPayoff = checkedNode.getPayoffs(emptyPositions);
    } else {
        const Identifier& playerName = *checkedNode.getPlayer()->getName();
        if (!extensivePositionsHelper.isPlayerPossible(playerName))
            throw ExceptionFactory::getInstance().playerNotFound(playerName);

        const Identifier& informationSet =
            extensivePositionsHelper.getInformationSetsForPlayer( playerName )
            .right.at( const_cast<ExtensiveDataNode* const>(&checkedNode) );
        const Index comparedPayoffIndex = strategicPositionsHelper.calculatePlayer( playerName );

        CalculatedPayoffs calculatedPayoffs;
        for (const ExtensiveDataNodes::value_type& child : checkedNode.getChildren()) {
            const Identifier& strategy         = child.first;
            const ExtensiveDataNode& childNode = *child.second;

            const NumbersPtr& bestSubTreePayoff = getBestPayoffWhen(
                strategicPositionsHelper,
                extensivePositionsHelper,
                childNode,
                optimalChoices
            );

            if (bestSubTreePayoff->size() <= comparedPayoffIndex)
                throw ExceptionFactory::getInstance().incompletePayoffInformation(playerName, strategy);

            calculatedPayoffs.insert( CalculatedPayoffs::value_type(strategy, bestSubTreePayoff) );
        }

        Identifier decision = calculatedPayoffs.begin()->first;
        NumberPtr  payoff   = calculatedPayoffs.begin()->second->at(comparedPayoffIndex);
        for (const CalculatedPayoffs::value_type& calculatedPayoff : calculatedPayoffs) {
            const Identifier& nextDecision = calculatedPayoff.first;
            const NumberPtr&  nextPayoff   = calculatedPayoff.second->at(comparedPayoffIndex);

            if (*nextPayoff > *payoff) {
                decision = nextDecision;
                payoff   = nextPayoff;
            }
        }

        bestPayoff = calculatedPayoffs.at(decision);
        optimalChoices.addPlayerChoice(informationSet, playerName, decision);
    }

    return bestPayoff;
}

// }; /* END class ExtensivePureEquilibriumRoutine */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
