#ifndef GT_ROUTINES_COMMON_HPP_INCLUDED
#define GT_ROUTINES_COMMON_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/routines/common.hpp
 * @brief     Declares classes for GT::Routines module.
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

/* Includes GT models headers  */
#include "gt/model/common.hpp"

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @namespace GT::Routines
 * @brief     Contains classes related to calculating Nash equilibria for given Models.
 *
 * It consists of Routines, Conditions and their factories.
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using boost::container::vector;
using boost::shared_ptr;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Exception declarations */

class InvalidCondition;
class InvalidPlayerChoice;

/* Factory declarations */

class NullFactory;
class ConditionFactory;
class RoutineFactory;

/* Routines declarations */

class Condition;     class NullCondition;
class Routine;       class NullRoutine;
class RoutineConfig; class NullRoutineConfig;

/* Shortens commonly used names */

typedef shared_ptr<Condition>     ConditionPtr;     /**< @brief Smart pointer to Condition. */
typedef vector<ConditionPtr>      Conditions;       /**< @brief Vector of Conditions. */
typedef shared_ptr<Conditions>    ConditionsPtr;    /**< @brief Smart pointer to Conditions. */
typedef shared_ptr<Routine>       RoutinePtr;       /**< @brief Smart pointer to Routine. */
typedef vector<RoutinePtr>        Routines;         /**< @brief Vector of Routines. */
typedef shared_ptr<Routines>      RoutinesPtr;      /**< @brief Smart pointer to Routines. */
typedef shared_ptr<RoutineConfig> RoutineConfigPtr; /**< @brief Smart pointer to RoutineConfig. */

typedef Model::Root               Root;             /**< @brief Alias for Model::Root. */
typedef Model::Game               Game;             /**< @brief Alias for Model::Game. */
typedef Model::NullGame           NullGame;         /**< @brief Alias for Model::NullGame. */
typedef Model::GamePtr            GamePtr;          /**< @brief Alias for Model::GamePtr. */
typedef Model::Result             Result;           /**< @brief Alias for Model::Result. */
typedef Model::NullResult         NullResult;       /**< @brief Alias for Model::NullResult. */
typedef Model::ResultPtr          ResultPtr;        /**< @brief Alias for Model::ResultPtr. */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

/* Includes Routinies headers */

#include "gt/routines/exceptions.hpp"

#include "gt/routines/null_factory.hpp"
#include "gt/routines/condition_factory.hpp"
#include "gt/routines/routine_factory.hpp"

#include "gt/routines/condition.hpp"
#include "gt/routines/routine.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif /* END #ifndef GT_ROUTINES_COMMON_HPP_INCLUDED */
