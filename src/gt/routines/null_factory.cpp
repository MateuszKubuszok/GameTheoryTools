#include "gt/routines/inner_common.hpp"

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class NullFactory {

SINGLETON_DEFINITION(NullFactory, getInstance, nullFactoryMutex)

// public:

ConditionPtr NullFactory::createCondition() {
    return ConditionPtr(new NullCondition());
}

ConditionsPtr NullFactory::createConditions() {
    return ConditionsPtr(new Conditions());
}

RoutinePtr NullFactory::createRoutine() {
    return RoutinePtr(new NullRoutine());
}

RoutinesPtr NullFactory::createRoutines() {
    return RoutinesPtr(new Routines());
}

// private:

NullFactory::NullFactory() {}

NullFactory::~NullFactory() {}

// }; /* END class NullFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
