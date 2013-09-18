#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>

#include "gt/model/inner_common.hpp"

BOOST_AUTO_TEST_SUITE( PlainDataBuilder )

BOOST_AUTO_TEST_CASE( PlainDataBuilder_getPlayers ) {
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

    // when
    GT::Model::PlainDataBuilder plainDataBuilder;
    plainDataBuilder.setPlayers(players);
    GT::Model::PlayersPtr gotPlayers = plainDataBuilder.getPlayers();

    // then
    BOOST_CHECK_EQUAL(
        players,
        gotPlayers
    );
}

BOOST_AUTO_TEST_CASE( PlainDataBuilder_getData ) {
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

    // when
    GT::Model::PlainDataBuilder plainDataBuilder;
    plainDataBuilder.setPlayers(players);

    // then
    GT::Model::DataPtr data = plainDataBuilder.getData();
}

BOOST_AUTO_TEST_CASE( PlainDataBuilder_toString ) {
    
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
    GT::Model::PlainDataBuilder plainDataBuilder;
    plainDataBuilder.setPlayers(players);
    
    plainDataBuilder.clone()->addNextPositions(positions1).setParams(params1);
    plainDataBuilder.clone()->addNextPositions(positions2).setParams(params2);

    // then
    BOOST_CHECK_EQUAL(
        plainDataBuilder.toString(),
        GT::Message() +
        "\t\n" +
        "Current Data:\n" +
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

BOOST_AUTO_TEST_CASE( PlainDataBuilder_functional ) {
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
    GT::Model::PlainDataBuilder plainDataBuilder;
    plainDataBuilder.setPlayers(players);
    
    plainDataBuilder.clone()->addNextPositions(positions1).setParams(params1);
    plainDataBuilder.clone()->addNextPositions(positions2).setParams(params2);

    GT::Model::DataPtr data = plainDataBuilder.getData();

    // then
    BOOST_CHECK_EQUAL(
        data->toString(),
        GT::Message() +
        "\t\n" +
        "Value:\n" +
        "\t\t\tp1,\n" +
        "\tPosition:\n" +
        "\t\t\tp1s1,\n" +
        "\tPayoff:\n" +
        "\t\t\t10,\n" +
        "Value:\n" +
        "\t\t\tp1,\n" +
        "\tPosition:\n" +
        "\t\t\tp1s2,\n" +
        "\tPayoff:\n" +
        "\t\t\t20,\n"
    );
}

BOOST_AUTO_TEST_SUITE_END()
