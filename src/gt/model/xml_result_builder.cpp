#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class XMLResultBuilder : public AbstractResultBuilder {
// public:

XMLResultBuilder::XMLResultBuilder(
    Message indentation
) :
    AbstractResultBuilder(indentation)
    {}

ResultPtr XMLResultBuilder::build() {
    checkPropertyToResultMatching();

    int propertiesSize = properties->size();
    std::stringstream result;

    result << "<results>" << std::endl;

    BOOST_FOREACH(PartialResult& partialResult, partialResults) {
        result << indent << '<' << (*partialResult.first) << '>' << std::endl;
        for (int property = 0; property < propertiesSize; property++)
            result  << indent << indent
                    << "<result"
                    << ' '
                    << "property=\"" << (*(*properties)[property]) << '"'
                    << ' '
                    << "value=\"" << (*(*partialResult.second)[property]) << '"'
                    << " />" << std::endl;
        result << indent << '<' << '/' << (*partialResult.first) << '>' << std::endl;
    }

    result << "</results>" << std::endl;

    return ResultFactory::getInstance().constResult(Message(result.str()));
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
