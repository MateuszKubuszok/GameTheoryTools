#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( GamePureEquilibriumProperty )

BOOST_AUTO_TEST_CASE( GamePureEquilibriumProperty_findForConditions ) {
    // given
    GT::GTL::ContextPtr    contextPtr    = GT::GTL::NullFactory::getInstance().createContext();
    GT::GTL::Context       context       = *contextPtr;
    GT::GTL::ConditionsPtr conditionsPtr = GT::GTL::NullFactory::getInstance().createConditions();
    GT::GTL::Conditions    conditions    = *conditionsPtr;

    GT::GTL::GamePtr game = GT::GTL::NullFactory::getInstance().createGame();

    // when
    GT::GTL::GamePureEquilibriumProperty property(game.get());

    // then
    BOOST_CHECK_EQUAL(
        game->pureEquilibrium(context, conditions)->getResult(),
        property.findForConditions(context, conditions)->getResult()
    );
}

BOOST_AUTO_TEST_SUITE_END()
