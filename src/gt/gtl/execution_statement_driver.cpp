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
    const DefinitionPtr* definitionPtr
) {
    if (!checkingStatementDriver.executeDefinition(definitionPtr))
        return false;

    context->registerParam(*definitionPtr);

    return true;
}

bool ExecutionStatementDriver::executeQuery(
    const QueryPtr* queryPtr
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
    const InputLocation& inputLocation,
    const IdentifierPtr* identifierPtr,
    const ObjectPtr*     objectPtr
) const {
    DefinitionPtr* errorCheck =
        checkingStatementDriver.createDefinition(inputLocation, identifierPtr, objectPtr);
    if (!(*errorCheck)->isValid())
        return errorCheck;
    delete errorCheck;

    const IdentifierPtr& identifier = *identifierPtr;
    const ObjectPtr&     object     = *objectPtr;

    return new DefinitionPtr(
        setupLocation<Definition>(
            DefinitionPtr(new Definition(identifier, ParamFactory::getInstance().createParam(object))),
            inputLocation
        )
    );
}

QueryPtr* ExecutionStatementDriver::createQuery(
    const InputLocation&  inputLocation,
    const IdentifiersPtr* identifiersPtr,
    const ObjectsPtr*     objectsPtr,
    const ConditionsPtr*  conditionsPtr
) const {
    QueryPtr* errorCheck =
        checkingStatementDriver.createQuery(inputLocation, identifiersPtr, objectsPtr, conditionsPtr);
    if (!(*errorCheck)->isValid())
        return errorCheck;
    delete errorCheck;

    const IdentifiersPtr& identifiers = *identifiersPtr;
    const ObjectsPtr&     objects     = *objectsPtr;
    const ConditionsPtr&  conditions  = *conditionsPtr;

    return new QueryPtr(
        setupLocation<Query>(
            QueryPtr(new Query(identifiers, objects, conditions)),
            inputLocation
        )
    );
}

Message ExecutionStatementDriver::toString() const {
    return Message("ExecutionStatementDriver");
}

// }; /* END class ExecutionStatementDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
