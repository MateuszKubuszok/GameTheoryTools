#ifndef __GT_GTL_QUERY_HPP__
#define __GT_GTL_QUERY_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Defines Query.
 *
 * @author Mateusz Kubuszok
 */
class Query : public virtual Root {
public:
    /**
     * @brief Execute Query in a defined Context.
     *
     * @param context Context with definitions
     */
    virtual ResultPtr execute(
        Context& context
    ) = 0;

    /**
     * @brief Returns Query results.
     *
     * @result Query results
     */
    virtual Message getResult() = 0;

    /**
     * @brief Returns Query's Message.
     *
     * @return Message
     */
    virtual Message toString() = 0;
}; /* END class Query */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null Query for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullQuery : public Query {
public:
    virtual ResultPtr execute(
        Context&
    ) {
        return NullFactory::getInstance().createResult();
    }

    virtual Message getResult() {
        return Message("NullQuery");
    }

    virtual bool isNotNull() {
        return false;
    }

    virtual Message toString() {
        return Message("NullQuery");
    }
}; /* END class NullQuery */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_QUERY_HPP__ */
