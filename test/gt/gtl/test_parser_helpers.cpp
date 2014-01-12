#include "gt/gtl/test_common.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class TestConditionDriverImpl final : public GT::GTL::ConditionDriver {
// public:

TestConditionDriverImpl::TestConditionDriverImpl() :
    GT::GTL::ConditionDriver(),
    createdConditions(0)
    {}

GT::GTL::ConditionPtr* TestConditionDriverImpl::informationSetChoosed(
    const GT::GTL::InputLocation& inputLocation,
    const GT::GTL::ObjectPtr*,
    const GT::GTL::ObjectPtr*,
    const GT::GTL::ObjectPtr*
) const {
    createdConditions++;
    return new GT::GTL::ConditionPtr(
        GT::GTL::setupLocation<GT::GTL::Condition>(
            GT::GTL::NullFactory::getInstance().createCondition(),
            inputLocation
        )
    );
}

GT::GTL::ConditionPtr* TestConditionDriverImpl::informationSetWithin(
    const GT::GTL::InputLocation& inputLocation,
    const GT::GTL::ObjectPtr*,
    const GT::GTL::ObjectPtr*,
    const GT::GTL::ObjectsPtr*
) const {
    createdConditions++;
    return new GT::GTL::ConditionPtr(
        GT::GTL::setupLocation<GT::GTL::Condition>(
            GT::GTL::NullFactory::getInstance().createCondition(),
            inputLocation
        )
    );
}

GT::GTL::ConditionPtr* TestConditionDriverImpl::playerChoosed(
    const GT::GTL::InputLocation& inputLocation,
    const GT::GTL::ObjectPtr*,
    const GT::GTL::ObjectPtr*
) const {
    createdConditions++;
    return new GT::GTL::ConditionPtr(
        GT::GTL::setupLocation<GT::GTL::Condition>(
            GT::GTL::NullFactory::getInstance().createCondition(),
            inputLocation
        )
    );
}

GT::GTL::ConditionPtr* TestConditionDriverImpl::playerWithin(
    const GT::GTL::InputLocation& inputLocation,
    const GT::GTL::ObjectPtr*,
    const GT::GTL::ObjectsPtr*
) const {
    createdConditions++;
    return new GT::GTL::ConditionPtr(
        GT::GTL::setupLocation<GT::GTL::Condition>(
            GT::GTL::NullFactory::getInstance().createCondition(),
            inputLocation
        )
    );
}

GT::Message TestConditionDriverImpl::toString() const {
    return GT::Message("TestCollectionsDriverImpl");
}

// }; /* END class TestConditionDriverImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class TestCoordinateDriverImpl final : public GT::GTL::CoordinateDriver {
// public:

TestCoordinateDriverImpl::TestCoordinateDriverImpl() :
    GT::GTL::CoordinateDriver(),
    createdCoordinates(0),
    filledCoordinates(0),
    mergedCoordinates(0)
    {}

GT::GTL::CoordinatePtr* TestCoordinateDriverImpl::create(
    const GT::GTL::InputLocation& inputLocation,
    const GT::IdentifierPtr*,
    const GT::IdentifierPtr*
) const {
    createdCoordinates++;
    return new GT::GTL::CoordinatePtr(
        GT::GTL::setupLocation<GT::GTL::Coordinate>(
            GT::GTL::NullFactory::getInstance().createCoordinate(),
            inputLocation
        )
    );
}

GT::GTL::CoordinatePtr* TestCoordinateDriverImpl::fillWithData(
    const GT::GTL::InputLocation& inputLocation,
    const GT::GTL::CoordinatePtr*,
    const GT::GTL::CoordinatesPtr*
) const {
    filledCoordinates++;
    return new GT::GTL::CoordinatePtr(
        GT::GTL::setupLocation<GT::GTL::Coordinate>(
            GT::GTL::NullFactory::getInstance().createCoordinate(),
            inputLocation
        )
    );
}

