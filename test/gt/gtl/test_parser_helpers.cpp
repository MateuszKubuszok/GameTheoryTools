#include "gt/gtl/test_common.hpp"

////////////////////////////////////////////////////////////////////////////////

// class TestConditionDriverImpl {
// public:

TestConditionDriverImpl::TestConditionDriverImpl() :
    GT::GTL::NullConditionDriver(),
    createdConditions(0)
    {}

GT::GTL::ConditionPtr* TestConditionDriverImpl::playerChoosed(
    GT::GTL::ObjectPtr* player,
    GT::GTL::ObjectPtr* strategy
) {
    createdConditions++;
    return GT::GTL::NullConditionDriver::playerChoosed(player, strategy);
}

// }

////////////////////////////////////////////////////////////////////////////////

// class TestCoordinateDriverImpl {
// public:

TestCoordinateDriverImpl::TestCoordinateDriverImpl() :
    GT::GTL::NullCoordinateDriver(),
    createdCoordinates(0),
    filledCoordinates(0),
    mergedCoordinates(0)
    {}

GT::GTL::CoordinatePtr* TestCoordinateDriverImpl::create(
    const GT::IdentifierPtr* player,
    const GT::IdentifierPtr* strategy
) {
    createdCoordinates++;
    return GT::GTL::NullCoordinateDriver::create(player, strategy);
}

GT::GTL::CoordinatePtr* TestCoordinateDriverImpl::fillWithData(
    const GT::GTL::CoordinatePtr* coordinate,
    const GT::GTL::ParamsPtr*     data
) {
    filledCoordinates++;
    return GT::GTL::NullCoordinateDriver::fillWithData(coordinate, data);
}

GT::GTL::CoordinatePtr* TestCoordinateDriverImpl::merge(
    const GT::GTL::CoordinatePtr* coordinate1,
    const GT::GTL::CoordinatePtr* coordinate2
) {
    mergedCoordinates++;
    return GT::GTL::NullCoordinateDriver::merge(coordinate1, coordinate2);
}

// }

////////////////////////////////////////////////////////////////////////////////

// class TestGameDriverImpl {
// public:

TestGameDriverImpl::TestGameDriverImpl() :
    GT::GTL::NullGameDriver(),
    createdStrategicGames(0),
    createdTreeGames(0),
    createdDetails(0),
    createdPlayers(0)
    {}

GT::GTL::GamePtr* TestGameDriverImpl::createStrategic(
    GT::GTL::DetailsPtr* details
) {
    createdStrategicGames++;
    return GT::GTL::NullGameDriver::createStrategic(details);
}

GT::GTL::GamePtr* TestGameDriverImpl::createTree(
    GT::GTL::DetailsPtr* details
) {
    createdTreeGames++;
    return GT::GTL::NullGameDriver::createTree(details);
}

GT::GTL::DetailsPtr* TestGameDriverImpl::createDetails(
    GT::GTL::ObjectsPtr*     players,
    GT::GTL::CoordinatesPtr* data
) {
    createdDetails++;
    return GT::GTL::NullGameDriver::createDetails(players, data);
}

GT::GTL::PlayerPtr* TestGameDriverImpl::createPlayer(
    GT::IdentifierPtr*  player,
    GT::IdentifiersPtr* strategies
) {
    createdPlayers++;
    return GT::GTL::NullGameDriver::createPlayer(player, strategies);
}

// }

////////////////////////////////////////////////////////////////////////////////

// class TestStatementDriverImpl {
// public:

TestStatementDriverImpl::TestStatementDriverImpl() :
    GT::GTL::NullStatementDriver(),
    executedDefinitions(0),
    executedQueries(0)
    {}

bool TestStatementDriverImpl::executeDefinition(
    GT::GTL::DefinitionPtr*
) {
    executedDefinitions++;
    return true;
}

bool TestStatementDriverImpl::executeQuery(
    GT::GTL::QueryPtr*
) {
    executedQueries++;
    return true;
}

// }

////////////////////////////////////////////////////////////////////////////////

// class TestValueDriverImpl {
// public:

TestValueDriverImpl::TestValueDriverImpl() :
    GT::GTL::NullValueDriver(),
    usedParameters(0)
    {}

GT::GTL::ParamPtr* TestValueDriverImpl::get(
    GT::IdentifierPtr* identifier
) {
    usedParameters++;
    return GT::GTL::NullValueDriver::get(identifier);
}

GT::GTL::ParamPtr* TestValueDriverImpl::get(
    GT::NumberPtr* number
) {
    usedParameters++;
    return GT::GTL::NullValueDriver::get(number);
}

// }

////////////////////////////////////////////////////////////////////////////////

// class TestDriverImpl {
// public:

TestDriverImpl::TestDriverImpl() :
    shownErrors(0)
    {}

GT::GTL::CoordinateDriver& TestDriverImpl::forCoordinate() {
    return coordinate;
}

GT::GTL::CollectionsDriver<GT::GTL::Coordinate>& TestDriverImpl::forCoordinates() {
    return coordinates;
}

GT::GTL::ConditionDriver& TestDriverImpl::forCondition() {
    return condition;
}

GT::GTL::CollectionsDriver<GT::GTL::Condition>& TestDriverImpl::forConditions() {
    return conditions;
}

GT::GTL::GameDriver& TestDriverImpl::forGame() {
    return game;
}

GT::GTL::CollectionsDriver<GT::Identifier>& TestDriverImpl::forIdentifiers() {
    return identifiers;
}

GT::GTL::CollectionsDriver<GT::GTL::Object>& TestDriverImpl::forObjects() {
    return objects;
}

GT::GTL::CollectionsDriver<GT::GTL::Param>& TestDriverImpl::forParams() {
    return params;
}

GT::GTL::ValueDriver& TestDriverImpl::forValue() {
    return value;
}

GT::GTL::StatementDriver& TestDriverImpl::forStatement() {
    return statement;
}

void TestDriverImpl::showError(
    const GT::Message&
) {
    shownErrors++;
}

void TestDriverImpl::showError(
    GT::GTL::ValidableSymbol&
) {
    shownErrors++;
}

GT::Message TestDriverImpl::toString() {
    return GT::Message("TestDriverImpl");
}

// }

////////////////////////////////////////////////////////////////////////////////
