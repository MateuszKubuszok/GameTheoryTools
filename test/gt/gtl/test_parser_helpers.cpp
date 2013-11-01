#include "gt/gtl/test_common.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class TestConditionDriverImpl : public GT::GTL::NullConditionDriver {
// public:

TestConditionDriverImpl::TestConditionDriverImpl() :
    GT::GTL::NullConditionDriver(),
    createdConditions(0)
    {}

GT::GTL::ConditionPtr* TestConditionDriverImpl::playerChoosed(
    GT::GTL::InputLocation& inputLocation,
    GT::GTL::ObjectPtr*     player,
    GT::GTL::ObjectPtr*     strategy
) {
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
    GT::GTL::InputLocation&  inputLocation,
    const GT::IdentifierPtr* player,
    const GT::IdentifierPtr* strategy
) {
    createdCoordinates++;
    return GT::GTL::NullCoordinateDriver::create(inputLocation, player, strategy);
}

GT::GTL::CoordinatePtr* TestCoordinateDriverImpl::fillWithData(
    GT::GTL::InputLocation&       inputLocation,
    const GT::GTL::CoordinatePtr* coordinate,
    const GT::GTL::ParamsPtr*     data
) {
    filledCoordinates++;
    return GT::GTL::NullCoordinateDriver::fillWithData(inputLocation, coordinate, data);
}

GT::GTL::CoordinatePtr* TestCoordinateDriverImpl::merge(
    GT::GTL::InputLocation&       inputLocation,
    const GT::GTL::CoordinatePtr* coordinate1,
    const GT::GTL::CoordinatePtr* coordinate2
) {
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
    GT::GTL::InputLocation& inputLocation,
    GT::GTL::DetailsPtr*    details
) {
    createdStrategicGames++;
    return GT::GTL::NullGameDriver::createStrategic(inputLocation, details);
}

GT::GTL::GamePtr* TestGameDriverImpl::createExtensive(
    GT::GTL::InputLocation& inputLocation,
    GT::GTL::DetailsPtr*    details
) {
    createdExtensiveGames++;
    return GT::GTL::NullGameDriver::createExtensive(inputLocation, details);
}

GT::GTL::DetailsPtr* TestGameDriverImpl::createDetails(
    GT::GTL::InputLocation&  inputLocation,
    GT::GTL::ObjectsPtr*     players,
    GT::GTL::CoordinatesPtr* data
) {
    createdDetails++;
    return GT::GTL::NullGameDriver::createDetails(inputLocation, players, data);
}

GT::GTL::PlayerPtr* TestGameDriverImpl::createPlayer(
    GT::GTL::InputLocation& inputLocation,
    GT::IdentifierPtr*      player,
    GT::IdentifiersPtr*     strategies
) {
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

// }; /* END class TestStatementDriverImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class TestValueDriverImpl : public GT::GTL::NullValueDriver {
// public:

TestValueDriverImpl::TestValueDriverImpl() :
    GT::GTL::NullValueDriver(),
    usedParameters(0)
    {}

GT::GTL::ParamPtr* TestValueDriverImpl::get(
    GT::GTL::InputLocation& inputLocation,
    GT::IdentifierPtr*      identifier
) {
    usedParameters++;
    return GT::GTL::NullValueDriver::get(inputLocation, identifier);
}

GT::GTL::ParamPtr* TestValueDriverImpl::get(
    GT::GTL::InputLocation& inputLocation,
    GT::NumberPtr*          number
) {
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

void TestDriverImpl::showResult(
    GT::GTL::ResultPtr
) {
    shownResults++;
}

void TestDriverImpl::showError(
    GT::GTL::InputLocation&,
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

// }; /* END class TestDriverImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
