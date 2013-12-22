#ifndef __GT_MODEL_GAME_HPP__
#define __GT_MODEL_GAME_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/game.hpp
 * @brief     Defines GT::Model::Game interface.
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
 * @class Game
 * @brief Defines Game.
 *
 * @author Mateusz Kubuszok
 */
class Game : public virtual Root {
public:
    /**
     * @brief Returns Game's Players.
     *
     * @return Players
     */
    virtual const PlayersPtr getPlayers() const = 0;

    /**
     * @brief Grants access to Data specific to a Game.
     *
     * @return DataAccessor returns DataAccessor specific for a Game
     */
    virtual const DataAccessorPtr getData() const = 0;

    /**
     * @brief Defines equality relation.
     *
     * @param root another root to compare
     * @return     true if roots are equal
     */
    virtual bool isEqual(
        const Root& root
    ) const override;

    /**
     * @brief Game's Message.
     *
     * @return Message
     */
    virtual Message toString() const = 0;

    /**
     * @brief Syntax sugar for #isEqual(const Root&) method.
     *
     * @param game1 first Game to compare
     * @param game2 second Game to compare
     * @return      true if Games are equal
     */
    friend bool operator==(
        const GamePtr& game1,
        const GamePtr& game2
    );

    /**
     * @brief Syntax sugar for !#isEqual(const Root&) method.
     *
     * @param game1 first Game to compare
     * @param game2 second Game to compare
     * @return      true if Games are not equal
     */
    friend bool operator!=(
        const GamePtr& game1,
        const GamePtr& game2
    );

    /**
     * @brief Syntax sugar for #toString() method.
     *
     * @param stream stream to concatenate
     * @param game   Game to concatenate
     * @return       stream for chaining
     */
    friend OutputStream& operator<<(
        OutputStream&  stream,
        const GamePtr& game
    );
}; /* END class Game */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class NullGame
 * @brief Null Game for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullGame final : public Game {
public:
    virtual const PlayersPtr getPlayers() const override {
        return NullFactory::getInstance().createPlayers();
    }

    virtual const DataAccessorPtr getData() const override {
        return NullFactory::getInstance().createDataAccessor();
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullGame");
    }
}; /* END class NullGame */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_GAME_HPP__ */
