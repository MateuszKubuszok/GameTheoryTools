/**
 * @file      gt/model/strategic_data_builder.cpp
 * @brief     Defines GT::Model::StrategicDataBuilder methods.
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

#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using boost::adaptors::map_keys;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class StrategicDataBuilder final : public DataBuilder {
// public:

StrategicDataBuilder::StrategicDataBuilder() :
    data(InnerNullFactory::getInstance().createStrategicData()),
    players(NullFactory::getInstance().createPlayers()),
    currentPositions(),
    currentlyKnownPositions()
    {}

StrategicDataPtr StrategicDataBuilder::build() const {
    return data;
}

const PlayersPtr StrategicDataBuilder::getPlayers() const {
    return players;
}

DataBuilder& StrategicDataBuilder::setPlayers(
    const PlayersPtr newPlayers
) {
    if (data->isNotNull())
        throw ExceptionFactory::getInstance().playersAlreadySet();

    checkPlayers(newPlayers);

    data    = StrategicDataPtr(new StrategicData(newPlayers));
    players = newPlayers;

    return *this;
}

DataBuilder& StrategicDataBuilder::addNextPositions(
    const PositionsPtr positions
) {
    for (Positions::value_type& position : (*positions)) {
        if (currentlyKnownPositions.count(position.first) && currentlyKnownPositions[position.first])
            throw ExceptionFactory::getInstance().coordinatesAlreadySet(*positions);

        const PlayerPtr player = (*players)[position.first];
        if (!player)
            throw ExceptionFactory::getInstance().invalidPlayer(position.first);

        if (!player->hasStrategy(position.second))
            throw ExceptionFactory::getInstance().invalidCoordinateFormat(*positions);
    }

    for (Positions::value_type& position : (*positions)) {
        currentPositions.insert( position );
        currentlyKnownPositions.insert( KnownPositions::value_type(position.first, true) );
    }

    return *this;
}

DataBuilder& StrategicDataBuilder::setPayoffs(
    const NumbersPtr params
) {
    for (Identifier player : (*players) | map_keys)
        if (!currentlyKnownPositions.count(player) || !currentlyKnownPositions[player])
            throw ExceptionFactory::getInstance().incompleteCoordinates();

    data->setPayoffs(currentPositions, params);

    return *this;
}

DataBuilderPtr StrategicDataBuilder::clone() const {
    return DataBuilderPtr(new StrategicDataBuilder(*this));
}

Message StrategicDataBuilder::toString() const {
    static const IdentifierPtr name    = createIdentifierPtr("Current Data");
    const MessagePtr           message = createMessagePtr(data->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, message).build()->getResult();
}

// }; /* END class StrategicDataBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
