#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class PlainResultBuilder {
// public:
    
PlainResultBuilder::PlainResultBuilder(
    Message indentation
) :
    AbstractResultBuilder(indentation)
    {}

ResultPtr PlainResultBuilder::build() {
    return buildRaw();
}

ResultPtr PlainResultBuilder::buildRaw() {
    checkPropertyToResultMatching();

    std::stringstream result;
    
    if (propertiesNames->size() > 0) {
        result << indent;
        for (IdentifierPtr& propertyName : (*propertiesNames))
            result << indent << (*propertyName) << ',';
        result << std::endl;

        for (PartialResult& partialResult : partialResults) {
            Identifier recordName = *partialResult.first;
            Messages   properties = *partialResult.second;

            result << recordName << ':' << std::endl << indent;
            for (MessagePtr& propertyValue : properties)
                result << indent << (*propertyValue) << ',';
            result << std::endl;
        }
    }

    if (subResults.size() > 0) {
        for (SubResult& subResult : subResults) {
            Identifier resultName  = *subResult.first;
            Message    resultValue = *subResult.second;

            result << resultName << ':' << std::endl << addIndent(resultValue);
        }
    }

    return ResultFactory::getInstance().constResult(Message(result.str()));
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
