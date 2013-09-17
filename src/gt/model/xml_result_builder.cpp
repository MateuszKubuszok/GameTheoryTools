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
    std::stringstream result;

    result << "<results>" << std::endl;
    result << addIndent(buildRaw()->getResult());
    result << "</results>" << std::endl;

    return ResultFactory::getInstance().constResult(Message(result.str()));
}

ResultPtr XMLResultBuilder::buildRaw() {
    checkPropertyToResultMatching();

    int propertiesSize = properties->size();
    std::stringstream result;

    BOOST_FOREACH(PartialResult& partialResult, partialResults) {
        result << '<' << (*partialResult.first) << '>' << std::endl;
        for (int property = 0; property < propertiesSize; property++)
            result << indent
                    << "<result"
                    << ' '
                    << "property=\"" << (*(*properties)[property]) << '"'
                    << ' '
                    << "value=\"" << (*(*partialResult.second)[property]) << '"'
                    << " />" << std::endl;
        result << '<' << '/' << (*partialResult.first) << '>' << std::endl;
    }

    BOOST_FOREACH(SubResult& subResult, subResults)
        result << '<' << (*subResult.first) << '>' << std::endl
               << addIndent(*subResult.second) << std::endl
               << '<' << '/' << (*subResult.first) << '>'
               << std::endl;

    return ResultFactory::getInstance().constResult(Message(result.str()));
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
