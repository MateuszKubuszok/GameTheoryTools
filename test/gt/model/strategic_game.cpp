#include "gt/model/test_common.hpp"

BOOST_AUTO_TEST_SUITE( StrategicGame )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( StrategicGame_getPlayers ) {
    // given
    GT::Model::PlayersPtr       players = GT::Model::NullFactory::getInstance().createPlayers();
    GT::Model::StrategicDataPtr data    = GT::Model::InnerNullFactory::getInstance().createStrategicData();

    // when
    GT::Model::StrategicGame game(players, data);

    // then
    BOOST_CHECK_EQUAL(
        players,
        game.getPlayers()
    );
}

BOOST_AUTO_TEST_CASE( StrategicGame_getData ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::Model::PlayersPtr       players = GT::Model::NullFactory::getInstance().createPlayers();
    GT::Model::StrategicDataPtr data    = GT::Model::InnerNullFactory::getInstance().createStrategicData();

    // when
    GT::Model::StrategicGame game(players, data);
    GT::Model::DataAccessorPtr dataAccessor = game.getData();

    // then
    BOOST_CHECK_EQUAL(
        dataAccessor->toString(),
        GT::Message() +
        "Strategic Data Accessor:\n"
        "\tNullStrategicData\n"
    );
}

BOOST_AUTO_TEST_CASE( StrategicGame_toString ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::Model::PlayersPtr       players = GT::Model::NullFactory::getInstance().createPlayers();
    GT::Model::StrategicDataPtr data    = GT::Model::InnerNullFactory::getInstance().createStrategicData();

    // when
    GT::Model::StrategicGame game(players, data);

    // then
    BOOST_CHECK_EQUAL(
        game.toString(),
        GT::Message() +
        "Strategic Game:\n"
        "\tNullStrategicData\n"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
