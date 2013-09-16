#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>

#include "gt/model/inner_common.hpp"

BOOST_AUTO_TEST_SUITE( JSONResultBuilder )

BOOST_AUTO_TEST_CASE( JSONResultBuilder_build ) {
    // given
    GT::IdentifiersPtr properties(new GT::Identifiers());
    properties->push_back(GT::IdentifierPtr(new GT::Identifier("property1")));
    properties->push_back(GT::IdentifierPtr(new GT::Identifier("property2")));

    GT::IdentifierPtr object(new GT::Identifier("TestObject"));
    GT::MessagesPtr   results(new GT::Messages());
    results->push_back(GT::MessagePtr(new GT::Message("result1")));
    results->push_back(GT::MessagePtr(new GT::Message("result2")));

    // when
    GT::Model::ResultBuilderPtr builder(new GT::Model::JSONResultBuilder(GT::Message("\t")));
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

BOOST_AUTO_TEST_SUITE_END()
