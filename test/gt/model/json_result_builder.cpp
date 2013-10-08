#include "gt/model/test_common.hpp"

BOOST_AUTO_TEST_SUITE( JSONResultBuilder )

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( JSONResultBuilder_build ) {
    // given
    GT::IdentifiersPtr properties = GT::createIdentifiersPtr();
    properties->push_back(GT::createIdentifierPtr("property1"));
    properties->push_back(GT::createIdentifierPtr("property2"));

    GT::IdentifierPtr object  = GT::createIdentifierPtr("TestObject");
    GT::MessagesPtr   results = GT::createMessagesPtr();
    results->push_back( GT::createMessagePtr("result1") );
    results->push_back( GT::createMessagePtr("result2") );

    GT::IdentifierPtr name   = GT::createIdentifierPtr("name");
    GT::MessagePtr    result = GT::createMessagePtr("result");

    // when
    GT::Model::ResultBuilderPtr builder(new GT::Model::JSONResultBuilder(GT::createMessage("\t")));
    builder->setHeaders(properties);
    builder->addRecord(object, results);
    builder->addResult(name, result);

    // then
    BOOST_CHECK_EQUAL(
        builder->build()->getResult(),
        GT::Message() +
        "{\n"
        "\t\"TestObject\" : [\n"
        "\t\t\"property1\" : \"result1\",\n"
        "\t\t\"property2\" : \"result2\",\n"
        "\t],\n"
        "\t\"name\" : result,\n"
        "}\n"
    );
}

BOOST_AUTO_TEST_CASE( JSONResultBuilder_buildRaw ) {
    // given
    GT::IdentifiersPtr properties = GT::createIdentifiersPtr();
    properties->push_back(GT::createIdentifierPtr("property1"));
    properties->push_back(GT::createIdentifierPtr("property2"));

    GT::IdentifierPtr object  = GT::createIdentifierPtr("TestObject");
    GT::MessagesPtr   results = GT::createMessagesPtr();
    results->push_back( GT::createMessagePtr("result1") );
    results->push_back( GT::createMessagePtr("result2") );

    GT::IdentifierPtr name   = GT::createIdentifierPtr("name");
    GT::MessagePtr    result = GT::createMessagePtr("result");

    // when
    GT::Model::ResultBuilderPtr builder(new GT::Model::JSONResultBuilder(GT::createMessage("\t")));
    builder->setHeaders(properties);
    builder->addRecord(object, results);
    builder->addResult(name, result);

    // then
    BOOST_CHECK_EQUAL(
        builder->buildRaw()->getResult(),
        GT::Message() +
        "\"TestObject\" : [\n"
        "\t\"property1\" : \"result1\",\n"
        "\t\"property2\" : \"result2\",\n"
        "],\n"
        "\"name\" : result,\n"
    );
}

BOOST_AUTO_TEST_CASE( JSONResultBuilder_throwExceptionOnError ) {
    // given
    GT::IdentifiersPtr properties = GT::createIdentifiersPtr();
    properties->push_back(GT::createIdentifierPtr("property1"));
    properties->push_back(GT::createIdentifierPtr("property2"));

    GT::IdentifierPtr object  = GT::createIdentifierPtr("TestObject");
    GT::MessagesPtr   results = GT::createMessagesPtr();
    results->push_back( GT::createMessagePtr("result1") );

    // when
    GT::Model::ResultBuilderPtr builder(new GT::Model::JSONResultBuilder(GT::createMessage("\t")));
    builder->setHeaders(properties);
    builder->addRecord(object, results);

    // then
    BOOST_CHECK_THROW(
        builder->build(),
        GT::Model::IllegalInnerState
    );
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
