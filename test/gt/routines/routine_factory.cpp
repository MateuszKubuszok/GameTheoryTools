#include "gt/routines/test_common.hpp"

BOOST_AUTO_TEST_SUITE( RoutineFactory )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using boost::make_shared;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( RoutineFactory_pureStrategyEquilibriumFindingRoutineFor ) {
    // given
    GT::Model::PlayersPtr players = GT::Model::NullFactory::getInstance().createPlayers();

    GT::Model::StrategicDataPtr strategicData =
        GT::Model::InnerNullFactory::getInstance().createStrategicData();
    GT::Model::GamePtr strategicGame = make_shared<GT::Model::StrategicGame>(players, strategicData);

    GT::Model::ExtensiveDataPtr extensiveData =
        GT::Model::InnerNullFactory::getInstance().createExtensiveData();
    GT::Model::GamePtr extensiveGame = make_shared<GT::Model::ExtensiveGame>(players, extensiveData);

    // when
    GT::Routines::RoutinePtr strategicPureEquilibriumRoutine =
        GT::Routines::RoutineFactory::getInstance().pureStrategyEquilibriumFindingRoutineFor(strategicGame);
    GT::Routines::RoutinePtr extensivePureEquilibriumRoutine =
        GT::Routines::RoutineFactory::getInstance().pureStrategyEquilibriumFindingRoutineFor(extensiveGame);

    // then
    BOOST_CHECK( boost::dynamic_pointer_cast<GT::Routines::StrategicPureEquilibriumRoutine>(
        strategicPureEquilibriumRoutine
    ) );
    BOOST_CHECK( boost::dynamic_pointer_cast<GT::Routines::ExtensivePureEquilibriumRoutine>(
        extensivePureEquilibriumRoutine
    ) );
}

