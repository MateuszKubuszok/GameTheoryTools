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

    virtual ResultPtr build() = 0;

    virtual Message toString();

protected:
    typedef std::pair<IdentifierPtr, MessagesPtr>   PartialResult;
    typedef boost::container::vector<PartialResult> PartialResults;
    
    IdentifiersPtr properties;
    PartialResults partialResults;
    Message        indent;

    void checkPropertyToResultMatching();
}; /* END class AbstractResultBuilder */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_ABSTRACT_RESULT_BUILDER_HPP__ */
