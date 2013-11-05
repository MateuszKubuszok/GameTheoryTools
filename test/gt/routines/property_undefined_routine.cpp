#include "gt/routines/test_common.hpp"

BOOST_AUTO_TEST_SUITE( PropertyUndefinedRoutine )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( NotYetImplementedRoutine_findResultFor ) {
    // given
    GT::Model::GamePtr          game       = GT::Model::NullFactory::getInstance().createGame();
    GT::Routines::ConditionsPtr conditions = GT::Routines::NullFactory::getInstance().createConditions();

    // when
    GT::Routines::PropertyUndefinedRoutine routine;
    GT::Model::ResultPtr                   result = routine.findResultFor(game, conditions);

    // then
    BOOST_CHECK_EQUAL(
        result->getResult(),
        GT::Message() +
        "Property not defined for this kind of Game"
    );
}

BOOST_AUTO_TEST_CASE( NotYetImplementedRoutine_toString ) {
    // given
    // when
    GT::Routines::PropertyUndefinedRoutine routine;

    // then
    BOOST_CHECK_EQUAL(
        routine.toString(),
        GT::Message() +
        "PropertyUndefinedRoutine"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
