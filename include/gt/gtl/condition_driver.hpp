#ifndef __GT_GTL_CONDITION_DRIVER_HPP__
#define __GT_GTL_CONDITION_DRIVER_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Used for handling Games via Driver.
 *
 * @author Mateusz Kubuszok
 */
class ConditionDriver : public virtual Root {
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
    ) = 0;

    /**
     * @brief ConditionDriver's Message.
     *
     * @return message
     */
    virtual Message toString() = 0;
}; /* END class ConditionDriver */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null ConditionDriver for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullConditionDriver : public ConditionDriver {
public:
	NullConditionDriver() :
        Root(),
		ConditionDriver()
		{}

	virtual ConditionPtr* playerChoosed(
        ObjectPtr* player,
        ObjectPtr* strategy
    ) {
        return new ConditionPtr(NullFactory::getInstance().createCondition());
    }

	virtual Message toString() {
		return Message("NullConditionDriver");
	}
}; /* END class NullConditionDriver */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_CONDITION_DRIVER_HPP__ */
