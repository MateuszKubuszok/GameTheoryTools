#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class StrategicDataPiece {
// public:

StrategicDataPiece::StrategicDataPiece(
    PlayersPtr players,
    NumbersPtr params
) :
    positionsHelper(players),
    numbers(params)
    {}

NumberPtr& StrategicDataPiece::getValue(
    Identifier& playerName
) {
    if (!positionsHelper.checkPlayer(playerName))
        throw ExceptionFactory::getInstance().invalidPlayer(playerName);
    return (*numbers)[positionsHelper.calculatePlayer(playerName)];
}

Message StrategicDataPiece::toString() {
    IdentifierPtr  name = createIdentifierPtr("Payoff");
    IdentifiersPtr players(new Identifiers());
    MessagesPtr    values(new Messages());

    BOOST_FOREACH(Identifier playerName, (*positionsHelper.getPlayers()) | boost::adaptors::map_keys) {
        players->push_back( createIdentifierPtr(playerName) );
        values->push_back( createMessagePtr((*numbers)[positionsHelper.calculatePlayer(playerName)]) );
    }

    ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();
    resultBuilder->setHeaders(players).addRecord( name, values );
    return resultBuilder->build()->getResult();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
