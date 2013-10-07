#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

//class ObjectParam {
// public:

ObjectParam::ObjectParam(
    ObjectPtr object
) :
    Param(),
    value(object)
    {}

ObjectPtr ObjectParam::getObject(
    Context&            context,
    VisitedIdentifiers& visitedIdentifiers 
) {
    return value;
}

NumberPtr ObjectParam::getNumber(
    Context&            context,
    VisitedIdentifiers& visitedIdentifiers
) {
    throw ExceptionFactory::getInstance().requiredUnavailableNumberFromParam();
}

Message ObjectParam::toString() {
    IdentifierPtr name  = createIdentifierPtr("ObjectParam");
    MessagePtr    val   = createMessagePtr(value->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, val).build()->getResult();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
