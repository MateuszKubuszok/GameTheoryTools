/**
 * @file      gt/model/strategic_game_positions_helper.cpp
 * @brief     Defines GT::Model::StrategicGamePositionsHelper methods.
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

#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using boost::adaptors::map_keys;
using boost::adaptors::reversed;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class StrategicGamePositionsHelper final : public Root {
// public:

StrategicGamePositionsHelper::StrategicGamePositionsHelper(
    const PlayersPtr playersDefinitions
) :
    players(playersDefinitions),
    playersHelper(),
    strategiesHelper(),
    positionsHelper()
{
    Index playerIndex   = 0;
    Index positionIndex = 1;

    for (const Players::value_type& playerPair : (*players)) {
        const Identifier& playerName = playerPair.first;
        const Player&     player     = *playerPair.second;
        const Identifiers strategies = *player.getStrategies(); // usage of reference here makes valgrind
                                                                // yell "Invalid read of size 8" in for below

        IdentifierMap strategiesMap;
        for (const IdentifierPtr& strategy : strategies)
            strategiesMap.insert(IdentifierMap::value_type(*strategy, player.getStrategyOrdinal(*strategy)));
        playersHelper.insert( IdentifierMap::value_type(playerName, playerIndex) );
        positionsHelper.insert( IdentifierMap::value_type(playerName, positionIndex) );
        strategiesHelper.insert( StrategyMap::value_type(playerName, strategiesMap) );

        playerIndex++;
        positionIndex *= player.getStrategiesNumber();
    }

    upperBound = positionIndex;
}

const PlayersPtr StrategicGamePositionsHelper::getPlayers() const {
    return players;
}

Index StrategicGamePositionsHelper::getUpperBound() const {
    return upperBound;
}

Index StrategicGamePositionsHelper::calculatePlayer(
    const Identifier& playerName
) const {
    return playersHelper.left.at(playerName);
}

Index StrategicGamePositionsHelper::calculatePlayer(
    const IdentifierPtr playerName
) const {
    return calculatePlayer(*playerName);
}

const IdentifierPtr StrategicGamePositionsHelper::retrievePlayer(
    const Index playerPosition
) const {
    return createIdentifierPtr(playersHelper.right.at(playerPosition));
}

Index StrategicGamePositionsHelper::calculatePosition(
    const Positions& positions
) const {
    Index storagePosition = 0;
    for (const Positions::value_type& position : positions) {
        const Identifier playerName   = position.first;
        const Identifier strategyName = position.second;
        storagePosition +=
            // dirty hack to "handle" situation when some players have only 1 strategy
            (positionsHelper.left.count(playerName) ? positionsHelper.left.at(playerName) : 0)
            *
            strategiesHelper.at(playerName).left.at(strategyName);
    }
    return storagePosition;
}

Index StrategicGamePositionsHelper::calculatePosition(
    const PositionsPtr positions
) const {
    return calculatePosition(*positions);
}

const PositionsPtr StrategicGamePositionsHelper::retrievePositions(
    const Index positionInStorage
) const {
    PositionsPtr positions       = createPositionsPtr();
    Index        checkedPosition = positionInStorage;

    // this adds at most one Player with only 1 strategy!
    for (Index playerValue : positionsHelper.right | map_keys | reversed) {
        Identifier playerName = positionsHelper.right.at(playerValue);
        for (Index strategyValue = strategiesHelper.at(playerName).size()-1;
                   true;
                   strategyValue--
        ) {
            if (playerValue*strategyValue <= checkedPosition) {
                positions->insert(
                    Positions::value_type(
                        playerName,
                        strategiesHelper.at(playerName).right.at(strategyValue)
                    )
                );
                checkedPosition -= playerValue*strategyValue;
                break;
            }
            if (!strategyValue)
                break;
        }
    }

    // dirty hack adding all missing Players with just 1 strategy
    for (const Players::value_type& player : *players) {
        const Identifier& playerName     = player.first;
        const Player&     playerInstance = *player.second;

        if (playerInstance.getStrategiesNumber() == 1 && !positions->count(playerName)) {
            const Identifier& strategy = *(*playerInstance.getStrategies())[0];

            positions->insert(
                Positions::value_type(
                    playerName,
                    strategy
                )
            );
        }
    }

    return positions;
}

bool StrategicGamePositionsHelper::checkPlayer(
    const Identifier& playerName
) const {
    return playersHelper.left.count(playerName);
}

bool StrategicGamePositionsHelper::checkPlayer(
    const IdentifierPtr playerName
) const {
    return checkPlayer(*playerName);
}

bool StrategicGamePositionsHelper::checkPositions(
    const Positions& positions
) const {
    for (Identifier playerName : positions | map_keys) {
        if (!checkPlayer(playerName))
            return false;
        Identifier strategyName = positions.at(playerName);
        if (!strategiesHelper.at(playerName).left.count(strategyName))
            return false;
    }
    return true;
}

bool StrategicGamePositionsHelper::checkPositions(
    const PositionsPtr positions
) const {
    return checkPositions(*positions);
}

Message StrategicGamePositionsHelper::toString() const {
    ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();
    IdentifierPtr    name          = createIdentifierPtr("Player");
    for (const Players::value_type& player : (*players)) {
        MessagePtr playerContent = createIdentifierPtr(player.second->toString());
        resultBuilder->addResult(name, playerContent);
    }
    return resultBuilder->build()->getResult();
}

// }; /* END class StrategicGamePositionsHelper */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
