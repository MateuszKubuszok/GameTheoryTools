#include "gt/model/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ExtensiveDataAccessor )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using boost::make_shared;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( ExtensiveDataAccesor_getRoot ) {
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

    GT::Model::PlayerPtr  player1 = make_shared<GT::Model::Player>(p1, strategies);
    GT::Model::PlayerPtr  player2 = make_shared<GT::Model::Player>(p2, strategies);
    GT::Model::PlayersPtr players = make_shared<GT::Model::Players>();
    players->insert( GT::Model::Players::value_type(*p1, player1) );
    players->insert( GT::Model::Players::value_type(*p2, player2) );

    GT::Model::ExtensiveDataPtr extensiveData = make_shared<GT::Model::ExtensiveData>(players);

    // when
    GT::Model::ExtensiveDataAccessor extensiveDataAccessor(extensiveData);
    GT::Model::ExtensiveDataNodePtr root = extensiveDataAccessor.getRoot();

    // then
    BOOST_REQUIRE( root );
    BOOST_CHECK( root->isLeaf() );
}

BOOST_AUTO_TEST_CASE( ExtensiveDataAccesor_getPlayers ) {
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

    GT::Model::PlayerPtr  player1 = make_shared<GT::Model::Player>(p1, strategies);
    GT::Model::PlayerPtr  player2 = make_shared<GT::Model::Player>(p2, strategies);
    GT::Model::PlayersPtr players = make_shared<GT::Model::Players>();
    players->insert( GT::Model::Players::value_type(*p1, player1) );
    players->insert( GT::Model::Players::value_type(*p2, player2) );

    GT::Model::ExtensiveDataPtr extensiveData = make_shared<GT::Model::ExtensiveData>(players);

    // when
    GT::Model::ExtensiveDataAccessor extensiveDataAccessor(extensiveData);
    GT::Model::PlayersPtr gotPlayers = extensiveDataAccessor.getPlayers();

    // then
    BOOST_CHECK_EQUAL(
        players,
        gotPlayers
    );
}

