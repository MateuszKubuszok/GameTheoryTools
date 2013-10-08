#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( Definition )

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( Definition_getName ) {
    // given
    GT::IdentifierPtr name  = GT::Model::NullFactory::getInstance().createIdentifier();
    GT::GTL::ParamPtr value = GT::GTL::NullFactory::getInstance().createParam();

    // when
    GT::GTL::Definition definition(name, value);

    // when
    BOOST_CHECK_EQUAL(
        definition.getName(),
        name
    );
}

BOOST_AUTO_TEST_CASE( Definition_getValue ) {
    // given
    GT::IdentifierPtr name  = GT::Model::NullFactory::getInstance().createIdentifier();
    GT::GTL::ParamPtr value = GT::GTL::NullFactory::getInstance().createParam();

    // when
    GT::GTL::Definition definition(name, value);

    // when
    BOOST_CHECK_EQUAL(
        definition.getValue(),
        value
    );
}

BOOST_AUTO_TEST_CASE( Definition_toString ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);
    
    GT::IdentifierPtr name  = GT::Model::NullFactory::getInstance().createIdentifier();
    GT::GTL::ParamPtr value = GT::GTL::NullFactory::getInstance().createParam();

    // when
    GT::GTL::Definition definition(name, value);

    // when
    BOOST_CHECK_EQUAL(
        definition.toString(),
        GT::Message() +
        "NullIdentifier:\n"
        "\tNullParam\n"
    );
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()