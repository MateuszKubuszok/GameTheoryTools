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

using boost::make_shared;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class NullFactory final {
// public:

NullFactory& NullFactory::getInstance() {
    static NullFactory instance;
    return instance;
}

ConditionPtr NullFactory::createCondition() const {
    return make_shared<NullCondition>();
}

ConditionsPtr NullFactory::createConditions() const {
    return make_shared<Conditions>();
}

ContextPtr NullFactory::createContext() const {
    return make_shared<NullContext>();
}

CoordinatePtr NullFactory::createCoordinate() const {
    return make_shared<NullCoordinate>();
}

CoordinatesPtr NullFactory::createCoordinates() const {
    return make_shared<Coordinates>();
}

DefinitionPtr NullFactory::createDefinition() const {
    return make_shared<NullDefinition>();
}

DetailsPtr NullFactory::createDetails() const {
    return make_shared<NullDetails>();
}

GamePtr NullFactory::createGame() const {
    return make_shared<NullGame>();
}

ObjectPtr NullFactory::createObject() const {
    return make_shared<NullObject>();
}

ObjectsPtr NullFactory::createObjects() const {
    return make_shared<Objects>();
}

ParamPtr NullFactory::createParam() const {
    return make_shared<NullParam>();
}

ParamsPtr NullFactory::createParams() const {
    return make_shared<Params>();
}

PlayerPtr NullFactory::createPlayer() const {
    return make_shared<NullPlayer>();
}

PositionsPtr NullFactory::createPositions() const {
    return make_shared<Positions>();
}

ResultPtr NullFactory::createResult() const {
    return make_shared<NullResult>();
}

QueryPtr NullFactory::createQuery() const {
    return make_shared<NullQuery>();
}

DriverPtr NullFactory::createDriver() const {
    return make_shared<NullDriver>();
}

ConditionDriverPtr NullFactory::createConditionDriver() const {
    return make_shared<NullConditionDriver>();
}

CoordinateDriverPtr NullFactory::createCoordinateDriver() const {
    return make_shared<NullCoordinateDriver>();
}

GameDriverPtr NullFactory::createGameDriver() const {
    return make_shared<NullGameDriver>();
}

ValueDriverPtr NullFactory::createValueDriver() const {
    return make_shared<NullValueDriver>();
}

StatementDriverPtr NullFactory::createStatementDriver() const {
    return make_shared<NullStatementDriver>();
}

CollectionsDriverPtr<Coordinate> NullFactory::createCoordinatesDriver() const {
    return make_shared<NullCollectionsDriver<Coordinate>>();
}

CollectionsDriverPtr<Condition> NullFactory::createConditionsDriver() const {
    return make_shared<NullCollectionsDriver<Condition>>();
}

CollectionsDriverPtr<Identifier> NullFactory::createIdentifiersDriver() const {
    return make_shared<NullCollectionsDriver<Identifier>>();
}

CollectionsDriverPtr<Object> NullFactory::createObjectsDriver() const {
    return make_shared<NullCollectionsDriver<Object>>();
}

CollectionsDriverPtr<Param> NullFactory::createParamsDriver() const {
    return make_shared<NullCollectionsDriver<Param>>();
}

InputLocationPtr NullFactory::createInputLocation() const {
    return make_shared<InputLocation>();
}

// }; /* END class NullFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
