#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class IdentifierParam {
// public:

IdentifierParam::IdentifierParam(
    Identifier& id
) :
    identifier(id)
    {}

ObjectPtr IdentifierParam::getObject(
    Context& context
) {
    return context.getParam(identifier)->getObject(context);
}

NumberPtr IdentifierParam::getValue(
    Context& context
) {
    return context.getParam(identifier)->getValue(context);
}

Message IdentifierParam::toString() {
    return Message("Param:Identifier=") + identifier;
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
