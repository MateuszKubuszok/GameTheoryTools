#ifndef __GT_GTL_CHECKING_COORDINATE_DRIVER_HPP__
#define __GT_GTL_CHECKING_COORDINATE_DRIVER_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/checking_coordinate_driver.hpp
 * @brief     Defines GT::GTL::CheckingCoordinateDriver class.
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
 * @class CheckingCoordinateDriver
 * @brief Implementation used for handling Coordinates via CheckingDriver.
 *
 * Performs only syntax/type checking on Coordinates' tokens.
 *
 * @author Mateusz Kubuszok
 *
 * @see CheckingDriver
 * @see CoordinateDriver
 */
class CheckingCoordinateDriver final : public CoordinateDriver {
    /**
     * @brief Implementation of a main Driver.
     */
    Driver* driver;

public:
    /**
     * @brief Initiates CheckingCoordinateDriver with its parent.
     *
     * @param parentDriver parent Driver
     */
    explicit CheckingCoordinateDriver(
        Driver* parentDriver
    );

    /**
     * @brief Creates coordinate.
     *
     * @param inputLocation input location of created Coordinate
     * @param player        dimension (Player)
     * @param strategy      position (strategy)
     * @return              Coordinate
     */
    virtual CoordinatePtr* create(
        const InputLocation& inputLocation,
        const IdentifierPtr* player,
        const IdentifierPtr* strategy
    ) const override;

    /**
     * @brief Fills Coordinate with subcoordinates.
     *
     * @param inputLocation input location of created Condition
     * @param coordinate    Coordinate to fill
     * @param data          data to insert
     * @return              Coordinate
     */
    virtual CoordinatePtr* fillWithData(
        const InputLocation&  inputLocation,
        const CoordinatePtr*  coordinate,
        const CoordinatesPtr* data
    ) const override;

    /**
     * @brief Fills Coordinate with Params.
     *
     * @param inputLocation input location of created Condition
     * @param coordinate    Coordinate to fill
     * @param data          data to insert
     * @return              Coordinate
     */
    virtual CoordinatePtr* fillWithData(
        const InputLocation& inputLocation,
        const CoordinatePtr* coordinate,
        const ParamsPtr*     data
    ) const override;

    /**
     * @brief Merge two coordinates into one.
     *
     * @param inputLocation input location of created Condition
     * @param coordinate1   first Coorinate
     * @param coordinate2   second Coorinate
     * @return              merged Coordinates
     */
    virtual CoordinatePtr* merge(
        const InputLocation& inputLocation,
        const CoordinatePtr* coordinate1,
        const CoordinatePtr* coordinate2
    ) const override;

    /**
     * @brief CheckingCoordinateDriver message.
     *
     * @return message
     */
    virtual Message toString() const override;
}; /* END class CheckingCoordinateDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END __GT_GTL_CHECKING_COORDINATE_DRIVER_HPP__ */
