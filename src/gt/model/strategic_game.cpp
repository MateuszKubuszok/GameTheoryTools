/**
 * @file      gt/model/strategic_game.cpp
 * @brief     Defines GT::Model::StrategicGame methods.
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

using boost::make_shared;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class StrategicGame final : public Game {
// public:

StrategicGame::StrategicGame(
    const PlayersPtr       newPlayers,
    const StrategicDataPtr newData
) :
    players(newPlayers),
    data(newData)
    {}

const PlayersPtr StrategicGame::getPlayers() const {
    return players;
}

const DataAccessorPtr StrategicGame::getData() const {
    return make_shared<StrategicDataAccessor>(data);
}

Message StrategicGame::toString() const {
    static const IdentifierPtr name      = createIdentifierPtr("Strategic Game");
    const MessagePtr           subresult = createMessagePtr(data->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, subresult).build()->getResult();
}

// }; /* END class StrategicGame */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
