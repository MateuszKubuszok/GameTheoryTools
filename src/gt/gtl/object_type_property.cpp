#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class ObjectTypeProperty {
// public:

ObjectTypeProperty::ObjectTypeProperty() {}

ResultPtr ObjectTypeProperty::findForConditions(
    const Context&    context,
    const Conditions& conditions
) {
    return ResultFactory::getInstance().constResult(Message("Object"));
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
