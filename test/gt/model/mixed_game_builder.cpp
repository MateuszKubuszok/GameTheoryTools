#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>

#include "gt/model/inner_common.hpp"

BOOST_AUTO_TEST_SUITE( MixedGameBulder )

BOOST_AUTO_TEST_CASE( MixedGameBuilder_functional ) {
    // given
    GT::IdentifierPtr  playerName = GT::createIdentifierPtr("p1"); 
    GT::IdentifierPtr  strategy1  = GT::createIdentifierPtr("p1s1"); 
    GT::IdentifierPtr  strategy2  = GT::createIdentifierPtr("p1s2");
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();
    strategies->push_back( strategy1 );
    strategies->push_back( strategy2 );
    GT::Model::PlayerPtr  player(new GT::Model::Player(playerName, strategies));
    GT::Model::PlayersPtr players(new GT::Model::Players());
    players->insert( GT::Model::Players::value_type( *playerName, player) );
    
    GT::NumbersPtr params1 = GT::createNumbersPtr();
    params1->push_back( GT::createNumberPtr(10) );
    GT::NumbersPtr params2 = GT::createNumbersPtr();
    params2->push_back( GT::createNumberPtr(20) );
    
    GT::PositionsPtr positions1 = GT::createPositionsPtr();
    positions1->insert( GT::Positions::value_type( *playerName, *strategy1 ) );
    GT::PositionsPtr positions2 = GT::createPositionsPtr();
    positions2->insert( GT::Positions::value_type( *playerName, *strategy2 ) );

    // when
    GT::Model::MixedGameBuilder MixedGameBuilder;
    MixedGameBuilder.setPlayers(players);
    
    MixedGameBuilder.clone()->addNextPositions(positions1).setParams(params1);
    MixedGameBuilder.clone()->addNextPositions(positions2).setParams(params2);

    GT::Model::GamePtr game = MixedGameBuilder.build();

    // then
    BOOST_CHECK_EQUAL(
        game->toString(),
        GT::Message() +
        "\t\n" +
        "Mixed Game:\n" +
        "\t\t\n" +
        "\tValue:\n" +
        "\t\t\t\tp1,\n" +
        "\t\tPosition:\n" +
        "\t\t\t\tp1s1,\n" +
        "\t\tPayoff:\n" +
        "\t\t\t\t10,\n" +
        "\tValue:\n" +
        "\t\t\t\tp1,\n" +
        "\t\tPosition:\n" +
        "\t\t\t\tp1s2,\n" +
        "\t\tPayoff:\n" +
        "\t\t\t\t20,\n"
    );
}

BOOST_AUTO_TEST_CASE( MixedGameBuilder_toString ) {
    // given
    GT::IdentifierPtr  playerName = GT::createIdentifierPtr("p1"); 
    GT::IdentifierPtr  strategy1  = GT::createIdentifierPtr("p1s1"); 
    GT::IdentifierPtr  strategy2  = GT::createIdentifierPtr("p1s2");
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();
    strategies->push_back( strategy1 );
    strategies->push_back( strategy2 );
    GT::Model::PlayerPtr  player(new GT::Model::Player(playerName, strategies));
    GT::Model::PlayersPtr players(new GT::Model::Players());
    players->insert( GT::Model::Players::value_type( *playerName, player) );
    
    GT::NumbersPtr params1 = GT::createNumbersPtr();
    params1->push_back( GT::createNumberPtr(10) );
    GT::NumbersPtr params2 = GT::createNumbersPtr();
    params2->push_back( GT::createNumberPtr(20) );
    
    GT::PositionsPtr positions1 = GT::createPositionsPtr();
    positions1->insert( GT::Positions::value_type( *playerName, *strategy1 ) );
    GT::PositionsPtr positions2 = GT::createPositionsPtr();
    positions2->insert( GT::Positions::value_type( *playerName, *strategy2 ) );

    // when
    GT::Model::MixedGameBuilder MixedGameBuilder;
    MixedGameBuilder.setPlayers(players);
    
    MixedGameBuilder.clone()->addNextPositions(positions1).setParams(params1);
    MixedGameBuilder.clone()->addNextPositions(positions2).setParams(params2);

    // then
    BOOST_CHECK_EQUAL(
        MixedGameBuilder.toString(),
        GT::Message() +
        "\t\n" +
        "Current Mixed Game:\n" +
        "\t\t\n" +
        "\tCurrent Data:\n" +
        "\t\t\t\n" +
        "\t\tValue:\n" +
        "\t\t\t\t\tp1,\n" +
        "\t\t\tPosition:\n" +
        "\t\t\t\t\tp1s1,\n" +
        "\t\t\tPayoff:\n" +
        "\t\t\t\t\t10,\n" +
        "\t\tValue:\n" +
        "\t\t\t\t\tp1,\n" +
        "\t\t\tPosition:\n" +
        "\t\t\t\t\tp1s2,\n" +
        "\t\t\tPayoff:\n" +
        "\t\t\t\t\t20,\n"
    );
}

BOOST_AUTO_TEST_SUITE_END()