GT::GTL::CoordinatePtr* TestCoordinateDriverImpl::fillWithData(
    const GT::GTL::InputLocation& inputLocation,
    const GT::GTL::CoordinatePtr*,
    const GT::GTL::ParamsPtr*
) const {
    filledCoordinates++;
    return new GT::GTL::CoordinatePtr(
        GT::GTL::setupLocation<GT::GTL::Coordinate>(
            GT::GTL::NullFactory::getInstance().createCoordinate(),
            inputLocation
        )
    );
}

GT::GTL::CoordinatePtr* TestCoordinateDriverImpl::merge(
    const GT::GTL::InputLocation& inputLocation,
    const GT::GTL::CoordinatePtr*,
    const GT::GTL::CoordinatePtr*
) const {
    mergedCoordinates++;
    return new GT::GTL::CoordinatePtr(
        GT::GTL::setupLocation<GT::GTL::Coordinate>(
            GT::GTL::NullFactory::getInstance().createCoordinate(),
            inputLocation
        )
    );
}

GT::Message TestCoordinateDriverImpl::toString() const {
    return GT::Message("TestCoordinateDriverImpl");
}

// }; /* END class TestCoordinateDriverImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class TestGameDriverImpl final : public GT::GTL::GameDriver {
// public:

TestGameDriverImpl::TestGameDriverImpl() :
    GT::GTL::GameDriver(),
    createdStrategicGames(0),
    createdExtensiveGames(0),
    createdDetails(0),
    createdPlayers(0)
    {}

GT::GTL::GamePtr* TestGameDriverImpl::createStrategic(
    const GT::GTL::InputLocation& inputLocation,
    const GT::GTL::DetailsPtr*
) const {
    createdStrategicGames++;
    return new GT::GTL::GamePtr(
        GT::GTL::setupLocation<GT::GTL::Game>(
            GT::GTL::NullFactory::getInstance().createGame(),
            inputLocation
        )
    );
}

GT::GTL::GamePtr* TestGameDriverImpl::createExtensive(
    const GT::GTL::InputLocation& inputLocation,
    const GT::GTL::DetailsPtr*
) const {
    createdExtensiveGames++;
    return new GT::GTL::GamePtr(
        GT::GTL::setupLocation<GT::GTL::Game>(
            GT::GTL::NullFactory::getInstance().createGame(),
            inputLocation
        )
    );
}

GT::GTL::DetailsPtr* TestGameDriverImpl::createDetails(
    const GT::GTL::InputLocation& inputLocation,
    const GT::GTL::ObjectsPtr*,
    const GT::GTL::CoordinatesPtr*
) const {
    createdDetails++;
    return new GT::GTL::DetailsPtr(
        GT::GTL::setupLocation<GT::GTL::Details>(
            GT::GTL::NullFactory::getInstance().createDetails(),
            inputLocation
        )
    );
}

GT::GTL::PlayerPtr* TestGameDriverImpl::createPlayer(
    const GT::GTL::InputLocation& inputLocation,
    const GT::IdentifierPtr*,
    const GT::IdentifiersPtr*
) const {
    createdPlayers++;
    return new GT::GTL::PlayerPtr(
        GT::GTL::setupLocation<GT::GTL::Player>(
            GT::GTL::NullFactory::getInstance().createPlayer(),
            inputLocation
        )
    );
}

GT::Message TestGameDriverImpl::toString() const {
    return GT::Message("TestGameDriverImpl");
}

// }; /* END class TestGameDriverImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class TestStatementDriverImpl final : public GT::GTL::StatementDriver {
// public:

TestStatementDriverImpl::TestStatementDriverImpl() :
    GT::GTL::StatementDriver(),
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

GT::GTL::DefinitionPtr* TestStatementDriverImpl::createDefinition(
    const GT::GTL::InputLocation& inputLocation,
    const GT::IdentifierPtr*,
    const GT::GTL::ObjectPtr*
) const {
    return new GT::GTL::DefinitionPtr(
        GT::GTL::setupLocation<GT::GTL::Definition>(
            GT::GTL::NullFactory::getInstance().createDefinition(),
            inputLocation
        )
    );
}

