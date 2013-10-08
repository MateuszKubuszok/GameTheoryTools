#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class Context {
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
    IdentifierPtr identifier,
    ParamPtr      param
) {
    knownObjects.insert( KnownObjects::value_type(*identifier, param) );
    return *this;
}

Context& Context::registerParam(
    DefinitionPtr definition
) {
    knownObjects.insert( KnownObjects::value_type(*definition->getName(), definition->getValue()) );
    return *this;
}

bool Context::hasRegistered(
    Identifier& identifier
) {
    return knownObjects.count(identifier) || (parentContext && parentContext->hasRegistered(identifier));
}

NumberPtr Context::getNumber(
    Identifier& identifier
) {
    if (knownObjects.count(identifier))
        return knownObjects[identifier]->getNumber(*this);
    if (parentContext && parentContext->hasRegistered(identifier))
        return parentContext->getNumber(identifier);
    throw ExceptionFactory::getInstance().notDefinedParam(identifier);
}

ObjectPtr Context::getObject(
    Identifier& identifier
) {
    if (knownObjects.count(identifier))
        return knownObjects[identifier]->getObject(*this);
    if (parentContext && parentContext->hasRegistered(identifier))
        return parentContext->getObject(identifier);
    throw ExceptionFactory::getInstance().notDefinedParam(identifier);
}

ParamPtr Context::getParam(
    Identifier& identifier
) {
    if (knownObjects.count(identifier))
        return knownObjects[identifier];
    if (parentContext && parentContext->hasRegistered(identifier))
        return parentContext->getParam(identifier);
    throw ExceptionFactory::getInstance().notDefinedParam(identifier);
}

Message Context::toString() {
    ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();

    for (KnownObjects::value_type& objectPair : knownObjects) {
        IdentifierPtr name  = createIdentifierPtr(objectPair.first);
        MessagePtr    value = createMessagePtr(objectPair.second->toString());
        resultBuilder->addResult(name, value);
    }

    return resultBuilder->build()->getResult();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
