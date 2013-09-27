#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class AbstractResultBuilder {
// public:
    
AbstractResultBuilder::AbstractResultBuilder(
    Message indentation
) :
    propertiesNames(new Identifiers()),
    partialResults(),
    subResults(),
    indent(indentation)
    {}

ResultBuilder& AbstractResultBuilder::setHeaders(
    IdentifiersPtr& newPropertiesNames
) {
    propertiesNames = newPropertiesNames;
    return *this;
}

ResultBuilder& AbstractResultBuilder::addRecord(
    IdentifierPtr& name,
    MessagesPtr&   propertiesValues
) {
    partialResults.push_back( PartialResults::value_type(name, propertiesValues) );
    return *this;
}

ResultBuilder& AbstractResultBuilder::addResult(
    IdentifierPtr& name, 
    MessagePtr&    result
) {
    subResults.push_back( SubResults::value_type(name, result) );
    return *this;
}

Message AbstractResultBuilder::toString() {
    try {
        return build()->getResult();
    } catch (IllegalInnerState e) {
        return Message(e.what());
    }
}

// protected:

void AbstractResultBuilder::checkPropertyToResultMatching() {
    int propertiesSize = propertiesNames->size();
    BOOST_FOREACH(PartialResult& partialResult, partialResults) {
        MessagesPtr checkedProperties = partialResult.second;
        if (checkedProperties->size() != propertiesSize)
            throw ExceptionFactory::getInstance()
                .propertiesAndResultsDontMatchInSize(
                    propertiesSize,
                    checkedProperties->size()
                );
    }
}

Message AbstractResultBuilder::addIndent(
    Message content
) {
    // do not use boost::container::vector here
    // - it causes memory access violation with split function
    std::vector<Message> lines;
    boost::split(lines, content, boost::is_any_of("\n"));

    std::stringstream result;
    BOOST_FOREACH(Message& line, lines)
        if (!line.empty() && line != "\n")
            result << indent << line << std::endl;
    
    return result.str();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
