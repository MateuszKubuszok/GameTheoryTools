/**
 * @file      gt/gtl/checking_driver.cpp
 * @brief     Defines GT::GTL::CheckingDriver methods.
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

using std::endl;
using std::ifstream;
using std::string;
using std::stringstream;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class CheckingDriver final : public Driver {
// public:

CheckingDriver::CheckingDriver(
    std::ostream* newErrorStream
) :
    coordinate(this),
    condition(this),
    game(this),
    value(this),
    statement(this),
    errorStream(newErrorStream)
    {}

CheckingDriver::~CheckingDriver() {}

CoordinateDriver& CheckingDriver::forCoordinate() const {
    return coordinate;
}

CollectionsDriver<Coordinate>& CheckingDriver::forCoordinates() const {
    return coordinates;
}

ConditionDriver& CheckingDriver::forCondition() const {
    return condition;
}

CollectionsDriver<Condition>& CheckingDriver::forConditions() const {
    return conditions;
}

GameDriver& CheckingDriver::forGame() const {
    return game;
}

CollectionsDriver<Identifier>& CheckingDriver::forIdentifiers() const {
    return identifiers;
}

CollectionsDriver<Object>& CheckingDriver::forObjects() const {
    return objects;
}

CollectionsDriver<Param>& CheckingDriver::forParams() const {
    return params;
}

ValueDriver& CheckingDriver::forValue() const {
    return value;
}

StatementDriver& CheckingDriver::forStatement() const {
    return statement;
}

void CheckingDriver::showResult(
    const ResultPtr
) const {}

void CheckingDriver::showError(
    const InputLocation& location,
    const Message&       message
) const {
    if (errorStream) {
        stringstream builder;
        builder << message << endl
                << "\tfrom line " << location.begin.line << " (column " << location.begin.column << ')'
                << endl
                << "\tto line " << location.end.line << " (column " << location.end.column << ')'
                << endl;
        string errorMessage(builder.str());

        static const IdentifierPtr name   = createIdentifierPtr("Error");
        const MessagePtr           result = createMessagePtr(builder.str());

        (*errorStream)
            << ResultFactory::getInstance().buildResult()->addResult(name, result).build()->getResult();
    }
}

void CheckingDriver::showError(
    const ValidableSymbol& symbol
) const {
    showError(*symbol.getInputLocation(), symbol.toString());
}

void CheckingDriver::execute(
    const InputLocation& location,
    const Identifier&    fileName
) const {
    if (!fileExists(fileName)) {
        stringstream builder;
        builder << "Executed file <" << fileName << "> does not exists";
        string errorMessage(builder.str());

        showError(location, errorMessage);
    }
}

void CheckingDriver::load(
    const InputLocation& location,
    const Identifier&    fileName
) {
    if (!fileExists(fileName)) {
        stringstream builder;
        builder << "Loaded file <" << fileName << "> does not exists";
        string errorMessage(builder.str());

        showError(location, errorMessage);
    }
}

void CheckingDriver::save(
    const InputLocation&,
    const Identifier&
) const {}

Message CheckingDriver::toString() const {
    return Message("CheckingDriver");
}

// private:

bool CheckingDriver::fileExists(
    const Identifier& fileName
) const {
    ifstream f(fileName);
    return f.good();
}

// }; /* END class CheckingDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
