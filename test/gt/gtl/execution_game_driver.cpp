#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ExecutionGameDriver )

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( ExecutionGameDriver_createDetails ) {
    // given
    TestDriverImpl            driver;
    GT::GTL::ContextPtr       context = GT::GTL::NullFactory::getInstance().createContext();
    GT::GTL::InputLocationPtr inputLocation = GT::GTL::NullFactory::getInstance().createInputLocation();
    GT::GTL::ObjectsPtr       players(new GT::GTL::Objects());
    players->push_back( boost::dynamic_pointer_cast<GT::GTL::Object>(GT::GTL::NullFactory::getInstance().createPlayer()) );
    players->push_back( boost::dynamic_pointer_cast<GT::GTL::Object>(GT::GTL::NullFactory::getInstance().createPlayer()) );
    GT::GTL::CoordinatesPtr   coordinates(new GT::GTL::Coordinates());
    coordinates->push_back( GT::GTL::NullFactory::getInstance().createCoordinate() );

    boost::scoped_ptr<GT::GTL::ObjectsPtr>     playersPtr(new GT::GTL::ObjectsPtr(players));
    boost::scoped_ptr<GT::GTL::CoordinatesPtr> coordinatesPtr(new GT::GTL::CoordinatesPtr(coordinates));

    // when
    GT::GTL::ExecutionGameDriver gameDriver(&driver, context);
    boost::scoped_ptr<GT::GTL::DetailsPtr> detailsPtr(gameDriver.createDetails(*inputLocation, playersPtr.get(), coordinatesPtr.get()));

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
    boost::scoped_ptr<GT::GTL::PlayerPtr> playerPtr(gameDriver.createPlayer(*inputLocation, playerNamePtr.get(), strategiesPtr.get()));

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

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
