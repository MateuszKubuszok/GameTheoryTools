#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>

#include "gt/model/inner_common.hpp"

BOOST_AUTO_TEST_SUITE( TreeGame )

BOOST_AUTO_TEST_CASE( TreeGame_getPlayers ) {
    // given
    GT::Model::PlayersPtr  players = GT::Model::NullFactory::getInstance().createPlayers();
    GT::Model::TreeDataPtr data    = GT::Model::InnerNullFactory::getInstance().createTreeData();

    // when
    GT::Model::TreeGame game(players, data);

    // then
    BOOST_CHECK_EQUAL(
        players,
        game.getPlayers()
    );
}

BOOST_AUTO_TEST_CASE( TreeGame_getData ) {
    // given
    GT::Model::PlayersPtr  players = GT::Model::NullFactory::getInstance().createPlayers();
    GT::Model::TreeDataPtr data    = GT::Model::InnerNullFactory::getInstance().createTreeData();

    // when
    GT::Model::TreeGame game(players, data);
    GT::Model::DataAccessorPtr dataAccessor = game.getData();

    // then
    BOOST_CHECK_EQUAL(
        dataAccessor->toString(),
        GT::Message() +
        "Tree Data Accessor:\n"
        "\tNullTreeData\n"
    );
}

BOOST_AUTO_TEST_CASE( TreeGame_toString ) {
    // given
    GT::Model::PlayersPtr  players = GT::Model::NullFactory::getInstance().createPlayers();
    GT::Model::TreeDataPtr data    = GT::Model::InnerNullFactory::getInstance().createTreeData();

    // when
    GT::Model::TreeGame game(players, data);

    // then
    BOOST_CHECK_EQUAL(
        game.toString(),
        GT::Message() +
        "Tree Game:\n"
        "\tNullTreeData\n" 
    );
}

BOOST_AUTO_TEST_SUITE_END()
