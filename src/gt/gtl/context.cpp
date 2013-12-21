/**
 * @file      gt/gtl/context.cpp
 * @brief     Defines GT::GTL::Context methods.
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

// class Context : public virtual Root {
// public:

Context::Context() :
    parentContext(),
    knownObjects()
    {}

Context::Context(
    const ContextPtr parentContext
) :
    parentContext(parentContext),
    knownObjects()
    {}

Context::~Context() {}

Context& Context::registerParam(
    const IdentifierPtr identifier,
    const ParamPtr      param
) {
    knownObjects.insert( KnownObjects::value_type(*identifier, param) );
    return *this;
}

Context& Context::registerParam(
    const DefinitionPtr definition
) {
    knownObjects.insert( KnownObjects::value_type(*definition->getName(), definition->getValue()) );
    return *this;
}

bool Context::hasRegistered(
    const Identifier& identifier
) const {
    return knownObjects.count(identifier) || (parentContext && parentContext->hasRegistered(identifier));
}

const NumberPtr Context::getNumber(
    const Identifier& identifier
) const {
    if (knownObjects.count(identifier))
        return knownObjects.at(identifier)->getNumber(*this);
    if (parentContext && parentContext->hasRegistered(identifier))
        return parentContext->getNumber(identifier);
    throw ExceptionFactory::getInstance().notDefinedParam(identifier);
}

const ObjectPtr Context::getObject(
    const Identifier& identifier
) const {
    if (knownObjects.count(identifier))
        return knownObjects.at(identifier)->getObject(*this);
    if (parentContext && parentContext->hasRegistered(identifier))
        return parentContext->getObject(identifier);
    throw ExceptionFactory::getInstance().notDefinedParam(identifier);
}

const ParamPtr Context::getParam(
    const Identifier& identifier
) const {
    if (knownObjects.count(identifier))
        return knownObjects.at(identifier);
    if (parentContext && parentContext->hasRegistered(identifier))
        return parentContext->getParam(identifier);
    throw ExceptionFactory::getInstance().notDefinedParam(identifier);
}

Message Context::toString() const {
    ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();

    for (const KnownObjects::value_type& objectPair : knownObjects) {
        IdentifierPtr name  = createIdentifierPtr(objectPair.first);
        MessagePtr    value = createMessagePtr(objectPair.second->toString());
        resultBuilder->addResult(name, value);
    }

    return resultBuilder->build()->getResult();
}

// }; /* END class Context */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
