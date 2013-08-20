#include "gtl/object.hpp"

namespace GTL {
class ObjectType;

// class Object {
// public:
Object::Object() {
    registerProperty("type", new ObjectKnownProperties(this));
    registerProperty("type", new ObjectType());
}

Object::~Object() {
    // foreach delete
    delete registeredProperties;
}

bool Object::isValid() {
    return true;
}

bool Object::respondsTo(
    Identifier &propertyName
) {
    return isPropertyRegistered(propertyName);
}

Result& Object::findProperty(
    Identifier &propertyName
) {
    return findPropertyWithConditions(propertyName, noConditions);
}

Result& Object::findPropertyWithConditions(
    Identifier &propertyName,
    Conditions &conditions
) {
    return getProperty(propertyName)(conditions);
}

// protected:
bool Object::isPropertyRegistered(
    Identifier &propertyName
) {
    return registeredProperties.count(propertyName);
}

ObjectProperty Object::getProperty(
    Identifier &propertyName
) {
    if (registeredProperties.count(propertyName))
        return registeredProperties[propertyName];
    // TODO: add name of a property and object type
    throw std::invalid_argument("Property not found for this Object");
}

void Object::registerProperty(
    Identifier     &propertyName,
    ObjectProperty property
) {
    if (registeredProperties.count(propertyName))
        delete registeredProperties[propertyName];
    registeredProperties[propertyName] = property;
}
// }

// class ObjectKnownProperties
// public:
Result& ObjectKnownProperties::findPropertyWithConditions(
    Conditions conditions
) {
    // TODO: create ResultBuilder that fills it up
    return NULL;
}
// }

class ObjectType : ObjectProperty {
public:
    Result& findForConditions(
        Conditions &conditions
    ) {
        // TODO: create ResultBuilder that fills it up
        return NULL;
    }
}