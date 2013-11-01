#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( CheckingStatementDriver )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( CheckingStatementDriver_executeDefinition ) {
    // given
    TestDriverImpl         driver;
    GT::GTL::DefinitionPtr invalidDefinition =
        GT::GTL::ErrorFactory::getInstance().createDefinition("Invalid Definition");
    GT::GTL::DefinitionPtr validDefinition   = GT::GTL::NullFactory::getInstance().createDefinition();

    boost::scoped_ptr<GT::GTL::DefinitionPtr>
        invalidDefinitionPtr( new GT::GTL::DefinitionPtr(invalidDefinition) );
    boost::scoped_ptr<GT::GTL::DefinitionPtr>
        validDefinitionPtr( new GT::GTL::DefinitionPtr(validDefinition) );

    // when
    GT::GTL::CheckingStatementDriver statementDriver(&driver);

    // then
    BOOST_REQUIRE( !statementDriver.executeDefinition(invalidDefinitionPtr.get()) );
    BOOST_CHECK_EQUAL(
        driver.getShownErrors(),
        1
    );
    BOOST_REQUIRE( statementDriver.executeDefinition(validDefinitionPtr.get()) );
    BOOST_CHECK_EQUAL(
        driver.getShownErrors(),
        1
    );
}

BOOST_AUTO_TEST_CASE( CheckingStatementDriver_executeQuery ) {
    // given
    TestDriverImpl    driver;
    GT::GTL::QueryPtr invalidQuery = GT::GTL::ErrorFactory::getInstance().createQuery("Invalid Query");
    GT::GTL::QueryPtr validQuery   = GT::GTL::NullFactory::getInstance().createQuery();

    boost::scoped_ptr<GT::GTL::QueryPtr> invalidQueryPtr( new GT::GTL::QueryPtr(invalidQuery) );
    boost::scoped_ptr<GT::GTL::QueryPtr> validQueryPtr( new GT::GTL::QueryPtr(validQuery) );

    // when
    GT::GTL::CheckingStatementDriver statementDriver(&driver);

    // then
    BOOST_REQUIRE( !statementDriver.executeQuery(invalidQueryPtr.get()) );
    BOOST_CHECK_EQUAL(
        driver.getShownErrors(),
        1
    );
    BOOST_REQUIRE( statementDriver.executeQuery(validQueryPtr.get()) );
    BOOST_CHECK_EQUAL(
        driver.getShownErrors(),
        1
    );
}

BOOST_AUTO_TEST_CASE( CheckingStatementDriver_createDefinition ) {
    // given
    TestDriverImpl driver;
    GT::GTL::InputLocationPtr inputLocation = GT::GTL::NullFactory::getInstance().createInputLocation();
    GT::IdentifierPtr         identifier    = GT::createIdentifierPtr("identifier");
    GT::GTL::ObjectPtr        invalidObject =
    GT::GTL::ErrorFactory::getInstance().createObject("Invalid Object");
    GT::GTL::ObjectPtr        validObject   = GT::GTL::NullFactory::getInstance().createObject();

    boost::scoped_ptr<GT::IdentifierPtr>  identifierPtr( new GT::IdentifierPtr(identifier) );
    boost::scoped_ptr<GT::GTL::ObjectPtr> invalidObjectPtr( new GT::GTL::ObjectPtr(invalidObject) );
    boost::scoped_ptr<GT::GTL::ObjectPtr> validObjectPtr( new GT::GTL::ObjectPtr(validObject) );

    // when
    GT::GTL::CheckingStatementDriver statementDriver(&driver);
    boost::scoped_ptr<GT::GTL::DefinitionPtr> definition1Ptr(
        statementDriver.createDefinition(*inputLocation, identifierPtr.get(), invalidObjectPtr.get()));
    boost::scoped_ptr<GT::GTL::DefinitionPtr> definition2Ptr(
        statementDriver.createDefinition(*inputLocation, identifierPtr.get(), validObjectPtr.get()));

    // then
    BOOST_REQUIRE(   definition1Ptr );
    BOOST_CHECK( !( *definition1Ptr )->isValid() );
    BOOST_REQUIRE(   definition2Ptr );
    BOOST_CHECK(  ( *definition2Ptr )->isValid() );
}

