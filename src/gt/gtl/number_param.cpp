#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//class NumberParam : public Param {
// public:

NumberParam::NumberParam(
    const NumberPtr number
) :
    Param(),
    value(number)
    {}

const ObjectPtr NumberParam::getObject(
    const Context&,
    VisitedIdentifiers&
) const {
    throw ExceptionFactory::getInstance().requiredUnavailableObjectFromParam();
}

const NumberPtr NumberParam::getNumber(
    const Context&,
    VisitedIdentifiers&
) const {
    return value;
}

Message NumberParam::toString() const {
    static const IdentifierPtr name  = createIdentifierPtr("NumberParam");
    MessagePtr                 val   = createMessagePtr(value);
    return ResultFactory::getInstance().buildResult()->addResult(name, val).build()->getResult();
}

// }; /* END class NumberParam */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
