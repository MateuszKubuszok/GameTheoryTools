#include "gt/routines/test_common.hpp"

BOOST_AUTO_TEST_SUITE( MatrixMixedEquilibriumRoutine )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using boost::make_shared;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( MatrixMixedEquilibriumRoutine_findResultsFor ) {
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

    GT::Model::PlayersPtr players = make_shared<GT::Model::Players>();
    GT::Model::PlayerPtr  player1 = make_shared<GT::Model::Player>(p1, p1s);
    GT::Model::PlayerPtr  player2 = make_shared<GT::Model::Player>(p2, p2s);
    players->insert( GT::Model::Players::value_type( *p1, player1 ) );
    players->insert( GT::Model::Players::value_type( *p2, player2 ) );

    GT::Model::GameBuilderPtr gameBuilder = GT::Model::GameFactory::getInstance().buildStrategicGame();
    gameBuilder->setPlayers(players);

    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( -5 ) ); // p1, p2=-p1
        gameBuilder->clone()->addNextPositions(p1s1Choice).addNextPositions(p2s1Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 3 ) ); // p1, p2=-p1
        gameBuilder->clone()->addNextPositions(p1s1Choice).addNextPositions(p2s2Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 1 ) ); // p1, p2=-p1
        gameBuilder->clone()->addNextPositions(p1s1Choice).addNextPositions(p2s3Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 8 ) ); // p1, p2=-p1
        gameBuilder->clone()->addNextPositions(p1s1Choice).addNextPositions(p2s4Choice).setPayoffs(payoff);
    }

    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 5 ) ); // p1, p2=-p1
        gameBuilder->clone()->addNextPositions(p1s2Choice).addNextPositions(p2s1Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 5 ) ); // p1, p2=-p1
        gameBuilder->clone()->addNextPositions(p1s2Choice).addNextPositions(p2s2Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 4 ) ); // p1, p2=-p1
        gameBuilder->clone()->addNextPositions(p1s2Choice).addNextPositions(p2s3Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 6 ) ); // p1, p2=-p1
        gameBuilder->clone()->addNextPositions(p1s2Choice).addNextPositions(p2s4Choice).setPayoffs(payoff);
    }

    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( -4 ) ); // p1, p2=-p1
        gameBuilder->clone()->addNextPositions(p1s3Choice).addNextPositions(p2s1Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 6 ) ); // p1, p2=-p1
        gameBuilder->clone()->addNextPositions(p1s3Choice).addNextPositions(p2s2Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 0 ) ); // p1, p2=-p1
        gameBuilder->clone()->addNextPositions(p1s3Choice).addNextPositions(p2s3Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 5 ) ); // p1, p2=-p1
        gameBuilder->clone()->addNextPositions(p1s3Choice).addNextPositions(p2s4Choice).setPayoffs(payoff);
    }


    GT::Model::GamePtr          game       = gameBuilder->build();
    GT::Routines::ConditionsPtr conditions = GT::Routines::NullFactory::getInstance().createConditions();

    // when
    GT::Routines::MatrixMixedEquilibriumRoutine routine;
    GT::Model::ResultPtr result;

    // then
    BOOST_REQUIRE_NO_THROW( result = routine.findResultFor(game, conditions) );
    BOOST_CHECK_EQUAL(
        result->getResult(),
        GT::Message() +
        "Mixed Strategies:\n"
        "\tp1:\n"
        "\t\tp1s1:\n"
        "\t\t\t0.00000\n"
        "\t\tp1s2:\n"
        "\t\t\t1.00000\n"
        "\t\tp1s3:\n"
        "\t\t\t0.00000\n"
        "\tp2:\n"
        "\t\tp2s1:\n"
        "\t\t\t0.00000\n"
        "\t\tp2s2:\n"
        "\t\t\t0.00000\n"
        "\t\tp2s3:\n"
        "\t\t\t1.00000\n"
        "\t\tp2s4:\n"
        "\t\t\t0.00000\n"
        "Payoff:\n"
        "\t\t\tp1,\tp2\n"
        "\tPayoff:\n"
        "\t\t\t4.00000,\t-4.00000\n"
    );
}

BOOST_AUTO_TEST_CASE( MatrixMixedEquilibriumRoutine_toString ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    // when
    GT::Routines::MatrixMixedEquilibriumRoutine routine;

    // then
    BOOST_CHECK_EQUAL(
        routine.toString(),
        GT::Message() +
        "MatrixMixedEquilibriumRoutine"
    );
}

