#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ErrorFactory {

ErrorFactory& ErrorFactory::getInstance() {
    static ErrorFactory instance;
    return instance;
}

// public:

ConditionPtr ErrorFactory::createCondition(
    const Message errorMessage
) const {
    return ConditionPtr(new ErrorCondition(errorMessage));
}

CoordinatePtr ErrorFactory::createCoordinate(
    const Message errorMessage
) const {
    return CoordinatePtr(new ErrorCoordinate(errorMessage));
}

DefinitionPtr ErrorFactory::createDefinition(
    const Message errorMessage
) const {
    return DefinitionPtr(new ErrorDefinition(errorMessage));
}

DetailsPtr ErrorFactory::createDetails(
    const Message errorMessage
) const {
    return DetailsPtr(new ErrorDetails(errorMessage));
}

GamePtr ErrorFactory::createGame(
    const Message errorMessage
) const {
    return GamePtr(new ErrorGame(errorMessage));
}

ObjectPtr ErrorFactory::createObject(
    const Message errorMessage
) const {
    return ObjectPtr(new ErrorObject(errorMessage));
}

ParamPtr ErrorFactory::createParam(
    const Message errorMessage
) const {
    return ParamPtr(new ErrorParam(errorMessage));
}

PlayerPtr ErrorFactory::createPlayer(
    const Message errorMessage
) const {
    return PlayerPtr(new ErrorPlayer(errorMessage));
}

QueryPtr ErrorFactory::createQuery(
    const Message errorMessage
) const {
    return QueryPtr(new ErrorQuery(errorMessage));
}

// private:

ErrorFactory::ErrorFactory() {}

ErrorFactory::~ErrorFactory() {}

// }; /* END class ErrorFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
