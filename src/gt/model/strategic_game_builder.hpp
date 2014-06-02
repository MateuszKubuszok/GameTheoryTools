#ifndef GT_MODEL_STRATEGIC_GAME_BUILDER_HPP_INCLUDED
#define GT_MODEL_STRATEGIC_GAME_BUILDER_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/strategic_game_builder.hpp
 * @brief     Defines GT::Model::StrategicGameBuilder class.
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
 * @class StrategicGameBuilder
 * @brief Builder used for creating StrategicGame.
 *
 * Games in this form should have all coordinates filled with payoffs. Since all Players and their
 * strategies are known beforehand, positions can also be hashed to Indexes with PositionsHelper.
 *
 * @author Mateusz Kubuszok
 *
 * @see StrategicGame
 * @see StrategicDataBuilder
 */
class StrategicGameBuilder final : public GameBuilder {
    /**
     * @brief Game's DataBuilder.
     */
    StrategicDataBuilderPtr strategicDataBuilder;

public:
    /**
     * @brief Default constructor.
     */
    StrategicGameBuilder();

    /**
     * @brief Returns set up Game.
     *
     * @return built Game
     */
    virtual GamePtr build() const override;

    /**
     * @brief Returns Players' definitions.
     *
     * @return Players' definitions
     */
    virtual const PlayersPtr getPlayers() const override;

    /**
     * @brief Sets Players' definitions.
     *
     * @param newPlayers        Players' definitions
     * @return                  reference to itself for chanining
     * @throw InvalidCoordinate thrown id some Player's name is empty or dupicated
     */
    virtual DataBuilder& setPlayers(
        PlayersPtr newPlayers
    ) override;

    /**
     * @brief Specifies next Positions.
     *
     * @param positions next Positions to specify
     * @return          reference to itself for chanining
     */
    virtual DataBuilder& addNextPositions(
        PositionsPtr positions
    ) override;

    /**
     * @brief Sets payoffs values.
     *
     * @param params values of payoffs
     * @return       reference to itself for chanining
     */
    virtual DataBuilder& setPayoffs(
        NumbersPtr params
    ) override;

    /**
     * @brief Returns copy of itsef with shared content and frozen values of already set Positions.
     *
     * @return copy with frozem Positions and content common to parent
     */
    virtual DataBuilderPtr clone() const override;

    /**
     * @brief Returns new copy of this GameBuilder's type.
     *
     * @return GameBuilder
     */
    virtual GameBuilderPtr cloneBuilder() const override;

    /**
     * @brief Returns Same's DataBuilder.
     *
     * @return DataBuilder
     */
    virtual DataBuilderPtr dataBuilder() const override;

    /**
     * @brief StrategicGameBuilder Message.
     *
     * @return Message
     */
    virtual Message toString() const override;
}; /* END class StrategicGameBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef GT_MODEL_STRATEGIC_GAME_BUILDER_HPP_INCLUDED */
