#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>

#include "gt/model/inner_common.hpp"

BOOST_AUTO_TEST_SUITE( TreeDataAccessor )

BOOST_AUTO_TEST_CASE( TreeDataAccesor_getPlayers ) {
    // given
    GT::IdentifierPtr p1 = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr p2 = GT::createIdentifierPtr("p2");
    GT::IdentifierPtr s1 = GT::createIdentifierPtr("s1");
    GT::IdentifierPtr s2 = GT::createIdentifierPtr("s2");
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();
    strategies->push_back(s1);
    strategies->push_back(s2);

    GT::Identifier l1 = GT::createIdentifier("1");
    GT::Identifier l2 = GT::createIdentifier("2");

    GT::Model::PlayerPtr  player1(new GT::Model::Player(p1, strategies));
    GT::Model::PlayerPtr  player2(new GT::Model::Player(p2, strategies));
    GT::Model::PlayersPtr players(new GT::Model::Players());
    players->insert( GT::Model::Players::value_type(*p1, player1) );
    players->insert( GT::Model::Players::value_type(*p2, player2) );

    GT::Model::TreeDataPtr treeData(new GT::Model::TreeData(players));

    // when
    GT::Model::TreeDataAccessor treeDataAccessor(treeData);
    GT::Model::PlayersPtr gotPlayers = treeDataAccessor.getPlayers();

    // then
    BOOST_CHECK_EQUAL(
        players,
        gotPlayers
    );
}

BOOST_AUTO_TEST_CASE( TreeDataAccessor_functional ) {
    // given
    GT::IdentifierPtr p1 = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr p2 = GT::createIdentifierPtr("p2");
    GT::IdentifierPtr s1 = GT::createIdentifierPtr("s1");
    GT::IdentifierPtr s2 = GT::createIdentifierPtr("s2");
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();
    strategies->push_back(s1);
    strategies->push_back(s2);

    GT::Identifier l1 = GT::createIdentifier("1");
    GT::Identifier l2 = GT::createIdentifier("2");

    GT::Model::PlayerPtr  player1(new GT::Model::Player(p1, strategies));
    GT::Model::PlayerPtr  player2(new GT::Model::Player(p2, strategies));
    GT::Model::PlayersPtr players(new GT::Model::Players());
    players->insert( GT::Model::Players::value_type(*p1, player1) );
    players->insert( GT::Model::Players::value_type(*p2, player2) );

    GT::Positions p11 = GT::createPositions();
    p11.insert( GT::Positions::value_type(l1, *s1) );
    p11.insert( GT::Positions::value_type(l2, *s1) );
    GT::Positions p12 = GT::createPositions();
    p12.insert( GT::Positions::value_type(l1, *s1) );
    p12.insert( GT::Positions::value_type(l2, *s2) );
    GT::Positions p21 = GT::createPositions();
    p21.insert( GT::Positions::value_type(l1, *s2) );
    p21.insert( GT::Positions::value_type(l2, *s1) );
    GT::Positions p22 = GT::createPositions();
    p22.insert( GT::Positions::value_type(l1, *s2) );
    p22.insert( GT::Positions::value_type(l2, *s2) );

    GT::NumbersPtr payoff11 = GT::createNumbersPtr();
    payoff11->push_back(GT::createNumberPtr(10));
    payoff11->push_back(GT::createNumberPtr(20));
    GT::NumbersPtr payoff12 = GT::createNumbersPtr();
    payoff12->push_back(GT::createNumberPtr(30));
    payoff12->push_back(GT::createNumberPtr(40));
    GT::NumbersPtr payoff21 = GT::createNumbersPtr();
    payoff21->push_back(GT::createNumberPtr(50));
    payoff21->push_back(GT::createNumberPtr(60));
    GT::NumbersPtr payoff22 = GT::createNumbersPtr();
    payoff22->push_back(GT::createNumberPtr(70));
    payoff22->push_back(GT::createNumberPtr(80));

    GT::Model::TreeDataPtr treeData(new GT::Model::TreeData(players));
    treeData->getPlayersInTurns()->insert( GT::Model::PlayersInTurns::value_type("1", player1) );
    treeData->getPlayersInTurns()->insert( GT::Model::PlayersInTurns::value_type("2", player2) );
    treeData->setValues( p11, payoff11 ).setValues( p12, payoff12 )
             .setValues( p21, payoff21 ).setValues( p22, payoff22 );

    // when
    GT::Model::TreeDataAccessor treeDataAccessor(treeData);
    GT::Model::DataPiecePtr got11 = treeDataAccessor.getValues(p11);
    GT::Model::DataPiecePtr got12 = treeDataAccessor.getValues(p12);
    GT::Model::DataPiecePtr got21 = treeDataAccessor.getValues(p21);
    GT::Model::DataPiecePtr got22 = treeDataAccessor.getValues(p22);

    // then
    BOOST_CHECK_EQUAL(*got11->getValue(p1), *(*payoff11)[0]);
    BOOST_CHECK_EQUAL(*got11->getValue(p2), *(*payoff11)[1]);

    BOOST_CHECK_EQUAL(*got12->getValue(p1), *(*payoff12)[0]);
    BOOST_CHECK_EQUAL(*got12->getValue(p2), *(*payoff12)[1]);

    BOOST_CHECK_EQUAL(*got21->getValue(p1), *(*payoff21)[0]);
    BOOST_CHECK_EQUAL(*got21->getValue(p2), *(*payoff21)[1]);

    BOOST_CHECK_EQUAL(*got22->getValue(p1), *(*payoff22)[0]);
    BOOST_CHECK_EQUAL(*got22->getValue(p2), *(*payoff22)[1]);
}

