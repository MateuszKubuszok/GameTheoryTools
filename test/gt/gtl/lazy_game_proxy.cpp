#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( LazyGameBuilder )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( LazyGameBuilder_getCoordinates ) {
    // given
    GT::Model::GameBuilderPtr gameBuilder = GT::Model::GameFactory::getInstance().buildExtensiveGame();

    GT::IdentifierPtr  player1Name = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr  strategy1 = GT::createIdentifierPtr("p1s1");
    GT::IdentifiersPtr strategies1(new GT::Identifiers());
    strategies1->push_back( strategy1 );
    GT::GTL::PlayerPtr player1(new GT::GTL::Player(player1Name, strategies1));

    GT::IdentifierPtr  player2Name = GT::createIdentifierPtr("p2");
    GT::IdentifierPtr  strategy2 = GT::createIdentifierPtr("p2s1");
    GT::IdentifiersPtr strategies2(new GT::Identifiers());
    strategies2->push_back( strategy2 );
    GT::GTL::PlayerPtr player2(new GT::GTL::Player(player2Name, strategies2));

    GT::GTL::ObjectsPtr players(new GT::GTL::Objects());
    players->push_back( boost::dynamic_pointer_cast<GT::GTL::Object>(player1) );
    players->push_back( boost::dynamic_pointer_cast<GT::GTL::Object>(player2) );

    GT::GTL::ParamsPtr payoff(new GT::GTL::Params());
    payoff->push_back( GT::GTL::ParamFactory::getInstance().createParam(GT::createNumberPtr(10)) );
    payoff->push_back( GT::GTL::ParamFactory::getInstance().createParam(GT::createNumberPtr(20)) );

    GT::GTL::CoordinatePtr coordinate1(new GT::GTL::Coordinate(player1Name, strategy1) );
    GT::GTL::CoordinatePtr coordinate2(new GT::GTL::Coordinate(player2Name, strategy2));
    coordinate2->addParams(payoff);
    coordinate1->addSubCoordinate(coordinate2);

    GT::GTL::CoordinatesPtr coordinates(new GT::GTL::Coordinates());
    coordinates->push_back(coordinate1);

    GT::GTL::ContextPtr context = GT::GTL::NullFactory::getInstance().createContext();

    // when
    GT::GTL::LazyGameProxy  lazyGame(gameBuilder, players, coordinates, context.get());
    GT::GTL::CoordinatesPtr gotCoordinates;

    // then
    BOOST_REQUIRE_NO_THROW(
        gotCoordinates = GT::GTL::CoordinatesPtr(lazyGame.getCoordinates())
    );
    BOOST_REQUIRE( gotCoordinates );
    BOOST_CHECK_EQUAL(
        gotCoordinates->size(),
        1
    );
}

BOOST_AUTO_TEST_CASE( LazyGameBuilder_getPlayersParams ) {
    // given
    GT::Model::GameBuilderPtr gameBuilder = GT::Model::GameFactory::getInstance().buildExtensiveGame();

    GT::IdentifierPtr  player1Name = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr  strategy1 = GT::createIdentifierPtr("p1s1");
    GT::IdentifiersPtr strategies1(new GT::Identifiers());
    strategies1->push_back( strategy1 );
    GT::GTL::PlayerPtr player1(new GT::GTL::Player(player1Name, strategies1));

    GT::IdentifierPtr  player2Name = GT::createIdentifierPtr("p2");
    GT::IdentifierPtr  strategy2 = GT::createIdentifierPtr("p2s1");
    GT::IdentifiersPtr strategies2(new GT::Identifiers());
    strategies2->push_back( strategy2 );
    GT::GTL::PlayerPtr player2(new GT::GTL::Player(player2Name, strategies2));

    GT::GTL::ObjectsPtr players(new GT::GTL::Objects());
    players->push_back( boost::dynamic_pointer_cast<GT::GTL::Object>(player1) );
    players->push_back( boost::dynamic_pointer_cast<GT::GTL::Object>(player2) );

    GT::GTL::ParamsPtr payoff(new GT::GTL::Params());
    payoff->push_back( GT::GTL::ParamFactory::getInstance().createParam(GT::createNumberPtr(10)) );
    payoff->push_back( GT::GTL::ParamFactory::getInstance().createParam(GT::createNumberPtr(20)) );

    GT::GTL::CoordinatePtr coordinate1(new GT::GTL::Coordinate(player1Name, strategy1) );
    GT::GTL::CoordinatePtr coordinate2(new GT::GTL::Coordinate(player2Name, strategy2));
    coordinate2->addParams(payoff);
    coordinate1->addSubCoordinate(coordinate2);

    GT::GTL::CoordinatesPtr coordinates(new GT::GTL::Coordinates());
    coordinates->push_back(coordinate1);

    GT::GTL::ContextPtr context = GT::GTL::NullFactory::getInstance().createContext();

    // when
    GT::GTL::LazyGameProxy lazyGame(gameBuilder, players, coordinates, context.get());
    GT::GTL::ObjectsPtr    gotObjects;

    // then
    BOOST_REQUIRE_NO_THROW(
        gotObjects = GT::GTL::ObjectsPtr(lazyGame.getPlayersParams())
    );
    BOOST_REQUIRE( gotObjects );
    BOOST_CHECK_EQUAL(
        gotObjects->size(),
        2
    );
}

