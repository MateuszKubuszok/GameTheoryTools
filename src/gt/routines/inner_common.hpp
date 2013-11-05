#ifndef __GT_ROUTINES_INNER_COMMON_HPP__
#define __GT_ROUTINES_INNER_COMMON_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Include standard libraries */
#include <algorithm>
#include <sstream>

/* Includes boost libraries */
#include <boost/algorithm/string.hpp>
#include <boost/bimap/bimap.hpp>
#include <boost/range/adaptor/map.hpp>
#include <boost/thread/mutex.hpp>

/* Includes public interface */
#include "gt/routines/common.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Implementations declarations */

class ExceptionFactory;

class SelectableStrategiesRoutine;

class PlayerChoiceCondition;

/* Shortens commonly used names */

typedef boost::shared_ptr<SelectableStrategiesRoutine> SelectableStrategiesRoutinePtr;

typedef Model::Player           Player;
typedef Model::PlayerPtr        PlayerPtr;
typedef Model::Players          Players;
typedef Model::PlayersPtr       PlayersPtr;

typedef Model::ResultFactory    ResultFactory;
typedef Model::ResultBuilderPtr ResultBuilderPtr;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

/* Implementations headers */

#include "gt/routines/exception_factory.hpp"

#include "gt/routines/selectable_strategies_routine.hpp"

#include "gt/routines/player_choice_condition.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif /* #define __GT_ROUTINES_INNER_COMMON_HPP__ */