BOOST_AUTO_TEST_CASE( CheckingStatementDriver_createQuery ) {
    // given
    TestDriverImpl driver;
    GT::GTL::InputLocationPtr inputLocation = GT::GTL::NullFactory::getInstance().createInputLocation();

    GT::IdentifiersPtr identifiers(new GT::Identifiers());
    identifiers->push_back(GT::createIdentifierPtr("type"));
    identifiers->push_back(GT::createIdentifierPtr("properties"));

    GT::GTL::ObjectsPtr invalidObjects(new GT::GTL::Objects());
    invalidObjects->push_back(GT::GTL::ErrorFactory::getInstance().createObject("Invalid Object 1"));
    invalidObjects->push_back(GT::GTL::ErrorFactory::getInstance().createObject("Invalid Object 2"));

    GT::GTL::ObjectsPtr validObjects(new GT::GTL::Objects());
    validObjects->push_back(GT::GTL::ObjectPtr(new GT::GTL::Object()));
    validObjects->push_back(GT::GTL::ObjectPtr(new GT::GTL::Object()));

    GT::GTL::ConditionsPtr invalidConditions(new GT::GTL::Conditions());
    invalidConditions->push_back(GT::GTL::ErrorFactory::getInstance().createCondition("Invalid Condition"));

    GT::GTL::ConditionsPtr validConditions(new GT::GTL::Conditions());
    validConditions->push_back(GT::GTL::NullFactory::getInstance().createCondition());

    boost::scoped_ptr<GT::IdentifiersPtr>     identifiersPtr(new GT::IdentifiersPtr(identifiers));
    boost::scoped_ptr<GT::GTL::ObjectsPtr>    invalidObjectsPtr(new GT::GTL::ObjectsPtr(invalidObjects));
    boost::scoped_ptr<GT::GTL::ObjectsPtr>    validObjectsPtr(new GT::GTL::ObjectsPtr(validObjects));
    boost::scoped_ptr<GT::GTL::ConditionsPtr> invalidConditionsPtr(
        new GT::GTL::ConditionsPtr(invalidConditions));
    boost::scoped_ptr<GT::GTL::ConditionsPtr> validConditionsPtr(new GT::GTL::ConditionsPtr(validConditions));

    // when
    GT::GTL::CheckingStatementDriver statementDriver(&driver);
    boost::scoped_ptr<GT::GTL::QueryPtr> query1Ptr(statementDriver.createQuery(
        *inputLocation, identifiersPtr.get(), invalidObjectsPtr.get(), validConditionsPtr.get()));
    boost::scoped_ptr<GT::GTL::QueryPtr> query2Ptr(statementDriver.createQuery(
        *inputLocation, identifiersPtr.get(), validObjectsPtr.get(),   invalidConditionsPtr.get()));
    boost::scoped_ptr<GT::GTL::QueryPtr> query3Ptr(statementDriver.createQuery(
        *inputLocation, identifiersPtr.get(), validObjectsPtr.get(),   validConditionsPtr.get()));

    // then
    BOOST_REQUIRE(   query1Ptr );
    BOOST_CHECK( !( *query1Ptr )->isValid() );
    BOOST_REQUIRE(   query2Ptr );
    BOOST_CHECK( !( *query2Ptr )->isValid() );
    BOOST_REQUIRE(   query3Ptr );
    BOOST_CHECK(  ( *query3Ptr )->isValid() );
}

BOOST_AUTO_TEST_CASE( CheckingStatementDriver_toString ) {
    // given
    TestDriverImpl driver;

    // when
    GT::GTL::CheckingStatementDriver statementDriver(&driver);

    // then
    BOOST_CHECK_EQUAL(
        statementDriver.toString(),
        GT::Message() +
        "CheckingStatementDriver"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
