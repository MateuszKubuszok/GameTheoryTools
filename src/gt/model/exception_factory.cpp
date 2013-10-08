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
    // "C++ and the Perils of Double-Checked Locking".
    if (!instance) {
        boost::mutex::scoped_lock lock(exceptionFactoryMutex);
        if (!instance) {
            ExceptionFactory* volatile tmp = (ExceptionFactory*) malloc(sizeof(ExceptionFactory));
            new (tmp) ExceptionFactory; // placement new
            instance = tmp;
        }
    }
    return *instance;
}

InvalidCoordinate ExceptionFactory::coordinatesAlreadySet(
    Positions& positions
) {
    std::stringstream result;
    
    result << "Coordinates:";
    for (Positions::value_type& position : positions) {
        Identifier  playerName   = position.first;
        Identifier& strategyName = position.second;
        result << " '" << playerName << "'='" << strategyName << "'";
    }
    result << " already has defined payoff";

    return InvalidCoordinate(result.str());
}

IllegalInnerState ExceptionFactory::incompleteCoordinates() {
    return IllegalInnerState("Cannot set parameters when not all coordinates are known");
}

InvalidCoordinate ExceptionFactory::invalidCoordinateFormat(
    Positions& positions
) {
    std::stringstream result;
    
    result << "Coordinates:";
    for (Positions::value_type& position : positions) {
        Identifier  playerName   = position.first;
        Identifier& strategyName = position.second;
        result << " '" << playerName << "'='" << strategyName << "'";
    }
    result << " has invalid format - make sure chosen Players' names and strategies are valid";

    return InvalidCoordinate(result.str());
}

InvalidCoordinate ExceptionFactory::invalidTreeCoordinateFormat(
    Positions& positions
) {
    std::stringstream result;
    
    result << "Coordinates:";
    for (Positions::value_type position : positions) {
        Identifier  playerName   = position.first;
        Identifier& strategyName = position.second;
        result << " '" << playerName << "'='" << strategyName << "'";
    }
    result << " has invalid format - make sure chosen Players' names does not collide with other coordinates on the same level of tree";

    return InvalidCoordinate(result.str());
}

InvalidCoordinate ExceptionFactory::noParamsForPositions(
    Index positionInStorage,
    Index maxPosition
) {
    std::stringstream result;

    result << "Calculated position ("
           << positionInStorage
           << ") has no defined payoff - make sure all Coordinates in range [0,"
           << (maxPosition-1)
           << "] has defined payoff";

    return InvalidCoordinate(result.str());
}

InvalidCoordinate ExceptionFactory::invalidPlayer(
    Identifier& playerName
) {
    std::stringstream result;

    result << "No Player '" << playerName << "' has been defined";

    return InvalidCoordinate(result.str());
}

InvalidCoordinate ExceptionFactory::invalidStrategy(
    Identifier& strategyName
) {
    std::stringstream result;

    result << "No Strategy '" << strategyName << "' has been defined";

    return InvalidCoordinate(result.str());
}

IllegalInnerState ExceptionFactory::playersAlreadySet() {
    return IllegalInnerState("Cannot change already set Players");
}

IllegalInnerState ExceptionFactory::propertiesAndResultsDontMatchInSize(
    Index propertiesSize,
    Index resultsSize
) {
    std::stringstream result;

    result << "Properties size ("
           << propertiesSize
           << ") and Results size ("
           << resultsSize
           << ") does not match";

    return IllegalInnerState(result.str());
}

// private:

ExceptionFactory::ExceptionFactory() {}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
