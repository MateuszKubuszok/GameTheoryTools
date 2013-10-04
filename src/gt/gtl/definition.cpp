#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class Definition {
// public:

Definition::Definition(
    IdentifierPtr definedName,
    ObjectPtr     definedValue
) :
    name(definedName),
    value(definedValue)
    {}

Definition::~Definition() {}

IdentifierPtr Definition::getName() {
    return Model::NullFactory::getInstance().createIdentifier();
}

ObjectPtr Definition::getValue() {
    return NullFactory::getInstance().createObject();
}

Message Definition::toString() {
    return Message("NullDefinition");
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
