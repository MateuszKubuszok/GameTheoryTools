#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>

#include "gt/model/inner_common.hpp"

BOOST_AUTO_TEST_SUITE( PlainData )

BOOST_AUTO_TEST_CASE( PlainData_setValue_getValue ) {
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

    GT::NumbersPtr values11 = GT::createNumbersPtr();
    values11->push_back( GT::createNumberPtr(10) );
    values11->push_back( GT::createNumberPtr(20) );
    GT::NumbersPtr values12 = GT::createNumbersPtr();
    values12->push_back( GT::createNumberPtr(30) );
    values12->push_back( GT::createNumberPtr(40) );
    GT::NumbersPtr values21 = GT::createNumbersPtr();
    values21->push_back( GT::createNumberPtr(50) );
    values21->push_back( GT::createNumberPtr(60) );
    GT::NumbersPtr values22 = GT::createNumbersPtr();
    values22->push_back( GT::createNumberPtr(70) );
    values22->push_back( GT::createNumberPtr(80) );

    // when
    GT::Model::PlainData plainData(players);
    plainData.setValues(position11, values11);
    plainData.setValues(position12, values12);
    plainData.setValues(position21, values21);
    plainData.setValues(position22, values22);

    // then
    BOOST_CHECK_EQUAL( plainData.getValues(position11)->getValue(*player1name), (*values11)[0] );
    BOOST_CHECK_EQUAL( plainData.getValues(position11)->getValue(*player2name), (*values11)[1] );

    BOOST_CHECK_EQUAL( plainData.getValues(position12)->getValue(*player1name), (*values12)[0] );
    BOOST_CHECK_EQUAL( plainData.getValues(position12)->getValue(*player2name), (*values12)[1] );

    BOOST_CHECK_EQUAL( plainData.getValues(position21)->getValue(*player1name), (*values21)[0] );
    BOOST_CHECK_EQUAL( plainData.getValues(position21)->getValue(*player2name), (*values21)[1] );

    BOOST_CHECK_EQUAL( plainData.getValues(position22)->getValue(*player1name), (*values22)[0] );
    BOOST_CHECK_EQUAL( plainData.getValues(position22)->getValue(*player2name), (*values22)[1] );
}

BOOST_AUTO_TEST_CASE( PlainData_operatorOverload ) {
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

    GT::NumbersPtr values11 = GT::createNumbersPtr();
    values11->push_back( GT::createNumberPtr(10) );
    values11->push_back( GT::createNumberPtr(20) );
    GT::NumbersPtr values12 = GT::createNumbersPtr();
    values12->push_back( GT::createNumberPtr(30) );
    values12->push_back( GT::createNumberPtr(40) );
    GT::NumbersPtr values21 = GT::createNumbersPtr();
    values21->push_back( GT::createNumberPtr(50) );
    values21->push_back( GT::createNumberPtr(60) );
    GT::NumbersPtr values22 = GT::createNumbersPtr();
    values22->push_back( GT::createNumberPtr(70) );
    values22->push_back( GT::createNumberPtr(80) );

    // when
    GT::Model::PlainData plainData(players);
    plainData.setValues(position11, values11);
    plainData.setValues(position12, values12);
    plainData.setValues(position21, values21);
    plainData.setValues(position22, values22);

    // then
    BOOST_CHECK_EQUAL( plainData[position11]->getValue(*player1name), (*values11)[0] );
    BOOST_CHECK_EQUAL( plainData[position11]->getValue(*player2name), (*values11)[1] );

    BOOST_CHECK_EQUAL( plainData[position12]->getValue(*player1name), (*values12)[0] );
    BOOST_CHECK_EQUAL( plainData[position12]->getValue(*player2name), (*values12)[1] );

    BOOST_CHECK_EQUAL( plainData[position21]->getValue(*player1name), (*values21)[0] );
    BOOST_CHECK_EQUAL( plainData[position21]->getValue(*player2name), (*values21)[1] );

    BOOST_CHECK_EQUAL( plainData[position22]->getValue(*player1name), (*values22)[0] );
    BOOST_CHECK_EQUAL( plainData[position22]->getValue(*player2name), (*values22)[1] );
}

