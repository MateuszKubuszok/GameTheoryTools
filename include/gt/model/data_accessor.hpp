#ifndef __GT_MODEL_DATA_ACCESSOR_HPP__
#define __GT_MODEL_DATA_ACCESSOR_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/data_accessor.hpp
 * @brief     Defines GT::Model::DataAccessor interface.
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
 * @class DataAccessor
 * @brief Custom interface for all Data accessing instances for Games.
 *
 * Is extended by Data interface.
 *
 * Used to restrict access to Data to ensure that ontent can only be read.
 *
 * @author Mateusz Kubuszok
 *
 * @see Data
 */
class DataAccessor : public virtual Root {
public:
    /**
     * @brief Returns map of Players available in this DataAccessor.
     *
     * @return Players
     */
    virtual const PlayersPtr getPlayers() const = 0;

    /**
     * @brief Returns values handler for given coordiantes.
     *
     * @param positions         coordinates in a Game
     * @return                  values of payoff
     * @throw InvalidCoordinate thrown when coordinates are invalid
     */
    virtual const DataPiecePtr getPayoffs(
        const PositionsPtr positions
    ) const = 0;

    /**
     * @brief Returns values handler for given coordiantes.
     *
     * @param positions         coordinates in a Game
     * @return                  values of payoff
     * @throw InvalidCoordinate thrown when coordinates are invalid
     */
    virtual const DataPiecePtr getPayoffs(
        const Positions& positions
    ) const = 0;

    /**
     * @brief Returns Data's message.
     *
     * @return Message
     */
    virtual Message toString() const override = 0;

    /**
     * @brief Overrides operator [] allowing easy access to values via DataPiece interface.
     *
     * @param positions          coordinates
     * @return                   DataPiece object allowing access to concrete value
     * @throw InvalidCoordinates thrown when positions coordinates are invalid
     */
    virtual const DataPiecePtr operator[](
        const Positions& positions
    ) const = 0;

    /**
     * @brief Overrides operator [] allowing easy access to values via DataPiece interface.
     *
     * @param positions          coordinates
     * @return                   DataPiece object allowing access to concrete value
     * @throw InvalidCoordinates thrown when positions coordinates are invalid
     */
    virtual const DataPiecePtr operator[](
        const PositionsPtr positions
    ) const = 0;
}; /* END class Data */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class NullDataAccessor
 * @brief Null DataAccessor for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullDataAccessor final : public DataAccessor {
public:
    virtual const PlayersPtr getPlayers() const override {
        return NullFactory::getInstance().createPlayers();
    }

    virtual const DataPiecePtr getPayoffs(
        const Positions&
    ) const override {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual const DataPiecePtr getPayoffs(
        const PositionsPtr
    ) const override {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullData");
    }

    virtual const DataPiecePtr operator[](
        const Positions&
    ) const override {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual const DataPiecePtr operator[](
        const PositionsPtr
    ) const override {
        return NullFactory::getInstance().createDataPiece();
    }
}; /* END class NullDataAccessor */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_DATA_ACCESSOR_HPP__ */
