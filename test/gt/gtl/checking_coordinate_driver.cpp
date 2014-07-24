#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( CheckingCoordinateDriver )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using boost::make_shared;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( CheckingCoordinateDriver_create ) {
    // given
    GT::GTL::InputLocationPtr inputLocation = GT::GTL::NullFactory::getInstance().createInputLocation();
    GT::IdentifierPtr         player        = GT::Model::NullFactory::getInstance().createIdentifier();
    GT::IdentifierPtr         strategy      = GT::Model::NullFactory::getInstance().createIdentifier();

    boost::scoped_ptr<GT::IdentifierPtr> playerPtr(new GT::IdentifierPtr(player));
    boost::scoped_ptr<GT::IdentifierPtr> strategyPtr(new GT::IdentifierPtr(strategy));

    // when
    GT::GTL::CheckingCoordinateDriver coordinateDriver;
    boost::scoped_ptr<GT::GTL::CoordinatePtr> coordinatePtr(
        coordinateDriver.create(*inputLocation, playerPtr.get(), strategyPtr.get()));

    // then
    BOOST_REQUIRE( coordinatePtr );
    BOOST_CHECK( (*coordinatePtr) );
}

BOOST_AUTO_TEST_CASE( CheckingCoordinateDriver_fillWithData ) {
    // given
    GT::GTL::InputLocationPtr inputLocation = GT::GTL::NullFactory::getInstance().createInputLocation();

    GT::GTL::CoordinatePtr    invalidCoordinate =
        GT::GTL::ErrorFactory::getInstance().createCoordinate("Invalid Coordinate");
    GT::GTL::CoordinatePtr    validCoordinate   =
        GT::GTL::NullFactory::getInstance().createCoordinate();

    GT::GTL::CoordinatesPtr invalidCoordinates = make_shared<GT::GTL::Coordinates>();
    invalidCoordinates->push_back(
        GT::GTL::ErrorFactory::getInstance().createCoordinate("Invalid Coordinate"));

    GT::GTL::CoordinatesPtr validCoordinates = make_shared<GT::GTL::Coordinates>();
    validCoordinates->push_back(GT::GTL::NullFactory::getInstance().createCoordinate());

    GT::GTL::ParamsPtr invalidParams = make_shared<GT::GTL::Params>();
    invalidParams->push_back(GT::GTL::ErrorFactory::getInstance().createParam("Invalid Param"));

    GT::GTL::ParamsPtr validParams = make_shared<GT::GTL::Params>();
    validParams->push_back(GT::GTL::NullFactory::getInstance().createParam());

    boost::scoped_ptr<GT::GTL::CoordinatePtr>
        invalidCoordinatePtr(new GT::GTL::CoordinatePtr(invalidCoordinate));
    boost::scoped_ptr<GT::GTL::CoordinatePtr>
        validCoordinatePtr(new GT::GTL::CoordinatePtr(validCoordinate));
    boost::scoped_ptr<GT::GTL::CoordinatesPtr>
        invalidCoordinatesPtr(new GT::GTL::CoordinatesPtr(invalidCoordinates));
    boost::scoped_ptr<GT::GTL::CoordinatesPtr>
        validCoordinatesPtr(new GT::GTL::CoordinatesPtr(validCoordinates));
    boost::scoped_ptr<GT::GTL::ParamsPtr>
        invalidParamsPtr(new GT::GTL::ParamsPtr(invalidParams));
    boost::scoped_ptr<GT::GTL::ParamsPtr>
        validParamsPtr(new GT::GTL::ParamsPtr(validParams));

    // when
    GT::GTL::CheckingCoordinateDriver coordinateDriver;
    boost::scoped_ptr<GT::GTL::CoordinatePtr> coordinate1Ptr(
    coordinateDriver.fillWithData(*inputLocation, invalidCoordinatePtr.get(), invalidCoordinatesPtr.get()));
    boost::scoped_ptr<GT::GTL::CoordinatePtr> coordinate2Ptr(
    coordinateDriver.fillWithData(*inputLocation, invalidCoordinatePtr.get(), validCoordinatesPtr.get()));
    boost::scoped_ptr<GT::GTL::CoordinatePtr> coordinate3Ptr(
    coordinateDriver.fillWithData(*inputLocation, validCoordinatePtr.get(),   invalidCoordinatesPtr.get()));
    boost::scoped_ptr<GT::GTL::CoordinatePtr> coordinate4Ptr(
    coordinateDriver.fillWithData(*inputLocation, validCoordinatePtr.get(),   validCoordinatesPtr.get()));
    boost::scoped_ptr<GT::GTL::CoordinatePtr> coordinate5Ptr(
    coordinateDriver.fillWithData(*inputLocation, invalidCoordinatePtr.get(), invalidParamsPtr.get()));
    boost::scoped_ptr<GT::GTL::CoordinatePtr> coordinate6Ptr(
    coordinateDriver.fillWithData(*inputLocation, invalidCoordinatePtr.get(), validParamsPtr.get()));
    boost::scoped_ptr<GT::GTL::CoordinatePtr> coordinate7Ptr(
    coordinateDriver.fillWithData(*inputLocation, validCoordinatePtr.get(),   invalidParamsPtr.get()));
    boost::scoped_ptr<GT::GTL::CoordinatePtr> coordinate8Ptr(
    coordinateDriver.fillWithData(*inputLocation, validCoordinatePtr.get(),   validParamsPtr.get()));

    // then
    BOOST_REQUIRE(  coordinate1Ptr );
    BOOST_CHECK( !(*coordinate1Ptr)->isValid() );
    BOOST_REQUIRE(  coordinate2Ptr );
    BOOST_CHECK( !(*coordinate2Ptr)->isValid() );
    BOOST_REQUIRE(  coordinate3Ptr );
    BOOST_CHECK( !(*coordinate3Ptr)->isValid() );
    BOOST_REQUIRE(  coordinate4Ptr );
    BOOST_CHECK(  (*coordinate4Ptr)->isValid() );
    BOOST_REQUIRE(  coordinate5Ptr );
    BOOST_CHECK( !(*coordinate5Ptr)->isValid() );
    BOOST_REQUIRE(  coordinate6Ptr );
    BOOST_CHECK( !(*coordinate6Ptr)->isValid() );
    BOOST_REQUIRE(  coordinate7Ptr );
    BOOST_CHECK( !(*coordinate7Ptr)->isValid() );
    BOOST_REQUIRE(  coordinate8Ptr );
    BOOST_CHECK(  (*coordinate8Ptr)->isValid() );
}

