#include "gt/model/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ExtensiveGame )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( ExtensiveGame_getPlayers ) {
    // given
    GT::Model::PlayersPtr  players = GT::Model::NullFactory::getInstance().createPlayers();
    GT::Model::ExtensiveDataPtr data    = GT::Model::InnerNullFactory::getInstance().createExtensiveData();

    // when
    GT::Model::ExtensiveGame game(players, data);

    // then
    BOOST_CHECK_EQUAL(
        players,
        game.getPlayers()
    );
}

BOOST_AUTO_TEST_CASE( ExtensiveGame_getData ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::Model::PlayersPtr  players = GT::Model::NullFactory::getInstance().createPlayers();
    GT::Model::ExtensiveDataPtr data    = GT::Model::InnerNullFactory::getInstance().createExtensiveData();

    // when
    GT::Model::ExtensiveGame game(players, data);
    GT::Model::DataAccessorPtr dataAccessor = game.getData();

    // then
    BOOST_CHECK_EQUAL(
        dataAccessor->toString(),
        GT::Message() +
        "Extensive Data Accessor:\n"
        "\tNullExtensiveData\n"
    );
}

BOOST_AUTO_TEST_CASE( ExtensiveGame_toString ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::Model::PlayersPtr  players = GT::Model::NullFactory::getInstance().createPlayers();
    GT::Model::ExtensiveDataPtr data    = GT::Model::InnerNullFactory::getInstance().createExtensiveData();

    // when
    GT::Model::ExtensiveGame game(players, data);

    // then
    BOOST_CHECK_EQUAL(
        game.toString(),
        GT::Message() +
        "Extensive Game:\n"
        "\tNullExtensiveData\n"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
