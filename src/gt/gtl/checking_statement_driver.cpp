#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class CheckingStatementDriver {
// public:

CheckingStatementDriver::CheckingStatementDriver(
    Driver* parentDriver
) :
    driver(parentDriver)
    {}

bool CheckingStatementDriver::executeDefinition(
    DefinitionPtr* definitionPtr
) {
    Definition& definition = **definitionPtr;
    if (!definition)
        driver->showError(definition);
    return definition.isValid();
}

bool CheckingStatementDriver::executeQuery(
    QueryPtr* queryPtr
) {
    Query& query = **queryPtr;
    if (!query)
        driver->showError(query);
    return query.isValid();
}

DefinitionPtr* CheckingStatementDriver::createDefinition(
    InputLocation& inputLocation,
    IdentifierPtr* identifierPtr,
    ObjectPtr*     objectPtr
) {
    Identifier& identifier = **identifierPtr;
    Object&     object     = **objectPtr;

    if (!object) {
        Message errorMessage = Message() +
            "Count not define parameter '" + identifier + "': " + object.toString();
        return new DefinitionPtr(
            setupLocation<Definition>(
                ErrorFactory::getInstance().createDefinition(errorMessage),
                inputLocation
            )
        );
    }
    return new DefinitionPtr(NullFactory::getInstance().createDefinition());
}

QueryPtr* CheckingStatementDriver::createQuery(
    InputLocation&  inputLocation,
    IdentifiersPtr* identifiersPtr,
    ObjectsPtr*     objectsPtr,
    ConditionsPtr*  conditionsPtr
) {
    Identifiers& identifiers = **identifiersPtr;
    Objects&     objects     = **objectsPtr;
    Conditions&  conditions  = **conditionsPtr;
    
    for (ObjectPtr& objectPtr : objects) {
        Object& object = *objectPtr;

        if (!object)
            return new QueryPtr(
                setupLocation<Query>(
                    ErrorFactory::getInstance().createQuery(object.toString()),
                    inputLocation
                )
            );
        
        for (IdentifierPtr& propertyPtr : identifiers) {
            Identifier& property = *propertyPtr;

            if (!object.respondsTo(property)) {
                Message errorMessage = Message() +
                    "Object: " + object.toString() + '\n' +
                    "has no property: " + property;
                return new QueryPtr(
                    setupLocation<Query>(
                        ErrorFactory::getInstance().createQuery(errorMessage),
                        inputLocation
                    )
                );
            }
        }
    }

    for (ConditionPtr& conditionPtr : conditions) {
        Condition& condition = *conditionPtr;

        if (!condition) {
            Message errorMessage = Message() +
                "Condition is not valid: " + condition.toString();
            return new QueryPtr(
                setupLocation<Query>(
                    ErrorFactory::getInstance().createQuery(errorMessage),
                    inputLocation
                )
            );
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
