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
    checkPropertyToResultMatching();

    int propertiesSize = properties->size();
    std::stringstream result;

    result << '{' << std::endl;

    BOOST_FOREACH(PartialResult& partialResult, partialResults) {
        result << indent << '"' << (*partialResult.first) << '"' << " : [" << std::endl;
        for (int property = 0; property < propertiesSize; property++)
            result  << indent << indent
                    << '"' << (*(*properties)[property]) << '"'
                    << " : "
                    << '"' << (*(*partialResult.second)[property]) << '"'
                    << ',' << std::endl;
        result << indent << "]," << std::endl;
    }

    result << '}' << std::endl;

    return ResultFactory::getInstance().constResult(Message(result.str()));
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
