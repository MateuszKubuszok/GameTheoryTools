#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class Object : public virtual ValidableSymbol {

GamePtr   Object::noGame   = ErrorFactory::getInstance().createGame("This Object is not a Game");

ParamPtr  Object::noParam  = ErrorFactory::getInstance().createParam("This Object is not a Param");

PlayerPtr Object::noPlayer = ErrorFactory::getInstance().createPlayer("This Object is not a Player");

// public:

Object::Object() :
    Root(),
    registeredProperties(),
    typeName(createIdentifierPtr("Object"))
{
    registerProperty(Identifier("properties"), ObjectPropertyPtr(new ObjectKnownProperties(this)));
    registerProperty(Identifier("type"),       ObjectPropertyPtr(new ObjectTypeProperty(this)));
}

Object::Object(
    Identifier type
) :
    Root(),
    registeredProperties(),
    typeName(createIdentifierPtr(type))
{
    registerProperty(Identifier("properties"), ObjectPropertyPtr(new ObjectKnownProperties(this)));
    registerProperty(Identifier("type"),       ObjectPropertyPtr(new ObjectTypeProperty(this)));
}

Object::~Object() {}

bool Object::respondsTo(
    Identifier& propertyName
) {
    return isPropertyRegistered(propertyName);
}

ResultPtr Object::findProperty(
    const Context& context,
    Identifier&    propertyName
) {
    ConditionsPtr noConditions = NullFactory::getInstance().createConditions();
    return findPropertyWithConditions(context, propertyName, *noConditions);
}

ResultPtr Object::findPropertyWithConditions(
    const Context&    context,
    Identifier&       propertyName,
    const Conditions& conditions
) {
    return getProperty(propertyName)->findForConditions(context, conditions);
}

IdentifiersPtr Object::listProperties() {
    IdentifiersPtr properties = createIdentifiersPtr();

    for (Identifier property : registeredProperties | boost::adaptors::map_keys)
        properties->push_back( createIdentifierPtr(property) );

    return properties;
}

IdentifierPtr Object::type() {
    return typeName;
}

Message Object::toString() {
    return createMessage(typeName);
}

Object::operator Game&() {
    return *noGame;
}

Object::operator Param&() {
    return *noParam;
}

Object::operator Player&() {
    return *noPlayer;
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
    throw ExceptionFactory::getInstance().invalidObjectProperty(propertyName);
}

void Object::registerProperty(
    Identifier        propertyName,
    ObjectPropertyPtr property
) {
    registeredProperties.insert( ObjectPropertyMap::value_type(propertyName, property) );
}

// }; /* END class Object */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
