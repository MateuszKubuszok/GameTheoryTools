#include "gt/model/test_common.hpp"

BOOST_AUTO_TEST_SUITE( PositionsHelper )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( PositionsHelper_getUpperBound ) {
    // given
       GT::IdentifierPtr player1name      = GT::createIdentifierPtr("player1");
    GT::IdentifierPtr player1strategy1 = GT::createIdentifierPtr("p1s1");
    GT::IdentifierPtr player1strategy2 = GT::createIdentifierPtr("p1s2");
    GT::IdentifiersPtr strategies1     = GT::createIdentifiersPtr();
    strategies1->push_back(player1strategy1);
    strategies1->push_back(player1strategy2);
    GT::Model::PlayerPtr player1(new GT::Model::Player(player1name, strategies1));

    GT::IdentifierPtr player2name      = GT::createIdentifierPtr("player2");
    GT::IdentifierPtr player2strategy1 = GT::createIdentifierPtr("p2s1");
    GT::IdentifierPtr player2strategy2 = GT::createIdentifierPtr("p2s2");
    GT::IdentifiersPtr strategies2     = GT::createIdentifiersPtr();
    strategies2->push_back(player2strategy1);
    strategies2->push_back(player2strategy2);
    GT::Model::PlayerPtr player2(new GT::Model::Player(player2name, strategies2));

    GT::Model::PlayersPtr players(new GT::Model::Players());
    players->insert( GT::Model::Players::value_type(*player1name, player1) );
    players->insert( GT::Model::Players::value_type(*player2name, player2) );

    // when
    GT::Model::PositionsHelper positionsHelper(players);

    // then
    BOOST_CHECK_EQUAL(
        positionsHelper.getUpperBound(),
        4
    );
}

BOOST_AUTO_TEST_CASE( PositionsHelper_calculatePlayer ) {
    // given
    GT::IdentifierPtr player1name      = GT::createIdentifierPtr("player1");
    GT::IdentifierPtr player1strategy1 = GT::createIdentifierPtr("p1s1");
    GT::IdentifierPtr player1strategy2 = GT::createIdentifierPtr("p1s2");
    GT::IdentifiersPtr strategies1     = GT::createIdentifiersPtr();
    strategies1->push_back(player1strategy1);
    strategies1->push_back(player1strategy2);
    GT::Model::PlayerPtr player1(new GT::Model::Player(player1name, strategies1));

    GT::IdentifierPtr player2name      = GT::createIdentifierPtr("player2");
    GT::IdentifierPtr player2strategy1 = GT::createIdentifierPtr("p2s1");
    GT::IdentifierPtr player2strategy2 = GT::createIdentifierPtr("p2s2");
    GT::IdentifiersPtr strategies2     = GT::createIdentifiersPtr();
    strategies2->push_back(player2strategy1);
    strategies2->push_back(player2strategy2);
    GT::Model::PlayerPtr player2(new GT::Model::Player(player2name, strategies2));

    GT::Model::PlayersPtr players(new GT::Model::Players());
    players->insert( GT::Model::Players::value_type(*player1name, player1) );
    players->insert( GT::Model::Players::value_type(*player2name, player2) );

    // when
    GT::Model::PositionsHelper positionsHelper(players);

    // then
    BOOST_CHECK_EQUAL(
        positionsHelper.calculatePlayer(player1name),
        0
    );
    BOOST_CHECK_EQUAL(
        positionsHelper.calculatePlayer(player2name),
        1
    );
}

