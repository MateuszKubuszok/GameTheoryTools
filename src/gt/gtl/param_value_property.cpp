#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ParamValueProperty : public ObjectProperty {
// public:

ParamValueProperty::ParamValueProperty(
    const Param* describedParam
) :
    param(describedParam)
    {}

ResultPtr ParamValueProperty::findForConditions(
    const Context&,
    const Conditions&
) const {
    return ResultFactory::getInstance().constResult(param->toString());
}

// }; /* END class ParamValueProperty */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
