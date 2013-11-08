#ifndef __GT_ROUTINES_ROUTINE_HPP__
#define __GT_ROUTINES_ROUTINE_HPP__

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
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
     * @param game       Game definition
     * @param conditions Conditions for this Routine
     * @return           Result for fiven Game and Conditions
     */
    virtual ResultPtr findResultFor(
        GamePtr       game,
        ConditionsPtr conditions
    ) = 0;

    /**
     * @brief Returns Routine's Message.
     *
     * @return Routine's Message
     */
    virtual Message toString() = 0;
}; /* END class Routine */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null Routine for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullRoutine : public Routine {
    virtual ResultPtr findResultFor(
        GamePtr,
        ConditionsPtr
    ) override {
        return Model::NullFactory::getInstance().createResult();
    }

    virtual bool isNotNull() override {
        return false;
    }

    virtual Message toString() override {
        return Message("NullRoutine");
    }
}; /* END class NullRoutine */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* #ifndef __GT_ROUTINES_ROUTINE_HPP__ */
