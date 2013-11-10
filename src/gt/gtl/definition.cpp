#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class Definition : public virtual ValidableSymbol {
// public:

Definition::Definition(
    const IdentifierPtr definedName,
    const ParamPtr      definedValue
) :
    name(definedName),
    value(definedValue)
    {}

const IdentifierPtr Definition::getName() const {
    return name;
}

const ParamPtr Definition::getValue() const {
    return value;
}

Message Definition::toString() const {
    IdentifierPtr nam = createIdentifierPtr(name);
    MessagePtr    val = createMessagePtr(value->toString());
    return ResultFactory::getInstance().buildResult()->addResult(nam, val).build()->getResult();
}

// }; /* END class Definition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
