#include "gt/routines/test_common.hpp"

BOOST_AUTO_TEST_SUITE( PlayerRangeCondition )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( PlayerRangeCondition_configureRoutine ) {
    // given
    GT::IdentifierPtr p1 = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr p2 = GT::createIdentifierPtr("p2");
    GT::IdentifierPtr s1 = GT::createIdentifierPtr("s1");
    GT::IdentifierPtr s2 = GT::createIdentifierPtr("s2");
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();
    strategies->push_back(s1);
    strategies->push_back(s2);

    GT::Identifier l1 = GT::createIdentifier("1");
    GT::Identifier l2 = GT::createIdentifier("2");

    GT::Model::PlayerPtr  player1(new GT::Model::Player(p1, strategies));
    GT::Model::PlayerPtr  player2(new GT::Model::Player(p2, strategies));
    GT::Model::PlayersPtr players(new GT::Model::Players());
    players->insert( GT::Model::Players::value_type(*p1, player1) );
    players->insert( GT::Model::Players::value_type(*p2, player2) );

    GT::Routines::RoutineConfigPtr routineConfig(
        new GT::Routines::StrategicPureEquilibriumRoutineConfig(players)
    );
    boost::shared_ptr<GT::Routines::StrategicPureEquilibriumRoutineConfig> specificRoutineConfig =
        boost::dynamic_pointer_cast<GT::Routines::StrategicPureEquilibriumRoutineConfig>(routineConfig);

    GT::IdentifierPtr  player         = p1;
    GT::IdentifiersPtr usedStrategies = GT::createIdentifiersPtr();
    usedStrategies->push_back( s1 );
    // when
    GT::Routines::PlayerRangeCondition condition(player, usedStrategies);

    // then
    BOOST_REQUIRE_EQUAL( specificRoutineConfig->getAvailableStrategies(*player).size(), 2 );
    BOOST_REQUIRE_NO_THROW( condition.configureRoutine(routineConfig) );
    BOOST_CHECK_EQUAL(   specificRoutineConfig->getAvailableStrategies(*player).size(), 1 );
}

BOOST_AUTO_TEST_CASE( PlayerRangeCondition_toString ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::IdentifierPtr  player     = GT::Model::NullFactory::getInstance().createIdentifier();
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();
    strategies->push_back( GT::Model::NullFactory::getInstance().createIdentifier() );
    strategies->push_back( GT::Model::NullFactory::getInstance().createIdentifier() );

    // when
    GT::Routines::PlayerRangeCondition condition(player, strategies);

    // then
    BOOST_CHECK_EQUAL(
        condition.toString(),
        GT::Message() +
        "NullIdentifier:\n"
        "\t1:\n"
        "\t\tNullIdentifier\n"
        "\t2:\n"
        "\t\tNullIdentifier\n"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
