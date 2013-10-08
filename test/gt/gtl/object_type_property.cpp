#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ObjectTypeProperty )

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( ObjectTypeProperty_findForConditions ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);
    
    GT::GTL::Object        object;
    GT::GTL::ContextPtr    contextPtr    = GT::GTL::NullFactory::getInstance().createContext();
    GT::GTL::Context       context       = *contextPtr;
    GT::GTL::ConditionsPtr conditionsPtr = GT::GTL::NullFactory::getInstance().createConditions();
    GT::GTL::Conditions    conditions    = *conditionsPtr;

    // when
    GT::GTL::ObjectTypeProperty property(&object);

    // then
    BOOST_CHECK_EQUAL(
        property.findForConditions(context, conditions)->getResult(),
        GT::Message() +
        "Type:\n"
        "\tObject\n"
    );
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
