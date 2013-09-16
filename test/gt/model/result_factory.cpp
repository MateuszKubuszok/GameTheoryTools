#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>

#include "gt/model/inner_common.hpp"

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
    GT::Model::ResultPtr      result = factory.constResult(testMessage);

    // then
    BOOST_CHECK_EQUAL(
        result->getResult(),
        testMessage
    );
}

BOOST_AUTO_TEST_CASE( ResultFactory_emptyResult ) {
    // given

    // when
    GT::Model::ResultFactory& factory = GT::Model::ResultFactory::getInstance();
    GT::Model::ResultPtr      result = factory.emptyResult();

    // then
    BOOST_CHECK_EQUAL(
        result->getResult(),
        GT::Message("")
    );
}

BOOST_AUTO_TEST_CASE( ResultFactory_JSONResultBuilder ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::JSON)
        .setIndentationMode(GT::Model::TABS);

    GT::IdentifiersPtr properties(new GT::Identifiers());
    properties->push_back(GT::IdentifierPtr(new GT::Identifier("property1")));
    properties->push_back(GT::IdentifierPtr(new GT::Identifier("property2")));

    GT::IdentifierPtr object(new GT::Identifier("TestObject"));
    GT::MessagesPtr   results(new GT::Messages());
    results->push_back(GT::MessagePtr(new GT::Message("result1")));
    results->push_back(GT::MessagePtr(new GT::Message("result2")));

    // when
    GT::Model::ResultBuilderPtr builder = GT::Model::ResultFactory::getInstance().buildResult();
    builder->setHeaders(properties);
    builder->addRecord(object, results);

    // then
    BOOST_CHECK_EQUAL(
        builder->build()->getResult(),
        GT::Message() +
        "{\n" +
        "\t\"TestObject\" : [\n" +
        "\t\t\"property1\" : \"result1\",\n" + 
        "\t\t\"property2\" : \"result2\",\n" + 
        "\t],\n" +
        "}\n"
    );
}

BOOST_AUTO_TEST_CASE( ResultFactory_XMLResultBuilder ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::XML)
        .setIndentationMode(GT::Model::TABS);

    GT::IdentifiersPtr properties(new GT::Identifiers());
    properties->push_back(GT::IdentifierPtr(new GT::Identifier("property1")));
    properties->push_back(GT::IdentifierPtr(new GT::Identifier("property2")));

    GT::IdentifierPtr object(new GT::Identifier("TestObject"));
    GT::MessagesPtr   results(new GT::Messages());
    results->push_back(GT::MessagePtr(new GT::Message("result1")));
    results->push_back(GT::MessagePtr(new GT::Message("result2")));

    // when
    GT::Model::ResultBuilderPtr builder = GT::Model::ResultFactory::getInstance().buildResult();
    builder->setHeaders(properties);
    builder->addRecord(object, results);

    // then
    BOOST_CHECK_EQUAL(
        builder->build()->getResult(),
        GT::Message() +
        "<results>\n" +
        "\t<TestObject>\n" +
        "\t\t<result property=\"property1\" value=\"result1\" />\n" + 
        "\t\t<result property=\"property2\" value=\"result2\" />\n" + 
        "\t</TestObject>\n" +
        "</results>\n"
    );
}

BOOST_AUTO_TEST_CASE( ResultFactory_PlainResultBuilder ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::PLAIN)
        .setIndentationMode(GT::Model::TABS);

    GT::IdentifiersPtr properties(new GT::Identifiers());
    properties->push_back(GT::IdentifierPtr(new GT::Identifier("property1")));
    properties->push_back(GT::IdentifierPtr(new GT::Identifier("property2")));

    GT::IdentifierPtr object(new GT::Identifier("TestObject"));
    GT::MessagesPtr   results(new GT::Messages());
    results->push_back(GT::MessagePtr(new GT::Message("result1")));
    results->push_back(GT::MessagePtr(new GT::Message("result2")));

    // when
    GT::Model::ResultBuilderPtr builder = GT::Model::ResultFactory::getInstance().buildResult();
    builder->setHeaders(properties);
    builder->addRecord(object, results);

    // then
    BOOST_CHECK_EQUAL(
        builder->build()->getResult(),
        GT::Message() +
        "\t\tproperty1,\tproperty2,\n" +
        "TestObject:\n" +
        "\t\tresult1,\tresult2,\n"
    );
}

BOOST_AUTO_TEST_SUITE_END()
