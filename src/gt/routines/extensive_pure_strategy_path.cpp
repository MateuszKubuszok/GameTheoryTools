/**
 * @file      gt/routines/extensive_pure_strategy_path.cpp
 * @brief     Defines GT::Routines::ExtensivePureStrategyPath methods.
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

using Model::DataPiecePtr;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExtensivePureStrategyPath final {
// public:

ExtensivePureStrategyPath::ExtensivePureStrategyPath(
    const PlayersPtr playersDefinitions
) :
    players(playersDefinitions),
    payoffs(Model::NullFactory::getInstance().createDataPiece()),
    playersChoices()
{
    for (Players::value_type& player : *players)
        playersChoices.insert( PlayersChoices::value_type(player.first, Positions()) );
}

ExtensivePureStrategyPath& ExtensivePureStrategyPath::addPlayerChoice(
    const Identifier& informationSet,
    const Identifier& player,
    const Identifier& strategy
) {
    if (!players->count(player) || !playersChoices.count(player))
        throw ExceptionFactory::getInstance().playerNotFound(player);
    if (!(*players)[player]->hasStrategy(strategy))
        throw ExceptionFactory::getInstance().strategyNotFound(player, strategy);

    playersChoices[player].insert( Positions::value_type( informationSet, strategy ) );

    return *this;
}

const ExtensivePureStrategyPath::PlayersChoices& ExtensivePureStrategyPath::getPlayersChoices() const {
    return playersChoices;
}

const DataPiecePtr ExtensivePureStrategyPath::getPayoff() const {
    return payoffs;
}

ExtensivePureStrategyPath& ExtensivePureStrategyPath::setPayoff(
    DataPiecePtr newPayoffs
) {
    payoffs = newPayoffs;
    return *this;
}

Message ExtensivePureStrategyPath::toString() const {
    static IdentifierPtr payoffName = createIdentifierPtr("Payoffs");

    ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();

    for (PlayersChoices::value_type playerChoices : playersChoices) {
        ResultBuilderPtr subResultBuilder = ResultFactory::getInstance().buildResult();

        for (Positions::value_type& choice : playerChoices.second)
            subResultBuilder->addResult( createIdentifierPtr(choice.first), createMessagePtr(choice.second) );

        resultBuilder->addResult(
            createIdentifierPtr(playerChoices.first),
            createMessagePtr(subResultBuilder->build()->getResult())
        );
    }

    resultBuilder->addResult(
        payoffName,
        createMessagePtr(payoffs->toString())
    );

    return resultBuilder->build()->getResult();
}

// }; /* END class ExtensivePureStrategyPath */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
