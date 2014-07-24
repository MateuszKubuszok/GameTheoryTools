#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( Player )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( Player_respondsTo ) {
    // given
    GT::Identifier properties = GT::createIdentifier("properties");
    GT::Identifier type       = GT::createIdentifier("type");
    GT::Identifier name       = GT::createIdentifier("name");
    GT::Identifier strategies = GT::createIdentifier("strategies");
    GT::Identifier error      = GT::createIdentifier("error");

    GT::IdentifierPtr  playerName       = GT::Model::NullFactory::getInstance().createIdentifier();
    GT::IdentifiersPtr playerStrategies = GT::Model::NullFactory::getInstance().createIdentifiers();

    // when
    GT::GTL::Player player(playerName, playerStrategies);

    // then
    BOOST_CHECK(  player.respondsTo(properties) );
    BOOST_CHECK(  player.respondsTo(type) );
    BOOST_CHECK(  player.respondsTo(name) );
    BOOST_CHECK(  player.respondsTo(strategies) );
    BOOST_CHECK( !player.respondsTo(error) );
}

BOOST_AUTO_TEST_CASE( Player_serialize ) {
    // given
    GT::IdentifierPtr  playerName       = GT::createIdentifierPtr("P");
    GT::IdentifiersPtr playerStrategies = GT::createIdentifiersPtr();
    playerStrategies->push_back( GT::createIdentifierPtr("1") );
    playerStrategies->push_back( GT::createIdentifierPtr("2") );

    // when
    GT::GTL::Player player(playerName, playerStrategies);

    // then
    BOOST_CHECK_EQUAL(
        player.serialize(),
        GT::Message() +
        "PLAYER P { 1, 2 }"
    );
}

BOOST_AUTO_TEST_CASE( Player_Player ) {
    // given
    GT::Identifier properties = GT::createIdentifier("properties");
    GT::Identifier type       = GT::createIdentifier("type");
    GT::Identifier name       = GT::createIdentifier("name");
    GT::Identifier strategies = GT::createIdentifier("strategies");
    GT::Identifier error      = GT::createIdentifier("error");

    GT::IdentifierPtr  playerName       = GT::Model::NullFactory::getInstance().createIdentifier();
    GT::IdentifiersPtr playerStrategies = GT::Model::NullFactory::getInstance().createIdentifiers();

    // when
    GT::GTL::Player        player(playerName, playerStrategies);
    const GT::GTL::Player& playerRef = player;

    // then
    BOOST_CHECK_EQUAL(
        player,
        playerRef
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
