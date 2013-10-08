#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

//class NumberParam {
// public:

NumberParam::NumberParam(
    NumberPtr number
) :
    Param(),
    value(number)
    {}

ObjectPtr NumberParam::getObject(
    Context&,
    VisitedIdentifiers& 
) {
    throw ExceptionFactory::getInstance().requiredUnavailableObjectFromParam();
}

NumberPtr NumberParam::getNumber(
    Context&,
    VisitedIdentifiers&
) {
    return value;
}

Message NumberParam::toString() {
    IdentifierPtr name  = createIdentifierPtr("NumberParam");
    MessagePtr    val   = createMessagePtr(value);
    return ResultFactory::getInstance().buildResult()->addResult(name, val).build()->getResult();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
