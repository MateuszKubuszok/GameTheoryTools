#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ExecutionGameDriver )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( ExecutionGameDriver_createStrategic ) {
    // given
    TestDriverImpl            driver;
    GT::GTL::ContextPtr       context = GT::GTL::NullFactory::getInstance().createContext();
    GT::GTL::InputLocationPtr inputLocation = GT::GTL::NullFactory::getInstance().createInputLocation();

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

    GT::GTL::DetailsPtr details(new GT::GTL::Details(players, coordinates));

    boost::scoped_ptr<GT::GTL::DetailsPtr> detailsPtr(new GT::GTL::DetailsPtr(details));

    // when
    GT::GTL::ExecutionGameDriver gameDriver(&driver, context);
    boost::scoped_ptr<GT::GTL::GamePtr> gamePtr(gameDriver.createStrategic(*inputLocation, detailsPtr.get()));

    // then
    BOOST_REQUIRE(gamePtr);
    BOOST_CHECK_EQUAL(
        (*gamePtr)->toString(),
        GT::Message() +
        "Strategic Game:\n"
        "\tValue:\n"
        "\t\t\t\tp1,\tp2,\n"
        "\t\tPosition:\n"
        "\t\t\t\tp1s1,\t,\n"
        "\t\tPayoff:\n"
        "\t\t\t\t10,\t20,\n"
    );
}

BOOST_AUTO_TEST_CASE( ExecutionGameDriver_createExtensive ) {
    // given
    TestDriverImpl            driver;
    GT::GTL::ContextPtr       context = GT::GTL::NullFactory::getInstance().createContext();
    GT::GTL::InputLocationPtr inputLocation = GT::GTL::NullFactory::getInstance().createInputLocation();

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

    GT::GTL::DetailsPtr details(new GT::GTL::Details(players, coordinates));

    boost::scoped_ptr<GT::GTL::DetailsPtr> detailsPtr(new GT::GTL::DetailsPtr(details));

    // when
    GT::GTL::ExecutionGameDriver gameDriver(&driver, context);
    boost::scoped_ptr<GT::GTL::GamePtr> gamePtr(gameDriver.createExtensive(*inputLocation, detailsPtr.get()));

    // then
    BOOST_REQUIRE(gamePtr);
    BOOST_CHECK_EQUAL(
        (*gamePtr)->toString(),
        GT::Message() +
        "Extensive Game:\n"
        "\tExtensiveData:\n"
        "\t\tPlayer:\n"
        "\t\t\t0:\n"
        "\t\t\t\tp1s1\n"
        "\t\tp1s1:\n"
        "\t\t\tPlayer:\n"
        "\t\t\t\t0:\n"
        "\t\t\t\t\tp2s1\n"
        "\t\t\tp2s1:\n"
        "\t\t\t\tValue:\n"
        "\t\t\t\t\t10\n"
        "\t\t\t\tValue:\n"
        "\t\t\t\t\t20\n"
    );
}

BOOST_AUTO_TEST_CASE( ExecutionGameDriver_createDetails ) {
    // given
    TestDriverImpl            driver;
    GT::GTL::ContextPtr       context = GT::GTL::NullFactory::getInstance().createContext();
    GT::GTL::InputLocationPtr inputLocation = GT::GTL::NullFactory::getInstance().createInputLocation();
    GT::GTL::ObjectsPtr       players(new GT::GTL::Objects());
    players->push_back(
        boost::dynamic_pointer_cast<GT::GTL::Object>(GT::GTL::NullFactory::getInstance().createPlayer()) );
    players->push_back(
        boost::dynamic_pointer_cast<GT::GTL::Object>(GT::GTL::NullFactory::getInstance().createPlayer()) );
    GT::GTL::CoordinatesPtr   coordinates(new GT::GTL::Coordinates());
    coordinates->push_back( GT::GTL::NullFactory::getInstance().createCoordinate() );

    boost::scoped_ptr<GT::GTL::ObjectsPtr>     playersPtr(new GT::GTL::ObjectsPtr(players));
    boost::scoped_ptr<GT::GTL::CoordinatesPtr> coordinatesPtr(new GT::GTL::CoordinatesPtr(coordinates));

    // when
    GT::GTL::ExecutionGameDriver gameDriver(&driver, context);
    boost::scoped_ptr<GT::GTL::DetailsPtr> detailsPtr(
        gameDriver.createDetails(*inputLocation, playersPtr.get(), coordinatesPtr.get()));

    // then
    BOOST_REQUIRE(detailsPtr);
    BOOST_CHECK_EQUAL(
        (*detailsPtr)->getPlayers(),
        players
    );
    BOOST_CHECK_EQUAL(
        (*detailsPtr)->getCoordinates(),
        coordinates
    );
}

BOOST_AUTO_TEST_CASE( ExecutionGameDriver_createPlayer ) {
    // given
    TestDriverImpl            driver;
    GT::GTL::ContextPtr       context = GT::GTL::NullFactory::getInstance().createContext();
    GT::GTL::InputLocationPtr inputLocation = GT::GTL::NullFactory::getInstance().createInputLocation();
    GT::IdentifierPtr         playerName    = GT::Model::NullFactory::getInstance().createIdentifier();
    GT::IdentifiersPtr        strategies(new GT::Identifiers());
    strategies->push_back(GT::Model::NullFactory::getInstance().createIdentifier());

    boost::scoped_ptr<GT::IdentifierPtr>  playerNamePtr(new GT::IdentifierPtr(playerName));
    boost::scoped_ptr<GT::IdentifiersPtr> strategiesPtr(new GT::IdentifiersPtr(strategies));

    // when
    GT::GTL::ExecutionGameDriver gameDriver(&driver, context);
    boost::scoped_ptr<GT::GTL::PlayerPtr> playerPtr(
        gameDriver.createPlayer(*inputLocation, playerNamePtr.get(), strategiesPtr.get()));

    // then
    BOOST_REQUIRE(playerPtr);
    BOOST_CHECK_EQUAL(
        (*playerPtr)->getName(),
        playerName
    );
    BOOST_CHECK_EQUAL(
        (*playerPtr)->getStrategies(),
        strategies
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
