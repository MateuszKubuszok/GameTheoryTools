#ifndef __GT_ROUTINES_INNER_COMMON_HPP__
#define __GT_ROUTINES_INNER_COMMON_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/routines/inner_common.hpp
 * @brief     Declares inner classes for GT::Routines module.
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

/* Include standard libraries */
#include <cstdlib>
#include <algorithm>
#include <limits>
#include <memory>
#include <sstream>

/* Includes boost libraries */
#include <boost/algorithm/string.hpp>
#include <boost/bimap/bimap.hpp>
#include <boost/range/adaptor/map.hpp>

/* GNU Linear Package Kit */
#include <glpk.h>

/* Includes public interface */
#include "gt/routines/common.hpp"

/* Includes private interface */
#include "gt/model/inner_common.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using std::unique_ptr;

using boost::container::vector;
using boost::shared_ptr;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Implementations declarations */

class ExceptionFactory;

class NotYetImplementedRoutine;
class PropertyUndefinedRoutine;

class PlayerChoiceRoutineConfig;
class InformationSetChoiceRoutineConfig;

class ExtensivePureStrategyPath;

class StrategicPureEquilibriumRoutine;
class StrategicPureEquilibriumRoutineConfig;
class ExtensivePureEquilibriumRoutine;
class ExtensivePureEquilibriumRoutineConfig;

class PlayerChoiceCondition;
class PlayerRangeCondition;
class InformationSetChoiceCondition;
class InformationSetRangeCondition;

/* Shortens commonly used names */

/** @brief Alias for GLPK's problem structure. */
typedef glp_prob                                      LPProblem;
/** @brief Defines wrapper with automatic deletion for GLPK's problem structure. */
typedef unique_ptr<LPProblem, void(*)(LPProblem*)>    LPProblemPtr;

/** @brief Shared pointer to PlayerChoiceRoutineConfig. */
typedef shared_ptr<PlayerChoiceRoutineConfig>         PlayerChoiceRoutineConfigPtr;
/** @brief Shared pointer to InformationSetChoiceRoutineConfig. */
typedef shared_ptr<InformationSetChoiceRoutineConfig> InformationSetChoiceRoutineConfigPtr;

/** @brief Vector of ExtensivePureStrategyPaths. */
typedef vector<ExtensivePureStrategyPath>             ExtensivePureStrategyPaths;

typedef Model::Player           Player;
typedef Model::PlayerPtr        PlayerPtr;
typedef Model::Players          Players;
typedef Model::PlayersPtr       PlayersPtr;

typedef Model::ResultFactory    ResultFactory;
typedef Model::ResultBuilderPtr ResultBuilderPtr;

/** @brief Creates LPProblem instance. */
LPProblemPtr createLPProblem();

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

/* Implementations headers */

#include "gt/routines/exception_factory.hpp"

#include "gt/routines/routine_config.hpp"

#include "gt/routines/player_choice_routine_config.hpp"
#include "gt/routines/information_set_choice_routine_config.hpp"

#include "gt/routines/not_yet_implemented_routine.hpp"
#include "gt/routines/property_undefined_routine.hpp"

#include "gt/routines/extensive_pure_strategy_path.hpp"

#include "gt/routines/strategic_pure_equilibrium_routine.hpp"
#include "gt/routines/strategic_pure_equilibrium_routine_config.hpp"
#include "gt/routines/extensive_pure_equilibrium_routine.hpp"
#include "gt/routines/extensive_pure_equilibrium_routine_config.hpp"

#include "gt/routines/strategic_2_player_0_sum_mixed_equilibrium_routine.hpp"
#include "gt/routines/strategic_2_player_mixed_equilibrium_routine.hpp"

#include "gt/routines/player_choice_condition.hpp"
#include "gt/routines/player_range_condition.hpp"
#include "gt/routines/information_set_choice_condition.hpp"
#include "gt/routines/information_set_range_condition.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif /* #define __GT_ROUTINES_INNER_COMMON_HPP__ */
