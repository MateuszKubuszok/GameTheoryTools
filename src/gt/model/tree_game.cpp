#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

//class TreeGame {
// public:

TreeGame::TreeGame(
    PlayersPtr  newPlayers,
    TreeDataPtr newData
) :
    players(newPlayers),
    data(newData)
    {}

PlayersPtr TreeGame::getPlayers() {
    return players;
}

DataAccessorPtr TreeGame::getData() {
    return DataAccessorPtr(new TreeDataAccessor(data));
}

Message TreeGame::toString() {
    IdentifierPtr name      = createIdentifierPtr("Tree Game");
    MessagePtr    subresult = createMessagePtr(data->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, subresult).build()->getResult();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
