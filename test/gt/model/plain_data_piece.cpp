#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>

#include "gt/model/inner_common.hpp"

BOOST_AUTO_TEST_SUITE( PlainDataPiece )

BOOST_AUTO_TEST_CASE( PlainDataPiece_getValue ) {
    // given
    GT::Identifier player1("player1");
    GT::Identifier player2("player2");

    GT::Model::IdentifierMap playersMap;
    playersMap.insert( GT::Model::IdentifierMap::value_type(player1, 0) );
    playersMap.insert( GT::Model::IdentifierMap::value_type(player2, 1) );

    GT::NumbersPtr numbers(new GT::Numbers());
    numbers->push_back( GT::NumberPtr(new GT::Number(10)) );
    numbers->push_back( GT::NumberPtr(new GT::Number(100)) );

    // when
    GT::Model::PlainDataPiece piece(playersMap, numbers);
    GT::Message player1msg = piece.getValue(player1)->get_str();
    GT::Message player2msg = piece.getValue(player2)->get_str();

    // then
    BOOST_CHECK_EQUAL(
        player1msg,
        GT::Message("10")
    );
    BOOST_CHECK_EQUAL(
        player2msg,
        GT::Message("100")
    );
}

BOOST_AUTO_TEST_CASE( PlainDataPiece_throwExceptionOnInvalidPlayer ) {
    // given
    GT::Identifier player1("player1");
    GT::Identifier player2("player2");
    GT::Identifier player3("player3");

    GT::Model::IdentifierMap playersMap;
    playersMap.insert( GT::Model::IdentifierMap::value_type(player1, 0) );
    playersMap.insert( GT::Model::IdentifierMap::value_type(player2, 1) );

    GT::NumbersPtr numbers(new GT::Numbers());
    numbers->push_back( GT::NumberPtr(new GT::Number(10)) );
    numbers->push_back( GT::NumberPtr(new GT::Number(100)) );

    // when
    GT::Model::PlainDataPiece piece(playersMap, numbers);

    // then
    BOOST_CHECK_THROW(
        piece.getValue(player3),
        GT::Model::InvalidCoordinate
    );
}

BOOST_AUTO_TEST_CASE( PlainDataPiece_toString ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::PLAIN)
        .setIndentationMode(GT::Model::TABS);

    GT::Identifier player1("player1");
    GT::Identifier player2("player2");

    GT::Model::IdentifierMap playersMap;
    playersMap.insert( GT::Model::IdentifierMap::value_type(player1, 0) );
    playersMap.insert( GT::Model::IdentifierMap::value_type(player2, 1) );

    GT::NumbersPtr numbers(new GT::Numbers());
    numbers->push_back( GT::NumberPtr(new GT::Number(10)) );
    numbers->push_back( GT::NumberPtr(new GT::Number(100)) );

    // when
    GT::Model::PlainDataPiece piece(playersMap, numbers);

    // then
    BOOST_CHECK_EQUAL(
        piece.toString(),
        GT::Message() +
        "\t\tplayer1,\tplayer2,\n" +
        "Payoff:\n" +
        "\t\t10,\t100,\n"
    );
}

BOOST_AUTO_TEST_SUITE_END()
