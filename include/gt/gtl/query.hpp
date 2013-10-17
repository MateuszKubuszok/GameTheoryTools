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
class Query : public virtual ValidableSymbol {
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

    virtual bool isNotNull() {
        return false;
    }

    virtual Message toString() {
        return Message("NullQuery");
    }
}; /* END class NullQuery */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Error Query for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class ErrorQuery : public Query {
    Message message;

public:
    ErrorQuery(
        Message errorMessage
    ) :
        message(errorMessage)
        {}

    virtual ResultPtr execute(
        Context&
    ) {
        return NullFactory::getInstance().createResult();
    }

    virtual bool isValid() const {
        return false;
    }

    virtual Message toString() {
        return message;
    }
}; /* END class ErrorQuery */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_QUERY_HPP__ */
