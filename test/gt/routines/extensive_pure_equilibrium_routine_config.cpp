#include "gt/routines/test_common.hpp"

BOOST_AUTO_TEST_SUITE( ExtensivePureEquilibriumRoutineConfig )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( ExtensivePureEquilibriumRoutineConfig_toString ) {
    // given
    GT::Model::ResultFactory::getInstance()
        .setBuilderMode(GT::Model::ResultBuilderMode::PLAIN)
        .setIndentationMode(GT::Model::ResultIndentationMode::TABS);

    GT::Model::ExtensiveDataNodePtr extensiveGameRoot = GT::Model::ExtensiveDataBuilder().build()->getRoot();

    // when
    GT::Routines::ExtensivePureEquilibriumRoutineConfig routineConfig(extensiveGameRoot);

    // then
    BOOST_CHECK_EQUAL(
        routineConfig.toString(),
        GT::Message() +
        "ExtensivePureEquilibriumRoutineConfig"
    );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
