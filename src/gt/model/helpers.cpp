/**
 * @file      gt/model/helpers.cpp
 * @brief     Defines GT::Model helpers.
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using std::fixed;
using std::setprecision;
using std::stringstream;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

Message createMessage(
    Index message
) {
    stringstream result;
    result << message;
    return Message(result.str());
}

Message createMessage(
    double message
) {
    stringstream result;
    result << setprecision(5) << fixed << message;
    return Message(result.str());
}

Message createMessage(
    Number number
) {
    stringstream result;
    result << setprecision(5) << fixed << number;
    return result.str();
}

Message createMessage(
    NumberPtr number
) {

    stringstream result;
    result << setprecision(5) << fixed << (*number);
    return result.str();
}

MessagePtr createMessagePtr(
    Index message
) {
    stringstream result;
    result << message;
    return MessagePtr(new Message(result.str()));
}

MessagePtr createMessagePtr(
    double message
) {
    stringstream result;
    result << setprecision(5) << fixed << message;
    return MessagePtr(new Message(result.str()));
}

MessagePtr createMessagePtr(
    Number number
) {
    stringstream result;
    result << setprecision(5) << fixed << number;
    return MessagePtr(new Message(result.str()));
}

MessagePtr createMessagePtr(
    NumberPtr number
) {
    stringstream result;
    result << setprecision(5) << fixed << (*number);
    return MessagePtr(new Message(result.str()));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

Identifier createIdentifier(
    Index identifier
) {
    stringstream result;
    result << identifier;
    return Identifier(result.str());
}

IdentifierPtr createIdentifierPtr(
    Index identifier
) {
    stringstream result;
    result << identifier;
    return IdentifierPtr(new Identifier(result.str()));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void checkPlayers(
    const PlayersPtr& players
) {
    for (Players::const_iterator player = players->begin(); player != players->end(); ++player) {
        if (player->first.size() == 0)
            throw ExceptionFactory::getInstance().emptyPlayerName();

        Players::const_iterator anotherPlayer = player;
        for (++anotherPlayer; anotherPlayer != players->end(); ++anotherPlayer) {
            if (player->first == anotherPlayer->first)
                throw ExceptionFactory::getInstance().duplicatedPlayerName(player->first);
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GT */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GT */
