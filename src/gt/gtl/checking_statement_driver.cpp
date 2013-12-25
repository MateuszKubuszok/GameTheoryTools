/**
 * @file      gt/gtl/checking_statement_driver.cpp
 * @brief     Defines GT::GTL::CheckingStatementDriver methods.
 * @copyright (C) 2013-2014
 * @author    Mateusz Kubuszok
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero
 * General Public License as published by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License along with this program. If not,
 * see [http://www.gnu.org/licenses/].
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class CheckingStatementDriver final : StatementDriver {
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
        // TODO: create MessageFactory
        Message errorMessage = Message() +
            "Count not define parameter '" + identifier + "': " + object.toString();
        return new DefinitionPtr(
            setupLocation<Definition>(
                ErrorFactory::getInstance().createDefinition(errorMessage),
                *object.getInputLocation()
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
                    *object.getInputLocation()
                )
            );

        for (const IdentifierPtr& propertyPtr : identifiers) {
            const Identifier& property = *propertyPtr;

            if (!object.respondsTo(property)) {
                const Param& param = object;

                if (!param) {
                    // TODO: create MessageFactory
                    Message errorMessage = Message() +
                        "Object: " + object.toString() + '\n' +
                        "has no property: " + property;
                    return new QueryPtr(
                        setupLocation<Query>(
                            ErrorFactory::getInstance().createQuery(errorMessage),
                            *param.getInputLocation()
                        )
                    );
                }
            }
        }
    }

    for (const ConditionPtr& conditionPtr : conditions) {
        const Condition& condition = *conditionPtr;

        if (!condition) {
            // TODO: create MessageFactory
            Message errorMessage = Message() +
                "Condition is not valid: " + condition.toString();
            return new QueryPtr(
                setupLocation<Query>(
                    ErrorFactory::getInstance().createQuery(errorMessage),
                    *condition.getInputLocation()
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
