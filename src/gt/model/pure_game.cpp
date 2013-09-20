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
	IdentifierPtr name      = createIdentifierPtr("Pure Game");
	MessagePtr    subresult = createMessagePtr(data->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, subresult).build()->getResult();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
