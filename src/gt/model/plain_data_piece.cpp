#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class PlainDataPiece : public DataPiece {
// public:

PlainDataPiece::PlainDataPiece(
    const PlayersPtr players,
    const NumbersPtr params
) :
    positionsHelper(players),
    numbers(params)
    {}

const NumberPtr& PlainDataPiece::getValue(
    const Identifier& playerName
) const {
    if (!positionsHelper.checkPlayer(playerName))
        throw ExceptionFactory::getInstance().invalidPlayer(playerName);
    return (*numbers)[positionsHelper.calculatePlayer(playerName)];
}

Message PlainDataPiece::toString() const {
    static const IdentifierPtr  name = createIdentifierPtr("Payoff");
    const IdentifiersPtr        players(new Identifiers());
    const MessagesPtr           values(new Messages());

    for (Identifier playerName : (*positionsHelper.getPlayers()) | boost::adaptors::map_keys) {
        players->push_back( createIdentifierPtr(playerName) );
        values->push_back( createMessagePtr((*numbers)[positionsHelper.calculatePlayer(playerName)]) );
    }

    ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();
    resultBuilder->setHeaders(players).addRecord( name, values );
    return resultBuilder->build()->getResult();
}

// }; /* END class PlainDataPiece */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
