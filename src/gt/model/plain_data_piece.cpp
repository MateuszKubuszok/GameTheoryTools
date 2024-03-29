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
using boost::make_shared;

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
    const size_t positionInStorage = positionsHelper.calculatePlayer(playerName);

    if (positionInStorage < numbers->size())
        return (*numbers)[positionInStorage];

    if (positionsHelper.getPlayers()->size() == 2 && numbers->size() == 1) {
        // In a matrix game we are allowed to deduce that: (player 2's payoff) = -1 * (player 1's payoff)
        Numbers&     payoffs       = const_cast<Numbers&>(*numbers);
        const Number player1Payoff = *(*numbers)[0];
        NumberPtr    player2Payoff = createNumberPtr(player1Payoff * -1.0);
        payoffs.push_back(player2Payoff);

        return payoffs[positionInStorage];
    }

    throw ExceptionFactory::getInstance()
              .noParamsForPositions(positionInStorage, positionsHelper.getUpperBound());
}

bool PlainDataPiece::is0Sum() const {
    if (positionsHelper.getPlayers()->size() == 2 && numbers->size() == 1)
        return true;

    double sum   = 0.0;
    for (NumberPtr& number : *numbers)
        sum += number->get_d();

    double delta = 10e-16;
    return (sum*sum) < delta;
}

Message PlainDataPiece::toString() const {
    static const IdentifierPtr  name    = createIdentifierPtr("Payoff");
    const IdentifiersPtr        players = createIdentifiersPtr();
    const MessagesPtr           values  = createMessagesPtr();

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