GT::GTL::QueryPtr* TestStatementDriverImpl::createQuery(
    const GT::GTL::InputLocation& inputLocation,
    const GT::IdentifiersPtr*,
    const GT::GTL::ObjectsPtr*,
    const GT::GTL::ConditionsPtr*
) const {
    return new GT::GTL::QueryPtr(
        GT::GTL::setupLocation<GT::GTL::Query>(
            GT::GTL::NullFactory::getInstance().createQuery(),
            inputLocation
        )
    );
}

GT::Message TestStatementDriverImpl::toString() const {
    return GT::Message("TestStatementDriverImpl");
}

// }; /* END class TestStatementDriverImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class TestValueDriverImpl final : public GT::GTL::ValueDriver {
// public:

TestValueDriverImpl::TestValueDriverImpl() :
    GT::GTL::ValueDriver(),
    usedParameters(0)
    {}

GT::GTL::ParamPtr* TestValueDriverImpl::get(
    const GT::GTL::InputLocation& inputLocation,
    const GT::IdentifierPtr*
) const {
    usedParameters++;
    return new GT::GTL::ParamPtr(
        GT::GTL::setupLocation<GT::GTL::Param>(
            GT::GTL::NullFactory::getInstance().createParam(),
            inputLocation
        )
    );
}

GT::GTL::ParamPtr* TestValueDriverImpl::get(
    const GT::GTL::InputLocation& inputLocation,
    const GT::NumberPtr*
) const {
    usedParameters++;
    return new GT::GTL::ParamPtr(
        GT::GTL::setupLocation<GT::GTL::Param>(
            GT::GTL::NullFactory::getInstance().createParam(),
            inputLocation
        )
    );
}

GT::GTL::ObjectPtr* TestValueDriverImpl::toObject(
    const GT::GTL::GamePtr* game
) const {
    return new GT::GTL::ObjectPtr(
        GT::GTL::setupLocation<GT::GTL::Object>(
            GT::GTL::NullFactory::getInstance().createObject(),
            *(*game)->getInputLocation()
        )
    );
}

GT::GTL::ObjectPtr* TestValueDriverImpl::toObject(
    const GT::GTL::PlayerPtr* player
) const {
    return new GT::GTL::ObjectPtr(
        GT::GTL::setupLocation<GT::GTL::Object>(
            GT::GTL::NullFactory::getInstance().createObject(),
            *(*player)->getInputLocation()
        )
    );
}

GT::GTL::ObjectPtr* TestValueDriverImpl::toObject(
    const GT::GTL::ParamPtr* param
) const {
    return new GT::GTL::ObjectPtr(
        GT::GTL::setupLocation<GT::GTL::Object>(
            GT::GTL::NullFactory::getInstance().createObject(),
            *(*param)->getInputLocation()
        )
    );
}

GT::Message TestValueDriverImpl::toString() const {
    return GT::Message("TestValueDriverImpl");
}

// }; /* END class TestValueDriverImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class TestDriverImpl final : public GT::GTL::Driver {
// public:

TestDriverImpl::TestDriverImpl() :
    shownResults(0),
    shownErrors(0),
    executed(0),
    loaded(0),
    saved(0)
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

void TestDriverImpl::execute(
    const GT::GTL::InputLocation&,
    const GT::Identifier&
) const {
    executed++;
}

void TestDriverImpl::load(
    const GT::GTL::InputLocation&,
    const GT::Identifier&
) {
    loaded++;
}

void TestDriverImpl::save(
    const GT::GTL::InputLocation&,
    const GT::Identifier&
) const {
    saved++;
}

GT::Message TestDriverImpl::toString() const {
    return GT::Message("TestDriverImpl");
}

// }; /* END class TestDriverImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
