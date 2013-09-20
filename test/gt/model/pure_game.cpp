#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>

#include "gt/model/inner_common.hpp"

BOOST_AUTO_TEST_SUITE( PureGame )

BOOST_AUTO_TEST_CASE( PureGame_getPlayers ) {
    // given
    GT::Model::PlayersPtr players = GT::Model::NullFactory::getInstance().createPlayers();
    GT::Model::DataPtr    data    = GT::Model::NullFactory::getInstance().createData();

    // when
    GT::Model::PureGame game(players, data);

    // then
    BOOST_CHECK_EQUAL(
        players,
        game.getPlayers()
    );
}

BOOST_AUTO_TEST_CASE( PureGame_toString ) {
    // given
    GT::Model::PlayersPtr players = GT::Model::NullFactory::getInstance().createPlayers();
    GT::Model::DataPtr    data    = GT::Model::NullFactory::getInstance().createData();

    // when
    GT::Model::PureGame game(players, data);

    // then
    BOOST_CHECK_EQUAL(
        game.toString(),
        GT::Message() +
        "\t\n" +
        "Pure Game:\n" +
        "\tNullData\n" 
    );
}

BOOST_AUTO_TEST_SUITE_END()
