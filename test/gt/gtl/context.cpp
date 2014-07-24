#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( Context )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using boost::make_shared;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( Context_functional ) {
    // given
    GT::IdentifierPtr  contextParamName          = GT::createIdentifierPtr("context");

    GT::IdentifierPtr  numberParamName           = GT::createIdentifierPtr("numberParam");
    GT::NumberPtr      numberParamValue          = GT::Model::NullFactory::getInstance().createNumber();
    GT::GTL::ParamPtr  numberParam               = make_shared<GT::GTL::NumberParam>(numberParamValue);
    GT::IdentifierPtr  numberParamIdentifierName = GT::createIdentifierPtr("numberParamIdentifier");
    GT::GTL::ParamPtr  numberParamIdentifier     = make_shared<GT::GTL::IdentifierParam>(*numberParamName);

    GT::IdentifierPtr  objectParamName           = GT::createIdentifierPtr("objectParam");
    GT::GTL::ObjectPtr objectParamValue          = GT::GTL::NullFactory::getInstance().createObject();
    GT::GTL::ParamPtr  objectParam               = make_shared<GT::GTL::ObjectParam>(objectParamValue);
    GT::IdentifierPtr  objectParamIdentifierName = GT::createIdentifierPtr("objectParamIdentifier");
    GT::GTL::ParamPtr  objectParamIdentifier     = make_shared<GT::GTL::IdentifierParam>(*objectParamName);

    GT::IdentifierPtr  cyclicParam1Name          = GT::createIdentifierPtr("cyclicParam1");
    GT::IdentifierPtr  cyclicParam2Name          = GT::createIdentifierPtr("cyclicParam2");
    GT::GTL::ParamPtr  cyclicParam1              = make_shared<GT::GTL::IdentifierParam>(*cyclicParam2Name);
    GT::GTL::ParamPtr  cyclicParam2              = make_shared<GT::GTL::IdentifierParam>(*cyclicParam1Name);

    GT::IdentifierPtr  invalidIdentifier         = GT::createIdentifierPtr("invalidIdentifier");

    // when
    GT::GTL::Context context;
    context.registerParam(numberParamName,           numberParam)
           .registerParam(numberParamIdentifierName, numberParamIdentifier)
           .registerParam(objectParamName,           objectParam)
           .registerParam(objectParamIdentifierName, objectParamIdentifier)
           .registerParam(cyclicParam1Name,          cyclicParam1)
           .registerParam(cyclicParam2Name,          cyclicParam2);

    // then
    BOOST_CHECK_EQUAL(
        context.getKnownObjects().size(),
        7
    );

    BOOST_REQUIRE_THROW( context.getNumber(*contextParamName), GT::GTL::InvalidContentRequest );
    BOOST_REQUIRE_NO_THROW( context.getObject(*contextParamName) );
    BOOST_REQUIRE_NO_THROW( context.getParam(*contextParamName) );

    BOOST_REQUIRE_NO_THROW( context.getNumber(*numberParamName) );
    BOOST_REQUIRE_THROW( context.getObject(*numberParamName), GT::GTL::InvalidContentRequest );
    BOOST_REQUIRE_NO_THROW( context.getParam(*numberParamName) );
    BOOST_CHECK_EQUAL(
        context.getNumber(*numberParamName),
        numberParamValue
    );

    BOOST_REQUIRE_NO_THROW( context.getNumber(*numberParamIdentifierName) );
    BOOST_REQUIRE_THROW( context.getObject(*numberParamIdentifierName), GT::GTL::InvalidContentRequest );
    BOOST_REQUIRE_NO_THROW( context.getParam(*numberParamIdentifierName) );
    BOOST_CHECK_EQUAL(
        context.getNumber(*numberParamIdentifierName),
        numberParamValue
    );

    BOOST_REQUIRE_THROW( context.getNumber(*objectParamName), GT::GTL::InvalidContentRequest );
    BOOST_REQUIRE_NO_THROW( context.getObject(*objectParamName) );
    BOOST_REQUIRE_NO_THROW( context.getParam(*objectParamName) );
    BOOST_CHECK_EQUAL(
        context.getObject(*objectParamName),
        objectParamValue
    );

    BOOST_REQUIRE_THROW( context.getNumber(*objectParamIdentifierName), GT::GTL::InvalidContentRequest );
    BOOST_REQUIRE_NO_THROW( context.getObject(*objectParamIdentifierName) );
    BOOST_REQUIRE_NO_THROW( context.getParam(*objectParamIdentifierName) );
    BOOST_CHECK_EQUAL(
        context.getObject(*objectParamIdentifierName),
        objectParamValue
    );

    BOOST_REQUIRE_THROW( context.getNumber(*cyclicParam1Name), GT::GTL::CyclicIdentifiers );
    BOOST_REQUIRE_THROW( context.getObject(*cyclicParam1Name), GT::GTL::CyclicIdentifiers );

    BOOST_REQUIRE_THROW( context.getNumber(*cyclicParam2Name), GT::GTL::CyclicIdentifiers );
    BOOST_REQUIRE_THROW( context.getObject(*cyclicParam2Name), GT::GTL::CyclicIdentifiers );

    BOOST_REQUIRE_THROW( context.getNumber(*invalidIdentifier), GT::GTL::NotDefinedParam );
    BOOST_REQUIRE_THROW( context.getObject(*invalidIdentifier), GT::GTL::NotDefinedParam );
    BOOST_REQUIRE_THROW( context.getParam(*invalidIdentifier),  GT::GTL::NotDefinedParam );
}

