#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class PlainDataPiece {
// public:

PlainDataPiece::PlainDataPiece(
    IdentifierMap players,
    NumbersPtr    params
) :
    playersMap(players),
    numbers(params)
    {}

NumberPtr& PlainDataPiece::getValue(
    Identifier& playerName
) {
    if (!playersMap.left.count(playerName))
        throw InvalidCoordinate("No such Player");
    return (*numbers)[playersMap.left.at(playerName)];
}

Message PlainDataPiece::toString() {
    IdentifierPtr  name = createIdentifierPtr("Payoff");
    IdentifiersPtr players(new Identifiers());
    MessagesPtr    values(new Messages());

    BOOST_FOREACH(Identifier playerName, playersMap.left | boost::adaptors::map_keys) {
        players->push_back( createIdentifierPtr(playerName) );
        values->push_back( createMessagePtr((*numbers)[playersMap.left.at(playerName)]) );
    }

    ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();
    resultBuilder->setHeaders(players).addRecord( name, values );
    return resultBuilder->build()->getResult();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
