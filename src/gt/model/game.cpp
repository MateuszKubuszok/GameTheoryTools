/**
 * @file      gt/model/game.cpp
 * @brief     Defines GT::Model::Game methods.
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

// class Game : public virtual Root {
// public:

bool Game::isEqual(
    const Root& root
) const {
    const Game* game = dynamic_cast<const Game*>(&root);
    if (!game)
        return false;
    if (game == this)
        return true;
    if (*game->getPlayers() != *getPlayers())
        return false;
    if (*game->getData() != *getData())
        return false;
    return true;
}

// }; /* END class Game */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool operator==(
    const GamePtr& game1,
    const GamePtr& game2
) {
    return (*game1) == (*game2);
}

bool operator!=(
    const GamePtr& game1,
    const GamePtr& game2
) {
    return (*game1) != (*game2);
}

OutputStream& operator<<(
    OutputStream&  stream,
    const GamePtr& game
) {
    return stream << game->toString();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