BOOST_AUTO_TEST_CASE( Context_depthChecking ) {
    // given
    GT::GTL::Context::setMaxLegalDepth(3);

    // when
    GT::GTL::ContextPtr context1 = make_shared<GT::GTL::Context>();
    GT::GTL::ContextPtr context2 = make_shared<GT::GTL::Context>(context1);
    GT::GTL::ContextPtr context3 = make_shared<GT::GTL::Context>(context2);

    // then
    BOOST_CHECK_EQUAL(
        GT::GTL::Context::getMaxLegalDepth(),
        3
    );
    BOOST_CHECK(  context1->canLegallySpawnChild() );
    BOOST_CHECK(  context2->canLegallySpawnChild() );
    BOOST_CHECK( !context3->canLegallySpawnChild() );
}

BOOST_AUTO_TEST_CASE( Context_replaceParam ) {
    // given
    GT::IdentifierPtr  paramName                 = GT::createIdentifierPtr("paramName");

    GT::NumberPtr      numberParamValue          = GT::Model::NullFactory::getInstance().createNumber();
    GT::GTL::ParamPtr  numberParam               = make_shared<GT::GTL::NumberParam>(numberParamValue);

    GT::GTL::ObjectPtr objectParamValue          = GT::GTL::NullFactory::getInstance().createObject();
    GT::GTL::ParamPtr  objectParam               = make_shared<GT::GTL::ObjectParam>(objectParamValue);

    // when
    GT::GTL::Context context;
    context.registerParam(paramName, numberParam)
           .registerParam(paramName, objectParam);

    // then
    BOOST_CHECK_EQUAL(
        context.getParam(*paramName),
        objectParam
    );
}

BOOST_AUTO_TEST_CASE( Context_serialize ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::IdentifierPtr  numberParamName           = GT::createIdentifierPtr("numberParam");
    GT::NumberPtr      numberParamValue          = GT::Model::NullFactory::getInstance().createNumber();
    GT::GTL::ParamPtr  numberParam               = make_shared<GT::GTL::NumberParam>(numberParamValue);
    GT::IdentifierPtr  numberParamIdentifierName = GT::createIdentifierPtr("numberParamIdentifier");
    GT::GTL::ParamPtr  numberParamIdentifier     = make_shared<GT::GTL::IdentifierParam>(*numberParamName);

    GT::IdentifierPtr identifierParamName  = GT::createIdentifierPtr("identifierParam");
    GT::IdentifierPtr identifierParamValue = GT::Model::NullFactory::getInstance().createIdentifier();
    GT::GTL::ParamPtr identifierParam      = make_shared<GT::GTL::IdentifierParam>(*identifierParamValue);

    // when
    GT::GTL::Context context;
    context.registerParam(numberParamName,           numberParam)
           .registerParam(numberParamIdentifierName, numberParamIdentifier)
           .registerParam(identifierParamName,       identifierParam);

    // then
    BOOST_CHECK_EQUAL(
        context.serialize(),
        GT::Message() +
        "LET identifierParam BE\n"
        "  NullIdentifier;\n"
        "LET numberParam BE\n"
        "  0.00000;\n"
        "LET numberParamIdentifier BE\n"
        "  numberParam;"
    );
}

BOOST_AUTO_TEST_CASE( Context_toString ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::IdentifierPtr  numberParamName           = GT::createIdentifierPtr("numberParam");
    GT::NumberPtr      numberParamValue          = GT::Model::NullFactory::getInstance().createNumber();
    GT::GTL::ParamPtr  numberParam               = make_shared<GT::GTL::NumberParam>(numberParamValue);
    GT::IdentifierPtr  numberParamIdentifierName = GT::createIdentifierPtr("numberParamIdentifier");
    GT::GTL::ParamPtr  numberParamIdentifier     = make_shared<GT::GTL::IdentifierParam>(*numberParamName);

    GT::IdentifierPtr  objectParamName           = GT::createIdentifierPtr("objectParam");
    GT::GTL::ObjectPtr objectParamValue          = GT::GTL::NullFactory::getInstance().createObject();
    GT::GTL::ParamPtr  objectParam               = make_shared<GT::GTL::ObjectParam>(objectParamValue);
    GT::IdentifierPtr  objectParamIdentifierName = GT::createIdentifierPtr("objectParamIdentifier");
    GT::GTL::ParamPtr  objectParamIdentifier     = make_shared<GT::GTL::IdentifierParam>(*objectParamName);

    // when
    GT::GTL::Context context;
    context.registerParam(numberParamName,           numberParam)
           .registerParam(numberParamIdentifierName, numberParamIdentifier)
           .registerParam(objectParamName,           objectParam)
           .registerParam(objectParamIdentifierName, objectParamIdentifier);

    // then
    BOOST_CHECK_EQUAL(
        context.toString(),
        GT::Message() +
        "numberParam:\n"
        "\tNumberParam:\n"
        "\t\t0.00000\n"
        "numberParamIdentifier:\n"
        "\tIdentifierParam:\n"
        "\t\tnumberParam\n"
        "objectParam:\n"
        "\tObjectParam:\n"
        "\t\tNullObject\n"
        "objectParamIdentifier:\n"
        "\tIdentifierParam:\n"
        "\t\tobjectParam\n"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
