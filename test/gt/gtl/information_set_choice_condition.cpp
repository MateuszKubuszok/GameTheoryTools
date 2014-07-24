#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( InformationSetChoiceCondition )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using boost::make_shared;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( InformationSetChoiceCondition_getCondition ) {
    // given
    GT::GTL::ObjectPtr player         = make_shared<GT::GTL::IdentifierParam>( GT::createIdentifier("Player") );
    GT::GTL::ObjectPtr informationSet = make_shared<GT::GTL::IdentifierParam>( GT::createIdentifier("InformationSet") );
    GT::GTL::ObjectPtr strategy       = make_shared<GT::GTL::IdentifierParam>( GT::createIdentifier("Strategy") );

    GT::GTL::Context context;

    // when
    GT::GTL::InformationSetChoiceCondition condition(
        player,
        informationSet,
        strategy
    );

    // then
    BOOST_REQUIRE_NO_THROW( condition.getCondition(context) );
}

BOOST_AUTO_TEST_CASE( InformationSetChoiceCondition_toString ) {
    // given
    GT::GTL::ObjectPtr player         = make_shared<GT::GTL::IdentifierParam>( GT::createIdentifier("Player") );
    GT::GTL::ObjectPtr informationSet = make_shared<GT::GTL::IdentifierParam>( GT::createIdentifier("InformationSet") );
    GT::GTL::ObjectPtr strategy       = make_shared<GT::GTL::IdentifierParam>( GT::createIdentifier("Strategy") );

    // when
    GT::GTL::InformationSetChoiceCondition condition(
        player,
        informationSet,
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
        "\tInformation Set:\n"
        "\t\tIdentifierParam:\n"
        "\t\t\tInformationSet\n"
        "\tChosen:\n"
        "\t\tIdentifierParam:\n"
        "\t\t\tStrategy\n"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
