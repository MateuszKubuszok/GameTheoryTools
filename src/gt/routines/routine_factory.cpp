/**
 * @file      gt/routines/routine_factory.cpp
 * @brief     Defines GT::Routines::RoutineFactory methods.
 * @copyright (C) 2013-2014
 * @author    Mateusz Kubuszok
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero
 * General Public License as published by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License along with this program. If not,
 * see [http://www.gnu.org/licenses/].
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "gt/routines/inner_common.hpp"

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using std::find_if;

using boost::dynamic_pointer_cast;
using boost::shared_ptr;

using Model::DataAccessorPtr;
using Model::ExtensiveDataAccessor;
using Model::PlayersPtr;
using Model::StrategicDataAccessor;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class RoutineFactory final {

RoutineFactory& RoutineFactory::getInstance() {
    static RoutineFactory instance;
    return instance;
}

// public:

RoutinePtr RoutineFactory::pureStrategyEquilibriumFindingRoutineFor(
    const GamePtr game
) const {
    DataAccessorPtr data = game->getData();

    shared_ptr<StrategicDataAccessor> strategicData( dynamic_pointer_cast<StrategicDataAccessor>(data) );
    if (strategicData)
        return RoutinePtr( new StrategicPureEquilibriumRoutine() );

    shared_ptr<ExtensiveDataAccessor> extensiveData( dynamic_pointer_cast<ExtensiveDataAccessor>(data) );
    if (extensiveData)
        return RoutinePtr( new ExtensivePureEquilibriumRoutine() );

    return RoutinePtr(new NotYetImplementedRoutine());
}

RoutinePtr RoutineFactory::mixedStrategyEquilibriumFindingRoutineFor(
    const GamePtr game
) const {
    DataAccessorPtr data = game->getData();

    shared_ptr<StrategicDataAccessor> strategicData( dynamic_pointer_cast<StrategicDataAccessor>(data) );
    if (strategicData) {
        if (game->getPlayers()->size() == 2) {
            bool is0Sum = true;
            for (Index i = 0; i < strategicData->getUpperBound(); i++)
                if (!strategicData->getPayoffs(i)->is0Sum()) {
                    is0Sum = false;
                    break;
                }

            if (is0Sum)
                return RoutinePtr( new Strategic2Player0SumMixedEquilibriumRoutine() );
            return RoutinePtr( new Strategic2PlayerMixedEquilibriumRoutine() );
        }
    }

    // shared_ptr<ExtensiveDataAccessor> extensiveData( dynamic_pointer_cast<ExtensiveDataAccessor>(data) );
    // if (extensiveData)
    //     return RoutinePtr( new ExtensiveMixedEquilibriumRoutine() );

    return RoutinePtr(new NotYetImplementedRoutine());
}

RoutinePtr RoutineFactory::behaviourStrategyEquilibriumFindingRoutineFor(
    const GamePtr game
) const {
    DataAccessorPtr data = game->getData();

    shared_ptr<StrategicDataAccessor> strategicData( dynamic_pointer_cast<StrategicDataAccessor>(data) );
    if (strategicData)
        return RoutinePtr( new PropertyUndefinedRoutine() );

    // shared_ptr<ExtensiveDataAccessor> extensiveData( dynamic_pointer_cast<ExtensiveDataAccessor>(data) );
    // if (extensiveData)
    //     return RoutinePtr( new ExtensiveBehaviourEquilibriumRoutine(players) );

    return RoutinePtr(new NotYetImplementedRoutine());
}

// private:

RoutineFactory::RoutineFactory() {}

RoutineFactory::~RoutineFactory() {}

// }; /* END class RoutineFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
