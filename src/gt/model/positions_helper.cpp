#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class PositionsHelper : public Root {
// public:

PositionsHelper::PositionsHelper(
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

const PlayersPtr PositionsHelper::getPlayers() const {
    return players;
}

Index PositionsHelper::getUpperBound() const {
    return upperBound;
}

Index PositionsHelper::calculatePlayer(
    const Identifier& playerName
) const {
    return playersHelper.left.at(playerName);
}

Index PositionsHelper::calculatePlayer(
    const IdentifierPtr playerName
) const {
    return calculatePlayer(*playerName);
}

const IdentifierPtr PositionsHelper::retrievePlayer(
    const Index playerPosition
) const {
    return createIdentifierPtr(playersHelper.right.at(playerPosition));
}

Index PositionsHelper::calculatePosition(
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

Index PositionsHelper::calculatePosition(
    const PositionsPtr positions
) const {
    return calculatePosition(*positions);
}

const PositionsPtr PositionsHelper::retrievePositions(
    const Index positionInStorage
) const {
    PositionsPtr positions       = createPositionsPtr();
    Index        checkedPosition = positionInStorage;

    for (Index playerValue : positionsHelper.right
                           | boost::adaptors::map_keys
                           | boost::adaptors::reversed
    ) {
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

    return positions;
}

bool PositionsHelper::checkPlayer(
    const Identifier& playerName
) const {
    return playersHelper.left.count(playerName);
}

bool PositionsHelper::checkPlayer(
    const IdentifierPtr playerName
) const {
    return checkPlayer(*playerName);
}

bool PositionsHelper::checkPositions(
    const Positions& positions
) const {
    for (Identifier playerName : positions | boost::adaptors::map_keys) {
        if (!checkPlayer(playerName))
            return false;
        Identifier strategyName = positions.at(playerName);
        if (!strategiesHelper.at(playerName).left.count(strategyName))
            return false;
    }
    return true;
}

bool PositionsHelper::checkPositions(
    const PositionsPtr positions
) const {
    return checkPositions(*positions);
}

Message PositionsHelper::toString() const {
    ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();
    IdentifierPtr    name          = createIdentifierPtr("Player");
    for (const Players::value_type& player : (*players)) {
        MessagePtr playerContent = createIdentifierPtr(player.second->toString());
        resultBuilder->addResult(name, playerContent);
    }
    return resultBuilder->build()->getResult();
}

// }; /* END class PositionsHelper */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
