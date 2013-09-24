#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>

#include "gt/model/inner_common.hpp"

BOOST_AUTO_TEST_SUITE( StrategicGameBuilder )

class StrategicGameBuilderTestImpl : public GT::Model::StrategicGameBuilder {
public:
    virtual GT::Model::GamePtr build() {
        return GT::Model::NullFactory::getInstance().createGame();
    }

    virtual GT::Message toString() {
        return GT::Message("TestStrategicGameBuilder");
    }
};

BOOST_AUTO_TEST_CASE( StrategicGameBuilder_setPlayers ) {
    // given
    GT::IdentifierPtr  playerName = GT::createIdentifierPtr("p1"); 
    GT::IdentifierPtr  strategy1  = GT::createIdentifierPtr("p1s1"); 
    GT::IdentifierPtr  strategy2  = GT::createIdentifierPtr("p1s2");
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();
    strategies->push_back( strategy1 );
    strategies->push_back( strategy2 );
    GT::Model::PlayerPtr  player(new GT::Model::Player(playerName, strategies));
    GT::Model::PlayersPtr players(new GT::Model::Players());
    players->insert( GT::Model::Players::value_type( *playerName, player) );

    // when
    StrategicGameBuilderTestImpl strategicGameBuilder;
    strategicGameBuilder.setPlayers(players);
    GT::Model::PlayersPtr gotPlayers =
        boost::dynamic_pointer_cast<GT::Model::StrategicDataBuilder>(
            strategicGameBuilder.dataBuilder()
        )->getPlayers();

    // then
    BOOST_CHECK_EQUAL(
        players,
        gotPlayers
    );
}

BOOST_AUTO_TEST_CASE( StrategicGameBuilder_functional ) {
    // given
    GT::IdentifierPtr  playerName = GT::createIdentifierPtr("p1"); 
    GT::IdentifierPtr  strategy1  = GT::createIdentifierPtr("p1s1"); 
    GT::IdentifierPtr  strategy2  = GT::createIdentifierPtr("p1s2");
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();
    strategies->push_back( strategy1 );
    strategies->push_back( strategy2 );
    GT::Model::PlayerPtr  player(new GT::Model::Player(playerName, strategies));
    GT::Model::PlayersPtr players(new GT::Model::Players());
    players->insert( GT::Model::Players::value_type( *playerName, player) );
    
    GT::NumbersPtr params1 = GT::createNumbersPtr();
    params1->push_back( GT::createNumberPtr(10) );
    GT::NumbersPtr params2 = GT::createNumbersPtr();
    params2->push_back( GT::createNumberPtr(20) );
    
    GT::PositionsPtr positions1 = GT::createPositionsPtr();
    positions1->insert( GT::Positions::value_type( *playerName, *strategy1 ) );
    GT::PositionsPtr positions2 = GT::createPositionsPtr();
    positions2->insert( GT::Positions::value_type( *playerName, *strategy2 ) );

    // when
    StrategicGameBuilderTestImpl strategicGameBuilder;
    strategicGameBuilder.setPlayers(players);
    
    strategicGameBuilder.clone()->addNextPositions(positions1).setParams(params1);
    strategicGameBuilder.clone()->addNextPositions(positions2).setParams(params2);

    GT::Model::DataPtr data = 
        boost::dynamic_pointer_cast<GT::Model::StrategicDataBuilder>(
            strategicGameBuilder.dataBuilder()
        )->getData();

    // then
    BOOST_CHECK_EQUAL(
        data->toString(),
        GT::Message() +
        "Value:\n" +
        "\t\t\tp1,\n" +
        "\tPosition:\n" +
        "\t\t\tp1s1,\n" +
        "\tPayoff:\n" +
        "\t\t\t10,\n" +
        "Value:\n" +
        "\t\t\tp1,\n" +
        "\tPosition:\n" +
        "\t\t\tp1s2,\n" +
        "\tPayoff:\n" +
        "\t\t\t20,\n"
    );
}

BOOST_AUTO_TEST_SUITE_END()
