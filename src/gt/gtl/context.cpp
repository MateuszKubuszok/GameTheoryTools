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
