#ifndef __GT_MODEL_STRATEGIC_GAME_HPP__
#define __GT_MODEL_STRATEGIC_GAME_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/strategic_game.hpp
 * @brief     Defines GT::Model::StrategicGame class.
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
 * @class StrategicGame
 * @brief Defnies StrategicGame.
 *
 * <p>Games in this form should have all coordinates filled with payoffs. Since all Players and their
 * strategies are known beforehand, positions can also be hashed to Indexes with
 * StrategicGamePositionsHelper.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see StrategicData
 * @see StrategicGamePositionsHelper
 */
class StrategicGame final : public Game {
    /**
     * @brief Players.
     */
    const PlayersPtr       players;
    /**
     * @brief Game's Data.
     */
    const StrategicDataPtr data;

public:
    /**
     * @brief Initiates Game with Players and Data.
     *
     * @param newPlayers Players' definitions
     * @param newData    Data for Game
     */
    StrategicGame(
        const PlayersPtr       newPlayers,
        const StrategicDataPtr newData
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
     * @brief Returns StrategicGame's Message.
     *
     * @return Message
     */
    virtual Message toString() const override;
}; /* END class StrategicGame */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_STRATEGIC_GAME_HPP__ */
