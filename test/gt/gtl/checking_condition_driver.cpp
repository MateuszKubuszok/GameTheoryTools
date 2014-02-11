#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( CheckingConditionDriver )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( CheckingConditionDriver_informationSetChoosed ) {
    // given
    GT::GTL::InputLocationPtr inputLocation = GT::GTL::NullFactory::getInstance().createInputLocation();
    GT::GTL::ObjectPtr        invalidPlayer =boost::dynamic_pointer_cast<GT::GTL::Object>(
        GT::GTL::ErrorFactory::getInstance().createPlayer("Invalid Player"));
    GT::GTL::ObjectPtr        validPlayer   = boost::dynamic_pointer_cast<GT::GTL::Object>(
        GT::GTL::NullFactory::getInstance().createPlayer());
    GT::GTL::ObjectPtr        invalidParam  = boost::dynamic_pointer_cast<GT::GTL::Object>(
        GT::GTL::ErrorFactory::getInstance().createParam("Invalid Player"));
    GT::GTL::ObjectPtr        validParam    = boost::dynamic_pointer_cast<GT::GTL::Object>(
        GT::GTL::NullFactory::getInstance().createParam());
    GT::GTL::ObjectPtr        invalidObject =
        GT::GTL::ErrorFactory::getInstance().createObject("Invalid Object");

    boost::scoped_ptr<GT::GTL::ObjectPtr> invalidPlayerPtr(new GT::GTL::ObjectPtr(invalidPlayer));
    boost::scoped_ptr<GT::GTL::ObjectPtr> validPlayerPtr(new GT::GTL::ObjectPtr(validPlayer));
    boost::scoped_ptr<GT::GTL::ObjectPtr> invalidParamPtr(new GT::GTL::ObjectPtr(invalidParam));
    boost::scoped_ptr<GT::GTL::ObjectPtr> validParamPtr(new GT::GTL::ObjectPtr(validParam));
    boost::scoped_ptr<GT::GTL::ObjectPtr> invalidObjectPtr(new GT::GTL::ObjectPtr(invalidObject));

    // when
    GT::GTL::CheckingConditionDriver conditionDriver;
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition1Ptr(
        conditionDriver.informationSetChoosed(
            *inputLocation, invalidPlayerPtr.get(), invalidParamPtr.get(), invalidParamPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition2Ptr(
        conditionDriver.informationSetChoosed(
            *inputLocation, invalidPlayerPtr.get(), validParamPtr.get(),   validParamPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition3Ptr(
        conditionDriver.informationSetChoosed(
            *inputLocation, validPlayerPtr.get(),   invalidParamPtr.get(), invalidParamPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition4Ptr(
        conditionDriver.informationSetChoosed(
            *inputLocation, validPlayerPtr.get(),   validParamPtr.get(),   validParamPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition5Ptr(
        conditionDriver.informationSetChoosed(
            *inputLocation, invalidParamPtr.get(),  invalidParamPtr.get(), invalidParamPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition6Ptr(
        conditionDriver.informationSetChoosed(
            *inputLocation, invalidParamPtr.get(),  validParamPtr.get(),   validParamPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition7Ptr(
        conditionDriver.informationSetChoosed(
            *inputLocation, validParamPtr.get(),    invalidParamPtr.get(), invalidParamPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition8Ptr(
        conditionDriver.informationSetChoosed(
            *inputLocation, validParamPtr.get(),    validParamPtr.get(),   validParamPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition9Ptr(
        conditionDriver.informationSetChoosed(
            *inputLocation, invalidObjectPtr.get(), validParamPtr.get(),   validParamPtr.get()));

    // then
    BOOST_REQUIRE(   condition1Ptr );
    BOOST_CHECK( !( *condition1Ptr )->isValid() );
    BOOST_REQUIRE(   condition2Ptr );
    BOOST_CHECK( !( *condition2Ptr )->isValid() );
    BOOST_REQUIRE(   condition3Ptr );
    BOOST_CHECK( !( *condition3Ptr )->isValid() );
    BOOST_REQUIRE(   condition4Ptr );
    BOOST_CHECK(  ( *condition4Ptr )->isValid() );
    BOOST_REQUIRE(   condition5Ptr );
    BOOST_CHECK( !( *condition5Ptr )->isValid() );
    BOOST_REQUIRE(   condition6Ptr );
    BOOST_CHECK( !( *condition6Ptr )->isValid() );
    BOOST_REQUIRE(   condition7Ptr );
    BOOST_CHECK( !( *condition7Ptr )->isValid() );
    BOOST_REQUIRE(   condition8Ptr );
    BOOST_CHECK(  ( *condition8Ptr )->isValid() );
    BOOST_REQUIRE(   condition9Ptr );
    BOOST_CHECK( !( *condition9Ptr )->isValid() );
}

BOOST_AUTO_TEST_CASE( CheckingConditionDriver_informationSetWithin ) {
    // given
    GT::GTL::InputLocationPtr inputLocation = GT::GTL::NullFactory::getInstance().createInputLocation();
    GT::GTL::ObjectPtr        invalidPlayer =boost::dynamic_pointer_cast<GT::GTL::Object>(
        GT::GTL::ErrorFactory::getInstance().createPlayer("Invalid Player"));
    GT::GTL::ObjectPtr        validPlayer   = boost::dynamic_pointer_cast<GT::GTL::Object>(
        GT::GTL::NullFactory::getInstance().createPlayer());
    GT::GTL::ObjectPtr        invalidParam  = boost::dynamic_pointer_cast<GT::GTL::Object>(
        GT::GTL::ErrorFactory::getInstance().createParam("Invalid Player"));
    GT::GTL::ObjectPtr        validParam    = boost::dynamic_pointer_cast<GT::GTL::Object>(
        GT::GTL::NullFactory::getInstance().createParam());
    GT::GTL::ObjectPtr        invalidObject =
        GT::GTL::ErrorFactory::getInstance().createObject("Invalid Object");

    boost::scoped_ptr<GT::GTL::ObjectPtr> invalidPlayerPtr(new GT::GTL::ObjectPtr(invalidPlayer));
    boost::scoped_ptr<GT::GTL::ObjectPtr> validPlayerPtr(new GT::GTL::ObjectPtr(validPlayer));
    boost::scoped_ptr<GT::GTL::ObjectPtr> invalidParamPtr(new GT::GTL::ObjectPtr(invalidParam));
    boost::scoped_ptr<GT::GTL::ObjectPtr> validParamPtr(new GT::GTL::ObjectPtr(validParam));
    boost::scoped_ptr<GT::GTL::ObjectPtr> invalidObjectPtr(new GT::GTL::ObjectPtr(invalidObject));

    boost::scoped_ptr<GT::GTL::ObjectsPtr> validParamsPtr(new GT::GTL::ObjectsPtr(new GT::GTL::Objects));
    (*validParamsPtr)->push_back( validParam );
    boost::scoped_ptr<GT::GTL::ObjectsPtr> invalidParamsPtr(new GT::GTL::ObjectsPtr(new GT::GTL::Objects));
    (*invalidParamsPtr)->push_back( invalidParam );

    // when
    GT::GTL::CheckingConditionDriver conditionDriver;
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition1Ptr(
        conditionDriver.informationSetWithin(
            *inputLocation, invalidPlayerPtr.get(), invalidParamPtr.get(), invalidParamsPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition2Ptr(
        conditionDriver.informationSetWithin(
            *inputLocation, invalidPlayerPtr.get(), validParamPtr.get(),   validParamsPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition3Ptr(
        conditionDriver.informationSetWithin(
            *inputLocation, validPlayerPtr.get(),   invalidParamPtr.get(), invalidParamsPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition4Ptr(
        conditionDriver.informationSetWithin(
            *inputLocation, validPlayerPtr.get(),   validParamPtr.get(),   validParamsPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition5Ptr(
        conditionDriver.informationSetWithin(
            *inputLocation, invalidParamPtr.get(),  invalidParamPtr.get(), invalidParamsPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition6Ptr(
        conditionDriver.informationSetWithin(
            *inputLocation, invalidParamPtr.get(),  validParamPtr.get(),   validParamsPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition7Ptr(
        conditionDriver.informationSetWithin(
            *inputLocation, validParamPtr.get(),    invalidParamPtr.get(), invalidParamsPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition8Ptr(
        conditionDriver.informationSetWithin(
            *inputLocation, validParamPtr.get(),    validParamPtr.get(),   validParamsPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition9Ptr(
        conditionDriver.informationSetWithin(
            *inputLocation, invalidObjectPtr.get(), validParamPtr.get(),   validParamsPtr.get()));

    // then
    BOOST_REQUIRE(   condition1Ptr );
    BOOST_CHECK( !( *condition1Ptr )->isValid() );
    BOOST_REQUIRE(   condition2Ptr );
    BOOST_CHECK( !( *condition2Ptr )->isValid() );
    BOOST_REQUIRE(   condition3Ptr );
    BOOST_CHECK( !( *condition3Ptr )->isValid() );
    BOOST_REQUIRE(   condition4Ptr );
    BOOST_CHECK(  ( *condition4Ptr )->isValid() );
    BOOST_REQUIRE(   condition5Ptr );
    BOOST_CHECK( !( *condition5Ptr )->isValid() );
    BOOST_REQUIRE(   condition6Ptr );
    BOOST_CHECK( !( *condition6Ptr )->isValid() );
    BOOST_REQUIRE(   condition7Ptr );
    BOOST_CHECK( !( *condition7Ptr )->isValid() );
    BOOST_REQUIRE(   condition8Ptr );
    BOOST_CHECK(  ( *condition8Ptr )->isValid() );
    BOOST_REQUIRE(   condition9Ptr );
    BOOST_CHECK( !( *condition9Ptr )->isValid() );
}

BOOST_AUTO_TEST_CASE( CheckingConditionDriver_playerChoosed ) {
    // given
    GT::GTL::InputLocationPtr inputLocation = GT::GTL::NullFactory::getInstance().createInputLocation();
    GT::GTL::ObjectPtr        invalidPlayer =boost::dynamic_pointer_cast<GT::GTL::Object>(
        GT::GTL::ErrorFactory::getInstance().createPlayer("Invalid Player"));
    GT::GTL::ObjectPtr        validPlayer   = boost::dynamic_pointer_cast<GT::GTL::Object>(
        GT::GTL::NullFactory::getInstance().createPlayer());
    GT::GTL::ObjectPtr        invalidParam  = boost::dynamic_pointer_cast<GT::GTL::Object>(
        GT::GTL::ErrorFactory::getInstance().createParam("Invalid Player"));
    GT::GTL::ObjectPtr        validParam    = boost::dynamic_pointer_cast<GT::GTL::Object>(
        GT::GTL::NullFactory::getInstance().createParam());
    GT::GTL::ObjectPtr        invalidObject =
        GT::GTL::ErrorFactory::getInstance().createObject("Invalid Object");

    boost::scoped_ptr<GT::GTL::ObjectPtr> invalidPlayerPtr(new GT::GTL::ObjectPtr(invalidPlayer));
    boost::scoped_ptr<GT::GTL::ObjectPtr> validPlayerPtr(new GT::GTL::ObjectPtr(validPlayer));
    boost::scoped_ptr<GT::GTL::ObjectPtr> invalidParamPtr(new GT::GTL::ObjectPtr(invalidParam));
    boost::scoped_ptr<GT::GTL::ObjectPtr> validParamPtr(new GT::GTL::ObjectPtr(validParam));
    boost::scoped_ptr<GT::GTL::ObjectPtr> invalidObjectPtr(new GT::GTL::ObjectPtr(invalidObject));

    boost::scoped_ptr<GT::GTL::ObjectsPtr> validParamsPtr(new GT::GTL::ObjectsPtr(new GT::GTL::Objects));
    (*validParamsPtr)->push_back( validParam );
    boost::scoped_ptr<GT::GTL::ObjectsPtr> invalidParamsPtr(new GT::GTL::ObjectsPtr(new GT::GTL::Objects));
    (*invalidParamsPtr)->push_back( invalidParam );

    // when
    GT::GTL::CheckingConditionDriver conditionDriver;
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition1Ptr(
        conditionDriver.playerWithin(*inputLocation, invalidPlayerPtr.get(), invalidParamsPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition2Ptr(
        conditionDriver.playerWithin(*inputLocation, invalidPlayerPtr.get(), validParamsPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition3Ptr(
        conditionDriver.playerWithin(*inputLocation, validPlayerPtr.get(),   invalidParamsPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition4Ptr(
        conditionDriver.playerWithin(*inputLocation, validPlayerPtr.get(),   validParamsPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition5Ptr(
        conditionDriver.playerWithin(*inputLocation, invalidParamPtr.get(),  invalidParamsPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition6Ptr(
        conditionDriver.playerWithin(*inputLocation, invalidParamPtr.get(),  validParamsPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition7Ptr(
        conditionDriver.playerWithin(*inputLocation, validParamPtr.get(),    invalidParamsPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition8Ptr(
        conditionDriver.playerWithin(*inputLocation, validParamPtr.get(),    validParamsPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition9Ptr(
        conditionDriver.playerWithin(*inputLocation, invalidObjectPtr.get(), validParamsPtr.get()));

    // then
    BOOST_REQUIRE(   condition1Ptr );
    BOOST_CHECK( !( *condition1Ptr )->isValid() );
    BOOST_REQUIRE(   condition2Ptr );
    BOOST_CHECK( !( *condition2Ptr )->isValid() );
    BOOST_REQUIRE(   condition3Ptr );
    BOOST_CHECK( !( *condition3Ptr )->isValid() );
    BOOST_REQUIRE(   condition4Ptr );
    BOOST_CHECK(  ( *condition4Ptr )->isValid() );
    BOOST_REQUIRE(   condition5Ptr );
    BOOST_CHECK( !( *condition5Ptr )->isValid() );
    BOOST_REQUIRE(   condition6Ptr );
    BOOST_CHECK( !( *condition6Ptr )->isValid() );
    BOOST_REQUIRE(   condition7Ptr );
    BOOST_CHECK( !( *condition7Ptr )->isValid() );
    BOOST_REQUIRE(   condition8Ptr );
    BOOST_CHECK(  ( *condition8Ptr )->isValid() );
    BOOST_REQUIRE(   condition9Ptr );
    BOOST_CHECK( !( *condition9Ptr )->isValid() );
}

BOOST_AUTO_TEST_CASE( CheckingConditionDriver_playerWithin ) {
    // given
    GT::GTL::InputLocationPtr inputLocation = GT::GTL::NullFactory::getInstance().createInputLocation();
    GT::GTL::ObjectPtr        invalidPlayer =boost::dynamic_pointer_cast<GT::GTL::Object>(
        GT::GTL::ErrorFactory::getInstance().createPlayer("Invalid Player"));
    GT::GTL::ObjectPtr        validPlayer   = boost::dynamic_pointer_cast<GT::GTL::Object>(
        GT::GTL::NullFactory::getInstance().createPlayer());
    GT::GTL::ObjectPtr        invalidParam  = boost::dynamic_pointer_cast<GT::GTL::Object>(
        GT::GTL::ErrorFactory::getInstance().createParam("Invalid Player"));
    GT::GTL::ObjectPtr        validParam    = boost::dynamic_pointer_cast<GT::GTL::Object>(
        GT::GTL::NullFactory::getInstance().createParam());
    GT::GTL::ObjectPtr        invalidObject =
        GT::GTL::ErrorFactory::getInstance().createObject("Invalid Object");

    boost::scoped_ptr<GT::GTL::ObjectPtr> invalidPlayerPtr(new GT::GTL::ObjectPtr(invalidPlayer));
    boost::scoped_ptr<GT::GTL::ObjectPtr> validPlayerPtr(new GT::GTL::ObjectPtr(validPlayer));
    boost::scoped_ptr<GT::GTL::ObjectPtr> invalidParamPtr(new GT::GTL::ObjectPtr(invalidParam));
    boost::scoped_ptr<GT::GTL::ObjectPtr> validParamPtr(new GT::GTL::ObjectPtr(validParam));
    boost::scoped_ptr<GT::GTL::ObjectPtr> invalidObjectPtr(new GT::GTL::ObjectPtr(invalidObject));

    // when
    GT::GTL::CheckingConditionDriver conditionDriver;
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition1Ptr(
        conditionDriver.playerChoosed(*inputLocation, invalidPlayerPtr.get(), invalidParamPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition2Ptr(
        conditionDriver.playerChoosed(*inputLocation, invalidPlayerPtr.get(), validParamPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition3Ptr(
        conditionDriver.playerChoosed(*inputLocation, validPlayerPtr.get(),   invalidParamPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition4Ptr(
        conditionDriver.playerChoosed(*inputLocation, validPlayerPtr.get(),   validParamPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition5Ptr(
        conditionDriver.playerChoosed(*inputLocation, invalidParamPtr.get(),  invalidParamPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition6Ptr(
        conditionDriver.playerChoosed(*inputLocation, invalidParamPtr.get(),  validParamPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition7Ptr(
        conditionDriver.playerChoosed(*inputLocation, validParamPtr.get(),    invalidParamPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition8Ptr(
        conditionDriver.playerChoosed(*inputLocation, validParamPtr.get(),    validParamPtr.get()));
    boost::scoped_ptr<GT::GTL::ConditionPtr> condition9Ptr(
        conditionDriver.playerChoosed(*inputLocation, invalidObjectPtr.get(), validParamPtr.get()));

    // then
    BOOST_REQUIRE(   condition1Ptr );
    BOOST_CHECK( !( *condition1Ptr )->isValid() );
    BOOST_REQUIRE(   condition2Ptr );
    BOOST_CHECK( !( *condition2Ptr )->isValid() );
    BOOST_REQUIRE(   condition3Ptr );
    BOOST_CHECK( !( *condition3Ptr )->isValid() );
    BOOST_REQUIRE(   condition4Ptr );
    BOOST_CHECK(  ( *condition4Ptr )->isValid() );
    BOOST_REQUIRE(   condition5Ptr );
    BOOST_CHECK( !( *condition5Ptr )->isValid() );
    BOOST_REQUIRE(   condition6Ptr );
    BOOST_CHECK( !( *condition6Ptr )->isValid() );
    BOOST_REQUIRE(   condition7Ptr );
    BOOST_CHECK( !( *condition7Ptr )->isValid() );
    BOOST_REQUIRE(   condition8Ptr );
    BOOST_CHECK(  ( *condition8Ptr )->isValid() );
    BOOST_REQUIRE(   condition9Ptr );
    BOOST_CHECK( !( *condition9Ptr )->isValid() );
}

BOOST_AUTO_TEST_CASE( CheckingConditionDriver_toString ) {
    // given
    // when
    GT::GTL::CheckingConditionDriver conditionDriver;

    // then
    BOOST_CHECK_EQUAL(
        conditionDriver.toString(),
        GT::Message() +
        "CheckingConditionDriver"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
