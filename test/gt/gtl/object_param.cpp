#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>

#include "gt/gtl/inner_common.hpp"

BOOST_AUTO_TEST_SUITE( ObjectParam )

BOOST_AUTO_TEST_CASE( ObjectParam_functional ) {
    // given
    GT::GTL::ContextPtr contextPtr = GT::GTL::NullFactory::getInstance().createContext();
    GT::GTL::Context&   context    = *contextPtr;
    GT::GTL::ObjectPtr  objectPtr  = GT::GTL::NullFactory::getInstance().createObject();
    
    // when
    GT::GTL::ParamPtr param(new GT::GTL::ObjectParam(objectPtr));

    // then
    BOOST_REQUIRE_THROW(
        param->getNumber(context),
        GT::GTL::InvalidContentRequest
    );
    BOOST_REQUIRE_NO_THROW(param->getObject(context));
    BOOST_CHECK_EQUAL(
        objectPtr,
        param->getObject(context)
    );
}

BOOST_AUTO_TEST_CASE( ObjectParam_toString ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setIndentationMode(GT::Model::TABS)
        .setBuilderMode(GT::Model::PLAIN);

    GT::GTL::ObjectPtr objectPtr  = GT::GTL::NullFactory::getInstance().createObject();
    
    // when
    GT::GTL::ParamPtr param(new GT::GTL::ObjectParam(objectPtr));

    // then
    BOOST_CHECK_EQUAL(
        param->toString(),
        GT::Message() +
        "ObjectParam:\n"
        "\tNullObject\n" 
    );
}

BOOST_AUTO_TEST_SUITE_END()
