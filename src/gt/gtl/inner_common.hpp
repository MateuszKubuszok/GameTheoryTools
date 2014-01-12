#ifndef __GT_GTL_INNER_COMMON_HPP__
#define __GT_GTL_INNER_COMMON_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/inner_common.hpp
 * @brief     Declares inner classes for GT::GTL module.
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
#include <sstream>

/* Includes boost libraries */
#include <boost/algorithm/string.hpp>
#include <boost/assign.hpp>
#include <boost/bimap/bimap.hpp>
#include <boost/range/adaptor/map.hpp>
#include <boost/scoped_ptr.hpp>

/* Includes public interface */
#include "gt/gtl/common.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Implementations declarations */

class ExceptionFactory;

class ObjectTypeProperty;
class ObjectKnownProperties;

class PlayerChoiceCondition;
class PlayerRangeCondition;
class InformationSetChoiceCondition;
class InformationSetRangeCondition;

class GamePureEquilibriumProperty;
class GameMixedEquilibriumProperty;
class GameBehaviorEquilibriumProperty;

class ParamKnownProperties;
class ParamValueProperty;

class PlayerNameProperty;
class PlayerStrategiesProperty;

class IdentifierParam;
class NumberParam;
class ObjectParam;

class CheckingConditionDriver;
class CheckingCoordinateDriver;
class CheckingGameDriver;
class CheckingValueDriver;
class CheckingStatementDriver;
class CheckingDriver;

class ExecutionConditionDriver;
class ExecutionCoordinateDriver;
class ExecutionGameDriver;
class ExecutionValueDriver;
class ExecutionStatementDriver;
class ExecutionDriver;

class LazyGameProxy;

/* Shortens commonly used names */

typedef Model::ResultFactory    ResultFactory;
typedef Model::ResultBuilderPtr ResultBuilderPtr;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Implementations headers */

#include "gt/gtl/object_property.hpp"

#include "gt/gtl/exception_factory.hpp"

#include "gt/gtl/object_type_property.hpp"
#include "gt/gtl/object_known_properties.hpp"

#include "gt/gtl/player_choice_condition.hpp"
#include "gt/gtl/player_range_condition.hpp"
#include "gt/gtl/information_set_choice_condition.hpp"
#include "gt/gtl/information_set_range_condition.hpp"

#include "gt/gtl/game_pure_equilibrium_property.hpp"
#include "gt/gtl/game_mixed_equilibrium_property.hpp"
#include "gt/gtl/game_behavior_equilibrium_property.hpp"

#include "gt/gtl/param_known_properties.hpp"
#include "gt/gtl/param_value_property.hpp"

#include "gt/gtl/player_name_property.hpp"
#include "gt/gtl/player_strategies_property.hpp"

#include "gt/gtl/identifier_param.hpp"
#include "gt/gtl/number_param.hpp"
#include "gt/gtl/object_param.hpp"

#include "gt/gtl/checking_condition_driver.hpp"
#include "gt/gtl/checking_coordinate_driver.hpp"
#include "gt/gtl/checking_game_driver.hpp"
#include "gt/gtl/checking_value_driver.hpp"
#include "gt/gtl/checking_statement_driver.hpp"
#include "gt/gtl/checking_driver.hpp"

#include "gt/gtl/execution_condition_driver.hpp"
#include "gt/gtl/execution_coordinate_driver.hpp"
#include "gt/gtl/execution_game_driver.hpp"
#include "gt/gtl/execution_value_driver.hpp"
#include "gt/gtl/execution_statement_driver.hpp"
#include "gt/gtl/execution_driver.hpp"

#include "gt/gtl/lazy_game_proxy.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif /* #define __GT_GTL_INNER_COMMON_HPP__ */
