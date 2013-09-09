#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>

#include "gt/model/common.hpp"

BOOST_AUTO_TEST_CASE( Player_getName ) {
    // given
    GT::IdentifierPtr  name(new GT::Identifier("test name"));
    GT::IdentifiersPtr strategies(new GT::Identifiers());

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
    GT::IdentifierPtr  name(new GT::Identifier("test name"));
    GT::IdentifiersPtr strategies(new GT::Identifiers());

    // when
    GT::Model::Player player(name, strategies);

    // then
    BOOST_CHECK_EQUAL_COLLECTIONS(
    	(*player.getStrategies()).begin(), (*player.getStrategies()).end(),
    	(*strategies).begin(),             (*strategies).end()
    );
}
BOOST_AUTO_TEST_CASE( Player_getStrategiesNumber ) {
    // given
    GT::IdentifierPtr  name(new GT::Identifier("test_name"));
    GT::IdentifiersPtr strategies(new GT::Identifiers());
    (*strategies).push_back(GT::IdentifierPtr(new GT::Identifier("some_strategy")));
    (*strategies).push_back(GT::IdentifierPtr(new GT::Identifier("other_strategy")));

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
    GT::IdentifierPtr  name(new GT::Identifier("test_name"));
    GT::IdentifierPtr  strategy1(new GT::Identifier("some_strategy"));
    GT::IdentifierPtr  strategy2(new GT::Identifier("other_strategy"));
    GT::IdentifiersPtr strategies(new GT::Identifiers());
    (*strategies).push_back(strategy1);
    (*strategies).push_back(strategy2);

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
}

BOOST_AUTO_TEST_CASE( Player_toString ) {
    // given
    GT::IdentifierPtr  name(new GT::Identifier("test_name"));
    GT::IdentifiersPtr strategies(new GT::Identifiers());
    (*strategies).push_back(GT::IdentifierPtr(new GT::Identifier("some_strategy")));
    (*strategies).push_back(GT::IdentifierPtr(new GT::Identifier("other_strategy")));

    // when
    GT::Model::Player player(name, strategies);

    // then
    BOOST_CHECK_EQUAL(player.toString(), GT::Message("Player:test_name{ some_strategy other_strategy }"));
}
