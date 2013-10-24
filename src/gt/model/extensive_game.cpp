#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

//class ExtensiveGame {
// public:

ExtensiveGame::ExtensiveGame(
    PlayersPtr  newPlayers,
    ExtensiveDataPtr newData
) :
    players(newPlayers),
    data(newData)
    {}

PlayersPtr ExtensiveGame::getPlayers() {
    return players;
}

DataAccessorPtr ExtensiveGame::getData() {
    return DataAccessorPtr(new ExtensiveDataAccessor(data));
}

Message ExtensiveGame::toString() {
    IdentifierPtr name      = createIdentifierPtr("Extensive Game");
    MessagePtr    subresult = createMessagePtr(data->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, subresult).build()->getResult();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
