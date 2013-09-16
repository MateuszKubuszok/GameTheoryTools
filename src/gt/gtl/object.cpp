#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class Object {
// public:

Object::Object() :
    registeredProperties()
{
    registerProperty(Identifier("properties"), ObjectPropertyPtr(new ObjectKnownProperties(this)));
    registerProperty(Identifier("type"),       ObjectPropertyPtr(new ObjectTypeProperty()));
}

Object::~Object() {}

bool Object::isValid() {
    return true;
}

bool Object::respondsTo(
    Identifier& propertyName
) {
    return isPropertyRegistered(propertyName);
}

ResultPtr Object::findProperty(
    const Context& context,
    Identifier&    propertyName
) {
    return findPropertyWithConditions(context, propertyName, *noConditions);
}

ResultPtr Object::findPropertyWithConditions(
    const Context&    context,
    Identifier&       propertyName,
    const Conditions& conditions
) {
    return getProperty(propertyName)->findForConditions(context, conditions);
}

Message Object::toString() {
    return "Object";
}

// protected:

bool Object::isPropertyRegistered(
    Identifier& propertyName
) {
    return registeredProperties.count(propertyName);
}

ObjectPropertyPtr Object::getProperty(
    Identifier& propertyName
) {
    if (registeredProperties.count(propertyName))
        return registeredProperties[propertyName];
    throw std::invalid_argument("Property not found for this Object");
}

void Object::registerProperty(
    Identifier        propertyName,
    ObjectPropertyPtr property
) {
    registeredProperties.insert( ObjectPropertyMap::value_type(propertyName, property) );
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
