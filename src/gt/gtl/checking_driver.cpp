#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class CheckingDriver {
// public:

CheckingDriver::CheckingDriver(
    std::ostream* newOutputStream
) :
    coordinate(this),
    condition(this),
    game(this),
    value(this),
    statement(this),
    outputStream(newOutputStream)
    {}

CoordinateDriver& CheckingDriver::forCoordinate() {
    return coordinate;
}

CollectionsDriver<Coordinate>& CheckingDriver::forCoordinates() {
    return coordinates;
}

ConditionDriver& CheckingDriver::forCondition() {
    return condition;
}

CollectionsDriver<Condition>& CheckingDriver::forConditions() {
    return conditions;
}

GameDriver& CheckingDriver::forGame() {
    return game;
}

CollectionsDriver<Identifier>& CheckingDriver::forIdentifiers() {
    return identifiers;
}

CollectionsDriver<Object>& CheckingDriver::forObjects() {
    return objects;
}

CollectionsDriver<Param>& CheckingDriver::forParams() {
    return params;
}

ValueDriver& CheckingDriver::forValue() {
    return value;
}

StatementDriver& CheckingDriver::forStatement() {
    return statement;
}

void CheckingDriver::showError(
    const Message& message
) {
    if (outputStream) {
        IdentifierPtr name   = createIdentifierPtr("Error");
        MessagePtr    result = createMessagePtr(message);
        (*outputStream) << ResultFactory::getInstance().buildResult()->addResult(name, result).build()->getResult();
    }
}

void CheckingDriver::showError(
    ValidableSymbol& symbol
) {
    showError(symbol.toString());
}

Message CheckingDriver::toString() {
    return Message("CheckingDriver");
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
