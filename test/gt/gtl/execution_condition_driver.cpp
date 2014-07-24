#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ExecutionConditionDriver )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using boost::make_shared;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( ExecutionConditionDriver_informationSetChoosed ) {
    // given
    GT::IdentifierPtr  playerName = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr  setName    = GT::createIdentifierPtr("1");
    GT::IdentifierPtr  strategy   = GT::createIdentifierPtr("p1s1");
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();
    strategies->push_back( strategy );
    GT::GTL::PlayerPtr player = make_shared<GT::GTL::Player>(playerName, strategies);

    GT::GTL::ParamPtr  setParam      = GT::GTL::ParamFactory::getInstance().createParam(setName);
    GT::GTL::ParamPtr  strategyParam = GT::GTL::ParamFactory::getInstance().createParam(strategy);

    GT::GTL::InputLocationPtr inputLocation  = GT::GTL::NullFactory::getInstance().createInputLocation();
    GT::GTL::ObjectPtr        objectPlayer   = boost::dynamic_pointer_cast<GT::GTL::Object>(player);
    GT::GTL::ObjectPtr        objectSet      = boost::dynamic_pointer_cast<GT::GTL::Object>(setParam);
    GT::GTL::ObjectPtr        objectStrategy = boost::dynamic_pointer_cast<GT::GTL::Object>(strategyParam);

    boost::scoped_ptr<GT::GTL::ObjectPtr> playerPtr(new GT::GTL::ObjectPtr(objectPlayer));
    boost::scoped_ptr<GT::GTL::ObjectPtr> setPtr(new GT::GTL::ObjectPtr(objectSet));
    boost::scoped_ptr<GT::GTL::ObjectPtr> strategyPtr(new GT::GTL::ObjectPtr(objectStrategy));

    // when
    GT::GTL::ExecutionConditionDriver conditionDriver;
    boost::scoped_ptr<GT::GTL::ConditionPtr> conditionPtr(
    conditionDriver.informationSetChoosed(*inputLocation, playerPtr.get(), setPtr.get(), strategyPtr.get())
    );

    // then
    BOOST_REQUIRE(conditionPtr);
    BOOST_CHECK(boost::dynamic_pointer_cast<GT::GTL::InformationSetChoiceCondition>(*conditionPtr));
}

BOOST_AUTO_TEST_CASE( ExecutionConditionDriver_informationSetWithin ) {
    // given
    GT::IdentifierPtr  playerName = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr  setName    = GT::createIdentifierPtr("1");
    GT::IdentifierPtr  strategy   = GT::createIdentifierPtr("p1s1");
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();
    strategies->push_back( strategy );
    GT::GTL::PlayerPtr player = make_shared<GT::GTL::Player>(playerName, strategies);

    GT::GTL::ParamPtr  setParam      = GT::GTL::ParamFactory::getInstance().createParam(setName);
    GT::GTL::ParamPtr  strategyParam = GT::GTL::ParamFactory::getInstance().createParam(strategy);

    GT::GTL::InputLocationPtr inputLocation    = GT::GTL::NullFactory::getInstance().createInputLocation();
    GT::GTL::ObjectPtr        objectPlayer     = boost::dynamic_pointer_cast<GT::GTL::Object>(player);
    GT::GTL::ObjectPtr        objectSet        = boost::dynamic_pointer_cast<GT::GTL::Object>(setParam);
    GT::GTL::ObjectsPtr       objectStrategies = make_shared<GT::GTL::Objects>();
    objectStrategies->push_back( strategyParam );

    boost::scoped_ptr<GT::GTL::ObjectPtr>  playerPtr(new GT::GTL::ObjectPtr(objectPlayer));
    boost::scoped_ptr<GT::GTL::ObjectPtr>  setPtr(new GT::GTL::ObjectPtr(objectSet));
    boost::scoped_ptr<GT::GTL::ObjectsPtr> strategiesPtr(new GT::GTL::ObjectsPtr(objectStrategies));

    // when
    GT::GTL::ExecutionConditionDriver conditionDriver;
    boost::scoped_ptr<GT::GTL::ConditionPtr> conditionPtr(
    conditionDriver.informationSetWithin(*inputLocation, playerPtr.get(), setPtr.get(), strategiesPtr.get())
    );

    // then
    BOOST_REQUIRE(conditionPtr);
    BOOST_CHECK(boost::dynamic_pointer_cast<GT::GTL::InformationSetRangeCondition>(*conditionPtr));
}

