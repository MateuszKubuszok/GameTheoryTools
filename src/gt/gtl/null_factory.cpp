/**
 * @file      gt/gtl/null_factory.cpp
 * @brief     Defines GT::GTL::NullFactory methods.
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

// class NullFactory final {
// public:

NullFactory& NullFactory::getInstance() {
    static NullFactory instance;
    return instance;
}

ConditionPtr NullFactory::createCondition() const {
    return ConditionPtr(new NullCondition());
}

ConditionsPtr NullFactory::createConditions() const {
    return ConditionsPtr(new Conditions());
}

ContextPtr NullFactory::createContext() const {
    return ContextPtr(new NullContext());
}

CoordinatePtr NullFactory::createCoordinate() const {
    return CoordinatePtr(new NullCoordinate());
}

CoordinatesPtr NullFactory::createCoordinates() const {
    return CoordinatesPtr(new Coordinates());
}

DefinitionPtr NullFactory::createDefinition() const {
    return DefinitionPtr(new NullDefinition());
}

DetailsPtr NullFactory::createDetails() const {
    return DetailsPtr(new NullDetails());
}

GamePtr NullFactory::createGame() const {
    return GamePtr(new NullGame());
}

ObjectPtr NullFactory::createObject() const {
    return ObjectPtr(new NullObject());
}

ObjectsPtr NullFactory::createObjects() const {
    return ObjectsPtr(new Objects());
}

ParamPtr NullFactory::createParam() const {
    return ParamPtr(new NullParam());
}

ParamsPtr NullFactory::createParams() const {
    return ParamsPtr(new Params());
}

PlayerPtr NullFactory::createPlayer() const {
    return PlayerPtr(new NullPlayer());
}

PositionsPtr NullFactory::createPositions() const {
    return PositionsPtr(new Positions());
}

ResultPtr NullFactory::createResult() const {
    return ResultPtr(new NullResult());
}

QueryPtr NullFactory::createQuery() const {
    return QueryPtr(new NullQuery());
}

DriverPtr NullFactory::createDriver() const {
    return DriverPtr(new NullDriver());
}

ConditionDriverPtr NullFactory::createConditionDriver() const {
    return ConditionDriverPtr(new NullConditionDriver());
}

CoordinateDriverPtr NullFactory::createCoordinateDriver() const {
    return CoordinateDriverPtr(new NullCoordinateDriver());
}

GameDriverPtr NullFactory::createGameDriver() const {
    return GameDriverPtr(new NullGameDriver());
}

ValueDriverPtr NullFactory::createValueDriver() const {
    return ValueDriverPtr(new NullValueDriver());
}

StatementDriverPtr NullFactory::createStatementDriver() const {
    return StatementDriverPtr(new NullStatementDriver());
}

CollectionsDriverPtr<Coordinate> NullFactory::createCoordinatesDriver() const {
    return CollectionsDriverPtr<Coordinate>(new NullCollectionsDriver<Coordinate>());
}

CollectionsDriverPtr<Condition> NullFactory::createConditionsDriver() const {
    return CollectionsDriverPtr<Condition>(new NullCollectionsDriver<Condition>());
}

CollectionsDriverPtr<Identifier> NullFactory::createIdentifiersDriver() const {
    return CollectionsDriverPtr<Identifier>(new NullCollectionsDriver<Identifier>());
}

CollectionsDriverPtr<Object> NullFactory::createObjectsDriver() const {
    return CollectionsDriverPtr<Object>(new NullCollectionsDriver<Object>());
}

CollectionsDriverPtr<Param> NullFactory::createParamsDriver() const {
    return CollectionsDriverPtr<Param>(new NullCollectionsDriver<Param>());
}

InputLocationPtr NullFactory::createInputLocation() const {
    return InputLocationPtr(new InputLocation());
}

// }; /* END class NullFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