BOOST_AUTO_TEST_CASE( LazyGameBuilder_getPlayers ) {
    // given
    GT::Model::GameBuilderPtr gameBuilder = GT::Model::GameFactory::getInstance().buildExtensiveGame();

    GT::IdentifierPtr  player1Name = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr  strategy1 = GT::createIdentifierPtr("p1s1");
    GT::IdentifiersPtr strategies1(new GT::Identifiers());
    strategies1->push_back( strategy1 );
    GT::GTL::PlayerPtr player1(new GT::GTL::Player(player1Name, strategies1));

    GT::IdentifierPtr  player2Name = GT::createIdentifierPtr("p2");
    GT::IdentifierPtr  strategy2 = GT::createIdentifierPtr("p2s1");
    GT::IdentifiersPtr strategies2(new GT::Identifiers());
    strategies2->push_back( strategy2 );
    GT::GTL::PlayerPtr player2(new GT::GTL::Player(player2Name, strategies2));

    GT::GTL::ObjectsPtr players(new GT::GTL::Objects());
    players->push_back( boost::dynamic_pointer_cast<GT::GTL::Object>(player1) );
    players->push_back( boost::dynamic_pointer_cast<GT::GTL::Object>(player2) );

    GT::GTL::ParamsPtr payoff(new GT::GTL::Params());
    payoff->push_back( GT::GTL::ParamFactory::getInstance().createParam(GT::createNumberPtr(10)) );
    payoff->push_back( GT::GTL::ParamFactory::getInstance().createParam(GT::createNumberPtr(20)) );

    GT::GTL::CoordinatePtr coordinate1(new GT::GTL::Coordinate(player1Name, strategy1) );
    GT::GTL::CoordinatePtr coordinate2(new GT::GTL::Coordinate(player2Name, strategy2));
    coordinate2->addParams(payoff);
    coordinate1->addSubCoordinate(coordinate2);

    GT::GTL::CoordinatesPtr coordinates(new GT::GTL::Coordinates());
    coordinates->push_back(coordinate1);

    GT::GTL::ContextPtr context = GT::GTL::NullFactory::getInstance().createContext();

    // when
    GT::GTL::LazyGameProxy lazyGame(gameBuilder, players, coordinates, context.get());
    GT::Model::PlayersPtr  gotPlayers;

    // then
    BOOST_REQUIRE_NO_THROW( gotPlayers = lazyGame.getPlayers() );
    BOOST_REQUIRE( gotPlayers );
    BOOST_CHECK_EQUAL(
        gotPlayers->size(),
        2
    );
}

