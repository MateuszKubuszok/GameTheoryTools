#ifndef GT_MODEL_HELPERS_HPP_INCLUDED
#define GT_MODEL_HELPERS_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/helpers.hpp
 * @brief     Declares GT::Model helpers.
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

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Creates Players.
 *
 * @return Players
 */
Players createPlayers();

/**
 * @brief Creates Players.
 *
 * @return Players
 */
PlayersPtr createPlayersPtr();

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Checks if Players are fulfilling criteria of nonemtyness and uniqueness.
 *
 * @param players               Players
 * @throw EmptyPlayerName       thrown when player have an empty name
 * @throw PlayersNameDuplicated thrown when some Player's name is duplicated
 */
void checkPlayers(
    const PlayersPtr& players
);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "gt/model/helpers.ipp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif /* END #ifndef GT_MODEL_HELPERS_HPP_INCLUDED */
