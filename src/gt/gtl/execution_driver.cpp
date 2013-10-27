#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class ExecutionDriver {
// public:

ExecutionDriver::ExecutionDriver(
    std::ostream* newOutputStream
) :
    checkingDriver(newOutputStream),
    context(new Context()),
    coordinate(this),
    condition(this),
    game(this),
    value(this),
    statement(this)
    {}

CoordinateDriver& ExecutionDriver::forCoordinate() {
    return coordinate;
}

CollectionsDriver<Coordinate>& ExecutionDriver::forCoordinates() {
    return coordinates;
}

ConditionDriver& ExecutionDriver::forCondition() {
    return condition;
}

CollectionsDriver<Condition>& ExecutionDriver::forConditions() {
    return conditions;
}

GameDriver& ExecutionDriver::forGame() {
    return game;
}

CollectionsDriver<Identifier>& ExecutionDriver::forIdentifiers() {
    return identifiers;
}

CollectionsDriver<Object>& ExecutionDriver::forObjects() {
    return objects;
}

CollectionsDriver<Param>& ExecutionDriver::forParams() {
    return params;
}

ValueDriver& ExecutionDriver::forValue() {
    return value;
}

StatementDriver& ExecutionDriver::forStatement() {
    return statement;
}

void ExecutionDriver::showError(
    InputLocation& location,
    const Message& message
) {
    checkingDriver.showError(location, message);
}

void ExecutionDriver::showError(
    ValidableSymbol& symbol
) {
    checkingDriver.showError(symbol);
}

Message ExecutionDriver::toString() {
    return Message("ExecutionDriver");
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
