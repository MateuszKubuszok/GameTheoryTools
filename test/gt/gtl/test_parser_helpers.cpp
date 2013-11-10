#include "gt/gtl/test_common.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class TestConditionDriverImpl : public GT::GTL::NullConditionDriver {
// public:

TestConditionDriverImpl::TestConditionDriverImpl() :
    GT::GTL::NullConditionDriver(),
    createdConditions(0)
    {}

GT::GTL::ConditionPtr* TestConditionDriverImpl::playerChoosed(
    const GT::GTL::InputLocation& inputLocation,
    const GT::GTL::ObjectPtr*     player,
    const GT::GTL::ObjectPtr*     strategy
) const {
    createdConditions++;
    return GT::GTL::NullConditionDriver::playerChoosed(inputLocation, player, strategy);
}

// }; /* END class TestConditionDriverImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class TestCoordinateDriverImpl : public GT::GTL::NullCoordinateDriver {
// public:

TestCoordinateDriverImpl::TestCoordinateDriverImpl() :
    GT::GTL::NullCoordinateDriver(),
    createdCoordinates(0),
    filledCoordinates(0),
    mergedCoordinates(0)
    {}

GT::GTL::CoordinatePtr* TestCoordinateDriverImpl::create(
    const GT::GTL::InputLocation& inputLocation,
    const GT::IdentifierPtr*      player,
    const GT::IdentifierPtr*      strategy
) const {
    createdCoordinates++;
    return GT::GTL::NullCoordinateDriver::create(inputLocation, player, strategy);
}

GT::GTL::CoordinatePtr* TestCoordinateDriverImpl::fillWithData(
    const GT::GTL::InputLocation& inputLocation,
    const GT::GTL::CoordinatePtr* coordinate,
    const GT::GTL::ParamsPtr*     data
) const {
    filledCoordinates++;
    return GT::GTL::NullCoordinateDriver::fillWithData(inputLocation, coordinate, data);
}

GT::GTL::CoordinatePtr* TestCoordinateDriverImpl::merge(
    const GT::GTL::InputLocation& inputLocation,
    const GT::GTL::CoordinatePtr* coordinate1,
    const GT::GTL::CoordinatePtr* coordinate2
) const {
    mergedCoordinates++;
    return GT::GTL::NullCoordinateDriver::merge(inputLocation, coordinate1, coordinate2);
}

// }; /* END class TestCoordinateDriverImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class TestGameDriverImpl : public GT::GTL::NullGameDriver {
// public:

TestGameDriverImpl::TestGameDriverImpl() :
    GT::GTL::NullGameDriver(),
    createdStrategicGames(0),
    createdExtensiveGames(0),
    createdDetails(0),
    createdPlayers(0)
    {}

GT::GTL::GamePtr* TestGameDriverImpl::createStrategic(
    const GT::GTL::InputLocation& inputLocation,
    const GT::GTL::DetailsPtr*    details
) const {
    createdStrategicGames++;
    return GT::GTL::NullGameDriver::createStrategic(inputLocation, details);
}

GT::GTL::GamePtr* TestGameDriverImpl::createExtensive(
    const GT::GTL::InputLocation& inputLocation,
    const GT::GTL::DetailsPtr*    details
) const {
    createdExtensiveGames++;
    return GT::GTL::NullGameDriver::createExtensive(inputLocation, details);
}

GT::GTL::DetailsPtr* TestGameDriverImpl::createDetails(
    const GT::GTL::InputLocation&  inputLocation,
    const GT::GTL::ObjectsPtr*     players,
    const GT::GTL::CoordinatesPtr* data
) const {
    createdDetails++;
    return GT::GTL::NullGameDriver::createDetails(inputLocation, players, data);
}

GT::GTL::PlayerPtr* TestGameDriverImpl::createPlayer(
    const GT::GTL::InputLocation& inputLocation,
    const GT::IdentifierPtr*      player,
    const GT::IdentifiersPtr*     strategies
) const {
    createdPlayers++;
    return GT::GTL::NullGameDriver::createPlayer(inputLocation, player, strategies);
}

// }; /* END class TestGameDriverImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class TestStatementDriverImpl : public GT::GTL::NullStatementDriver {
// public:

TestStatementDriverImpl::TestStatementDriverImpl() :
    GT::GTL::NullStatementDriver(),
    executedDefinitions(0),
    executedQueries(0)
    {}

bool TestStatementDriverImpl::executeDefinition(
    const GT::GTL::DefinitionPtr*
) {
    executedDefinitions++;
    return true;
}

bool TestStatementDriverImpl::executeQuery(
    const GT::GTL::QueryPtr*
) {
    executedQueries++;
    return true;
}

// }; /* END class TestStatementDriverImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class TestValueDriverImpl : public GT::GTL::NullValueDriver {
// public:

TestValueDriverImpl::TestValueDriverImpl() :
    GT::GTL::NullValueDriver(),
    usedParameters(0)
    {}

GT::GTL::ParamPtr* TestValueDriverImpl::get(
    const GT::GTL::InputLocation& inputLocation,
    const GT::IdentifierPtr*      identifier
) const {
    usedParameters++;
    return GT::GTL::NullValueDriver::get(inputLocation, identifier);
}

GT::GTL::ParamPtr* TestValueDriverImpl::get(
    const GT::GTL::InputLocation& inputLocation,
    const GT::NumberPtr*          number
) const {
    usedParameters++;
    return GT::GTL::NullValueDriver::get(inputLocation, number);
}

// }; /* END class TestValueDriverImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class TestDriverImpl : public GT::GTL::Driver {
// public:

TestDriverImpl::TestDriverImpl() :
    shownResults(0),
    shownErrors(0)
    {}

GT::GTL::CoordinateDriver& TestDriverImpl::forCoordinate() const {
    return coordinate;
}

GT::GTL::CollectionsDriver<GT::GTL::Coordinate>& TestDriverImpl::forCoordinates() const {
    return coordinates;
}

GT::GTL::ConditionDriver& TestDriverImpl::forCondition() const {
    return condition;
}

GT::GTL::CollectionsDriver<GT::GTL::Condition>& TestDriverImpl::forConditions() const {
    return conditions;
}

GT::GTL::GameDriver& TestDriverImpl::forGame() const {
    return game;
}

GT::GTL::CollectionsDriver<GT::Identifier>& TestDriverImpl::forIdentifiers() const {
    return identifiers;
}

GT::GTL::CollectionsDriver<GT::GTL::Object>& TestDriverImpl::forObjects() const {
    return objects;
}

GT::GTL::CollectionsDriver<GT::GTL::Param>& TestDriverImpl::forParams() const {
    return params;
}

GT::GTL::ValueDriver& TestDriverImpl::forValue() const {
    return value;
}

GT::GTL::StatementDriver& TestDriverImpl::forStatement() const {
    return statement;
}

void TestDriverImpl::showResult(
    const GT::GTL::ResultPtr
) const {
    shownResults++;
}

void TestDriverImpl::showError(
    const GT::GTL::InputLocation&,
    const GT::Message&
) const {
    shownErrors++;
}

void TestDriverImpl::showError(
    const GT::GTL::ValidableSymbol&
) const {
    shownErrors++;
}

GT::Message TestDriverImpl::toString() const {
    return GT::Message("TestDriverImpl");
}

// }; /* END class TestDriverImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
