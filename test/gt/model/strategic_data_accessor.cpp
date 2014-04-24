#include "gt/model/test_common.hpp"

BOOST_AUTO_TEST_SUITE( StrategicDataAccessor )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( StrategicDataAccessor_getPayoff ) {
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

    GT::Model::StrategicDataPtr strategicData(new GT::Model::StrategicData(players));
    strategicData->setPayoffs(position11, values11);
    strategicData->setPayoffs(position12, values12);
    strategicData->setPayoffs(position21, values21);
    strategicData->setPayoffs(position22, values22);

    // when
    GT::Model::StrategicDataAccessor strategicDataAccessor(strategicData);

    // then
    BOOST_CHECK_EQUAL( strategicDataAccessor.getPayoffs(position11)->getPayoff(*player1name), (*values11)[0] );
    BOOST_CHECK_EQUAL( strategicDataAccessor.getPayoffs(position11)->getPayoff(*player2name), (*values11)[1] );

    BOOST_CHECK_EQUAL( strategicDataAccessor.getPayoffs(position12)->getPayoff(*player1name), (*values12)[0] );
    BOOST_CHECK_EQUAL( strategicDataAccessor.getPayoffs(position12)->getPayoff(*player2name), (*values12)[1] );

    BOOST_CHECK_EQUAL( strategicDataAccessor.getPayoffs(position21)->getPayoff(*player1name), (*values21)[0] );
    BOOST_CHECK_EQUAL( strategicDataAccessor.getPayoffs(position21)->getPayoff(*player2name), (*values21)[1] );

    BOOST_CHECK_EQUAL( strategicDataAccessor.getPayoffs(position22)->getPayoff(*player1name), (*values22)[0] );
    BOOST_CHECK_EQUAL( strategicDataAccessor.getPayoffs(position22)->getPayoff(*player2name), (*values22)[1] );
}

BOOST_AUTO_TEST_CASE( StrategicDataAccessor_getUpperBound ) {
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

    GT::Model::StrategicDataPtr strategicData(new GT::Model::StrategicData(players));
    strategicData->setPayoffs(position11, values11);
    strategicData->setPayoffs(position12, values12);
    strategicData->setPayoffs(position21, values21);
    strategicData->setPayoffs(position22, values22);

    // when
    GT::Model::StrategicDataAccessor strategicDataAccessor(strategicData);

    // then
    BOOST_CHECK_EQUAL( strategicDataAccessor.getUpperBound(), 4 );
}

BOOST_AUTO_TEST_CASE( StrategicDataAccessor_operatorOverload ) {
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

    GT::Model::StrategicDataPtr strategicData(new GT::Model::StrategicData(players));
    strategicData->setPayoffs(position11, values11);
    strategicData->setPayoffs(position12, values12);
    strategicData->setPayoffs(position21, values21);
    strategicData->setPayoffs(position22, values22);

    // when
    GT::Model::StrategicDataAccessor strategicDataAccessor(strategicData);

    // then
    BOOST_CHECK_EQUAL( strategicDataAccessor[position11]->getPayoff(*player1name), (*values11)[0] );
    BOOST_CHECK_EQUAL( strategicDataAccessor[position11]->getPayoff(*player2name), (*values11)[1] );

    BOOST_CHECK_EQUAL( strategicDataAccessor[position12]->getPayoff(*player1name), (*values12)[0] );
    BOOST_CHECK_EQUAL( strategicDataAccessor[position12]->getPayoff(*player2name), (*values12)[1] );

    BOOST_CHECK_EQUAL( strategicDataAccessor[position21]->getPayoff(*player1name), (*values21)[0] );
    BOOST_CHECK_EQUAL( strategicDataAccessor[position21]->getPayoff(*player2name), (*values21)[1] );

    BOOST_CHECK_EQUAL( strategicDataAccessor[position22]->getPayoff(*player1name), (*values22)[0] );
    BOOST_CHECK_EQUAL( strategicDataAccessor[position22]->getPayoff(*player2name), (*values22)[1] );
}

BOOST_AUTO_TEST_CASE( StrategicDataAccessor_toString ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

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

    GT::Model::StrategicDataPtr strategicData(new GT::Model::StrategicData(players));
    strategicData->setPayoffs(position11, values11);
    strategicData->setPayoffs(position12, values12);
    strategicData->setPayoffs(position21, values21);
    strategicData->setPayoffs(position22, values22);

    // when
    GT::Model::StrategicDataAccessor strategicDataAccessor(strategicData);

    // then
    BOOST_CHECK_EQUAL(
        strategicDataAccessor.toString(),
        GT::Message() +
        "Strategic Data Accessor:\n"
        "\tValue:\n"
        "\t\t\t\tp1,\tp2\n"
        "\t\tPosition:\n"
        "\t\t\t\tp1s1,\tp2s1\n"
        "\t\tPayoff:\n"
        "\t\t\t\t10.00000,\t20.00000\n"
        "\tValue:\n"
        "\t\t\t\tp1,\tp2\n"
        "\t\tPosition:\n"
        "\t\t\t\tp1s2,\tp2s1\n"
        "\t\tPayoff:\n"
        "\t\t\t\t50.00000,\t60.00000\n"
        "\tValue:\n"
        "\t\t\t\tp1,\tp2\n"
        "\t\tPosition:\n"
        "\t\t\t\tp1s1,\tp2s2\n"
        "\t\tPayoff:\n"
        "\t\t\t\t30.00000,\t40.00000\n"
        "\tValue:\n"
        "\t\t\t\tp1,\tp2\n"
        "\t\tPosition:\n"
        "\t\t\t\tp1s2,\tp2s2\n"
        "\t\tPayoff:\n"
        "\t\t\t\t70.00000,\t80.00000\n"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
