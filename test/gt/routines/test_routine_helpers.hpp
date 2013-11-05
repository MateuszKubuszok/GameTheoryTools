#ifndef __GT_ROUTINES_TEST_ROUTINE_HELPERS_HPP__
#define __GT_ROUTINES_TEST_ROUTINE_HELPERS_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class TestSelectableStrategiesRoutineImpl : public GT::Routines::SelectableStrategiesRoutine {
public:
    TestSelectableStrategiesRoutineImpl(
        GT::Model::PlayersPtr players
    );

    virtual GT::Model::ResultPtr findResultFor(
        GT::Routines::GamePtr,
        GT::Routines::ConditionsPtr
    );

    virtual GT::Message toString();
}; /* END class TestSelectableStrategiesRoutineImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif /* END #ifndef __GT_ROUTINES_TEST_ROUTINE_HELPERS_HPP__ */