BOOST_AUTO_TEST_CASE( RoutineFactory_mixedStrategyEquilibriumFindingRoutineFor ) {
    // given
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

    GT::Model::GameBuilderPtr _0SGameBuilder = GT::Model::GameFactory::getInstance().buildStrategicGame();
    _0SGameBuilder->setPlayers(players);

    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( -5 ) ); // p1, p2=-p1
        _0SGameBuilder->clone()->addNextPositions(p1s1Choice).addNextPositions(p2s1Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 3 ) ); // p1, p2=-p1
        _0SGameBuilder->clone()->addNextPositions(p1s1Choice).addNextPositions(p2s2Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 1 ) ); // p1, p2=-p1
        _0SGameBuilder->clone()->addNextPositions(p1s1Choice).addNextPositions(p2s3Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 8 ) ); // p1, p2=-p1
        _0SGameBuilder->clone()->addNextPositions(p1s1Choice).addNextPositions(p2s4Choice).setPayoffs(payoff);
    }

    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 5 ) ); // p1, p2=-p1
        _0SGameBuilder->clone()->addNextPositions(p1s2Choice).addNextPositions(p2s1Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 5 ) ); // p1, p2=-p1
        _0SGameBuilder->clone()->addNextPositions(p1s2Choice).addNextPositions(p2s2Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 4 ) ); // p1, p2=-p1
        _0SGameBuilder->clone()->addNextPositions(p1s2Choice).addNextPositions(p2s3Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 6 ) ); // p1, p2=-p1
        _0SGameBuilder->clone()->addNextPositions(p1s2Choice).addNextPositions(p2s4Choice).setPayoffs(payoff);
    }

    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( -4 ) ); // p1, p2=-p1
        _0SGameBuilder->clone()->addNextPositions(p1s3Choice).addNextPositions(p2s1Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 6 ) ); // p1, p2=-p1
        _0SGameBuilder->clone()->addNextPositions(p1s3Choice).addNextPositions(p2s2Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 0 ) ); // p1, p2=-p1
        _0SGameBuilder->clone()->addNextPositions(p1s3Choice).addNextPositions(p2s3Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 5 ) ); // p1, p2=-p1
        _0SGameBuilder->clone()->addNextPositions(p1s3Choice).addNextPositions(p2s4Choice).setPayoffs(payoff);
    }

    GT::Model::GameBuilderPtr _2PGameBuilder = GT::Model::GameFactory::getInstance().buildStrategicGame();
    _2PGameBuilder->setPlayers(players);

    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 0 ) );
        payoff->push_back( GT::createNumberPtr( 6 ) );
        _2PGameBuilder->clone()->addNextPositions(p1s1Choice).addNextPositions(p2s1Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 3 ) );
        payoff->push_back( GT::createNumberPtr( 6 ) );
        _2PGameBuilder->clone()->addNextPositions(p1s1Choice).addNextPositions(p2s2Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 1 ) );
        payoff->push_back( GT::createNumberPtr( 2 ) );
        _2PGameBuilder->clone()->addNextPositions(p1s1Choice).addNextPositions(p2s3Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 8 ) );
        payoff->push_back( GT::createNumberPtr( 2 ) );
        _2PGameBuilder->clone()->addNextPositions(p1s1Choice).addNextPositions(p2s4Choice).setPayoffs(payoff);
    }

    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 5 ) );
        payoff->push_back( GT::createNumberPtr( 3 ) );
        _2PGameBuilder->clone()->addNextPositions(p1s2Choice).addNextPositions(p2s1Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 5 ) );
        payoff->push_back( GT::createNumberPtr( 2 ) );
        _2PGameBuilder->clone()->addNextPositions(p1s2Choice).addNextPositions(p2s2Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 4 ) );
        payoff->push_back( GT::createNumberPtr( 5 ) );
        _2PGameBuilder->clone()->addNextPositions(p1s2Choice).addNextPositions(p2s3Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 6 ) );
        payoff->push_back( GT::createNumberPtr( 6 ) );
        _2PGameBuilder->clone()->addNextPositions(p1s2Choice).addNextPositions(p2s4Choice).setPayoffs(payoff);
    }

    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 2 ) );
        payoff->push_back( GT::createNumberPtr( 0 ) );
        _2PGameBuilder->clone()->addNextPositions(p1s3Choice).addNextPositions(p2s1Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 6 ) );
        payoff->push_back( GT::createNumberPtr( 7 ) );
        _2PGameBuilder->clone()->addNextPositions(p1s3Choice).addNextPositions(p2s2Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 0 ) );
        payoff->push_back( GT::createNumberPtr( 0 ) );
        _2PGameBuilder->clone()->addNextPositions(p1s3Choice).addNextPositions(p2s3Choice).setPayoffs(payoff);
    }
    {
        GT::NumbersPtr payoff = GT::createNumbersPtr();
        payoff->push_back( GT::createNumberPtr( 5 ) );
        payoff->push_back( GT::createNumberPtr( 1 ) );
        _2PGameBuilder->clone()->addNextPositions(p1s3Choice).addNextPositions(p2s4Choice).setPayoffs(payoff);
    }

    GT::Model::GamePtr matrixGame   = _0SGameBuilder->build();
    GT::Model::GamePtr bimatrixGame = _2PGameBuilder->build();

    // when
    GT::Routines::RoutinePtr matrixMixedEquilibriumRoutine =
        GT::Routines::RoutineFactory::getInstance()
        .mixedStrategyEquilibriumFindingRoutineFor(matrixGame);
    GT::Routines::RoutinePtr bimatrixMixedEquilibriumRoutine =
        GT::Routines::RoutineFactory::getInstance()
        .mixedStrategyEquilibriumFindingRoutineFor(bimatrixGame);

    // then
    BOOST_CHECK( boost::dynamic_pointer_cast<GT::Routines::MatrixMixedEquilibriumRoutine>(
        matrixMixedEquilibriumRoutine
    ) );
    BOOST_CHECK( boost::dynamic_pointer_cast<GT::Routines::BimatrixMixedEquilibriumRoutine>(
        bimatrixMixedEquilibriumRoutine
    ) );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
