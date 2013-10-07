#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( Game )

BOOST_AUTO_TEST_CASE( Game_pureEquilibrium ) {
    // given
    GT::GTL::ContextPtr    contextPtr    = GT::GTL::NullFactory::getInstance().createContext();
    GT::GTL::Context       context       = *contextPtr;
    GT::GTL::ConditionsPtr conditionsPtr = GT::GTL::NullFactory::getInstance().createConditions();
    GT::GTL::Conditions    conditions    = *conditionsPtr;

    GT::Model::GamePtr gameImplementation = GT::Model::NullFactory::getInstance().createGame();

    // when
    GT::GTL::Game game(gameImplementation);

    // then
    BOOST_CHECK_EQUAL(
        game.pureEquilibrium(context, conditions)->getResult(),
        GT::Message("Not yet implemented")
    );
}

BOOST_AUTO_TEST_CASE( Game_mixedEquilibrium ) {
    // given
    GT::GTL::ContextPtr    contextPtr    = GT::GTL::NullFactory::getInstance().createContext();
    GT::GTL::Context       context       = *contextPtr;
    GT::GTL::ConditionsPtr conditionsPtr = GT::GTL::NullFactory::getInstance().createConditions();
    GT::GTL::Conditions    conditions    = *conditionsPtr;

    GT::Model::GamePtr gameImplementation = GT::Model::NullFactory::getInstance().createGame();

    // when
    GT::GTL::Game game(gameImplementation);

    // then
    BOOST_CHECK_EQUAL(
        game.mixedEquilibrium(context, conditions)->getResult(),
        GT::Message("Not yet implemented")
    );
}

BOOST_AUTO_TEST_CASE( Game_respondsTo ) {
    // given
    GT::Identifier properties = GT::createIdentifier("properties");
    GT::Identifier type       = GT::createIdentifier("type");
    GT::Identifier pureEqu    = GT::createIdentifier("pure_equilibrium");
    GT::Identifier mixedEqu   = GT::createIdentifier("mixed_equilibrium");
    GT::Identifier error      = GT::createIdentifier("error");

    GT::Model::GamePtr gameImplementation = GT::Model::NullFactory::getInstance().createGame();

    // when
    GT::GTL::Game game(gameImplementation);

    // then
    BOOST_CHECK(  game.respondsTo(properties) );
    BOOST_CHECK(  game.respondsTo(type) );
    BOOST_CHECK(  game.respondsTo(pureEqu) );
    BOOST_CHECK(  game.respondsTo(mixedEqu) );
    BOOST_CHECK( !game.respondsTo(error) );
}

BOOST_AUTO_TEST_CASE( Game_toString ) {
    // given
    GT::Model::GamePtr gameImplementation = GT::Model::NullFactory::getInstance().createGame();

    // when
    GT::GTL::Game game(gameImplementation);

    // then
    BOOST_CHECK_EQUAL(
        game.toString(),
        gameImplementation->toString()
    );
}

BOOST_AUTO_TEST_SUITE_END()