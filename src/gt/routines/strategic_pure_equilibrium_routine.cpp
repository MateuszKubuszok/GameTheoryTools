#include "gt/routines/inner_common.hpp"

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class StrategicPureEquilibriumRoutine : public SelectableStrategiesRoutine {
// public:

StrategicPureEquilibriumRoutine::StrategicPureEquilibriumRoutine(
    const PlayersPtr players
) :
    SelectableStrategiesRoutine(players)
    {}

ResultPtr StrategicPureEquilibriumRoutine::findResultFor(
    const GamePtr,
    const ConditionsPtr
) const {
    return ResultFactory::getInstance().constResult(Message("Not yet implemented"));
}

Message StrategicPureEquilibriumRoutine::toString() const {
    return Message("StrategicPureEquilibriumRoutine");
}

// }; /* END class StrategicPureEquilibriumRoutine */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
