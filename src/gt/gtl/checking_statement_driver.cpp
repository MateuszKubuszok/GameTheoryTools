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
    const DefinitionPtr* definitionPtr
) {
    const Definition& definition = **definitionPtr;
    if (!definition)
        driver->showError(definition);
    return definition.isValid();
}

bool CheckingStatementDriver::executeQuery(
    const QueryPtr* queryPtr
) {
    const Query& query = **queryPtr;
    if (!query)
        driver->showError(query);
    return query.isValid();
}

DefinitionPtr* CheckingStatementDriver::createDefinition(
    const InputLocation& inputLocation,
    const IdentifierPtr* identifierPtr,
    const ObjectPtr*     objectPtr
) const {
    const Identifier& identifier = **identifierPtr;
    const Object&     object     = **objectPtr;

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
    const InputLocation&  inputLocation,
    const IdentifiersPtr* identifiersPtr,
    const ObjectsPtr*     objectsPtr,
    const ConditionsPtr*  conditionsPtr
) const {
    const Identifiers& identifiers = **identifiersPtr;
    const Objects&     objects     = **objectsPtr;
    const Conditions&  conditions  = **conditionsPtr;

    for (const ObjectPtr& objectPtr : objects) {
        const Object& object = *objectPtr;

        if (!object)
            return new QueryPtr(
                setupLocation<Query>(
                    ErrorFactory::getInstance().createQuery(object.toString()),
                    inputLocation
                )
            );

        for (const IdentifierPtr& propertyPtr : identifiers) {
            const Identifier& property = *propertyPtr;

            if (!object.respondsTo(property)) {
                const Param& param = object;

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

    for (const ConditionPtr& conditionPtr : conditions) {
        const Condition& condition = *conditionPtr;

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

Message CheckingStatementDriver::toString() const {
    return Message("CheckingStatementDriver");
}

// }; /* END class CheckingStatementDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
