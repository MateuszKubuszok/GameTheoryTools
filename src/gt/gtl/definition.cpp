#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class Definition {
// public:

Definition::Definition(
    IdentifierPtr definedName,
    ParamPtr      definedValue
) :
    name(definedName),
    value(definedValue)
    {}

Definition::~Definition() {}

IdentifierPtr Definition::getName() {
    return Model::NullFactory::getInstance().createIdentifier();
}

ParamPtr Definition::getValue() {
    return NullFactory::getInstance().createParam();
}

Message Definition::toString() {
    return Message("NullDefinition");
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
