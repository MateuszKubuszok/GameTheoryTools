#include "gt/model/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ExtensiveDataNode )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( ExtensiveDataNode_setPlayer_getPlayer ) {
    // given
    GT::Model::PlayerPtr player = GT::Model::NullFactory::getInstance().createPlayer();

    // when
    GT::Model::ExtensiveDataNode root;
    root.setPlayer(player);

    // then
    BOOST_CHECK_EQUAL(
        root.getPlayer(),
        player
    );
}

BOOST_AUTO_TEST_CASE( ExtensiveDataNode_functional ) {
    // given
    GT::Identifier l1 = GT::createIdentifier("1");
    GT::Identifier l2 = GT::createIdentifier("2");
    GT::Identifier s1 = GT::createIdentifier("s1");
    GT::Identifier s2 = GT::createIdentifier("s2");

    GT::IdentifierPtr  p          = GT::createIdentifierPtr("p");
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();
    strategies->push_back(GT::createIdentifierPtr(s1));
    strategies->push_back(GT::createIdentifierPtr(s2));
    GT::Model::PlayerPtr  player(new GT::Model::Player(p, strategies));

    GT::Positions plRoot = GT::createPositions();
    GT::Positions pl11 = GT::createPositions();
    pl11.insert( GT::Positions::value_type(l1, s1) );
    GT::Positions pl12 = GT::createPositions();
    pl12.insert( GT::Positions::value_type(l1, s2) );

    GT::Positions p11 = GT::createPositions();
    p11.insert( GT::Positions::value_type(l1, s1) );
    p11.insert( GT::Positions::value_type(l2, s1) );
    GT::Positions p12 = GT::createPositions();
    p12.insert( GT::Positions::value_type(l1, s1) );
    p12.insert( GT::Positions::value_type(l2, s2) );
    GT::Positions p21 = GT::createPositions();
    p21.insert( GT::Positions::value_type(l1, s2) );
    p21.insert( GT::Positions::value_type(l2, s1) );
    GT::Positions p22 = GT::createPositions();
    p22.insert( GT::Positions::value_type(l1, s2) );
    p22.insert( GT::Positions::value_type(l2, s2) );

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
    GT::Model::ExtensiveDataNode root;

    root.setPlayer( plRoot, player )
        .setPlayer( pl11,   player ).setPlayer( pl12, player );

    root.setPayoffs( p11, payoff11 ).setPayoffs( p12, payoff12 )
        .setPayoffs( p21, payoff21 ).setPayoffs( p22, payoff22 );

    GT::NumbersPtr got11 = root.getPayoffs(p11);
    GT::NumbersPtr got12 = root.getPayoffs(p12);
    GT::NumbersPtr got21 = root.getPayoffs(p21);
    GT::NumbersPtr got22 = root.getPayoffs(p22);

    // then
    BOOST_CHECK_EQUAL_COLLECTIONS(
        got11->begin(),    got11->end(),
        payoff11->begin(), payoff11->end()
    );
    BOOST_CHECK_EQUAL_COLLECTIONS(
        got12->begin(),    got12->end(),
        payoff12->begin(), payoff12->end()
    );
    BOOST_CHECK_EQUAL_COLLECTIONS(
        got21->begin(),    got21->end(),
        payoff21->begin(), payoff21->end()
    );
    BOOST_CHECK_EQUAL_COLLECTIONS(
        got22->begin(),    got22->end(),
        payoff22->begin(), payoff22->end()
    );

    BOOST_CHECK(      !root.isLeaf() );
    BOOST_CHECK_EQUAL( root.getChoices()->size(), 2 );

    BOOST_CHECK(            root.hasChoice(s1) );
    BOOST_REQUIRE_NO_THROW( root.getNodeForChoice(s1) );
    BOOST_CHECK(           !root.getNodeForChoice(s1).isLeaf() );
    BOOST_CHECK_EQUAL(      root.getNodeForChoice(s1).getChoices()->size(), 2 );

    BOOST_CHECK(            root.getNodeForChoice(s1).hasChoice(s1) );
    BOOST_REQUIRE_NO_THROW( root.getNodeForChoice(s1).getNodeForChoice(s1) );
    BOOST_CHECK(            root.getNodeForChoice(s1).getNodeForChoice(s1).isLeaf() );
    BOOST_CHECK(            root.getNodeForChoice(s1).getNodeForChoice(s1).getChoices()->empty() );

    BOOST_CHECK(            root.getNodeForChoice(s1).hasChoice(s2) );
    BOOST_REQUIRE_NO_THROW( root.getNodeForChoice(s1).getNodeForChoice(s2) );
    BOOST_CHECK(            root.getNodeForChoice(s1).getNodeForChoice(s2).isLeaf() );
    BOOST_CHECK(            root.getNodeForChoice(s1).getNodeForChoice(s2).getChoices()->empty() );

    BOOST_CHECK(            root.hasChoice(s2) );
    BOOST_REQUIRE_NO_THROW( root.getNodeForChoice(s2) );
    BOOST_CHECK(           !root.getNodeForChoice(s2).isLeaf() );
    BOOST_CHECK_EQUAL(      root.getNodeForChoice(s2).getChoices()->size(), 2 );

    BOOST_CHECK(            root.getNodeForChoice(s2).hasChoice(s1) );
    BOOST_REQUIRE_NO_THROW( root.getNodeForChoice(s2).getNodeForChoice(s1) );
    BOOST_CHECK(            root.getNodeForChoice(s2).getNodeForChoice(s1).isLeaf() );
    BOOST_CHECK(            root.getNodeForChoice(s2).getNodeForChoice(s1).getChoices()->empty() );

    BOOST_CHECK(            root.getNodeForChoice(s2).hasChoice(s2) );
    BOOST_REQUIRE_NO_THROW( root.getNodeForChoice(s2).getNodeForChoice(s2) );
    BOOST_CHECK(            root.getNodeForChoice(s2).getNodeForChoice(s2).isLeaf() );
    BOOST_CHECK(            root.getNodeForChoice(s2).getNodeForChoice(s2).getChoices()->empty() );
}

