#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( CurrentContextValuesProperty )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( CurrentContextValuesProperty_functional ) {
    // given
    GT::GTL::ContextPtr    contextPtr    = GT::GTL::NullFactory::getInstance().createContext();
    GT::GTL::Context       context       = *contextPtr;
    GT::GTL::ConditionsPtr conditionsPtr = GT::GTL::NullFactory::getInstance().createConditions();
    GT::GTL::Conditions    conditions    = *conditionsPtr;

    // when
    GT::GTL::CurrentContextValuesProperty currentContextValuesProperty(contextPtr.get());

    // then
    BOOST_CHECK_EQUAL(
        currentContextValuesProperty.findForConditions(context, conditions)->getResult(),
        GT::Message() +
        "context:\n"
        "\tObjectParam:\n"
        "\t\tContext\n"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
