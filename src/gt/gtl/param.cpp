#include "gt/gtl/common.hpp"

namespace GT {
namespace GTL {

class ParamValueProperty;

Param::Param() {
    registerProperty("value", ParamValueProperty(this));
}

class ParamValueProperty : ObjectProperty {
public: 
    Result findPropertyWithConditions(
        Context&    context,
        Conditions& conditions
    ) {
        // TODO: create ResultBuilder that fills it up
        // make use oh param.getValue(context)
        )
        return ResultFactory::getInstance()->constResult("TODO");
    }
    
private:
    Param& param;
}

} /* END namespace GTL */
} /* END namespace GT */
