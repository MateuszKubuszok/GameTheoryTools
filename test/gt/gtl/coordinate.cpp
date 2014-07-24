#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( Coordinate )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using boost::make_shared;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
    BOOST_CHECK_EQUAL( coordinate.getPositions()->begin()->first,  *player );
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

BOOST_AUTO_TEST_CASE( Coordinate_fillDataBuilder ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::IdentifierPtr  player1Name = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr  strategy1   = GT::createIdentifierPtr("p1s1");
    GT::IdentifiersPtr strategies1 = GT::createIdentifiersPtr();
    strategies1->push_back( strategy1 );
    GT::GTL::PlayerPtr player1 = make_shared<GT::GTL::Player>(player1Name, strategies1);

    GT::IdentifierPtr  player2Name = GT::createIdentifierPtr("p2");
    GT::IdentifierPtr  strategy2   = GT::createIdentifierPtr("p2s1");
    GT::IdentifiersPtr strategies2 = GT::createIdentifiersPtr();
    strategies2->push_back( strategy2 );
    GT::GTL::PlayerPtr player2 = make_shared<GT::GTL::Player>(player2Name, strategies2);

    GT::Model::PlayersPtr players = make_shared<GT::Model::Players>();
    players->insert(
        GT::Model::Players::value_type(*player1Name, boost::dynamic_pointer_cast<GT::Model::Player>(player1))
    );
    players->insert(
        GT::Model::Players::value_type(*player2Name, boost::dynamic_pointer_cast<GT::Model::Player>(player2))
    );

    GT::GTL::ParamsPtr payoff = make_shared<GT::GTL::Params>();
    payoff->push_back( GT::GTL::ParamFactory::getInstance().createParam(GT::createNumberPtr(10)) );
    payoff->push_back( GT::GTL::ParamFactory::getInstance().createParam(GT::createNumberPtr(20)) );

    GT::GTL::Context context;

    GT::Model::DataBuilderPtr dataBuilder = make_shared<GT::Model::StrategicDataBuilder>();
    dataBuilder->setPlayers(players);

    GT::PositionsPtr positions = make_shared<GT::Positions>();
    positions->insert( GT::Positions::value_type(*player1Name, *strategy1) );
    positions->insert( GT::Positions::value_type(*player2Name, *strategy2) );

    // when
    GT::GTL::CoordinatePtr coordinate1 = make_shared<GT::GTL::Coordinate>(player1Name, strategy1);
    GT::GTL::CoordinatePtr coordinate2 = make_shared<GT::GTL::Coordinate>(player2Name, strategy2);
    coordinate2->addParams(payoff);
    coordinate1->addSubCoordinate(coordinate2);
    coordinate1->fillDataBuilder(context, dataBuilder);

    GT::Model::DataPtr data =
        boost::dynamic_pointer_cast<GT::Model::StrategicDataBuilder>(dataBuilder)->build();

    // then
    BOOST_CHECK_EQUAL(
        data->getPayoffs(positions)->getPayoff(*player1Name),
        (*payoff)[0]->getNumber(context)
    );
    BOOST_CHECK_EQUAL(
        data->getPayoffs(positions)->getPayoff(*player2Name),
        (*payoff)[1]->getNumber(context)
    );
}

BOOST_AUTO_TEST_CASE( Coordinate_serialize ) {
    // given
    GT::GTL::ParamPtr  param1 = make_shared<GT::GTL::NumberParam>(GT::createNumberPtr(10));
    GT::GTL::ParamPtr  param2 = make_shared<GT::GTL::NumberParam>(GT::createNumberPtr(20));
    GT::GTL::ParamPtr  param3 = make_shared<GT::GTL::NumberParam>(GT::createNumberPtr(30));
    GT::GTL::ParamsPtr params = GT::GTL::NullFactory::getInstance().createParams();
    params->push_back(param2);
    params->push_back(param3);

    GT::IdentifierPtr player   = GT::Model::NullFactory::getInstance().createIdentifier();
    GT::IdentifierPtr strategy = GT::Model::NullFactory::getInstance().createIdentifier();

    // when
    GT::GTL::CoordinatePtr coordinatePtr = make_shared<GT::GTL::Coordinate>();
    GT::GTL::Coordinate&   coordinate    = *coordinatePtr;
    coordinate.addParam(param1)
              .addParams(params)
              .addPosition(player, strategy);
    GT::GTL::Coordinate coordinate2;
    coordinate2.addPosition(player, strategy)
               .addSubCoordinate(coordinatePtr);

    // then
    BOOST_CHECK_EQUAL(
        coordinate2.serialize(),
        GT::Message() +
        "{ NullIdentifier = NullIdentifier :\n"
        "  { NullIdentifier = NullIdentifier :\n"
        "    10.00000,\n"
        "    20.00000,\n"
        "    30.00000\n"
        "  }\n"
        "}"
    );
}

BOOST_AUTO_TEST_CASE( Coordinate_toString ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

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

BOOST_AUTO_TEST_CASE( Coordinate_operatorOverload ) {
    // given
    GT::IdentifierPtr player1   = GT::createIdentifierPtr("player1");
    GT::IdentifierPtr strategy1 = GT::createIdentifierPtr("strategy1");
    GT::IdentifierPtr player2   = GT::createIdentifierPtr("player2");
    GT::IdentifierPtr strategy2 = GT::createIdentifierPtr("strategy2");

    // when
    GT::GTL::Coordinate coordinate1;
    coordinate1.addPosition(player1, strategy1);
    GT::GTL::Coordinate coordinate2;
    coordinate1.addPosition(player2, strategy2);
    GT::GTL::Coordinate coordinate = coordinate1 + coordinate2;

    // then
    BOOST_REQUIRE_EQUAL(
        coordinate.getPositions()->size(),
        2
    );
    BOOST_CHECK_EQUAL(
        (*coordinate.getPositions())[*player1],
        *strategy1
    );
    BOOST_CHECK_EQUAL(
        (*coordinate.getPositions())[*player2],
        *strategy2
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
