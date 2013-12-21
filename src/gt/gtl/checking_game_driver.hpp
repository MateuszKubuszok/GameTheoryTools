#ifndef __GT_GTL_CHECKING_GAME_DRIVER_HPP__
#define __GT_GTL_CHECKING_GAME_DRIVER_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/checking_game_driver.hpp
 * @brief     Defines GT::GTL::CheckingGameDriver class.
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
 * @class CheckingGameDriver
 * @brief Implementation used for handling Games via CheckingDriver.
 *
 * Performs only syntax/type checking on Games' tokens.
 *
 * @author Mateusz Kubuszok
 *
 * @see CheckingDriver
 * @see GameDriver
 */
class CheckingGameDriver final : public GameDriver {
    /**
     * @brief Implementation of a main Driver.
     */
    Driver* driver;

public:
    /**
     * @brief Initiates CheckingGameDriver with its parent.
     *
     * @param parentDriver parent Driver
     */
    explicit CheckingGameDriver(
        Driver* parentDriver
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
     * @brief CheckingGameDriver's Message.
     *
     * @return message
     */
    virtual Message toString() const override;
}; /* END class CheckingGameDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_CHECKING_GAME_DRIVER_HPP__ */
