#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( PlayerChoiceCondition )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( PlayerChoiceCondition_getCondition ) {
    // given
    GT::GTL::ObjectPtr player(new GT::GTL::IdentifierParam( GT::createIdentifier("Player") ));
    GT::GTL::ObjectPtr strategy(new GT::GTL::IdentifierParam( GT::createIdentifier("Strategy") ));

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
    GT::GTL::ObjectPtr player(new GT::GTL::IdentifierParam( GT::createIdentifier("Player") ));
    GT::GTL::ObjectPtr strategy(new GT::GTL::IdentifierParam( GT::createIdentifier("Strategy") ));

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
