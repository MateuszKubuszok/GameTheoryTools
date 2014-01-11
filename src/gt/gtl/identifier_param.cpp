/**
 * @file      gt/gtl/identifier_param.cpp
 * @brief     Defines GT::GTL::IdentifierParam methods.
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

// class IdentifierParam final : public Param {
// public:

IdentifierParam::IdentifierParam(
    const Identifier& id
) :
    Param(),
    identifier(id)
    {}

const Identifier& IdentifierParam::getIdentifier() const {
    return identifier;
}

const ObjectPtr IdentifierParam::getObject(
    const Context&      context,
    VisitedIdentifiers& visitedIdentifiers
) const {
    checkVisitedIdentifiers(visitedIdentifiers, identifier);
    visitedIdentifiers.insert(identifier);
    return context.getParam(identifier)->getObject(context, visitedIdentifiers);
}

const NumberPtr IdentifierParam::getNumber(
    const Context&      context,
    VisitedIdentifiers& visitedIdentifiers
) const {
    checkVisitedIdentifiers(visitedIdentifiers, identifier);
    visitedIdentifiers.insert(identifier);
    return context.getParam(identifier)->getNumber(context, visitedIdentifiers);
}

Message IdentifierParam::serialize() const {
    return createMessage(identifier);
}

Message IdentifierParam::toString() const {
    static const IdentifierPtr name  = createIdentifierPtr("IdentifierParam");
    MessagePtr                 value = createMessagePtr(identifier);
    return ResultFactory::getInstance().buildResult()->addResult(name, value).build()->getResult();
}

// }; /* END class IdentifierParam */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
