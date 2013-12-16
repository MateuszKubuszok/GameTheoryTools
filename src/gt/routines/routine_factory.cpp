#include "gt/routines/inner_common.hpp"

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class RoutineFactory {

SINGLETON_DEFINITION(RoutineFactory, getInstance, routineFactoryMutex)

// public:

RoutinePtr RoutineFactory::pureStrategyEquilibriumFindingRoutineFor(
    const GamePtr game
) const {
    Model::DataAccessorPtr data    = game->getData();
    Model::PlayersPtr      players = game->getPlayers();

    boost::shared_ptr<Model::StrategicDataAccessor> strategicData(
        boost::dynamic_pointer_cast<Model::StrategicDataAccessor>(data)
    );
    if (strategicData)
        return RoutinePtr( new StrategicPureEquilibriumRoutine(players) );

    boost::shared_ptr<Model::ExtensiveDataAccessor> extensiveData(
        boost::dynamic_pointer_cast<Model::ExtensiveDataAccessor>(data)
    );
    if (extensiveData)
        return RoutinePtr( new ExtensivePureEquilibriumRoutine(players) );

    return RoutinePtr(new NotYetImplementedRoutine());
}

RoutinePtr RoutineFactory::mixedStrategyEquilibriumFindingRoutineFor(
    const GamePtr
) const {
    return RoutinePtr(new NotYetImplementedRoutine());
}

RoutinePtr RoutineFactory::behaviourStrategyEquilibriumFindingRoutineFor(
    const GamePtr
) const {
    return RoutinePtr(new NotYetImplementedRoutine());
}

// private:

RoutineFactory::RoutineFactory() {}

RoutineFactory::~RoutineFactory() {}

// }; /* END class RoutineFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
