#ifndef GT_ROUTINES_STRATEGIC_PURE_EQUILIBRIUM_ROUTINE_HPP_INCLUDED
#define GT_ROUTINES_STRATEGIC_PURE_EQUILIBRIUM_ROUTINE_HPP_INCLUDED

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

using boost::container::set;

using Model::StrategicDataAccessor;

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
    ) const override;

    /**
     * @brief Returns Routine's Message.
     *
     * @return Routine's Message
     */
    virtual Message toString() const override;

private:
    /**
     * @brief Creates RoutineConfig basing on passes Conditions.
     *
     * @param players          Players definitions
     * @param conditions       Conditions to apply
     * @return                 conditioned RoutineConfig
     * @throw InvalidCondition thrown when some Condition is invalid
     */
    StrategicPureEquilibriumRoutineConfig applyConditions(
        const PlayersPtr  players,
        const Conditions& conditions
    ) const;

    /**
     * @brief Whether or not Positions are allowed to be used by configuration.
     *
     * @param routineConfig contains configureation for currently executed Routine
     * @param positions     Positions to check
     * @return              true if Positions are allowed to be used
     */
    bool arePositionsAllowed(
        const StrategicPureEquilibriumRoutineConfig& routineConfig,
        const Positions&                             positions
    ) const;

    /**
     * @brief Whether or not passed Position points to a Nash equilibrium.
     *
     * @param data      data with payoffs
     * @param positions Positions to check
     * @return          true if Position point to Nash equilibrium
     */
    bool isNashEquilibrium(
        const StrategicDataAccessor& data,
        const Positions&             positions
    ) const;
}; /* END class StrategicPureEquilibriumRoutine */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* #ifndef GT_ROUTINES_STRATEGIC_PURE_EQUILIBRIUM_ROUTINE_HPP_INCLUDED */
