#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ParamFactory )

BOOST_AUTO_TEST_CASE( ParamFactory_createParam ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setIndentationMode(GT::Model::TABS)
        .setBuilderMode(GT::Model::PLAIN);
    
    GT::IdentifierPtr  identifier = GT::Model::NullFactory::getInstance().createIdentifier();
    GT::NumberPtr      number     = GT::Model::NullFactory::getInstance().createNumber();
    GT::GTL::ObjectPtr object     = GT::GTL::NullFactory::getInstance().createObject();

    // when
    GT::GTL::ParamPtr identifierParam = GT::GTL::ParamFactory::getInstance().createParam(identifier);
    GT::GTL::ParamPtr numberParam     = GT::GTL::ParamFactory::getInstance().createParam(number);
    GT::GTL::ParamPtr objectParam     = GT::GTL::ParamFactory::getInstance().createParam(object);

    // then
    BOOST_CHECK_EQUAL(
        identifierParam->toString(),
        GT::Message() +
        "IdentifierParam:\n"
        "\tNullIdentifier\n"
    );
    BOOST_CHECK_EQUAL(
        numberParam->toString(),
        GT::Message() +
        "NumberParam:\n"
        "\t0\n"
    );
    BOOST_CHECK_EQUAL(
        objectParam->toString(),
        GT::Message() +
        "ObjectParam:\n"
        "\tNullObject\n"
    );
}

BOOST_AUTO_TEST_SUITE_END()