BOOST_AUTO_TEST_CASE( TreeDataAccessor_operatorOverload ) {
    // given
    GT::IdentifierPtr p1 = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr p2 = GT::createIdentifierPtr("p2");
    GT::IdentifierPtr s1 = GT::createIdentifierPtr("s1");
    GT::IdentifierPtr s2 = GT::createIdentifierPtr("s2");
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();
    strategies->push_back(s1);
    strategies->push_back(s2);

    GT::Identifier l1 = GT::createIdentifier("1");
    GT::Identifier l2 = GT::createIdentifier("2");

    GT::Model::PlayerPtr  player1(new GT::Model::Player(p1, strategies));
    GT::Model::PlayerPtr  player2(new GT::Model::Player(p2, strategies));
    GT::Model::PlayersPtr players(new GT::Model::Players());
    players->insert( GT::Model::Players::value_type(*p1, player1) );
    players->insert( GT::Model::Players::value_type(*p2, player2) );

    GT::Positions p11 = GT::createPositions();
    p11.insert( GT::Positions::value_type(l1, *s1) );
    p11.insert( GT::Positions::value_type(l2, *s1) );
    GT::Positions p12 = GT::createPositions();
    p12.insert( GT::Positions::value_type(l1, *s1) );
    p12.insert( GT::Positions::value_type(l2, *s2) );
    GT::Positions p21 = GT::createPositions();
    p21.insert( GT::Positions::value_type(l1, *s2) );
    p21.insert( GT::Positions::value_type(l2, *s1) );
    GT::Positions p22 = GT::createPositions();
    p22.insert( GT::Positions::value_type(l1, *s2) );
    p22.insert( GT::Positions::value_type(l2, *s2) );

    GT::NumbersPtr payoff11 = GT::createNumbersPtr();
    payoff11->push_back(GT::createNumberPtr(10));
    payoff11->push_back(GT::createNumberPtr(20));
    GT::NumbersPtr payoff12 = GT::createNumbersPtr();
    payoff12->push_back(GT::createNumberPtr(30));
    payoff12->push_back(GT::createNumberPtr(40));
    GT::NumbersPtr payoff21 = GT::createNumbersPtr();
    payoff21->push_back(GT::createNumberPtr(50));
    payoff21->push_back(GT::createNumberPtr(60));
    GT::NumbersPtr payoff22 = GT::createNumbersPtr();
    payoff22->push_back(GT::createNumberPtr(70));
    payoff22->push_back(GT::createNumberPtr(80));

    GT::Model::TreeDataPtr treeData(new GT::Model::TreeData(players));
    treeData->getPlayersInTurns()->insert( GT::Model::PlayersInTurns::value_type("1", player1) );
    treeData->getPlayersInTurns()->insert( GT::Model::PlayersInTurns::value_type("2", player2) );
    treeData->setValues( p11, payoff11 ).setValues( p12, payoff12 )
             .setValues( p21, payoff21 ).setValues( p22, payoff22 );
    
    // when
    GT::Model::TreeDataAccessor treeDataAccessor(treeData);
    GT::Model::DataPiecePtr got11 = treeDataAccessor[p11];
    GT::Model::DataPiecePtr got12 = treeDataAccessor[p12];
    GT::Model::DataPiecePtr got21 = treeDataAccessor[p21];
    GT::Model::DataPiecePtr got22 = treeDataAccessor[p22];

    // then
    BOOST_CHECK_EQUAL(*(*got11)[p1], *(*payoff11)[0]);
    BOOST_CHECK_EQUAL(*(*got11)[p2], *(*payoff11)[1]);

    BOOST_CHECK_EQUAL(*(*got12)[p1], *(*payoff12)[0]);
    BOOST_CHECK_EQUAL(*(*got12)[p2], *(*payoff12)[1]);

    BOOST_CHECK_EQUAL(*(*got21)[p1], *(*payoff21)[0]);
    BOOST_CHECK_EQUAL(*(*got21)[p2], *(*payoff21)[1]);

    BOOST_CHECK_EQUAL(*(*got22)[p1], *(*payoff22)[0]);
    BOOST_CHECK_EQUAL(*(*got22)[p2], *(*payoff22)[1]);
}

