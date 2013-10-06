#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>

#include "gt/gtl/inner_common.hpp"

BOOST_AUTO_TEST_SUITE( Definition )

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
    GT::IdentifierPtr name  = GT::Model::NullFactory::getInstance().createIdentifier();
    GT::GTL::ParamPtr value = GT::GTL::NullFactory::getInstance().createParam();

    // when
    GT::GTL::Definition definition(name, value);

    // when
    BOOST_CHECK_EQUAL(
        definition.toString(),
        GT::Message() +
        "NullIdentifier:\n" +
        "\tNullParam\n"
    );
}

BOOST_AUTO_TEST_SUITE_END()