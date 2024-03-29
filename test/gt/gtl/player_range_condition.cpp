#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( PlayerRangeCondition )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using boost::make_shared;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( PlayerRangeCondition_getCondition ) {
    // given
    GT::GTL::ObjectPtr  player     = make_shared<GT::GTL::IdentifierParam>( GT::createIdentifier("Player") );
    GT::GTL::ObjectsPtr strategies = make_shared<GT::GTL::Objects>();
    strategies->push_back(
        make_shared<GT::GTL::IdentifierParam>(GT::createIdentifier("Strategy 1"))
    );
    strategies->push_back(
        make_shared<GT::GTL::IdentifierParam>(GT::createIdentifier("Strategy 2"))
    );

    GT::GTL::Context context;

    // when
    GT::GTL::PlayerRangeCondition condition(
        player,
        strategies
    );

    // then
    BOOST_REQUIRE_NO_THROW( condition.getCondition(context) );
}

BOOST_AUTO_TEST_CASE( PlayerRangeCondition_toString ) {
    // given
    GT::GTL::ObjectPtr  player     = make_shared<GT::GTL::IdentifierParam>( GT::createIdentifier("Player") );
    GT::GTL::ObjectsPtr strategies = make_shared<GT::GTL::Objects>();
    strategies->push_back(
        make_shared<GT::GTL::IdentifierParam>(GT::createIdentifier("Strategy 1"))
    );
    strategies->push_back(
        make_shared<GT::GTL::IdentifierParam>(GT::createIdentifier("Strategy 2"))
    );

    // when
    GT::GTL::PlayerRangeCondition condition(
        player,
        strategies
    );

    // then
    BOOST_CHECK_EQUAL(
        condition.toString(),
        GT::Message() +
        "Condition:\n"
        "\tPlayer:\n"
        "\t\tIdentifierParam:\n"
        "\t\t\tPlayer\n"
        "\tAllowed:\n"
        "\t\t1:\n"
        "\t\t\tIdentifierParam:\n"
        "\t\t\t\tStrategy 1\n"
        "\t\t2:\n"
        "\t\t\tIdentifierParam:\n"
        "\t\t\t\tStrategy 2\n"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
