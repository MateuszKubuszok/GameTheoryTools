#ifndef __GT_MODEL_ABSTRACT_RESULT_BUILDER_HPP__
#define __GT_MODEL_ABSTRACT_RESULT_BUILDER_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Common base class of all actual implemetations used in Model.
 *
 * Implements ResultBuilder interface.
 *
 * @author Mateusz Kubuszok
 *
 * @see ResultBuilder
 */
class AbstractResultBuilder : public ResultBuilder {
public:
    /**
     * @brief Constructor initiating class with indentation. 
     *
     * @param indentation sequence used for indentation 
     */
    explicit AbstractResultBuilder(
        Message indentation
    );

    /**
     * @brief Sets headers used for displaying records.
     *
     * Size of headers must match size of each record. 
     *
     * @param   propertiesNames headers' names that will be used in a Result
     * @return                  refernce to self for chaining
     *
     * @see #addRecord(IdentifierPtr&,MessagesPtr&)
     */
    virtual ResultBuilder& setHeaders(
        IdentifiersPtr& propertiesNames
    );

    /**
     * @brief Adds record to displayed Result. 
     *
     * Results size must match headers size.
     *
     * @param name             name of added record
     * @param propertiesValues properties that should be displayed
     * @return                 refernce to self for chaining
     *
     * @see #setHeaders(IdentifiersPtr&)
     */
    virtual ResultBuilder& addRecord(
        IdentifierPtr& name,
        MessagesPtr&   propertiesValues
    );

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
    );

    /**
     * @brief Build Result.
     * 
     * @return                   Result
     * @throw IllegalInnerState  thrown when number of Messages for any Object
     *                           does not match number of properties
     *
     * @see #buildRaw()
     */
    virtual ResultPtr build() = 0;

    /**
     * @brief Build raw Result - one that can be inserted into other results.
     * 
     * @return                   Result
     * @throw IllegalInnerState  thrown when number of Messages for any Object
     *                           does not match number of properties
     *
     * @see #build()
     */
    virtual ResultPtr buildRaw() = 0;

    /**
     * Displays what would be build or error message that would be thrown.
     *
     * @return current result or error message
     *
     * @see #build()
     */
    virtual Message toString();

protected:
    typedef std::pair<IdentifierPtr, MessagesPtr>   PartialResult;
    typedef boost::container::vector<PartialResult> PartialResults;
    typedef std::pair<IdentifierPtr, MessagePtr>    SubResult;
    typedef boost::container::vector<SubResult>     SubResults;
    
    IdentifiersPtr propertiesNames;
    PartialResults partialResults;
    SubResults     subResults;
    Message        indent;

    /**
     * @brief Check whether all records has the same size as headers.
     * 
     * @throw IllegalInnerState thrown when some record does not match headers size
     */
    void checkPropertyToResultMatching();

    /**
     * @brief Adds indent to the beginning of each line of passes content.
     *
     * @param content content that should be indented 
     * @return        indented content
     */
    Message addIndent(
        Message content
    );
}; /* END class AbstractResultBuilder */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_ABSTRACT_RESULT_BUILDER_HPP__ */
