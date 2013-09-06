#include "gt/gtl/common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

class ParamTypeProperty : public ObjectProperty {
public:
    ParamTypeProperty() {}

    virtual ResultPtr findForConditions(
        const Context&    context,
        const Conditions& conditions
    ) {
        return ResultFactory::getInstance().constResult(Message("Param"));
    }
}; /* END class ParamTypeProperty */

////////////////////////////////////////////////////////////////////////////////

class ParamValueProperty : public ObjectProperty {
    Param* param;
    
public: 
    ParamValueProperty(
        Param* owner
    ) :
        param(owner)
        {}
 
    virtual ResultPtr findForConditions(
        const Context&    context,
        const Conditions& conditions
    ) {
        // TODO: create ResultBuilder that fills it up
        // make use oh param.getValue(context)
        return ResultFactory::getInstance().constResult(Message("TODO"));
    }
}; /* END class ParamTypeProperty */

////////////////////////////////////////////////////////////////////////////////

// class Param
// public:
Param::Param() {
    registerProperty(Identifier("value"), ObjectPropertyPtr(new ParamValueProperty(this)));
    registerProperty(Identifier("type"),  ObjectPropertyPtr(new ParamTypeProperty()));
}
// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