BOOST_AUTO_TEST_CASE( PositionsHelper_retrievePlayer ) {
    // given
    GT::IdentifierPtr player1name      = GT::createIdentifierPtr("player1");
    GT::IdentifierPtr player1strategy1 = GT::createIdentifierPtr("p1s1");
    GT::IdentifierPtr player1strategy2 = GT::createIdentifierPtr("p1s2");
    GT::IdentifiersPtr strategies1     = GT::createIdentifiersPtr();
    strategies1->push_back(player1strategy1);
    strategies1->push_back(player1strategy2);
    GT::Model::PlayerPtr player1(new GT::Model::Player(player1name, strategies1));

    GT::IdentifierPtr player2name      = GT::createIdentifierPtr("player2");
    GT::IdentifierPtr player2strategy1 = GT::createIdentifierPtr("p2s1");
    GT::IdentifierPtr player2strategy2 = GT::createIdentifierPtr("p2s2");
    GT::IdentifiersPtr strategies2     = GT::createIdentifiersPtr();
    strategies2->push_back(player2strategy1);
    strategies2->push_back(player2strategy2);
    GT::Model::PlayerPtr player2(new GT::Model::Player(player2name, strategies2));

    GT::Model::PlayersPtr players(new GT::Model::Players());
    players->insert( GT::Model::Players::value_type(*player1name, player1) );
    players->insert( GT::Model::Players::value_type(*player2name, player2) );

    // when
    GT::Model::PositionsHelper positionsHelper(players);

    // then
    BOOST_CHECK_EQUAL(
        (*positionsHelper.retrievePlayer(0)),
        (*player1name)
    );
    BOOST_CHECK_EQUAL(
        (*positionsHelper.retrievePlayer(1)),
        (*player2name)
    );
}

BOOST_AUTO_TEST_CASE( PositionsHelper_calculatePosition ) {
    // given
    GT::IdentifierPtr player1name      = GT::createIdentifierPtr("player1");
    GT::IdentifierPtr player1strategy1 = GT::createIdentifierPtr("p1s1");
    GT::IdentifierPtr player1strategy2 = GT::createIdentifierPtr("p1s2");
    GT::IdentifiersPtr strategies1     = GT::createIdentifiersPtr();
    strategies1->push_back(player1strategy1);
    strategies1->push_back(player1strategy2);
    GT::Model::PlayerPtr player1(new GT::Model::Player(player1name, strategies1));

    GT::IdentifierPtr player2name      = GT::createIdentifierPtr("player2");
    GT::IdentifierPtr player2strategy1 = GT::createIdentifierPtr("p2s1");
    GT::IdentifierPtr player2strategy2 = GT::createIdentifierPtr("p2s2");
    GT::IdentifiersPtr strategies2     = GT::createIdentifiersPtr();
    strategies2->push_back(player2strategy1);
    strategies2->push_back(player2strategy2);
    GT::Model::PlayerPtr player2(new GT::Model::Player(player2name, strategies2));

    GT::Model::PlayersPtr players(new GT::Model::Players());
    players->insert( GT::Model::Players::value_type(*player1name, player1) );
    players->insert( GT::Model::Players::value_type(*player2name, player2) );

    GT::PositionsPtr position11 = GT::createPositionsPtr();
    position11->insert( GT::Positions::value_type(*player1name, *player1strategy1) );
    position11->insert( GT::Positions::value_type(*player2name, *player2strategy1) );
    GT::PositionsPtr position12 = GT::createPositionsPtr();
    position12->insert( GT::Positions::value_type(*player1name, *player1strategy1) );
    position12->insert( GT::Positions::value_type(*player2name, *player2strategy2) );
    GT::PositionsPtr position21 = GT::createPositionsPtr();
    position21->insert( GT::Positions::value_type(*player1name, *player1strategy2) );
    position21->insert( GT::Positions::value_type(*player2name, *player2strategy1) );
    GT::PositionsPtr position22 = GT::createPositionsPtr();
    position22->insert( GT::Positions::value_type(*player1name, *player1strategy2) );
    position22->insert( GT::Positions::value_type(*player2name, *player2strategy2) );

    // when
    GT::Model::PositionsHelper positionsHelper(players);

    // then
    BOOST_CHECK_EQUAL(
        positionsHelper.calculatePosition(position11),
        0
    );
    BOOST_CHECK_EQUAL(
        positionsHelper.calculatePosition(position12),
        2
    );
    BOOST_CHECK_EQUAL(
        positionsHelper.calculatePosition(position21),
        1
    );
    BOOST_CHECK_EQUAL(
        positionsHelper.calculatePosition(position22),
        3
    );
}

