#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class ExtensiveData {
// public:

ExtensiveData::ExtensiveData(
    PlayersPtr playersDefinitions
) :
    players(playersDefinitions),
    root(new ExtensiveDataNode()),
    playersInTurns(new PlayersInTurns())
    {}

PlayersPtr ExtensiveData::getPlayers() {
    return players;
}

PlayersInTurnsPtr ExtensiveData::getPlayersInTurns() {
    return playersInTurns;
}

DataPiecePtr ExtensiveData::getValues(
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

DataPiecePtr ExtensiveData::getValues(
    PositionsPtr positions
) {
    return getValues(*positions);
}

Data& ExtensiveData::setValues(
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

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
