#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( Object )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( Object_isValid ) {
    // given
    // when
    GT::GTL::Object object;

    // then
    BOOST_CHECK( object.isValid() );
}

BOOST_AUTO_TEST_CASE( Object_respondsTo ) {
    // given
    GT::Identifier properties = GT::createIdentifier("properties");
    GT::Identifier type       = GT::createIdentifier("type");
    GT::Identifier error      = GT::createIdentifier("error");

    // when
    GT::GTL::Object object;

    // then
    BOOST_CHECK(  object.respondsTo(properties) );
    BOOST_CHECK(  object.respondsTo(type) );
    BOOST_CHECK( !object.respondsTo(error) );
}

BOOST_AUTO_TEST_CASE( Object_describeProperty ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::Identifier      properties = GT::createIdentifier("properties");
    GT::Identifier      type       = GT::createIdentifier("type");
    GT::Identifier      error      = GT::createIdentifier("error");
    GT::GTL::ContextPtr contextPtr = GT::GTL::NullFactory::getInstance().createContext();
    GT::GTL::Context    context    = *contextPtr;

    // when
    GT::GTL::Object object;

    // then
    BOOST_REQUIRE_NO_THROW( object.describeProperty(properties) );
    BOOST_REQUIRE_NO_THROW( object.describeProperty(type) );
    BOOST_REQUIRE_THROW(
        object.describeProperty(error),
        GT::GTL::InvalidProperty
    );

    BOOST_CHECK_EQUAL(
        object.describeProperty(properties)->getResult(),
        GT::Message() +
        "Lists known properties for given Object"
    );
    BOOST_CHECK_EQUAL(
        object.describeProperty(type)->getResult(),
        GT::Message() +
        "Shows Object's type"
    );
}

BOOST_AUTO_TEST_CASE( Object_findProperty ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::Identifier      properties = GT::createIdentifier("properties");
    GT::Identifier      type       = GT::createIdentifier("type");
    GT::Identifier      error      = GT::createIdentifier("error");
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
        "\t\tKnown Properties\n"
        "properties:\n"
        "\t\tLists known properties for given Object\n"
        "type:\n"
        "\t\tShows Object's type\n"
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
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::Identifier         properties    = GT::createIdentifier("properties");
    GT::Identifier         type          = GT::createIdentifier("type");
    GT::Identifier         error         = GT::createIdentifier("error");
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
        "\t\tKnown Properties\n"
        "properties:\n"
        "\t\tLists known properties for given Object\n"
        "type:\n"
        "\t\tShows Object's type\n"
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

    for (GT::Index i = 0; i < properties->size(); i++)
        BOOST_CHECK_EQUAL(
            *(*properties)[i],
            *(*expectedProperties)[i]
        );
}

BOOST_AUTO_TEST_CASE( Object_type ) {
    // given
    // when
    GT::GTL::Object object1;
    GT::GTL::Object object2(GT::Identifier("OtherType"));

    // then
    BOOST_CHECK_EQUAL(
        *object1.type(),
        GT::Identifier() +
        "Object"
    );
    BOOST_CHECK_EQUAL(
        *object2.type(),
        GT::Identifier() +
        "OtherType"
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

BOOST_AUTO_TEST_CASE( Object_Game ) {
    // given
    // when
    GT::GTL::Object      object;
    const GT::GTL::Game& game = object;

    // when
    BOOST_CHECK( !game );
}

BOOST_AUTO_TEST_CASE( Object_Param ) {
    // given
    // when
    GT::GTL::Object       object;
    const GT::GTL::Param& param = object;

    // when
    BOOST_CHECK( !param );
}

BOOST_AUTO_TEST_CASE( Object_Player ) {
    // given
    // when
    GT::GTL::Object        object;
    const GT::GTL::Player& player = object;

    // when
    BOOST_CHECK( !player );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
