#include "gt/routines/test_common.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class TestSelectableStrategiesRoutineImpl : public GT::Routines::SelectableStrategiesRoutine {
// public:

TestSelectableStrategiesRoutineImpl::TestSelectableStrategiesRoutineImpl(
    GT::Model::PlayersPtr players
) :
    GT::Routines::SelectableStrategiesRoutine(players)
    {}

GT::Model::ResultPtr TestSelectableStrategiesRoutineImpl::findResultFor(
    GT::Routines::GamePtr,
    GT::Routines::ConditionsPtr
) {
    return GT::Model::NullFactory::getInstance().createResult();
}

GT::Message TestSelectableStrategiesRoutineImpl::toString() {
    return GT::Message("TestSelectableStrategiesRoutineImpl");
}

// }; /* class TestSelectableStrategiesRoutineImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
