#ifndef __GT_MODEL_DATA_HPP__
#define __GT_MODEL_DATA_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/data.hpp
 * @brief     Defines GT::Model::Data interface.
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
 * @class Data
 * @brief Custom interface for all Data containers for Games.
 *
 * Extends DataAccessor interface.
 *
 * Used to store all information necessary to calculate Nash equlibria for each type of Games.
 *
 * @author Mateusz Kubuszok
 *
 * @see DataAccessor
 * @see DataBuilder
 */
class Data : public DataAccessor {
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
     * @brief Sets values for given coordiantes.
     *
     * @param positions         coordinates in a Game
     * @param numbers           payoff to set
     * @return                  reference to itself
     * @throw InvalidCoordinate thrown when calculated coordinates are invalid
     */
    virtual Data& setPayoffs(
        const Positions& positions,
        const NumbersPtr numbers
    ) = 0;

    /**
     * @brief Sets values for given coordiantes.
     *
     * @param positions         coordinates in a Game
     * @param numbers           payoff to set
     * @return                  reference to itself
     * @throw InvalidCoordinate thrown when calculated coordinates are invalid
     */
    virtual Data& setPayoffs(
        const PositionsPtr positions,
        const NumbersPtr   numbers
    ) = 0;

    /**
     * @brief Returns Data's message.
     *
     * @return message
     */
    virtual Message toString() const override = 0;

    /**
     * @brief Overrides #operator[] allowing easy access to values via DataPiece interface.
     *
     * @param positions          coordinates
     * @return                   DataPiece object allowing access to concrete value
     * @throw InvalidCoordinates thrown when positions coordinates are invalid
     */
    virtual const DataPiecePtr operator[](
        const Positions& positions
    ) const = 0;

    /**
     * @brief Overrides #operator[] allowing easy access to values via DataPiece interface.
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
 * @class NullData
 * @brief Null Data for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullData final : public Data {
public:
    virtual const PlayersPtr getPlayers() const override {
        return NullFactory::getInstance().createPlayers();
    }

    virtual const DataPiecePtr getPayoffs(
        const Positions&
    )  const override {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual const DataPiecePtr getPayoffs(
        const PositionsPtr
    ) const override {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual Data& setPayoffs(
        const Positions&,
        const NumbersPtr
    ) override {
        return *this;
    }

    virtual Data& setPayoffs(
        const PositionsPtr,
        const NumbersPtr
    ) override {
        return *this;
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
}; /* END class NullData */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_DATA_HPP__ */
