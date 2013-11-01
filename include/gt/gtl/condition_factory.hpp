#ifndef __GT_GTL_CONDITION_FACTORY_HPP__
#define __GT_GTL_CONDITION_FACTORY_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Used for creation of Conditions for GT model.
 *
 * @author Mateusz Kubuszok
 */
class ConditionFactory {
    SINGLETON_DECLARATION(ConditionFactory)

public:
    /**
     * @brief Returns the instance of a ResultFactory.
     *
     * @return ConditionFactory instance
     */
    static ConditionFactory& getInstance();

    /**
     * @brief Creates condition for a player choosing strategy beforehand.
     *
     * @param player   player Object
     * @parma strategy strategy Object
     * @result         Condition for a player
     */
    ConditionPtr createPlayerChoiceCondition(
        const ObjectPtr player,
        const ObjectPtr strategy
    );

private:
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
}; /* END class ConditionFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_CONDITION_FACTORY_HPP__ */
