/**
 * @file      gt/gtl/checking_coordinate_driver.cpp
 * @brief     Defines GT::GTL::CheckingCoordinateDriver methods.
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

#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class CheckingCoordinateDriver final : public CoordinateDriver {
// public:

CoordinatePtr* CheckingCoordinateDriver::create(
    const InputLocation& inputLocation,
    const IdentifierPtr*,
    const IdentifierPtr*
) const {
    return new CoordinatePtr(
        setupLocation<Coordinate>(
            NullFactory::getInstance().createCoordinate(),
            inputLocation
        )
    );
}

CoordinatePtr* CheckingCoordinateDriver::fillWithData(
    const InputLocation&  inputLocation,
    const CoordinatePtr*  coordinatePtr,
    const CoordinatesPtr* dataPtr
) const {
    const Coordinate&  coordinate = **coordinatePtr;
    const Coordinates& data       = **dataPtr;

    if (!coordinate) {
        // TODO: create MessageFactory
        Message errorMessage = Message() +
            "Invalid Coordinate: " + coordinate.toString();
        return new CoordinatePtr(
            setupLocation<Coordinate>(
                ErrorFactory::getInstance().createCoordinate(errorMessage),
                *coordinate.getInputLocation()
            )
        );
    }

    for (CoordinatePtr subCoordinatePtr : data) {
        Coordinate& subCoordinate = *subCoordinatePtr;
        if (!subCoordinate) {
            // TODO: create MessageFactory
            Message errorMessage = Message() +
                "Invalid Data: " + subCoordinate.toString();
            return new CoordinatePtr(
                setupLocation<Coordinate>(
                    ErrorFactory::getInstance().createCoordinate(errorMessage),
                    *subCoordinate.getInputLocation()
                )
            );
        }
    }

    return new CoordinatePtr(
        setupLocation<Coordinate>(
            NullFactory::getInstance().createCoordinate(),
            inputLocation
        )
    );
}

CoordinatePtr* CheckingCoordinateDriver::fillWithData(
    const InputLocation& inputLocation,
    const CoordinatePtr* coordinatePtr,
    const ParamsPtr*     dataPtr
) const {
    const Coordinate&  coordinate = **coordinatePtr;
    const Params&      data       = **dataPtr;

    if (!coordinate) {
        // TODO: create MessageFactory
        Message errorMessage = Message() +
            "Invalid Coordinate: " + coordinate.toString();
        return new CoordinatePtr(
            setupLocation<Coordinate>(
                ErrorFactory::getInstance().createCoordinate(errorMessage),
                *coordinate.getInputLocation()
            )
        );
    }

    for (ParamPtr subDataPtr : data) {
        Param& subData = *subDataPtr;
        if (!subData) {
            // TODO: create MessageFactory
            Message errorMessage = Message() +
                "Invalid Data: " + subData.toString();
            return new CoordinatePtr(
                setupLocation<Coordinate>(
                    ErrorFactory::getInstance().createCoordinate(errorMessage),
                    *subData.getInputLocation()
                )
            );
        }
    }

    return new CoordinatePtr(
        setupLocation<Coordinate>(
            NullFactory::getInstance().createCoordinate(),
            inputLocation
        )
    );
}

CoordinatePtr* CheckingCoordinateDriver::merge(
    const InputLocation& inputLocation,
    const CoordinatePtr* coordinate1Ptr,
    const CoordinatePtr* coordinate2Ptr
) const {
    const Coordinate&  coordinate1 = **coordinate1Ptr;
    const Coordinate&  coordinate2 = **coordinate2Ptr;

    if (!coordinate1) {
        // TODO: create MessageFactory
        Message errorMessage = Message() +
            "Invalid Coordinate: " + coordinate1.toString();
        return new CoordinatePtr(
            setupLocation<Coordinate>(
                ErrorFactory::getInstance().createCoordinate(errorMessage),
                *coordinate1.getInputLocation()
            )
        );
    }

    if (!coordinate2) {
        // TODO: create MessageFactory
        Message errorMessage = Message() +
            "Invalid Coordinate: " + coordinate2.toString();
        return new CoordinatePtr(
            setupLocation<Coordinate>(
                ErrorFactory::getInstance().createCoordinate(errorMessage),
                *coordinate2.getInputLocation()
            )
        );
    }

    return new CoordinatePtr(
        setupLocation<Coordinate>(
            NullFactory::getInstance().createCoordinate(),
            inputLocation
        )
    );
}

Message CheckingCoordinateDriver::toString() const {
    return Message("CheckingCoordinateDriver");
}

// }; /* END class CheckingCoordinateDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
