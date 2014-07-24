/**
 * @file      gt/model/extensive_data.cpp
 * @brief     Defines GT::Model::ExtensiveData methods.
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

// class ExtensiveData final : public Data {
// public:

ExtensiveData::ExtensiveData(
    const PlayersPtr playersDefinitions
) :
    players(playersDefinitions),
    root(make_shared<ExtensiveDataNode>())
    {}

const ExtensiveDataNodePtr ExtensiveData::getRoot() const {
    return root;
}

const PlayersPtr ExtensiveData::getPlayers() const {
    return players;
}

const PlayerPtr ExtensiveData::getPlayerInTurn(
    const Positions& positions
) const {
    return root->getPlayer(positions);
}

const PlayerPtr ExtensiveData::getPlayerInTurn(
    const PositionsPtr positions
) const {
    return getPlayerInTurn(*positions);
}

ExtensiveData& ExtensiveData::setPlayerInTurn(
    const Positions& positions,
    const PlayerPtr  player
) {
    root->setPlayer(positions, player);
    return *this;
}

ExtensiveData& ExtensiveData::setPlayerInTurn(
    const PositionsPtr positions,
    const PlayerPtr    player
) {
    return setPlayerInTurn(*positions, player);
}

const DataPiecePtr ExtensiveData::getPayoffs(
    const Positions& positions
) const {
    Positions checkedPositions;

    for (const Positions::value_type& position : positions) {
        const PlayerPtr   playedPlayer = getPlayerInTurn(checkedPositions);
        const Identifier& strategy     = position.second;

        if (!playedPlayer) {
            Identifier nullPlayer("no player definition");
            throw ExceptionFactory::getInstance().invalidPlayer(nullPlayer);
        }

        if (!playedPlayer->hasStrategy(strategy))
            throw ExceptionFactory::getInstance().invalidCoordinateFormat(positions);

        checkedPositions.insert( position );
    }

    NumbersPtr payoff = root->getPayoffs(positions);
    return make_shared<PlainDataPiece>(players, payoff);
}

const DataPiecePtr ExtensiveData::getPayoffs(
    const PositionsPtr positions
) const {
    return getPayoffs(*positions);
}

Data& ExtensiveData::setPayoffs(
    const Positions& positions,
    const NumbersPtr numbers
) {
    Positions checkedPositions;

    for (const Positions::value_type& position : positions) {
        const PlayerPtr   playedPlayer = getPlayerInTurn(checkedPositions);
        const Identifier& strategy     = position.second;

        if (!playedPlayer) {
            Identifier nullPlayer("no player definition");
            throw ExceptionFactory::getInstance().invalidPlayer(nullPlayer);
        }

        if (!playedPlayer->hasStrategy(strategy))
            throw ExceptionFactory::getInstance().invalidCoordinateFormat(positions);

        checkedPositions.insert( position );
    }

    root->setPayoffs(positions, numbers);

    return *this;
}

Data& ExtensiveData::setPayoffs(
    const PositionsPtr positions,
    const NumbersPtr   numbers
) {
    return setPayoffs(*positions, numbers);
}

Message ExtensiveData::toString() const {
    static const IdentifierPtr name   = createIdentifierPtr("ExtensiveData");
    const MessagePtr           result = createMessagePtr(root->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, result).build()->getResult();
}

const DataPiecePtr ExtensiveData::operator[](
    const Positions& positions
) const {
    return getPayoffs(positions);
}

const DataPiecePtr ExtensiveData::operator[](
    const PositionsPtr positions
) const {
    return getPayoffs(positions);
}

// }; /* END class ExtensiveData */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
