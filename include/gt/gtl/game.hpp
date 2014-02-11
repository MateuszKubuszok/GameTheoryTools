#ifndef __GT_GTL_GAME_HPP__
#define __GT_GTL_GAME_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/game.hpp
 * @brief     Defines GT::GTL::Game class.
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
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class Game
 * @brief Defines Game.
 *
 * Game Object can be later used to Query it or to store it into Context for later use.
 *
 * @author Mateusz Kubuszok
 *
 * @see GameDriver
 * @see Parser
 */
class Game : public Object {
    /**
     * @brief Model Game implementation.
     */
    const Model::GamePtr game;

    /**
     * @brief Game type
     */
    const IdentifierPtr gameType;

public:
    /**
     * @brief Initiates Object with Game model.
     *
     * @param game Model Game implementation
     */
    explicit Game(
        const Model::GamePtr game
    );

    /**
     * @brief Initiates Object with Game model.
     *
     * @param game     Model Game implementation
     * @param gameType type of Game: "STRATEGIC" or "EXTENSIVE"
     */
    Game(
        const Model::GamePtr game,
        const IdentifierPtr  gameType
    );

    /**
     * @brief Search pure Nash equilibrium for given conditions.
     *
     * @param context    context with definitions
     * @param conditions conditions for query
     */
    virtual ResultPtr pureEquilibrium(
        const Context&    context,
        const Conditions& conditions
    ) const;

    /**
     * @brief Search mixed Nash equilibrium for given conditions.
     *
     * @param context    context with definitions
     * @param conditions conditions for query
     */
    virtual ResultPtr mixedEquilibrium(
        const Context&    context,
        const Conditions& conditions
    ) const;

    /**
     * @brief Search behavior Nash equilibrium for given conditions.
     *
     * @param context    context with definitions
     * @param conditions conditions for query
     */
    virtual ResultPtr behaviorEquilibrium(
        const Context&    context,
        const Conditions& conditions
    ) const;

    /**
     * @brief Returns game type name.
     *
     * Game type used during game definition: EXTENSIVE, STRATEGIC.
     *
     * @return game type Identifier
     */
    virtual const IdentifierPtr getGameType() const;

    /**
     * @brief Returns serialized Message for a Game.
     *
     * @return serialization result
     */
    virtual Message serialize() const override;

    /**
     * @brief Returns Message about Game.
     *
     * @return Game's state
     */
    virtual Message toString() const override;

    /**
     * @brief Explicit cast to Game type.
     *
     * @return Game
     */
    virtual const Game& toGame() const override;
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
    NullGame() :
        Game(Model::NullFactory::getInstance().createGame())
        {}

    virtual ResultPtr pureEquilibrium(
        const Context&,
        const Conditions&
    ) const override {
        return Model::NullFactory::getInstance().createResult();
    }

    virtual ResultPtr mixedEquilibrium(
        const Context&,
        const Conditions&
    ) const override {
        return Model::NullFactory::getInstance().createResult();
    }

    virtual ResultPtr behaviorEquilibrium(
        const Context&,
        const Conditions&
    ) const override {
        return Model::NullFactory::getInstance().createResult();
    }

    virtual const IdentifierPtr getGameType() const override {
        return createIdentifierPtr("NULL");
    }

    virtual Message serialize() const override {
        return createMessage("NULL GAME");
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullGame");
    }
}; /* END class NullGame */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class ErrorGame
 * @brief Error Condition for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class ErrorGame final : public Game {
    /**
     * @brief Error message.
     */
    const Message message;

public:
    ErrorGame(
        const Message errorMessage
    ) :
        Game(Model::NullFactory::getInstance().createGame()),
        message(errorMessage)
        {}

    virtual ResultPtr pureEquilibrium(
        const Context&,
        const Conditions&
    ) const override {
        return Model::NullFactory::getInstance().createResult();
    }

    virtual ResultPtr mixedEquilibrium(
        const Context&,
        const Conditions&
    ) const override {
        return Model::NullFactory::getInstance().createResult();
    }

    virtual ResultPtr behaviorEquilibrium(
        const Context&,
        const Conditions&
    ) const override {
        return Model::NullFactory::getInstance().createResult();
    }

    virtual const IdentifierPtr getGameType() const override {
        return createIdentifierPtr("ERROR");
    }

    virtual Message serialize() const override {
        return createMessage("ERROR GAME");
    }

    virtual bool isValid() const override {
        return false;
    }

    virtual Message toString() const override {
        return message;
    }
}; /* END class ErrorGame */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_GAME_HPP__ */
