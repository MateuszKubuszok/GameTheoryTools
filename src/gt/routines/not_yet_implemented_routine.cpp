#include "gt/routines/inner_common.hpp"

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class NotYetImplementedRoutine : public Routine {
// public:

ResultPtr NotYetImplementedRoutine::findResultFor(
    const GamePtr,
    const ConditionsPtr
) const {
    return ResultFactory::getInstance().constResult(Message("Not yet implemented"));
}

Message NotYetImplementedRoutine::toString() const {
    return Message("NotYetImplementedRoutine");
}

// }; /* END class NotYetImplementedRoutine */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
