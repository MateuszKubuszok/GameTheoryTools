#ifndef GT_ROUTINES_STRATEGIC_BIMATRIX_MIXED_EQUILIBRIUM_ROUTINE_HPP_INCLUDED
#define GT_ROUTINES_STRATEGIC_BIMATRIX_MIXED_EQUILIBRIUM_ROUTINE_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/routines/bimatrix_mixed_equilibrium_routine.hpp
 * @brief     Defines GT::Routines::BimatrixMixedEquilibriumRoutine class.
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
 * @class BimatrixMixedEquilibriumRoutine
 * @brief Routune returning mixed strategy equilibrium for any sum Strategic Game with 2 Players.
 *
 * @author Mateusz Kubuszok
 *
 * @see Condition
 */
class BimatrixMixedEquilibriumRoutine final : public Routine {
public:
    /**
     * @brief Returns mixed strategy equilibrium for Strategic Game with 2 Players.
     *
     * It uses mixed-integer programming algorithm described by T. Sandholm, A. Gilpin and V. Conitzer in
     * their article *Mixed-Integer Programming Methods for Finding Nash Equilibria*. Formulation 1 of the
     * problem was implemented where cost function (since it is unimportant here) was choosen to be
     * `sum r_s_i -> minimize`.
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
     * @brief Initializes GLPK's problem (LPProblem structure) with variables declarations.
     *
     * @param  players Players used to initialize problem
     * @return         initalized problem
     */
    LPProblemPtr initializeProblem(
        const Players& players
    ) const;

    /**
     * @brief Fills ProblemPtr instance with values.
     *
     * @param problem         instance of a LPProblem that needs to have its values filled
     * @param data            contains data with Payoff values
     * @param positionsHelper helper used to calculate positions in StrategicDataAccessor
     */
    void fillUpProblem(
        LPProblem*                          problem,
        const StrategicDataAccessor&        data,
        const StrategicGamePositionsHelper& positionsHelper
    ) const;

    /**
     * @brief Returns solution for the passed Problem.
     *
     * @param problem         instance of a LPProblem to solve
     * @param data            contains data with Payoff values
     * @param positionsHelper helper used to calculate positions in StrategicDataAccessor
     * @return                resuls
     */
    ResultPtr solveProblem(
        LPProblem*                          problem,
        const StrategicDataAccessor&        data,
        const StrategicGamePositionsHelper& positionsHelper
    ) const;
}; /* END class BimatrixMixedEquilibriumRoutine */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* #ifndef GT_ROUTINES_STRATEGIC_BIMATRIX_MIXED_EQUILIBRIUM_ROUTINE_HPP_INCLUDED */
