#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class CheckingStatementDriver {
// public:

void CheckingStatementDriver::executeDefinition(
    DefinitionPtr*
) {
    // TODO check whether definition can be executed
    // show error if occured
}

void CheckingStatementDriver::executeQuery(
    QueryPtr*
) {
    // TODO check whether query can be executed
}

DefinitionPtr* CheckingStatementDriver::createDefinition(
    IdentifierPtr*,
    ObjectPtr*     object
) {
    if (!(*object)->isValid())
        return new DefinitionPtr(ErrorFactory::getInstance().createDefinition((*object)->toString()));
    return new DefinitionPtr(NullFactory::getInstance().createDefinition());
}

QueryPtr* CheckingStatementDriver::createQuery(
    IdentifiersPtr* identifiers,
    ObjectsPtr*     objects,
    ConditionsPtr*
) {
    for (ObjectPtr& object : **objects) {
        if (!object->isValid())
            return new QueryPtr(ErrorFactory::getInstance().createQuery(object->toString()));
        for (IdentifierPtr& property : **identifiers)
            if (!object->respondsTo(*property)) {
                Message errorMessage = Message() +
                    "Object: " + object->toString() + '\n' +
                    "has no property: " + *property;
                return new QueryPtr(ErrorFactory::getInstance().createQuery(errorMessage));
            }
    }
    return new QueryPtr(NullFactory::getInstance().createQuery());
}

Message CheckingStatementDriver::toString() {
    return Message("CheckingStatementDriver");
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
