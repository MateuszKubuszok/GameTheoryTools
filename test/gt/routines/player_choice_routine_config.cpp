#include "gt/routines/test_common.hpp"

BOOST_AUTO_TEST_SUITE( PlayerChoiceRoutineConfig )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using boost::make_shared;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class PlayerChoiceRoutineConfigImpl : public GT::Routines::PlayerChoiceRoutineConfig {
public:
    explicit PlayerChoiceRoutineConfigImpl(
        const GT::Model::PlayersPtr players
    ) :
        GT::Routines::PlayerChoiceRoutineConfig(players)
        {}

    virtual bool isValid() const override {
        return GT::Routines::PlayerChoiceRoutineConfig::isValid();
    }

    virtual GT::Message toString() const {
        return GT::Message("PlayerChoiceRoutineConfigImpl");
    }
}; /* END class PlayerChoiceRoutineConfigImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( PlayerChoiceRoutineConfig_functional ) {
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

    GT::Model::PlayersPtr players = make_shared<GT::Model::Players>();
    GT::Model::PlayerPtr  player1 = make_shared<GT::Model::Player>(p1, p1s);
    GT::Model::PlayerPtr  player2 = make_shared<GT::Model::Player>(p2, p2s);
    players->insert( GT::Model::Players::value_type( *p1, player1 ) );
    players->insert( GT::Model::Players::value_type( *p2, player2 ) );

    GT::Identifier  choiceExactly(*p1s2);
    GT::Identifiers choiceWithin;
    choiceWithin.push_back(p2s2);
    GT::Identifiers invalidChoice;

    // when
    PlayerChoiceRoutineConfigImpl routineConfig(players);

    // then
    BOOST_REQUIRE_NO_THROW( routineConfig.getAvailableStrategies(*p1) );
    BOOST_CHECK_EQUAL(      routineConfig.getAvailableStrategies(*p1).size(), 2 );
    BOOST_REQUIRE_NO_THROW( routineConfig.requireChoiceExactly(  *p1, choiceExactly) );
    BOOST_REQUIRE_NO_THROW( routineConfig.getAvailableStrategies(*p1) );
    BOOST_CHECK_EQUAL(      routineConfig.getAvailableStrategies(*p1).size(), 1 );
    BOOST_CHECK(            routineConfig.isValid() );

    BOOST_REQUIRE_NO_THROW( routineConfig.getAvailableStrategies(*p2) );
    BOOST_CHECK_EQUAL(      routineConfig.getAvailableStrategies(*p2).size(), 2 );
    BOOST_REQUIRE_NO_THROW( routineConfig.requireChoiceWithin(   *p2, choiceWithin) );
    BOOST_REQUIRE_NO_THROW( routineConfig.getAvailableStrategies(*p2) );
    BOOST_CHECK_EQUAL(      routineConfig.getAvailableStrategies(*p2).size(), 1 );
    BOOST_CHECK(            routineConfig.isValid() );

    BOOST_REQUIRE_NO_THROW( routineConfig.getAvailableStrategies(*p1) );
    BOOST_CHECK_EQUAL(      routineConfig.getAvailableStrategies(*p1).size(), 1 );
    BOOST_REQUIRE_NO_THROW( routineConfig.requireChoiceWithin(   *p1, invalidChoice) );
    BOOST_REQUIRE_NO_THROW( routineConfig.getAvailableStrategies(*p1) );
    BOOST_CHECK_EQUAL(      routineConfig.getAvailableStrategies(*p1).size(), 0 );
    BOOST_CHECK(           !routineConfig.isValid() );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
