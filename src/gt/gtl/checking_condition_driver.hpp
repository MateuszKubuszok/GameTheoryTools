#ifndef __GT_GTL_CHECKING_CONDITION_DRIVER_HPP__
#define __GT_GTL_CHECKING_CONDITION_DRIVER_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Implementation used for handling Conditions via CheckingDriver.
 *
 * <p>Performs only syntax/type checking on Conditions' tokens.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see CheckingDriver
 * @see ConditionDriver
 */
class CheckingConditionDriver : public ConditionDriver {
    /**
     * @brief Implementation of a main Driver.
     */
    Driver* driver;

public:
    /**
     * @brief Initiates CheckingConditionDriver with its parent.
     *
     * @param parentDriver parent Driver
     */
    explicit CheckingConditionDriver(
        Driver* parentDriver
    );

    /**
     * @brief Create condition for Player choosing strategy.
     *
     * @param inputLocation input location of a created Condition
     * @param player        Player's name
     * @param strategy      chosen strategy
     * @return              Condition
     */
    virtual ConditionPtr* playerChoosed(
        const InputLocation& inputLocation,
        const ObjectPtr*     playerPtr,
        const ObjectPtr*     strategyPtr
    ) const;

    /**
     * @brief CheckingConditionDriver's Message.
     *
     * @return message
     */
    virtual Message toString() const override;
}; /* END class CheckingConditionDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_CHECKING_CONDITION_DRIVER_HPP__ */
