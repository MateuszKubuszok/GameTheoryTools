#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( Details )

BOOST_AUTO_TEST_CASE( Details_getCoordinates ) {
    // given
    GT::GTL::PlayerPtr player1 = GT::GTL::NullFactory::getInstance().createPlayer();
    GT::GTL::PlayerPtr player2 = GT::GTL::NullFactory::getInstance().createPlayer();
    GT::GTL::ObjectsPtr players(new GT::GTL::Objects());
    players->push_back( boost::dynamic_pointer_cast<GT::GTL::Object>(player1) );
    players->push_back( boost::dynamic_pointer_cast<GT::GTL::Object>(player2) );

    GT::GTL::CoordinatePtr coordinate1 = GT::GTL::NullFactory::getInstance().createCoordinate();
    GT::GTL::CoordinatePtr coordinate2 = GT::GTL::NullFactory::getInstance().createCoordinate();
    GT::GTL::CoordinatesPtr coordinates(new GT::GTL::Coordinates()); 
    coordinates->push_back( coordinate1 );
    coordinates->push_back( coordinate2 );

    // when
    GT::GTL::Details details(players, coordinates);

    // then
    BOOST_REQUIRE_EQUAL(
        details.getCoordinates()->size(),
        2
    );
    BOOST_CHECK_EQUAL( (*details.getCoordinates())[0], coordinate1 );
    BOOST_CHECK_EQUAL( (*details.getCoordinates())[1], coordinate2 );
}

BOOST_AUTO_TEST_CASE( Details_getPlayers ) {
    // given
    GT::GTL::PlayerPtr player1 = GT::GTL::NullFactory::getInstance().createPlayer();
    GT::GTL::PlayerPtr player2 = GT::GTL::NullFactory::getInstance().createPlayer();
    GT::GTL::ObjectsPtr players(new GT::GTL::Objects());
    players->push_back( boost::dynamic_pointer_cast<GT::GTL::Object>(player1) );
    players->push_back( boost::dynamic_pointer_cast<GT::GTL::Object>(player2) );

    GT::GTL::CoordinatePtr coordinate1 = GT::GTL::NullFactory::getInstance().createCoordinate();
    GT::GTL::CoordinatePtr coordinate2 = GT::GTL::NullFactory::getInstance().createCoordinate();
    GT::GTL::CoordinatesPtr coordinates(new GT::GTL::Coordinates()); 
    coordinates->push_back( coordinate1 );
    coordinates->push_back( coordinate2 );

    // when
    GT::GTL::Details details(players, coordinates);

    // then
    BOOST_REQUIRE_EQUAL(
        details.getPlayers()->size(),
        2
    );
    BOOST_CHECK_EQUAL( (*details.getPlayers())[0], boost::dynamic_pointer_cast<GT::GTL::Object>(player1) );
    BOOST_CHECK_EQUAL( (*details.getPlayers())[1], boost::dynamic_pointer_cast<GT::GTL::Object>(player2) );
}

BOOST_AUTO_TEST_CASE( Details_toString ) {
    GT::GTL::PlayerPtr player1 = GT::GTL::NullFactory::getInstance().createPlayer();
    GT::GTL::PlayerPtr player2 = GT::GTL::NullFactory::getInstance().createPlayer();
    GT::GTL::ObjectsPtr players(new GT::GTL::Objects());
    players->push_back( boost::dynamic_pointer_cast<GT::GTL::Object>(player1) );
    players->push_back( boost::dynamic_pointer_cast<GT::GTL::Object>(player2) );

    GT::GTL::CoordinatePtr coordinate1 = GT::GTL::NullFactory::getInstance().createCoordinate();
    GT::GTL::CoordinatePtr coordinate2 = GT::GTL::NullFactory::getInstance().createCoordinate();
    GT::GTL::CoordinatesPtr coordinates(new GT::GTL::Coordinates()); 
    coordinates->push_back( coordinate1 );
    coordinates->push_back( coordinate2 );

    // when
    GT::GTL::Details details(players, coordinates);

    // then
    BOOST_CHECK_EQUAL(
        details.toString(),
        GT::Message() +
        "Players:\n"
        "\tPlayer:\n"
        "\t\tNullPlayer\n"
        "\tPlayer:\n"
        "\t\tNullPlayer\n"
        "Coordinates:\n"
        "\tCoordinate:\n"
        "\t\tNullCoordinate\n"
        "\tCoordinate:\n"
        "\t\tNullCoordinate\n"
    );
}

BOOST_AUTO_TEST_SUITE_END()
