#include "gt/routines/test_common.hpp"

BOOST_AUTO_TEST_SUITE( StrategicPureEquilibriumRoutineConfig )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( StrategicPureEquilibriumRoutineConfig_toString ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::Model::PlayersPtr players = GT::Model::NullFactory::getInstance().createPlayers();

    // when
    GT::Routines::StrategicPureEquilibriumRoutineConfig routineConfig(players);

    // then
    BOOST_CHECK_EQUAL(
        routineConfig.toString(),
        GT::Message() +
        "StrategicPureEquilibriumRoutineConfig"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
