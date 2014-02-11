#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( CheckingStatementDriver )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( CheckingStatementDriver_get ) {
    // given
    GT::GTL::InputLocationPtr inputLocation = GT::GTL::NullFactory::getInstance().createInputLocation();
    GT::IdentifierPtr         identifier    = GT::Model::NullFactory::getInstance().createIdentifier();
    GT::NumberPtr             number        = GT::Model::NullFactory::getInstance().createNumber();

    boost::scoped_ptr<GT::IdentifierPtr> identifierPtr(new GT::IdentifierPtr(identifier));
    boost::scoped_ptr<GT::NumberPtr>     numberPtr(new GT::NumberPtr(number));

    // when
    GT::GTL::CheckingValueDriver valueDriver;
    boost::scoped_ptr<GT::GTL::ParamPtr> param1Ptr(valueDriver.get(*inputLocation, identifierPtr.get()));
    boost::scoped_ptr<GT::GTL::ParamPtr> param2Ptr(valueDriver.get(*inputLocation, numberPtr.get()));

    // then
    BOOST_REQUIRE(  param1Ptr );
    BOOST_CHECK( ( *param1Ptr ) );
    BOOST_REQUIRE(  param2Ptr );
    BOOST_CHECK( ( *param2Ptr ) );
}

BOOST_AUTO_TEST_CASE( CheckingValueDriver_toObject ) {
    // given
    GT::GTL::GamePtr   invalidGame   = GT::GTL::ErrorFactory::getInstance().createGame("Invalid Game");
    GT::GTL::GamePtr   validGame     = GT::GTL::NullFactory::getInstance().createGame();
    GT::GTL::PlayerPtr invalidPlayer = GT::GTL::ErrorFactory::getInstance().createPlayer("Invalid Player");
    GT::GTL::PlayerPtr validPlayer   = GT::GTL::NullFactory::getInstance().createPlayer();
    GT::GTL::ParamPtr  invalidParam  = GT::GTL::ErrorFactory::getInstance().createParam("Invalid Param");
    GT::GTL::ParamPtr  validParam    = GT::GTL::NullFactory::getInstance().createParam();

    boost::scoped_ptr<GT::GTL::GamePtr>   invalidGamePtr(new GT::GTL::GamePtr(invalidGame));
    boost::scoped_ptr<GT::GTL::GamePtr>   validGamePtr(new GT::GTL::GamePtr(validGame));
    boost::scoped_ptr<GT::GTL::PlayerPtr> invalidPlayerPtr(new GT::GTL::PlayerPtr(invalidPlayer));
    boost::scoped_ptr<GT::GTL::PlayerPtr> validPlayerPtr(new GT::GTL::PlayerPtr(validPlayer));
    boost::scoped_ptr<GT::GTL::ParamPtr>  invalidParamPtr(new GT::GTL::ParamPtr(invalidParam));
    boost::scoped_ptr<GT::GTL::ParamPtr>  validParamPtr(new GT::GTL::ParamPtr(validParam));

    // when
    GT::GTL::CheckingValueDriver valueDriver;
    boost::scoped_ptr<GT::GTL::ObjectPtr> object1Ptr(valueDriver.toObject(invalidGamePtr.get()));
    boost::scoped_ptr<GT::GTL::ObjectPtr> object2Ptr(valueDriver.toObject(validGamePtr.get()));
    boost::scoped_ptr<GT::GTL::ObjectPtr> object3Ptr(valueDriver.toObject(invalidPlayerPtr.get()));
    boost::scoped_ptr<GT::GTL::ObjectPtr> object4Ptr(valueDriver.toObject(validPlayerPtr.get()));
    boost::scoped_ptr<GT::GTL::ObjectPtr> object5Ptr(valueDriver.toObject(invalidParamPtr.get()));
    boost::scoped_ptr<GT::GTL::ObjectPtr> object6Ptr(valueDriver.toObject(validParamPtr.get()));

    // then
    BOOST_REQUIRE(   object1Ptr );
    BOOST_CHECK( !( *object1Ptr )->isValid() );
    BOOST_REQUIRE(   object2Ptr );
    BOOST_CHECK(  ( *object2Ptr )->isValid() );
    BOOST_REQUIRE(   object3Ptr );
    BOOST_CHECK( !( *object3Ptr )->isValid() );
    BOOST_REQUIRE(   object4Ptr );
    BOOST_CHECK(  ( *object4Ptr )->isValid() );
    BOOST_REQUIRE(   object5Ptr );
    BOOST_CHECK( !( *object5Ptr )->isValid() );
    BOOST_REQUIRE(   object6Ptr );
    BOOST_CHECK(  ( *object6Ptr )->isValid() );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
