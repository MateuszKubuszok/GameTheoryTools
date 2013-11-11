#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

//class ObjectParam {
// public:

ObjectParam::ObjectParam(
    const ObjectPtr object
) :
    Param(),
    value(object)
    {}

const ObjectPtr ObjectParam::getObject(
    const Context&,
    VisitedIdentifiers&
) const {
    return value;
}

const NumberPtr ObjectParam::getNumber(
    const Context&,
    VisitedIdentifiers&
) const {
    throw ExceptionFactory::getInstance().requiredUnavailableNumberFromParam();
}

Message ObjectParam::toString() const {
    static const IdentifierPtr name  = createIdentifierPtr("ObjectParam");
    MessagePtr                 val   = createMessagePtr(value->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, val).build()->getResult();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
