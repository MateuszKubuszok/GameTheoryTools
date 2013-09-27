#ifndef __GT_MODEL_RESULT_BUILDER_HPP__
#define __GT_MODEL_RESULT_BUILDER_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Builder used for creating Results displayed to user.
 *
 * @author Mateusz Kubuszok
 */
class ResultBuilder : public virtual Root {
public:
    /**
     * @brief Sets headers used for displaying records.
     *
     * <p>Size of headers must match size of each record.</p>
     *
     * @param   newProperties headers' names that will be used in a Result
     * @return                refernce to self for chaining
     *
     * @see #addRecord(IdentifierPtr&,MessagesPtr&)
     */
    virtual ResultBuilder& setHeaders(
        IdentifiersPtr& properties
    ) = 0;

    /**
     * @brief Adds record to displayed Result. 
     *
     * <p>Results size must match headers size.</p>
     *
     * @param object  name of added record
     * @param results properties that should be displayed
     * @return        refernce to self for chaining
     *
     * @see #setHeaders(IdentifiersPtr&)
     */
    virtual ResultBuilder& addRecord(
        IdentifierPtr& object,
        MessagesPtr&   results
    ) = 0;

    /**
     * @brief Adds single named subresult.
     *
     * @param name   name subresult is build 
     * @param result subresult
     * @result       reference for itself for chaining
     */
    virtual ResultBuilder& addResult(
        IdentifierPtr& name,
        MessagePtr&    result
    ) = 0;

    /**
     * @brief Build Result.
     * 
     * @return                   Result
     * @throw IllegalInnerState  thrown when number of Messages for any Object
     *                           does not match number of properties
     */
    virtual ResultPtr build() = 0;

    /**
     * @brief Build raw Result - one that can be inserted into other results.
     * 
     * @return                   Result
     * @throw IllegalInnerState  thrown when number of Messages for any Object
     *                           does not match number of properties
     */
    virtual ResultPtr buildRaw() = 0;
}; /* END class ResultBuilder */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null ResultBuilder for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullResultBuilder : public ResultBuilder {
public:
    virtual ResultBuilder& setHeaders(
        IdentifiersPtr& properties
    ) {
        return *this;
    }

    virtual ResultBuilder& addRecord(
        IdentifierPtr& object,
        MessagesPtr&   results
    ) {
        return *this;
    }

    virtual ResultBuilder& addResult(
        IdentifierPtr& name,
        MessagePtr&    result
    ) {
        return *this;
    }

    virtual ResultPtr build() {
        return NullFactory::getInstance().createResult();
    }

    virtual ResultPtr buildRaw() {
        return NullFactory::getInstance().createResult();
    }

    virtual bool isNotNull() {
        return false;
    }

    virtual Message toString() {
        return Message("NullResultBuilder");
    }
}; /* END class NullResultBuilder */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* END #ifndef __GT_MODEL_RESULT_BUILDER_HPP__ */