BOOST_AUTO_TEST_CASE( TreeDataAccessor_throwExceptionOnInvalidCoordinate ) {
        // given
    GT::IdentifierPtr p1 = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr p2 = GT::createIdentifierPtr("p2");
    GT::IdentifierPtr s1 = GT::createIdentifierPtr("s1");
    GT::IdentifierPtr s2 = GT::createIdentifierPtr("s2");
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();
    strategies->push_back(s1);
    strategies->push_back(s2);

    GT::Identifier l1 = GT::createIdentifier("1");
    GT::Identifier l2 = GT::createIdentifier("2");

    GT::Model::PlayerPtr  player1(new GT::Model::Player(p1, strategies));
    GT::Model::PlayerPtr  player2(new GT::Model::Player(p2, strategies));
    GT::Model::PlayersPtr players(new GT::Model::Players());
    players->insert( GT::Model::Players::value_type(*p1, player1) );
    players->insert( GT::Model::Players::value_type(*p2, player2) );

    GT::Positions p11 = GT::createPositions();
    p11.insert( GT::Positions::value_type(l1, *s1) );
    p11.insert( GT::Positions::value_type(l2, *s1) );
    GT::Positions p12 = GT::createPositions();
    p12.insert( GT::Positions::value_type(l1, *s1) );
    p12.insert( GT::Positions::value_type(l2, *s2) );
    GT::Positions p21 = GT::createPositions();
    p21.insert( GT::Positions::value_type(l1, *s2) );
    p21.insert( GT::Positions::value_type(l2, *s1) );
    GT::Positions p22 = GT::createPositions();
    p22.insert( GT::Positions::value_type(l1, *s2) );
    p22.insert( GT::Positions::value_type(l2, *s2) );

    GT::NumbersPtr payoff11 = GT::createNumbersPtr();
    payoff11->push_back(GT::createNumberPtr(10));
    payoff11->push_back(GT::createNumberPtr(20));
    GT::NumbersPtr payoff12 = GT::createNumbersPtr();
    payoff12->push_back(GT::createNumberPtr(30));
    payoff12->push_back(GT::createNumberPtr(40));
    GT::NumbersPtr payoff21 = GT::createNumbersPtr();
    payoff21->push_back(GT::createNumberPtr(50));
    payoff21->push_back(GT::createNumberPtr(60));
    GT::NumbersPtr payoff22 = GT::createNumbersPtr();
    payoff22->push_back(GT::createNumberPtr(70));
    payoff22->push_back(GT::createNumberPtr(80));

    GT::Model::TreeDataPtr treeData(new GT::Model::TreeData(players));
    treeData->getPlayersInTurns()->insert( GT::Model::PlayersInTurns::value_type("1", player1) );
    treeData->getPlayersInTurns()->insert( GT::Model::PlayersInTurns::value_type("2", player2) );
    treeData->setValues( p11, payoff11 ).setValues( p12, payoff12 )
             .setValues( p21, payoff21 ).setValues( p22, payoff22 );

    GT::Positions pos1 = GT::createPositions();
    pos1.insert( GT::Positions::value_type(*p1, *s1) );
    pos1.insert( GT::Positions::value_type(l2, *s1) );
    GT::Positions pos2 = GT::createPositions();
    pos2.insert( GT::Positions::value_type(l1, *s1) );
    pos2.insert( GT::Positions::value_type(*p2, *s2) );
    GT::Positions pos3 = GT::createPositions();
    pos3.insert( GT::Positions::value_type(l1, *s2) );
    pos3.insert( GT::Positions::value_type(l2, *p2) );
    
    // when
    GT::Model::TreeDataAccessor treeDataAccessor(treeData);

    // then
    BOOST_CHECK_THROW(
        treeDataAccessor.getValues(pos1),
        GT::Model::InvalidCoordinate
    );
    BOOST_CHECK_THROW(
        treeDataAccessor.getValues(pos2),
        GT::Model::InvalidCoordinate
    );
    BOOST_CHECK_THROW(
        treeDataAccessor.getValues(pos3),
        GT::Model::InvalidCoordinate
    );
}

