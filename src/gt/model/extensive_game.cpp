#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExtensiveGame : public Game {
// public:

ExtensiveGame::ExtensiveGame(
    const PlayersPtr       newPlayers,
    const ExtensiveDataPtr newData
) :
    players(newPlayers),
    data(newData)
    {}

const PlayersPtr ExtensiveGame::getPlayers() const {
    return players;
}

const DataAccessorPtr ExtensiveGame::getData() const {
    return DataAccessorPtr(new ExtensiveDataAccessor(data));
}

Message ExtensiveGame::toString() const {
    IdentifierPtr name      = createIdentifierPtr("Extensive Game");
    MessagePtr    subresult = createMessagePtr(data->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, subresult).build()->getResult();
}

// }; /* END class ExtensiveGame */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
