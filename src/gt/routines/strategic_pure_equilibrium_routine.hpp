#ifndef __GT_ROUTINES_STRATEGIC_PURE_EQUILIBRIUM_ROUTINE_HPP__
#define __GT_ROUTINES_STRATEGIC_PURE_EQUILIBRIUM_ROUTINE_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/routines/strategic_pure_equilibrium_routine.hpp
 * @brief     Defines GT::Routines::StrategicPureEquilibriumRoutine class.
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
 * @class StrategicPureEquilibriumRoutine
 * @brief Routune returning pure strategy equilibrium for Strategic Game.
 *
 * @author Mateusz Kubuszok
 *
 * @see Condition
 */
class StrategicPureEquilibriumRoutine final : public Routine {
public:
    /**
     * @brief Returns pure strategy equilibrium for Strategic Game.
     *
     * @param game       Game definition
     * @param conditions Conditions for this Routine
     * @return           Result for fiven Game and Conditions
     */
    virtual ResultPtr findResultFor(
        const GamePtr       game,
        const ConditionsPtr conditions
    ) const override;

    /**
     * @brief Returns Routine's Message.
     *
     * @return Routine's Message
     */
    virtual Message toString() const override;
}; /* END class StrategicPureEquilibriumRoutine */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* #ifndef __GT_ROUTINES_STRATEGIC_PURE_EQUILIBRIUM_ROUTINE_HPP__ */