BOOST_AUTO_TEST_CASE( TreeDataAccessor_toString ) {
    // given
    GT::IdentifierPtr p1 = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr p2 = GT::createIdentifierPtr("p2");
    GT::IdentifierPtr s1 = GT::createIdentifierPtr("s1");
    GT::IdentifierPtr s2 = GT::createIdentifierPtr("s2");
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();
    strategies->push_back(s1);
    strategies->push_back(s2);

    GT::Identifier l1 = GT::createIdentifier("1");
    GT::Identifier l2 = GT::createIdentifier("2");

    GT::Model::PlayerPtr  player1(new GT::Model::Player(p1, strategies));
    GT::Model::PlayerPtr  player2(new GT::Model::Player(p2, strategies));
    GT::Model::PlayersPtr players(new GT::Model::Players());
    players->insert( GT::Model::Players::value_type(*p1, player1) );
    players->insert( GT::Model::Players::value_type(*p2, player2) );

    GT::Positions p11 = GT::createPositions();
    p11.insert( GT::Positions::value_type(l1, *s1) );
    p11.insert( GT::Positions::value_type(l2, *s1) );
    GT::Positions p12 = GT::createPositions();
    p12.insert( GT::Positions::value_type(l1, *s1) );
    p12.insert( GT::Positions::value_type(l2, *s2) );
    GT::Positions p21 = GT::createPositions();
    p21.insert( GT::Positions::value_type(l1, *s2) );
    p21.insert( GT::Positions::value_type(l2, *s1) );
    GT::Positions p22 = GT::createPositions();
    p22.insert( GT::Positions::value_type(l1, *s2) );
    p22.insert( GT::Positions::value_type(l2, *s2) );

    GT::NumbersPtr payoff11 = GT::createNumbersPtr();
    payoff11->push_back(GT::createNumberPtr(10));
    payoff11->push_back(GT::createNumberPtr(20));
    GT::NumbersPtr payoff12 = GT::createNumbersPtr();
    payoff12->push_back(GT::createNumberPtr(30));
    payoff12->push_back(GT::createNumberPtr(40));
    GT::NumbersPtr payoff21 = GT::createNumbersPtr();
    payoff21->push_back(GT::createNumberPtr(50));
    payoff21->push_back(GT::createNumberPtr(60));
    GT::NumbersPtr payoff22 = GT::createNumbersPtr();
    payoff22->push_back(GT::createNumberPtr(70));
    payoff22->push_back(GT::createNumberPtr(80));

    GT::Model::TreeDataPtr treeData(new GT::Model::TreeData(players));
    treeData->getPlayersInTurns()->insert( GT::Model::PlayersInTurns::value_type("1", player1) );
    treeData->getPlayersInTurns()->insert( GT::Model::PlayersInTurns::value_type("2", player2) );
    treeData->setValues( p11, payoff11 ).setValues( p12, payoff12 )
             .setValues( p21, payoff21 ).setValues( p22, payoff22 );
    
    // when
    GT::Model::TreeDataAccessor treeDataAccessor(treeData);

    // then
    BOOST_CHECK_EQUAL(
        treeDataAccessor.toString(),
        GT::Message() +
        "Tree Data Accessor:\n" +
        "\tTreeData:\n" +
        "\t\ts1:\n" +
        "\t\t\ts1:\n" +
        "\t\t\t\tValue:\n" +
        "\t\t\t\t\t10\n" +
        "\t\t\t\tValue:\n" +
        "\t\t\t\t\t20\n"
        "\t\t\ts2:\n" +
        "\t\t\t\tValue:\n" +
        "\t\t\t\t\t30\n" +
        "\t\t\t\tValue:\n" +
        "\t\t\t\t\t40\n" +
        "\t\ts2:\n" +
        "\t\t\ts1:\n" +
        "\t\t\t\tValue:\n" +
        "\t\t\t\t\t50\n" +
        "\t\t\t\tValue:\n" +
        "\t\t\t\t\t60\n"
        "\t\t\ts2:\n" +
        "\t\t\t\tValue:\n" +
        "\t\t\t\t\t70\n" +
        "\t\t\t\tValue:\n" +
        "\t\t\t\t\t80\n"
    );
}

BOOST_AUTO_TEST_SUITE_END()
