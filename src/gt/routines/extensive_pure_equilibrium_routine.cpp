#include "gt/routines/inner_common.hpp"

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExtensivePureEquilibriumRoutine : public SelectableStrategiesRoutine {
// public:

ExtensivePureEquilibriumRoutine::ExtensivePureEquilibriumRoutine(
    const PlayersPtr players
) :
    SelectableStrategiesRoutine(players)
    {}

ResultPtr ExtensivePureEquilibriumRoutine::findResultFor(
    const GamePtr       game,
    const ConditionsPtr
) const {
    const Model::ExtensiveDataAccessorPtr data =
        boost::dynamic_pointer_cast<Model::ExtensiveDataAccessor>(game->getData());

    if (!data) {
        static Identifier extensiveGameName("Extensive Game");
        throw ExceptionFactory::getInstance().invalidGameType(extensiveGameName);
    }

    const Model::StrategicGamePositionsHelper strategicPositionsHelper(data->getPlayers());
    const Model::ExtensiveGamePositionsHelper extensivePositionsHelper(data->getRoot());
    const Model::ExtensiveDataNode&           root = *data->getRoot();
    ExtensivePureStrategyPath                 resultPath(game->getPlayers());

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
        Model::PlainDataPiece(game->getPlayers(), finalPayoff).toString()
    );
    resultBuilder->addResult( finalPayoffName, finalPayoffResult );

    return resultBuilder->build();
}

Message ExtensivePureEquilibriumRoutine::toString() const {
    return Message("ExtensivePureEquilibriumRoutine");
}

// private:

NumbersPtr ExtensivePureEquilibriumRoutine::getBestPayoffWhen(
    const Model::StrategicGamePositionsHelper& strategicPositionsHelper,
    const Model::ExtensiveGamePositionsHelper& extensivePositionsHelper,
    const Model::ExtensiveDataNode&            checkedNode,
    ExtensivePureStrategyPath&                 optimalChoices
) const {
    NumbersPtr bestPayoff = createNumbersPtr();

    if (checkedNode.isLeaf()) {
        static const Positions emptyPositions;
        bestPayoff = checkedNode.getValues(emptyPositions);
    } else {
        const Identifier& playerName = *checkedNode.getPlayer()->getName();
        if (!extensivePositionsHelper.isPlayerPossible(playerName))
            throw ExceptionFactory::getInstance().playerNotFound(playerName);

        const Identifier& informationSet =
            extensivePositionsHelper.getInformationSetsForPlayer( playerName )
            .right.at( const_cast<Model::ExtensiveDataNode* const>(&checkedNode) );
        const Index comparedPayoffIndex = strategicPositionsHelper.calculatePlayer( playerName );

        CalculatedPayoffs calculatedPayoffs;
        for (const Model::ExtensiveDataNodes::value_type& child : checkedNode.getChildren()) {
            const Identifier& strategy                = child.first;
            const Model::ExtensiveDataNode& childNode = *child.second;

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
