/**
 * @file      gt/routines/strategic_pure_equilibrium_routine_config.cpp
 * @brief     Defines GT::Routines::StrategicPureEquilibriumRoutineConfig methods.
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

using Model::PlayersPtr;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class StrategicPureEquilibriumRoutineConfig : public PlayerChoiceRoutineConfig {
// public:

StrategicPureEquilibriumRoutineConfig::StrategicPureEquilibriumRoutineConfig(
    const PlayersPtr players
) :
    RoutineConfig(),
    PlayerChoiceRoutineConfig(players)
    {}

bool StrategicPureEquilibriumRoutineConfig::isValid() const {
    return PlayerChoiceRoutineConfig::isValid();
}

Message StrategicPureEquilibriumRoutineConfig::toString() const {
    return Message("StrategicPureEquilibriumRoutineConfig");
}

// }; /* END class StrategicPureEquilibriumRoutineConfig */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
