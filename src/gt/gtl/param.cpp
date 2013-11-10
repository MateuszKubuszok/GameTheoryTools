#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class Param : public Object {
// public:

Param::Param() :
    Object(createIdentifier("Param"))
{
    registerProperty(Identifier("value"), ObjectPropertyPtr(new ParamValueProperty(this)));
}

const ObjectPtr Param::getObject(
    const Context& context
) const {
    VisitedIdentifiers visitedIdentifiers;
    return getObject(context, visitedIdentifiers);
}

const NumberPtr Param::getNumber(
    const Context& context
) const {
    VisitedIdentifiers visitedIdentifiers;
    return getNumber(context, visitedIdentifiers);
}

Param::operator const Param&() const {
    return *this;
}

// protected:

void Param::checkVisitedIdentifiers(
    const VisitedIdentifiers& visitedIdentifiers,
    const Identifier&         currentIdentifier
) const {
    for (const Identifier& visitedIdentifier : visitedIdentifiers)
        if (visitedIdentifier == currentIdentifier)
            throw ExceptionFactory::getInstance()
                .cyclicIdentifiersFound(visitedIdentifiers, currentIdentifier);
}

// }; /* END class Param */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
