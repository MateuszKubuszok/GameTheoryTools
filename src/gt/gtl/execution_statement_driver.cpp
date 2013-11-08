#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExecutionStatementDriver : public StatementDriver {
// public:

ExecutionStatementDriver::ExecutionStatementDriver(
    Driver*  parentDriver,
    Context* parentContext
) :
    checkingStatementDriver(parentDriver),
    driver(parentDriver),
    context(parentContext)
    {}

bool ExecutionStatementDriver::executeDefinition(
    DefinitionPtr* definitionPtr
) {
    if (!checkingStatementDriver.executeDefinition(definitionPtr))
        return false;

    context->registerParam(*definitionPtr);

    return true;
}

bool ExecutionStatementDriver::executeQuery(
    QueryPtr* queryPtr
) {
    if (!checkingStatementDriver.executeQuery(queryPtr))
        return false;

    Query& query = **queryPtr;

    try {
        driver->showResult(query.execute(*context));
        return true;
    } catch (const std::exception& e) {
        driver->showError(*query.getInputLocation(), createMessage(e.what()));
        return false;
    }
}

DefinitionPtr* ExecutionStatementDriver::createDefinition(
    InputLocation& inputLocation,
    IdentifierPtr* identifierPtr,
    ObjectPtr*     objectPtr
) {
    DefinitionPtr* errorCheck =
        checkingStatementDriver.createDefinition(inputLocation, identifierPtr, objectPtr);
    if (!(*errorCheck)->isValid())
        return errorCheck;
    delete errorCheck;

    IdentifierPtr& identifier = *identifierPtr;
    ObjectPtr&     object     = *objectPtr;

    return new DefinitionPtr(
        setupLocation<Definition>(
            DefinitionPtr(new Definition(identifier, ParamFactory::getInstance().createParam(object))),
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
    QueryPtr* errorCheck =
        checkingStatementDriver.createQuery(inputLocation, identifiersPtr, objectsPtr, conditionsPtr);
    if (!(*errorCheck)->isValid())
        return errorCheck;
    delete errorCheck;

    IdentifiersPtr& identifiers = *identifiersPtr;
    ObjectsPtr&     objects     = *objectsPtr;
    ConditionsPtr&  conditions  = *conditionsPtr;

    return new QueryPtr(
        setupLocation<Query>(
            QueryPtr(new Query(identifiers, objects, conditions)),
            inputLocation
        )
    );
}

Message ExecutionStatementDriver::toString() {
    return Message("ExecutionStatementDriver");
}

// }; /* END class ExecutionStatementDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
