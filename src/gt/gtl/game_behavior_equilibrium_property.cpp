/**
 * @file      gt/gtl/game_behavior_equilibrium_property.cpp
 * @brief     Defines GT::GTL::GameBehaviorEquilibriumProperty methods.
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

// class GameBehaviorEquilibriumProperty final : public ObjectProperty {
// public:

GameBehaviorEquilibriumProperty::GameBehaviorEquilibriumProperty(
    const Game* describedGame
) :
    game(describedGame)
    {}

ResultPtr GameBehaviorEquilibriumProperty::getDescription() const {
    static Message description =
        "Finds behaviour strategies' Nash equilibrium";
    return ResultFactory::getInstance().constResult(description);
}

ResultPtr GameBehaviorEquilibriumProperty::findForConditions(
    const Context&    context,
    const Conditions& conditions
) const {
    return game->behaviorEquilibrium(context, conditions);
}

// }; /* END class GameBehaviorEquilibriumProperty */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