BOOST_AUTO_TEST_CASE(rock_paper_scissors) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::IdentifierPtr  p1       = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr  p2       = GT::createIdentifierPtr("p2");
    GT::IdentifierPtr  rock     = GT::createIdentifierPtr("rock");
    GT::IdentifierPtr  paper    = GT::createIdentifierPtr("paper");
    GT::IdentifierPtr  scissors = GT::createIdentifierPtr("scissors");
    GT::IdentifiersPtr rps      = GT::createIdentifiersPtr();
    rps->push_back( rock );
    rps->push_back( paper );
    rps->push_back( scissors );

    GT::PositionsPtr p1Rock = GT::createPositionsPtr();
    p1Rock->insert( GT::Positions::value_type( *p1, *rock ) );
    GT::PositionsPtr p1Paper = GT::createPositionsPtr();
    p1Paper->insert( GT::Positions::value_type( *p1, *paper ) );
    GT::PositionsPtr p1Scissors = GT::createPositionsPtr();
    p1Scissors->insert( GT::Positions::value_type( *p1, *scissors ) );

    GT::PositionsPtr p2Rock = GT::createPositionsPtr();
    p2Rock->insert( GT::Positions::value_type( *p2, *rock ) );
    GT::PositionsPtr p2Paper = GT::createPositionsPtr();
    p2Paper->insert( GT::Positions::value_type( *p2, *paper ) );
    GT::PositionsPtr p2Scissors = GT::createPositionsPtr();
    p2Scissors->insert( GT::Positions::value_type( *p2, *scissors ) );

    GT::Model::PlayersPtr players = make_shared<GT::Model::Players>();
    GT::Model::PlayerPtr  player1 = make_shared<GT::Model::Player>(p1, rps);
    GT::Model::PlayerPtr  player2 = make_shared<GT::Model::Player>(p2, rps);
    players->insert( GT::Model::Players::value_type( *p1, player1 ) );
    players->insert( GT::Model::Players::value_type( *p2, player2 ) );

    GT::Model::GameBuilderPtr gameBuilder = GT::Model::GameFactory::getInstance().buildStrategicGame();
    gameBuilder->setPlayers(players);

    GT::NumbersPtr win = GT::createNumbersPtr();
    win->push_back( GT::createNumberPtr( 1.0 ) );
    GT::NumbersPtr loose = GT::createNumbersPtr();
    loose->push_back( GT::createNumberPtr( -1.0 ) );
    GT::NumbersPtr draw = GT::createNumbersPtr();
    draw->push_back( GT::createNumberPtr( 0.0 ) );

    gameBuilder->clone()->addNextPositions(p1Rock).addNextPositions(p2Rock).setPayoffs(draw);
    gameBuilder->clone()->addNextPositions(p1Rock).addNextPositions(p2Paper).setPayoffs(loose);
    gameBuilder->clone()->addNextPositions(p1Rock).addNextPositions(p2Scissors).setPayoffs(win);
    gameBuilder->clone()->addNextPositions(p1Paper).addNextPositions(p2Rock).setPayoffs(win);
    gameBuilder->clone()->addNextPositions(p1Paper).addNextPositions(p2Paper).setPayoffs(draw);
    gameBuilder->clone()->addNextPositions(p1Paper).addNextPositions(p2Scissors).setPayoffs(loose);
    gameBuilder->clone()->addNextPositions(p1Scissors).addNextPositions(p2Rock).setPayoffs(loose);
    gameBuilder->clone()->addNextPositions(p1Scissors).addNextPositions(p2Paper).setPayoffs(win);
    gameBuilder->clone()->addNextPositions(p1Scissors).addNextPositions(p2Scissors).setPayoffs(draw);

    GT::Model::GamePtr          game       = gameBuilder->build();
    GT::Routines::ConditionsPtr conditions = GT::Routines::NullFactory::getInstance().createConditions();

    // when
    GT::Routines::MatrixMixedEquilibriumRoutine routine;
    GT::Model::ResultPtr result;

    // then
    BOOST_REQUIRE_NO_THROW( result = routine.findResultFor(game, conditions) );
    BOOST_CHECK_EQUAL(
        result->getResult(),
        GT::Message() +
        "Mixed Strategies:\n"
        "\tp1:\n"
        "\t\trock:\n"
        "\t\t\t0.33333\n"
        "\t\tpaper:\n"
        "\t\t\t0.33333\n"
        "\t\tscissors:\n"
        "\t\t\t0.33333\n"
        "\tp2:\n"
        "\t\trock:\n"
        "\t\t\t0.33333\n"
        "\t\tpaper:\n"
        "\t\t\t0.33333\n"
        "\t\tscissors:\n"
        "\t\t\t0.33333\n"
        "Payoff:\n"
        "\t\t\tp1,\tp2\n"
        "\tPayoff:\n"
        "\t\t\t0.00000,\t-0.00000\n"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
