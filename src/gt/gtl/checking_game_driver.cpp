#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class CheckingGameDriver : public GameDriver {
// public:

CheckingGameDriver::CheckingGameDriver(
    Driver* parentDriver
) :
    driver(parentDriver)
    {}

GamePtr* CheckingGameDriver::createStrategic(
    const InputLocation& inputLocation,
    const DetailsPtr*    detailsPtr
) const {
    const Details& details = **detailsPtr;

    if (!details) {
        // TODO: create ErrorMessageFactory
        Message errorMessage = Message() +
            "Invalid Details: " + details.toString();
        return new GamePtr(
            setupLocation<Game>(
                ErrorFactory::getInstance().createGame(errorMessage),
                *details.getInputLocation()
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
    const InputLocation& inputLocation,
    const DetailsPtr*    detailsPtr
) const {
    const Details& details = **detailsPtr;

    if (!details) {
        // TODO: create ErrorMessageFactory
        Message errorMessage = Message() +
            "Invalid Details: " + details.toString();
        return new GamePtr(
            setupLocation<Game>(
                ErrorFactory::getInstance().createGame(errorMessage),
                *details.getInputLocation()
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
    const InputLocation&  inputLocation,
    const ObjectsPtr*     playersPtr,
    const CoordinatesPtr* dataPtr
) const {
    const Objects&     objectPlayers = **playersPtr;
    const Coordinates& coordinates   = **dataPtr;

    for (const ObjectPtr& objectPlayerPtr : objectPlayers) {
        const Object& objectPlayer = *objectPlayerPtr;
        const Player& player       = objectPlayer;
        const Param&  param        = objectPlayer;
        if (!player && !param) {
            // TODO: create ErrorMessageFactory
            Message errorMessage = Message() +
                "Invalid Player: " + player.toString();
            return new DetailsPtr(
                setupLocation<Details>(
                    ErrorFactory::getInstance().createDetails(errorMessage),
                    *player.getInputLocation()
                )
            );
        }
    }

    for (const CoordinatePtr& coordinatePtr : coordinates) {
        const Coordinate& coordinate = *coordinatePtr;
        if (!coordinate) {
            // TODO: create ErrorMessageFactory
            Message errorMessage = Message() +
                "Invalid Data: " + coordinate.toString();
            return new DetailsPtr(
                setupLocation<Details>(
                    ErrorFactory::getInstance().createDetails(errorMessage),
                    *coordinate.getInputLocation()
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
    const InputLocation&  inputLocation,
    const IdentifierPtr*,
    const IdentifiersPtr*
) const {
    return new PlayerPtr(
        setupLocation<Player>(
            NullFactory::getInstance().createPlayer(),
            inputLocation
        )
    );
}

Message CheckingGameDriver::toString() const {
    return Message("CheckingGameDriver");
}

// }; /* END class CheckingGameDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