BOOST_AUTO_TEST_CASE( PositionsHelper_retrievePositions ) {
    // given
    GT::IdentifierPtr player1name      = GT::createIdentifierPtr("player1");
    GT::IdentifierPtr player1strategy1 = GT::createIdentifierPtr("p1s1");
    GT::IdentifierPtr player1strategy2 = GT::createIdentifierPtr("p1s2");
    GT::IdentifiersPtr strategies1     = GT::createIdentifiersPtr();
    strategies1->push_back(player1strategy1);
    strategies1->push_back(player1strategy2);
    GT::Model::PlayerPtr player1(new GT::Model::Player(player1name, strategies1));

    GT::IdentifierPtr player2name      = GT::createIdentifierPtr("player2");
    GT::IdentifierPtr player2strategy1 = GT::createIdentifierPtr("p2s1");
    GT::IdentifierPtr player2strategy2 = GT::createIdentifierPtr("p2s2");
    GT::IdentifiersPtr strategies2     = GT::createIdentifiersPtr();
    strategies2->push_back(player2strategy1);
    strategies2->push_back(player2strategy2);
    GT::Model::PlayerPtr player2(new GT::Model::Player(player2name, strategies2));

    GT::Model::PlayersPtr players(new GT::Model::Players());
    players->insert( GT::Model::Players::value_type(*player1name, player1) );
    players->insert( GT::Model::Players::value_type(*player2name, player2) );

    GT::PositionsPtr position11 = GT::createPositionsPtr();
    position11->insert( GT::Positions::value_type(*player1name, *player1strategy1) );
    position11->insert( GT::Positions::value_type(*player2name, *player2strategy1) );
    GT::PositionsPtr position12 = GT::createPositionsPtr();
    position12->insert( GT::Positions::value_type(*player1name, *player1strategy1) );
    position12->insert( GT::Positions::value_type(*player2name, *player2strategy2) );
    GT::PositionsPtr position21 = GT::createPositionsPtr();
    position21->insert( GT::Positions::value_type(*player1name, *player1strategy2) );
    position21->insert( GT::Positions::value_type(*player2name, *player2strategy1) );
    GT::PositionsPtr position22 = GT::createPositionsPtr();
    position22->insert( GT::Positions::value_type(*player1name, *player1strategy2) );
    position22->insert( GT::Positions::value_type(*player2name, *player2strategy2) );

    // when
    GT::Model::PositionsHelper positionsHelper(players);
    GT::PositionsPtr retrievedPosition0 = positionsHelper.retrievePositions(0);
    GT::PositionsPtr retrievedPosition1 = positionsHelper.retrievePositions(1);
    GT::PositionsPtr retrievedPosition2 = positionsHelper.retrievePositions(2);
    GT::PositionsPtr retrievedPosition3 = positionsHelper.retrievePositions(3);

    // then
    BOOST_CHECK_EQUAL(
        (*retrievedPosition0)[*player1name],
        (*position11)[*player1name]
    );
    BOOST_CHECK_EQUAL(
        (*retrievedPosition0)[*player2name],
        (*position11)[*player2name]
    );
    BOOST_CHECK_EQUAL(
        (*retrievedPosition1)[*player1name],
        (*position21)[*player1name]
    );
    BOOST_CHECK_EQUAL(
        (*retrievedPosition1)[*player2name],
        (*position21)[*player2name]
    );
    BOOST_CHECK_EQUAL(
        (*retrievedPosition2)[*player1name],
        (*position12)[*player1name]
    );
    BOOST_CHECK_EQUAL(
        (*retrievedPosition2)[*player2name],
        (*position12)[*player2name]
    );
    BOOST_CHECK_EQUAL(
        (*retrievedPosition3)[*player1name],
        (*position22)[*player1name]
    );
    BOOST_CHECK_EQUAL(
        (*retrievedPosition3)[*player2name],
        (*position22)[*player2name]
    );
}

