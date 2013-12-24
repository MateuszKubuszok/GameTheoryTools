#ifndef __GT_ROUTINES_ROUTINE_HPP__
#define __GT_ROUTINES_ROUTINE_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/routines/routine.hpp
 * @brief     Defines GT::Routines::Routine interface.
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

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class Routine
 * @brief Routine that calculates some Result e.g. Nash equilibrium.
 *
 * @author Mateusz Kubuszok
 *
 * @see Condition
 */
class Routine : public virtual Root {
public:
    /**
     * @brief Calculates Result for given Game and Conditions.
     *
     * @param game             Game definition
     * @param conditions       Conditions for this Routine
     * @return                 Result for fiven Game and Conditions
     * @throw InvalidCondition thrown when some Condition is invalid or when Conditions application leads to
     *                         an invalid RoutineConfig or no result
     * @throw InvalidGameType  thrown when Game's type doesn't match Routine's one
     */
    virtual ResultPtr findResultFor(
        const GamePtr       game,
        const ConditionsPtr conditions
    ) const = 0;

    /**
     * @brief Returns Routine's Message.
     *
     * @return Routine's Message
     */
    virtual Message toString() const override = 0;
}; /* END class Routine */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class NullRoutine
 * @brief Null Routine for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullRoutine final : public Routine {
    virtual ResultPtr findResultFor(
        const GamePtr,
        const ConditionsPtr
    ) const override {
        return Model::NullFactory::getInstance().createResult();
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullRoutine");
    }
}; /* END class NullRoutine */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* #ifndef __GT_ROUTINES_ROUTINE_HPP__ */
