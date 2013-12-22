#include "gt/model/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ExtensiveGamePositionsHelper )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( ExtensiveGamePositionsHelper_functional ) {
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

    GT::Model::ExtensiveDataNodePtr root(new GT::Model::ExtensiveDataNode());

    (*root)
        .setPlayer(  plRoot, player )
        .setPlayer(  pl11,   player ).setPlayer(  pl12, player  )
        .setPayoffs( p11, payoff11  ).setPayoffs( p12, payoff12 )
        .setPayoffs( p21, payoff21  ).setPayoffs( p22, payoff22 );

    GT::Identifier is1("1");
    GT::Identifier is2("2");
    GT::Identifier is3("3");

    // when
    GT::Model::ExtensiveGamePositionsHelper positionsHelper(root);

    // then
    BOOST_CHECK_EQUAL(      positionsHelper.getPossiblePlayers()->size(), 1 );
    BOOST_REQUIRE(         *positionsHelper.getPossiblePlayers()->at(0) == *p );
    BOOST_REQUIRE_NO_THROW( positionsHelper.getPossibleInformationSetsForPlayer(*p) );
    BOOST_CHECK_EQUAL(      positionsHelper.getPossibleInformationSetsForPlayer(*p)->size(), 3 );
    BOOST_REQUIRE_EQUAL(    positionsHelper.getInformationSetsForPlayer(*p).size(), 3 );
    BOOST_CHECK_EQUAL(
        positionsHelper.getInformationSetForPlayer(*p, is1),
        *root
    );
    BOOST_REQUIRE_NO_THROW( root->getChildren().at(s1) );
    BOOST_CHECK_EQUAL(
        positionsHelper.getInformationSetForPlayer(*p, is2),
        *root->getChildren().at(s1)
    );
    BOOST_REQUIRE_NO_THROW( root->getChildren().at(s2) );
    BOOST_CHECK_EQUAL(
        positionsHelper.getInformationSetForPlayer(*p, is3),
        *root->getChildren().at(s2)
    );
}

BOOST_AUTO_TEST_CASE( ExtensiveGamePositionsHelper_toString ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::Model::ExtensiveDataNodePtr root(new GT::Model::ExtensiveDataNode());

    // when
    GT::Model::ExtensiveGamePositionsHelper positionsHelper(root);

    // then
    BOOST_CHECK_EQUAL(
        positionsHelper.toString(),
        GT::Message() +
        "ExtensiveGamePositionsHelper"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
