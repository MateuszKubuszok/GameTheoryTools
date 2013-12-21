/**
 * @file      gt/gtl/game_pure_equilibrium_property.cpp
 * @brief     Defines GT::GTL::GamePureEquilibriumProperty methods.
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

#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class GamePureEquilibriumProperty final : public ObjectProperty {
// public:

GamePureEquilibriumProperty::GamePureEquilibriumProperty(
    const Game* describedGame
) :
    game(describedGame)
    {}

ResultPtr GamePureEquilibriumProperty::findForConditions(
    const Context&    context,
    const Conditions& conditions
) const {
    return game->pureEquilibrium(context, conditions);
}

// }; /* END class GamePureEquilibriumProperty */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
