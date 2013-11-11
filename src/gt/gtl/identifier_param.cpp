#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class IdentifierParam : public Param {
// public:

IdentifierParam::IdentifierParam(
    const Identifier& id
) :
    Param(),
    identifier(id)
    {}

const ObjectPtr IdentifierParam::getObject(
    const Context&      context,
    VisitedIdentifiers& visitedIdentifiers
) const {
    checkVisitedIdentifiers(visitedIdentifiers, identifier);
    visitedIdentifiers.insert(identifier);
    return context.getParam(identifier)->getObject(context, visitedIdentifiers);
}

const NumberPtr IdentifierParam::getNumber(
    const Context&      context,
    VisitedIdentifiers& visitedIdentifiers
) const {
    checkVisitedIdentifiers(visitedIdentifiers, identifier);
    visitedIdentifiers.insert(identifier);
    return context.getParam(identifier)->getNumber(context, visitedIdentifiers);
}

Message IdentifierParam::toString() const {
    static const IdentifierPtr name  = createIdentifierPtr("IdentifierParam");
    MessagePtr                 value = createMessagePtr(identifier);
    return ResultFactory::getInstance().buildResult()->addResult(name, value).build()->getResult();
}

// }; /* END class IdentifierParam */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
