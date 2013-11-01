#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class Definition : public virtual ValidableSymbol {
// public:

Definition::Definition(
    IdentifierPtr definedName,
    ParamPtr      definedValue
) :
    name(definedName),
    value(definedValue)
    {}

IdentifierPtr Definition::getName() {
    return name;
}

ParamPtr Definition::getValue() {
    return value;
}

Message Definition::toString() {
    IdentifierPtr nam = createIdentifierPtr(name);
    MessagePtr    val = createMessagePtr(value->toString());
    return ResultFactory::getInstance().buildResult()->addResult(nam, val).build()->getResult();
}

// }; /* END class Definition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
