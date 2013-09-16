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
    const Context&    context,
    const Conditions& conditions
) {
    // TODO: create ResultBuilder that fills it up
    // make use oh param.getValue(context)
    return ResultFactory::getInstance().constResult(Message("TODO"));
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
