#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ExecutionCoordinateDriver )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( ExecutionCoordinateDriver_create ) {
    // given
    GT::GTL::InputLocationPtr inputLocation = GT::GTL::NullFactory::getInstance().createInputLocation();
    GT::IdentifierPtr         player        = GT::createIdentifierPtr("Player");
    GT::IdentifierPtr         strategy      = GT::createIdentifierPtr("Strategy");

    boost::scoped_ptr<GT::IdentifierPtr> playerPtr(new GT::IdentifierPtr(player));
    boost::scoped_ptr<GT::IdentifierPtr> strategyPtr(new GT::IdentifierPtr(strategy));

    // when
    GT::GTL::ExecutionCoordinateDriver coordinateDriver;
    boost::scoped_ptr<GT::GTL::CoordinatePtr> coordinatePtr(
        coordinateDriver.create(*inputLocation, playerPtr.get(), strategyPtr.get()));

    // then
    BOOST_REQUIRE(coordinatePtr);
    BOOST_REQUIRE((*coordinatePtr)->getPositions()->count(*player));
    BOOST_CHECK_EQUAL(
        (*(*coordinatePtr)->getPositions())[*player],
        *strategy
    );
}

BOOST_AUTO_TEST_CASE( ExecutionCoordinateDriver_fillWithData ) {
    // given
    GT::GTL::InputLocationPtr inputLocation = GT::GTL::NullFactory::getInstance().createInputLocation();

    GT::GTL::ParamsPtr        params(new GT::GTL::Params());
    params->push_back( GT::GTL::ParamFactory::getInstance().createParam(GT::createNumberPtr(10)) );
    params->push_back( GT::GTL::ParamFactory::getInstance().createParam(GT::createNumberPtr(20)) );

    GT::IdentifierPtr         player0       = GT::createIdentifierPtr("Player0");
    GT::IdentifierPtr         strategy0     = GT::createIdentifierPtr("Strategy0");
    GT::GTL::CoordinatePtr    coordinate(new GT::GTL::Coordinate(player0, strategy0));

    GT::IdentifierPtr         player1       = GT::createIdentifierPtr("Player1");
    GT::IdentifierPtr         strategy1     = GT::createIdentifierPtr("Strategy1");
    GT::GTL::CoordinatePtr    coordinate1(new GT::GTL::Coordinate(player1, strategy1));
    coordinate1->addParams(params);

    GT::IdentifierPtr         player2       = GT::createIdentifierPtr("Player2");
    GT::IdentifierPtr         strategy2     = GT::createIdentifierPtr("Strategy2");
    GT::GTL::CoordinatePtr    coordinate2(new GT::GTL::Coordinate(player2, strategy2));
    coordinate2->addParams(params);

    GT::GTL::CoordinatesPtr coordinates(new GT::GTL::Coordinates());
    coordinates->push_back( coordinate1 );
    coordinates->push_back( coordinate2 );

    boost::scoped_ptr<GT::GTL::CoordinatePtr>  coordinatePtr(new GT::GTL::CoordinatePtr(coordinate));
    boost::scoped_ptr<GT::GTL::CoordinatesPtr> coordinatesPtr(new GT::GTL::CoordinatesPtr(coordinates));
    boost::scoped_ptr<GT::GTL::ParamsPtr>      paramsPtr(new GT::GTL::ParamsPtr(params));

    // when
    GT::GTL::ExecutionCoordinateDriver coordinateDriver;
    boost::scoped_ptr<GT::GTL::CoordinatePtr> coordinate3Ptr(
        coordinateDriver.fillWithData(*inputLocation, coordinatePtr.get(), paramsPtr.get()));
    boost::scoped_ptr<GT::GTL::CoordinatePtr> coordinate4Ptr(
        coordinateDriver.fillWithData(*inputLocation, coordinatePtr.get(), coordinatesPtr.get()));

    // then
    BOOST_REQUIRE(coordinate3Ptr);
    BOOST_CHECK_EQUAL_COLLECTIONS(
        (*coordinate3Ptr)->getParams()->begin(), (*coordinate3Ptr)->getParams()->end(),
        params->begin(),                         params->end()
    );
    BOOST_REQUIRE(coordinate4Ptr);
    BOOST_CHECK_EQUAL_COLLECTIONS(
        (*coordinate4Ptr)->getSubCoordinates()->begin(), (*coordinate4Ptr)->getSubCoordinates()->end(),
        coordinates->begin(),                            coordinates->end()
    );
}

BOOST_AUTO_TEST_CASE( ExecutionCoordinateDriver_merge ) {
    // given
    GT::GTL::InputLocationPtr inputLocation = GT::GTL::NullFactory::getInstance().createInputLocation();

    GT::IdentifierPtr         player1       = GT::createIdentifierPtr("Player1");
    GT::IdentifierPtr         strategy1     = GT::createIdentifierPtr("Strategy1");
    GT::GTL::CoordinatePtr    coordinate1(new GT::GTL::Coordinate(player1, strategy1));

    GT::IdentifierPtr         player2       = GT::createIdentifierPtr("Player2");
    GT::IdentifierPtr         strategy2     = GT::createIdentifierPtr("Strategy2");
    GT::GTL::CoordinatePtr    coordinate2(new GT::GTL::Coordinate(player2, strategy2));

    boost::scoped_ptr<GT::GTL::CoordinatePtr>  coordinate1Ptr(new GT::GTL::CoordinatePtr(coordinate1));
    boost::scoped_ptr<GT::GTL::CoordinatePtr>  coordinate2Ptr(new GT::GTL::CoordinatePtr(coordinate2));

    // when
    GT::GTL::ExecutionCoordinateDriver coordinateDriver;
    boost::scoped_ptr<GT::GTL::CoordinatePtr> coordinate3Ptr(
        coordinateDriver.merge(*inputLocation, coordinate1Ptr.get(), coordinate2Ptr.get()));

    // then
    BOOST_REQUIRE(coordinate3Ptr);
    BOOST_CHECK_EQUAL(
        (*coordinate3Ptr)->getPositions()->size(),
        2
    );
    BOOST_REQUIRE((*coordinate3Ptr)->getPositions()->count(*player1));
    BOOST_CHECK_EQUAL(
        (*(*coordinate3Ptr)->getPositions())[*player1],
        *strategy1
    );
    BOOST_REQUIRE((*coordinate3Ptr)->getPositions()->count(*player2));
    BOOST_CHECK_EQUAL(
        (*(*coordinate3Ptr)->getPositions())[*player2],
        *strategy2
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
