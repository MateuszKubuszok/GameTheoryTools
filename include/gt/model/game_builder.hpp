#ifndef __GT_MODEL_GAME_BUILDER_HPP__
#define __GT_MODEL_GAME_BUILDER_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/game_builder.hpp
 * @brief     Defines GT::Model::GameBuilder interface.
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
 * @class GameBuilder
 * @brief Helper used to create Games.
 *
 * Has the same interface as DataBuilder to make easy decoration possible.
 *
 * Intended to be used recursively with clone method:
 *
 * @code
 * DataBuilderPtr builder1 = gameBuilder->clone();
 *     builder1->addNextPositions(position11);
 *     builder->clone()->addNextPositions(positions21).setParams(param11_21); // payoff(p1=s1, p2=s1)
 *     builder->clone()->addNextPositions(positions22).setParams(param11_22); // payoff(p1=s1, p2=s2)
 * DataBuilderPtr builder2 = gameBuilder->clone();
 *     builder2->addNextPositions(position12);
 *     builder->clone()->addNextPositions(positions21).setParams(param12_21); // payoff(p1=s2, p2=s1)
 *     builder->clone()->addNextPositions(positions22).setParams(param12_22); // payoff(p1=s2, p2=s2)
 * @endcode
 *
 * @author Mateusz Kubuszok
 *
 * @see Game
 * @see DataBuilder
 */
class GameBuilder : public DataBuilder {
public:
    /**
     * @brief Builds Game.
     *
     * @return Game
     */
    virtual GamePtr build() const = 0;

    /**
     * @brief Returns new copy of this GameBuilder's type.
     *
     * @return GameBuilder
     */
    virtual GameBuilderPtr cloneBuilder() const = 0;

    /**
     * @brief Returns Players' definitions.
     *
     * @return Players' definitions
     */
    virtual const PlayersPtr getPlayers() const = 0;

    /**
     * @brief Returns inner DataBuilder.
     *
     * @return DataBuilder
     */
    virtual DataBuilderPtr dataBuilder() const = 0;
}; /* END class GameBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class NulGameBuilder
 * @brief Null GameBuilder for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullGameBuilder final : public GameBuilder {
public:
    virtual const PlayersPtr getPlayers() const override {
        return NullFactory::getInstance().createPlayers();
    }

    virtual DataBuilder& setPlayers(
        const PlayersPtr
    ) override {
        return *this;
    }

    virtual DataBuilder& addNextPositions(
        const PositionsPtr
    ) override {
        return *this;
    }

    virtual DataBuilder& setParams(
        const NumbersPtr
    ) override {
        return *this;
    }

    virtual DataBuilderPtr dataBuilder() const override {
        return NullFactory::getInstance().createDataBuilder();
    }

    virtual GamePtr build() const override {
        return NullFactory::getInstance().createGame();
    }

    virtual DataBuilderPtr clone() const override {
        return NullFactory::getInstance().createDataBuilder();
    }

    virtual GameBuilderPtr cloneBuilder() const override {
        return NullFactory::getInstance().createGameBuilder();
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullGameBuilder");
    }
}; /* END class NullDataBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_GAME_BUILDER_HPP__ */
