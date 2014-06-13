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

BOOST_AUTO_TEST_CASE( battle_of_the_sexes ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::IdentifierPtr  h        = GT::createIdentifierPtr("h");
    GT::IdentifierPtr  w        = GT::createIdentifierPtr("w");
    GT::IdentifierPtr  opera    = GT::createIdentifierPtr("opera");
    GT::IdentifierPtr  football = GT::createIdentifierPtr("football");
    GT::IdentifiersPtr bots     = GT::createIdentifiersPtr();
    bots->push_back( opera );
    bots->push_back( football );

    GT::PositionsPtr p1Opera = GT::createPositionsPtr();
    p1Opera->insert( GT::Positions::value_type( *h, *opera ) );
    GT::PositionsPtr p1Football = GT::createPositionsPtr();
    p1Football->insert( GT::Positions::value_type( *h, *football ) );

    GT::PositionsPtr p2Opera = GT::createPositionsPtr();
    p2Opera->insert( GT::Positions::value_type( *w, *opera ) );
    GT::PositionsPtr p2Football = GT::createPositionsPtr();
    p2Football->insert( GT::Positions::value_type( *w, *football ) );

    GT::Model::PlayersPtr players(new GT::Model::Players());
    GT::Model::PlayerPtr  husband(new GT::Model::Player(h, bots));
    GT::Model::PlayerPtr  wife(new GT::Model::Player(w, bots));
    players->insert( GT::Model::Players::value_type( *h, husband ) );
    players->insert( GT::Model::Players::value_type( *w, wife ) );

    GT::Model::GameBuilderPtr gameBuilder = GT::Model::GameFactory::getInstance().buildStrategicGame();
    gameBuilder->setPlayers(players);

    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 2.0 ) );
        payoff->push_back( GT::createNumberPtr( 3.0 ) );
        gameBuilder->clone()->addNextPositions(p1Opera).addNextPositions(p2Opera).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 0.0 ) );
        payoff->push_back( GT::createNumberPtr( 0.0 ) );
        gameBuilder->clone()->addNextPositions(p1Opera).addNextPositions(p2Football).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 0.0 ) );
        payoff->push_back( GT::createNumberPtr( 0.0 ) );
        gameBuilder->clone()->addNextPositions(p1Football).addNextPositions(p2Opera).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 3.0 ) );
        payoff->push_back( GT::createNumberPtr( 2.0 ) );
        gameBuilder->clone()->addNextPositions(p1Football).addNextPositions(p2Football).setPayoffs(payoff);
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
        "\th:\n"
        "\t\topera:\n"
        "\t\t\t0.40000\n"
        "\t\tfootball:\n"
        "\t\t\t0.60000\n"
        "\tw:\n"
        "\t\topera:\n"
        "\t\t\t0.60000\n"
        "\t\tfootball:\n"
        "\t\t\t0.40000\n"
        "Payoff:\n"
        "\t\t\th,\tw\n"
        "\tPayoff:\n"
        "\t\t\t1.20000,\t1.20000\n"
    );
}

BOOST_AUTO_TEST_CASE( chicken ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::IdentifierPtr  p1       = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr  p2       = GT::createIdentifierPtr("p2");
    GT::IdentifierPtr  swerve   = GT::createIdentifierPtr("swerves");
    GT::IdentifierPtr  straight = GT::createIdentifierPtr("straight");
    GT::IdentifiersPtr ch       = GT::createIdentifiersPtr();
    ch->push_back( swerve );
    ch->push_back( straight );

    GT::PositionsPtr p1Swerve = GT::createPositionsPtr();
    p1Swerve->insert( GT::Positions::value_type( *p1, *swerve ) );
    GT::PositionsPtr p1dStraight = GT::createPositionsPtr();
    p1dStraight->insert( GT::Positions::value_type( *p1, *straight ) );

    GT::PositionsPtr p2Swerve = GT::createPositionsPtr();
    p2Swerve->insert( GT::Positions::value_type( *p2, *swerve ) );
    GT::PositionsPtr p2dStraight = GT::createPositionsPtr();
    p2dStraight->insert( GT::Positions::value_type( *p2, *straight ) );

    GT::Model::PlayersPtr players(new GT::Model::Players());
    GT::Model::PlayerPtr  player1(new GT::Model::Player(p1, ch));
    GT::Model::PlayerPtr  player2(new GT::Model::Player(p2, ch));
    players->insert( GT::Model::Players::value_type( *p1, player1 ) );
    players->insert( GT::Model::Players::value_type( *p2, player2 ) );

    GT::Model::GameBuilderPtr gameBuilder = GT::Model::GameFactory::getInstance().buildStrategicGame();
    gameBuilder->setPlayers(players);

    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 0.0 ) );
        payoff->push_back( GT::createNumberPtr( 0.0 ) );
        gameBuilder->clone()->addNextPositions(p1Swerve).addNextPositions(p2Swerve).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( -1.0 ) );
        payoff->push_back( GT::createNumberPtr(  1.0 ) );
        gameBuilder->clone()->addNextPositions(p1Swerve).addNextPositions(p2dStraight).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr(  1.0 ) );
        payoff->push_back( GT::createNumberPtr( -1.0 ) );
        gameBuilder->clone()->addNextPositions(p1dStraight).addNextPositions(p2Swerve).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( -10.0 ) );
        payoff->push_back( GT::createNumberPtr( -10.0 ) );
        gameBuilder->clone()->addNextPositions(p1dStraight).addNextPositions(p2dStraight).setPayoffs(payoff);
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
        "\t\tswerves:\n"
        "\t\t\t0.90000\n"
        "\t\tstraight:\n"
        "\t\t\t0.10000\n"
        "\tp2:\n"
        "\t\tswerves:\n"
        "\t\t\t0.90000\n"
        "\t\tstraight:\n"
        "\t\t\t0.10000\n"
        "Payoff:\n"
        "\t\t\tp1,\tp2\n"
        "\tPayoff:\n"
        "\t\t\t-0.10000,\t-0.10000\n"
    );
}

