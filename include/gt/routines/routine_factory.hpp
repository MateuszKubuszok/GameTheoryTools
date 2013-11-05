#ifndef __GT_ROUTINES_ROUTINES_FACTORY_HPP__
#define __GT_ROUTINES_ROUTINES_FACTORY_HPP__

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Used for creation of Null instances for Routines classes.
 *
 * @author Mateusz Kubuszok
 */
class RoutineFactory {
    SINGLETON_DECLARATION(RoutineFactory)

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
        GamePtr game
    );

    /**
     * @brief Creates Routine that find mixed-stratgy Nash eqilibrium.
     *
     * @param game Game for which equilibrium should be sought
     * @result     Routine finding Nash equilibria
     */
    RoutinePtr mixedStrategyEquilibriumFindingRoutineFor(
        GamePtr game
    );

    /**
     * @brief Creates Routine that find behaiour-stratgy Nash eqilibrium.
     *
     * @param game Game for which equilibrium should be sought
     * @result     Routine finding Nash equilibria
     */
    RoutinePtr behaiourStrategyEquilibriumFindingRoutineFor(
        GamePtr game
    );

private:
    /**
     * @brief Default constructor hidden from programmers.
     */
    RoutineFactory();

    /**
     * @brief Default copy constructor hidden from programmers.
     *
     * @param object to copy
     */
    RoutineFactory(
        const RoutineFactory& nullFactory
    );

    /**
     * @brief Default destructor hidden from programmers.
     */
    ~RoutineFactory();
}; /* END class RoutineFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* END #ifndef __GT_ROUTINES_ROUTINES_FACTORY_HPP__ */
