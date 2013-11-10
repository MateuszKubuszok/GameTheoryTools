#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class XMLResultBuilder : public AbstractResultBuilder {
// public:

XMLResultBuilder::XMLResultBuilder(
    Message indentation
) :
    AbstractResultBuilder(indentation)
    {}

ResultPtr XMLResultBuilder::build() const {
    std::stringstream result;

    result << "<results>" << std::endl;
    result << addIndent( buildRaw()->getResult() );
    result << "</results>" << std::endl;

    return ResultFactory::getInstance().constResult(Message(result.str()));
}

ResultPtr XMLResultBuilder::buildRaw() const {
    checkPropertyToResultMatching();

    int propertiesSize = propertiesNames->size();
    std::stringstream result;

    if (propertiesSize > 0)
        for (const PartialResult& partialResult : partialResults) {
            Identifier recordName = *partialResult.first;
            Messages   properties = *partialResult.second;

            result << '<' << recordName << '>' << std::endl;
            for (int property = 0; property < propertiesSize; property++) {
                Identifier propertyName  = *(*propertiesNames)[property];
                Message    propertyValue = *(*partialResult.second)[property];

                result << indent
                        << "<result"
                        << ' '
                        << "property=\"" << propertyName << '"'
                        << ' '
                        << "value=\"" << propertyValue << '"'
                        << " />" << std::endl;
            }
            result << '<' << '/' << recordName << '>' << std::endl;
        }

    if (subResults.size() > 0)
        for (const SubResult& subResult : subResults) {
            Identifier resultName  = *subResult.first;
            Message    resultValue = *subResult.second;

            result << '<' << resultName << '>' << std::endl
                   << addIndent( resultValue )
                   << '<' << '/' << resultName << '>'
                   << std::endl;
        }

    return ResultFactory::getInstance().constResult(Message(result.str()));
}

// }; /* END class XMLResultBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
