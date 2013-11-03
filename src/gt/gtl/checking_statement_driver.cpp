#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class CheckingStatementDriver : StatementDriver {
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
        // TODO: create ErrorMessageFactory
        Message errorMessage = Message() +
            "Count not define parameter '" + identifier + "': " + object.toString();
        return new DefinitionPtr(
            setupLocation<Definition>(
                ErrorFactory::getInstance().createDefinition(errorMessage),
                inputLocation
            )
        );
    }

    return new DefinitionPtr(
        setupLocation<Definition>(
            NullFactory::getInstance().createDefinition(),
            inputLocation
        )
    );
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
                Param& param = object;

                if (!param) {
                    // TODO: create ErrorMessageFactory
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
    }

    for (ConditionPtr& conditionPtr : conditions) {
        Condition& condition = *conditionPtr;

        if (!condition) {
            // TODO: create ErrorMessageFactory
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

    return new QueryPtr(
        setupLocation<Query>(
            NullFactory::getInstance().createQuery(),
            inputLocation
        )
    );
}

Message CheckingStatementDriver::toString() {
    return Message("CheckingStatementDriver");
}

// }; /* END class CheckingStatementDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
