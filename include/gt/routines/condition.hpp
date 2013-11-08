#ifndef __GT_ROUTINES_CONDITION_HPP__
#define __GT_ROUTINES_CONDITION_HPP__

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Condition that sets up Routine before actual calculation.
 *
 * @author Mateusz Kubuszok
 *
 * @see Routine
 */
class Condition : public virtual Root {
public:
    /**
     * @brief Configureg given Routine.
     *
     * @param routine          Routine to configure
     * @throw InvalidCondition thrown when Condition is invalid
     */
    virtual void configureRoutine(
        RoutinePtr routine
    ) = 0;

    /**
     * @brief Returns Condition's Message.
     *
     * @return Condition's Message
     */
    virtual Message toString() = 0;
}; /* END class Condition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null Condition for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullCondition : public Condition {
    virtual void configureRoutine(
        RoutinePtr
    ) override {}

    virtual bool isNotNull() override {
        return false;
    }

    virtual Message toString() override {
        return Message("NullCondition");
    }
}; /* END class NullCondition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* #ifndef __GT_ROUTINES_CONDITION_HPP__ */
