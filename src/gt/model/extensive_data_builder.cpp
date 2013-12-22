/**
 * @file      gt/model/extensive_data_builder.cpp
 * @brief     Defines GT::Model::ExtensiveDataBuilder methods.
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

// class ExtensiveDataBuilder final : public DataBuilder {
// public:

ExtensiveDataBuilder::ExtensiveDataBuilder() :
    data(InnerNullFactory::getInstance().createExtensiveData()),
    players(NullFactory::getInstance().createPlayers()),
    currentPositions(),
    depthValue(1),
    depthName(createIdentifier(1))
    {}

ExtensiveDataPtr ExtensiveDataBuilder::build() const {
    return data;
}

const PlayersPtr ExtensiveDataBuilder::getPlayers() const {
    return players;
}

DataBuilder& ExtensiveDataBuilder::setPlayers(
    const PlayersPtr newPlayers
) {
    if (data->isNotNull())
        throw ExceptionFactory::getInstance().playersAlreadySet();

    data    = ExtensiveDataPtr(new ExtensiveData(newPlayers));
    players = newPlayers;

    return *this;
}

DataBuilder& ExtensiveDataBuilder::addNextPositions(
    const PositionsPtr positions
) {
    if (positions->size() != 1)
        throw ExceptionFactory::getInstance().invalidCoordinateFormat(*positions);

    Identifier player   = positions->begin()->first;
    Identifier strategy = positions->begin()->second;

    PlayerPtr currentPlayer = data->getPlayerInTurn(currentPositions);

    if (currentPlayer->isNull()) {
        data->setPlayerInTurn(currentPositions, (*players)[player]);
        currentPlayer = (*players)[player];
    } else if ((*currentPlayer->getName()) != player)
        throw ExceptionFactory::getInstance().invalidExtensiveCoordinateFormat(*positions);

    currentPositions.insert( Positions::value_type(depthName, strategy) );
    depthName = createIdentifier(++depthValue);

    return *this;
}

DataBuilder& ExtensiveDataBuilder::setPayoffs(
    const NumbersPtr params
) {
    data->setPayoffs(currentPositions, params);
    return *this;
}

DataBuilderPtr ExtensiveDataBuilder::clone() const {
    return DataBuilderPtr(new ExtensiveDataBuilder(*this));
}

Message ExtensiveDataBuilder::toString() const {
    static const IdentifierPtr name    = createIdentifierPtr("Current Data");
    const MessagePtr           message = createMessagePtr(data->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, message).build()->getResult();
}

// }; /* END class ExtensiveDataBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
