#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class ParamTypeProperty {
// public:

ParamTypeProperty::ParamTypeProperty() {}

ResultPtr ParamTypeProperty::findForConditions(
    const Context&    context,
    const Conditions& conditions
) {
    return ResultFactory::getInstance().constResult(Message("Param"));
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
