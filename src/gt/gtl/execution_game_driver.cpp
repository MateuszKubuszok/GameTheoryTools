#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class ExecutionGameDriver {
// public:

ExecutionGameDriver::ExecutionGameDriver(
    Driver* parentDriver
) :
    checkingGameDriver(parentDriver),
    driver(parentDriver)
    {}

GamePtr* ExecutionGameDriver::createStrategic(
    InputLocation& inputLocation,
    DetailsPtr*    detailsPtr
) {
    GamePtr* errorCheck = checkingGameDriver.createStrategic(inputLocation, detailsPtr);
    if (!(*errorCheck)->isValid())
        return errorCheck;

    // Details& details = **detailsPtr;

    return new GamePtr(
        setupLocation<Game>(
            NullFactory::getInstance().createGame(),
            inputLocation
        )
    );
}

GamePtr* ExecutionGameDriver::createExtensive(
    InputLocation& inputLocation,
    DetailsPtr*    detailsPtr
) {
    GamePtr* errorCheck = checkingGameDriver.createStrategic(inputLocation, detailsPtr);
    if (!(*errorCheck)->isValid())
        return errorCheck;

    // Details& details = **detailsPtr;

    return new GamePtr(
        setupLocation<Game>(
            NullFactory::getInstance().createGame(),
            inputLocation
        )
    );
}

DetailsPtr* ExecutionGameDriver::createDetails(
    InputLocation&  inputLocation,
    ObjectsPtr*     playersPtr,
    CoordinatesPtr* dataPtr
) {
    DetailsPtr* errorCheck = checkingGameDriver.createDetails(inputLocation, playersPtr, dataPtr);
    if (!(*errorCheck)->isValid())
        return errorCheck;

    // Objects&     objectPlayers = **playersPtr;
    // Coordinates& coordinates   = **dataPtr;

    return new DetailsPtr(
        setupLocation<Details>(
            NullFactory::getInstance().createDetails(),
            inputLocation
        )
    );
}

PlayerPtr* ExecutionGameDriver::createPlayer(
    InputLocation&  inputLocation,
    IdentifierPtr*  playerPtr,
    IdentifiersPtr* strategiesPtr
) {
    PlayerPtr* errorCheck = checkingGameDriver.createPlayer(inputLocation, playerPtr, strategiesPtr);
    if (!(*errorCheck)->isValid())
        return errorCheck;

    // IdentifierPtr&  player     = *playerPtr;
    // IdentifiersPtr& strategies = *strategiesPtr;

    return new PlayerPtr(
        setupLocation<Player>(
            NullFactory::getInstance().createPlayer(),
            inputLocation
        )
    );
}

Message ExecutionGameDriver::toString() {
    return Message("ExecutionGameDriver");
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
