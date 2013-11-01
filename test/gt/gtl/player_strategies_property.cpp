#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( PlayerStrategiesProperty )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( PlayerStrategiesProperty_findForConditions ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::GTL::ContextPtr    contextPtr    = GT::GTL::NullFactory::getInstance().createContext();
    GT::GTL::Context       context       = *contextPtr;
    GT::GTL::ConditionsPtr conditionsPtr = GT::GTL::NullFactory::getInstance().createConditions();
    GT::GTL::Conditions    conditions    = *conditionsPtr;

    GT::GTL::PlayerPtr player = GT::GTL::NullFactory::getInstance().createPlayer();

    // when
    GT::GTL::PlayerStrategiesProperty property(player.get());

    // then
    BOOST_CHECK_EQUAL(
        property.findForConditions(context, conditions)->getResult(),
        GT::Message() +
        "Strategies:\n"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
