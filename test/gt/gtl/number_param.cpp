#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( NumberParam )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( NumberParam_functional ) {
    // given
    GT::GTL::ContextPtr contextPtr = GT::GTL::NullFactory::getInstance().createContext();
    GT::GTL::Context&   context    = *contextPtr;
    GT::NumberPtr       numberPtr  = GT::Model::NullFactory::getInstance().createNumber();

    // when
    GT::GTL::ParamPtr param(new GT::GTL::NumberParam(numberPtr));

    // then
    BOOST_REQUIRE_NO_THROW(param->getNumber(context));
    BOOST_CHECK_EQUAL(
        numberPtr,
        param->getNumber(context)
    );
    BOOST_REQUIRE_THROW(
        param->getObject(context),
        GT::GTL::InvalidContentRequest
    );
}

BOOST_AUTO_TEST_CASE( NumberParam_serialize ) {
    // given
    GT::NumberPtr numberPtr  = GT::Model::NullFactory::getInstance().createNumber();

    // when
    GT::GTL::ParamPtr param(new GT::GTL::NumberParam(numberPtr));

    // then
    BOOST_CHECK_EQUAL(
        param->serialize(),
        GT::Message() +
        "0.00000"
    );
}

BOOST_AUTO_TEST_CASE( NumberParam_toString ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::NumberPtr numberPtr  = GT::Model::NullFactory::getInstance().createNumber();

    // when
    GT::GTL::ParamPtr param(new GT::GTL::NumberParam(numberPtr));

    // then
    BOOST_CHECK_EQUAL(
        param->toString(),
        GT::Message() +
        "NumberParam:\n"
        "\t0.00000\n"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
