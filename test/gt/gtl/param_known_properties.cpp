#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ParamKnownProperties )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( ParamKnownProperties_findForConditions ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::GTL::ObjectPtr     object(new GT::GTL::Object());
    GT::GTL::ContextPtr    contextPtr    = GT::GTL::NullFactory::getInstance().createContext();
    GT::GTL::Context       context       = *contextPtr;
    GT::GTL::ConditionsPtr conditionsPtr = GT::GTL::NullFactory::getInstance().createConditions();
    GT::GTL::Conditions    conditions    = *conditionsPtr;
    GT::GTL::ObjectParam   param(object);

    // when
    GT::GTL::ParamKnownProperties property(&param);

    // then
    BOOST_CHECK_EQUAL(
        property.findForConditions(context, conditions)->getResult(),
        GT::Message() +
        "\t\tKnown Properties\n"
        "Property:\n"
        "\t\tproperties\n"
        "Property:\n"
        "\t\ttype\n"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
