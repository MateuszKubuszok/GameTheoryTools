#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class Details : public virtual ValidableSymbol {
// public:

Details::Details(
    const ObjectsPtr     playersDetails,
    const CoordinatesPtr coordinatesDetails
) :
    players(playersDetails),
    coordinates(coordinatesDetails)
    {}

const CoordinatesPtr Details::getCoordinates() const {
    return coordinates;
}

const ObjectsPtr Details::getPlayers() const {
    return players;
}

Message Details::toString() const {
    ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();

    static const IdentifierPtr playersName = createIdentifierPtr("Players");
    static const IdentifierPtr playerName  = createIdentifierPtr("Player");
    ResultBuilderPtr playersResultBuilder  = ResultFactory::getInstance().buildResult();
    for (const ObjectPtr& player : *players) {
        MessagePtr playerValue = createMessagePtr(player->toString());
        playersResultBuilder->addResult(playerName, playerValue);
    }
    MessagePtr playersValue = createMessagePtr(playersResultBuilder->build()->getResult());
    resultBuilder->addResult(playersName, playersValue);

    static const IdentifierPtr coordinatesName = createIdentifierPtr("Coordinates");
    static const IdentifierPtr coordinateName  = createIdentifierPtr("Coordinate");
    ResultBuilderPtr coordinatesResultBuilder  = ResultFactory::getInstance().buildResult();
    for (const CoordinatePtr& coordinate : *coordinates) {
        MessagePtr coordinateValue = createMessagePtr(coordinate->toString());
        coordinatesResultBuilder->addResult(coordinateName, coordinateValue);
    }
    MessagePtr coordinatesValue = createMessagePtr(coordinatesResultBuilder->build()->getResult());
    resultBuilder->addResult(coordinatesName, coordinatesValue);

    return resultBuilder->build()->getResult();
}

// }; /* END class Details */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
