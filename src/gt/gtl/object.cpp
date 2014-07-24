/**
 * @file      gt/gtl/object.cpp
 * @brief     Defines GT::GTL::Object methods.
 * @copyright (C) 2013-2014
 * @author    Mateusz Kubuszok
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero
 * General Public License as published by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License along with this program. If not,
 * see [http://www.gnu.org/licenses/].
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using boost::adaptors::map_keys;
using boost::make_shared;

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
    registerProperty(Identifier("properties"), make_shared<ObjectKnownProperties>(this));
    registerProperty(Identifier("type"),       make_shared<ObjectTypeProperty>(this));
}

Object::Object(
    const Identifier type
) :
    Root(),
    registeredProperties(),
    typeName(createIdentifierPtr(type))
{
    registerProperty(Identifier("properties"), make_shared<ObjectKnownProperties>(this));
    registerProperty(Identifier("type"),       make_shared<ObjectTypeProperty>(this));
}

Object::~Object() {}

bool Object::respondsTo(
    const Identifier& propertyName
) const {
    return isPropertyRegistered(propertyName);
}

ResultPtr Object::describeProperty(
    const Identifier& propertyName
) const {
    return getProperty(propertyName)->getDescription();
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

    for (Identifier property : registeredProperties | map_keys)
        properties->push_back( createIdentifierPtr(property) );

    return properties;
}

const IdentifierPtr Object::type() const {
    return typeName;
}

Message Object::toString() const {
    return createMessage(typeName);
}

const Game& Object::toGame() const {
    return *noGame;
}

const Param& Object::toParam() const {
    return *noParam;
}

const Player& Object::toPlayer() const {
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
