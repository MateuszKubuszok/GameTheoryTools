#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class ExecutionStatementDriver {
// public:

ExecutionStatementDriver::ExecutionStatementDriver(
    Driver* parentDriver
) :
    checkingStatementDriver(parentDriver),
    driver(parentDriver)
    {}

bool ExecutionStatementDriver::executeDefinition(
    DefinitionPtr* definitionPtr
) {
    if (!checkingStatementDriver.executeDefinition(definitionPtr))
        return false;
    // EXECUTE DEFINITION
    return true;
}

bool ExecutionStatementDriver::executeQuery(
    QueryPtr* queryPtr
) {
    if (!checkingStatementDriver.executeQuery(queryPtr))
        return false;
    // EXECUTE QUERY
    return true;
}

DefinitionPtr* ExecutionStatementDriver::createDefinition(
    InputLocation& inputLocation,
    IdentifierPtr* identifierPtr,
    ObjectPtr*     objectPtr
) {
    DefinitionPtr* errorCheck = checkingStatementDriver.createDefinition(inputLocation, identifierPtr, objectPtr);
    if (!(*errorCheck)->isValid())
        return errorCheck;

    // Identifier& identifier = **identifierPtr;
    // Object&     object     = **objectPtr;

    return new DefinitionPtr(
        setupLocation<Definition>(
            NullFactory::getInstance().createDefinition(),
            inputLocation
        )
    );
}

QueryPtr* ExecutionStatementDriver::createQuery(
    InputLocation&  inputLocation,
    IdentifiersPtr* identifiersPtr,
    ObjectsPtr*     objectsPtr,
    ConditionsPtr*  conditionsPtr
) {
    QueryPtr* errorCheck = checkingStatementDriver.createQuery(inputLocation, identifiersPtr, objectsPtr, conditionsPtr);
    if (!(*errorCheck)->isValid())
        return errorCheck;

    // Identifiers& identifiers = **identifiersPtr;
    // Objects&     objects     = **objectsPtr;
    // Conditions&  conditions  = **conditionsPtr;

    return new QueryPtr(
        setupLocation<Query>(
            NullFactory::getInstance().createQuery(),
            inputLocation
        )
    );
}

Message ExecutionStatementDriver::toString() {
    return Message("ExecutionStatementDriver");
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
