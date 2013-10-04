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

Context& Context::registerObject(
    IdentifierPtr identifier,
    ObjectPtr     object
) {
    return *this;
}

Context& Context::registerObject(
    DefinitionPtr definition
) {
    return *this;
}

ObjectPtr Context::getObject(
    Identifier& identifier
) {
    return NullFactory::getInstance().createObject();
}

ParamPtr Context::getParam(
    Identifier& identifier
) {
    return NullFactory::getInstance().createParam();
}

Message Context::toString() {
    return Message("NullContext");
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
