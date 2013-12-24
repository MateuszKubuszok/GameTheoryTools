#include "gt/routines/test_common.hpp"

BOOST_AUTO_TEST_SUITE( InformationSetChoiceRoutineConfig )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class InformationSetChoiceRoutineConfigImpl : public GT::Routines::InformationSetChoiceRoutineConfig {
public:
    explicit InformationSetChoiceRoutineConfigImpl(
        const GT::Model::ExtensiveDataNodePtr extensiveGameRoot
    ) :
        GT::Routines::InformationSetChoiceRoutineConfig(extensiveGameRoot)
        {}

    virtual bool isValid() const override {
        return GT::Routines::InformationSetChoiceRoutineConfig::isValid();
    }

    virtual GT::Message toString() const {
        return GT::Message("InformationSetChoiceRoutineConfigImpl");
    }
}; /* END class InformationSetChoiceRoutineConfigImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( InformationSetChoiceRoutineConfig_functional ) {
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

    GT::Identifier is1("1");
    GT::Identifier is2("2");

    GT::Identifier  choiceExactly(*p1s2);
    GT::Identifiers choiceWithin;
    choiceWithin.push_back(p2s2);
    GT::Identifiers invalidChoice;

    // when
    InformationSetChoiceRoutineConfigImpl routineConfig(extensiveGameRoot);

    // then
    BOOST_REQUIRE_NO_THROW( routineConfig.getAvailableStrategies(*p1, is1) );
    BOOST_CHECK_EQUAL(      routineConfig.getAvailableStrategies(*p1, is1).size(), 2 );
    BOOST_REQUIRE_NO_THROW( routineConfig.requireChoiceExactly(  *p1, is1, choiceExactly) );
    BOOST_REQUIRE_NO_THROW( routineConfig.getAvailableStrategies(*p1, is1) );
    BOOST_CHECK_EQUAL(      routineConfig.getAvailableStrategies(*p1, is1).size(), 1 );
    BOOST_CHECK(            routineConfig.isValid() );

    BOOST_REQUIRE_NO_THROW( routineConfig.getAvailableStrategies(*p2, is1) );
    BOOST_CHECK_EQUAL(      routineConfig.getAvailableStrategies(*p2, is1).size(), 2 );
    BOOST_REQUIRE_NO_THROW( routineConfig.requireChoiceWithin(   *p2, is1, choiceWithin) );
    BOOST_REQUIRE_NO_THROW( routineConfig.getAvailableStrategies(*p2, is1) );
    BOOST_CHECK_EQUAL(      routineConfig.getAvailableStrategies(*p2, is1).size(), 1 );
    BOOST_CHECK(            routineConfig.isValid() );

    BOOST_REQUIRE_NO_THROW( routineConfig.getAvailableStrategies(*p1, is2) );
    BOOST_CHECK_EQUAL(      routineConfig.getAvailableStrategies(*p1, is2).size(), 2 );
    BOOST_REQUIRE_NO_THROW( routineConfig.requireChoiceWithin(   *p1, is2, invalidChoice) );
    BOOST_REQUIRE_NO_THROW( routineConfig.getAvailableStrategies(*p1, is2) );
    BOOST_CHECK_EQUAL(      routineConfig.getAvailableStrategies(*p1, is2).size(), 0 );
    BOOST_CHECK(           !routineConfig.isValid() );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
