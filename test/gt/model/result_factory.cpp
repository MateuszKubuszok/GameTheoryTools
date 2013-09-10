#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>

#include "gt/model/common.hpp"

BOOST_AUTO_TEST_SUITE( ResultFactory )

BOOST_AUTO_TEST_CASE( ResultFactory_getInstance ) {
    // given

    // when

    // then
    BOOST_CHECK_NO_THROW(
        GT::Model::ResultFactory::getInstance()
    );
}

BOOST_AUTO_TEST_CASE( ResultFactory_builderMode ) {
    // given

    // when
    GT::Model::ResultFactory& factory = GT::Model::ResultFactory::getInstance();

    // then
    factory.setBuilderMode(GT::Model::XML);
    BOOST_CHECK_EQUAL(
        factory.getBuilderMode(),
        GT::Model::XML
    );
    factory.setBuilderMode(GT::Model::JSON);
    BOOST_CHECK_EQUAL(
        factory.getBuilderMode(),
        GT::Model::JSON
    );
    factory.setBuilderMode(GT::Model::PLAIN);
    BOOST_CHECK_EQUAL(
        factory.getBuilderMode(),
        GT::Model::PLAIN
    );
}

BOOST_AUTO_TEST_CASE( ResultFactory_indentationMode ) {
    // given

    // when
    GT::Model::ResultFactory& factory = GT::Model::ResultFactory::getInstance();

    // then
    factory.setIndentationMode(GT::Model::NONE);
    BOOST_CHECK_EQUAL(
        factory.getIndentationMode(),
        GT::Model::NONE
    );
    factory.setIndentationMode(GT::Model::SPACES);
    BOOST_CHECK_EQUAL(
        factory.getIndentationMode(),
        GT::Model::SPACES
    );
    factory.setIndentationMode(GT::Model::TABS);
    BOOST_CHECK_EQUAL(
        factory.getIndentationMode(),
        GT::Model::TABS
    );
}

BOOST_AUTO_TEST_CASE( ResultFactory_constResult ) {
    // given
    GT::Message testMessage("testMessage");

    // when
    GT::Model::ResultFactory& factory = GT::Model::ResultFactory::getInstance();
    GT::Model::ResultPtr result = factory.constResult(testMessage);

    // then
    BOOST_CHECK_EQUAL(
        (*result).getResult(),
        testMessage
    );
}

BOOST_AUTO_TEST_CASE( ResultFactory_emptyResult ) {
    // given

    // when
    GT::Model::ResultFactory& factory = GT::Model::ResultFactory::getInstance();
    GT::Model::ResultPtr result = factory.emptyResult();

    // then
    BOOST_CHECK_EQUAL(
        (*result).getResult(),
        GT::Message("")
    );
}

BOOST_AUTO_TEST_SUITE_END()
