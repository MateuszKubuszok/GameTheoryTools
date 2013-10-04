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
    // TODO: NullCoodinates
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
    // TODO: NullObjects
    return ObjectsPtr(new Objects());
}

ParamPtr NullFactory::createParam() {
    return ParamPtr(new NullParam());
}

ParamsPtr NullFactory::createParams() {
    // TODO: NullParams
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

// private:

NullFactory::NullFactory() {}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
