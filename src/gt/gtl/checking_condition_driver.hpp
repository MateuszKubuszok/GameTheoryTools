#ifndef __GT_GTL_CHECKING_CONDITION_DRIVER_HPP__
#define __GT_GTL_CHECKING_CONDITION_DRIVER_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Implementation used for handling Games via CheckingDriver.
 *
 * @author Mateusz Kubuszok
 *
 * @see CheckingDriver
 * @see ConditionDriver
 */
class CheckingConditionDriver : public ConditionDriver {
public:
    /**
     * @brief Create condition for Player choosing strategy.
     *
     * @param player   Player's name
     * @param strategy chosen strategy
     * @return         Condition
     */
    virtual ConditionPtr* playerChoosed(
        ObjectPtr* player,
        ObjectPtr* strategy
    );

    /**
     * @brief CheckingConditionDriver's Message.
     *
     * @return message
     */
    virtual Message toString();
}; /* END class CheckingConditionDriver */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_CHECKING_CONDITION_DRIVER_HPP__ */
