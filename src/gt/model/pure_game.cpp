#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

//class PureGame {
// public:

PureGame::PureGame(
    PlayersPtr newPlayers,
    DataPtr    newData
) :
    players(newPlayers),
    data(newData)
    {}

PlayersPtr PureGame::getPlayers() {
    return players;
}

Message PureGame::toString() {
    // TODO
    return Message();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