BOOST_AUTO_TEST_CASE( PositionsHelper_checkPlayer ) {
    // given
    GT::IdentifierPtr player1name      = GT::createIdentifierPtr("player1");
    GT::IdentifierPtr player1strategy1 = GT::createIdentifierPtr("p1s1");
    GT::IdentifierPtr player1strategy2 = GT::createIdentifierPtr("p1s2");
    GT::IdentifiersPtr strategies1     = GT::createIdentifiersPtr();
    strategies1->push_back(player1strategy1);
    strategies1->push_back(player1strategy2);
    GT::Model::PlayerPtr player1(new GT::Model::Player(player1name, strategies1));

    GT::IdentifierPtr player2name      = GT::createIdentifierPtr("player2");
    GT::IdentifierPtr player2strategy1 = GT::createIdentifierPtr("p2s1");
    GT::IdentifierPtr player2strategy2 = GT::createIdentifierPtr("p2s2");
    GT::IdentifiersPtr strategies2     = GT::createIdentifiersPtr();
    strategies2->push_back(player2strategy1);
    strategies2->push_back(player2strategy2);
    GT::Model::PlayerPtr player2(new GT::Model::Player(player2name, strategies2));


    GT::IdentifierPtr player3name      = GT::createIdentifierPtr("player3");

    GT::Model::PlayersPtr players(new GT::Model::Players());
    players->insert( GT::Model::Players::value_type(*player1name, player1) );
    players->insert( GT::Model::Players::value_type(*player2name, player2) );

    // when
    GT::Model::PositionsHelper positionsHelper(players);

    // then
    BOOST_CHECK(positionsHelper.checkPlayer(player1name));
    BOOST_CHECK(positionsHelper.checkPlayer(player2name));
    BOOST_CHECK(!positionsHelper.checkPlayer(player3name));
}

