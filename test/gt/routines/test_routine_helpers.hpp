#ifndef __GT_ROUTINES_TEST_ROUTINE_HELPERS_HPP__
#define __GT_ROUTINES_TEST_ROUTINE_HELPERS_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class TestSelectableStrategiesRoutineImpl : public GT::Routines::SelectableStrategiesRoutine {
public:
    TestSelectableStrategiesRoutineImpl(
        const GT::Model::PlayersPtr players
    );

    virtual GT::Model::ResultPtr findResultFor(
        const GT::Routines::GamePtr,
        const GT::Routines::ConditionsPtr
    ) override;

    virtual GT::Message toString() const override;
}; /* END class TestSelectableStrategiesRoutineImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif /* END #ifndef __GT_ROUTINES_TEST_ROUTINE_HELPERS_HPP__ */
