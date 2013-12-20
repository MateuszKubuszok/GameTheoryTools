#ifndef __GT_ROUTINES_CONDITION_FACTORY_HPP__
#define __GT_ROUTINES_CONDITION_FACTORY_HPP__

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Used for creation of Null instances for Routines classes.
 *
 * @author Mateusz Kubuszok
 */
class ConditionFactory {
public:
    /**
     * @brief Returns the instance of a ConditionFactory.
     *
     * @return ConditionFactory instance
     */
    static ConditionFactory& getInstance();

    /**
     * @brief Creates Condition of Player's choice.
     *
     * @result Condition
     */
    ConditionPtr createPlayerChoiceCondition(
        const IdentifierPtr player,
        const IdentifierPtr strategy
    ) const;

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
        const ConditionFactory& nullFactory
    );

    /**
     * @brief Default destructor hidden from programmers.
     */
    ~ConditionFactory();
}; /* END class ConditionFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* END #ifndef __GT_ROUTINES_CONDITION_FACTORY_HPP__ */
