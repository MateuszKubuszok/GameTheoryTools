#include "gt/routines/inner_common.hpp"

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class StrategicPureEquilibriumRoutine : public SelectableStrategiesRoutine {
// public:

ResultPtr StrategicPureEquilibriumRoutine::findResultFor(
    GamePtr,
    ConditionsPtr
) {
    return ResultFactory::getInstance().constResult(Message("Not yet implemented"));
}

Message StrategicPureEquilibriumRoutine::toString() {
    return Message("StrategicPureEquilibriumRoutine");
}

// }; /* END class StrategicPureEquilibriumRoutine */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
