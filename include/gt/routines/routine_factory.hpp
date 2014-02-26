#ifndef __GT_ROUTINES_ROUTINES_FACTORY_HPP__
#define __GT_ROUTINES_ROUTINES_FACTORY_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/routines/routine_factory.hpp
 * @brief     Defines GT::Routines::RoutineFactory class.
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
 * @class RoutineFactory
 * @brief Used for creation of Null instances for Routines classes.
 *
 * @author Mateusz Kubuszok
 */
class RoutineFactory final {
public:
    /**
     * @brief Returns the instance of a RoutineFactory.
     *
     * @return RoutineFactory instance
     */
    static RoutineFactory& getInstance();

    /**
     * @brief Creates Routine that find pure-stratgy Nash eqilibrium.
     *
     * @param game Game for which equilibrium should be sought
     * @result     Routine finding Nash equilibria
     */
    RoutinePtr pureStrategyEquilibriumFindingRoutineFor(
        const GamePtr game
    ) const;

    /**
     * @brief Creates Routine that find mixed-stratgy Nash eqilibrium.
     *
     * @param game Game for which equilibrium should be sought
     * @result     Routine finding Nash equilibria
     */
    RoutinePtr mixedStrategyEquilibriumFindingRoutineFor(
        const GamePtr game
    ) const;

    /**
     * @brief Creates Routine that find behaiour-stratgy Nash eqilibrium.
     *
     * @param game Game for which equilibrium should be sought
     * @result     Routine finding Nash equilibria
     */
    RoutinePtr behaviourStrategyEquilibriumFindingRoutineFor(
        const GamePtr game
    ) const;

private:
    /**
     * @brief Default constructor hidden from programmers.
     */
    RoutineFactory() = default;

    /**
     * @brief Default copy constructor hidden from programmers.
     *
     * @param routineFactory object to copy
     */
    RoutineFactory(
        const RoutineFactory& routineFactory
    ) = delete;

    /**
     * @brief Default destructor hidden from programmers.
     */
    ~RoutineFactory() = default;
}; /* END class RoutineFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* END #ifndef __GT_ROUTINES_ROUTINES_FACTORY_HPP__ */
