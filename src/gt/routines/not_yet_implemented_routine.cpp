#include "gt/routines/inner_common.hpp"

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class NotYetImplementedRoutine : public Routine {
// public:

ResultPtr NotYetImplementedRoutine::findResultFor(
    GamePtr,
    ConditionsPtr
) {
    return ResultFactory::getInstance().constResult(Message("Not yet implemented"));
}

Message NotYetImplementedRoutine::toString() {
    return Message("NotYetImplementedRoutine");
}

// }; /* END class NotYetImplementedRoutine */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
