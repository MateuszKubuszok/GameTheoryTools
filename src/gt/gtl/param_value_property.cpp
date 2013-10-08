#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class ParamValueProperty {
// public:

ParamValueProperty::ParamValueProperty(
    Param* owner
) :
    param(owner)
    {}

ResultPtr ParamValueProperty::findForConditions(
    const Context&,
    const Conditions&
) {
    return ResultFactory::getInstance().constResult(param->toString());
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
