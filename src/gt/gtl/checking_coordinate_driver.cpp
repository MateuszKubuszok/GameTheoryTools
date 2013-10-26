#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class CheckingCoordinateDriver {
// public:

CheckingCoordinateDriver::CheckingCoordinateDriver(
    Driver* parentDriver
) :
    driver(parentDriver)
    {}

CoordinatePtr* CheckingCoordinateDriver::create(
    InputLocation&       inputLocation,
    const IdentifierPtr*,
    const IdentifierPtr*
) {
    return new CoordinatePtr(
        setupLocation<Coordinate>(
            NullFactory::getInstance().createCoordinate(),
            inputLocation
        )
    );
}

CoordinatePtr* CheckingCoordinateDriver::fillWithData(
    InputLocation&        inputLocation,
    const CoordinatePtr*  coordinatePtr,
    const CoordinatesPtr* dataPtr
) {
    Coordinate&  coordinate = **coordinatePtr;
    Coordinates& data       = **dataPtr;

    if (!coordinate) {
        Message errorMessage = Message() +
            "Invalid Coordinate: " + coordinate.toString();
        return new CoordinatePtr(
            setupLocation<Coordinate>(
                ErrorFactory::getInstance().createCoordinate(errorMessage),
                inputLocation
            )
        );
    }

    for (CoordinatePtr subCoordinatePtr : data) {
        Coordinate& subCoordinate = *subCoordinatePtr;
        if (!subCoordinate) {
            Message errorMessage = Message() +
                "Invalid Data: " + subCoordinate.toString();
            return new CoordinatePtr(
                setupLocation<Coordinate>(
                    ErrorFactory::getInstance().createCoordinate(errorMessage),
                    inputLocation
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
    InputLocation&       inputLocation,
    const CoordinatePtr* coordinatePtr,
    const ParamsPtr*     dataPtr
) {
    Coordinate&  coordinate = **coordinatePtr;
    Params&      data       = **dataPtr;

    if (!coordinate) {
        Message errorMessage = Message() +
            "Invalid Coordinate: " + coordinate.toString();
        return new CoordinatePtr(
            setupLocation<Coordinate>(
                ErrorFactory::getInstance().createCoordinate(errorMessage),
                inputLocation
            )
        );
    }

    for (ParamPtr subDataPtr : data) {
        Param& subData = *subDataPtr;
        if (!subData) {
            Message errorMessage = Message() +
                "Invalid Data: " + subData.toString();
            return new CoordinatePtr(
                setupLocation<Coordinate>(
                    ErrorFactory::getInstance().createCoordinate(errorMessage),
                    inputLocation
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
    InputLocation&       inputLocation,
    const CoordinatePtr* coordinate1Ptr,
    const CoordinatePtr* coordinate2Ptr
) {
    Coordinate&  coordinate1 = **coordinate1Ptr;
    Coordinate&  coordinate2 = **coordinate2Ptr;

    if (!coordinate1) {
        Message errorMessage = Message() +
            "Invalid Coordinate: " + coordinate1.toString();
        return new CoordinatePtr(
            setupLocation<Coordinate>(
                ErrorFactory::getInstance().createCoordinate(errorMessage),
                inputLocation
            )
        );
    }

    if (!coordinate2) {
        Message errorMessage = Message() +
            "Invalid Coordinate: " + coordinate2.toString();
        return new CoordinatePtr(
            setupLocation<Coordinate>(
                ErrorFactory::getInstance().createCoordinate(errorMessage),
                inputLocation
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

Message CheckingCoordinateDriver::toString() {
    return Message("CheckingCoordinateDriver");
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
