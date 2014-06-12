/**
 * @file      gt/model/exception_factory.cpp
 * @brief     Defines GT::Model::ExceptionFactory methods.
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

#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using std::stringstream;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExceptionFactory final {
// public:

ExceptionFactory& ExceptionFactory::getInstance() {
    static ExceptionFactory instance;
    return instance;
}

InvalidCoordinate ExceptionFactory::duplicatedPlayerName(
    const Identifier& playerName
) const {
    stringstream result;

    result << "Name '" << playerName << "' already used for another player";

    return InvalidCoordinate(result.str());
}

InvalidCoordinate ExceptionFactory::duplicatedStrategyName(
    const Identifier& playerName,
    const Identifier& strategyName
) const {
    stringstream result;

    result << "Name '" << strategyName << "' already used for another strategy for player '"
                       << playerName << "'";

    return InvalidCoordinate(result.str());
}

InvalidCoordinate ExceptionFactory::emptyPlayerName() const {
    return InvalidCoordinate("Player's name cannot be empty");
}

InvalidCoordinate ExceptionFactory::coordinatesAlreadySet(
    const Positions& positions
) const {
    stringstream result;

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
    stringstream result;

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
    stringstream result;

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
    stringstream result;

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
    stringstream result;

    result << "No Player '" << playerName << "' has been defined";

    return InvalidCoordinate(result.str());
}

InvalidCoordinate ExceptionFactory::invalidStrategy(
    const Identifier& strategyName
) const {
    stringstream result;

    result << "No Strategy '" << strategyName << "' has been defined";

    return InvalidCoordinate(result.str());
}

InvalidCoordinate ExceptionFactory::invalidInformationSet(
    const Identifier& infromationSetName
) const {
    stringstream result;

    result << "No Information Set '" << infromationSetName << "' has been defined";

    return InvalidCoordinate(result.str());
}

IllegalInnerState ExceptionFactory::playersAlreadySet() const {
    return IllegalInnerState("Cannot change already set Players");
}

IllegalInnerState ExceptionFactory::propertiesAndResultsDontMatchInSize(
    const Index propertiesSize,
    const Index resultsSize
) const {
    stringstream result;

    result << "Properties size ("
           << propertiesSize
           << ") and Results size ("
           << resultsSize
           << ") does not match";

    return IllegalInnerState(result.str());
}

// }; /* END class ExceptionFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
