/**
 * @file      gt/routines/selectable_strategies_routine.cpp
 * @brief     Defines GT::Routines::SelectableStrategiesRoutine methods.
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

// class SelectableStrategiesRoutine : virtual public Routine {
// public:

SelectableStrategiesRoutine::SelectableStrategiesRoutine(
    const PlayersPtr definedPlayers
) :
    players(definedPlayers),
    availableStrategies()
{
    for (const Players::value_type& playerPair : *players) {
        const Identifier   playerName = playerPair.first;
        const Identifiers& strategies = *playerPair.second->getStrategies();

        IdentifiersPtr availableStrategiesForPlayer(new Identifiers(strategies));

        availableStrategies.insert( AvailableStrategies::value_type(
            playerName,
            availableStrategiesForPlayer
        ) );
    }
}

const PlayersPtr SelectableStrategiesRoutine::getAvailablePlayers() const {
    return players;
}

IdentifiersPtr SelectableStrategiesRoutine::getAvailableStrategiesForPlayer(
    const Identifier& player
) const {
    if (!availableStrategies.count(player))
        throw ExceptionFactory::getInstance().playerNotFound(player);

    return availableStrategies.at(player);
}

void SelectableStrategiesRoutine::setAvailableStrategiesForPlayer(
    const Identifier& player,
    IdentifiersPtr    strategies
) {
    if (!availableStrategies.count(player))
        throw ExceptionFactory::getInstance().playerNotFound(player);

    availableStrategies[player] = strategies;
}

// }; /* END class SelectableStrategiesRoutine */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
