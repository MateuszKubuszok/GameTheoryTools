#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ExceptionFactory )

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( ExceptionFactory_cyclicIdentifiersFound ) {
    // given
    GT::Identifier identifier1 = GT::createIdentifier("identifier1");
    GT::Identifier identifier2 = GT::createIdentifier("identifier2");
    GT::GTL::Param::VisitedIdentifiers visitedIdentifiers;
    visitedIdentifiers.insert(identifier1);
    visitedIdentifiers.insert(identifier2);

    // when
    GT::GTL::CyclicIdentifiers exception = GT::GTL::ExceptionFactory::getInstance()
                                               .cyclicIdentifiersFound(visitedIdentifiers, identifier1);

    // then
    BOOST_CHECK_EQUAL(
        exception.what(),
        GT::Message() +
        "Cyclic Identifiers found in list:\n"
        "\t'identifier1'\n"
        "\t'identifier2'\n"
        "identifier 'identifier1' already defined"
    );
}

BOOST_AUTO_TEST_CASE( ExceptionFactory_invalidObjectProperty ) {
    // given
    GT::Identifier identifier = GT::createIdentifier("identifier");

    // when
    GT::GTL::InvalidProperty exception = GT::GTL::ExceptionFactory::getInstance()
                                            .invalidObjectProperty(identifier);

    // then
    BOOST_CHECK_EQUAL(
        exception.what(),
        GT::Message() +
        "Property 'identifier' not defined"
    );
}

BOOST_AUTO_TEST_CASE( ExceptionFactory_notDefinedParam ) {
    // given
    GT::Identifier identifier = GT::createIdentifier("identifier");

    // when
    GT::GTL::NotDefinedParam exception = GT::GTL::ExceptionFactory::getInstance()
                                            .notDefinedParam(identifier);

    // then
    BOOST_CHECK_EQUAL(
        exception.what(),
        GT::Message() +
        "Param 'identifier' not defined"
    );
}

BOOST_AUTO_TEST_CASE( ExceptionFactory_requiredUnavailableNumberFromParam ) {
    // given
    // when
    GT::GTL::InvalidContentRequest exception = GT::GTL::ExceptionFactory::getInstance()
                                                   .requiredUnavailableNumberFromParam();

    // then
    BOOST_CHECK_EQUAL(
        exception.what(),
        GT::Message() +
        "Cannot obtain Number from this Param"
    );
}

BOOST_AUTO_TEST_CASE( ExceptionFactory_requiredUnavailableObjectFromParam ) {
    // given
    // when
    GT::GTL::InvalidContentRequest exception = GT::GTL::ExceptionFactory::getInstance()
                                                   .requiredUnavailableObjectFromParam();

    // then
    BOOST_CHECK_EQUAL(
        exception.what(),
        GT::Message() +
        "Cannot obtain Object from this Param"
    );
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
