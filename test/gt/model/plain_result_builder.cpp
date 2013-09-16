#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>

#include "gt/model/inner_common.hpp"

BOOST_AUTO_TEST_SUITE( PlainResultBuilder )

BOOST_AUTO_TEST_CASE( PlainResultBuilder_build ) {
    // given
    GT::IdentifiersPtr properties(new GT::Identifiers());
    properties->push_back(GT::IdentifierPtr(new GT::Identifier("property1")));
    properties->push_back(GT::IdentifierPtr(new GT::Identifier("property2")));

    GT::IdentifierPtr object(new GT::Identifier("TestObject"));
    GT::MessagesPtr   results(new GT::Messages());
    results->push_back(GT::MessagePtr(new GT::Message("result1")));
    results->push_back(GT::MessagePtr(new GT::Message("result2")));

    // when
    GT::Model::ResultBuilderPtr builder(new GT::Model::PlainResultBuilder(GT::Message("\t")));
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