BOOST_AUTO_TEST_CASE( ExtensiveDataAccessor_functional ) {
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

    GT::Model::PlayerPtr  player1 = make_shared<GT::Model::Player>(p1, strategies);
    GT::Model::PlayerPtr  player2 = make_shared<GT::Model::Player>(p2, strategies);
    GT::Model::PlayersPtr players = make_shared<GT::Model::Players>();
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

    GT::Model::ExtensiveDataPtr extensiveData = make_shared<GT::Model::ExtensiveData>(players);

    extensiveData->setPlayerInTurn(plRoot, player1);
    extensiveData->setPlayerInTurn(pl11, player2);
    extensiveData->setPlayerInTurn(pl12, player2);

    extensiveData->setPayoffs( p11, payoff11 ).setPayoffs( p12, payoff12 )
                  .setPayoffs( p21, payoff21 ).setPayoffs( p22, payoff22 );

    // when
    GT::Model::ExtensiveDataAccessor extensiveDataAccessor(extensiveData);
    GT::Model::DataPiecePtr got11 = extensiveDataAccessor.getPayoffs(p11);
    GT::Model::DataPiecePtr got12 = extensiveDataAccessor.getPayoffs(p12);
    GT::Model::DataPiecePtr got21 = extensiveDataAccessor.getPayoffs(p21);
    GT::Model::DataPiecePtr got22 = extensiveDataAccessor.getPayoffs(p22);

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

BOOST_AUTO_TEST_CASE( ExtensiveDataAccessor_operatorOverload ) {
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

    GT::Model::PlayerPtr  player1 = make_shared<GT::Model::Player>(p1, strategies);
    GT::Model::PlayerPtr  player2 = make_shared<GT::Model::Player>(p2, strategies);
    GT::Model::PlayersPtr players = make_shared<GT::Model::Players>();
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

    GT::Model::ExtensiveDataPtr extensiveData = make_shared<GT::Model::ExtensiveData>(players);

    extensiveData->setPlayerInTurn(plRoot, player1);
    extensiveData->setPlayerInTurn(pl11, player2);
    extensiveData->setPlayerInTurn(pl12, player2);

    extensiveData->setPayoffs( p11, payoff11 ).setPayoffs( p12, payoff12 )
                  .setPayoffs( p21, payoff21 ).setPayoffs( p22, payoff22 );

    // when
    GT::Model::ExtensiveDataAccessor extensiveDataAccessor(extensiveData);
    GT::Model::DataPiecePtr got11 = extensiveDataAccessor[p11];
    GT::Model::DataPiecePtr got12 = extensiveDataAccessor[p12];
    GT::Model::DataPiecePtr got21 = extensiveDataAccessor[p21];
    GT::Model::DataPiecePtr got22 = extensiveDataAccessor[p22];

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

BOOST_AUTO_TEST_CASE( ExtensiveDataAccessor_throwExceptionOnInvalidCoordinate ) {
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

    GT::Model::PlayerPtr  player1 = make_shared<GT::Model::Player>(p1, strategies);
    GT::Model::PlayerPtr  player2 = make_shared<GT::Model::Player>(p2, strategies);
    GT::Model::PlayersPtr players = make_shared<GT::Model::Players>();
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

    GT::Model::ExtensiveDataPtr extensiveData = make_shared<GT::Model::ExtensiveData>(players);

    extensiveData->setPlayerInTurn(plRoot, player1);
    extensiveData->setPlayerInTurn(pl11, player2);
    extensiveData->setPlayerInTurn(pl12, player2);

    extensiveData->setPayoffs( p11, payoff11 ).setPayoffs( p12, payoff12 )
                  .setPayoffs( p21, payoff21 ).setPayoffs( p22, payoff22 );

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
    GT::Model::ExtensiveDataAccessor extensiveDataAccessor(extensiveData);

    // then
    BOOST_CHECK_THROW(
        extensiveDataAccessor.getPayoffs(pos1),
        GT::Model::InvalidCoordinate
    );
    BOOST_CHECK_THROW(
        extensiveDataAccessor.getPayoffs(pos2),
        GT::Model::InvalidCoordinate
    );
    BOOST_CHECK_THROW(
        extensiveDataAccessor.getPayoffs(pos3),
        GT::Model::InvalidCoordinate
    );
}

BOOST_AUTO_TEST_CASE( ExtensiveDataAccessor_toString ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::IdentifierPtr p1 = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr p2 = GT::createIdentifierPtr("p2");
    GT::IdentifierPtr s1 = GT::createIdentifierPtr("s1");
    GT::IdentifierPtr s2 = GT::createIdentifierPtr("s2");
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();
    strategies->push_back(s1);
    strategies->push_back(s2);

    GT::Identifier l1 = GT::createIdentifier("1");
    GT::Identifier l2 = GT::createIdentifier("2");

    GT::Model::PlayerPtr  player1 = make_shared<GT::Model::Player>(p1, strategies);
    GT::Model::PlayerPtr  player2 = make_shared<GT::Model::Player>(p2, strategies);
    GT::Model::PlayersPtr players = make_shared<GT::Model::Players>();
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

    GT::Model::ExtensiveDataPtr extensiveData = make_shared<GT::Model::ExtensiveData>(players);

    extensiveData->setPlayerInTurn(plRoot, player1);
    extensiveData->setPlayerInTurn(pl11, player2);
    extensiveData->setPlayerInTurn(pl12, player2);

    extensiveData->setPayoffs( p11, payoff11 ).setPayoffs( p12, payoff12 )
                  .setPayoffs( p21, payoff21 ).setPayoffs( p22, payoff22 );

    // when
    GT::Model::ExtensiveDataAccessor extensiveDataAccessor(extensiveData);

    // then
    BOOST_CHECK_EQUAL(
        extensiveDataAccessor.toString(),
        GT::Message() +
        "Extensive Data Accessor:\n"
        "\tExtensiveData:\n"
        "\t\tPlayer:\n"
        "\t\t\tName:\n"
        "\t\t\t\tp1\n"
        "\t\t\t1:\n"
        "\t\t\t\ts1\n"
        "\t\t\t2:\n"
        "\t\t\t\ts2\n"
        "\t\ts1:\n"
        "\t\t\tPlayer:\n"
        "\t\t\t\tName:\n"
        "\t\t\t\t\tp2\n"
        "\t\t\t\t1:\n"
        "\t\t\t\t\ts1\n"
        "\t\t\t\t2:\n"
        "\t\t\t\t\ts2\n"
        "\t\t\ts1:\n"
        "\t\t\t\tValue:\n"
        "\t\t\t\t\t10.00000\n"
        "\t\t\t\tValue:\n"
        "\t\t\t\t\t20.00000\n"
        "\t\t\ts2:\n"
        "\t\t\t\tValue:\n"
        "\t\t\t\t\t30.00000\n"
        "\t\t\t\tValue:\n"
        "\t\t\t\t\t40.00000\n"
        "\t\ts2:\n"
        "\t\t\tPlayer:\n"
        "\t\t\t\tName:\n"
        "\t\t\t\t\tp2\n"
        "\t\t\t\t1:\n"
        "\t\t\t\t\ts1\n"
        "\t\t\t\t2:\n"
        "\t\t\t\t\ts2\n"
        "\t\t\ts1:\n"
        "\t\t\t\tValue:\n"
        "\t\t\t\t\t50.00000\n"
        "\t\t\t\tValue:\n"
        "\t\t\t\t\t60.00000\n"
        "\t\t\ts2:\n"
        "\t\t\t\tValue:\n"
        "\t\t\t\t\t70.00000\n"
        "\t\t\t\tValue:\n"
        "\t\t\t\t\t80.00000\n"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
