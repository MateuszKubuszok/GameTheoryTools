#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( Query )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using boost::make_shared;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( Query_execute ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::IdentifiersPtr properties = GT::createIdentifiersPtr();
    properties->push_back( GT::createIdentifierPtr("properties") );
    properties->push_back( GT::createIdentifierPtr("type") );

    GT::GTL::ObjectsPtr objects = make_shared<GT::GTL::Objects>();
    objects->push_back( make_shared<GT::GTL::Object>() );
    objects->push_back( boost::dynamic_pointer_cast<GT::GTL::Object>(
        GT::GTL::ParamFactory::getInstance().createParam(GT::createIdentifierPtr("Name"))
    ) );

    GT::GTL::ConditionsPtr conditions = make_shared<GT::GTL::Conditions>();

    GT::GTL::Context context;

    // when
    GT::GTL::Query query(properties, objects, conditions);

    // then
    BOOST_CHECK_EQUAL(
        query.execute(context)->getResult(),
        GT::Message() +
        "1:\n"
        "\tproperties:\n"
        "\t\t\t\tKnown Properties\n"
        "\t\tproperties:\n"
        "\t\t\t\tLists known properties for given Object\n"
        "\t\ttype:\n"
        "\t\t\t\tShows Object's type\n"
        "\ttype:\n"
        "\t\tType:\n"
        "\t\t\tObject\n"
        "2:\n"
        "\tproperties:\n"
        "\t\t\t\tKnown Properties\n"
        "\t\tproperties:\n"
        "\t\t\t\tLists known properties for given Object\n"
        "\t\treferred_properties:\n"
        "\t\t\t\tLists known properties for given Param's referee\n"
        "\t\ttype:\n"
        "\t\t\t\tShows Object's type\n"
        "\t\tvalue:\n"
        "\t\t\t\tShows value of a given Param\n"
        "\ttype:\n"
        "\t\tType:\n"
        "\t\t\tParam\n"
    );
}

BOOST_AUTO_TEST_CASE( Query_toString ) {
    //given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::IdentifiersPtr properties = GT::createIdentifiersPtr();
    properties->push_back( GT::createIdentifierPtr("properties") );
    properties->push_back( GT::createIdentifierPtr("type") );

    GT::GTL::ObjectsPtr objects = make_shared<GT::GTL::Objects>();
    objects->push_back( make_shared<GT::GTL::Object>() );
    objects->push_back( boost::dynamic_pointer_cast<GT::GTL::Object>(
        GT::GTL::ParamFactory::getInstance().createParam(GT::createIdentifierPtr("Name"))
    ) );

    GT::GTL::ConditionsPtr conditions = make_shared<GT::GTL::Conditions>();

    // when
    GT::GTL::Query query(properties, objects, conditions);

    // then
    BOOST_CHECK_EQUAL(
        query.toString(),
        GT::Message() +
        "\t\tProperties\n"
        "Property Name:\n"
        "\t\tproperties\n"
        "Property Name:\n"
        "\t\ttype\n"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
