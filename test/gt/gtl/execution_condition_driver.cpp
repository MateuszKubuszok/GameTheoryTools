#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ExecutionConditionDriver )

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( ExecutionConditionDriver_playerChoosed ) {
    // given
    TestDriverImpl driver;

    GT::IdentifierPtr  playerName = GT::createIdentifierPtr("p1");
    GT::IdentifierPtr  strategy   = GT::createIdentifierPtr("p1s1");
    GT::IdentifiersPtr strategies(new GT::Identifiers());
    strategies->push_back( strategy );
    GT::GTL::PlayerPtr player(new GT::GTL::Player(playerName, strategies));

    GT::GTL::ParamPtr  strategyParam = GT::GTL::ParamFactory::getInstance().createParam(strategy);

    GT::GTL::InputLocationPtr inputLocation  = GT::GTL::NullFactory::getInstance().createInputLocation();
    GT::GTL::ObjectPtr        objectPlayer   = boost::dynamic_pointer_cast<GT::GTL::Object>(player);
    GT::GTL::ObjectPtr        objectStrategy = boost::dynamic_pointer_cast<GT::GTL::Object>(strategyParam);

    boost::scoped_ptr<GT::GTL::ObjectPtr> playerPtr(new GT::GTL::ObjectPtr(objectPlayer));
    boost::scoped_ptr<GT::GTL::ObjectPtr> strategyPtr(new GT::GTL::ObjectPtr(objectStrategy));

    // when
    GT::GTL::ExecutionConditionDriver conditionDriver(&driver);
    boost::scoped_ptr<GT::GTL::ConditionPtr> conditionPtr(conditionDriver.playerChoosed(*inputLocation, playerPtr.get(), strategyPtr.get()));

    // then
    BOOST_REQUIRE(conditionPtr);
    BOOST_CHECK(boost::dynamic_pointer_cast<GT::GTL::PlayerChoiceCondition>(*conditionPtr));
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
