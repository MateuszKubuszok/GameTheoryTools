#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class Coordinate {
// public:

Coordinate::Coordinate() :
    Root()
    {}

Coordinate::Coordinate(
    const IdentifierPtr player,
    const IdentifierPtr strategy
) :
    Root()
    {}

Coordinate& Coordinate::addParams(
    const ParamPtr param
) {
    return *this;
}

Coordinate& Coordinate::addParams(
    const ParamsPtr params
) {
    return *this;
}

Coordinate& Coordinate::addPosition(
    const IdentifierPtr player,
    const IdentifierPtr strategy
) {
    return *this;
}

Coordinate& Coordinate::addSubCoordinates(
    const CoordinatePtr subCoordinate
) {
    return *this;
}

Coordinate& Coordinate::addSubCoordinates(
    const CoordinatesPtr subCoordinates
) {
    return *this;
}

ParamsPtr Coordinate::getParams() {
    return NullFactory::getInstance().createParams();
}

PositionsPtr Coordinate::getPositions() {
    return NullFactory::getInstance().createPositions();
}

CoordinatesPtr Coordinate::getSubCoordinates() {
    return NullFactory::getInstance().createCoordinates();
}

Message Coordinate::toString() {
    return Message("NullCoordinate");
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
