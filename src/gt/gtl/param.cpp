/**
 * @file      gt/gtl/param.cpp
 * @brief     Defines GT::GTL::Param methods.
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

const Param& Param::toParam() const {
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
