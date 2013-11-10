#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExtensiveData : public Data {
// public:

ExtensiveData::ExtensiveData(
    const PlayersPtr playersDefinitions
) :
    players(playersDefinitions),
    root(new ExtensiveDataNode())
    {}

const PlayersPtr ExtensiveData::getPlayers() const {
    return players;
}

const PlayerPtr ExtensiveData::getPlayerInTurn(
    const Positions& positions
) const {
    return root->getPlayer(positions);
}

const PlayerPtr ExtensiveData::getPlayerInTurn(
    const PositionsPtr positions
) const {
    return getPlayerInTurn(*positions);
}

ExtensiveData& ExtensiveData::setPlayerInTurn(
    const Positions& positions,
    const PlayerPtr  player
) {
    root->setPlayer(positions, player);
    return *this;
}

ExtensiveData& ExtensiveData::setPlayerInTurn(
    const PositionsPtr positions,
    const PlayerPtr    player
) {
    return setPlayerInTurn(*positions, player);
}

const DataPiecePtr ExtensiveData::getValues(
    const Positions& positions
) const {
    Positions checkedPositions;

    for (const Positions::value_type& position : positions) {
        const PlayerPtr   playedPlayer = getPlayerInTurn(checkedPositions);
        const Identifier& strategy     = position.second;

        if (!playedPlayer->hasStrategy(strategy))
            throw ExceptionFactory::getInstance().invalidCoordinateFormat(positions);

        checkedPositions.insert( position );
    }

    NumbersPtr payoff = root->getValues(positions);
    return DataPiecePtr(new PlainDataPiece(players, payoff));
}

const DataPiecePtr ExtensiveData::getValues(
    const PositionsPtr positions
) const {
    return getValues(*positions);
}

Data& ExtensiveData::setValues(
    const Positions& positions,
    const NumbersPtr numbers
) {
    Positions checkedPositions;

    for (const Positions::value_type& position : positions) {
        const PlayerPtr   playedPlayer = getPlayerInTurn(checkedPositions);
        const Identifier& strategy     = position.second;

        if (!playedPlayer->hasStrategy(strategy))
            throw ExceptionFactory::getInstance().invalidCoordinateFormat(positions);

        checkedPositions.insert( position );
    }

    root->setValues(positions, numbers);

    return *this;
}

Data& ExtensiveData::setValues(
    const PositionsPtr positions,
    const NumbersPtr   numbers
) {
    return setValues(*positions, numbers);
}

Message ExtensiveData::toString() const {
    IdentifierPtr name   = createIdentifierPtr("ExtensiveData");
    MessagePtr    result = createMessagePtr(root->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, result).build()->getResult();
}

const DataPiecePtr ExtensiveData::operator[](
    const Positions& positions
) const {
    return getValues(positions);
}

const DataPiecePtr ExtensiveData::operator[](
    const PositionsPtr positions
) const {
    return getValues(positions);
}

// }; /* END class ExtensiveData */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
