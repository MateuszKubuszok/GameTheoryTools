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

ContextPtr Details::createSubContext(
    const Context& parentContext
) {
    return NullFactory::getInstance().createContext();
}

CoordinatesPtr Details::getCoordinates() {
    return NullFactory::getInstance().createCoordinates();
}

ObjectsPtr Details::getPlayers() {
    return NullFactory::getInstance().createObjects();
}

Message Details::toString() {
    return Message("NullDetails");
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
