#ifndef __GT_GTL_EXECUTION_GAME_DRIVER_HPP__
#define __GT_GTL_EXECUTION_GAME_DRIVER_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/execution_game_driver.hpp
 * @brief     Defines GT::GTL::ExecutionGameDriver class.
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
 * @class ExecutionGameDriver
 * @brief Implementation used for handling Games via ExecutionDriver.
 *
 * Performs actual execution of instructions for Games.
 *
 * @author Mateusz Kubuszok
 *
 * @see ExecutionDriver
 * @see GameDriver
 */
class ExecutionGameDriver final : public GameDriver {
    /**
     * @brief Driver for error handling.
     */
    CheckingGameDriver checkingGameDriver;
    /**
     * @brief Implementation of a main Driver.
     */
    Driver*            driver;
    /**
     * @brief Contains Context.
     */
    Context*           context;

public:
    /**
     * @brief Initiates ExecutionGameDriver with its parent.
     *
     * @param parentDriver parent Driver
     * @param context      Context data
     */
    ExecutionGameDriver(
        Driver*  parentDriver,
        Context* context
    );

    /**
     * @brief Create Strategic Game.
     *
     * @param inputLocation input location of created Game
     * @param details       Details for game
     * @return              Game
     */
    virtual GamePtr* createStrategic(
        const InputLocation& inputLocation,
        const DetailsPtr*    details
    ) const override;

    /**
     * @brief Create Extensive Game.
     *
     * @param inputLocation input location of created Game
     * @param details       Details for game
     * @return              Game
     */
    virtual GamePtr* createExtensive(
        const InputLocation& inputLocation,
        const DetailsPtr*    details
    ) const override;

    /**
     * @brief Create Details.
     *
     * @param inputLocation input location of created Details
     * @param player        declared Players
     * @param data          declared Coordinates
     * @return              Details
     */
    virtual DetailsPtr* createDetails(
        const InputLocation&  inputLocation,
        const ObjectsPtr*     players,
        const CoordinatesPtr* data
    ) const override;

    /**
     * @brief Create Player.
     *
     * @param inputLocation input location of created Player
     * @param player        Player's name
     * @param strategies    strategies
     * @return              Player
     */
    virtual PlayerPtr* createPlayer(
        const InputLocation&  inputLocation,
        const IdentifierPtr*  player,
        const IdentifiersPtr* strategies
    ) const override;

    /**
     * @brief ExecutionGameDriver's Message.
     *
     * @return message
     */
    virtual Message toString() const override;

private:
    /**
     * @brief Game building routine common for Strategic and Extensive form Games.
     *
     * @param inputLocation input location of created Game
     * @param details       Details built game details
     * @param gameBuilder   GameBuilder specific for given game
     * @return              Game instance (valid or not)
     */
    GamePtr* createGameWithBuilder(
        const InputLocation&      inputLocation,
        const Details&            details,
        const Model::GameBuilder& gameBuilder
    ) const;
}; /* END class ExecutionGameDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_EXECUTION_GAME_DRIVER_HPP__ */
