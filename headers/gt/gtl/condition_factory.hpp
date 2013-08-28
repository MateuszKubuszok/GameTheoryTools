#ifndef __GT_GTL_CONDITION_FACTORY_HPP__
#define __GT_GTL_CONDITION_FACTORY_HPP__ 1

#include "gt/gtl/condition.hpp"

namespace GT {
namespace GTL {

/**
 * @brief Used for creation of Conditions for GT model.
 *
 * @author Mateusz Kubuszok
 */
class ConditionFactory {
public:
    /**
     * @brief Returns the instance of a ResultFactory.
     *
     * @return ConditionFactory instance
     */
    static ConditionFactory& volatile getInstance();

    /**
     * @brief Creates condition for a player choosing strategy beforehand.
     *
     * @param player   player Object
     * @parma strategy strategy Object
     * @result         Condition for a player
     */
    Condition createPlayerChoiceCondition(
        Object& player,
        Object& strategy
    );

private:
    /**
     * @brief Contains pointer to a ParamFactory instance.
     */
    static ConditionFactory volatile *instance = 0;

    /**
     * @brief Default constructor hidden from programmers.
     */
    ConditionFactory();

    /**
     * @brief Default copy constructor hidden from programmers.
     *
     * @param object to copy
     */
    ConditionFactory(
        const ConditionFactory& conditionFactory
    );

    /**
     * @brief Default destructor hidden from programmers.
     */
    ~ConditionFactory();
}

} /* END namepsace GTL */
} /* END namspace GT */

#endif /* #ifndef __GT_GTL_CONDITION_FACTORY_HPP__ */
