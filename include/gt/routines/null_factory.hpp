#ifndef __GT_ROUTINES_NULL_FACTORY_HPP__
#define __GT_ROUTINES_NULL_FACTORY_HPP__

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Used for creation of Null instances for Routines classes.
 *
 * @author Mateusz Kubuszok
 */
class NullFactory {
    SINGLETON_DECLARATION(NullFactory)

public:
    /**
     * @brief Returns the instance of a NullFactory.
     *
     * @return NullFactory instance
     */
    static NullFactory& getInstance();

    /**
     * @brief Creates NullCondition.
     *
     * @result NullCondition
     */
    ConditionPtr createCondition();

    /**
     * @brief Creates NullConditions.
     *
     * @result NullConditions
     */
    ConditionsPtr createConditions();

    /**
     * @brief Creates NullRoutine.
     *
     * @result NullRoutine
     */
    RoutinePtr createRoutine();

    /**
     * @brief Creates NullRoutines.
     *
     * @result NullRoutines
     */
    RoutinesPtr createRoutines();

private:
    /**
     * @brief Default constructor hidden from programmers.
     */
    NullFactory();

    /**
     * @brief Default copy constructor hidden from programmers.
     *
     * @param object to copy
     */
    NullFactory(
        const NullFactory& nullFactory
    );

    /**
     * @brief Default destructor hidden from programmers.
     */
    ~NullFactory();
}; /* END class NullFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* END #ifndef __GT_ROUTINES_NULL_FACTORY_HPP__ */
