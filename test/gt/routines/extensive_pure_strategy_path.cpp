#include "gt/routines/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ExtensivePureStrategyPath )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( ExtensivePureStrategyPath_setPayoff_getPayoff ) {
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

    GT::NumbersPtr payoff = GT::createNumbersPtr();
    payoff->push_back( GT::createNumberPtr(10) );
    payoff->push_back( GT::createNumberPtr(20) );

    GT::Model::DataPiecePtr dataPiece(new GT::Model::PlainDataPiece(players, payoff));

    // when
    GT::Routines::ExtensivePureStrategyPath path(players);
    path.setPayoff(dataPiece);

    // then
    BOOST_CHECK_EQUAL(
        path.getPayoff(),
        dataPiece
    );
}

BOOST_AUTO_TEST_CASE( ExtensivePureStrategyPath_addOlderChoice_getPlayersChoices ) {
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
    GT::Routines::ExtensivePureStrategyPath path(players);
    path.addOlderChoice(l2, *p2, *s2)
        .addOlderChoice(l2, *p1, *s2)
        .addOlderChoice(l1, *p2, *s1)
        .addOlderChoice(l1, *p1, *s1);

    // then
    BOOST_REQUIRE_EQUAL( path.getPlayersChoices().size(), 2 );
    BOOST_REQUIRE_EQUAL( path.getPlayersChoices().at(*p1).size(), 2 );
    BOOST_REQUIRE_EQUAL( path.getPlayersChoices().at(*p2).size(), 2 );
    BOOST_CHECK_EQUAL( path.getPlayersChoices().at(*p1).at(l1), *s1 );
    BOOST_CHECK_EQUAL( path.getPlayersChoices().at(*p1).at(l2), *s2 );
    BOOST_CHECK_EQUAL( path.getPlayersChoices().at(*p2).at(l1), *s1 );
    BOOST_CHECK_EQUAL( path.getPlayersChoices().at(*p2).at(l2), *s2 );
}

BOOST_AUTO_TEST_CASE( ExtensivePureStrategyPath_toString ) {
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

    GT::Model::PlayerPtr  player1(new GT::Model::Player(p1, strategies));
    GT::Model::PlayerPtr  player2(new GT::Model::Player(p2, strategies));
    GT::Model::PlayersPtr players(new GT::Model::Players());
    players->insert( GT::Model::Players::value_type(*p1, player1) );
    players->insert( GT::Model::Players::value_type(*p2, player2) );

    GT::NumbersPtr payoff = GT::createNumbersPtr();
    payoff->push_back( GT::createNumberPtr(10) );
    payoff->push_back( GT::createNumberPtr(20) );

    GT::Model::DataPiecePtr dataPiece(new GT::Model::PlainDataPiece(players, payoff));

    // when
    GT::Routines::ExtensivePureStrategyPath path(players);
    path.addOlderChoice(l2, *p2, *s2)
        .addOlderChoice(l2, *p1, *s2)
        .addOlderChoice(l1, *p2, *s1)
        .addOlderChoice(l1, *p1, *s1)
        .setPayoff(dataPiece);

    // then
    BOOST_CHECK_EQUAL(
        path.toString(),
        GT::Message() +
        "p1:\n"
        "\t1:\n"
        "\t\ts1\n"
        "\t2:\n"
        "\t\ts2\n"
        "p2:\n"
        "\t1:\n"
        "\t\ts1\n"
        "\t2:\n"
        "\t\ts2\n"
        "Payoffs:\n"
        "\t\t\tp1,\tp2\n"
        "\tPayoff:\n"
        "\t\t\t10,\t20\n"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
