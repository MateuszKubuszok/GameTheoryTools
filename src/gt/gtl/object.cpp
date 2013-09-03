#include <boost/foreach.hpp>

#include "gt/gtl/common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

class ObjectType : public ObjectProperty {
public:
    ObjectType() {}

    virtual ResultPtr findForConditions(
        const Context&    context,
        const Conditions& conditions
    ) {
        return ResultFactory::getInstance().constResult(Message("Object"));
    }
}; /* END class ObjectType */

////////////////////////////////////////////////////////////////////////////////

class ObjectKnownProperties : public ObjectProperty {
    const Object* object;

public:
    ObjectKnownProperties(
        const Object* describedObject
    ) :
        object(describedObject)
        {}

    virtual ResultPtr findForConditions(
        const Context&    context,
        const Conditions& conditions
    ) {
        // TODO: create ResultBuilder that fills it up
        return ResultFactory::getInstance().constResult(Message("TODO"));
    }
}; /* END class ObjectKnownProperties */

////////////////////////////////////////////////////////////////////////////////

// class Object {
// public:
Object::Object() :
    registeredProperties()
{
    registerProperty(Identifier("properties"), dynamic_cast<ObjectProperty*>(new ObjectKnownProperties(this)));
    registerProperty(Identifier("type"),       dynamic_cast<ObjectProperty*>(new ObjectType()));
}

Object::~Object() {
    // TODO
    // BOOST_FOREACH(std::pair<Identifier, ObjectProperty*> propertyPair, registeredProperties) {
    //     delete propertyPair->second_type;
    // };
}

bool Object::isValid() {
    return true;
}

bool Object::respondsTo(
    const Identifier propertyName
) {
    return isPropertyRegistered(propertyName);
}

ResultPtr Object::findProperty(
    const Context&   context,
    const Identifier propertyName
) {
    return findPropertyWithConditions(context, propertyName, noConditions);
}

ResultPtr Object::findPropertyWithConditions(
    const Context&    context,
    const Identifier  propertyName,
    const Conditions& conditions
) {
    return getProperty(propertyName)->findForConditions(context, conditions);
}

// protected:
bool Object::isPropertyRegistered(
    Identifier propertyName
) {
    return registeredProperties.count(propertyName);
}

ObjectProperty* Object::getProperty(
    Identifier propertyName
) {
    if (registeredProperties.count(propertyName))
        return registeredProperties[propertyName];
    throw std::invalid_argument("Property not found for this Object");
}

void Object::registerProperty(
    Identifier      propertyName,
    ObjectProperty* property
) {
    std::pair<Identifier, ObjectProperty*> pair = std::make_pair(propertyName, property);
    if (registeredProperties.count(propertyName))
        delete registeredProperties[propertyName];
    registeredProperties.insert(pair);
}
// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
