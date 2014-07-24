#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( PlayerChoiceCondition )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using boost::make_shared;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( PlayerChoiceCondition_getCondition ) {
    // given
    GT::GTL::ObjectPtr player   = make_shared<GT::GTL::IdentifierParam>( GT::createIdentifier("Player") );
    GT::GTL::ObjectPtr strategy = make_shared<GT::GTL::IdentifierParam>( GT::createIdentifier("Strategy") );

    GT::GTL::Context context;

    // when
    GT::GTL::PlayerChoiceCondition condition(
        player,
        strategy
    );

    // then
    BOOST_REQUIRE_NO_THROW( condition.getCondition(context) );
}

BOOST_AUTO_TEST_CASE( PlayerChoiceCondition_toString ) {
    // given
    GT::GTL::ObjectPtr player   = make_shared<GT::GTL::IdentifierParam>( GT::createIdentifier("Player") );
    GT::GTL::ObjectPtr strategy = make_shared<GT::GTL::IdentifierParam>( GT::createIdentifier("Strategy") );

    // when
    GT::GTL::PlayerChoiceCondition condition(
        player,
        strategy
    );

    // then
    BOOST_CHECK_EQUAL(
        condition.toString(),
        GT::Message() +
        "Condition:\n"
        "\tPlayer:\n"
        "\t\tIdentifierParam:\n"
        "\t\t\tPlayer\n"
        "\tChosen:\n"
        "\t\tIdentifierParam:\n"
        "\t\t\tStrategy\n"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
