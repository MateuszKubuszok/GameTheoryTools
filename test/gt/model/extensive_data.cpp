#include "gt/model/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ExtensiveData )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( ExtensiveData_getRoot ) {
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
    GT::Model::ExtensiveData extensiveData(players);
    GT::Model::ExtensiveDataNodePtr root = extensiveData.getRoot();

    // then
    BOOST_REQUIRE( root );
    BOOST_CHECK( root->isLeaf() );
}

BOOST_AUTO_TEST_CASE( ExtensiveData_getPlayers ) {
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
    GT::Model::ExtensiveData extensiveData(players);
    GT::Model::PlayersPtr gotPlayers = extensiveData.getPlayers();

    // then
    BOOST_CHECK_EQUAL(
        players,
        gotPlayers
    );
}

BOOST_AUTO_TEST_CASE( ExtensiveData_functional ) {
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

    GT::Positions plRoot = GT::createPositions();
    GT::Positions pl11 = GT::createPositions();
    pl11.insert( GT::Positions::value_type(l1, *s1) );
    GT::Positions pl12 = GT::createPositions();
    pl12.insert( GT::Positions::value_type(l1, *s2) );

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
    GT::Model::ExtensiveData extensiveData(players);

    extensiveData.setPlayerInTurn(plRoot, player1);
    extensiveData.setPlayerInTurn(pl11, player2);
    extensiveData.setPlayerInTurn(pl12, player2);

    extensiveData.setPayoffs( p11, payoff11 ).setPayoffs( p12, payoff12 )
                 .setPayoffs( p21, payoff21 ).setPayoffs( p22, payoff22 );

    GT::Model::DataPiecePtr got11 = extensiveData.getPayoffs(p11);
    GT::Model::DataPiecePtr got12 = extensiveData.getPayoffs(p12);
    GT::Model::DataPiecePtr got21 = extensiveData.getPayoffs(p21);
    GT::Model::DataPiecePtr got22 = extensiveData.getPayoffs(p22);

    // then
    BOOST_CHECK_EQUAL(*got11->getPayoff(p1), *(*payoff11)[0]);
    BOOST_CHECK_EQUAL(*got11->getPayoff(p2), *(*payoff11)[1]);

    BOOST_CHECK_EQUAL(*got12->getPayoff(p1), *(*payoff12)[0]);
    BOOST_CHECK_EQUAL(*got12->getPayoff(p2), *(*payoff12)[1]);

    BOOST_CHECK_EQUAL(*got21->getPayoff(p1), *(*payoff21)[0]);
    BOOST_CHECK_EQUAL(*got21->getPayoff(p2), *(*payoff21)[1]);

    BOOST_CHECK_EQUAL(*got22->getPayoff(p1), *(*payoff22)[0]);
    BOOST_CHECK_EQUAL(*got22->getPayoff(p2), *(*payoff22)[1]);
}

