/**
 * @file      gt/gtl/checking_game_driver.cpp
 * @brief     Defines GT::GTL::CheckingGameDriver methods.
 * @copyright (C) 2013-2014
 * @author    Mateusz Kubuszok
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero
 * General Public License as published by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License along with this program. If not,
 * see [http://www.gnu.org/licenses/].
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class CheckingGameDriver final : public GameDriver {
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
