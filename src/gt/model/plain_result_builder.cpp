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
    
    result << indent;
    BOOST_FOREACH(IdentifierPtr& property, (*properties))
        result << indent << (*property) << ',';
    result << std::endl;

    BOOST_FOREACH(PartialResult& partialResult, partialResults) {
        result << (*partialResult.first) << ':' << std::endl << indent;
        BOOST_FOREACH(MessagePtr& message, (*partialResult.second))
            result << indent << (*message) << ',';
        result << std::endl;
    }

    BOOST_FOREACH(SubResult& subResult, subResults)
        result << (*subResult.first) << ':' << std::endl
               << addIndent(*subResult.second);

    return ResultFactory::getInstance().constResult(Message(result.str()));
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
