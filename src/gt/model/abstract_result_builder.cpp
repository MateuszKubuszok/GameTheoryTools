#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class AbstractResultBuilder : public ResultBuilder {
// public:

AbstractResultBuilder::AbstractResultBuilder(
    const Message indentation
) :
    propertiesNames(new Identifiers()),
    partialResults(),
    subResults(),
    indent(indentation)
    {}

ResultBuilder& AbstractResultBuilder::setHeaders(
    const IdentifiersPtr& newPropertiesNames
) {
    propertiesNames = newPropertiesNames;
    return *this;
}

ResultBuilder& AbstractResultBuilder::addRecord(
    const IdentifierPtr& name,
    const MessagesPtr&   propertiesValues
) {
    partialResults.push_back( PartialResults::value_type(name, propertiesValues) );
    return *this;
}

ResultBuilder& AbstractResultBuilder::addResult(
    const IdentifierPtr& name,
    const MessagePtr&    result
) {
    subResults.push_back( SubResults::value_type(name, result) );
    return *this;
}

Message AbstractResultBuilder::toString() const {
    try {
        return build()->getResult();
    } catch (const IllegalInnerState& e) {
        return Message(e.what());
    }
}

// protected:

void AbstractResultBuilder::checkPropertyToResultMatching() const {
    Index propertiesSize = propertiesNames->size();
    for (const PartialResult& partialResult : partialResults) {
        MessagesPtr checkedProperties = partialResult.second;
        if (checkedProperties->size() != propertiesSize)
            throw ExceptionFactory::getInstance().propertiesAndResultsDontMatchInSize(
                propertiesSize,
                checkedProperties->size()
            );
    }
}

Message AbstractResultBuilder::addIndent(
    const Message content
) const {
    // do not use boost::container::vector here
    // - it causes memory access violation with split function
    std::vector<Message> lines;
    boost::split(lines, content, boost::is_any_of("\n"));

    std::stringstream result;
    for (Message& line : lines)
        if (!line.empty() && line != "\n")
            result << indent << line << std::endl;

    return result.str();
}

// }; /* END class AbstractResultBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
