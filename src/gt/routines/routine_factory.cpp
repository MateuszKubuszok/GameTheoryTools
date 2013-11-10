#include "gt/routines/inner_common.hpp"

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class RoutineFactory {

SINGLETON_DEFINITION(RoutineFactory, getInstance, routineFactoryMutex)

// public:

RoutinePtr RoutineFactory::pureStrategyEquilibriumFindingRoutineFor(
    const GamePtr
) const {
    return RoutinePtr(new NotYetImplementedRoutine());
}

RoutinePtr RoutineFactory::mixedStrategyEquilibriumFindingRoutineFor(
    const GamePtr
) const {
    return RoutinePtr(new NotYetImplementedRoutine());
}

RoutinePtr RoutineFactory::behaviourStrategyEquilibriumFindingRoutineFor(
    const GamePtr
) const {
    return RoutinePtr(new NotYetImplementedRoutine());
}

// private:

RoutineFactory::RoutineFactory() {}

RoutineFactory::~RoutineFactory() {}

// }; /* END class RoutineFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
