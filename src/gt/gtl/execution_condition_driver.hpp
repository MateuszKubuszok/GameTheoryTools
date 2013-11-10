#ifndef __GT_GTL_EXECUTION_CONDITION_DRIVER_HPP__
#define __GT_GTL_EXECUTION_CONDITION_DRIVER_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Implementation used for handling Conditions via ExecutionDriver.
 *
 * <p>Performs actual execution of instructions for Conditions.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see ExecutionDriver
 * @see ConditionDriver
 */
class ExecutionConditionDriver : public ConditionDriver {
    /**
     * @brief Driver for error handling.
     */
    CheckingConditionDriver checkingConditionDriver;
    /**
     * @brief Implementation of a main Driver.
     */
    Driver*                 driver;

public:
    /**
     * @brief Initiates ExecutionConditionDriver with its parent.
     *
     * @param parentDriver parent Driver
     */
    explicit ExecutionConditionDriver(
        Driver* parentDriver
    );

    /**
     * @brief Create Condition for Player choosing strategy.
     *
     * @param inputLocation input location of created Condition
     * @param player        Player's name
     * @param strategy      chosen strategy
     * @return              Condition
     */
    virtual ConditionPtr* playerChoosed(
        const InputLocation& inputLocation,
        const ObjectPtr*     playerPtr,
        const ObjectPtr*     strategyPtr
    ) const override;

    /**
     * @brief ExecutionConditionDriver's Message.
     *
     * @return message
     */
    virtual Message toString() const override;
}; /* END class ExecutionConditionDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_EXECUTION_CONDITION_DRIVER_HPP__ */
