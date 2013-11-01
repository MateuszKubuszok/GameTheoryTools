#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class IdentifierParam : public Param {
// public:

IdentifierParam::IdentifierParam(
    Identifier& id
) :
    Param(),
    identifier(id)
    {}

ObjectPtr IdentifierParam::getObject(
    Context&            context,
    VisitedIdentifiers& visitedIdentifiers
) {
    checkVisitedIdentifiers(visitedIdentifiers, identifier);
    visitedIdentifiers.insert(identifier);
    return context.getParam(identifier)->getObject(context, visitedIdentifiers);
}

NumberPtr IdentifierParam::getNumber(
    Context&            context,
    VisitedIdentifiers& visitedIdentifiers
) {
    checkVisitedIdentifiers(visitedIdentifiers, identifier);
    visitedIdentifiers.insert(identifier);
    return context.getParam(identifier)->getNumber(context, visitedIdentifiers);
}

Message IdentifierParam::toString() {
    IdentifierPtr name  = createIdentifierPtr("IdentifierParam");
    MessagePtr    value = createMessagePtr(identifier);
    return ResultFactory::getInstance().buildResult()->addResult(name, value).build()->getResult();
}

// }; /* END class IdentifierParam */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
