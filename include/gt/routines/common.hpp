#ifndef __GT_ROUTINES_COMMON_HPP__
#define __GT_ROUTINES_COMMON_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Includes GT models headers  */
#include "gt/model/common.hpp"

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Exception declarations */

class InvalidCondition;
class InvalidPlayerChoice;

/* Factory declarations */

class NullFactory;
class ConditionFactory;
// class RoutineFactory;

/* Routines declarations */

class Condition; class NullCondition;
class Routine;   class NullRoutine;

/* Shortens commonly used names */

typedef boost::shared_ptr<Condition>           ConditionPtr;
typedef boost::container::vector<ConditionPtr> Conditions;
typedef boost::shared_ptr<Conditions>          ConditionsPtr;
typedef boost::shared_ptr<Routine>             RoutinePtr;
typedef boost::container::vector<RoutinePtr>   Routines;
typedef boost::shared_ptr<Routines>            RoutinesPtr;

typedef Model::Root                            Root;
typedef Model::Game                            Game;
typedef Model::NullGame                        NullGame;
typedef Model::GamePtr                         GamePtr;
typedef Model::Result                          Result;
typedef Model::NullResult                      NullResult;
typedef Model::ResultPtr                       ResultPtr;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

/* Includes Routinies headers */

#include "gt/routines/exceptions.hpp"

#include "gt/routines/null_factory.hpp"
#include "gt/routines/condition_factory.hpp"

#include "gt/routines/condition.hpp"
#include "gt/routines/routine.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif /* END #ifndef __GT_ROUTINES_COMMON_HPP__ */
