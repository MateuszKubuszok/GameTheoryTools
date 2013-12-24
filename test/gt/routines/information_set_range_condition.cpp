#include "gt/routines/test_common.hpp"

BOOST_AUTO_TEST_SUITE( InformationSetRangeCondition )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( InformationSetRangeCondition_configureRoutine ) {
    // given
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

    GT::Model::ExtensiveDataBuilder dataBuilder;
    dataBuilder.setPlayers(players);
    {
        GT::Model::DataBuilderPtr s1_node = dataBuilder.clone();
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
        GT::Model::DataBuilderPtr s2_node = dataBuilder.clone();
        s2_node->addNextPositions(p1s2Choice);
        {
            GT::NumbersPtr payoff = GT::createNumbersPtr();
            payoff->push_back( GT::createNumberPtr( -10 ) ); // p1
            payoff->push_back( GT::createNumberPtr(  10 ) ); // p2
            s2_node->setPayoffs(payoff);
        }
    }

    GT::Model::ExtensiveDataNodePtr extensiveGameRoot = dataBuilder.build()->getRoot();

    GT::Routines::RoutineConfigPtr routineConfig(
        new GT::Routines::ExtensivePureEquilibriumRoutineConfig(extensiveGameRoot)
    );
    boost::shared_ptr<GT::Routines::ExtensivePureEquilibriumRoutineConfig> specificRoutineConfig =
        boost::dynamic_pointer_cast<GT::Routines::ExtensivePureEquilibriumRoutineConfig>(routineConfig);

    GT::IdentifierPtr  player         = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr  informationSet = GT::createIdentifierPtr("1");
    GT::IdentifiersPtr strategies     = GT::createIdentifiersPtr();
    strategies->push_back( GT::createIdentifierPtr("p1s1") );

    // when
    GT::Routines::InformationSetRangeCondition condition(player, informationSet, strategies);

    BOOST_REQUIRE_EQUAL( specificRoutineConfig->getAvailableStrategies(*player, *informationSet).size(), 2 );
    BOOST_REQUIRE_NO_THROW( condition.configureRoutine(routineConfig) );
    BOOST_CHECK_EQUAL(   specificRoutineConfig->getAvailableStrategies(*player, *informationSet).size(), 1 );
}

BOOST_AUTO_TEST_CASE( InformationSetRangeCondition_toString ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::IdentifierPtr  player         = GT::Model::NullFactory::getInstance().createIdentifier();
    GT::IdentifierPtr  informationSet = GT::Model::NullFactory::getInstance().createIdentifier();
    GT::IdentifiersPtr strategies     = GT::createIdentifiersPtr();
    strategies->push_back( GT::Model::NullFactory::getInstance().createIdentifier() );
    strategies->push_back( GT::Model::NullFactory::getInstance().createIdentifier() );

    // when
    GT::Routines::InformationSetRangeCondition condition(player, informationSet, strategies);

    // then
    BOOST_CHECK_EQUAL(
        condition.toString(),
        GT::Message() +
        "NullIdentifier:\n"
        "\tNullIdentifier:\n"
        "\t\t1:\n"
        "\t\t\tNullIdentifier\n"
        "\t\t2:\n"
        "\t\t\tNullIdentifier\n"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
