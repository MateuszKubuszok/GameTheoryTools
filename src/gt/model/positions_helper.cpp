#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class PositionsHelper { 
// public:

PositionsHelper::PositionsHelper(
    PlayersPtr playersDefinitions
) :
    players(playersDefinitions),
    playersHelper(),
    strategiesHelper(),
    positionsHelper()
{
    Index playerIndex   = 0;
    Index positionIndex = 1;

    BOOST_FOREACH(Players::value_type playerPair, (*players)) {
        const Identifier& playerName = playerPair.first;
        Player& player = *playerPair.second;

        IdentifierMap strategiesMap;
        BOOST_FOREACH(IdentifierPtr& strategy, (*player.getStrategies()))
            strategiesMap.insert( IdentifierMap::value_type(*strategy, player.getStrategyOrdinal(*strategy)) );
        playersHelper.insert( IdentifierMap::value_type(playerName, playerIndex) );
        positionsHelper.insert( IdentifierMap::value_type(playerName, positionIndex) );
        strategiesHelper.insert( StrategyMap::value_type(playerName, strategiesMap) );

        playerIndex++;
        positionIndex *= player.getStrategiesNumber();
    }

    upperBound = positionIndex;
}

PlayersPtr PositionsHelper::getPlayers() {
    return players;
}

Index PositionsHelper::getUpperBound() {
    return upperBound;
}

Index PositionsHelper::calculatePlayer(
    Identifier& playerName
) {
    return playersHelper.left.at(playerName);
}

Index PositionsHelper::calculatePlayer(
    IdentifierPtr playerName
) {
    return calculatePlayer(*playerName);
}

IdentifierPtr PositionsHelper::retrievePlayer(
    Index playerPosition
) {
    return createIdentifierPtr(playersHelper.right.at(playerPosition));
}

Index PositionsHelper::calculatePosition(
    Positions& positions
) {
    Index storagePosition = 0;
    BOOST_FOREACH(Positions::value_type& position, positions) {
        Identifier playerName   = position.first;
        Identifier strategyName = position.second;
        storagePosition +=
            positionsHelper.left.at(playerName)
            *
            strategiesHelper[playerName].left.at(strategyName);
    }
    return storagePosition;
}

Index PositionsHelper::calculatePosition(
    PositionsPtr positions
) {
    return calculatePosition(*positions);
}

PositionsPtr PositionsHelper::retrievePositions(
    Index positionInStorage
) {
    PositionsPtr positions = createPositionsPtr();

    BOOST_FOREACH(Index playerValue, positionsHelper.right
                                    | boost::adaptors::map_keys
                                    | boost::adaptors::reversed
    ) {
        Identifier playerName = positionsHelper.right.at(playerValue);
        for (Index strategyValue = strategiesHelper[playerName].size()-1;
                   strategyValue >= 0;
                   strategyValue--
        ) {
            if (playerValue*strategyValue <= positionInStorage) {
                positions->insert(
                    Positions::value_type(
                        playerName,
                        strategiesHelper[playerName].right.at(strategyValue)
                    )
                );
                positionInStorage -= playerValue*strategyValue;
                break;
            }
        }
    }

    return positions;
}

bool PositionsHelper::checkPlayer(
    Identifier& playerName
) {
    return playersHelper.left.count(playerName);
}

bool PositionsHelper::checkPlayer(
    IdentifierPtr playerName
) {
    return checkPlayer(*playerName);
}

bool PositionsHelper::checkPositions(
    Positions& positions
) {
    BOOST_FOREACH(Identifier playerName, positions | boost::adaptors::map_keys) {
        if (!checkPlayer(playerName))
            return false;
        Identifier strategyName = positions[playerName];
        if (!strategiesHelper[playerName].left.count(strategyName))
            return false;
    }
    return true;
}

bool PositionsHelper::checkPositions(
    PositionsPtr positions
) {
    return checkPositions(*positions);
}

Message PositionsHelper::toString() {
    ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();
    IdentifierPtr    name          = createIdentifierPtr("Player");
    BOOST_FOREACH(Players::value_type& player, (*players)) {
        MessagePtr playerContent = createIdentifierPtr(player.second->toString());
        resultBuilder->addResult(name, playerContent);
    }
    return resultBuilder->build()->getResult();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
