#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class TreeData { 
// public:

TreeData::TreeData(
    PlayersPtr playersDefinitions
) :
    players(playersDefinitions),
    root(new TreeDataNode()),
    playersInTurns(new PlayersInTurns())
    {}

PlayersPtr TreeData::getPlayers() {
    return players;
}

PlayersInTurnsPtr TreeData::getPlayersInTurns() {
    return playersInTurns;
}

DataPiecePtr TreeData::getValues(
    Positions& positions
) {
    for (Positions::value_type& position : positions) {
        Identifier turn     = position.first;
        Identifier strategy = position.second;
        if (!playersInTurns->count(turn) || !(*playersInTurns)[turn]->hasStrategy(strategy))
            throw ExceptionFactory::getInstance().invalidCoordinateFormat(positions);
    }

    NumbersPtr payoff = root->getValues(positions);
    return DataPiecePtr(new PlainDataPiece(players, payoff));
}

DataPiecePtr TreeData::getValues(
    PositionsPtr positions
) {
    return getValues(*positions);
}

Data& TreeData::setValues(
    Positions& positions,
    NumbersPtr numbers
) {
    for (Positions::value_type& position : positions) {
        Identifier turn     = position.first;
        Identifier strategy = position.second;
        if (!playersInTurns->count(turn) || !(*playersInTurns)[turn]->hasStrategy(strategy))
            throw ExceptionFactory::getInstance().invalidCoordinateFormat(positions);
    }

    root->setValues(positions, numbers);

    return *this;
}

Data& TreeData::setValues(
    PositionsPtr positions,
    NumbersPtr   numbers
) {
    return setValues(*positions, numbers);
}

DataPiecePtr TreeData::operator[](
    Positions& positions
) {
    return getValues(positions);
}

DataPiecePtr TreeData::operator[](
    PositionsPtr positions
) {
    return getValues(positions);
}

Message TreeData::toString() {
    IdentifierPtr name   = createIdentifierPtr("TreeData");
    MessagePtr    result = createMessagePtr(root->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, result).build()->getResult();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
