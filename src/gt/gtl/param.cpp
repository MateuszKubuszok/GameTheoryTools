#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class Param
// public:

Param::Param() :
    Object(createIdentifier("Param"))
{
    registerProperty(Identifier("value"), ObjectPropertyPtr(new ParamValueProperty(this)));
}

ObjectPtr Param::getObject(
    Context& context
) {
    VisitedIdentifiers visitedIdentifiers;
    return getObject(context, visitedIdentifiers);
}

NumberPtr Param::getNumber(
    Context& context
) {
    VisitedIdentifiers visitedIdentifiers;
    return getNumber(context, visitedIdentifiers);
}

// protected:

void Param::checkVisitedIdentifiers(
    VisitedIdentifiers& visitedIdentifiers,
    Identifier&         currentIdentifier
) {
    BOOST_FOREACH(Identifier& visitedIdentifier, visitedIdentifiers) 
        if (visitedIdentifier == currentIdentifier)
            throw ExceptionFactory::getInstance().cyclicIdentifiersFound(visitedIdentifiers, currentIdentifier);
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
