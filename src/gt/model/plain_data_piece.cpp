#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class PlainDataPiece {
// public:

PlainDataPiece::PlainDataPiece(
    IdentifierMap players,
    NumbersPtr    params
) :
    playersMap(players),
    numbers(params)
    {}

NumberPtr& PlainDataPiece::getValue(
    Identifier& playerName
) {
    if (!playersMap.left.count(playerName))
        throw InvalidCoordinate("No such player");
    return (*numbers)[playersMap.left.at(playerName)];
}

Message PlainDataPiece::toString() {
    // TODO
    return Message();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
