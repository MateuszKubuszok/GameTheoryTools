#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class CheckingCoordinateDriver : public CoordinateDriver {
// public:

CheckingCoordinateDriver::CheckingCoordinateDriver(
    Driver* parentDriver
) :
    driver(parentDriver)
    {}

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
        // TODO: create ErrorMessageFactory
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
            // TODO: create ErrorMessageFactory
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
    const InputLocation& inputLocation,
    const CoordinatePtr* coordinatePtr,
    const ParamsPtr*     dataPtr
) const {
    const Coordinate&  coordinate = **coordinatePtr;
    const Params&      data       = **dataPtr;

    if (!coordinate) {
        // TODO: create ErrorMessageFactory
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
            // TODO: create ErrorMessageFactory
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
    const InputLocation& inputLocation,
    const CoordinatePtr* coordinate1Ptr,
    const CoordinatePtr* coordinate2Ptr
) const {
    const Coordinate&  coordinate1 = **coordinate1Ptr;
    const Coordinate&  coordinate2 = **coordinate2Ptr;

    if (!coordinate1) {
        // TODO: create ErrorMessageFactory
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
        // TODO: create ErrorMessageFactory
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

Message CheckingCoordinateDriver::toString() const {
    return Message("CheckingCoordinateDriver");
}

// }; /* END class CheckingCoordinateDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
