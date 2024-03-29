/**
 * @file      gt/gtl/player.cpp
 * @brief     Defines GT::GTL::Player methods.
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

using std::stringstream;

using boost::make_shared;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class Player : public Object, public Model::Player {
// public:

Player::Player(
    const IdentifierPtr  playerName,
    const IdentifiersPtr playerStrategies
) :
    Object(createIdentifier("Player")),
    Model::Player(playerName, playerStrategies)
{
    registerProperty(createIdentifier("name"),       make_shared<PlayerNameProperty>(this));
    registerProperty(createIdentifier("strategies"), make_shared<PlayerStrategiesProperty>(this));
}

Message Player::serialize() const {
    stringstream result;
    result << "PLAYER " << *getName() << " {";

    bool firstElement = true;
    for (const IdentifierPtr& strategy : *getStrategies()) {
        if (!firstElement)
            result << ',';
        result << ' ' << *strategy;
        firstElement = false;
    }

    result << " }";
    return result.str();
}

Message Player::toString() const {
    return Model::Player::toString();
}

const Player& Player::toPlayer() const {
    return *this;
}

// }; /* END class Player */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
