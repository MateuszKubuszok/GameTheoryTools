#include "gt/routines/test_common.hpp"

BOOST_AUTO_TEST_SUITE( Strategic2PlayerMixedEquilibriumRoutine )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( Strategic2Player0SumMixedEquilibriumRoutine_findResultsFor ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::IdentifierPtr  p1   = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr  p1s1 = GT::createIdentifierPtr("p1s1");
    GT::IdentifierPtr  p1s2 = GT::createIdentifierPtr("p1s2");
    GT::IdentifierPtr  p1s3 = GT::createIdentifierPtr("p1s3");
    GT::IdentifiersPtr p1s  = GT::createIdentifiersPtr();
    p1s->push_back( p1s1 );
    p1s->push_back( p1s2 );
    p1s->push_back( p1s3 );

    GT::PositionsPtr p1s1Choice = GT::createPositionsPtr();
    p1s1Choice->insert( GT::Positions::value_type( *p1, *p1s1 ) );
    GT::PositionsPtr p1s2Choice = GT::createPositionsPtr();
    p1s2Choice->insert( GT::Positions::value_type( *p1, *p1s2 ) );
    GT::PositionsPtr p1s3Choice = GT::createPositionsPtr();
    p1s3Choice->insert( GT::Positions::value_type( *p1, *p1s3 ) );

    GT::IdentifierPtr  p2   = GT::createIdentifierPtr("p2");
    GT::IdentifierPtr  p2s1 = GT::createIdentifierPtr("p2s1");
    GT::IdentifierPtr  p2s2 = GT::createIdentifierPtr("p2s2");
    GT::IdentifierPtr  p2s3 = GT::createIdentifierPtr("p2s3");
    GT::IdentifierPtr  p2s4 = GT::createIdentifierPtr("p2s4");
    GT::IdentifiersPtr p2s  = GT::createIdentifiersPtr();
    p2s->push_back( p2s1 );
    p2s->push_back( p2s2 );
    p2s->push_back( p2s3 );
    p2s->push_back( p2s4 );

    GT::PositionsPtr p2s1Choice = GT::createPositionsPtr();
    p2s1Choice->insert( GT::Positions::value_type( *p2, *p2s1 ) );
    GT::PositionsPtr p2s2Choice = GT::createPositionsPtr();
    p2s2Choice->insert( GT::Positions::value_type( *p2, *p2s2 ) );
    GT::PositionsPtr p2s3Choice = GT::createPositionsPtr();
    p2s3Choice->insert( GT::Positions::value_type( *p2, *p2s3 ) );
    GT::PositionsPtr p2s4Choice = GT::createPositionsPtr();
    p2s4Choice->insert( GT::Positions::value_type( *p2, *p2s4 ) );

    GT::Model::PlayersPtr players(new GT::Model::Players());
    GT::Model::PlayerPtr  player1(new GT::Model::Player(p1, p1s));
    GT::Model::PlayerPtr  player2(new GT::Model::Player(p2, p2s));
    players->insert( GT::Model::Players::value_type( *p1, player1 ) );
    players->insert( GT::Model::Players::value_type( *p2, player2 ) );

    GT::Model::GameBuilderPtr gameBuilder = GT::Model::GameFactory::getInstance().buildStrategicGame();
    gameBuilder->setPlayers(players);

    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 0 ) );
        payoff->push_back( GT::createNumberPtr( 6 ) );
        gameBuilder->clone()->addNextPositions(p1s1Choice).addNextPositions(p2s1Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 3 ) );
        payoff->push_back( GT::createNumberPtr( 6 ) );
        gameBuilder->clone()->addNextPositions(p1s1Choice).addNextPositions(p2s2Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 1 ) );
        payoff->push_back( GT::createNumberPtr( 2 ) );
        gameBuilder->clone()->addNextPositions(p1s1Choice).addNextPositions(p2s3Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 8 ) );
        payoff->push_back( GT::createNumberPtr( 2 ) );
        gameBuilder->clone()->addNextPositions(p1s1Choice).addNextPositions(p2s4Choice).setPayoffs(payoff);
    }

    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 5 ) );
        payoff->push_back( GT::createNumberPtr( 3 ) );
        gameBuilder->clone()->addNextPositions(p1s2Choice).addNextPositions(p2s1Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 5 ) );
        payoff->push_back( GT::createNumberPtr( 2 ) );
        gameBuilder->clone()->addNextPositions(p1s2Choice).addNextPositions(p2s2Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 4 ) );
        payoff->push_back( GT::createNumberPtr( 5 ) );
        gameBuilder->clone()->addNextPositions(p1s2Choice).addNextPositions(p2s3Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 6 ) );
        payoff->push_back( GT::createNumberPtr( 6 ) );
        gameBuilder->clone()->addNextPositions(p1s2Choice).addNextPositions(p2s4Choice).setPayoffs(payoff);
    }

    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 2 ) );
        payoff->push_back( GT::createNumberPtr( 0 ) );
        gameBuilder->clone()->addNextPositions(p1s3Choice).addNextPositions(p2s1Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 6 ) );
        payoff->push_back( GT::createNumberPtr( 7 ) );
        gameBuilder->clone()->addNextPositions(p1s3Choice).addNextPositions(p2s2Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 0 ) );
        payoff->push_back( GT::createNumberPtr( 0 ) );
        gameBuilder->clone()->addNextPositions(p1s3Choice).addNextPositions(p2s3Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 5 ) );
        payoff->push_back( GT::createNumberPtr( 1 ) );
        gameBuilder->clone()->addNextPositions(p1s3Choice).addNextPositions(p2s4Choice).setPayoffs(payoff);
    }


    GT::Model::GamePtr          game       = gameBuilder->build();
    GT::Routines::ConditionsPtr conditions = GT::Routines::NullFactory::getInstance().createConditions();

    // when
    GT::Routines::Strategic2PlayerMixedEquilibriumRoutine routine;
    GT::Model::ResultPtr result;

    // then
    BOOST_REQUIRE_NO_THROW( result = routine.findResultFor(game, conditions) );
    BOOST_CHECK_EQUAL(
        result->getResult(),
        GT::Message() +
        "Mixed Strategies:\n"
        "\tp1:\n"
        "\t\tp1s1:\n"
        "\t\t\t0.40741\n"
        "\t\tp1s2:\n"
        "\t\t\t0.51852\n"
        "\t\tp1s3:\n"
        "\t\t\t0.07407\n"
        "\tp2:\n"
        "\t\tp2s1:\n"
        "\t\t\t0.00000\n"
        "\t\tp2s2:\n"
        "\t\t\t0.50000\n"
        "\t\tp2s3:\n"
        "\t\t\t0.00000\n"
        "\t\tp2s4:\n"
        "\t\t\t0.50000\n"
        "Payoff:\n"
        "\t\t\tp1,\tp2\n"
        "\tPayoff:\n"
        "\t\t\t5.50000,\t4.00000\n"
    );
}

BOOST_AUTO_TEST_CASE( Strategic2Player0SumMixedEquilibriumRoutine_toString ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    // when
    GT::Routines::Strategic2PlayerMixedEquilibriumRoutine routine;

    // then
    BOOST_CHECK_EQUAL(
        routine.toString(),
        GT::Message() +
        "Strategic2PlayerMixedEquilibriumRoutine"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
