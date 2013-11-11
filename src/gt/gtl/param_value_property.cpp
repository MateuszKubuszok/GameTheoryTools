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
    const Context& context,
    const Conditions&
) const {
    Message content;
    try {
        content = param->getObject(context)->toString();
    } catch (const InvalidContentRequest&) {
        try {
            content = createMessage(param->getNumber(context));
        } catch (const InvalidContentRequest&) {
            content = param->toString();
        }
    }
    return ResultFactory::getInstance().constResult(content);
}

// }; /* END class ParamValueProperty */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
