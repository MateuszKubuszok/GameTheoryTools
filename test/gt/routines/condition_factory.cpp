#include "gt/routines/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ConditionFactory )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( ConditionFactory_createInformationSetChoiceCondition ) {
    // given
    GT::IdentifierPtr player         = GT::Model::NullFactory::getInstance().createIdentifier();
    GT::IdentifierPtr informationSet = GT::Model::NullFactory::getInstance().createIdentifier();
    GT::IdentifierPtr strategy       = GT::Model::NullFactory::getInstance().createIdentifier();

    // when
    GT::Routines::ConditionPtr condition = GT::Routines::ConditionFactory::getInstance()
                                    .createInformationSetChoiceCondition(player, informationSet, strategy);

    // then
    BOOST_REQUIRE( condition );
    BOOST_CHECK( boost::dynamic_pointer_cast<GT::Routines::InformationSetChoiceCondition>(condition) );
}

BOOST_AUTO_TEST_CASE( ConditionFactory_createInformationSetRangeCondition ) {
    // given
    GT::IdentifierPtr  player         = GT::Model::NullFactory::getInstance().createIdentifier();
    GT::IdentifierPtr  informationSet = GT::Model::NullFactory::getInstance().createIdentifier();
    GT::IdentifiersPtr strategies     = GT::createIdentifiersPtr();
    strategies->push_back( GT::Model::NullFactory::getInstance().createIdentifier() );

    // when
    GT::Routines::ConditionPtr condition = GT::Routines::ConditionFactory::getInstance()
                                    .createInformationSetRangeCondition(player, informationSet, strategies);

    // then
    BOOST_REQUIRE( condition );
    BOOST_CHECK( boost::dynamic_pointer_cast<GT::Routines::InformationSetRangeCondition>(condition) );
}

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

BOOST_AUTO_TEST_CASE( ConditionFactory_createPlayerRangeCondition ) {
    // given
    GT::IdentifierPtr  player     = GT::Model::NullFactory::getInstance().createIdentifier();
    GT::IdentifiersPtr strategies = GT::createIdentifiersPtr();
    strategies->push_back( GT::Model::NullFactory::getInstance().createIdentifier() );

    // when
    GT::Routines::ConditionPtr condition = GT::Routines::ConditionFactory::getInstance()
                                    .createPlayerRangeCondition(player, strategies);

    // then
    BOOST_REQUIRE( condition );
    BOOST_CHECK( boost::dynamic_pointer_cast<GT::Routines::PlayerRangeCondition>(condition) );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
