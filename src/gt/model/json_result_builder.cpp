#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class JSONResultBuilder {
// public:
    
JSONResultBuilder::JSONResultBuilder(
    Message indentation
) :
    AbstractResultBuilder(indentation)
    {}

ResultPtr JSONResultBuilder::build() {
    std::stringstream result;

    result << '{' << std::endl;
    result << addIndent( buildRaw()->getResult() );
    result << '}' << std::endl;

    return ResultFactory::getInstance().constResult(Message(result.str()));
}

ResultPtr JSONResultBuilder::buildRaw() {
    checkPropertyToResultMatching();

    int propertiesSize = propertiesNames->size();
    std::stringstream result;

    if (propertiesSize > 0)
        BOOST_FOREACH(PartialResult& partialResult, partialResults) {
            Identifier recordName = *partialResult.first;
            Messages   properties = *partialResult.second;

            result << '"' << recordName << '"' << " : [" << std::endl;
            for (int property = 0; property < propertiesSize; property++) {
                Identifier propertyName  = *(*propertiesNames)[property];
                Message    propertyValue = *(*partialResult.second)[property];
                
                result << indent
                       << '"' << propertyName << '"'
                       << " : "
                       << '"' << propertyValue << '"'
                       << ',' << std::endl;
            }
            result << "]," << std::endl;
        }

    if (subResults.size() > 0)
        BOOST_FOREACH(SubResult& subResult, subResults) {
            Identifier resultName  = *subResult.first;
            Message    resultValue = *subResult.second;
            
            result << '"' << resultName << '"' << " : " << resultValue << ',' << std::endl;
        }

    return ResultFactory::getInstance().constResult(Message(result.str()));
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
