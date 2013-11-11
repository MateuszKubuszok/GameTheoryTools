#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class PlainResultBuilder : public AbstractResultBuilder {
// public:

PlainResultBuilder::PlainResultBuilder(
    const Message indentation
) :
    AbstractResultBuilder(indentation)
    {}

ResultPtr PlainResultBuilder::build() const {
    return buildRaw();
}

ResultPtr PlainResultBuilder::buildRaw() const {
    checkPropertyToResultMatching();

    std::stringstream result;

    if (!propertiesNames->empty()) {
        bool firstProperty = true;
        for (IdentifierPtr& propertyName : (*propertiesNames)) {
            if (firstProperty)
                result << indent;
            else
                result << ',';
            result << indent << (*propertyName);

            firstProperty = false;
        }
        result << std::endl;

        for (const PartialResult& partialResult : partialResults) {
            Identifier recordName = *partialResult.first;
            Messages   properties = *partialResult.second;

            result << recordName << ':' << std::endl;
            firstProperty = true;
            for (MessagePtr& propertyValue : properties) {
                if (firstProperty)
                    result << indent;
                else
                    result << ',';
                result << indent << (*propertyValue);

                firstProperty = false;
            }
            result << std::endl;
        }
    }

    if (!subResults.empty()) {
        for (const SubResult& subResult : subResults) {
            Identifier resultName  = *subResult.first;
            Message    resultValue = *subResult.second;

            result << resultName << ':' << std::endl << addIndent(resultValue);
        }
    }

    return ResultFactory::getInstance().constResult(Message(result.str()));
}

// }; /* END class PlainResultBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
