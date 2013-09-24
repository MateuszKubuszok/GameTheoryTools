#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class AbstractResultBuilder {
// public:
    
AbstractResultBuilder::AbstractResultBuilder(
    Message indentation
) :
    properties(new Identifiers()),
    partialResults(),
    subResults(),
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

ResultBuilder& AbstractResultBuilder::addResult(
    IdentifierPtr& name, 
    MessagePtr&    result
) {
    subResults.push_back( SubResults::value_type(name, result) );
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
            throw ExceptionFactory::getInstance()
                .propertiesAndResultsDontMatchInSize(
                    properties->size(),
                    partialResult.second->size()
                );
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
