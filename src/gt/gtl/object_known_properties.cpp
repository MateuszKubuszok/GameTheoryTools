#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class ObjectKnownProperties {
// public:

ObjectKnownProperties::ObjectKnownProperties(
    const Object* describedObject
) :
    object(describedObject)
    {}

ResultPtr ObjectKnownProperties::findForConditions(
    const Context&    context,
    const Conditions& conditions
) {
    // TODO: create ResultBuilder that fills it up
    return ResultFactory::getInstance().constResult(Message("TODO"));
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
