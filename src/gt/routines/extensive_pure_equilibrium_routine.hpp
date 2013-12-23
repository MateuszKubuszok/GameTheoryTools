#ifndef __GT_ROUTINES_EXTENSIVE_PURE_EQUILIBRIUM_ROUTINE_HPP__
#define __GT_ROUTINES_EXTENSIVE_PURE_EQUILIBRIUM_ROUTINE_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/routines/extensive_pure_equilibrium_routine.hpp
 * @brief     Defines GT::Routines::ExtensivePureEquilibriumRoutine class.
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

using boost::container::map;

using Model::ExtensiveDataNode;
using Model::ExtensiveGamePositionsHelper;
using Model::StrategicGamePositionsHelper;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class ExtensivePureEquilibriumRoutine
 * @brief Routune returning pure strategy equilibrium for Extensive Game.
 *
 * @author Mateusz Kubuszok
 *
 * @see Condition
 */
class ExtensivePureEquilibriumRoutine final : public Routine {
public:
    /**
     * @brief Returns pure strategy equilibrium for Extensive Game.
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

private:
    /**
     * @brief Continas bottom-top best payoff partial results.
     */
    typedef map<Identifier, const NumbersPtr> CalculatedPayoffs;

    /**
     * @brief Returns best payoff for Player in checkedNode and adds that choice to optimalChoices.
     *
     * @param strategicPositionsHelper positions helper that calculates position of compared payoff
     * @param extensivePositionsHelper positions helper that calculates the information set of checkedNode
     * @param checkedNode              node that should its best payoff calculated
     * @param optimalChoices           contains all optimal choices of already checked decisions
     * @return                         value of optimal Payoff for current Player in checkedNode
     */
    NumbersPtr getBestPayoffWhen(
        const StrategicGamePositionsHelper& strategicPositionsHelper,
        const ExtensiveGamePositionsHelper& extensivePositionsHelper,
        const ExtensiveDataNode&            checkedNode,
        ExtensivePureStrategyPath&          optimalChoices
    ) const;
}; /* END class ExtensivePureEquilibriumRoutine */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* #ifndef __GT_ROUTINES_EXTENSIVE_PURE_EQUILIBRIUM_ROUTINE_HPP__ */
