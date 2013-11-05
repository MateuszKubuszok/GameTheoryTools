#include "gt/routines/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ConditionFactory )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( ConditionFactory_createPlayerChoiceCondition ) {
    // given
    GT::IdentifierPtr player   = GT::Model::NullFactory::getInstance().createIdentifier();
    GT::IdentifierPtr strategy = GT::Model::NullFactory::getInstance().createIdentifier();

    // when
    GT::Routines::ConditionPtr condition = GT::Routines::ConditionFactory::getInstance()
                                               .createPlayerChoiceCondition(player, strategy);

    // then
    BOOST_REQUIRE( condition );
    BOOST_CHECK( boost::dynamic_pointer_cast<GT::Routines::PlayerChoiceCondition>(condition) );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
