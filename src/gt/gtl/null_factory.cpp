#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class NullFactory {

NullFactory& NullFactory::getInstance() {
    static NullFactory instance;
    return instance;
}

// public:

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

// private:

NullFactory::NullFactory() {}

NullFactory::~NullFactory() {}

// }; /* END class NullFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
