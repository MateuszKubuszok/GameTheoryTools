#include "gt/routines/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ExceptionFactory )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( ExceptionFactory_invalidCondition ) {
    // given
    std::runtime_error e("some error");

    // when
    GT::Routines::InvalidCondition exception = GT::Routines::ExceptionFactory::getInstance()
                                                 .invalidCondition(e);

    // then
    BOOST_CHECK_EQUAL(
        exception.what(),
        GT::Message() +
        "Invalid Condition: some error"
    );
}

BOOST_AUTO_TEST_CASE( ExceptionFactory_contradictoryConditions ) {
    // given
    // when
    GT::Routines::InvalidCondition exception = GT::Routines::ExceptionFactory::getInstance()
                                                 .contradictoryConditions();

    // then
    BOOST_CHECK_EQUAL(
        exception.what(),
        GT::Message() +
        "Contradictory conditions lead to an invalid configuration"
    );
}

BOOST_AUTO_TEST_CASE( ExceptionFactory_invalidGameType ) {
    // given
    GT::Identifier type("SomeType");

    // when
    GT::Routines::InvalidGameType exception = GT::Routines::ExceptionFactory::getInstance()
                                                 .invalidGameType(type);

    // then
    BOOST_CHECK_EQUAL(
        exception.what(),
        GT::Message() +
        "Invalid Game Type: SomeType expected"
    );
}

BOOST_AUTO_TEST_CASE( ExceptionFactory_playerNotFound ) {
    // given
    GT::Identifier identifier = GT::createIdentifier("identifier");

    // when
    GT::Routines::InvalidPlayerChoice exception = GT::Routines::ExceptionFactory::getInstance()
                                                 .playerNotFound(identifier);

    // then
    BOOST_CHECK_EQUAL(
        exception.what(),
        GT::Message() +
        "Player \"identifier\" do not exists"
    );
}

BOOST_AUTO_TEST_CASE( ExceptionFactory_strategyNotFound ) {
    // given
    GT::Identifier identifier1 = GT::createIdentifier("identifier1");
    GT::Identifier identifier2 = GT::createIdentifier("identifier2");

    // when
    GT::Routines::InvalidPlayerChoice exception = GT::Routines::ExceptionFactory::getInstance()
                                                 .strategyNotFound(identifier1, identifier2);

    // then
    BOOST_CHECK_EQUAL(
        exception.what(),
        GT::Message() +
        "There is no strategy \"identifier2\" for player \"identifier1\""
    );
}

BOOST_AUTO_TEST_CASE( ExceptionFactory_informationSetNotFound ) {
    // given
    GT::Identifier identifier1 = GT::createIdentifier("identifier1");
    GT::Identifier identifier2 = GT::createIdentifier("identifier2");

    // when
    GT::Routines::InvalidPlayerChoice exception = GT::Routines::ExceptionFactory::getInstance()
                                                 .informationSetNotFound(identifier1, identifier2);

    // then
    BOOST_CHECK_EQUAL(
        exception.what(),
        GT::Message() +
        "There is no information set \"identifier2\" for player \"identifier1\""
    );
}

BOOST_AUTO_TEST_CASE( ExceptionFactory_incompletePayoffInformation ) {
    // given
    GT::Identifier identifier1 = GT::createIdentifier("identifier1");
    GT::Identifier identifier2 = GT::createIdentifier("identifier2");

    // when
    GT::Routines::IncompletePayoffInformation exception = GT::Routines::ExceptionFactory::getInstance()
                                                 .incompletePayoffInformation(identifier1, identifier2);

    // then
    BOOST_CHECK_EQUAL(
        exception.what(),
        GT::Message() +
        "There is no Payoff information about \"identifier2\" for player \"identifier1\""
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
