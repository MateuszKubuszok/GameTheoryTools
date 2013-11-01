#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExtensiveData : public Data {
// public:

ExtensiveData::ExtensiveData(
    PlayersPtr playersDefinitions
) :
    players(playersDefinitions),
    root(new ExtensiveDataNode())
    {}

PlayersPtr ExtensiveData::getPlayers() {
    return players;
}

PlayerPtr ExtensiveData::getPlayerInTurn(
    Positions& positions
) {
    return root->getPlayer(positions);
}

PlayerPtr ExtensiveData::getPlayerInTurn(
    PositionsPtr positions
) {
    return getPlayerInTurn(*positions);
}

Data& ExtensiveData::setPlayerInTurn(
    Positions& positions,
    PlayerPtr  player
) {
    root->setPlayer(positions, player);
    return *this;
}

Data& ExtensiveData::setPlayerInTurn(
    PositionsPtr positions,
    PlayerPtr   player
) {
    return setPlayerInTurn(*positions, player);
}

DataPiecePtr ExtensiveData::getValues(
    Positions& positions
) {
    Positions checkedPositions;

    for (Positions::value_type& position : positions) {
        PlayerPtr   playedPlayer = getPlayerInTurn(checkedPositions);
        Identifier& strategy     = position.second;

        if (!playedPlayer->hasStrategy(strategy))
            throw ExceptionFactory::getInstance().invalidCoordinateFormat(positions);

        checkedPositions.insert( position );
    }

    NumbersPtr payoff = root->getValues(positions);
    return DataPiecePtr(new PlainDataPiece(players, payoff));
}

DataPiecePtr ExtensiveData::getValues(
    PositionsPtr positions
) {
    return getValues(*positions);
}

Data& ExtensiveData::setValues(
    Positions& positions,
    NumbersPtr numbers
) {
    Positions checkedPositions;

    for (Positions::value_type& position : positions) {
        PlayerPtr   playedPlayer = getPlayerInTurn(checkedPositions);
        Identifier& strategy     = position.second;

        if (!playedPlayer->hasStrategy(strategy))
            throw ExceptionFactory::getInstance().invalidCoordinateFormat(positions);

        checkedPositions.insert( position );
    }

    root->setValues(positions, numbers);

    return *this;
}

Data& ExtensiveData::setValues(
    PositionsPtr positions,
    NumbersPtr   numbers
) {
    return setValues(*positions, numbers);
}

DataPiecePtr ExtensiveData::operator[](
    Positions& positions
) {
    return getValues(positions);
}

DataPiecePtr ExtensiveData::operator[](
    PositionsPtr positions
) {
    return getValues(positions);
}

Message ExtensiveData::toString() {
    IdentifierPtr name   = createIdentifierPtr("ExtensiveData");
    MessagePtr    result = createMessagePtr(root->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, result).build()->getResult();
}

// }; /* END class ExtensiveData */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
