#include "gt/routines/test_common.hpp"

BOOST_AUTO_TEST_SUITE( NotYetImplementedRoutine )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( NotYetImplementedRoutine_findResultFor ) {
    // given
    GT::Model::GamePtr          game       = GT::Model::NullFactory::getInstance().createGame();
    GT::Routines::ConditionsPtr conditions = GT::Routines::NullFactory::getInstance().createConditions();

    // when
    GT::Routines::NotYetImplementedRoutine routine;
    GT::Model::ResultPtr                   result = routine.findResultFor(game, conditions);

    // then
    BOOST_CHECK_EQUAL(
        result->getResult(),
        GT::Message() +
        "Not yet implemented"
    );
}

BOOST_AUTO_TEST_CASE( NotYetImplementedRoutine_toString ) {
    // given
    // when
    GT::Routines::NotYetImplementedRoutine routine;

    // then
    BOOST_CHECK_EQUAL(
        routine.toString(),
        GT::Message() +
        "NotYetImplementedRoutine"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
