#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ParamValueProperty : public ObjectProperty {
// public:

ParamValueProperty::ParamValueProperty(
    Param* describedParam
) :
    param(describedParam)
    {}

ResultPtr ParamValueProperty::findForConditions(
    const Context&,
    const Conditions&
) {
    return ResultFactory::getInstance().constResult(param->toString());
}

// }; /* END class ParamValueProperty */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
