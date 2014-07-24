#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( PlayerStrategiesProperty )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( PlayerStrategiesProperty_findForConditions ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);


    GT::IdentifierPtr  playerName       = GT::createIdentifierPtr("P");
    GT::IdentifiersPtr playerStrategies = GT::createIdentifiersPtr();
    playerStrategies->push_back( GT::createIdentifierPtr("1") );
    playerStrategies->push_back( GT::createIdentifierPtr("2") );
    GT::GTL::Player player(playerName, playerStrategies);

    GT::GTL::ContextPtr    contextPtr    = GT::GTL::NullFactory::getInstance().createContext();
    GT::GTL::Context       context       = *contextPtr;
    GT::GTL::ConditionsPtr conditionsPtr = GT::GTL::NullFactory::getInstance().createConditions();
    GT::GTL::Conditions    conditions    = *conditionsPtr;

    // when
    GT::GTL::PlayerStrategiesProperty property(&player);

    // then
    BOOST_CHECK_EQUAL(
        property.findForConditions(context, conditions)->getResult(),
        GT::Message() +
        "Strategies:\n"
        "\tStrategy:\n"
        "\t\t1\n"
        "\tStrategy:\n"
        "\t\t2\n"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
