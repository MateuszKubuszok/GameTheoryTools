#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class AbstractResultBuilder {
// public:
    
AbstractResultBuilder::AbstractResultBuilder(
    Message indentation
) :
    properties(),
    partialResults(),
    indent(indentation)
    {}

ResultBuilder& AbstractResultBuilder::setHeaders(
    IdentifiersPtr& newProperties
) {
    properties = newProperties;
    return *this;
}

ResultBuilder& AbstractResultBuilder::addRecord(
    IdentifierPtr& object,
    MessagesPtr&   results
) {
    partialResults.push_back( PartialResults::value_type(object, results) );
    return *this;
}

Message AbstractResultBuilder::toString() {
    return build()->getResult();
}

// protected:

void AbstractResultBuilder::checkPropertyToResultMatching() {
    int propertiesSize = properties->size();
    BOOST_FOREACH(PartialResult& partialResult, partialResults)
        if (partialResult.second->size() != propertiesSize)
            throw IllegalInnerState("Properties size and Result\'s size does not match");
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
