#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ConditionFactory )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( ConditionFactory_createPlayerChoiceCondition ) {
    // given
    GT::GTL::ObjectPtr player  = GT::GTL::NullFactory::getInstance().createObject();
    GT::GTL::ObjectPtr strategy = GT::GTL::NullFactory::getInstance().createObject();

    // when
    GT::GTL::ConditionPtr condition = GT::GTL::ConditionFactory::getInstance()
                                        .createPlayerChoiceCondition(player, strategy);

    // then
    BOOST_REQUIRE( condition );
    BOOST_CHECK( boost::dynamic_pointer_cast<GT::GTL::PlayerChoiceCondition>(condition) );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
