/**
 * @file      gt/gtl/execution_driver.cpp
 * @brief     Defines GT::GTL::ExecutionDriver methods.
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

using std::ifstream;
using std::ofstream;
using std::stringstream;

using boost::scoped_ptr;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExecutionDriver final : public Driver {
// public:

ExecutionDriver::ExecutionDriver(
    OutputStream* newOutputStream,
    OutputStream* newErrorStream
) :
    checkingDriver(newErrorStream),
    context(new Context()),
    coordinate(),
    condition(),
    game(context.get()),
    value(),
    statement(this, context.get()),
    outputStream(newOutputStream),
    errorStream(newErrorStream)
    {}

ExecutionDriver::~ExecutionDriver() {}

CoordinateDriver& ExecutionDriver::forCoordinate() const {
    return coordinate;
}

CollectionsDriver<Coordinate>& ExecutionDriver::forCoordinates() const {
    return coordinates;
}

ConditionDriver& ExecutionDriver::forCondition() const {
    return condition;
}

CollectionsDriver<Condition>& ExecutionDriver::forConditions() const {
    return conditions;
}

GameDriver& ExecutionDriver::forGame() const {
    return game;
}

CollectionsDriver<Identifier>& ExecutionDriver::forIdentifiers() const {
    return identifiers;
}

CollectionsDriver<Object>& ExecutionDriver::forObjects() const {
    return objects;
}

CollectionsDriver<Param>& ExecutionDriver::forParams() const {
    return params;
}

ValueDriver& ExecutionDriver::forValue() const {
    return value;
}

StatementDriver& ExecutionDriver::forStatement() const {
    return statement;
}

void ExecutionDriver::showResult(
    const ResultPtr result
) const {
    if (outputStream)
        (*outputStream) << result->getResult();
}

void ExecutionDriver::showError(
    const InputLocation& location,
    const Message&       message
) const {
    checkingDriver.showError(location, message);
}

void ExecutionDriver::showError(
    const ValidableSymbol& symbol
) const {
    checkingDriver.showError(symbol);
}

void ExecutionDriver::execute(
    const InputLocation& location,
    const Identifier&    fileName
) const {
    scoped_ptr<ifstream> file(new ifstream(fileName));
    if (!file->good()) {
        stringstream builder;
        builder << "Executed file <" << fileName << "> does not exists";
        string errorMessage(builder.str());

        showError(location, errorMessage);
        return;
    }

    ExecutionDriver driver(outputStream, errorStream, context);
    Scanner         scanner(file.get());
    Parser          parser(scanner, driver);

    bool      success = parser.parse() == 0;
    ResultPtr result;
    if (success) {
        static IdentifierPtr name  = createIdentifierPtr("Result");
        static MessagePtr    value = createIdentifierPtr("File executed without errors");
        result = ResultFactory::getInstance().buildResult()->addResult(name, value).build();
    } else {
        static IdentifierPtr name  = createIdentifierPtr("Result");
        static MessagePtr    value = createIdentifierPtr("There were errors during execution of this file");
        result = ResultFactory::getInstance().buildResult()->addResult(name, value).build();
    }
    showResult(result);
}

void ExecutionDriver::load(
    const InputLocation& location,
    const Identifier&    fileName
) {
    scoped_ptr<ifstream> file(new ifstream(fileName));
    if (!file->good()) {
        stringstream builder;
        builder << "Loaded file <" << fileName << "> does not exists";
        string errorMessage(builder.str());

        showError(location, errorMessage);
        return;
    }

    Scanner scanner(file.get());
    Parser  parser(scanner, *this);

    bool      success = parser.parse() == 0;
    ResultPtr result;
    if (success) {
        static IdentifierPtr name  = createIdentifierPtr("Result");
        static MessagePtr    value = createIdentifierPtr("File loaded without errors");
        result = ResultFactory::getInstance().buildResult()->addResult(name, value).build();
    } else {
        static IdentifierPtr name  = createIdentifierPtr("Result");
        static MessagePtr    value = createIdentifierPtr("There were errors during loading of this file");
        result = ResultFactory::getInstance().buildResult()->addResult(name, value).build();
    }
    showResult(result);
}

void ExecutionDriver::save(
    const InputLocation& location,
    const Identifier&    fileName
) const {
    ofstream file(fileName);
    if (!file.good()) {
        stringstream builder;
        builder << "Cannot save to file <" << fileName << ">";
        string errorMessage(builder.str());

        showError(location, errorMessage);
        return;
    }

    file << context->serialize();

    bool      success = !file.fail();
    ResultPtr result;
    if (success) {
        static IdentifierPtr name  = createIdentifierPtr("Result");
        static MessagePtr    value = createIdentifierPtr("Context saved without errors");
        result = ResultFactory::getInstance().buildResult()->addResult(name, value).build();
    } else {
        static IdentifierPtr name  = createIdentifierPtr("Result");
        static MessagePtr    value = createIdentifierPtr("There were errors during saving of this context");
        result = ResultFactory::getInstance().buildResult()->addResult(name, value).build();
    }
    showResult(result);
}

Message ExecutionDriver::toString() const {
    return Message("ExecutionDriver");
}

// private:

ExecutionDriver::ExecutionDriver(
    OutputStream* newOutputStream,
    OutputStream* newErrorStream,
    ContextPtr    parentContext
) :
    checkingDriver(newErrorStream),
    context(new Context(parentContext)),
    coordinate(),
    condition(),
    game(context.get()),
    value(),
    statement(this, context.get()),
    outputStream(newOutputStream)
    {}

// }; /* END class ExecutionDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
