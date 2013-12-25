#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ConditionFactory )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( ConditionFactory_createInformationSetChoiceCondition ) {
    // given
    GT::GTL::ObjectPtr player         = GT::GTL::NullFactory::getInstance().createObject();
    GT::GTL::ObjectPtr informationSet = GT::GTL::NullFactory::getInstance().createObject();
    GT::GTL::ObjectPtr strategy       = GT::GTL::NullFactory::getInstance().createObject();

    // when
    GT::GTL::ConditionPtr condition = GT::GTL::ConditionFactory::getInstance()
                                    .createInformationSetChoiceCondition(player, informationSet, strategy);

    // then
    BOOST_REQUIRE( condition );
    BOOST_CHECK( boost::dynamic_pointer_cast<GT::GTL::InformationSetChoiceCondition>(condition) );
}

BOOST_AUTO_TEST_CASE( ConditionFactory_createInformationSetRangeCondition ) {
    // given

    GT::GTL::ObjectPtr  player         = GT::GTL::NullFactory::getInstance().createObject();
    GT::GTL::ObjectPtr  informationSet = GT::GTL::NullFactory::getInstance().createObject();
    GT::GTL::ObjectsPtr strategies     = GT::GTL::NullFactory::getInstance().createObjects();

    // when
    GT::GTL::ConditionPtr condition = GT::GTL::ConditionFactory::getInstance()
                                    .createInformationSetRangeCondition(player, informationSet, strategies);

    // then
    BOOST_REQUIRE( condition );
    BOOST_CHECK( boost::dynamic_pointer_cast<GT::GTL::InformationSetRangeCondition>(condition) );
}

BOOST_AUTO_TEST_CASE( ConditionFactory_createPlayerChoiceCondition ) {
    // given
    GT::GTL::ObjectPtr player   = GT::GTL::NullFactory::getInstance().createObject();
    GT::GTL::ObjectPtr strategy = GT::GTL::NullFactory::getInstance().createObject();

    // when
    GT::GTL::ConditionPtr condition = GT::GTL::ConditionFactory::getInstance()
                                        .createPlayerChoiceCondition(player, strategy);

    // then
    BOOST_REQUIRE( condition );
    BOOST_CHECK( boost::dynamic_pointer_cast<GT::GTL::PlayerChoiceCondition>(condition) );
}

BOOST_AUTO_TEST_CASE( ConditionFactory_createPlayerRangeCondition ) {
    // given
    GT::GTL::ObjectPtr  player     = GT::GTL::NullFactory::getInstance().createObject();
    GT::GTL::ObjectsPtr strategies = GT::GTL::NullFactory::getInstance().createObjects();

    // when
    GT::GTL::ConditionPtr condition = GT::GTL::ConditionFactory::getInstance()
                                        .createPlayerRangeCondition(player, strategies);

    // then
    BOOST_REQUIRE( condition );
    BOOST_CHECK( boost::dynamic_pointer_cast<GT::GTL::PlayerRangeCondition>(condition) );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
