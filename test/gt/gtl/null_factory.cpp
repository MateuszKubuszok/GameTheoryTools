#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( NullFactory )

BOOST_AUTO_TEST_CASE( NullFactory_createCondition ) {
    // given
    // when
    GT::GTL::ConditionPtr result = GT::GTL::NullFactory::getInstance().createCondition();

    // then
    BOOST_CHECK(result);
    BOOST_CHECK(result->isNull());
    BOOST_CHECK(!result->isNotNull());
}

BOOST_AUTO_TEST_CASE( NullFactory_createConditions ) {
    // given
    // when
    GT::GTL::ConditionsPtr result = GT::GTL::NullFactory::getInstance().createConditions();

    // then
    BOOST_CHECK(result);
    BOOST_CHECK(result->empty());
}

BOOST_AUTO_TEST_CASE( NullFactory_createContext ) {
    // given
    // when
    GT::GTL::ContextPtr result = GT::GTL::NullFactory::getInstance().createContext();

    // then
    BOOST_CHECK(result);
    BOOST_CHECK(result->isNull());
    BOOST_CHECK(!result->isNotNull());
}

BOOST_AUTO_TEST_CASE( NullFactory_createCoordinate ) {
    // given
    // when
    GT::GTL::CoordinatePtr result = GT::GTL::NullFactory::getInstance().createCoordinate();

    // then
    BOOST_CHECK(result);
    BOOST_CHECK(result->isNull());
    BOOST_CHECK(!result->isNotNull());
}

BOOST_AUTO_TEST_CASE( NullFactory_createCoordinates ) {
    // given
    // when
    GT::GTL::CoordinatesPtr result = GT::GTL::NullFactory::getInstance().createCoordinates();

    // then
    BOOST_CHECK(result);
    BOOST_CHECK(result->empty());
}

BOOST_AUTO_TEST_CASE( NullFactory_createDefinition ) {
    // given
    // when
    GT::GTL::DefinitionPtr result = GT::GTL::NullFactory::getInstance().createDefinition();

    // then
    BOOST_CHECK(result);
    BOOST_CHECK(result->isNull());
    BOOST_CHECK(!result->isNotNull());
}

BOOST_AUTO_TEST_CASE( NullFactory_createDetails ) {
    // given
    // when
    GT::GTL::DetailsPtr result = GT::GTL::NullFactory::getInstance().createDetails();

    // then
    BOOST_CHECK(result);
    BOOST_CHECK(result->isNull());
    BOOST_CHECK(!result->isNotNull());
}

BOOST_AUTO_TEST_CASE( NullFactory_createGame ) {
    // given
    // when
    GT::GTL::GamePtr result = GT::GTL::NullFactory::getInstance().createGame();

    // then
    BOOST_CHECK(result);
    BOOST_CHECK(result->isNull());
    BOOST_CHECK(!result->isNotNull());
}

BOOST_AUTO_TEST_CASE( NullFactory_createObject ) {
    // given
    // when
    GT::GTL::ObjectPtr result = GT::GTL::NullFactory::getInstance().createObject();

    // then
    BOOST_CHECK(result);
    BOOST_CHECK(result->isNull());
    BOOST_CHECK(!result->isNotNull());
}

BOOST_AUTO_TEST_CASE( NullFactory_createObjects ) {
    // given
    // when
    GT::GTL::ObjectsPtr result = GT::GTL::NullFactory::getInstance().createObjects();

    // then
    BOOST_CHECK(result);
    BOOST_CHECK(result->empty());
}

BOOST_AUTO_TEST_CASE( NullFactory_createParam ) {
    // given
    // when
    GT::GTL::ParamPtr result = GT::GTL::NullFactory::getInstance().createParam();

    // then
    BOOST_CHECK(result);
    BOOST_CHECK(result->isNull());
    BOOST_CHECK(!result->isNotNull());
}

BOOST_AUTO_TEST_CASE( NullFactory_createParams ) {
    // given
    // when
    GT::GTL::ParamsPtr result = GT::GTL::NullFactory::getInstance().createParams();

    // then
    BOOST_CHECK(result);
    BOOST_CHECK(result->empty());
}

BOOST_AUTO_TEST_CASE( NullFactory_createPlayer ) {
    // given
    // when
    GT::GTL::PlayerPtr result = GT::GTL::NullFactory::getInstance().createPlayer();

    // then
    BOOST_CHECK(result);
    BOOST_CHECK(result->isNull());
    BOOST_CHECK(!result->isNotNull());
}

BOOST_AUTO_TEST_CASE( NullFactory_createPositions ) {
    // when
    GT::PositionsPtr result = GT::GTL::NullFactory::getInstance().createPositions();

    // then
    BOOST_CHECK(result);
    BOOST_CHECK(result->empty());
}

BOOST_AUTO_TEST_CASE( NullFactory_createResult ) {
    // given
    // when
    GT::GTL::ResultPtr result = GT::GTL::NullFactory::getInstance().createResult();

    // then
    BOOST_CHECK(result);
    BOOST_CHECK(result->isNull());
    BOOST_CHECK(!result->isNotNull());
}

BOOST_AUTO_TEST_CASE( NullFactory_createQuery ) {
    // given
    // when
    GT::GTL::QueryPtr result = GT::GTL::NullFactory::getInstance().createQuery();

    // then
    BOOST_CHECK(result);
    BOOST_CHECK(result->isNull());
    BOOST_CHECK(!result->isNotNull());
}

BOOST_AUTO_TEST_SUITE_END()