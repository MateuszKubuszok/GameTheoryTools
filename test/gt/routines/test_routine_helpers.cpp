#include "gt/routines/test_common.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class TestSelectableStrategiesRoutineImpl : public GT::Routines::SelectableStrategiesRoutine {
// public:

TestSelectableStrategiesRoutineImpl::TestSelectableStrategiesRoutineImpl(
    const GT::Model::PlayersPtr players
) :
    GT::Routines::SelectableStrategiesRoutine(players)
    {}

GT::Model::ResultPtr TestSelectableStrategiesRoutineImpl::findResultFor(
    const GT::Routines::GamePtr,
    const GT::Routines::ConditionsPtr
) const {
    return GT::Model::NullFactory::getInstance().createResult();
}

GT::Message TestSelectableStrategiesRoutineImpl::toString() const {
    return GT::Message("TestSelectableStrategiesRoutineImpl");
}

// }; /* class TestSelectableStrategiesRoutineImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
