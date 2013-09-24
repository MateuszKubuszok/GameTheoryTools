#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

//class MixedGame {
// public:

MixedGame::MixedGame(
    PlayersPtr newPlayers,
    DataPtr    newData
) :
    players(newPlayers),
    data(newData)
    {}

PlayersPtr MixedGame::getPlayers() {
    return players;
}

DataAccessorPtr MixedGame::equilibriumData() {
	return DataAccessorPtr(new MixedDataAccessor(data));
}

Message MixedGame::toString() {
	IdentifierPtr name      = createIdentifierPtr("Mixed Game");
	MessagePtr    subresult = createMessagePtr(data->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, subresult).build()->getResult();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
