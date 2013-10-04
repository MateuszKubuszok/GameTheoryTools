#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>

#include "gt/gtl/inner_common.hpp"

BOOST_AUTO_TEST_SUITE( ObjectKnownProperties )

BOOST_AUTO_TEST_CASE( ObjectKnownProperties_findForConditions ) {
    // given
    GT::GTL::Object        object;
    GT::GTL::ContextPtr    contextPtr    = GT::GTL::NullFactory::getInstance().createContext();
    GT::GTL::Context       context       = *contextPtr;
    GT::GTL::ConditionsPtr conditionsPtr = GT::GTL::NullFactory::getInstance().createConditions();
    GT::GTL::Conditions    conditions    = *conditionsPtr;

    // when
    GT::GTL::ObjectKnownProperties property(&object);

    // then
    BOOST_CHECK_EQUAL(
        property.findForConditions(context, conditions)->getResult(),
        GT::Message() +
        "\t\tKnown Properties,\n" +
        "Property:\n" +
        "\t\tproperties,\n" +
        "Property:\n" +
        "\t\ttype,\n"
    );
}

BOOST_AUTO_TEST_SUITE_END()