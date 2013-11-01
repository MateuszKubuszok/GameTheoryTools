#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( Context )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( Context_functional ) {
    // given
    GT::IdentifierPtr  numberParamName           = GT::createIdentifierPtr("numberParam");
    GT::NumberPtr      numberParamValue          = GT::Model::NullFactory::getInstance().createNumber();
    GT::GTL::ParamPtr  numberParam               =
        GT::GTL::ParamPtr(new GT::GTL::NumberParam(numberParamValue));
    GT::IdentifierPtr  numberParamIdentifierName = GT::createIdentifierPtr("numberParamIdentifier");
    GT::GTL::ParamPtr  numberParamIdentifier     =
        GT::GTL::ParamPtr(new GT::GTL::IdentifierParam(*numberParamName));

    GT::IdentifierPtr  objectParamName           = GT::createIdentifierPtr("objectParam");
    GT::GTL::ObjectPtr objectParamValue          = GT::GTL::NullFactory::getInstance().createObject();
    GT::GTL::ParamPtr  objectParam               =
        GT::GTL::ParamPtr(new GT::GTL::ObjectParam(objectParamValue));
    GT::IdentifierPtr  objectParamIdentifierName = GT::createIdentifierPtr("objectParamIdentifier");
    GT::GTL::ParamPtr  objectParamIdentifier     =
        GT::GTL::ParamPtr(new GT::GTL::IdentifierParam(*objectParamName));

    GT::IdentifierPtr  cyclicParam1Name          = GT::createIdentifierPtr("cyclicParam1");
    GT::IdentifierPtr  cyclicParam2Name          = GT::createIdentifierPtr("cyclicParam2");
    GT::GTL::ParamPtr  cyclicParam1              =
        GT::GTL::ParamPtr(new GT::GTL::IdentifierParam(*cyclicParam2Name));
    GT::GTL::ParamPtr  cyclicParam2              =
        GT::GTL::ParamPtr(new GT::GTL::IdentifierParam(*cyclicParam1Name));

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

BOOST_AUTO_TEST_CASE( Context_toString ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::IdentifierPtr  numberParamName           = GT::createIdentifierPtr("numberParam");
    GT::NumberPtr      numberParamValue          = GT::Model::NullFactory::getInstance().createNumber();
    GT::GTL::ParamPtr  numberParam               =
        GT::GTL::ParamPtr(new GT::GTL::NumberParam(numberParamValue));
    GT::IdentifierPtr  numberParamIdentifierName = GT::createIdentifierPtr("numberParamIdentifier");
    GT::GTL::ParamPtr  numberParamIdentifier     =
        GT::GTL::ParamPtr(new GT::GTL::IdentifierParam(*numberParamName));

    GT::IdentifierPtr  objectParamName           = GT::createIdentifierPtr("objectParam");
    GT::GTL::ObjectPtr objectParamValue          = GT::GTL::NullFactory::getInstance().createObject();
    GT::GTL::ParamPtr  objectParam               =
        GT::GTL::ParamPtr(new GT::GTL::ObjectParam(objectParamValue));
    GT::IdentifierPtr  objectParamIdentifierName = GT::createIdentifierPtr("objectParamIdentifier");
    GT::GTL::ParamPtr  objectParamIdentifier     =
        GT::GTL::ParamPtr(new GT::GTL::IdentifierParam(*objectParamName));

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
        "\t\t0\n"
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