BOOST_AUTO_TEST_CASE( CheckingCoordinateDriver_merge ) {
    // given
    GT::GTL::InputLocationPtr inputLocation = GT::GTL::NullFactory::getInstance().createInputLocation();

    GT::GTL::CoordinatePtr    invalidCoordinate =
        GT::GTL::ErrorFactory::getInstance().createCoordinate("Invalid Coordinate");
    GT::GTL::CoordinatePtr    validCoordinate   = GT::GTL::NullFactory::getInstance().createCoordinate();

    boost::scoped_ptr<GT::GTL::CoordinatePtr>  invalidCoordinatePtr(
        new GT::GTL::CoordinatePtr(invalidCoordinate));
    boost::scoped_ptr<GT::GTL::CoordinatePtr>  validCoordinatePtr(
        new GT::GTL::CoordinatePtr(validCoordinate));

    // when
    GT::GTL::CheckingCoordinateDriver coordinateDriver;
    boost::scoped_ptr<GT::GTL::CoordinatePtr> coordinate1Ptr(
        coordinateDriver.merge(*inputLocation, invalidCoordinatePtr.get(), invalidCoordinatePtr.get()));
    boost::scoped_ptr<GT::GTL::CoordinatePtr> coordinate2Ptr(
        coordinateDriver.merge(*inputLocation, invalidCoordinatePtr.get(), validCoordinatePtr.get()));
    boost::scoped_ptr<GT::GTL::CoordinatePtr> coordinate3Ptr(
        coordinateDriver.merge(*inputLocation, validCoordinatePtr.get(),   invalidCoordinatePtr.get()));
    boost::scoped_ptr<GT::GTL::CoordinatePtr> coordinate4Ptr(
        coordinateDriver.merge(*inputLocation, validCoordinatePtr.get(),   validCoordinatePtr.get()));

    // then
    BOOST_REQUIRE(  coordinate1Ptr );
    BOOST_CHECK( !(*coordinate1Ptr)->isValid() );
    BOOST_REQUIRE(  coordinate2Ptr );
    BOOST_CHECK( !(*coordinate2Ptr)->isValid() );
    BOOST_REQUIRE(  coordinate3Ptr );
    BOOST_CHECK( !(*coordinate3Ptr)->isValid() );
    BOOST_REQUIRE(  coordinate4Ptr );
    BOOST_CHECK(  (*coordinate4Ptr)->isValid() );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
