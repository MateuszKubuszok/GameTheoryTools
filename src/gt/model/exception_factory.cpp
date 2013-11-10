#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExceptionFactory {

SINGLETON_DEFINITION(ExceptionFactory, getInstance, exceptionFactoryMutex)

// public:

InvalidCoordinate ExceptionFactory::coordinatesAlreadySet(
    const Positions& positions
) const {
    std::stringstream result;

    result << "Coordinates:";
    for (const Positions::value_type& position : positions) {
        const Identifier  playerName   = position.first;
        const Identifier& strategyName = position.second;
        result << " '" << playerName << "'='" << strategyName << "'";
    }
    result << " already has defined payoff";

    return InvalidCoordinate(result.str());
}

IllegalInnerState ExceptionFactory::incompleteCoordinates() const {
    return IllegalInnerState("Cannot set parameters when not all coordinates are known");
}

InvalidCoordinate ExceptionFactory::invalidCoordinateFormat(
    const Positions& positions
) const {
    std::stringstream result;

    result << "Coordinates:";
    for (const Positions::value_type& position : positions) {
        const Identifier  playerName   = position.first;
        const Identifier& strategyName = position.second;
        result << " '" << playerName << "'='" << strategyName << "'";
    }
    result << " has invalid format - make sure chosen Players' names and strategies are valid";

    return InvalidCoordinate(result.str());
}

InvalidCoordinate ExceptionFactory::invalidExtensiveCoordinateFormat(
    const Positions& positions
) const {
    std::stringstream result;

    result << "Coordinates:";
    for (Positions::value_type position : positions) {
        const Identifier  playerName   = position.first;
        const Identifier& strategyName = position.second;
        result << " '" << playerName << "'='" << strategyName << "'";
    }
    result << " has invalid format - make sure chosen Players' names does not collide"
              " with other coordinates on the same level of tree";

    return InvalidCoordinate(result.str());
}

InvalidCoordinate ExceptionFactory::noParamsForPositions(
    const Index positionInStorage,
    const Index maxPosition
) const {
    std::stringstream result;

    result << "Calculated position ("
           << positionInStorage
           << ") has no defined payoff - make sure all Coordinates in range [0,"
           << (maxPosition-1)
           << "] has defined payoff";

    return InvalidCoordinate(result.str());
}

InvalidCoordinate ExceptionFactory::invalidPlayer(
    const Identifier& playerName
) const {
    std::stringstream result;

    result << "No Player '" << playerName << "' has been defined";

    return InvalidCoordinate(result.str());
}

InvalidCoordinate ExceptionFactory::invalidStrategy(
    const Identifier& strategyName
) const {
    std::stringstream result;

    result << "No Strategy '" << strategyName << "' has been defined";

    return InvalidCoordinate(result.str());
}

IllegalInnerState ExceptionFactory::playersAlreadySet() const {
    return IllegalInnerState("Cannot change already set Players");
}

IllegalInnerState ExceptionFactory::propertiesAndResultsDontMatchInSize(
    const Index propertiesSize,
    const Index resultsSize
) const {
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

ExceptionFactory::~ExceptionFactory() {}

// }; /* END class ExceptionFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
