#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ErrorFactory {

SINGLETON_DEFINITION(ErrorFactory, getInstance, errorFactoryMutex)

// public:

ConditionPtr ErrorFactory::createCondition(
    Message errorMessage
) {
    return ConditionPtr(new ErrorCondition(errorMessage));
}

CoordinatePtr ErrorFactory::createCoordinate(
    Message errorMessage
) {
    return CoordinatePtr(new ErrorCoordinate(errorMessage));
}

DefinitionPtr ErrorFactory::createDefinition(
    Message errorMessage
) {
    return DefinitionPtr(new ErrorDefinition(errorMessage));
}

DetailsPtr ErrorFactory::createDetails(
    Message errorMessage
) {
    return DetailsPtr(new ErrorDetails(errorMessage));
}

GamePtr ErrorFactory::createGame(
    Message errorMessage
) {
    return GamePtr(new ErrorGame(errorMessage));
}

ObjectPtr ErrorFactory::createObject(
    Message errorMessage
) {
    return ObjectPtr(new ErrorObject(errorMessage));
}

ParamPtr ErrorFactory::createParam(
    Message errorMessage
) {
    return ParamPtr(new ErrorParam(errorMessage));
}

PlayerPtr ErrorFactory::createPlayer(
    Message errorMessage
) {
    return PlayerPtr(new ErrorPlayer(errorMessage));
}

QueryPtr ErrorFactory::createQuery(
    Message errorMessage
) {
    return QueryPtr(new ErrorQuery(errorMessage));
}

// private:

ErrorFactory::ErrorFactory() {}

ErrorFactory::~ErrorFactory() {}

// }; /* END class ErrorFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
