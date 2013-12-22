#ifndef __GT_MODEL_STRATEGIC_DATA_HPP__
#define __GT_MODEL_STRATEGIC_DATA_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/strategic_data.hpp
 * @brief     Defines GT::Model::StrategicData class.
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

using boost::container::vector;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class StrategicData
 * @brief Contains data specific for Game in a strategic form.
 *
 * Games in this form should have all coordinates filled with payoffs. Since all Players and their
 * strategies are known beforehand, positions can also be hashed to Indexes with
 * StrategicGamePositionsHelper.
 *
 * @author Mateusz Kubuszok
 *
 * @see DataAccessor
 * @see Data
 * @see DataPiece
 * @see StrategicDataAccessor
 * @see StrategicDataPiece
 * @see StrategicDataBuilder
 * @see StrategicGamePositionsHelper
 */
class StrategicData : public Data {
    /**
     * @brief StrategicGamePositionsHelper used to calculate positions in storage vector.
     */
    StrategicGamePositionsHelper positionsHelper;

    /**
     * @brief Contains Payoff - indexes can be calculated with PostionsHelper.
     */
    vector<NumbersPtr> payoffStorage;
    /**
     * @brief Contains information whether or not some storage poition is already used.
     */
    vector<bool>       payoffStorageAllocation;

public:
    /**
     * @brief Initiates Data with Players' definitions.
     *
     * @param playersDefinitions Players' definitions
     */
    explicit StrategicData(
        const PlayersPtr playersDefinitions
    );

    /**
     * @brief Returns Players' definitions.
     *
     * @return Players' definitions
     */
    virtual const PlayersPtr getPlayers() const override;

    /**
     * @brief Returns DataPiece that gives access to payoffs.
     *
     * @param positionInStorage Index of positon in payoff storage
     *                          according to StrategicGamePositionsHelper
     * @return                  DataPiece handling access to payoffs
     * @throw InvalidCoordinate thrown when no data is set under such position
     */
    virtual const DataPiecePtr getPayoffs(
        const Index positionInStorage
    ) const;

    /**
     * @brief Returns DataPiece that gives access to payoffs.
     *
     * @param positions         Positions in payoff storage
     * @return                  DataPiece handling access to payoffs
     * @throw InvalidCoordinate thrown when no data is set under such position
     */
    virtual const DataPiecePtr getPayoffs(
        const PositionsPtr positions
    ) const override;

    /**
     * @brief Returns DataPiece that gives access to payoffs.
     *
     * @param positions         Positions in payoff storage
     * @return                  DataPiece handling access to payoffs
     * @throw InvalidCoordinate thrown when no data is set under such position
     */
    virtual const DataPiecePtr getPayoffs(
        const Positions& positions
    ) const override;

    /**
     * @brief Sets Positions to contains given payoffs.
     *
     * @param positionInStorage Index of position in payoff storage
     * @param numbers           payoffs values
     * @return                  reference to itself for chaining
     * @throw InvalidCoordinate thrown when Index in not in allowed range
     */
    virtual Data& setPayoffs(
        const Index      positionInStorage,
        const NumbersPtr numbers
    );

    /**
     * @brief Sets Positions to contains given payoffs.
     *
     * @param positions         Positions to set
     * @param numbers           payoffs values
     * @return                  reference to itself for chaining
     */
    virtual Data& setPayoffs(
        const Positions& positions,
        const NumbersPtr numbers
    ) override;

    /**
     * @brief Sets Positions to contains given payoffs.
     *
     * @param positions         Positions to set
     * @param numbers           payoffs values
     * @return                  reference to itself for chaining
     */
    virtual Data& setPayoffs(
        const PositionsPtr positions,
        const NumbersPtr   numbers
    ) override;

    /**
     * @brief Returns DataPiece that gives access to payoffs.
     *
     * @param positionInStorage Index of positon in payoff storage
     *                          according to StrategicGamePositionsHelper
     * @return                  DataPiece handling access to payoffs
     * @throw InvalidCoordinate thrown when no data is set under such position
     */
    virtual const DataPiecePtr operator[](
        const Index positionInStorage
    ) const;

    /**
     * @brief Returns DataPiece that gives access to payoffs.
     *
     * @param positions         Positions in payoff storage
     * @return                  DataPiece handling access to payoffs
     * @throw InvalidCoordinate thrown when no data is set under such position
     */
    virtual const DataPiecePtr operator[](
        const Positions& positions
    ) const override;

    /**
     * @brief Returns DataPiece that gives access to payoffs.
     *
     * @param positions         Positions in payoff storage
     * @return                  DataPiece handling access to payoffs
     * @throw InvalidCoordinate thrown when no data is set under such position
     */
    virtual const DataPiecePtr operator[](
        const PositionsPtr positions
    ) const override;

    /**
     * @brief Returns StrategicData Message.
     *
     * @return Message
     */
    virtual Message toString() const override;
}; /* END class StrategicData */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class NullStrategicData
 * @brief Null StrategicData for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullStrategicData final : public StrategicData {
public:
    NullStrategicData() :
        StrategicData(NullFactory::getInstance().createPlayers())
        {}

    virtual const PlayersPtr getPlayers() const override {
        return NullFactory::getInstance().createPlayers();
    }

    virtual const DataPiecePtr getPayoffs(
        const Index
    ) const override {
        return NullFactory::getInstance().createDataPiece();
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

    virtual Data& setPayoffs(
        const Index,
        const NumbersPtr
    ) override {
        return *this;
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
        return Message("NullStrategicData");
    }

    virtual const DataPiecePtr operator[](
        const Index
    ) const override {
        return NullFactory::getInstance().createDataPiece();
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
}; /* END class NullStrategicData */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_STRATEGIC_DATA_HPP__ */
