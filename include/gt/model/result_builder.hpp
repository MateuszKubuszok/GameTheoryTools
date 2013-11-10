#ifndef __GT_MODEL_RESULT_BUILDER_HPP__
#define __GT_MODEL_RESULT_BUILDER_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Builder used for creating Results displayed to user.
 *
 * @author Mateusz Kubuszok
 *
 * @see Result
 * @see ResultFactory
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
        const IdentifiersPtr& properties
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
        const IdentifierPtr& object,
        const MessagesPtr&   results
    ) = 0;

    /**
     * @brief Adds single named subresult.
     *
     * @param name   name subresult is build
     * @param result subresult
     * @result       reference for itself for chaining
     */
    virtual ResultBuilder& addResult(
        const IdentifierPtr& name,
        const MessagePtr&    result
    ) = 0;

    /**
     * @brief Build Result.
     *
     * @return                   Result
     * @throw IllegalInnerState  thrown when number of Messages for any Object
     *                           does not match number of properties
     */
    virtual ResultPtr build() const = 0;

    /**
     * @brief Build raw Result - one that can be inserted into other results.
     *
     * @return                   Result
     * @throw IllegalInnerState  thrown when number of Messages for any Object
     *                           does not match number of properties
     */
    virtual ResultPtr buildRaw() const = 0;
}; /* END class ResultBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null ResultBuilder for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullResultBuilder : public ResultBuilder {
public:
    virtual ResultBuilder& setHeaders(
        const IdentifiersPtr&
    ) override {
        return *this;
    }

    virtual ResultBuilder& addRecord(
        const IdentifierPtr&,
        const MessagesPtr&
    ) override {
        return *this;
    }

    virtual ResultBuilder& addResult(
        const IdentifierPtr&,
        const MessagePtr&
    ) override {
        return *this;
    }

    virtual ResultPtr build() const override {
        return NullFactory::getInstance().createResult();
    }

    virtual ResultPtr buildRaw() const override {
        return NullFactory::getInstance().createResult();
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullResultBuilder");
    }
}; /* END class NullResultBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* END #ifndef __GT_MODEL_RESULT_BUILDER_HPP__ */
