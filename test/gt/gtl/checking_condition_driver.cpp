#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( CheckingConditionDriver )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( CheckingConditionDriver_playerChoosed ) {
    // given
    TestDriverImpl driver;
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
    GT::GTL::CheckingConditionDriver conditionDriver(&driver);
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
    TestDriverImpl driver;

    // when
    GT::GTL::CheckingConditionDriver conditionDriver(&driver);

    // then
    BOOST_CHECK_EQUAL(
        conditionDriver.toString(),
        GT::Message() +
        "CheckingConditionDriver"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
