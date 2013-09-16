#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class PlainData { 
// public:

PlainData::PlainData(
    PlayersPtr playersDefinitions
) :
    players(playersDefinitions),
    playersHelper(),
    strategiesHelper(),
    positionsHelper(),
    paramsStorage(),
    paramsStorageAllocation()
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
}

DataPiecePtr PlainData::getValues(
    Index positionInStorage
) {
    if (!paramsStorageAllocation[positionInStorage])
        throw InvalidCoordinate("No params under such position");
    
    return DataPiecePtr(
        new PlainDataPiece(
            playersHelper,
            paramsStorage[positionInStorage]
        )
    );
}

DataPiecePtr PlainData::getValues(
    Positions& positions
) {
    return getValues(calculatePosition(positions));
}

DataPiecePtr PlainData::getValues(
    PositionsPtr positions
) {
    return getValues(*positions);
}

Data& PlainData::setValues(
    Index      positionInStorage,
    NumbersPtr numbers
) {
    paramsStorage[positionInStorage] = numbers;
    paramsStorageAllocation[positionInStorage] = true;

    return *this;
}

Data& PlainData::setValues(
    Positions& positions,
    NumbersPtr numbers
) {
    if (!checkPositions(positions))
        throw InvalidCoordinate("Invalid coordinates format");

    return setValues(
        calculatePosition(positions),
        numbers
    );
}

Data& PlainData::setValues(
    PositionsPtr positions,
    NumbersPtr   numbers
) {
    return setValues(*positions, numbers);
}

DataPiecePtr PlainData::operator[](
    Index positionInStorage
) {
    return getValues(positionInStorage);
}

DataPiecePtr PlainData::operator[](
    Positions& positions
) {
    return getValues(positions);
}

DataPiecePtr PlainData::operator[](
    PositionsPtr positions
) {
    return getValues(positions);
}

Message PlainData::toString() {
    return contentMessage()->getResult();
}

// private:

Index PlainData::calculatePlayer(
    Identifier& playerName
) {
    return playersHelper.left.at(playerName);
}

Index PlainData::calculatePlayer(
    IdentifierPtr playerName
) {
    return checkPlayer(*playerName);
}

Index PlainData::calculatePosition(
    Positions& positions
) {
    Index storagePosition = 0;
    BOOST_FOREACH(Positions::value_type& position, positions) {
        storagePosition +=
            positionsHelper.left.at(position.first)
            *
            strategiesHelper[position.first].left.at(position.second);
    }
    return storagePosition;
}

Index PlainData::calculatePosition(
    PositionsPtr positions
) {
    return calculatePosition(*positions);
}

bool PlainData::checkPlayer(
    Identifier& playerName
) {
    return playersHelper.left.count(playerName);
}

bool PlainData::checkPlayer(
    IdentifierPtr playerName
) {
    return checkPlayer(*playerName);
}

bool PlainData::checkPositions(
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

bool PlainData::checkPositions(
    PositionsPtr positions
) {
    return checkPositions(*positions);
}

ResultPtr PlainData::contentMessage() {
    // TODO: generate message with conetent using ResultBuilder
    return NullFactory::getInstance().createResult();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
