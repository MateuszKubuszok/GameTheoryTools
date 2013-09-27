#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>

#include "gt/model/inner_common.hpp"

BOOST_AUTO_TEST_SUITE( TreeDataBuilder )

BOOST_AUTO_TEST_CASE( TreeDataBuilder_setPlayers_getPlayers ) {
    // given
    GT::IdentifierPtr  playerName = GT::createIdentifierPtr("p1"); 
    GT::IdentifierPtr  strategy1  = GT::createIdentifierPtr("p1s1"); 
    GT::IdentifierPtr  strategy2  = GT::createIdentifierPtr("p1s2");
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();
    strategies->push_back( strategy1 );
    strategies->push_back( strategy2 );
    GT::Model::PlayerPtr  player(new GT::Model::Player(playerName, strategies));
    GT::Model::PlayersPtr players(new GT::Model::Players());
    players->insert( GT::Model::Players::value_type(*playerName, player) );

    // when
    GT::Model::TreeDataBuilder treeDataBuilder;
    treeDataBuilder.setPlayers(players);
    GT::Model::PlayersPtr gotPlayers = treeDataBuilder.getPlayers();

    // then
    BOOST_CHECK_EQUAL(
        players,
        gotPlayers
    );
}

BOOST_AUTO_TEST_CASE( TreeDataBuilder_getData ) {
    // given
    GT::IdentifierPtr  playerName = GT::createIdentifierPtr("p1"); 
    GT::IdentifierPtr  strategy1  = GT::createIdentifierPtr("p1s1"); 
    GT::IdentifierPtr  strategy2  = GT::createIdentifierPtr("p1s2");
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();
    strategies->push_back( strategy1 );
    strategies->push_back( strategy2 );
    GT::Model::PlayerPtr  player(new GT::Model::Player(playerName, strategies));
    GT::Model::PlayersPtr players(new GT::Model::Players());
    players->insert( GT::Model::Players::value_type(*playerName, player) );

    // when
    GT::Model::TreeDataBuilder treeDataBuilder;
    treeDataBuilder.setPlayers(players);

    // then
    BOOST_CHECK_NO_THROW(
        treeDataBuilder.getData()
    );
}

BOOST_AUTO_TEST_CASE( TreeDataBuilder_toString ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setIndentationMode(GT::Model::TABS)
        .setBuilderMode(GT::Model::PLAIN);

    GT::IdentifierPtr  playerName = GT::createIdentifierPtr("p1"); 
    GT::IdentifierPtr  strategy1  = GT::createIdentifierPtr("p1s1"); 
    GT::IdentifierPtr  strategy2  = GT::createIdentifierPtr("p1s2");
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();
    strategies->push_back( strategy1 );
    strategies->push_back( strategy2 );
    GT::Model::PlayerPtr  player(new GT::Model::Player(playerName, strategies));
    GT::Model::PlayersPtr players(new GT::Model::Players());
    players->insert( GT::Model::Players::value_type(*playerName, player) );
    
    GT::NumbersPtr params1 = GT::createNumbersPtr();
    params1->push_back( GT::createNumberPtr(10) );
    GT::NumbersPtr params2 = GT::createNumbersPtr();
    params2->push_back( GT::createNumberPtr(20) );
    
    GT::PositionsPtr positions1 = GT::createPositionsPtr();
    positions1->insert( GT::Positions::value_type(*playerName, *strategy1) );
    GT::PositionsPtr positions2 = GT::createPositionsPtr();
    positions2->insert( GT::Positions::value_type(*playerName, *strategy2) );

    // when
    GT::Model::TreeDataBuilder treeDataBuilder;
    treeDataBuilder.setPlayers(players);
    
    treeDataBuilder.clone()->addNextPositions(positions1).setParams(params1);
    treeDataBuilder.clone()->addNextPositions(positions2).setParams(params2);

    // then
    BOOST_CHECK_EQUAL(
        treeDataBuilder.toString(),
        GT::Message() +
        "Current Data:\n" +
        "\tTreeData:\n" +
        "\t\tp1s1:\n" +
        "\t\t\tValue:\n" +
        "\t\t\t\t10\n" +
        "\t\tp1s2:\n" +
        "\t\t\tValue:\n" +
        "\t\t\t\t20\n"
    );
}

BOOST_AUTO_TEST_CASE( TreeDataBuilder_functional ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setIndentationMode(GT::Model::TABS)
        .setBuilderMode(GT::Model::PLAIN);

    GT::IdentifierPtr  playerName = GT::createIdentifierPtr("p1"); 
    GT::IdentifierPtr  strategy1  = GT::createIdentifierPtr("p1s1"); 
    GT::IdentifierPtr  strategy2  = GT::createIdentifierPtr("p1s2");
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();
    strategies->push_back( strategy1 );
    strategies->push_back( strategy2 );
    GT::Model::PlayerPtr  player(new GT::Model::Player(playerName, strategies));
    GT::Model::PlayersPtr players(new GT::Model::Players());
    players->insert( GT::Model::Players::value_type(*playerName, player) );
    
    GT::NumbersPtr params1 = GT::createNumbersPtr();
    params1->push_back( GT::createNumberPtr(10) );
    GT::NumbersPtr params2 = GT::createNumbersPtr();
    params2->push_back( GT::createNumberPtr(20) );
    
    GT::PositionsPtr positions1 = GT::createPositionsPtr();
    positions1->insert( GT::Positions::value_type(*playerName, *strategy1) );
    GT::PositionsPtr positions2 = GT::createPositionsPtr();
    positions2->insert( GT::Positions::value_type(*playerName, *strategy2) );

    // when
    GT::Model::TreeDataBuilder treeDataBuilder;
    treeDataBuilder.setPlayers(players);
    
    treeDataBuilder.clone()->addNextPositions(positions1).addNextPositions(positions2).setParams(params1);
    treeDataBuilder.clone()->addNextPositions(positions2).addNextPositions(positions1).setParams(params2);

    GT::Model::DataPtr data = treeDataBuilder.getData();

    // then
    BOOST_CHECK_EQUAL(
        data->toString(),
        GT::Message() +
        "TreeData:\n" +
        "\tp1s1:\n" +
        "\t\tp1s2:\n" +
        "\t\t\tValue:\n" +
        "\t\t\t\t10\n" +
        "\tp1s2:\n" +
        "\t\tp1s1:\n" +
        "\t\t\tValue:\n" +
        "\t\t\t\t20\n"
    );
}

BOOST_AUTO_TEST_SUITE_END()
