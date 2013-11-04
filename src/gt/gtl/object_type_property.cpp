#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ObjectTypeProperty : public ObjectProperty {
// public:

ObjectTypeProperty::ObjectTypeProperty(
    Object* describedObject
) :
    object(describedObject)
    {}

ResultPtr ObjectTypeProperty::findForConditions(
    const Context&,
    const Conditions&
) {
    IdentifierPtr name  = createIdentifierPtr("Type");
    MessagePtr    value = createMessagePtr(object->type());
    return ResultFactory::getInstance().buildResult()->addResult(name, value).build();
}

// }; /* END class ObjectTypeProperty */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
