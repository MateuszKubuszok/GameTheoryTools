#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ExecutionStatementDriver )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using boost::make_shared;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( ExecutionStatementDriver_executeDefinition ) {
    // given
    TestDriverImpl      driver;
    GT::GTL::ContextPtr context = make_shared<GT::GTL::Context>();

    GT::IdentifierPtr name  = GT::createIdentifierPtr("Name");
    GT::GTL::ParamPtr value =
        GT::GTL::ParamFactory::getInstance().createParam(GT::createIdentifierPtr("Value"));

    GT::GTL::DefinitionPtr definition = make_shared<GT::GTL::Definition>(name, value);

    boost::scoped_ptr<GT::GTL::DefinitionPtr> definitionPtr(new GT::GTL::DefinitionPtr(definition));

    // when
    GT::GTL::ExecutionStatementDriver statementDriver(&driver, context.get());

    // then
    BOOST_REQUIRE(statementDriver.executeDefinition(definitionPtr.get()));
    BOOST_CHECK(context->hasRegistered(*name));
}

BOOST_AUTO_TEST_CASE( ExecutionStatementDriver_executeQuery ) {
    // given
    TestDriverImpl      driver;
    GT::GTL::ContextPtr context = make_shared<GT::GTL::Context>();

    GT::IdentifiersPtr properties = GT::createIdentifiersPtr();
    properties->push_back( GT::createIdentifierPtr("properties") );
    properties->push_back( GT::createIdentifierPtr("type") );

    GT::GTL::ObjectsPtr objects = make_shared<GT::GTL::Objects>();
    objects->push_back( make_shared<GT::GTL::Object>() );
    objects->push_back( boost::dynamic_pointer_cast<GT::GTL::Object>(
        GT::GTL::ParamFactory::getInstance().createParam(GT::createIdentifierPtr("Name"))
    ) );

    GT::GTL::ConditionsPtr conditions = make_shared<GT::GTL::Conditions>();
    GT::GTL::QueryPtr      query      = make_shared<GT::GTL::Query>(properties, objects, conditions);

    boost::scoped_ptr<GT::GTL::QueryPtr> queryPtr(new GT::GTL::QueryPtr(query));

    // when
    GT::GTL::ExecutionStatementDriver statementDriver(&driver, context.get());

    // then
    BOOST_REQUIRE(statementDriver.executeQuery(queryPtr.get()));
    BOOST_CHECK_EQUAL(
        driver.getShownResults(),
        1
    );
}

BOOST_AUTO_TEST_CASE( ExecutionStatementDriver_createDefinition ) {
    // given
    TestDriverImpl            driver;
    GT::GTL::ContextPtr       context = make_shared<GT::GTL::Context>();
    GT::GTL::InputLocationPtr inputLocation = GT::GTL::NullFactory::getInstance().createInputLocation();

    GT::IdentifierPtr  name  = GT::createIdentifierPtr("Name");
    GT::GTL::ObjectPtr value = GT::GTL::NullFactory::getInstance().createObject();

    boost::scoped_ptr<GT::IdentifierPtr>  namePtr(new GT::IdentifierPtr(name));
    boost::scoped_ptr<GT::GTL::ObjectPtr> valuePtr(new GT::GTL::ObjectPtr(value));

    // when
    GT::GTL::ExecutionStatementDriver statementDriver(&driver, context.get());
    boost::scoped_ptr<GT::GTL::DefinitionPtr> definitionPtr(
        statementDriver.createDefinition(*inputLocation, namePtr.get(), valuePtr.get()));

    // then
    BOOST_REQUIRE(definitionPtr);
    BOOST_CHECK_EQUAL(
        (*definitionPtr)->getName(),
        name
    );
    BOOST_CHECK_EQUAL(
        (*definitionPtr)->getValue()->getObject(*context),
        value
    );
}

BOOST_AUTO_TEST_CASE( ExecutionStatementDriver_createQuery ) {
    // given
    TestDriverImpl            driver;
    GT::GTL::ContextPtr       context = make_shared<GT::GTL::Context>();
    GT::GTL::InputLocationPtr inputLocation = GT::GTL::NullFactory::getInstance().createInputLocation();

    GT::IdentifiersPtr properties = GT::createIdentifiersPtr();
    properties->push_back( GT::createIdentifierPtr("properties") );
    properties->push_back( GT::createIdentifierPtr("type") );

    GT::GTL::ObjectsPtr objects = make_shared<GT::GTL::Objects>();
    objects->push_back( make_shared<GT::GTL::Object>() );
    objects->push_back( boost::dynamic_pointer_cast<GT::GTL::Object>(
        GT::GTL::ParamFactory::getInstance().createParam(GT::createIdentifierPtr("Name"))
    ) );

    GT::GTL::ConditionsPtr conditions = make_shared<GT::GTL::Conditions>();

    boost::scoped_ptr<GT::IdentifiersPtr>     propertiesPtr(new GT::IdentifiersPtr(properties));
    boost::scoped_ptr<GT::GTL::ObjectsPtr>    objectsPtr(new GT::GTL::ObjectsPtr(objects));
    boost::scoped_ptr<GT::GTL::ConditionsPtr> conditionsPtr(new GT::GTL::ConditionsPtr(conditions));

    // when
    GT::GTL::ExecutionStatementDriver statementDriver(&driver, context.get());
    boost::scoped_ptr<GT::GTL::QueryPtr> queryPtr(statementDriver.createQuery(
        *inputLocation, propertiesPtr.get(), objectsPtr.get(), conditionsPtr.get()));

    // then
    BOOST_REQUIRE(queryPtr);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
