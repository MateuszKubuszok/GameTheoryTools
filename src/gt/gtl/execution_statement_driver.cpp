/**
 * @file      gt/gtl/execution_statement_driver.cpp
 * @brief     Defines GT::GTL::ExecutionStatementDriver methods.
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

using std::exception;

using boost::make_shared;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExecutionStatementDriver final : public StatementDriver {
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

    static IdentifierPtr name   = createIdentifierPtr("Result");
    static MessagePtr    value  = createIdentifierPtr("Param defined successfully");
    ResultPtr            result = ResultFactory::getInstance().buildResult()->addResult(name, value).build();
    driver->showResult(result);

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
    } catch (const exception& e) {
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
            make_shared<Definition>(identifier, ParamFactory::getInstance().createParam(object)),
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
            make_shared<Query>(identifiers, objects, conditions),
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
