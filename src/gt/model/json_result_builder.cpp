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
    result << addIndent(buildRaw()->getResult());
    result << '}' << std::endl;

    return ResultFactory::getInstance().constResult(Message(result.str()));
}

ResultPtr JSONResultBuilder::buildRaw() {
    checkPropertyToResultMatching();

    int propertiesSize = properties->size();
    std::stringstream result;

    BOOST_FOREACH(PartialResult& partialResult, partialResults) {
        result << '"' << (*partialResult.first) << '"' << " : [" << std::endl;
        for (int property = 0; property < propertiesSize; property++)
            result << indent
                    << '"' << (*(*properties)[property]) << '"'
                    << " : "
                    << '"' << (*(*partialResult.second)[property]) << '"'
                    << ',' << std::endl;
        result << "]," << std::endl;
    }

    BOOST_FOREACH(SubResult& subResult, subResults)
        result << '"' << (*subResult.first) << '"'
               << " : "
               << (*subResult.second) << ','
               << std::endl;

    return ResultFactory::getInstance().constResult(Message(result.str()));
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
