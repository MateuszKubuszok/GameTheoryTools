/**
 * @file      gt/gtl/details.cpp
 * @brief     Defines GT::GTL::Details methods.
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
