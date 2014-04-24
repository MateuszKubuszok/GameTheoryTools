#ifndef GT_MODEL_EXTENSIVE_DATA_BUILDER_HPP_INCLUDED
#define GT_MODEL_EXTENSIVE_DATA_BUILDER_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/extensive_data_builder.hpp
 * @brief     Defines GT::Model::ExtensiveDataBuilder class.
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
 * @class ExtensiveDataBuilder
 * @brief Builder used for creating ExtensiveGame's Data.
 *
 * Games in this form has all payoffs defined in nodes of a game tree. Each node of that tree has assigned
 * Player. As such each SubCoordinates is mapped to strategy of the same Player.
 *
 * @author Mateusz Kubuszok
 *
 * @see ExtensiveData
 * @see ExtensiveGame
 */
class ExtensiveDataBuilder final : public DataBuilder {
    /**
     * @brief Actual data.
     */
    ExtensiveDataPtr data;

    /**
     * @brief Players.
     */
    PlayersPtr players;
    /**
     * @brief Current Positions that will be used to set params with setPayoffs(NumbersPtr).
     */
    Positions  currentPositions;

    /**
     * @brief Current depth as numeric value.
     */
    Index      depthValue;
     /**
     * @brief Current depth as Identifier.
     */
    Identifier depthName;

public:
    /**
     * @brief Defalt constructor.
     */
    ExtensiveDataBuilder();

    /**
     * @brief Returns set up Data.
     *
     * @return built Data
     */
    ExtensiveDataPtr build() const;

    /**
     * @brief Returns Players' definitions.
     *
     * @return Players' definitions
     */
    const PlayersPtr getPlayers() const;

    /**
     * @brief Sets Players' definitions.
     *
     * @param newPlayers Players' definitions
     * @return           reference to itself for chanining
     */
    virtual DataBuilder& setPlayers(
        const PlayersPtr newPlayers
    ) override;

    /**
     * @brief Specifies next Positions.
     *
     * @param positions next Positions to specify
     * @return          reference to itself for chanining
     */
    virtual DataBuilder& addNextPositions(
        const PositionsPtr positions
    ) override;

    /**
     * @brief Sets payoffs values.
     *
     * @param params values of payoffs
     * @return       reference to itself for chanining
     */
    virtual DataBuilder& setPayoffs(
        const NumbersPtr params
    ) override;

    /**
     * @brief Returns copy of itsef with shared content and frozen values of already set Positions.
     *
     * @return copy with frozem Positions and content common to parent
     */
    virtual DataBuilderPtr clone() const override;

    /**
     * @brief ExtensiveDataBuilder Message.
     *
     * @return Message
     */
    virtual Message toString() const override;
}; /* END class ExtensiveDataBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef GT_MODEL_EXTENSIVE_DATA_BUILDER_HPP_INCLUDED */
