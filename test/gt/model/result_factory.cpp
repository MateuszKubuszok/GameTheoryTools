#include "gt/model/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ResultFactory )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
    factory.setBuilderMode(GT::Model::ResultBuilderMode::XML);
    BOOST_CHECK( factory.getBuilderMode() == GT::Model::ResultBuilderMode::XML );
    factory.setBuilderMode(GT::Model::ResultBuilderMode::JSON);
    BOOST_CHECK( factory.getBuilderMode() == GT::Model::ResultBuilderMode::JSON );
    factory.setBuilderMode(GT::Model::ResultBuilderMode::PLAIN);
    BOOST_CHECK( factory.getBuilderMode() == GT::Model::ResultBuilderMode::PLAIN );
}

BOOST_AUTO_TEST_CASE( ResultFactory_indentationMode ) {
    // given

    // when
    GT::Model::ResultFactory& factory = GT::Model::ResultFactory::getInstance();

    // then
    factory.setIndentationMode(GT::Model::ResultIndentationMode::NONE);
    BOOST_CHECK( factory.getIndentationMode() == GT::Model::ResultIndentationMode::NONE );
    factory.setIndentationMode(GT::Model::ResultIndentationMode::SPACES);
    BOOST_CHECK( factory.getIndentationMode() == GT::Model::ResultIndentationMode::SPACES );
    factory.setIndentationMode(GT::Model::ResultIndentationMode::TABS);
    BOOST_CHECK( factory.getIndentationMode() == GT::Model::ResultIndentationMode::TABS );
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
        .setBuilderMode(GT::Model::ResultBuilderMode::JSON)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::IdentifiersPtr properties = GT::createIdentifiersPtr();
    properties->push_back(GT::createIdentifierPtr("property1"));
    properties->push_back(GT::createIdentifierPtr("property2"));

    GT::IdentifierPtr object  = GT::createIdentifierPtr("TestObject");
    GT::MessagesPtr   results = GT::createMessagesPtr();
    results->push_back( GT::createMessagePtr("result1") );
    results->push_back( GT::createMessagePtr("result2") );

    // when
    GT::Model::ResultBuilderPtr builder = GT::Model::ResultFactory::getInstance().buildResult();
    builder->setHeaders(properties);
    builder->addRecord(object, results);

    // then
    BOOST_CHECK_EQUAL(
        builder->build()->getResult(),
        GT::Message() +
        "{\n"
        "\t\"TestObject\" : [\n"
        "\t\t\"property1\" : \"result1\",\n"
        "\t\t\"property2\" : \"result2\"\n"
        "\t]\n"
        "}\n"
    );
}

BOOST_AUTO_TEST_CASE( ResultFactory_XMLResultBuilder ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::XML)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::IdentifiersPtr properties = GT::createIdentifiersPtr();
    properties->push_back(GT::createIdentifierPtr("property1"));
    properties->push_back(GT::createIdentifierPtr("property2"));

    GT::IdentifierPtr object  = GT::createIdentifierPtr("TestObject");
    GT::MessagesPtr   results = GT::createMessagesPtr();
    results->push_back( GT::createMessagePtr("result1") );
    results->push_back( GT::createMessagePtr("result2") );

    // when
    GT::Model::ResultBuilderPtr builder = GT::Model::ResultFactory::getInstance().buildResult();
    builder->setHeaders(properties);
    builder->addRecord(object, results);

    // then
    BOOST_CHECK_EQUAL(
        builder->build()->getResult(),
        GT::Message() +
        "<TestObject>\n"
        "\t<result property=\"property1\" value=\"result1\" />\n"
        "\t<result property=\"property2\" value=\"result2\" />\n"
        "</TestObject>\n"
    );
}

BOOST_AUTO_TEST_CASE( ResultFactory_PlainResultBuilder ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::IdentifiersPtr properties = GT::createIdentifiersPtr();
    properties->push_back(GT::createIdentifierPtr("property1"));
    properties->push_back(GT::createIdentifierPtr("property2"));

    GT::IdentifierPtr object  = GT::createIdentifierPtr("TestObject");
    GT::MessagesPtr   results = GT::createMessagesPtr();
    results->push_back( GT::createMessagePtr("result1") );
    results->push_back( GT::createMessagePtr("result2") );

    // when
    GT::Model::ResultBuilderPtr builder = GT::Model::ResultFactory::getInstance().buildResult();
    builder->setHeaders(properties);
    builder->addRecord(object, results);

    // then
    BOOST_CHECK_EQUAL(
        builder->build()->getResult(),
        GT::Message() +
        "\t\tproperty1,\tproperty2\n"
        "TestObject:\n"
        "\t\tresult1,\tresult2\n"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
