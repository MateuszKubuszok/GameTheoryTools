#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>

#include "gt/model/inner_common.hpp"

BOOST_AUTO_TEST_SUITE( TreeData )

BOOST_AUTO_TEST_CASE( TreeData_getPlayers ) {
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

    // when
    GT::Model::TreeData treeData(players);
    GT::Model::PlayersPtr gotPlayers = treeData.getPlayers();

    // then
    BOOST_CHECK_EQUAL(
        players,
        gotPlayers
    );
}

BOOST_AUTO_TEST_CASE( TreeData_functional ) {
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

    // when
    GT::Model::TreeData treeData(players);
    treeData.getPlayersInTurns()->insert( GT::Model::PlayersInTurns::value_type("1", player1) );
    treeData.getPlayersInTurns()->insert( GT::Model::PlayersInTurns::value_type("2", player2) );
    treeData.setValues( p11, payoff11 ).setValues( p12, payoff12 )
            .setValues( p21, payoff21 ).setValues( p22, payoff22 );
    GT::Model::DataPiecePtr got11 = treeData.getValues(p11);
    GT::Model::DataPiecePtr got12 = treeData.getValues(p12);
    GT::Model::DataPiecePtr got21 = treeData.getValues(p21);
    GT::Model::DataPiecePtr got22 = treeData.getValues(p22);

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

BOOST_AUTO_TEST_CASE( TreeData_operatorOverload ) {
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

    // when
    GT::Model::TreeData treeData(players);
    treeData.getPlayersInTurns()->insert( GT::Model::PlayersInTurns::value_type("1", player1) );
    treeData.getPlayersInTurns()->insert( GT::Model::PlayersInTurns::value_type("2", player2) );
    treeData.setValues( p11, payoff11 ).setValues( p12, payoff12 )
            .setValues( p21, payoff21 ).setValues( p22, payoff22 );
    GT::Model::DataPiecePtr got11 = treeData[p11];
    GT::Model::DataPiecePtr got12 = treeData[p12];
    GT::Model::DataPiecePtr got21 = treeData[p21];
    GT::Model::DataPiecePtr got22 = treeData[p22];

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

BOOST_AUTO_TEST_CASE( StrategicData_throwExceptionOnInvalidCoordinate ) {
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

    GT::Positions pos1 = GT::createPositions();
    pos1.insert( GT::Positions::value_type(*p1, *s1) );
    pos1.insert( GT::Positions::value_type(l2, *s1) );
    GT::Positions pos2 = GT::createPositions();
    pos2.insert( GT::Positions::value_type(l1, *s1) );
    pos2.insert( GT::Positions::value_type(*p2, *s2) );
    GT::Positions pos3 = GT::createPositions();
    pos3.insert( GT::Positions::value_type(l1, *s2) );
    pos3.insert( GT::Positions::value_type(l2, *p2) );

    GT::NumbersPtr payoff = GT::createNumbersPtr();

    // when
    GT::Model::TreeData treeData(players);
    treeData.getPlayersInTurns()->insert( GT::Model::PlayersInTurns::value_type("1", player1) );
    treeData.getPlayersInTurns()->insert( GT::Model::PlayersInTurns::value_type("2", player2) );

    // then
    BOOST_CHECK_THROW(
        treeData.setValues(pos1, payoff),
        GT::Model::InvalidCoordinate
    );
    BOOST_CHECK_THROW(
        treeData.setValues(pos2, payoff),
        GT::Model::InvalidCoordinate
    );
    BOOST_CHECK_THROW(
        treeData.setValues(pos3, payoff),
        GT::Model::InvalidCoordinate
    );
}

BOOST_AUTO_TEST_CASE( TreeData_toString ) {
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

    // when
    GT::Model::TreeData treeData(players);
    treeData.getPlayersInTurns()->insert( GT::Model::PlayersInTurns::value_type("1", player1) );
    treeData.getPlayersInTurns()->insert( GT::Model::PlayersInTurns::value_type("2", player2) );
    treeData.setValues( p11, payoff11 ).setValues( p12, payoff12 )
            .setValues( p21, payoff21 ).setValues( p22, payoff22 );
    GT::Model::DataPiecePtr got11 = treeData.getValues(p11);
    GT::Model::DataPiecePtr got12 = treeData.getValues(p12);
    GT::Model::DataPiecePtr got21 = treeData.getValues(p21);
    GT::Model::DataPiecePtr got22 = treeData.getValues(p22);

    // then
    BOOST_CHECK_EQUAL(
        treeData.toString(),
        GT::Message() +
        "TreeData:\n" +
        "\ts1:\n" +
        "\t\ts1:\n" +
        "\t\t\tValue:\n" +
        "\t\t\t\t10\n" +
        "\t\t\tValue:\n" +
        "\t\t\t\t20\n"
        "\t\ts2:\n" +
        "\t\t\tValue:\n" +
        "\t\t\t\t30\n" +
        "\t\t\tValue:\n" +
        "\t\t\t\t40\n" +
        "\ts2:\n" +
        "\t\ts1:\n" +
        "\t\t\tValue:\n" +
        "\t\t\t\t50\n" +
        "\t\t\tValue:\n" +
        "\t\t\t\t60\n"
        "\t\ts2:\n" +
        "\t\t\tValue:\n" +
        "\t\t\t\t70\n" +
        "\t\t\tValue:\n" +
        "\t\t\t\t80\n"
    );
}

BOOST_AUTO_TEST_SUITE_END()
