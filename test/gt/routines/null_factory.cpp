#include "gt/routines/test_common.hpp"

BOOST_AUTO_TEST_SUITE( NullFactory )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( NullFactory_createCondition ) {
    // given
    // when
    GT::Routines::ConditionPtr result = GT::Routines::NullFactory::getInstance().createCondition();

    // then
    BOOST_REQUIRE(result);
    BOOST_CHECK(result->isNull());
    BOOST_CHECK(!result->isNotNull());
}

BOOST_AUTO_TEST_CASE( NullFactory_createConditions ) {
    // given
    // when
    GT::Routines::ConditionsPtr result = GT::Routines::NullFactory::getInstance().createConditions();

    // then
    BOOST_REQUIRE(result);
    BOOST_CHECK(result->empty());
}

BOOST_AUTO_TEST_CASE( NullFactory_createRoutine ) {
    // given
    // when
    GT::Routines::RoutinePtr result = GT::Routines::NullFactory::getInstance().createRoutine();

    // then
    BOOST_REQUIRE(result);
    BOOST_CHECK(result->isNull());
    BOOST_CHECK(!result->isNotNull());
}

BOOST_AUTO_TEST_CASE( NullFactory_createRoutines ) {
    // given
    // when
    GT::Routines::RoutinesPtr result = GT::Routines::NullFactory::getInstance().createRoutines();

    // then
    BOOST_REQUIRE(result);
    BOOST_CHECK(result->empty());
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
