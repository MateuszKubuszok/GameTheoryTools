#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( Object )

BOOST_AUTO_TEST_CASE( Object_isValid ) {
    // given
    // when
    GT::GTL::Object object;

    // then
    BOOST_CHECK( object.isValid() );
}

BOOST_AUTO_TEST_CASE( Object_respondsTo ) {
    // given
    GT::Identifier properties = "properties";
    GT::Identifier type       = "type";
    GT::Identifier error      = "error";

    // when
    GT::GTL::Object object;

    // then
    BOOST_CHECK(  object.respondsTo(properties) );
    BOOST_CHECK(  object.respondsTo(type) );
    BOOST_CHECK( !object.respondsTo(error) );
}

BOOST_AUTO_TEST_CASE( Object_findProperty ) {
    // given
    GT::Identifier      properties = "properties";
    GT::Identifier      type       = "type";
    GT::Identifier      error      = "error";
    GT::GTL::ContextPtr contextPtr = GT::GTL::NullFactory::getInstance().createContext();
    GT::GTL::Context    context    = *contextPtr;

    // when
    GT::GTL::Object object;

    // then
    BOOST_REQUIRE_NO_THROW( object.findProperty(context, properties) );
    BOOST_REQUIRE_NO_THROW( object.findProperty(context, type) );
    BOOST_REQUIRE_THROW(
        object.findProperty(context, error),
        GT::GTL::InvalidProperty
    );

    BOOST_CHECK_EQUAL(
        object.findProperty(context, properties)->getResult(),
        GT::Message() +
        "\t\tKnown Properties,\n"
        "Property:\n"
        "\t\tproperties,\n"
        "Property:\n"
        "\t\ttype,\n"
    );
    BOOST_CHECK_EQUAL(
        object.findProperty(context, type)->getResult(),
        GT::Message() +
        "Type:\n"
        "\tObject\n"
    );
}

BOOST_AUTO_TEST_CASE( Object_findPropertyWithConditions ) {
        // given
    GT::Identifier         properties    = "properties";
    GT::Identifier         type          = "type";
    GT::Identifier         error         = "error";
    GT::GTL::ContextPtr    contextPtr    = GT::GTL::NullFactory::getInstance().createContext();
    GT::GTL::Context       context       = *contextPtr;
    GT::GTL::ConditionsPtr conditionsPtr = GT::GTL::NullFactory::getInstance().createConditions();
    GT::GTL::Conditions    conditions    = *conditionsPtr;

    // when
    GT::GTL::Object object;

    // then
    BOOST_REQUIRE_NO_THROW( object.findPropertyWithConditions(context, properties, conditions) );
    BOOST_REQUIRE_NO_THROW( object.findPropertyWithConditions(context, type, conditions) );
    BOOST_REQUIRE_THROW(
        object.findPropertyWithConditions(context, error, conditions),
        GT::GTL::InvalidProperty
    );

    BOOST_CHECK_EQUAL(
        object.findPropertyWithConditions(context, properties, conditions)->getResult(),
        GT::Message() +
        "\t\tKnown Properties,\n"
        "Property:\n"
        "\t\tproperties,\n"
        "Property:\n"
        "\t\ttype,\n"
    );
    BOOST_CHECK_EQUAL(
        object.findPropertyWithConditions(context, type, conditions)->getResult(),
        GT::Message() +
        "Type:\n"
        "\tObject\n"
    );
}

BOOST_AUTO_TEST_CASE( Object_listProperties ) {
    // given
    GT::IdentifiersPtr expectedProperties = GT::createIdentifiersPtr();
    expectedProperties->push_back( GT::createIdentifierPtr("properties") );
    expectedProperties->push_back( GT::createIdentifierPtr("type") );

    // when
    GT::GTL::Object object;
    GT::IdentifiersPtr properties = object.listProperties();

    // then
    BOOST_REQUIRE_EQUAL(
        properties->size(),
        expectedProperties->size()
    );

    for (int i = 0; i < properties->size(); i++)
        BOOST_CHECK_EQUAL(
            *(*properties)[i],
            *(*expectedProperties)[i]
        );
}

BOOST_AUTO_TEST_CASE( Object_type ) {
    // given
    // when
    GT::GTL::Object object;

    // then
    BOOST_CHECK_EQUAL(
        *object.type(),
        GT::Identifier() +
        "Object"
    );
}

BOOST_AUTO_TEST_CASE( Object_toString ) {
    // given
    // when
    GT::GTL::Object object;

    // then
    BOOST_CHECK_EQUAL(
        object.toString(),
        GT::Identifier() +
        "Object"
    );
}

BOOST_AUTO_TEST_SUITE_END()
