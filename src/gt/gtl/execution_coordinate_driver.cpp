/**
 * @file      gt/gtl/execution_coordinate_driver.cpp
 * @brief     Defines GT::GTL::ExecutionCoordinateDriver methods.
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

// class ExecutionCoordinateDriver final : public CoordinateDriver {
// public:

ExecutionCoordinateDriver::ExecutionCoordinateDriver(
    Driver* parentDriver
) :
    checkingCoordinateDriver(parentDriver),
    driver(parentDriver)
    {}

CoordinatePtr* ExecutionCoordinateDriver::create(
    const InputLocation& inputLocation,
    const IdentifierPtr* playerPtr,
    const IdentifierPtr* strategyPtr
) const {
    CoordinatePtr* errorCheck = checkingCoordinateDriver.create(inputLocation, playerPtr, strategyPtr);
    if (!(*errorCheck)->isValid())
        return errorCheck;
    delete errorCheck;

    return new CoordinatePtr(
        setupLocation<Coordinate>(
            CoordinatePtr(new Coordinate(*playerPtr, *strategyPtr)),
            inputLocation
        )
    );
}

CoordinatePtr* ExecutionCoordinateDriver::fillWithData(
    const InputLocation&  inputLocation,
    const CoordinatePtr*  coordinatePtr,
    const CoordinatesPtr* dataPtr
) const {
    CoordinatePtr* errorCheck = checkingCoordinateDriver.fillWithData(inputLocation, coordinatePtr, dataPtr);
    if (!(*errorCheck)->isValid())
        return errorCheck;
    delete errorCheck;

    (*coordinatePtr)->addSubCoordinates(*dataPtr);

    return new CoordinatePtr(
        setupLocation<Coordinate>(
            (*coordinatePtr),
            inputLocation
        )
    );
}

CoordinatePtr* ExecutionCoordinateDriver::fillWithData(
    const InputLocation& inputLocation,
    const CoordinatePtr* coordinatePtr,
    const ParamsPtr*     dataPtr
) const {
    CoordinatePtr* errorCheck = checkingCoordinateDriver.fillWithData(inputLocation, coordinatePtr, dataPtr);
    if (!(*errorCheck)->isValid())
        return errorCheck;
    delete errorCheck;

    (*coordinatePtr)->addParams(*dataPtr);

    return new CoordinatePtr(
        setupLocation<Coordinate>(
            (*coordinatePtr),
            inputLocation
        )
    );
}

CoordinatePtr* ExecutionCoordinateDriver::merge(
    const InputLocation& inputLocation,
    const CoordinatePtr* coordinate1Ptr,
    const CoordinatePtr* coordinate2Ptr
) const {
    CoordinatePtr* errorCheck = checkingCoordinateDriver.merge(inputLocation, coordinate1Ptr, coordinate2Ptr);
    if (!(*errorCheck)->isValid())
        return errorCheck;
    delete errorCheck;

    const Coordinate& coordinate1 = **coordinate1Ptr;
    const Coordinate& coordinate2 = **coordinate2Ptr;

    return new CoordinatePtr(
        setupLocation<Coordinate>(
            CoordinatePtr(new Coordinate(coordinate1 + coordinate2)),
            inputLocation
        )
    );
}

Message ExecutionCoordinateDriver::toString() const {
    return Message("ExecutionCoordinateDriver");
}

// }; /* END class ExecutionCoordinateDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
