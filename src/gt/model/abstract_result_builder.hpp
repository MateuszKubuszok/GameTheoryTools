#ifndef __GT_MODEL_ABSTRACT_RESULT_BUILDER_HPP__
#define __GT_MODEL_ABSTRACT_RESULT_BUILDER_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

class AbstractResultBuilder : public ResultBuilder {
public:
    AbstractResultBuilder(
        Message indentation
    );

    virtual ResultBuilder& setHeaders(
        IdentifiersPtr& newProperties
    );

    virtual ResultBuilder& addRecord(
        IdentifierPtr& object,
        MessagesPtr&   results
    );

    virtual ResultBuilder& addResult(
        IdentifierPtr& name,
        MessagePtr&    result
    );

    virtual ResultPtr build() = 0;

    virtual ResultPtr buildRaw() = 0;

    virtual Message toString();

protected:
    typedef std::pair<IdentifierPtr, MessagesPtr>   PartialResult;
    typedef boost::container::vector<PartialResult> PartialResults;
    typedef std::pair<IdentifierPtr, MessagePtr>    SubResult;
    typedef boost::container::vector<SubResult>     SubResults;
    
    IdentifiersPtr properties;
    PartialResults partialResults;
    SubResults     subResults;
    Message        indent;

    void checkPropertyToResultMatching();

    Message addIndent(
        Message content
    );
}; /* END class AbstractResultBuilder */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_ABSTRACT_RESULT_BUILDER_HPP__ */