BOOST_AUTO_TEST_CASE( PlainData_throwExceptionOnInvalidCoordinate ) {
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
    GT::Model::PlayerPtr player2(new GT::Model::Player(player2name, strategies2));

    GT::IdentifierPtr player3name      = GT::createIdentifierPtr("player3");

    GT::Model::PlayersPtr players(new GT::Model::Players());
    players->insert( GT::Model::Players::value_type(*player1name, player1) );
    players->insert( GT::Model::Players::value_type(*player2name, player2) );

    // when
    GT::Model::PlainData plainData(players);

    GT::PositionsPtr invalidPosition1 = GT::createPositionsPtr();
    invalidPosition1->insert( GT::Positions::value_type(*player1name, *player1strategy1) );
    invalidPosition1->insert( GT::Positions::value_type(*player2name, *player2strategy2) );
    GT::PositionsPtr invalidPosition2 = GT::createPositionsPtr();
    invalidPosition2->insert( GT::Positions::value_type(*player3name, *player1strategy1) );
    invalidPosition2->insert( GT::Positions::value_type(*player2name, *player2strategy2) );

    GT::NumbersPtr values1 = GT::createNumbersPtr();
    values1->push_back( GT::createNumberPtr(10) );
    values1->push_back( GT::createNumberPtr(20) );
    GT::NumbersPtr values2 = GT::createNumbersPtr();
    values2->push_back( GT::createNumberPtr(30) );
    values2->push_back( GT::createNumberPtr(40) );

    // then
    BOOST_CHECK_THROW(
        plainData.setValues(invalidPosition1, values1),
        GT::Model::InvalidCoordinate
    );
    BOOST_CHECK_THROW(
        plainData.setValues(invalidPosition2, values2),
        GT::Model::InvalidCoordinate
    );
}

BOOST_AUTO_TEST_CASE( PlainData_toString ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setIndentationMode(GT::Model::TABS)
        .setBuilderMode(GT::Model::PLAIN);

    GT::IdentifierPtr player1name      = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr player1strategy1 = GT::createIdentifierPtr("p1s1");
    GT::IdentifierPtr player1strategy2 = GT::createIdentifierPtr("p1s2");
    GT::IdentifiersPtr strategies1     = GT::createIdentifiersPtr();
    strategies1->push_back(player1strategy1);
    strategies1->push_back(player1strategy2);
    GT::Model::PlayerPtr player1(new GT::Model::Player(player1name, strategies1));
    
    GT::IdentifierPtr player2name      = GT::createIdentifierPtr("p2");
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

    GT::NumbersPtr values11 = GT::createNumbersPtr();
    values11->push_back( GT::createNumberPtr(10) );
    values11->push_back( GT::createNumberPtr(20) );
    GT::NumbersPtr values12 = GT::createNumbersPtr();
    values12->push_back( GT::createNumberPtr(30) );
    values12->push_back( GT::createNumberPtr(40) );
    GT::NumbersPtr values21 = GT::createNumbersPtr();
    values21->push_back( GT::createNumberPtr(50) );
    values21->push_back( GT::createNumberPtr(60) );
    GT::NumbersPtr values22 = GT::createNumbersPtr();
    values22->push_back( GT::createNumberPtr(70) );
    values22->push_back( GT::createNumberPtr(80) );

    // when
    GT::Model::PlainData plainData(players);
    plainData.setValues(position11, values11);
    plainData.setValues(position12, values12);
    plainData.setValues(position21, values21);
    plainData.setValues(position22, values22);

    // then
    BOOST_CHECK_EQUAL(
        plainData.toString(),
        GT::Message() +
        "\t\nValue:\n"
        "\t\t\tp1,\tp2,\n" +
        "\tPosition:\n" +
        "\t\t\tp1s1,\tp2s1,\n" +
        "\tPayoff:\n" +
        "\t\t\t10,\t20,\n" +
        "Value:\n" +
        "\t\t\tp1,\tp2,\n" +
        "\tPosition:\n" +
        "\t\t\tp1s2,\tp2s1,\n" +
        "\tPayoff:\n" +
        "\t\t\t50,\t60,\n" +
        "Value:\n" +
        "\t\t\tp1,\tp2,\n" +
        "\tPosition:\n" +
        "\t\t\tp1s1,\tp2s2,\n" +
        "\tPayoff:\n" +
        "\t\t\t30,\t40,\n" +
        "Value:\n" +
        "\t\t\tp1,\tp2,\n" +
        "\tPosition:\n" +
        "\t\t\tp1s2,\tp2s2,\n" +
        "\tPayoff:\n" +
        "\t\t\t70,\t80,\n"
    );
}

BOOST_AUTO_TEST_SUITE_END()