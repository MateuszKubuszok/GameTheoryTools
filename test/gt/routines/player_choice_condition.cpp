#include "gt/routines/test_common.hpp"

BOOST_AUTO_TEST_SUITE( PlayerChoiceCondition )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( PlayerChoiceCondition_configureRoutine ) {
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

    BOOST_CHECK( true ); // to do!
    // GT::Routines::RoutinePtr routine(new TestSelectableStrategiesRoutineImpl(players));
    // GT::Routines::SelectableStrategiesRoutinePtr specificRoutine =
    //     boost::dynamic_pointer_cast<GT::Routines::SelectableStrategiesRoutine>(routine);

    // GT::IdentifiersPtr chosenStrategies = GT::createIdentifiersPtr();
    // chosenStrategies->push_back(s1);

    // // when
    // GT::Routines::PlayerChoiceCondition condition1(p1, s1);
    // GT::Routines::PlayerChoiceCondition condition2(s1, p1);

    // // then
    // BOOST_REQUIRE_NO_THROW( condition1.configureRoutine(routine) );
    // BOOST_CHECK_EQUAL_COLLECTIONS(
    //     specificRoutine->getAvailableStrategiesForPlayer(*p1)->begin(),
    //     specificRoutine->getAvailableStrategiesForPlayer(*p1)->end(),
    //     chosenStrategies->begin(),
    //     chosenStrategies->end()
    // );
    // BOOST_REQUIRE_THROW(
    //     condition2.configureRoutine(routine),
    //     GT::Routines::InvalidCondition
    // );
}

BOOST_AUTO_TEST_CASE( PlayerChoiceCondition_toString ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::IdentifierPtr player   = GT::Model::NullFactory::getInstance().createIdentifier();
    GT::IdentifierPtr strategy = GT::Model::NullFactory::getInstance().createIdentifier();

    // when
    GT::Routines::PlayerChoiceCondition condition(player, strategy);

    // then
    BOOST_CHECK_EQUAL(
        condition.toString(),
        GT::Message() +
        "NullIdentifier:\n"
        "\tNullIdentifier\n"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
