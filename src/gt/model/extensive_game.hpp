#ifndef GT_MODEL_EXTENSIVE_GAME_HPP_INCLUDED
#define GT_MODEL_EXTENSIVE_GAME_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/extensive_game.hpp
 * @brief     Defines GT::Model::ExtensiveGame class.
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
 * @class ExtensiveGame
 * @brief Defnies ExtensiveGame.
 *
 * Games in this form has all payoffs defined in nodes of a game tree. Each node of that tree has assigned
 * Player. As such each SubCoordinates is mapped to strategy of the same Player.
 *
 * @author Mateusz Kubuszok
 *
 * @see ExtensiveData
 */
class ExtensiveGame final : public Game {
    /**
     * @brief Players.
     */
    const PlayersPtr       players;
    /**
     * @brief Game's data.
     */
    const ExtensiveDataPtr data;
    /**
     * @brief Positons helper used be printer.
     */
    const ExtensiveGamePositionsHelper positionsHelper;

public:
    /**
     * @brief Initiates Game with Players and Data.
     *
     * @param newPlayers Players' definitions
     * @param newData    Data for Game
     */
    ExtensiveGame(
        const PlayersPtr       newPlayers,
        const ExtensiveDataPtr newData
    );

    /**
     * @brief Returns Players' definitions.
     *
     * @return Players' denifitions
     */
    virtual const PlayersPtr getPlayers() const override;

    /**
     * @brief Returns Game's Data.
     *
     * @return Game's Data
     */
    virtual const DataAccessorPtr getData() const override;

    /**
     * @brief Returns ExtensiveGame's Message.
     *
     * @return Message
     */
    virtual Message toString() const override;
}; /* END class ExtensiveGame */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef GT_MODEL_EXTENSIVE_GAME_HPP_INCLUDED */
