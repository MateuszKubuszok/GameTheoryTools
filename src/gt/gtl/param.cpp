#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class Param : public Object {
// public:

Param::Param() :
    Object(createIdentifier("Param"))
{
    registerProperty(Identifier("referred_properties"), ObjectPropertyPtr(new ParamKnownProperties(this)));
    registerProperty(Identifier("value"),               ObjectPropertyPtr(new ParamValueProperty(this)));
}

ResultPtr Param::findProperty(
    const Context&    context,
    const Identifier& propertyName
) const {
    try {
        const ObjectPtr object = getObject(context);
        if (object->respondsTo(propertyName))
            return object->findProperty(context, propertyName);
    } catch (const CyclicIdentifiers&) {
    } catch (const InvalidContentRequest&) {
    } catch (const NotDefinedParam&) {}

    return Object::findProperty(context, propertyName);
}

ResultPtr Param::findPropertyWithConditions(
    const Context&    context,
    const Identifier& propertyName,
    const Conditions& conditions
) const {
    try {
        const ObjectPtr object = getObject(context);
        if (object->respondsTo(propertyName))
            return object->findPropertyWithConditions(context, propertyName, conditions);
    } catch (const CyclicIdentifiers&) {
    } catch (const InvalidContentRequest&) {
    } catch (const NotDefinedParam&) {}

    return Object::findPropertyWithConditions(context, propertyName, conditions);
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
