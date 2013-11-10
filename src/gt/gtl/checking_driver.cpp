#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class CheckingDriver : public Driver {
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
        std::stringstream builder;
        builder << message << std::endl
                << "\tat line \"" << location << "\"" << std::endl;
        std::string errorMessage(builder.str());

        IdentifierPtr name   = createIdentifierPtr("Error");
        MessagePtr    result = createMessagePtr(builder.str());

        (*errorStream)
            << ResultFactory::getInstance().buildResult()->addResult(name, result).build()->getResult();
    }
}

void CheckingDriver::showError(
    const ValidableSymbol& symbol
) const {
    showError(*symbol.getInputLocation(), symbol.toString());
}

Message CheckingDriver::toString() const {
    return Message("CheckingDriver");
}

// }; /* END class CheckingDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
