#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExecutionCoordinateDriver : public CoordinateDriver {
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
