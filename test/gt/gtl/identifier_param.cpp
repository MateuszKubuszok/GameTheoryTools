#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( IdentifierParam )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( IdentifierParam_functional ) {
    // given
    GT::GTL::ContextPtr contextPtr = GT::GTL::NullFactory::getInstance().createContext();
    GT::GTL::Context&   context    = *contextPtr;
    GT::Identifier      mockID     = GT::createIdentifier("mockID");

    // when
    GT::GTL::ParamPtr param(new GT::GTL::IdentifierParam(mockID));

    // then
    BOOST_REQUIRE_NO_THROW(param->getNumber(context));
    BOOST_REQUIRE_NO_THROW(param->getObject(context));
}

BOOST_AUTO_TEST_CASE( IdentifierParam_toString ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::GTL::ContextPtr contextPtr = GT::GTL::NullFactory::getInstance().createContext();
    GT::GTL::Context&   context    = *contextPtr;
    GT::Identifier      mockID     = GT::createIdentifier("mockID");

    // when
    GT::GTL::ParamPtr param(new GT::GTL::IdentifierParam(mockID));

    // then
    BOOST_REQUIRE_NO_THROW(param->getNumber(context));
    BOOST_CHECK_EQUAL(
        *param->getNumber(context),
        *GT::Model::NullFactory::getInstance().createNumber()
    );
    BOOST_REQUIRE_NO_THROW(param->getObject(context));
    BOOST_CHECK_EQUAL(
        param->getObject(context)->toString(),
        GT::GTL::NullFactory::getInstance().createObject()->toString()
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