BOOST_AUTO_TEST_CASE( ExtensiveData_operatorOverload ) {
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

    GT::Positions plRoot = GT::createPositions();
    GT::Positions pl11 = GT::createPositions();
    pl11.insert( GT::Positions::value_type(l1, *s1) );
    GT::Positions pl12 = GT::createPositions();
    pl12.insert( GT::Positions::value_type(l1, *s2) );

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
    GT::Model::ExtensiveData extensiveData(players);

    extensiveData.setPlayerInTurn(plRoot, player1);
    extensiveData.setPlayerInTurn(pl11, player2);
    extensiveData.setPlayerInTurn(pl12, player2);

    extensiveData.setPayoffs( p11, payoff11 ).setPayoffs( p12, payoff12 )
            .setPayoffs( p21, payoff21 ).setPayoffs( p22, payoff22 );
    GT::Model::DataPiecePtr got11 = extensiveData[p11];
    GT::Model::DataPiecePtr got12 = extensiveData[p12];
    GT::Model::DataPiecePtr got21 = extensiveData[p21];
    GT::Model::DataPiecePtr got22 = extensiveData[p22];

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

BOOST_AUTO_TEST_CASE( ExtensiveData_throwExceptionOnInvalidCoordinate ) {
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

    GT::Positions plRoot = GT::createPositions();
    GT::Positions pl11 = GT::createPositions();
    pl11.insert( GT::Positions::value_type(l1, *s1) );
    GT::Positions pl12 = GT::createPositions();
    pl12.insert( GT::Positions::value_type(l1, *s2) );

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
    GT::Model::ExtensiveData extensiveData(players);

    extensiveData.setPlayerInTurn(plRoot, player1);
    extensiveData.setPlayerInTurn(pl11, player2);
    extensiveData.setPlayerInTurn(pl12, player2);

    // then
    BOOST_CHECK_THROW(
        extensiveData.setPayoffs(pos1, payoff),
        GT::Model::InvalidCoordinate
    );
    BOOST_CHECK_THROW(
        extensiveData.setPayoffs(pos2, payoff),
        GT::Model::InvalidCoordinate
    );
    BOOST_CHECK_THROW(
        extensiveData.setPayoffs(pos3, payoff),
        GT::Model::InvalidCoordinate
    );
}

BOOST_AUTO_TEST_CASE( ExtensiveData_toString ) {
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

    GT::Positions plRoot = GT::createPositions();
    GT::Positions pl11 = GT::createPositions();
    pl11.insert( GT::Positions::value_type(l1, *s1) );
    GT::Positions pl12 = GT::createPositions();
    pl12.insert( GT::Positions::value_type(l1, *s2) );

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
    GT::Model::ExtensiveData extensiveData(players);

    extensiveData.setPlayerInTurn(plRoot, player1);
    extensiveData.setPlayerInTurn(pl11, player2);
    extensiveData.setPlayerInTurn(pl12, player2);

    extensiveData.setPayoffs( p11, payoff11 ).setPayoffs( p12, payoff12 )
            .setPayoffs( p21, payoff21 ).setPayoffs( p22, payoff22 );
    GT::Model::DataPiecePtr got11 = extensiveData.getPayoffs(p11);
    GT::Model::DataPiecePtr got12 = extensiveData.getPayoffs(p12);
    GT::Model::DataPiecePtr got21 = extensiveData.getPayoffs(p21);
    GT::Model::DataPiecePtr got22 = extensiveData.getPayoffs(p22);

    // then
    BOOST_CHECK_EQUAL(
        extensiveData.toString(),
        GT::Message() +
        "ExtensiveData:\n"
        "\tPlayer:\n"
        "\t\tName:\n"
        "\t\t\tp1\n"
        "\t\t0:\n"
        "\t\t\ts1\n"
        "\t\t1:\n"
        "\t\t\ts2\n"
        "\ts1:\n"
        "\t\tPlayer:\n"
        "\t\t\tName:\n"
        "\t\t\t\tp2\n"
        "\t\t\t0:\n"
        "\t\t\t\ts1\n"
        "\t\t\t1:\n"
        "\t\t\t\ts2\n"
        "\t\ts1:\n"
        "\t\t\tValue:\n"
        "\t\t\t\t10\n"
        "\t\t\tValue:\n"
        "\t\t\t\t20\n"
        "\t\ts2:\n"
        "\t\t\tValue:\n"
        "\t\t\t\t30\n"
        "\t\t\tValue:\n"
        "\t\t\t\t40\n"
        "\ts2:\n"
        "\t\tPlayer:\n"
        "\t\t\tName:\n"
        "\t\t\t\tp2\n"
        "\t\t\t0:\n"
        "\t\t\t\ts1\n"
        "\t\t\t1:\n"
        "\t\t\t\ts2\n"
        "\t\ts1:\n"
        "\t\t\tValue:\n"
        "\t\t\t\t50\n"
        "\t\t\tValue:\n"
        "\t\t\t\t60\n"
        "\t\ts2:\n"
        "\t\t\tValue:\n"
        "\t\t\t\t70\n"
        "\t\t\tValue:\n"
        "\t\t\t\t80\n"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
