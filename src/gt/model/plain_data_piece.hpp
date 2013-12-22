#ifndef __GT_MODEL_PLAIN_DATA_PIECE_HPP__
#define __GT_MODEL_PLAIN_DATA_PIECE_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/plain_data_piece.hpp
 * @brief     Defines GT::Model::PlainDataPiece class.
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
 * @class PlainDataPiece
 * @brief Used to store values at lowest level.
 *
 * Implements DataPiece interface.
 *
 * @author Mateusz Kubuszok
 *
 * @see DataPiece
 * @see Data
 * @see DataAccessor
 */
class PlainDataPiece final : public DataPiece {
    /**
     * @brief StrategicGamePositionsHelper used to properly locate Index in storage.
     */
    StrategicGamePositionsHelper positionsHelper;
    /**
     * @brief Values of payoff.
     */
    NumbersPtr numbers;

public:
    /**
     * @brief Constructor initiated with Players and params definitions.
     *
     * @param players Players definitions
     * @param params  params definitions
     */
    PlainDataPiece(
        const PlayersPtr players,
        const NumbersPtr params
    );

    /**
     * @brief Returns Player's payoff by its name.
     *
     * @param playerName        name of Player for which payoff is required
     * @return                  value of a payoff
     * @throw InvalidCoordinate thrown when player name is not known
     */
    virtual const NumberPtr& getPayoff(
        const Identifier& playerName
    ) const override;

    /**
     * @brief Returns PlainDataPiece's Message.
     *
     * @return Message
     */
    virtual Message toString() const override;
}; /* END class PlainDataPiece */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_PLAIN_DATA_PIECE_HPP__ */
