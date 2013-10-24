#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class CheckingGameDriver {
// public:

CheckingGameDriver::CheckingGameDriver(
    Driver* parentDriver
) :
    driver(parentDriver)
    {}

GamePtr* CheckingGameDriver::createStrategic(
    InputLocation& inputLocation,
    DetailsPtr*    detailsPtr
) {
    Details& details = **detailsPtr;

    if (!details) {
        Message errorMessage = Message() +
            "Invalid Details: " + details.toString();
        return new GamePtr(
            setupLocation<Game>(
                ErrorFactory::getInstance().createGame(errorMessage),
                inputLocation
            )
        );
    }

    return new GamePtr(
        setupLocation<Game>(
            NullFactory::getInstance().createGame(),
            inputLocation
        )
    );
}

GamePtr* CheckingGameDriver::createExtensive(
    InputLocation& inputLocation,
    DetailsPtr*    detailsPtr
) {
    Details& details = **detailsPtr;

    if (!details) {
        Message errorMessage = Message() +
            "Invalid Details: " + details.toString();
        return new GamePtr(
            setupLocation<Game>(
                ErrorFactory::getInstance().createGame(errorMessage),
                inputLocation
            )
        );
    }

    return new GamePtr(
        setupLocation<Game>(
            NullFactory::getInstance().createGame(),
            inputLocation
        )
    );
}

DetailsPtr* CheckingGameDriver::createDetails(
    InputLocation&  inputLocation,
    ObjectsPtr*     playersPtr,
    CoordinatesPtr* dataPtr
) {
    Objects&     objectPlayers = **playersPtr;
    Coordinates& coordinates   = **dataPtr;

    for (ObjectPtr& objectPlayerPtr : objectPlayers) {
        Object& objectPlayer = *objectPlayerPtr;
        Player& player       = objectPlayer;
        Param&  param        = objectPlayer;
        if (!player && !param) {
            Message errorMessage = Message() +
                "Invalid Player: " + player.toString();
            return new DetailsPtr(
                setupLocation<Details>(
                    ErrorFactory::getInstance().createDetails(errorMessage),
                    inputLocation
                )
            );
        }
    }

    for (CoordinatePtr& coordinatePtr : coordinates) {
        Coordinate& coorinate = *coordinatePtr;
        if (!coorinate) {
            Message errorMessage = Message() +
                "Invalid Data: " + coorinate.toString();
            return new DetailsPtr(
                setupLocation<Details>(
                    ErrorFactory::getInstance().createDetails(errorMessage),
                    inputLocation
                )
            );
        }
    }

    return new DetailsPtr(
        setupLocation<Details>(
            NullFactory::getInstance().createDetails(),
            inputLocation
        )
    );
}

PlayerPtr* CheckingGameDriver::createPlayer(
    InputLocation&  inputLocation,
    IdentifierPtr*,
    IdentifiersPtr*
) {
    return new PlayerPtr(
        setupLocation<Player>(
            NullFactory::getInstance().createPlayer(),
            inputLocation
        )
    );
}

Message CheckingGameDriver::toString() {
    return Message("CheckingGameDriver");
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
