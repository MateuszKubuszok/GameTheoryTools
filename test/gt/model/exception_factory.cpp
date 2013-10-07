#include "gt/model/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ExceptionFactory )

BOOST_AUTO_TEST_CASE( ExceptionFactory_coordinatesAlreadySet ) {
    // given
    GT::Identifier playerName   = GT::createIdentifier("player");
    GT::Identifier strategyName = GT::createIdentifier("strategy");
    GT::Positions  positions    = GT::createPositions();
    positions.insert( GT::Positions::value_type(playerName, strategyName) );

    // when
    GT::Model::InvalidCoordinate exception = GT::Model::ExceptionFactory::getInstance().coordinatesAlreadySet(positions);

    // then
    BOOST_CHECK_EQUAL(
        exception.what(),
        GT::Message() +
        "Coordinates: 'player'='strategy' already has defined payoff"
    );
}

BOOST_AUTO_TEST_CASE( ExceptionFactory_incompleteCoordinates ) {
    // given
    // when
    GT::Model::IllegalInnerState exception = GT::Model::ExceptionFactory::getInstance().incompleteCoordinates();

    // then
    BOOST_CHECK_EQUAL(
        exception.what(),
        GT::Message() +
        "Cannot set parameters when not all coordinates are known"
    );
}

BOOST_AUTO_TEST_CASE( ExceptionFactory_invalidCoordinateFormat ) {
    // given
    GT::Identifier playerName   = GT::createIdentifier("player");
    GT::Identifier strategyName = GT::createIdentifier("strategy");
    GT::Positions  positions    = GT::createPositions();
    positions.insert( GT::Positions::value_type(playerName, strategyName) );

    // when
    GT::Model::InvalidCoordinate exception = GT::Model::ExceptionFactory::getInstance().invalidCoordinateFormat(positions);

    // then
    BOOST_CHECK_EQUAL(
        exception.what(),
        GT::Message() +
        "Coordinates: 'player'='strategy' has invalid format - make sure chosen Players' names and strategies are valid"
    );
}

BOOST_AUTO_TEST_CASE( ExceptionFactory_invalidTreeCoordinateFormat ) {
    // given
    GT::Identifier playerName   = GT::createIdentifier("player");
    GT::Identifier strategyName = GT::createIdentifier("strategy");
    GT::Positions  positions    = GT::createPositions();
    positions.insert( GT::Positions::value_type(playerName, strategyName) );

    // when
    GT::Model::InvalidCoordinate exception = GT::Model::ExceptionFactory::getInstance().invalidTreeCoordinateFormat(positions);

    // then
    BOOST_CHECK_EQUAL(
        exception.what(),
        GT::Message() +
        "Coordinates: 'player'='strategy' has invalid format - make sure chosen Players' names does not collide with other coordinates on the same level of tree"
    );
}

BOOST_AUTO_TEST_CASE( ExceptionFactory_noParamsForPositions ) {
    // given
    GT::Index positionInStorage = 5;
    GT::Index maxPosition       = 10;

    // when
    GT::Model::InvalidCoordinate exception = GT::Model::ExceptionFactory::getInstance().noParamsForPositions(positionInStorage, maxPosition);

    // then
    BOOST_CHECK_EQUAL(
        exception.what(),
        GT::Message() +
        "Calculated position (5) has no defined payoff - make sure all Coordinates in range [0,9] has defined payoff"
    );
}

BOOST_AUTO_TEST_CASE( ExceptionFactory_invalidPlayer ) {
    // given
    GT::Identifier player = GT::createIdentifier("player");
    
    // when
    GT::Model::InvalidCoordinate exception = GT::Model::ExceptionFactory::getInstance().invalidPlayer(player);

    // then
    BOOST_CHECK_EQUAL(
        exception.what(),
        GT::Message() +
        "No Player 'player' has been defined"
    );
}

BOOST_AUTO_TEST_CASE( ExceptionFactory_invalidStrategy ) {
    // given
    GT::Identifier strategy = GT::createIdentifier("strategy");
    
    // when
    GT::Model::InvalidCoordinate exception = GT::Model::ExceptionFactory::getInstance().invalidStrategy(strategy);

    // then
    BOOST_CHECK_EQUAL(
        exception.what(),
        GT::Message() +
        "No Strategy 'strategy' has been defined"
    );
}

BOOST_AUTO_TEST_CASE( ExceptionFactory_playersAlreadySet ) {
    // given
    // when
    GT::Model::IllegalInnerState exception = GT::Model::ExceptionFactory::getInstance().playersAlreadySet();

    // then
    BOOST_CHECK_EQUAL(
        exception.what(),
        GT::Message() +
        "Cannot change already set Players"
    );
}

BOOST_AUTO_TEST_CASE( ExceptionFactory_propertiesAndResultsDontMatchInSize ) {
    // given
    GT::Index propertiesSize = 5;
    GT::Index resultsSize    = 6;

    // when
    GT::Model::IllegalInnerState exception = GT::Model::ExceptionFactory::getInstance().propertiesAndResultsDontMatchInSize(propertiesSize, resultsSize);

    // then
    BOOST_CHECK_EQUAL(
        exception.what(),
        GT::Message() +
        "Properties size (5) and Results size (6) does not match"
    );
}

BOOST_AUTO_TEST_SUITE_END()
