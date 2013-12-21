/**
 * @file      gt/model/extensive_game.cpp
 * @brief     Defines GT::Model::ExtensiveGame methods.
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

// class ExtensiveGame final : public Game {
// public:

ExtensiveGame::ExtensiveGame(
    const PlayersPtr       newPlayers,
    const ExtensiveDataPtr newData
) :
    players(newPlayers),
    data(newData)
    {}

const PlayersPtr ExtensiveGame::getPlayers() const {
    return players;
}

const DataAccessorPtr ExtensiveGame::getData() const {
    return DataAccessorPtr(new ExtensiveDataAccessor(data));
}

Message ExtensiveGame::toString() const {
    static const IdentifierPtr name      = createIdentifierPtr("Extensive Game");
    const MessagePtr           subresult = createMessagePtr(data->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, subresult).build()->getResult();
}

// }; /* END class ExtensiveGame */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
