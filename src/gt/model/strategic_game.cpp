#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

//class StrategicGame {
// public:

StrategicGame::StrategicGame(
    PlayersPtr       newPlayers,
    StrategicDataPtr newData
) :
    players(newPlayers),
    data(newData)
    {}

PlayersPtr StrategicGame::getPlayers() {
    return players;
}

DataAccessorPtr StrategicGame::equilibriumData() {
    return DataAccessorPtr(new StrategicDataAccessor(data));
}

Message StrategicGame::toString() {
    IdentifierPtr name      = createIdentifierPtr("Strategic Game");
    MessagePtr    subresult = createMessagePtr(data->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, subresult).build()->getResult();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