BOOST_AUTO_TEST_CASE( ExecutionConditionDriver_playerChoosed ) {
    // given
    GT::IdentifierPtr  playerName = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr  strategy   = GT::createIdentifierPtr("p1s1");
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();
    strategies->push_back( strategy );
    GT::GTL::PlayerPtr player = make_shared<GT::GTL::Player>(playerName, strategies);

    GT::GTL::ParamPtr  strategyParam = GT::GTL::ParamFactory::getInstance().createParam(strategy);

    GT::GTL::InputLocationPtr inputLocation  = GT::GTL::NullFactory::getInstance().createInputLocation();
    GT::GTL::ObjectPtr        objectPlayer   = boost::dynamic_pointer_cast<GT::GTL::Object>(player);
    GT::GTL::ObjectPtr        objectStrategy = boost::dynamic_pointer_cast<GT::GTL::Object>(strategyParam);

    boost::scoped_ptr<GT::GTL::ObjectPtr> playerPtr(new GT::GTL::ObjectPtr(objectPlayer));
    boost::scoped_ptr<GT::GTL::ObjectPtr> strategyPtr(new GT::GTL::ObjectPtr(objectStrategy));

    // when
    GT::GTL::ExecutionConditionDriver conditionDriver;
    boost::scoped_ptr<GT::GTL::ConditionPtr> conditionPtr(
        conditionDriver.playerChoosed(*inputLocation, playerPtr.get(), strategyPtr.get()));

    // then
    BOOST_REQUIRE(conditionPtr);
    BOOST_CHECK(boost::dynamic_pointer_cast<GT::GTL::PlayerChoiceCondition>(*conditionPtr));
}

BOOST_AUTO_TEST_CASE( ExecutionConditionDriver_playerWithin ) {
    // given
    GT::IdentifierPtr  playerName = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr  strategy   = GT::createIdentifierPtr("p1s1");
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();
    strategies->push_back( strategy );
    GT::GTL::PlayerPtr player = make_shared<GT::GTL::Player>(playerName, strategies);

    GT::GTL::ParamPtr  strategyParam = GT::GTL::ParamFactory::getInstance().createParam(strategy);

    GT::GTL::InputLocationPtr inputLocation    = GT::GTL::NullFactory::getInstance().createInputLocation();
    GT::GTL::ObjectPtr        objectPlayer     = boost::dynamic_pointer_cast<GT::GTL::Object>(player);
    GT::GTL::ObjectsPtr       objectStrategies = make_shared<GT::GTL::Objects>();
    objectStrategies->push_back( strategyParam );

    boost::scoped_ptr<GT::GTL::ObjectPtr>  playerPtr(new GT::GTL::ObjectPtr(objectPlayer));
    boost::scoped_ptr<GT::GTL::ObjectsPtr> strategiesPtr(new GT::GTL::ObjectsPtr(objectStrategies));

    // when
    GT::GTL::ExecutionConditionDriver conditionDriver;
    boost::scoped_ptr<GT::GTL::ConditionPtr> conditionPtr(
        conditionDriver.playerWithin(*inputLocation, playerPtr.get(), strategiesPtr.get()));

    // then
    BOOST_REQUIRE(conditionPtr);
    BOOST_CHECK(boost::dynamic_pointer_cast<GT::GTL::PlayerRangeCondition>(*conditionPtr));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
