#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>

#include "gt/gtl/inner_common.hpp"

BOOST_AUTO_TEST_SUITE( Player )

BOOST_AUTO_TEST_CASE( Player_respondsTo ) {
    // given
    GT::Identifier properties = "properties";
    GT::Identifier type       = "type";
    GT::Identifier name       = "name";
    GT::Identifier strategies = "strategies";
    GT::Identifier error      = "error";

    GT::IdentifierPtr  playerName       = GT::Model::NullFactory::getInstance().createIdentifier();
    GT::IdentifiersPtr playerStrategies = GT::Model::NullFactory::getInstance().createIdentifiers();

    // when
    GT::GTL::Player player(playerName, playerStrategies);

    // then
    BOOST_CHECK(  player.respondsTo(properties) );
    BOOST_CHECK(  player.respondsTo(type) );
    BOOST_CHECK(  player.respondsTo(name) );
    BOOST_CHECK(  player.respondsTo(strategies) );
    BOOST_CHECK( !player.respondsTo(error) );
}

BOOST_AUTO_TEST_SUITE_END()
