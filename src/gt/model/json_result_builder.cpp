#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class JSONResultBuilder : public AbstractResultBuilder {
// public:

JSONResultBuilder::JSONResultBuilder(
    const Message indentation
) :
    AbstractResultBuilder(indentation)
    {}

ResultPtr JSONResultBuilder::build() const {
    std::stringstream result;

    result << '{' << std::endl;
    result << addIndent( buildRaw()->getResult() );
    result << '}' << std::endl;

    return ResultFactory::getInstance().constResult(Message(result.str()));
}

ResultPtr JSONResultBuilder::buildRaw() const {
    checkPropertyToResultMatching();

    Index propertiesSize = propertiesNames->size();
    std::stringstream result;

    if (propertiesSize > 0) {
        bool firstPartial = true;
        for (const PartialResult& partialResult : partialResults) {
            if (!firstPartial)
                result << ',' << std::endl;

            Identifier recordName = *partialResult.first;
            Messages   properties = *partialResult.second;

            result << '"' << recordName << '"' << " : [";
            bool firstProperty = true;
            for (Index property = 0; property < propertiesSize; property++) {
                if (firstProperty)
                    result << std::endl;
                else
                    result << ',' << std::endl;

                Identifier propertyName  = *(*propertiesNames)[property];
                Message    propertyValue = *(*partialResult.second)[property];

                result << indent
                       << '"' << propertyName << '"'
                       << " : "
                       << '"' << propertyValue << '"';

                firstProperty = false;
            }
            result << std::endl << ']';

            firstPartial = false;
        }

        if (!subResults.empty())
            result << ',';
    }

    if (!subResults.empty()) {
        bool firstSubResult = true;
        for (const SubResult& subResult : subResults) {
            if (firstSubResult)
                result << std::endl;
            else
                result << ',' << std::endl;

            Identifier resultName  = *subResult.first;
            Message    resultValue = *subResult.second;

            result << '"' << resultName << '"' << " : " << resultValue;

            firstSubResult = false;
        }
        result << std::endl;
    }

    return ResultFactory::getInstance().constResult(Message(result.str()));
}

// }; /* END class JSONResultBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
