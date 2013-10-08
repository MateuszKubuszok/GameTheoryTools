#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( Coordinate )

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( Coordinate_addParam_addParams_getParams ) {
    // given
    GT::GTL::ParamPtr  param1 = GT::GTL::NullFactory::getInstance().createParam();
    GT::GTL::ParamPtr  param2 = GT::GTL::NullFactory::getInstance().createParam();
    GT::GTL::ParamPtr  param3 = GT::GTL::NullFactory::getInstance().createParam();
    GT::GTL::ParamsPtr params = GT::GTL::NullFactory::getInstance().createParams();
    params->push_back(param2);
    params->push_back(param3);

    // when
    GT::GTL::Coordinate coordinate;
    coordinate.addParam(param1)
              .addParams(params);

    // then
    BOOST_REQUIRE_EQUAL(
        coordinate.getParams()->size(),
        3
    );
    BOOST_CHECK_EQUAL( (*coordinate.getParams())[0], param1 );
    BOOST_CHECK_EQUAL( (*coordinate.getParams())[1], param2 );
    BOOST_CHECK_EQUAL( (*coordinate.getParams())[2], param3 );
}

BOOST_AUTO_TEST_CASE( Coordinate_addPosition_getPositions ) {
    // given
    GT::IdentifierPtr player   = GT::Model::NullFactory::getInstance().createIdentifier();
    GT::IdentifierPtr strategy = GT::Model::NullFactory::getInstance().createIdentifier();

    // when
    GT::GTL::Coordinate coordinate;
    coordinate.addPosition(player, strategy);

    // then
    BOOST_REQUIRE_EQUAL(
        coordinate.getPositions()->size(),
        1
    );
    BOOST_CHECK_EQUAL( coordinate.getPositions()->begin()->first, *player );
    BOOST_CHECK_EQUAL( coordinate.getPositions()->begin()->second, *strategy );
}

BOOST_AUTO_TEST_CASE( Coordinate_addSubCoordinate_addSubCoordinates_getSubCoordinates ) {
    // given
    GT::GTL::CoordinatePtr  subCoordinate1 = GT::GTL::NullFactory::getInstance().createCoordinate();
    GT::GTL::CoordinatePtr  subCoordinate2 = GT::GTL::NullFactory::getInstance().createCoordinate();
    GT::GTL::CoordinatePtr  subCoordinate3 = GT::GTL::NullFactory::getInstance().createCoordinate();
    GT::GTL::CoordinatesPtr subCoordinates = GT::GTL::NullFactory::getInstance().createCoordinates();
    subCoordinates->push_back(subCoordinate2);
    subCoordinates->push_back(subCoordinate3);

    // when
    GT::GTL::Coordinate coordinate;
    coordinate.addSubCoordinate(subCoordinate1)
              .addSubCoordinates(subCoordinates);

    // then
    BOOST_REQUIRE_EQUAL(
        coordinate.getSubCoordinates()->size(),
        3
    );
    BOOST_CHECK_EQUAL( (*coordinate.getSubCoordinates())[0], subCoordinate1 );
    BOOST_CHECK_EQUAL( (*coordinate.getSubCoordinates())[1], subCoordinate2 );
    BOOST_CHECK_EQUAL( (*coordinate.getSubCoordinates())[2], subCoordinate3 );
}

BOOST_AUTO_TEST_CASE( Coordinate_toString ) {
    // given
    GT::GTL::ParamPtr  param1 = GT::GTL::NullFactory::getInstance().createParam();
    GT::GTL::ParamPtr  param2 = GT::GTL::NullFactory::getInstance().createParam();
    GT::GTL::ParamPtr  param3 = GT::GTL::NullFactory::getInstance().createParam();
    GT::GTL::ParamsPtr params = GT::GTL::NullFactory::getInstance().createParams();
    params->push_back(param2);
    params->push_back(param3);

    GT::IdentifierPtr player   = GT::Model::NullFactory::getInstance().createIdentifier();
    GT::IdentifierPtr strategy = GT::Model::NullFactory::getInstance().createIdentifier();

    GT::GTL::CoordinatePtr  subCoordinate1 = GT::GTL::NullFactory::getInstance().createCoordinate();
    GT::GTL::CoordinatePtr  subCoordinate2 = GT::GTL::NullFactory::getInstance().createCoordinate();
    GT::GTL::CoordinatePtr  subCoordinate3 = GT::GTL::NullFactory::getInstance().createCoordinate();
    GT::GTL::CoordinatesPtr subCoordinates = GT::GTL::NullFactory::getInstance().createCoordinates();
    subCoordinates->push_back(subCoordinate2);
    subCoordinates->push_back(subCoordinate3);

    // when
    GT::GTL::Coordinate coordinate;
    coordinate.addParam(param1)
              .addParams(params)
              .addPosition(player, strategy)
              .addSubCoordinate(subCoordinate1)
              .addSubCoordinates(subCoordinates);

    // then
    BOOST_CHECK_EQUAL(
        coordinate.toString(),
        GT::Message() +
        "Params:\n"
        "\tParam:\n"
        "\t\tNullParam\n"
        "\tParam:\n"
        "\t\tNullParam\n"
        "\tParam:\n"
        "\t\tNullParam\n"
        "Positions:\n"
        "\tNullIdentifier:\n"
        "\t\tNullIdentifier\n"
        "SubCoordinates:\n"
        "\tCoordinate:\n"
        "\t\tNullCoordinate\n"
        "\tCoordinate:\n"
        "\t\tNullCoordinate\n"
        "\tCoordinate:\n"
        "\t\tNullCoordinate\n"
    );
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