BOOST_AUTO_TEST_CASE( LazyGameBuilder_getData ) {
    // given
    GT::Model::GameBuilderPtr gameBuilder = GT::Model::GameFactory::getInstance().buildExtensiveGame();

    GT::IdentifierPtr  player1Name = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr  strategy1 = GT::createIdentifierPtr("p1s1");
    GT::IdentifiersPtr strategies1(new GT::Identifiers());
    strategies1->push_back( strategy1 );
    GT::GTL::PlayerPtr player1(new GT::GTL::Player(player1Name, strategies1));

    GT::IdentifierPtr  player2Name = GT::createIdentifierPtr("p2");
    GT::IdentifierPtr  strategy2 = GT::createIdentifierPtr("p2s1");
    GT::IdentifiersPtr strategies2(new GT::Identifiers());
    strategies2->push_back( strategy2 );
    GT::GTL::PlayerPtr player2(new GT::GTL::Player(player2Name, strategies2));

    GT::GTL::ObjectsPtr players(new GT::GTL::Objects());
    players->push_back( boost::dynamic_pointer_cast<GT::GTL::Object>(player1) );
    players->push_back( boost::dynamic_pointer_cast<GT::GTL::Object>(player2) );

    GT::GTL::ParamsPtr payoff(new GT::GTL::Params());
    payoff->push_back( GT::GTL::ParamFactory::getInstance().createParam(GT::createNumberPtr(10)) );
    payoff->push_back( GT::GTL::ParamFactory::getInstance().createParam(GT::createNumberPtr(20)) );

    GT::GTL::CoordinatePtr coordinate1(new GT::GTL::Coordinate(player1Name, strategy1) );
    GT::GTL::CoordinatePtr coordinate2(new GT::GTL::Coordinate(player2Name, strategy2));
    coordinate2->addParams(payoff);
    coordinate1->addSubCoordinate(coordinate2);

    GT::GTL::CoordinatesPtr coordinates(new GT::GTL::Coordinates());
    coordinates->push_back(coordinate1);

    GT::GTL::ContextPtr context = GT::GTL::NullFactory::getInstance().createContext();

    // when
    GT::GTL::LazyGameProxy     lazyGame(gameBuilder, players, coordinates, context.get());
    GT::Model::DataAccessorPtr gotData;

    // then
    BOOST_REQUIRE_NO_THROW( gotData = lazyGame.getData() );
    BOOST_REQUIRE( gotData );
}

BOOST_AUTO_TEST_CASE( LazyGameBuilder_toString ) {
    // given
    GT::Model::GameBuilderPtr gameBuilder = GT::Model::GameFactory::getInstance().buildExtensiveGame();

    GT::IdentifierPtr  player1Name = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr  strategy1 = GT::createIdentifierPtr("p1s1");
    GT::IdentifiersPtr strategies1(new GT::Identifiers());
    strategies1->push_back( strategy1 );
    GT::GTL::PlayerPtr player1(new GT::GTL::Player(player1Name, strategies1));

    GT::IdentifierPtr  player2Name = GT::createIdentifierPtr("p2");
    GT::IdentifierPtr  strategy2 = GT::createIdentifierPtr("p2s1");
    GT::IdentifiersPtr strategies2(new GT::Identifiers());
    strategies2->push_back( strategy2 );
    GT::GTL::PlayerPtr player2(new GT::GTL::Player(player2Name, strategies2));

    GT::GTL::ObjectsPtr players(new GT::GTL::Objects());
    players->push_back( boost::dynamic_pointer_cast<GT::GTL::Object>(player1) );
    players->push_back( boost::dynamic_pointer_cast<GT::GTL::Object>(player2) );

    GT::GTL::ParamsPtr payoff(new GT::GTL::Params());
    payoff->push_back( GT::GTL::ParamFactory::getInstance().createParam(GT::createNumberPtr(10)) );
    payoff->push_back( GT::GTL::ParamFactory::getInstance().createParam(GT::createNumberPtr(20)) );

    GT::GTL::CoordinatePtr coordinate1(new GT::GTL::Coordinate(player1Name, strategy1) );
    GT::GTL::CoordinatePtr coordinate2(new GT::GTL::Coordinate(player2Name, strategy2));
    coordinate2->addParams(payoff);
    coordinate1->addSubCoordinate(coordinate2);

    GT::GTL::CoordinatesPtr coordinates(new GT::GTL::Coordinates());
    coordinates->push_back(coordinate1);

    GT::GTL::ContextPtr context = GT::GTL::NullFactory::getInstance().createContext();

    // when
    GT::GTL::LazyGameProxy lazyGame(gameBuilder, players, coordinates, context.get());
    GT::Message            gotString;

    // then
    BOOST_REQUIRE_NO_THROW( gotString = lazyGame.toString() );
    BOOST_CHECK_EQUAL(
        gotString,
        GT::Message() +
        "Extensive Game:\n"
        "\tPlayer:\n"
        "\t\tName:\n"
        "\t\t\tp1\n"
        "\t\t1:\n"
        "\t\t\tp1s1\n"
        "\tInformation Set:\n"
        "\t\t1\n"
        "\tp1s1:\n"
        "\t\tPlayer:\n"
        "\t\t\tName:\n"
        "\t\t\t\tp2\n"
        "\t\t\t1:\n"
        "\t\t\t\tp2s1\n"
        "\t\tInformation Set:\n"
        "\t\t\t1\n"
        "\t\tp2s1:\n"
        "\t\t\tValue:\n"
        "\t\t\t\t10\n"
        "\t\t\tValue:\n"
        "\t\t\t\t20\n"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
