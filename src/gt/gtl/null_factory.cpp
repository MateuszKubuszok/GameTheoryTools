#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

boost::mutex nullFactoryMutex;

////////////////////////////////////////////////////////////////////////////////

// class NullFactory {

NullFactory* volatile NullFactory::instance = 0;

// public:

NullFactory& NullFactory::getInstance() {
    // Singleton implemented according to:
    // "C++ and the Perils of Double-Checked Locking"
    // but without executing constructor inside getInstance() method
    // since it's an eyesore. 
    if (!instance) {
        boost::mutex::scoped_lock lock(nullFactoryMutex);
        if (!instance) {
            NullFactory* volatile tmp = new NullFactory();
            instance = tmp;
        }
    }
    return *instance;
}

ConditionPtr NullFactory::createCondition() {
    return ConditionPtr(new NullCondition());
}

ConditionsPtr NullFactory::createConditions() {
    // TODO: NullParams
    return ConditionsPtr(new Conditions());
}

ContextPtr NullFactory::createContext() {
    return ContextPtr(new NullContext());
}

CoordinatePtr NullFactory::createCoordinate() {
    return CoordinatePtr(new NullCoordinate());
}

CoordinatesPtr NullFactory::createCoordinates() {
    return CoordinatesPtr(new Coordinates());
}

DefinitionPtr NullFactory::createDefinition() {
    return DefinitionPtr(new NullDefinition());
}

DetailsPtr NullFactory::createDetails() {
    return DetailsPtr(new NullDetails());
}

GamePtr NullFactory::createGame() {
    return GamePtr(new NullGame());
}

ObjectPtr NullFactory::createObject() {
    return ObjectPtr(new NullObject());
}

ObjectsPtr NullFactory::createObjects() {
    return ObjectsPtr(new Objects());
}

ParamPtr NullFactory::createParam() {
    return ParamPtr(new NullParam());
}

ParamsPtr NullFactory::createParams() {
    return ParamsPtr(new Params());
}

PlayerPtr NullFactory::createPlayer() {
    return PlayerPtr(new NullPlayer());
}

PositionsPtr NullFactory::createPositions() {
    return PositionsPtr(new Positions());
}

ResultPtr NullFactory::createResult() {
    return ResultPtr(new NullResult());
}

QueryPtr NullFactory::createQuery() {
    return QueryPtr(new NullQuery());
}

DriverPtr NullFactory::createDriver() {
    return DriverPtr(new NullDriver());
}

ConditionDriverPtr NullFactory::createConditionDriver() {
    return ConditionDriverPtr(new NullConditionDriver());
}

CoordinateDriverPtr NullFactory::createCoordinateDriver() {
    return CoordinateDriverPtr(new NullCoordinateDriver());
}

GameDriverPtr NullFactory::createGameDriver() {
    return GameDriverPtr(new NullGameDriver());
}

ValueDriverPtr NullFactory::createValueDriver() {
    return ValueDriverPtr(new NullValueDriver());
}

StatementDriverPtr NullFactory::createStatementDriver() {
    return StatementDriverPtr(new NullStatementDriver());
}

CollectionsDriverPtr<Coordinate> NullFactory::createCoordinatesDriver() {
    return CollectionsDriverPtr<Coordinate>(new NullCollectionsDriver<Coordinate>());
}

CollectionsDriverPtr<Condition> NullFactory::createConditionsDriver() {
    return CollectionsDriverPtr<Condition>(new NullCollectionsDriver<Condition>());
}

CollectionsDriverPtr<Identifier> NullFactory::createIdentifiersDriver() {
    return CollectionsDriverPtr<Identifier>(new NullCollectionsDriver<Identifier>());
}

CollectionsDriverPtr<Object> NullFactory::createObjectsDriver() {
    return CollectionsDriverPtr<Object>(new NullCollectionsDriver<Object>());
}

CollectionsDriverPtr<Param> NullFactory::createParamsDriver() {
    return CollectionsDriverPtr<Param>(new NullCollectionsDriver<Param>());
}

// private:

NullFactory::NullFactory() {}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
