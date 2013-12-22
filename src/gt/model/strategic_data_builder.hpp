#ifndef __GT_MODEL_STRATEGIC_DATA_BUILDER_HPP__
#define __GT_MODEL_STRATEGIC_DATA_BUILDER_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/strategic_data_builder.hpp
 * @brief     Defines GT::Model::StrategicDataBuilder class.
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

using boost::container::map;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class StrategicDataBuilder
 * @brief Builder used for creating StrategicGame's Data.
 *
 * Games in this form should have all coordinates filled with payoffs. Since all Players and their
 * strategies are known beforehand, positions can also be hashed to Indexes with
 * StrategicGamePositionsHelper.
 *
 * @author Mateusz Kubuszok
 *
 * @see StrategicData
 * @see StrategicGamePositionsHelper
 */
class StrategicDataBuilder final : public DataBuilder {
    /**
     * @brief Type containing information whether some player-strategy pair is already known.
     */
    typedef map<Identifier, bool> KnownPositions;

    /**
     * @brief Actual data.
     */
    StrategicDataPtr data;

    /**
     * @brief Players.
     */
    PlayersPtr players;

    /**
     * @brief Currently known Positions.
     */
    Positions      currentPositions;
    /**
     * @brief Information which Positions are already known.
     */
    KnownPositions currentlyKnownPositions;

public:
    /**
     * @brief Defalt constructor.
     */
    StrategicDataBuilder();

    /**
     * @brief Returns set up Data.
     *
     * @return built Data
     */
    StrategicDataPtr build() const;

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
     * @brief StrategicDataBuilder Message.
     *
     * @return Message
     */
    virtual Message toString() const override;
}; /* END class StrategicDataBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_STRATEGIC_DATA_BUILDER_HPP__ */
