#include "gt/routines/test_common.hpp"

BOOST_AUTO_TEST_SUITE( RoutineFactory )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( RoutineFactory_pureStrategyEquilibriumFindingRoutineFor ) {
    // given
    GT::Model::PlayersPtr players = GT::Model::NullFactory::getInstance().createPlayers();

    GT::Model::StrategicDataPtr strategicData =
        GT::Model::InnerNullFactory::getInstance().createStrategicData();
    GT::Model::GamePtr strategicGame(new GT::Model::StrategicGame(players, strategicData));

    GT::Model::ExtensiveDataPtr extensiveData =
        GT::Model::InnerNullFactory::getInstance().createExtensiveData();
    GT::Model::GamePtr extensiveGame(new GT::Model::ExtensiveGame(players, extensiveData));

    // when
    GT::Routines::RoutinePtr strategicPureEquilibriumRoutine =
        GT::Routines::RoutineFactory::getInstance().pureStrategyEquilibriumFindingRoutineFor(strategicGame);
    GT::Routines::RoutinePtr extensivePureEquilibriumRoutine =
        GT::Routines::RoutineFactory::getInstance().pureStrategyEquilibriumFindingRoutineFor(extensiveGame);

    // then
    BOOST_CHECK( boost::dynamic_pointer_cast<GT::Routines::StrategicPureEquilibriumRoutine>(
        strategicPureEquilibriumRoutine
    ) );
    BOOST_CHECK( boost::dynamic_pointer_cast<GT::Routines::ExtensivePureEquilibriumRoutine>(
        extensivePureEquilibriumRoutine
    ) );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
