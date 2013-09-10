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
     * @brief Sets names of used properties.
     *
     * @param properties names of properties
     * @result           reference for itself for chaining
     */
    virtual ResultBuilder& setHeaders(
        IdentifiersPtr& properties
    ) = 0;

    /**
     * @brief Adds Object with its results.
     *
     * @param object  name of Object for which Result is build 
     * @param results results for each of queries properties
     * @result        reference for itself for chaining
     */
    virtual ResultBuilder& addRecord(
        IdentifierPtr& object,
        MessagesPtr&   results
    ) = 0;

    /**
     * @brief Build Result.
     * 
     * @return Result
     */
    virtual ResultPtr build() = 0;
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
        Identifiers& properties
    ) {
        return *this;
    }

    virtual ResultBuilder& addRecord(
        Identifier& object,
        Messages&   results
    ) {
        return *this;
    }

    virtual ResultPtr build() {
        return NullFactory::getInstance().createResult();
    }

    virtual Message toString() {
        return Message("NullResultBuilder");
    }
}; /* END class NullResultBuilder */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* END #ifndef __GT_MODEL_RESULT_BUILDER_HPP__ */
