#ifndef __GT_GTL_INNER_COMMON_HPP__
#define __GT_GTL_INNER_COMMON_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Include standard libraries */
#include <sstream>

/* Includes boost libraries */
#include <boost/algorithm/string.hpp>
#include <boost/bimap/bimap.hpp>
#include <boost/range/adaptor/map.hpp>
#include <boost/thread/mutex.hpp>

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

class GamePureEquilibriumProperty;
class GameMixedEquilibriumProperty;
class GameBehavioralEquilibriumProperty;

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

/* Shortens commonly used names */

typedef Model::ResultFactory    ResultFactory;
typedef Model::ResultBuilderPtr ResultBuilderPtr;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Implementations headers */

#include "gt/gtl/exception_factory.hpp"

#include "gt/gtl/object_type_property.hpp"
#include "gt/gtl/object_known_properties.hpp"

#include "gt/gtl/player_choice_condition.hpp"

#include "gt/gtl/game_pure_equilibrium_property.hpp"
#include "gt/gtl/game_mixed_equilibrium_property.hpp"
#include "gt/gtl/game_behavioral_equilibrium_property.hpp"

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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif /* #define __GT_GTL_INNER_COMMON_HPP__ */
