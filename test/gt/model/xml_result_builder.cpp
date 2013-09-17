#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>

#include "gt/model/inner_common.hpp"

BOOST_AUTO_TEST_SUITE( XMLResultBuilder )

BOOST_AUTO_TEST_CASE( XMLResultBuilder_build ) {
    // given
    GT::IdentifiersPtr properties(new GT::Identifiers());
    properties->push_back(GT::IdentifierPtr(new GT::Identifier("property1")));
    properties->push_back(GT::IdentifierPtr(new GT::Identifier("property2")));

    GT::IdentifierPtr object(new GT::Identifier("TestObject"));
    GT::MessagesPtr   results(new GT::Messages());
    results->push_back(GT::MessagePtr(new GT::Message("result1")));
    results->push_back(GT::MessagePtr(new GT::Message("result2")));

    GT::IdentifierPtr name(new GT::Identifier("name"));
    GT::MessagePtr    result(new GT::Message("result"));

    // when
    GT::Model::ResultBuilderPtr builder(new GT::Model::XMLResultBuilder(GT::Message("\t")));
    builder->setHeaders(properties);
    builder->addRecord(object, results);
    builder->addResult(name, result);

    // then
    BOOST_CHECK_EQUAL(
        builder->build()->getResult(),
        GT::Message() +
        "<results>\n" +
        "\t<TestObject>\n" +
        "\t\t<result property=\"property1\" value=\"result1\" />\n" + 
        "\t\t<result property=\"property2\" value=\"result2\" />\n" + 
        "\t</TestObject>\n" +
        "\t<name>\n" + 
        "\t\tresult\n" + 
        "\t</name>\n" + 
        "</results>\n"
    );
}

BOOST_AUTO_TEST_CASE( XMLResultBuilder_buildRaw ) {
    // given
    GT::IdentifiersPtr properties(new GT::Identifiers());
    properties->push_back(GT::IdentifierPtr(new GT::Identifier("property1")));
    properties->push_back(GT::IdentifierPtr(new GT::Identifier("property2")));

    GT::IdentifierPtr object(new GT::Identifier("TestObject"));
    GT::MessagesPtr   results(new GT::Messages());
    results->push_back(GT::MessagePtr(new GT::Message("result1")));
    results->push_back(GT::MessagePtr(new GT::Message("result2")));

    GT::IdentifierPtr name(new GT::Identifier("name"));
    GT::MessagePtr    result(new GT::Message("result"));

    // when
    GT::Model::ResultBuilderPtr builder(new GT::Model::XMLResultBuilder(GT::Message("\t")));
    builder->setHeaders(properties);
    builder->addRecord(object, results);
    builder->addResult(name, result);

    // then
    BOOST_CHECK_EQUAL(
        builder->buildRaw()->getResult(),
        GT::Message() +
        "<TestObject>\n" +
        "\t<result property=\"property1\" value=\"result1\" />\n" + 
        "\t<result property=\"property2\" value=\"result2\" />\n" + 
        "</TestObject>\n" +
        "<name>\n" + 
        "\tresult\n" + 
        "</name>\n"
    );
}

BOOST_AUTO_TEST_SUITE_END()
