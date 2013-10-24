#ifndef __GT_GTL_EXECUTION_CONDITION_DRIVER_HPP__
#define __GT_GTL_EXECUTION_CONDITION_DRIVER_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Implementation used for handling Games via ExecutionDriver.
 *
 * @author Mateusz Kubuszok
 *
 * @see ExecutionDriver
 * @see ConditionDriver
 */
class ExecutionConditionDriver : public ConditionDriver {
    Driver* driver;

public:
    /**
     * @brief Initiates ExecutionConditionDriver with its parent.
     *
     * @param parentDriver parent Driver
     */
    ExecutionConditionDriver(
        Driver* parentDriver
    );

    /**
     * @brief Create condition for Player choosing strategy.
     *
     * @param inputLocation input location of created Condition
     * @param player        Player's name
     * @param strategy      chosen strategy
     * @return              Condition
     */
    virtual ConditionPtr* playerChoosed(
        InputLocation& inputLocation,
        ObjectPtr*     playerPtr,
        ObjectPtr*     strategyPtr
    );

    /**
     * @brief ExecutionConditionDriver's Message.
     *
     * @return message
     */
    virtual Message toString();
}; /* END class ExecutionConditionDriver */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_EXECUTION_CONDITION_DRIVER_HPP__ */
