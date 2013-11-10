#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class Object : public virtual ValidableSymbol {

const GamePtr   Object::noGame   = ErrorFactory::getInstance().createGame("This Object is not a Game");

const ParamPtr  Object::noParam  = ErrorFactory::getInstance().createParam("This Object is not a Param");

const PlayerPtr Object::noPlayer = ErrorFactory::getInstance().createPlayer("This Object is not a Player");

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
    const Identifier type
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
    const Identifier& propertyName
) const {
    return isPropertyRegistered(propertyName);
}

ResultPtr Object::findProperty(
    const Context&    context,
    const Identifier& propertyName
) const {
    ConditionsPtr noConditions = NullFactory::getInstance().createConditions();
    return findPropertyWithConditions(context, propertyName, *noConditions);
}

ResultPtr Object::findPropertyWithConditions(
    const Context&    context,
    const Identifier& propertyName,
    const Conditions& conditions
) const {
    return getProperty(propertyName)->findForConditions(context, conditions);
}

IdentifiersPtr Object::listProperties() const {
    IdentifiersPtr properties = createIdentifiersPtr();

    for (Identifier property : registeredProperties | boost::adaptors::map_keys)
        properties->push_back( createIdentifierPtr(property) );

    return properties;
}

const IdentifierPtr Object::type() const {
    return typeName;
}

Message Object::toString() const {
    return createMessage(typeName);
}

Object::operator const Game&() const {
    return *noGame;
}

Object::operator const Param&() const {
    return *noParam;
}

Object::operator const Player&() const {
    return *noPlayer;
}

// protected:

bool Object::isPropertyRegistered(
    const Identifier& propertyName
) const {
    return registeredProperties.count(propertyName);
}

const ObjectPropertyPtr Object::getProperty(
    const Identifier& propertyName
) const {
    if (registeredProperties.count(propertyName))
        return registeredProperties.at(propertyName);
    throw ExceptionFactory::getInstance().invalidObjectProperty(propertyName);
}

void Object::registerProperty(
    const Identifier        propertyName,
    const ObjectPropertyPtr property
) {
    registeredProperties.insert( ObjectPropertyMap::value_type(propertyName, property) );
}

// }; /* END class Object */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
