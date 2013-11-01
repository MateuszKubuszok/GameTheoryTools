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
    InputLocation&       inputLocation,
    const IdentifierPtr* playerPtr,
    const IdentifierPtr* strategyPtr
) {
    CoordinatePtr* errorCheck = checkingCoordinateDriver.create(inputLocation, playerPtr, strategyPtr);
    if (!(*errorCheck)->isValid())
        return errorCheck;

    return new CoordinatePtr(
        setupLocation<Coordinate>(
            CoordinatePtr(new Coordinate(*playerPtr, *strategyPtr)),
            inputLocation
        )
    );
}

CoordinatePtr* ExecutionCoordinateDriver::fillWithData(
    InputLocation&        inputLocation,
    const CoordinatePtr*  coordinatePtr,
    const CoordinatesPtr* dataPtr
) {
    CoordinatePtr* errorCheck = checkingCoordinateDriver.fillWithData(inputLocation, coordinatePtr, dataPtr);
    if (!(*errorCheck)->isValid())
        return errorCheck;

    (*coordinatePtr)->addSubCoordinates(*dataPtr);

    return new CoordinatePtr(
        setupLocation<Coordinate>(
            (*coordinatePtr),
            inputLocation
        )
    );
}

CoordinatePtr* ExecutionCoordinateDriver::fillWithData(
    InputLocation&       inputLocation,
    const CoordinatePtr* coordinatePtr,
    const ParamsPtr*     dataPtr
) {
    CoordinatePtr* errorCheck = checkingCoordinateDriver.fillWithData(inputLocation, coordinatePtr, dataPtr);
    if (!(*errorCheck)->isValid())
        return errorCheck;

    (*coordinatePtr)->addParams(*dataPtr);

    return new CoordinatePtr(
        setupLocation<Coordinate>(
            (*coordinatePtr),
            inputLocation
        )
    );
}

CoordinatePtr* ExecutionCoordinateDriver::merge(
    InputLocation&       inputLocation,
    const CoordinatePtr* coordinate1Ptr,
    const CoordinatePtr* coordinate2Ptr
) {
    CoordinatePtr* errorCheck = checkingCoordinateDriver.merge(inputLocation, coordinate1Ptr, coordinate2Ptr);
    if (!(*errorCheck)->isValid())
        return errorCheck;

    Coordinate& coordinate1 = **coordinate1Ptr;
    Coordinate& coordinate2 = **coordinate2Ptr;

    return new CoordinatePtr(
        setupLocation<Coordinate>(
            CoordinatePtr(new Coordinate(coordinate1 + coordinate2)),
            inputLocation
        )
    );
}

Message ExecutionCoordinateDriver::toString() {
    return Message("ExecutionCoordinateDriver");
}

// }; /* END class ExecutionCoordinateDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
