#include "gt/routines/test_common.hpp"

BOOST_AUTO_TEST_SUITE( SelectableStrategiesRoutine )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( SelectableStrategiesRoutine_getAvailablePlayers ) {
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

    // when
    TestSelectableStrategiesRoutineImpl routine(players);

    // then
    BOOST_REQUIRE( routine.getAvailablePlayers() );
    BOOST_CHECK_EQUAL(
        players,
        routine.getAvailablePlayers()
    );
}

BOOST_AUTO_TEST_CASE( SelectableStrategiesRoutine_getAvailableStrategiesForPlayer ) {
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

    // when
    TestSelectableStrategiesRoutineImpl routine(players);
    GT::IdentifiersPtr strategies1 = routine.getAvailableStrategiesForPlayer(*p1);
    GT::IdentifiersPtr strategies2 = routine.getAvailableStrategiesForPlayer(*p2);

    // then
    BOOST_REQUIRE( strategies1 );
    BOOST_CHECK_EQUAL_COLLECTIONS(
        strategies->begin(),  strategies->end(),
        strategies1->begin(), strategies1->end()
    );
    BOOST_REQUIRE( strategies2 );
    BOOST_CHECK_EQUAL_COLLECTIONS(
        strategies->begin(),  strategies->end(),
        strategies2->begin(), strategies2->end()
    );
}

BOOST_AUTO_TEST_CASE( SelectableStrategiesRoutine_setAvailableStrategiesForPlayer ) {
        // given
    GT::IdentifierPtr p1 = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr p2 = GT::createIdentifierPtr("p2");
    GT::IdentifierPtr s1 = GT::createIdentifierPtr("s1");
    GT::IdentifierPtr s2 = GT::createIdentifierPtr("s2");
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();
    strategies->push_back(s1);
    strategies->push_back(s2);
    GT::IdentifiersPtr chosenStrategies1 = GT::createIdentifiersPtr();
    chosenStrategies1->push_back(s1);
    GT::IdentifiersPtr chosenStrategies2 = GT::createIdentifiersPtr();
    chosenStrategies2->push_back(s2);

    GT::Identifier l1 = GT::createIdentifier("1");
    GT::Identifier l2 = GT::createIdentifier("2");

    GT::Model::PlayerPtr  player1(new GT::Model::Player(p1, strategies));
    GT::Model::PlayerPtr  player2(new GT::Model::Player(p2, strategies));
    GT::Model::PlayersPtr players(new GT::Model::Players());
    players->insert( GT::Model::Players::value_type(*p1, player1) );
    players->insert( GT::Model::Players::value_type(*p2, player2) );

    // when
    TestSelectableStrategiesRoutineImpl routine(players);
    routine.setAvailableStrategiesForPlayer(*p1, chosenStrategies1);
    routine.setAvailableStrategiesForPlayer(*p2, chosenStrategies2);
    GT::IdentifiersPtr strategies1 = routine.getAvailableStrategiesForPlayer(*p1);
    GT::IdentifiersPtr strategies2 = routine.getAvailableStrategiesForPlayer(*p2);

    // then
    BOOST_REQUIRE( strategies1 );
    BOOST_CHECK_EQUAL_COLLECTIONS(
        chosenStrategies1->begin(), chosenStrategies1->end(),
        strategies1->begin(),       strategies1->end()
    );
    BOOST_REQUIRE( strategies2 );
    BOOST_CHECK_EQUAL_COLLECTIONS(
        chosenStrategies2->begin(), chosenStrategies2->end(),
        strategies2->begin(),       strategies2->end()
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
