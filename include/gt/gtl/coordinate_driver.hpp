#ifndef GT_GTL_COORDINATE_DRIVER_HPP_INCLUDED
#define GT_GTL_COORDINATE_DRIVER_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/coordinate_driver.hpp
 * @brief     Defines GT::GTL::CoordinateDriver interface.
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
 * @class CoordinateDriver
 * @brief Used for handling Coordinates via Driver.
 *
 * @author Mateusz Kubuszok
 */
class CoordinateDriver : public virtual Root {
public:
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
    ) const = 0;

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
    ) const = 0;

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
    ) const = 0;

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
    ) const = 0;

    /**
     * @brief CoordinateDriver message.
     *
     * @return message
     */
    virtual Message toString() const override = 0;
}; /* END class CoordinateDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class NullCoordinateDriver
 * @brief Null CoordinateDriver for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullCoordinateDriver : public CoordinateDriver {
public:
    NullCoordinateDriver() :
        CoordinateDriver()
        {}

    virtual CoordinatePtr* create(
        const InputLocation& inputLocation,
        const IdentifierPtr*,
        const IdentifierPtr*
    ) const override {
        return new CoordinatePtr(
            setupLocation<Coordinate>(
                NullFactory::getInstance().createCoordinate(),
                inputLocation
            )
        );
    }

    virtual CoordinatePtr* fillWithData(
        const InputLocation& inputLocation,
        const CoordinatePtr*,
        const CoordinatesPtr*
    ) const override {
        return new CoordinatePtr(
            setupLocation<Coordinate>(
                NullFactory::getInstance().createCoordinate(),
                inputLocation
            )
        );
    }

    virtual CoordinatePtr* fillWithData(
        const InputLocation& inputLocation,
        const CoordinatePtr*,
        const ParamsPtr*
    ) const override {
        return new CoordinatePtr(
            setupLocation<Coordinate>(
                NullFactory::getInstance().createCoordinate(),
                inputLocation
            )
        );
    }

    virtual CoordinatePtr* merge(
        const InputLocation& inputLocation,
        const CoordinatePtr*,
        const CoordinatePtr*
    ) const override {
        return new CoordinatePtr(
            setupLocation<Coordinate>(
                NullFactory::getInstance().createCoordinate(),
                inputLocation
            )
        );
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullCoordinateDriver");
    }
}; /* END class NullCoordinateDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END GT_GTL_COORDINATE_DRIVER_HPP_INCLUDED */
