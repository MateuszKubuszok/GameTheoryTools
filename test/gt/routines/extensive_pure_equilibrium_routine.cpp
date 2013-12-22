#include "gt/routines/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ExtensivePureEquilibriumRoutine )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( ExtensivePureEquilibriumRoutine_findResultsFor ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::IdentifierPtr  p1   = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr  p1s1 = GT::createIdentifierPtr("p1s1");
    GT::IdentifierPtr  p1s2 = GT::createIdentifierPtr("p1s2");
    GT::IdentifiersPtr p1s  = GT::createIdentifiersPtr();
    p1s->push_back( p1s1 );
    p1s->push_back( p1s2 );

    GT::PositionsPtr p1s1Choice = GT::createPositionsPtr();
    p1s1Choice->insert( GT::Positions::value_type( *p1, *p1s1 ) );
    GT::PositionsPtr p1s2Choice = GT::createPositionsPtr();
    p1s2Choice->insert( GT::Positions::value_type( *p1, *p1s2 ) );

    GT::IdentifierPtr  p2   = GT::createIdentifierPtr("p2");
    GT::IdentifierPtr  p2s1 = GT::createIdentifierPtr("p2s1");
    GT::IdentifierPtr  p2s2 = GT::createIdentifierPtr("p2s2");
    GT::IdentifiersPtr p2s  = GT::createIdentifiersPtr();
    p2s->push_back( p2s1 );
    p2s->push_back( p2s2 );

    GT::PositionsPtr p2s1Choice = GT::createPositionsPtr();
    p2s1Choice->insert( GT::Positions::value_type( *p2, *p2s1 ) );
    GT::PositionsPtr p2s2Choice = GT::createPositionsPtr();
    p2s2Choice->insert( GT::Positions::value_type( *p2, *p2s2 ) );

    GT::Model::PlayersPtr players(new GT::Model::Players());
    GT::Model::PlayerPtr  player1(new GT::Model::Player(p1, p1s));
    GT::Model::PlayerPtr  player2(new GT::Model::Player(p2, p2s));
    players->insert( GT::Model::Players::value_type( *p1, player1 ) );
    players->insert( GT::Model::Players::value_type( *p2, player2 ) );

    GT::Model::GameBuilderPtr gameBuilder = GT::Model::GameFactory::getInstance().buildExtensiveGame();
    gameBuilder->setPlayers(players);
    {
        GT::Model::DataBuilderPtr s1_node = gameBuilder->clone();
        s1_node->addNextPositions(p1s1Choice);
        {
            GT::Model::DataBuilderPtr s1_s1_node = s1_node->clone();
            s1_s1_node->addNextPositions(p2s1Choice);
            {
                GT::Model::DataBuilderPtr s1_s1_s1_node = s1_s1_node->clone();
                s1_s1_s1_node->addNextPositions(p1s1Choice);
                {
                    GT::NumbersPtr payoff = GT::createNumbersPtr();
                    payoff->push_back( GT::createNumberPtr( 0 ) ); // p1
                    payoff->push_back( GT::createNumberPtr( 0 ) ); // p2
                    s1_s1_s1_node->setPayoffs(payoff);
                }
            }
            {
                GT::Model::DataBuilderPtr s1_s1_s2_node = s1_s1_node->clone();
                s1_s1_s2_node->addNextPositions(p1s2Choice);
                {
                    GT::NumbersPtr payoff = GT::createNumbersPtr();
                    payoff->push_back( GT::createNumberPtr( 20 ) ); // p1
                    payoff->push_back( GT::createNumberPtr( 20 ) ); // p2
                    s1_s1_s2_node->setPayoffs(payoff);
                }
            }
        }
        {
            GT::Model::DataBuilderPtr s1_s2_node = s1_node->clone();
            s1_s2_node->addNextPositions(p2s2Choice);
            {
                GT::NumbersPtr payoff = GT::createNumbersPtr();
                payoff->push_back( GT::createNumberPtr(  10 ) ); // p1
                payoff->push_back( GT::createNumberPtr( -10 ) ); // p2
                s1_s2_node->setPayoffs(payoff);
            }
        }
    }
    {
        GT::Model::DataBuilderPtr s2_node = gameBuilder->clone();
        s2_node->addNextPositions(p1s2Choice);
        {
            GT::NumbersPtr payoff = GT::createNumbersPtr();
            payoff->push_back( GT::createNumberPtr( -10 ) ); // p1
            payoff->push_back( GT::createNumberPtr(  10 ) ); // p2
            s2_node->setPayoffs(payoff);
        }
    }

    GT::Model::GamePtr          game       = gameBuilder->build();
    GT::Routines::ConditionsPtr conditions = GT::Routines::NullFactory::getInstance().createConditions();

    // when
    GT::Routines::ExtensivePureEquilibriumRoutine routine(players);
    GT::Model::ResultPtr result;

    // then
    BOOST_REQUIRE_NO_THROW( result = routine.findResultFor(game, conditions) );
    BOOST_CHECK_EQUAL(
        result->getResult(),
        GT::Message() +
        "Pure Strategies:\n"
        "\tp1:\n"
        "\t\t1:\n"
        "\t\t\tp1s1\n"
        "\t\t2:\n"
        "\t\t\tp1s2\n"
        "\tp2:\n"
        "\t\t1:\n"
        "\t\t\tp2s1\n"
        "Payoff:\n"
        "\t\t\tp1,\tp2\n"
        "\tPayoff:\n"
        "\t\t\t20,\t20\n"
    );
}

BOOST_AUTO_TEST_CASE( ExtensivePureEquilibriumRoutine_toString ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::Model::PlayersPtr players = GT::Model::NullFactory::getInstance().createPlayers();

    // when
    GT::Routines::ExtensivePureEquilibriumRoutine routine(players);

    // then
    BOOST_CHECK_EQUAL(
        routine.toString(),
        GT::Message() +
        "ExtensivePureEquilibriumRoutine"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
