/**
 * @file      gt/model/plain_data_piece.cpp
 * @brief     Defines GT::Model::PlainDataPiece methods.
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

// class PlainDataPiece final : public DataPiece {
// public:

PlainDataPiece::PlainDataPiece(
    const PlayersPtr players,
    const NumbersPtr params
) :
    positionsHelper(players),
    numbers(params)
    {}

const NumberPtr& PlainDataPiece::getPayoff(
    const Identifier& playerName
) const {
    if (!positionsHelper.checkPlayer(playerName))
        throw ExceptionFactory::getInstance().invalidPlayer(playerName);
    return (*numbers)[positionsHelper.calculatePlayer(playerName)];
}

Message PlainDataPiece::toString() const {
    static const IdentifierPtr  name = createIdentifierPtr("Payoff");
    const IdentifiersPtr        players(new Identifiers());
    const MessagesPtr           values(new Messages());

    for (Identifier playerName : (*positionsHelper.getPlayers()) | map_keys) {
        players->push_back( createIdentifierPtr(playerName) );
        values->push_back( createMessagePtr((*numbers)[positionsHelper.calculatePlayer(playerName)]) );
    }

    ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();
    resultBuilder->setHeaders(players).addRecord( name, values );
    return resultBuilder->build()->getResult();
}

// }; /* END class PlainDataPiece */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
