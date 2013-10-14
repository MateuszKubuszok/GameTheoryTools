#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ErrorFactory )

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( ErrorFactory_createCondition ) {
    // given
    GT::Message errorMessage("errorMessage");

    // when
    GT::GTL::ConditionPtr result = GT::GTL::ErrorFactory::getInstance().createCondition(errorMessage);

    // then
    BOOST_REQUIRE(result);
    BOOST_CHECK(result->isNotNull());
    BOOST_CHECK(!result->isValid());
    BOOST_CHECK_EQUAL(
        result->toString(),
        errorMessage
    );
}

BOOST_AUTO_TEST_CASE( ErrorFactory_createDefinition ) {
    // given
    GT::Message errorMessage("errorMessage");
    
    // when
    GT::GTL::DefinitionPtr result = GT::GTL::ErrorFactory::getInstance().createDefinition(errorMessage);

    // then
    BOOST_REQUIRE(result);
    BOOST_CHECK(result->isNotNull());
    BOOST_CHECK(!result->isValid());
    BOOST_CHECK_EQUAL(
        result->toString(),
        errorMessage
    );
}

BOOST_AUTO_TEST_CASE( ErrorFactory_createDetails ) {
    // given
    GT::Message errorMessage("errorMessage");
    
    // when
    GT::GTL::DetailsPtr result = GT::GTL::ErrorFactory::getInstance().createDetails(errorMessage);

    // then
    BOOST_REQUIRE(result);
    BOOST_CHECK(result->isNotNull());
    BOOST_CHECK(!result->isValid());
    BOOST_CHECK_EQUAL(
        result->toString(),
        errorMessage
    );
}

BOOST_AUTO_TEST_CASE( ErrorFactory_createGame ) {
    // given
    GT::Message errorMessage("errorMessage");
    
    // when
    GT::GTL::GamePtr result = GT::GTL::ErrorFactory::getInstance().createGame(errorMessage);

    // then
    BOOST_REQUIRE(result);
    BOOST_CHECK(result->isNotNull());
    BOOST_CHECK(!result->isValid());
    BOOST_CHECK_EQUAL(
        result->toString(),
        errorMessage
    );
}

BOOST_AUTO_TEST_CASE( ErrorFactory_createObject ) {
    // given
    GT::Message errorMessage("errorMessage");
    
    // when
    GT::GTL::ObjectPtr result = GT::GTL::ErrorFactory::getInstance().createObject(errorMessage);

    // then
    BOOST_REQUIRE(result);
    BOOST_CHECK(result->isNotNull());
    BOOST_CHECK(!result->isValid());
    BOOST_CHECK_EQUAL(
        result->toString(),
        errorMessage
    );
}

BOOST_AUTO_TEST_CASE( ErrorFactory_createParam ) {
    // given
    GT::Message errorMessage("errorMessage");
    
    // when
    GT::GTL::ParamPtr result = GT::GTL::ErrorFactory::getInstance().createParam(errorMessage);

    // then
    BOOST_REQUIRE(result);
    BOOST_CHECK(result->isNotNull());
    BOOST_CHECK(!result->isValid());
    BOOST_CHECK_EQUAL(
        result->toString(),
        errorMessage
    );
}

BOOST_AUTO_TEST_CASE( ErrorFactory_createPlayer ) {
    // given
    GT::Message errorMessage("errorMessage");
    
    // when
    GT::GTL::PlayerPtr result = GT::GTL::ErrorFactory::getInstance().createPlayer(errorMessage);

    // then
    BOOST_REQUIRE(result);
    BOOST_CHECK(result->isNotNull());
    BOOST_CHECK(!result->isValid());
    BOOST_CHECK_EQUAL(
        result->toString(),
        errorMessage
    );
}

BOOST_AUTO_TEST_CASE( ErrorFactory_createQuery ) {
    // given
    GT::Message errorMessage("errorMessage");
    
    // when
    GT::GTL::QueryPtr result = GT::GTL::ErrorFactory::getInstance().createQuery(errorMessage);

    // then
    BOOST_REQUIRE(result);
    BOOST_CHECK(result->isNotNull());
    BOOST_CHECK(!result->isValid());
    BOOST_CHECK_EQUAL(
        result->toString(),
        errorMessage
    );
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
