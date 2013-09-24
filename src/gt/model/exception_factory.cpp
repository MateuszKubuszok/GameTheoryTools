#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

boost::mutex exceptionFactoryMutex;

////////////////////////////////////////////////////////////////////////////////

// class ResultFactory {

ExceptionFactory* volatile ExceptionFactory::instance = 0;

// public:

ExceptionFactory& ExceptionFactory::getInstance() {
    // Singleton implemented according to:
    // "C++ and the Perils of Double-Checked Locking"
    // but without executing constructor inside getInstance() method
    // since it's an eyesore. 
    if (!instance) {
        boost::mutex::scoped_lock lock(exceptionFactoryMutex);
        if (!instance) {
            ExceptionFactory* volatile tmp = new ExceptionFactory();
            instance = tmp;
        }
    }
    return *instance;
}

InvalidCoordinate ExceptionFactory::coordinatesAlreadySet(
    Positions& positions
) {
    return InvalidCoordinate("Some of Coordinates are already set");
}

IllegalInnerState ExceptionFactory::incompleteCoordinates() {
    return IllegalInnerState("Cannot set parameters when not all coordinates are known");
}

InvalidCoordinate ExceptionFactory::invalidCoordinateFormat(
    Positions& positions
) {
    return InvalidCoordinate("Invalid coordinates format");
}

InvalidCoordinate ExceptionFactory::noParamsForPositions(
    Index positionInStorage,
    Index maxPosition
) {
    return InvalidCoordinate("No params under such position");
}

InvalidCoordinate ExceptionFactory::invalidPlayer(
    Identifier& playerName
) {
    return InvalidCoordinate("No such Player");
}

InvalidCoordinate ExceptionFactory::invalidStrategy(
    Identifier& strategyName
) {
    return InvalidCoordinate("No such Strategy");
}

IllegalInnerState ExceptionFactory::playersAlreadySet() {
    return IllegalInnerState("Cannot change already set Players");
}

IllegalInnerState ExceptionFactory::propertiesAndResultsDontMatchInSize(
    Index propertiesSize,
    Index resultsSize
) {
    return IllegalInnerState("Properties size and Result\'s size does not match");
}

// private:

ExceptionFactory::ExceptionFactory() {}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
