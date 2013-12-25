/**
 * @file      gt/routines/strategic_pure_equilibrium_routine.cpp
 * @brief     Defines GT::Routines::StrategicPureEquilibriumRoutine methods.
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

using Model::DataPiecePtr;
using Model::Players;
using Model::PlayersPtr;
using Model::StrategicDataAccessor;
using Model::StrategicDataAccessorPtr;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class StrategicPureEquilibriumRoutine final : public Routine {
// public:

ResultPtr StrategicPureEquilibriumRoutine::findResultFor(
    const GamePtr       game,
    const ConditionsPtr conditions
) const {
    const StrategicDataAccessorPtr data = dynamic_pointer_cast<StrategicDataAccessor>(game->getData());
    if (!data) {
        static Identifier extensiveGameName("Strategic Game");
        throw ExceptionFactory::getInstance().invalidGameType(extensiveGameName);
    }

    const StrategicPureEquilibriumRoutineConfig routineConfig =
        applyConditions(data->getPlayers(), *conditions);
    if (!routineConfig.isValid())
        throw ExceptionFactory::getInstance().contradictoryConditions();

    const StrategicGamePositionsHelper positionsHelper(data->getPlayers());

    Index upperBound = positionsHelper.getUpperBound();
    for (Index index = 0; index < upperBound; index++) {
        const PositionsPtr positions = positionsHelper.retrievePositions(index);

        if (!arePositionsAllowed(routineConfig, *positions))
            continue;

        if (isNashEquilibrium(*data, *positions)) {
            ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();

            static const IdentifierPtr pureStrategiesName = createIdentifierPtr("Pure Strategies");
            ResultBuilderPtr pureStrategiesResult = ResultFactory::getInstance().buildResult();
            for (const Positions::value_type& position : *positions) {
                const IdentifierPtr& playerName = createIdentifierPtr(position.first);
                const MessagePtr&    strategy   = createMessagePtr(position.second);
                pureStrategiesResult->addResult( playerName, strategy );
            }
            const MessagePtr pureStrategies = createMessagePtr(pureStrategiesResult->build()->getResult());
            resultBuilder->addResult( pureStrategiesName, pureStrategies );

            static const IdentifierPtr finalPayoffName = createIdentifierPtr("Payoff");
            const MessagePtr finalPayoffResult = createMessagePtr(
                data->getPayoffs(*positions)->toString()
            );
            resultBuilder->addResult( finalPayoffName, finalPayoffResult );

            return resultBuilder->build();
        }
    }

    // TODO: create MessageFactory
    return ResultFactory::getInstance().constResult(Message("No Nash equilibrium found"));
}

Message StrategicPureEquilibriumRoutine::toString() const {
    return Message("StrategicPureEquilibriumRoutine");
}

// private:

StrategicPureEquilibriumRoutineConfig StrategicPureEquilibriumRoutine::applyConditions(
    const PlayersPtr  players,
    const Conditions& conditions
) const {
    RoutineConfigPtr routineConfig(new StrategicPureEquilibriumRoutineConfig(players));
    for (const ConditionPtr& condition : conditions)
        condition->configureRoutine(routineConfig);
    return *dynamic_pointer_cast<StrategicPureEquilibriumRoutineConfig>(routineConfig);
}

bool StrategicPureEquilibriumRoutine::arePositionsAllowed(
    const StrategicPureEquilibriumRoutineConfig& routineConfig,
    const Positions&                             currentPositions
) const {
    for (const Positions::value_type& positionPair : currentPositions) {
        const Identifier& playerName = positionPair.first;
        const Identifier& strategy   = positionPair.second;

        const Identifiers& allowedForPlayer = routineConfig.getAvailableStrategies(playerName);

        bool isAllowed = allowedForPlayer.end() != find_if(
            allowedForPlayer.begin(),
            allowedForPlayer.end(),
            [strategy](const IdentifierPtr& checkedStrategy) {
                return strategy == *checkedStrategy;
            }
        );
        if (!isAllowed)
            return false;
    }

    return true;
}

bool StrategicPureEquilibriumRoutine::isNashEquilibrium(
    const StrategicDataAccessor& data,
    const Positions&             currentPositions
) const {
    const DataPiecePtr& currentPayoffs = data.getPayoffs(currentPositions);

    for (const Players::value_type& playerPair : *data.getPlayers()) {
        const Identifier&  playerName      = playerPair.first;
        const Identifiers& strategies      = *playerPair.second->getStrategies();
        const Identifier&  currentStrategy = currentPositions.at(playerName);
        const NumberPtr&   currentPayoff   = currentPayoffs->getPayoff(playerName);

        for (const IdentifierPtr& strategyPtr : strategies) {
            const Identifier& strategy = *strategyPtr;

            if (strategy != currentStrategy) {
                Positions checkedPosition(currentPositions);
                checkedPosition[playerName] = strategy;

                const DataPiecePtr& checkedPayoffs = data.getPayoffs(checkedPosition);
                if (*currentPayoff < *checkedPayoffs->getPayoff(playerName))
                    return false;
            }
        }
    }

    return true;
}

// }; /* END class StrategicPureEquilibriumRoutine */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
