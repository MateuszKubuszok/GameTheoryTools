#include <boost/foreach.hpp>

#include "gt/gtl/object.hpp"

namespace GT {
namespace GTL {

/* Class declarations */
class ObjectType;

// class Object {
// public:
Object::Object() :
    registeredProperties()
{
    registerProperty("properties", ObjectKnownProperties(this));
    registerProperty("type", ObjectType());
}

Object::~Object() {
    BOOST_FOREACH(ObjectProperty& property, registeredProperties) {
        delete property;
    }
    delete registeredProperties;
}

bool Object::isValid() {
    return true;
}

bool Object::respondsTo(
    const Identifier& propertyName
) {
    return isPropertyRegistered(propertyName);
}

Result Object::findProperty(
    const Context&    context,
    const Identifier& propertyName
) {
    return findPropertyWithConditions(context, propertyName, noConditions);
}

Result Object::findPropertyWithConditions(
    const Context&    context,
    const Identifier& propertyName,
    const Conditions& conditions
) {
    return getProperty(propertyName)(context, conditions);
}

// protected:
bool Object::isPropertyRegistered(
    const Identifier& propertyName
) {
    return registeredProperties.count(propertyName);
}

ObjectProperty Object::getProperty(
    const Identifier& propertyName
) {
    if (registeredProperties.count(propertyName))
        return registeredProperties[propertyName];
    throw std::invalid_argument("Property not found for this Object");
}

void Object::registerProperty(
    const Identifier&     propertyName,
    const ObjectProperty& property
) {
    if (registeredProperties.count(propertyName))
        delete registeredProperties[propertyName];
    registeredProperties[propertyName] = property;
}
// }

// class ObjectKnownProperties
// public:
Result ObjectKnownProperties::findPropertyWithConditions(
    const Context&    context,
    const Conditions& conditions
) {
    // TODO: create ResultBuilder that fills it up
    return ResultFactory::getInstance()->constResult("TODO");;
}
// }

class ObjectType : public ObjectProperty {
public:
    Result findForConditions(
        const Context&    context,
        const Conditions& conditions
    ) {
        return ResultFactory::getInstance()->constResult("Object");
    }
} /* END class ObjectType */

} /* END namespace GTL */
} /* END namespace GT */