BOOST_AUTO_TEST_CASE( peace_war ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::IdentifierPtr  p1    = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr  p2    = GT::createIdentifierPtr("p2");
    GT::IdentifierPtr  peace = GT::createIdentifierPtr("peace");
    GT::IdentifierPtr  war   = GT::createIdentifierPtr("war");
    GT::IdentifiersPtr pw    = GT::createIdentifiersPtr();
    pw->push_back( peace );
    pw->push_back( war );

    GT::PositionsPtr p1Peace = GT::createPositionsPtr();
    p1Peace->insert( GT::Positions::value_type( *p1, *peace ) );
    GT::PositionsPtr p1War = GT::createPositionsPtr();
    p1War->insert( GT::Positions::value_type( *p1, *war ) );

    GT::PositionsPtr p2Peace = GT::createPositionsPtr();
    p2Peace->insert( GT::Positions::value_type( *p2, *peace ) );
    GT::PositionsPtr p2War = GT::createPositionsPtr();
    p2War->insert( GT::Positions::value_type( *p2, *war ) );

    GT::Model::PlayersPtr players(new GT::Model::Players());
    GT::Model::PlayerPtr  player1(new GT::Model::Player(p1, pw));
    GT::Model::PlayerPtr  player2(new GT::Model::Player(p2, pw));
    players->insert( GT::Model::Players::value_type( *p1, player1 ) );
    players->insert( GT::Model::Players::value_type( *p2, player2 ) );

    GT::Model::GameBuilderPtr gameBuilder = GT::Model::GameFactory::getInstance().buildStrategicGame();
    gameBuilder->setPlayers(players);

    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 2.0 ) );
        payoff->push_back( GT::createNumberPtr( 2.0 ) );
        gameBuilder->clone()->addNextPositions(p1Peace).addNextPositions(p2Peace).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 0.0 ) );
        payoff->push_back( GT::createNumberPtr( 3.0 ) );
        gameBuilder->clone()->addNextPositions(p1Peace).addNextPositions(p2War).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 3.0 ) );
        payoff->push_back( GT::createNumberPtr( 0.0 ) );
        gameBuilder->clone()->addNextPositions(p1War).addNextPositions(p2Peace).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 1.0 ) );
        payoff->push_back( GT::createNumberPtr( 1.0 ) );
        gameBuilder->clone()->addNextPositions(p1War).addNextPositions(p2War).setPayoffs(payoff);
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
        "\t\tpeace:\n"
        "\t\t\t0.00000\n"
        "\t\twar:\n"
        "\t\t\t1.00000\n"
        "\tp2:\n"
        "\t\tpeace:\n"
        "\t\t\t0.00000\n"
        "\t\twar:\n"
        "\t\t\t1.00000\n"
        "Payoff:\n"
        "\t\t\tp1,\tp2\n"
        "\tPayoff:\n"
        "\t\t\t1.00000,\t1.00000\n"
    );
}

