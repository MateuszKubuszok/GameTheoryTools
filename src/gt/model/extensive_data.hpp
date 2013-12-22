#ifndef __GT_MODEL_EXTENSIVE_DATA_HPP__
#define __GT_MODEL_EXTENSIVE_DATA_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/extensive_data.hpp
 * @brief     Defines GT::Model::ExtensiveData class.
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
 * @class ExtensiveData
 * @brief Contins data specific for Game in a tree form.
 *
 * Games in this form has all payoffs defined in nodes of a game tree. Each level of that tree has assigned
 * Player and for this level. As such coordinates are mapping from turn into choosen strategy instead of
 * Player to strategy mapping.
 *
 * @author Mateusz Kubuszok
 *
 * @see DataAccessor
 * @see Data
 * @see DataPiece
 * @see ExtensiveDataAccessor
 * @see ExtensiveDataPiece
 * @see ExtensiveDataBuilder
 * @see ExtensiveDataNode
 */
class ExtensiveData : public Data {
    /**
     * @brief Players.
     */
    const PlayersPtr     players;
    /**
     * @brief Root of Data tree.
     */
    ExtensiveDataNodePtr root;

public:
    /**
     * @brief Initiates Data with Players' definitions.
     *
     * @param playersDefinitions Players' definitions
     */
    explicit ExtensiveData(
        const PlayersPtr playersDefinitions
    );

    /**
     * @brief Returns root of ExtensiveData tree.
     *
     * @return root
     */
    virtual const ExtensiveDataNodePtr getRoot() const;

    /**
     * @brief Returns Players' definitions.
     *
     * @return Players' definitions
     */
    virtual const PlayersPtr getPlayers() const override;

    /**
     * @brief Returns Player that plays for given position.
     *
     * @param positions Positions in payoff storage
     * @return          Player that plays given position
     */
    virtual const PlayerPtr getPlayerInTurn(
        const Positions& positions
    ) const;

    /**
     * @brief Returns Player that plays for given position.
     *
     * @param positions Positions in payoff storage
     * @return          Player that plays given position
     */
    virtual const PlayerPtr getPlayerInTurn(
        const PositionsPtr positions
    ) const;

    /**
     * @brief Sets Player that plays for given position.
     *
     * @param positions Positions for which player Player
     * @param player    Player that plays given position
     * @return          reference ot itdelf for chaining
     */
    virtual ExtensiveData& setPlayerInTurn(
        const Positions& positions,
        const PlayerPtr  player
    );

    /**
     * @brief Sets Player that plays for given position.
     *
     * @param positions Positions for which player Player
     * @param player    Player that plays given position
     * @return          reference ot itdelf for chaining
     */
    virtual ExtensiveData& setPlayerInTurn(
        const PositionsPtr positions,
        const PlayerPtr    player
    );

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
     * @param positions         Positions to set
     * @param numbers           payoffs values
     * @return                  reference to itself for chaining
     * @throw InvalidCoordinate thrown when Positions does not specify all depths continously ("1", "2", ...)
     *                          or some strategies do not match assigned for each turn Players
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
     * @throw InvalidCoordinate thrown when Positions does not specify all depths continously ("1", "2", ...)
     *                          or some strategies do not match assigned for each turn Players
     */
    virtual Data& setPayoffs(
        const PositionsPtr positions,
        const NumbersPtr   numbers
    ) override;

    /**
     * @brief Returns ExtensiveData Message.
     *
     * @return Message
     */
    virtual Message toString() const override;

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
}; /* END class ExtensiveData */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class NullExtensiveData
 * @brief Null ExtensiveData for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullExtensiveData final : public ExtensiveData {
public:
    NullExtensiveData() :
        ExtensiveData(NullFactory::getInstance().createPlayers())
        {}

    virtual const PlayersPtr getPlayers() const override {
        return NullFactory::getInstance().createPlayers();
    }

    virtual const PlayerPtr getPlayerInTurn(
        const Positions&
    ) const override {
        return NullFactory::getInstance().createPlayer();
    }

    virtual const PlayerPtr getPlayerInTurn(
        const PositionsPtr
    ) const override {
        return NullFactory::getInstance().createPlayer();
    }

    virtual ExtensiveData& setPlayerInTurn(
        const Positions&,
        const PlayerPtr
    ) override {
        return *this;
    }

    virtual ExtensiveData& setPlayerInTurn(
        const PositionsPtr,
        const PlayerPtr
    ) override {
        return *this;
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
        return Message("NullExtensiveData");
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
}; /* END class NullExtensiveData */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_EXTENSIVE_DATA_HPP__ */