BOOST_AUTO_TEST_CASE( PositionsHelper_checkPositions ) {
    // given
    GT::IdentifierPtr player1name      = GT::createIdentifierPtr("player1");
    GT::IdentifierPtr player1strategy1 = GT::createIdentifierPtr("p1s1");
    GT::IdentifierPtr player1strategy2 = GT::createIdentifierPtr("p1s2");
    GT::IdentifiersPtr strategies1     = GT::createIdentifiersPtr();
    strategies1->push_back(player1strategy1);
    strategies1->push_back(player1strategy2);
    GT::Model::PlayerPtr player1(new GT::Model::Player(player1name, strategies1));

    GT::IdentifierPtr player2name      = GT::createIdentifierPtr("player2");
    GT::IdentifierPtr player2strategy1 = GT::createIdentifierPtr("p2s1");
    GT::IdentifierPtr player2strategy2 = GT::createIdentifierPtr("p2s2");
    GT::IdentifiersPtr strategies2     = GT::createIdentifiersPtr();
    strategies2->push_back(player2strategy1);
    strategies2->push_back(player2strategy2);
    GT::Model::PlayerPtr player2(new GT::Model::Player(player2name, strategies2));

    GT::Model::PlayersPtr players(new GT::Model::Players());
    players->insert( GT::Model::Players::value_type(*player1name, player1) );
    players->insert( GT::Model::Players::value_type(*player2name, player2) );

    GT::IdentifierPtr wrongPlayer   = GT::createIdentifierPtr("player3");
    GT::IdentifierPtr wrongStrategy = GT::createIdentifierPtr("p3s1");

    GT::PositionsPtr position11 = GT::createPositionsPtr();
    position11->insert( GT::Positions::value_type(*player1name, *player1strategy1) );
    position11->insert( GT::Positions::value_type(*player2name, *player2strategy1) );
    GT::PositionsPtr position12 = GT::createPositionsPtr();
    position12->insert( GT::Positions::value_type(*player1name, *player1strategy1) );
    position12->insert( GT::Positions::value_type(*player2name, *player2strategy2) );
    GT::PositionsPtr position21 = GT::createPositionsPtr();
    position21->insert( GT::Positions::value_type(*player1name, *player1strategy2) );
    position21->insert( GT::Positions::value_type(*player2name, *player2strategy1) );
    GT::PositionsPtr position22 = GT::createPositionsPtr();
    position22->insert( GT::Positions::value_type(*player1name, *player1strategy2) );
    position22->insert( GT::Positions::value_type(*player2name, *player2strategy2) );
    GT::PositionsPtr wrongPosition1 = GT::createPositionsPtr();
    wrongPosition1->insert( GT::Positions::value_type(*player1name, *player1strategy2) );
    wrongPosition1->insert( GT::Positions::value_type(*wrongPlayer, *player2strategy2) );
    GT::PositionsPtr wrongPosition2 = GT::createPositionsPtr();
    wrongPosition2->insert( GT::Positions::value_type(*player1name, *player1strategy2) );
    wrongPosition2->insert( GT::Positions::value_type(*player2name, *wrongStrategy) );

    // when
    GT::Model::PositionsHelper positionsHelper(players);

    // then
    BOOST_CHECK(positionsHelper.checkPositions(position11));
    BOOST_CHECK(positionsHelper.checkPositions(position12));
    BOOST_CHECK(positionsHelper.checkPositions(position21));
    BOOST_CHECK(positionsHelper.checkPositions(position22));
    BOOST_CHECK(!positionsHelper.checkPositions(wrongPosition1));
    BOOST_CHECK(!positionsHelper.checkPositions(wrongPosition2));
}

BOOST_AUTO_TEST_CASE( PositionsHelper_toString ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::IdentifierPtr player1name      = GT::createIdentifierPtr("player1");
    GT::IdentifierPtr player1strategy1 = GT::createIdentifierPtr("p1s1");
    GT::IdentifierPtr player1strategy2 = GT::createIdentifierPtr("p1s2");
    GT::IdentifiersPtr strategies1     = GT::createIdentifiersPtr();
    strategies1->push_back(player1strategy1);
    strategies1->push_back(player1strategy2);
    GT::Model::PlayerPtr player1(new GT::Model::Player(player1name, strategies1));

    GT::IdentifierPtr player2name      = GT::createIdentifierPtr("player2");
    GT::IdentifierPtr player2strategy1 = GT::createIdentifierPtr("p2s1");
    GT::IdentifierPtr player2strategy2 = GT::createIdentifierPtr("p2s2");
    GT::IdentifiersPtr strategies2     = GT::createIdentifiersPtr();
    strategies2->push_back(player2strategy1);
    strategies2->push_back(player2strategy2);
    GT::Model::PlayerPtr player2(new GT::Model::Player(player2name, strategies2));

    GT::Model::PlayersPtr players(new GT::Model::Players());
    players->insert( GT::Model::Players::value_type(*player1name, player1) );
    players->insert( GT::Model::Players::value_type(*player2name, player2) );

    // when
    GT::Model::PositionsHelper positionsHelper(players);

    // then
    BOOST_CHECK_EQUAL(
        positionsHelper.toString(),
        GT::Message() +
        "Player:\n"
        "\tName:\n"
        "\t\tplayer1\n"
        "\t0:\n"
        "\t\tp1s1\n"
        "\t1:\n"
        "\t\tp1s2\n"
        "Player:\n"
        "\tName:\n"
        "\t\tplayer2\n"
        "\t0:\n"
        "\t\tp2s1\n"
        "\t1:\n"
        "\t\tp2s2\n"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
