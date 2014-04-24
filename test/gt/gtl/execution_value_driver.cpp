#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ExecutionValueDriver )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( ExecutionValueDriver_get ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::GTL::InputLocationPtr inputLocation = GT::GTL::NullFactory::getInstance().createInputLocation();
    GT::IdentifierPtr         identifier    = GT::Model::NullFactory::getInstance().createIdentifier();
    GT::NumberPtr             number        = GT::Model::NullFactory::getInstance().createNumber();

    boost::scoped_ptr<GT::IdentifierPtr> identifierPtr(new GT::IdentifierPtr(identifier));
    boost::scoped_ptr<GT::NumberPtr>     numberPtr(new GT::NumberPtr(number));

    // when
    GT::GTL::ExecutionValueDriver valueDriver;
    boost::scoped_ptr<GT::GTL::ParamPtr> param1Ptr(valueDriver.get(*inputLocation, identifierPtr.get()));
    boost::scoped_ptr<GT::GTL::ParamPtr> param2Ptr(valueDriver.get(*inputLocation, numberPtr.get()));

    // then
    BOOST_REQUIRE(param1Ptr);
    BOOST_CHECK_EQUAL(
        (*param1Ptr)->toString(),
        GT::Message() +
        "IdentifierParam:\n"
        "\tNullIdentifier\n"
    );
    BOOST_REQUIRE(param2Ptr);
    BOOST_CHECK_EQUAL(
        (*param2Ptr)->toString(),
        GT::Message() +
        "NumberParam:\n"
        "\t0.00000\n"
    );
}

BOOST_AUTO_TEST_CASE( ExecutionValueDriver_toObject ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::GTL::GamePtr   game   = GT::GTL::NullFactory::getInstance().createGame();
    GT::GTL::ParamPtr  param  = GT::GTL::NullFactory::getInstance().createParam();
    GT::GTL::PlayerPtr player = GT::GTL::NullFactory::getInstance().createPlayer();

    boost::scoped_ptr<GT::GTL::GamePtr>   gamePtr(new GT::GTL::GamePtr(game));
    boost::scoped_ptr<GT::GTL::ParamPtr>  paramPtr(new GT::GTL::ParamPtr(param));
    boost::scoped_ptr<GT::GTL::PlayerPtr> playerPtr(new GT::GTL::PlayerPtr(player));

    // when
    GT::GTL::ExecutionValueDriver valueDriver;
    boost::scoped_ptr<GT::GTL::ObjectPtr> gameObjectPtr(valueDriver.toObject(gamePtr.get()));
    boost::scoped_ptr<GT::GTL::ObjectPtr> paramObjectPtr(valueDriver.toObject(paramPtr.get()));
    boost::scoped_ptr<GT::GTL::ObjectPtr> playerObjectPtr(valueDriver.toObject(playerPtr.get()));

    // then
    BOOST_REQUIRE(gameObjectPtr);
    BOOST_CHECK_EQUAL(
        (*gameObjectPtr)->toString(),
        GT::Message() +
        "NullGame"
    );
    BOOST_REQUIRE(paramObjectPtr);
    BOOST_CHECK_EQUAL(
        (*paramObjectPtr)->toString(),
        GT::Message() +
        "NullParam"
    );
    BOOST_REQUIRE(playerObjectPtr);
    BOOST_CHECK_EQUAL(
        (*playerObjectPtr)->toString(),
        GT::Message() +
        "NullPlayer"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
