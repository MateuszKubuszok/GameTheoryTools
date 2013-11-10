#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExecutionDriver : public Driver {
// public:

ExecutionDriver::ExecutionDriver(
    std::ostream* newOutputStream,
    std::ostream* newErrorStream
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
