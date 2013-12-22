#ifndef __GT_MODEL_DATA_BUILDER_HPP__
#define __GT_MODEL_DATA_BUILDER_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/data_builder.hpp
 * @brief     Defines GT::Model::DataBuilder interface.
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
 * @class DataBuilder
 * @brief Helper used to create data for Games.
 *
 * Intended to be used recursively with #clone() method:
 *
 * @code{.cpp}
 * DataBuilderPtr builder1 = dataBuilder->clone();
 *     builder1->addNextPositions(position11);
 *     builder->clone()->addNextPositions(positions21).setPayoffs(param11_21); // payoff(p1=s1, p2=s1)
 *     builder->clone()->addNextPositions(positions22).setPayoffs(param11_22); // payoff(p1=s1, p2=s2)
 * DataBuilderPtr builder2 = dataBuilder->clone();
 *     builder2->addNextPositions(position12);
 *     builder->clone()->addNextPositions(positions21).setPayoffs(param12_21); // payoff(p1=s2, p2=s1)
 *     builder->clone()->addNextPositions(positions22).setPayoffs(param12_22); // payoff(p1=s2, p2=s2)
 * @endcode
 *
 * @author Mateusz Kubuszok
 *
 * @see Data
 * @see GameBuilder
 */
class DataBuilder : public virtual Root {
public:
    /**
     * @brief Sets Players defined for Game.
     *
     * @param players           Players
     * @return                  reference to itself
     * @throw IllegalInnerState thrown when Players are already set
     */
    virtual DataBuilder& setPlayers(
        const PlayersPtr players
    ) = 0;

    /**
     * @brief Adds next positions to Data.
     *
     * @param positions         Positions
     * @return                  reference to itself
     * @throw IllegalInnerState thrown when some of Positions are already set
     * @throw InvalidCoordinate thrown when some of values are not valid strategies names
     */
    virtual DataBuilder& addNextPositions(
        const PositionsPtr positions
    ) = 0;

    /**
     * @brief Sets Params with values.
     *
     * @param params            Params
     * @return                  reference to itself
     * @throw IllegalInnerState thrown when attempting to set Params when not all coordinates are known
     */
    virtual DataBuilder& setPayoffs(
        const NumbersPtr params
    ) = 0;

    /**
     * @brief Clones DataBuilder for recursive building.
     *
     * @return DataBuilder clone
     */
    virtual DataBuilderPtr clone() const = 0;

    /**
     * @brief DataBuilder's Message.
     *
     * @return Message
     */
    virtual Message toString() const override = 0;
}; /* END class DataBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class NullDataBuilder
 * @brief Null DataBuilder for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullDataBuilder final : public DataBuilder {
public:
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

    virtual DataBuilder& setPayoffs(
        const NumbersPtr
    ) override {
        return *this;
    }

    virtual DataBuilderPtr clone() const override {
        return NullFactory::getInstance().createDataBuilder();
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullDataBuilder");
    }
}; /* END class NullDataBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_DATA_BUILDER_HPP__ */
