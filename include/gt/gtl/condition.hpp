#ifndef __GT_GTL_CONDITION_HPP__
#define __GT_GTL_CONDITION_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Condition used for querying Objects with some requirements.
 *
 * @author Mateusz Kubuszok
 */
class Condition : public virtual Root {
public:
    /**
     * @brief Default destructor.
     */
    virtual ~Condition();

    /**
     * @brief Parametrizes query using the inversion of control.
     *
     * @param query query to parametrize
     */
    virtual void conditionQuery(
        Query& query
    ) = 0;

    /**
     * @brief Returns Message about Condition.
     *
     * @return Condition's Message
     */
    virtual Message toString() = 0;
}; /* END class Condition */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null Condition for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullCondition : public Condition {
public:
    NullCondition() :
        Root()
        {}
    
    virtual void conditionQuery(
        Query& query
    ) {}

    virtual bool isNotNull() {
        return false;
    }

    virtual Message toString() {
        return Message("NullCondition");
    }
}; /* END class NullCondition */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_CONDITION_HPP__ */
