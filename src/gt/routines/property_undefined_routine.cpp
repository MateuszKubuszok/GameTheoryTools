#include "gt/routines/inner_common.hpp"

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class PropertyUndefinedRoutine : public Routine {
// public:

ResultPtr PropertyUndefinedRoutine::findResultFor(
    const GamePtr,
    const ConditionsPtr
) {
    return ResultFactory::getInstance().constResult(Message("Property not defined for this kind of Game"));
}

Message PropertyUndefinedRoutine::toString() const {
    return Message("PropertyUndefinedRoutine");
}

// }; /* END class PropertyUndefinedRoutine */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
