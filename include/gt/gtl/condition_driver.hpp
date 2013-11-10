#ifndef __GT_GTL_CONDITION_DRIVER_HPP__
#define __GT_GTL_CONDITION_DRIVER_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
     * @param inputLocation input location of created Condition
     * @param player        Player's name
     * @param strategy      chosen strategy
     * @return              Condition
     */
    virtual ConditionPtr* playerChoosed(
        const InputLocation& inputLocation,
        const ObjectPtr*     playerPtr,
        const ObjectPtr*     strategyPtr
    ) const = 0;

    /**
     * @brief ConditionDriver's Message.
     *
     * @return message
     */
    virtual Message toString() const override = 0;
}; /* END class ConditionDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
        const InputLocation&,
        const ObjectPtr*,
        const ObjectPtr*
    ) const {
        return new ConditionPtr(NullFactory::getInstance().createCondition());
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullConditionDriver");
    }
}; /* END class NullConditionDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_CONDITION_DRIVER_HPP__ */