BOOST_AUTO_TEST_CASE( prisonners_dilemma ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::IdentifierPtr  p1        = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr  p2        = GT::createIdentifierPtr("p2");
    GT::IdentifierPtr  cooperate = GT::createIdentifierPtr("cooperates");
    GT::IdentifierPtr  defects   = GT::createIdentifierPtr("defects");
    GT::IdentifiersPtr pd        = GT::createIdentifiersPtr();
    pd->push_back( cooperate );
    pd->push_back( defects );

    GT::PositionsPtr p1Cooperate = GT::createPositionsPtr();
    p1Cooperate->insert( GT::Positions::value_type( *p1, *cooperate ) );
    GT::PositionsPtr p1Defects = GT::createPositionsPtr();
    p1Defects->insert( GT::Positions::value_type( *p1, *defects ) );

    GT::PositionsPtr p2Cooperate = GT::createPositionsPtr();
    p2Cooperate->insert( GT::Positions::value_type( *p2, *cooperate ) );
    GT::PositionsPtr p2Defects = GT::createPositionsPtr();
    p2Defects->insert( GT::Positions::value_type( *p2, *defects ) );

    GT::Model::PlayersPtr players(new GT::Model::Players());
    GT::Model::PlayerPtr  player1(new GT::Model::Player(p1, pd));
    GT::Model::PlayerPtr  player2(new GT::Model::Player(p2, pd));
    players->insert( GT::Model::Players::value_type( *p1, player1 ) );
    players->insert( GT::Model::Players::value_type( *p2, player2 ) );

    GT::Model::GameBuilderPtr gameBuilder = GT::Model::GameFactory::getInstance().buildStrategicGame();
    gameBuilder->setPlayers(players);

    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( -1.0 ) );
        payoff->push_back( GT::createNumberPtr( -1.0 ) );
        gameBuilder->clone()->addNextPositions(p1Cooperate).addNextPositions(p2Cooperate).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( -3.0 ) );
        payoff->push_back( GT::createNumberPtr(  0.0 ) );
        gameBuilder->clone()->addNextPositions(p1Cooperate).addNextPositions(p2Defects).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr(  0.0 ) );
        payoff->push_back( GT::createNumberPtr( -3.0 ) );
        gameBuilder->clone()->addNextPositions(p1Defects).addNextPositions(p2Cooperate).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( -2.0 ) );
        payoff->push_back( GT::createNumberPtr( -2.0 ) );
        gameBuilder->clone()->addNextPositions(p1Defects).addNextPositions(p2Defects).setPayoffs(payoff);
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
        "\t\tcooperates:\n"
        "\t\t\t0.00000\n"
        "\t\tdefects:\n"
        "\t\t\t1.00000\n"
        "\tp2:\n"
        "\t\tcooperates:\n"
        "\t\t\t0.00000\n"
        "\t\tdefects:\n"
        "\t\t\t1.00000\n"
        "Payoff:\n"
        "\t\t\tp1,\tp2\n"
        "\tPayoff:\n"
        "\t\t\t-2.00000,\t-2.00000\n"
    );
}

BOOST_AUTO_TEST_CASE( stag_hunt ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::IdentifierPtr  p1   = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr  p2   = GT::createIdentifierPtr("p2");
    GT::IdentifierPtr  stag = GT::createIdentifierPtr("stag");
    GT::IdentifierPtr  hare = GT::createIdentifierPtr("hare");
    GT::IdentifiersPtr sh   = GT::createIdentifiersPtr();
    sh->push_back( stag );
    sh->push_back( hare );

    GT::PositionsPtr p1Stag = GT::createPositionsPtr();
    p1Stag->insert( GT::Positions::value_type( *p1, *stag ) );
    GT::PositionsPtr p1Hare = GT::createPositionsPtr();
    p1Hare->insert( GT::Positions::value_type( *p1, *hare ) );

    GT::PositionsPtr p2Stag = GT::createPositionsPtr();
    p2Stag->insert( GT::Positions::value_type( *p2, *stag ) );
    GT::PositionsPtr p2Hare = GT::createPositionsPtr();
    p2Hare->insert( GT::Positions::value_type( *p2, *hare ) );

    GT::Model::PlayersPtr players(new GT::Model::Players());
    GT::Model::PlayerPtr  player1(new GT::Model::Player(p1, sh));
    GT::Model::PlayerPtr  player2(new GT::Model::Player(p2, sh));
    players->insert( GT::Model::Players::value_type( *p1, player1 ) );
    players->insert( GT::Model::Players::value_type( *p2, player2 ) );

    GT::Model::GameBuilderPtr gameBuilder = GT::Model::GameFactory::getInstance().buildStrategicGame();
    gameBuilder->setPlayers(players);

    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 2.0 ) );
        payoff->push_back( GT::createNumberPtr( 2.0 ) );
        gameBuilder->clone()->addNextPositions(p1Stag).addNextPositions(p2Stag).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 0.0 ) );
        payoff->push_back( GT::createNumberPtr( 1.0 ) );
        gameBuilder->clone()->addNextPositions(p1Stag).addNextPositions(p2Hare).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 1.0 ) );
        payoff->push_back( GT::createNumberPtr( 0.0 ) );
        gameBuilder->clone()->addNextPositions(p1Hare).addNextPositions(p2Stag).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 1.0 ) );
        payoff->push_back( GT::createNumberPtr( 1.0 ) );
        gameBuilder->clone()->addNextPositions(p1Hare).addNextPositions(p2Hare).setPayoffs(payoff);
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
        "\t\tstag:\n"
        "\t\t\t0.50000\n"
        "\t\thare:\n"
        "\t\t\t0.50000\n"
        "\tp2:\n"
        "\t\tstag:\n"
        "\t\t\t0.50000\n"
        "\t\thare:\n"
        "\t\t\t0.50000\n"
        "Payoff:\n"
        "\t\t\tp1,\tp2\n"
        "\tPayoff:\n"
        "\t\t\t1.00000,\t1.00000\n"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
