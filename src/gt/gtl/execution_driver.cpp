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

// class ExecutionDriver final : public Driver {
// public:

ExecutionDriver::ExecutionDriver(
    OutputStream* newOutputStream,
    OutputStream* newErrorStream
) :
    checkingDriver(newErrorStream),
    context(new Context()),
    coordinate(this),
    condition(this),
    game(this, context.get()),
    value(this),
    statement(this, context.get()),
    outputStream(newOutputStream)
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

Message ExecutionDriver::toString() const {
    return Message("ExecutionDriver");
}

// }; /* END class ExecutionDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
