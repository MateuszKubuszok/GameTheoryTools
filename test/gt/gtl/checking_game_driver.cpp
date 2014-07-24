#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( CheckingGameDriver )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using boost::make_shared;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( CheckingGameDriver_createStrategic ) {
    // given
    GT::GTL::InputLocationPtr inputLocation = GT::GTL::NullFactory::getInstance().createInputLocation();

    GT::GTL::DetailsPtr invalidDetails = GT::GTL::ErrorFactory::getInstance().createDetails("Error Details");
    GT::GTL::DetailsPtr validDetails   = GT::GTL::NullFactory::getInstance().createDetails();

    boost::scoped_ptr<GT::GTL::DetailsPtr> invalidDetailsPtr(new GT::GTL::DetailsPtr(invalidDetails));
    boost::scoped_ptr<GT::GTL::DetailsPtr> validDetailsPtr(new GT::GTL::DetailsPtr(validDetails));

    // when
    GT::GTL::CheckingGameDriver gameDriver;
    boost::scoped_ptr<GT::GTL::GamePtr> game1Ptr(
        gameDriver.createStrategic(*inputLocation, invalidDetailsPtr.get()));
    boost::scoped_ptr<GT::GTL::GamePtr> game2Ptr(
        gameDriver.createStrategic(*inputLocation, validDetailsPtr.get()));

    // then
    BOOST_REQUIRE(  game1Ptr );
    BOOST_CHECK( !(*game1Ptr)->isValid() );
    BOOST_REQUIRE(  game2Ptr );
    BOOST_CHECK(  (*game2Ptr)->isValid() );
}

BOOST_AUTO_TEST_CASE( CheckingGameDriver_createExtensive ) {
    // given
    GT::GTL::InputLocationPtr inputLocation = GT::GTL::NullFactory::getInstance().createInputLocation();

    GT::GTL::DetailsPtr invalidDetails = GT::GTL::ErrorFactory::getInstance().createDetails("Error Details");
    GT::GTL::DetailsPtr validDetails   = GT::GTL::NullFactory::getInstance().createDetails();

    boost::scoped_ptr<GT::GTL::DetailsPtr> invalidDetailsPtr(new GT::GTL::DetailsPtr(invalidDetails));
    boost::scoped_ptr<GT::GTL::DetailsPtr> validDetailsPtr(new GT::GTL::DetailsPtr(validDetails));

    // when
    GT::GTL::CheckingGameDriver gameDriver;
    boost::scoped_ptr<GT::GTL::GamePtr> game1Ptr(
        gameDriver.createExtensive(*inputLocation, invalidDetailsPtr.get()));
    boost::scoped_ptr<GT::GTL::GamePtr> game2Ptr(
        gameDriver.createExtensive(*inputLocation, validDetailsPtr.get()));

    // then
    BOOST_REQUIRE(  game1Ptr );
    BOOST_CHECK( !(*game1Ptr)->isValid() );
    BOOST_REQUIRE(  game2Ptr );
    BOOST_CHECK(  (*game2Ptr)->isValid() );
}

BOOST_AUTO_TEST_CASE( CheckingGameDriver_createDetails ) {
    // given
    GT::GTL::InputLocationPtr inputLocation = GT::GTL::NullFactory::getInstance().createInputLocation();

    GT::GTL::ObjectsPtr invalidPlayers = make_shared<GT::GTL::Objects>();
    invalidPlayers->push_back(boost::dynamic_pointer_cast<GT::GTL::Object>(
        GT::GTL::ErrorFactory::getInstance().createPlayer("Invalid Player")));

    GT::GTL::ObjectsPtr validPlayers = make_shared<GT::GTL::Objects>();
    validPlayers->push_back(
        boost::dynamic_pointer_cast<GT::GTL::Object>(GT::GTL::NullFactory::getInstance().createPlayer()));

    GT::GTL::CoordinatesPtr invalidCoordinates = make_shared<GT::GTL::Coordinates>();
    invalidCoordinates->push_back(
        GT::GTL::ErrorFactory::getInstance().createCoordinate("Invalid Coordinate"));

    GT::GTL::CoordinatesPtr validCoordinates = make_shared<GT::GTL::Coordinates>();
    validCoordinates->push_back(GT::GTL::NullFactory::getInstance().createCoordinate());

    boost::scoped_ptr<GT::GTL::ObjectsPtr>
        invalidPlayersPtr(new GT::GTL::ObjectsPtr(invalidPlayers));
    boost::scoped_ptr<GT::GTL::ObjectsPtr>
        validPlayersPtr(new GT::GTL::ObjectsPtr(validPlayers));
    boost::scoped_ptr<GT::GTL::CoordinatesPtr>
        invalidCoordinatesPtr(new GT::GTL::CoordinatesPtr(invalidCoordinates));
    boost::scoped_ptr<GT::GTL::CoordinatesPtr>
        validCoordinatesPtr(new GT::GTL::CoordinatesPtr(validCoordinates));

    // when
    GT::GTL::CheckingGameDriver gameDriver;
    boost::scoped_ptr<GT::GTL::DetailsPtr> details1Ptr(
        gameDriver.createDetails(*inputLocation, invalidPlayersPtr.get(), invalidCoordinatesPtr.get()));
    boost::scoped_ptr<GT::GTL::DetailsPtr> details2Ptr(
        gameDriver.createDetails(*inputLocation, invalidPlayersPtr.get(), validCoordinatesPtr.get()));
    boost::scoped_ptr<GT::GTL::DetailsPtr> details3Ptr(
        gameDriver.createDetails(*inputLocation, validPlayersPtr.get(),   invalidCoordinatesPtr.get()));
    boost::scoped_ptr<GT::GTL::DetailsPtr> details4Ptr(
        gameDriver.createDetails(*inputLocation, validPlayersPtr.get(),   validCoordinatesPtr.get()));

    // then
    BOOST_REQUIRE(  details1Ptr );
    BOOST_CHECK( !(*details1Ptr)->isValid() );
    BOOST_REQUIRE(  details2Ptr );
    BOOST_CHECK( !(*details2Ptr)->isValid() );
    BOOST_REQUIRE(  details3Ptr );
    BOOST_CHECK( !(*details3Ptr)->isValid() );
    BOOST_REQUIRE(  details4Ptr );
    BOOST_CHECK(  (*details4Ptr)->isValid() );
}

BOOST_AUTO_TEST_CASE( CheckingGameDriver_createPlayer ) {
    // given
    GT::GTL::InputLocationPtr inputLocation = GT::GTL::NullFactory::getInstance().createInputLocation();

    GT::IdentifierPtr playerName   = GT::Model::NullFactory::getInstance().createIdentifier();

    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();
    strategies->push_back(GT::Model::NullFactory::getInstance().createIdentifier());

    boost::scoped_ptr<GT::IdentifierPtr>  playerNamePtr(new GT::IdentifierPtr(playerName));
    boost::scoped_ptr<GT::IdentifiersPtr> strategiesPtr(new GT::IdentifiersPtr(strategies));

    // when
    GT::GTL::CheckingGameDriver gameDriver;
    boost::scoped_ptr<GT::GTL::PlayerPtr> playerPtr(
        gameDriver.createPlayer(*inputLocation, playerNamePtr.get(), strategiesPtr.get()));

    // then
    BOOST_REQUIRE( playerPtr );
    BOOST_CHECK( (*playerPtr)->isValid() );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