BOOST_AUTO_TEST_CASE( ExtensiveDataNode_toString ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::Identifier l1 = GT::createIdentifier("1");
    GT::Identifier l2 = GT::createIdentifier("2");
    GT::Identifier s1 = GT::createIdentifier("s1");
    GT::Identifier s2 = GT::createIdentifier("s2");

    GT::IdentifierPtr  p          = GT::createIdentifierPtr("p");
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();
    strategies->push_back(GT::createIdentifierPtr(s1));
    strategies->push_back(GT::createIdentifierPtr(s2));
    GT::Model::PlayerPtr  player(new GT::Model::Player(p, strategies));

    GT::Positions plRoot = GT::createPositions();
    GT::Positions pl11 = GT::createPositions();
    pl11.insert( GT::Positions::value_type(l1, s1) );
    GT::Positions pl12 = GT::createPositions();
    pl12.insert( GT::Positions::value_type(l1, s2) );

    GT::Positions p11 = GT::createPositions();
    p11.insert( GT::Positions::value_type(l1, s1) );
    p11.insert( GT::Positions::value_type(l2, s1) );
    GT::Positions p12 = GT::createPositions();
    p12.insert( GT::Positions::value_type(l1, s1) );
    p12.insert( GT::Positions::value_type(l2, s2) );
    GT::Positions p21 = GT::createPositions();
    p21.insert( GT::Positions::value_type(l1, s2) );
    p21.insert( GT::Positions::value_type(l2, s1) );
    GT::Positions p22 = GT::createPositions();
    p22.insert( GT::Positions::value_type(l1, s2) );
    p22.insert( GT::Positions::value_type(l2, s2) );

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
    GT::Model::ExtensiveDataNode root;

    root.setPlayer( plRoot, player )
        .setPlayer( pl11,   player ).setPlayer( pl12, player );

    root.setPayoffs( p11, payoff11 ).setPayoffs( p12, payoff12 )
        .setPayoffs( p21, payoff21 ).setPayoffs( p22, payoff22 );

    GT::NumbersPtr got11 = root.getPayoffs(p11);
    GT::NumbersPtr got12 = root.getPayoffs(p12);
    GT::NumbersPtr got21 = root.getPayoffs(p21);
    GT::NumbersPtr got22 = root.getPayoffs(p22);

    // then
    BOOST_CHECK_EQUAL(
        root.toString(),
        GT::Message() +
        "Player:\n"
        "\tName:\n"
        "\t\tp\n"
        "\t0:\n"
        "\t\ts1\n"
        "\t1:\n"
        "\t\ts2\n"
        "s1:\n"
        "\tPlayer:\n"
        "\t\tName:\n"
        "\t\t\tp\n"
        "\t\t0:\n"
        "\t\t\ts1\n"
        "\t\t1:\n"
        "\t\t\ts2\n"
        "\ts1:\n"
        "\t\tValue:\n"
        "\t\t\t10\n"
        "\t\tValue:\n"
        "\t\t\t20\n"
        "\ts2:\n"
        "\t\tValue:\n"
        "\t\t\t30\n"
        "\t\tValue:\n"
        "\t\t\t40\n"
        "s2:\n"
        "\tPlayer:\n"
        "\t\tName:\n"
        "\t\t\tp\n"
        "\t\t0:\n"
        "\t\t\ts1\n"
        "\t\t1:\n"
        "\t\t\ts2\n"
        "\ts1:\n"
        "\t\tValue:\n"
        "\t\t\t50\n"
        "\t\tValue:\n"
        "\t\t\t60\n"
        "\ts2:\n"
        "\t\tValue:\n"
        "\t\t\t70\n"
        "\t\tValue:\n"
        "\t\t\t80\n"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
