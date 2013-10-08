#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( PlayerNameProperty )

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( PlayerNameProperty_findForConditions ) {
    // given
    GT::GTL::ContextPtr    contextPtr    = GT::GTL::NullFactory::getInstance().createContext();
    GT::GTL::Context       context       = *contextPtr;
    GT::GTL::ConditionsPtr conditionsPtr = GT::GTL::NullFactory::getInstance().createConditions();
    GT::GTL::Conditions    conditions    = *conditionsPtr;

    GT::GTL::PlayerPtr player = GT::GTL::NullFactory::getInstance().createPlayer();

    // when
    GT::GTL::PlayerNameProperty property(player.get());

    // then
    BOOST_CHECK_EQUAL(
        property.findForConditions(context, conditions)->getResult(),
        GT::Message() +
        "Name:\n"
        "\tNullIdentifier\n"
    );
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
