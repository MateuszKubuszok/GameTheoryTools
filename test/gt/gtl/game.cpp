#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( Game )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using boost::make_shared;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( Game_pureEquilibrium ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

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
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

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

BOOST_AUTO_TEST_CASE( Game_behaviorEquilibrium ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::GTL::ContextPtr    contextPtr    = GT::GTL::NullFactory::getInstance().createContext();
    GT::GTL::Context       context       = *contextPtr;
    GT::GTL::ConditionsPtr conditionsPtr = GT::GTL::NullFactory::getInstance().createConditions();
    GT::GTL::Conditions    conditions    = *conditionsPtr;

    GT::Model::GamePtr gameImplementation = GT::Model::NullFactory::getInstance().createGame();

    // when
    GT::GTL::Game game(gameImplementation);

    // then
    BOOST_CHECK_EQUAL(
        game.behaviorEquilibrium(context, conditions)->getResult(),
        GT::Message("Not yet implemented")
    );
}

BOOST_AUTO_TEST_CASE( Game_respondsTo ) {
    // given
    GT::Identifier properties  = GT::createIdentifier("properties");
    GT::Identifier type        = GT::createIdentifier("type");
    GT::Identifier pureEqu     = GT::createIdentifier("pure_equilibrium");
    GT::Identifier mixedEqu    = GT::createIdentifier("mixed_equilibrium");
    GT::Identifier behaviorEqu = GT::createIdentifier("behavior_equilibrium");
    GT::Identifier error       = GT::createIdentifier("error");

    GT::Model::GamePtr gameImplementation = GT::Model::NullFactory::getInstance().createGame();

    // when
    GT::GTL::Game game(gameImplementation);

    // then
    BOOST_CHECK(  game.respondsTo(properties) );
    BOOST_CHECK(  game.respondsTo(type) );
    BOOST_CHECK(  game.respondsTo(pureEqu) );
    BOOST_CHECK(  game.respondsTo(mixedEqu) );
    BOOST_CHECK(  game.respondsTo(behaviorEqu) );
    BOOST_CHECK( !game.respondsTo(error) );
}

BOOST_AUTO_TEST_CASE( Game_getGameType ) {
    // given
    GT::Model::GamePtr gameImplementation = GT::Model::NullFactory::getInstance().createGame();
    GT::IdentifierPtr  gameType           = GT::createIdentifierPtr("TEST");

    // when
    GT::GTL::Game game(gameImplementation, gameType);

    // then
    BOOST_CHECK_EQUAL(
        *game.getGameType(),
        *gameType
    );
}

BOOST_AUTO_TEST_CASE( Game_serialize ) {
    // given
    GT::IdentifierPtr  player1Name = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr  strategy1 = GT::createIdentifierPtr("p1s1");
    GT::IdentifiersPtr strategies1 = GT::createIdentifiersPtr();
    strategies1->push_back( strategy1 );
    GT::GTL::PlayerPtr player1 = make_shared<GT::GTL::Player>(player1Name, strategies1);

    GT::IdentifierPtr  player2Name = GT::createIdentifierPtr("p2");
    GT::IdentifierPtr  strategy2 = GT::createIdentifierPtr("p2s1");
    GT::IdentifiersPtr strategies2 = GT::createIdentifiersPtr();
    strategies2->push_back( strategy2 );
    GT::GTL::PlayerPtr player2 = make_shared<GT::GTL::Player>(player2Name, strategies2);

    GT::GTL::ObjectsPtr players = make_shared<GT::GTL::Objects>();
    players->push_back( boost::dynamic_pointer_cast<GT::GTL::Object>(player1) );
    players->push_back( boost::dynamic_pointer_cast<GT::GTL::Object>(player2) );

    GT::GTL::ParamsPtr payoff = make_shared<GT::GTL::Params>();
    payoff->push_back( GT::GTL::ParamFactory::getInstance().createParam(GT::createNumberPtr(10)) );
    payoff->push_back( GT::GTL::ParamFactory::getInstance().createParam(GT::createNumberPtr(20)) );

    GT::GTL::CoordinatePtr coordinate1 = make_shared<GT::GTL::Coordinate>(player1Name, strategy1);
    GT::GTL::CoordinatePtr coordinate2 = make_shared<GT::GTL::Coordinate>(player2Name, strategy2);
    coordinate2->addParams(payoff);
    coordinate1->addSubCoordinate(coordinate2);

    GT::GTL::CoordinatesPtr coordinates = make_shared<GT::GTL::Coordinates>();
    coordinates->push_back(coordinate1);

    GT::Model::GameBuilderPtr gameBuilder = GT::Model::GameFactory::getInstance().buildStrategicGame();
    GT::GTL::ContextPtr       context     = GT::GTL::NullFactory::getInstance().createContext();

    GT::Model::GamePtr gameImplementation = make_shared<GT::GTL::LazyGameProxy>(
        gameBuilder,
        players,
        coordinates,
        context.get()
    );

    // when
    GT::GTL::Game game(gameImplementation, GT::createIdentifierPtr("STRATEGIC"));

    // then
    BOOST_CHECK_EQUAL(
        game.serialize(),
        GT::Message() +
        "STRATEGIC GAME WITH\n"
        "  PLAYER p1 { p1s1 },\n"
        "  PLAYER p2 { p2s1 }\n"
        "SUCH AS\n"
        "  { p1 = p1s1 :\n"
        "    { p2 = p2s1 :\n"
        "      10.00000,\n"
        "      20.00000\n"
        "    }\n"
        "  }\n"
        "END"
    );
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

BOOST_AUTO_TEST_CASE( Game_Game ) {
    // given
    GT::Model::GamePtr gameImplementation = GT::Model::NullFactory::getInstance().createGame();

    // when
    GT::GTL::Game        game(gameImplementation);
    const GT::GTL::Game& gameRef = game;

    // then
    BOOST_CHECK_EQUAL(
        game,
        gameRef
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
