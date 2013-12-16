#ifndef __GT_GTL_CONDITION_HPP__
#define __GT_GTL_CONDITION_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Condition used for querying Objects with some requirements.
 *
 * <p>Each kind of Condition should have its own representation recognized by Parser. It should be then
 * created by ConditionDriver (which in turn would use ConditionFactory). Conditions would be used e.g.
 * like that:</p>
 *
 * <p><pre>
 * FIND pure_exuilibrium
 * FOR  some_game
 * WITH [condition1](, [condition2](, ...))
 * </pre></p>
 *
 * @author Mateusz Kubuszok
 *
 * @see ConditionDriver
 * @see ConditionFactory
 * @see Query
 * @see Parser
 */
class Condition : public virtual ValidableSymbol {
public:
    /**
     * @brief Default destructor.
     */
    virtual ~Condition();

    /**
     * @brief Returns Condition applicable to Route.
     *
     * @param             Context
     * @return            Condition applicable to Route
     * @throw InvalidType thrown when condition make use of not accepted Objects
     */
    virtual Routines::ConditionPtr getCondition(
        const Context& context
    ) const = 0;

    /**
     * @brief Returns Message about Condition.
     *
     * @return Condition's Message
     */
    virtual Message toString() const override = 0;
}; /* END class Condition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null Condition for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullCondition final : public Condition {
public:
    virtual Routines::ConditionPtr getCondition(
        const Context&
    ) const override {
        return Routines::NullFactory::getInstance().createCondition();
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullCondition");
    }
}; /* END class NullCondition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Error Condition for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class ErrorCondition final : public Condition {
    /**
     * @brief Error message.
     */
    const Message message;

public:
    ErrorCondition(
        const Message errorMessage
    ) :
        message(errorMessage)
        {}

    virtual Routines::ConditionPtr getCondition(
        const Context&
    ) const override {
        return Routines::NullFactory::getInstance().createCondition();
    }

    virtual bool isValid() const override {
        return false;
    }

    virtual Message toString() const override {
        return message;
    }
}; /* END class ErrorCondition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_CONDITION_HPP__ */
