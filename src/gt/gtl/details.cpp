#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class Details {
// public:

Details::Details(
    const ObjectsPtr     playersDetails,
    const CoordinatesPtr coordinatesDetails
) :
    players(playersDetails),
    coordinates(coordinatesDetails)
    {}

CoordinatesPtr Details::getCoordinates() {
    return coordinates;
}

ObjectsPtr Details::getPlayers() {
    return players;
}

Message Details::toString() {
    ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();

    IdentifierPtr playersName = createIdentifierPtr("Players");
    ResultBuilderPtr playersResultBuilder = ResultFactory::getInstance().buildResult();
    IdentifierPtr playerName = createIdentifierPtr("Player");
    BOOST_FOREACH(ObjectPtr& player, *players) {
        MessagePtr playerValue = createMessagePtr(player->toString());
        playersResultBuilder->addResult(playerName, playerValue);
    }
    MessagePtr playersValue = createMessagePtr(playersResultBuilder->build()->getResult());
    resultBuilder->addResult(playersName, playersValue);

    IdentifierPtr coordinatesName = createIdentifierPtr("Coordinates");
    ResultBuilderPtr coordinatesResultBuilder = ResultFactory::getInstance().buildResult();
    IdentifierPtr coordinateName = createIdentifierPtr("Coordinate");
    BOOST_FOREACH(CoordinatePtr& coordinate, *coordinates) {
        MessagePtr coordinateValue = createMessagePtr(coordinate->toString());
        coordinatesResultBuilder->addResult(coordinateName, coordinateValue);
    }
    MessagePtr coordinatesValue = createMessagePtr(coordinatesResultBuilder->build()->getResult());
    resultBuilder->addResult(coordinatesName, coordinatesValue);

    return resultBuilder->build()->getResult();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
