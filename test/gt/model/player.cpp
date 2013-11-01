#include "gt/model/test_common.hpp"

BOOST_AUTO_TEST_SUITE( Player )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( Player_getName ) {
    // given
    GT::IdentifierPtr  name       = GT::createIdentifierPtr("test name");
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();

    // when
    GT::Model::Player player(name, strategies);

    // then
    BOOST_CHECK_EQUAL(
        *(player.getName()),
        *name
    );
}

BOOST_AUTO_TEST_CASE( Player_getStrategies ) {
    // given
    GT::IdentifierPtr  name       = GT::createIdentifierPtr("test name");
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();

    // when
    GT::Model::Player player(name, strategies);

    // then
    BOOST_CHECK_EQUAL_COLLECTIONS(
        player.getStrategies()->begin(), player.getStrategies()->end(),
        strategies->begin(),             strategies->end()
    );
}

BOOST_AUTO_TEST_CASE( Player_getStrategiesNumber ) {
    // given
    GT::IdentifierPtr  name       = GT::createIdentifierPtr("test_name");
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();
    strategies->push_back( GT::createIdentifierPtr("some_strategy") );
    strategies->push_back( GT::createIdentifierPtr("other_strategy") );

    // when
    GT::Model::Player player(name, strategies);

    // then
    BOOST_CHECK_EQUAL(
        player.getStrategiesNumber(),
        2
    );
}

BOOST_AUTO_TEST_CASE( Player_getStrategyOrdinal ) {
    // given
    GT::IdentifierPtr  name            = GT::createIdentifierPtr("test name");
    GT::IdentifierPtr  strategy1       = GT::createIdentifierPtr("some_strategy");
    GT::IdentifierPtr  strategy2       = GT::createIdentifierPtr("other_strategy");
    GT::IdentifierPtr  invalidStrategy = GT::createIdentifierPtr("invalid_strategy");
    GT::IdentifiersPtr strategies      = GT::createIdentifiersPtr();
    strategies->push_back(strategy1);
    strategies->push_back(strategy2);

    // when
    GT::Model::Player player(name, strategies);

    // then
    BOOST_CHECK_EQUAL(
        player.getStrategyOrdinal(*strategy1),
        0
    );
    BOOST_CHECK_EQUAL(
        player.getStrategyOrdinal(*strategy2),
        1
    );
    BOOST_CHECK_THROW(
        player.getStrategyOrdinal(*invalidStrategy),
        std::invalid_argument
    );
}

BOOST_AUTO_TEST_CASE( Player_hasStrategy ) {
    // given
    GT::IdentifierPtr  name            = GT::createIdentifierPtr("test name");
    GT::IdentifierPtr  strategy1       = GT::createIdentifierPtr("some_strategy");
    GT::IdentifierPtr  strategy2       = GT::createIdentifierPtr("other_strategy");
    GT::IdentifierPtr  invalidStrategy = GT::createIdentifierPtr("invalid_strategy");
    GT::IdentifiersPtr strategies      = GT::createIdentifiersPtr();
    strategies->push_back(strategy1);
    strategies->push_back(strategy2);

    // when
    GT::Model::Player player(name, strategies);

    // then
    BOOST_CHECK(player.hasStrategy(*strategy1));
    BOOST_CHECK(!player.hasStrategy(*invalidStrategy));
}

BOOST_AUTO_TEST_CASE( Player_toString ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::IdentifierPtr  name       = GT::createIdentifierPtr("test_name");
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();
    strategies->push_back( GT::createIdentifierPtr("some_strategy") );
    strategies->push_back( GT::createIdentifierPtr("other_strategy") );

    // when
    GT::Model::Player player(name, strategies);

    // then
    BOOST_CHECK_EQUAL(
        player.toString(),
        GT::Message() +
        "0:\n"
        "\tsome_strategy\n"
        "1:\n"
        "\tother_strategy\n"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
