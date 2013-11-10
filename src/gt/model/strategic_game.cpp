#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//class StrategicGame : public Game {
// public:

StrategicGame::StrategicGame(
    const PlayersPtr       newPlayers,
    const StrategicDataPtr newData
) :
    players(newPlayers),
    data(newData)
    {}

const PlayersPtr StrategicGame::getPlayers() const {
    return players;
}

const DataAccessorPtr StrategicGame::getData() const {
    return DataAccessorPtr(new StrategicDataAccessor(data));
}

Message StrategicGame::toString() const {
    IdentifierPtr name      = createIdentifierPtr("Strategic Game");
    MessagePtr    subresult = createMessagePtr(data->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, subresult).build()->getResult();
}

// }; /* END class StrategicGame */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
