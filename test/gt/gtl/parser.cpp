#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( Parser )

////////////////////////////////////////////////////////////////////////////////

template<typename Content>
class ParserTestCollectionsDriverImpl : public GT::GTL::NullCollectionsDriver<Content> {
    unsigned int createdCollections;
    unsigned int addedElements;

public:
    ParserTestCollectionsDriverImpl<Content>() :
        GT::GTL::NullCollectionsDriver<Content>(),
        createdCollections(0),
        addedElements(0)
        {}

    virtual typename GT::GTL::NullCollectionsDriver<Content>::CollectionPtr* empty() {
        createdCollections++;
        return GT::GTL::NullCollectionsDriver<Content>::empty();
    }

    virtual typename GT::GTL::NullCollectionsDriver<Content>::CollectionPtr* create(
        typename GT::GTL::NullCollectionsDriver<Content>::ContentPtr* element
    ) {
        createdCollections++;
        addedElements++;
        return GT::GTL::NullCollectionsDriver<Content>::create(element);
    }

    virtual typename GT::GTL::NullCollectionsDriver<Content>::CollectionPtr* insert(
        typename GT::GTL::NullCollectionsDriver<Content>::ContentPtr*    element,
        typename GT::GTL::NullCollectionsDriver<Content>::CollectionPtr* collection
    ) {
        addedElements++;
        return GT::GTL::NullCollectionsDriver<Content>::insert(element, collection);
    }

    unsigned int getCreatedCollections() {
        return createdCollections;
    }

    unsigned int getAddedElements() {
        return addedElements;
    }
}; /* END class ParserTestCollectionsDriver */

////////////////////////////////////////////////////////////////////////////////

class ParserTestConditionDriverImpl : public GT::GTL::NullConditionDriver {
    unsigned int createdConditions;

public:
    ParserTestConditionDriverImpl() :
        GT::GTL::NullConditionDriver(),
        createdConditions(0)
        {}

    virtual GT::GTL::ConditionPtr* playerChoosed(
        GT::GTL::ObjectPtr* player,
        GT::GTL::ObjectPtr* strategy
    ) {
        createdConditions++;
        return GT::GTL::NullConditionDriver::playerChoosed(player, strategy);
    }

    unsigned int getCreatedConditions() {
        return createdConditions;
    }
}; /* END class ParserTestConditionDriverImpl */

////////////////////////////////////////////////////////////////////////////////

class ParserTestCoordinateDriverImpl : public GT::GTL::NullCoordinateDriver {
    unsigned int createdCoordinates;
    unsigned int filledCoordinates;
    unsigned int mergedCoordinates;
public:
    ParserTestCoordinateDriverImpl() :
        GT::GTL::NullCoordinateDriver(),
        createdCoordinates(0),
        filledCoordinates(0),
        mergedCoordinates(0)
        {}

    virtual GT::GTL::CoordinatePtr* create(
        const GT::IdentifierPtr* player,
        const GT::IdentifierPtr* strategy
    ) {
        createdCoordinates++;
        return GT::GTL::NullCoordinateDriver::create(player, strategy);
    }

    virtual GT::GTL::CoordinatePtr* fillWithData(
        const GT::GTL::CoordinatePtr* coordinate,
        const GT::GTL::ParamsPtr*     data
    ) {
        filledCoordinates++;
        return GT::GTL::NullCoordinateDriver::fillWithData(coordinate, data);
    }

    virtual GT::GTL::CoordinatePtr* merge(
        const GT::GTL::CoordinatePtr* coordinate1,
        const GT::GTL::CoordinatePtr* coordinate2
    ) {
        mergedCoordinates++;
        return GT::GTL::NullCoordinateDriver::merge(coordinate1, coordinate2);
    }

    unsigned int getCreatedCoordinates() {
        return createdCoordinates;
    }

    unsigned int getFilledCoordinates() {
        return filledCoordinates;
    }

    unsigned int getMergeCoordinates() {
        return mergedCoordinates;
    }
}; /* END class ParserTestCoordinateDriverImpl */

////////////////////////////////////////////////////////////////////////////////

class ParserTestGameDriverImpl : public GT::GTL::NullGameDriver {
    unsigned int createdStrategicGames;
    unsigned int createdTreeGames;
    unsigned int createdDetails;
    unsigned int createdPlayers;

public:
    ParserTestGameDriverImpl() :
        GT::GTL::NullGameDriver(),
        createdStrategicGames(0),
        createdTreeGames(0),
        createdDetails(0),
        createdPlayers(0)
        {}

    virtual GT::GTL::GamePtr* createStrategic(
        GT::GTL::DetailsPtr* details
    ) {
        createdStrategicGames++;
        return GT::GTL::NullGameDriver::createStrategic(details);
    }

    virtual GT::GTL::GamePtr* createTree(
        GT::GTL::DetailsPtr* details
    ) {
        createdTreeGames++;
        return GT::GTL::NullGameDriver::createTree(details);
    }

    virtual GT::GTL::DetailsPtr* createDetails(
        GT::GTL::ObjectsPtr*     players,
        GT::GTL::CoordinatesPtr* data
    ) {
        createdDetails++;
        return GT::GTL::NullGameDriver::createDetails(players, data);
    }

    virtual GT::GTL::PlayerPtr* createPlayer(
        GT::IdentifierPtr*  player,
        GT::IdentifiersPtr* strategies
    ) {
        createdPlayers++;
        return GT::GTL::NullGameDriver::createPlayer(player, strategies);
    }

    unsigned int getCreatedStrategicGames() {
        return createdStrategicGames;
    }

    unsigned int getCreatedTreeGames() {
        return createdTreeGames;
    }

    unsigned int getCreatedDetails() {
        return createdDetails;
    }

    unsigned int getCreatedPlayers() {
        return createdPlayers;
    }
}; /* END class ParserTestGameDriverImpl */

////////////////////////////////////////////////////////////////////////////////

class ParserTestStatementDriverImpl : public GT::GTL::NullStatementDriver {
    unsigned int executedDefinitions;
    unsigned int executedQueries;

public:
    ParserTestStatementDriverImpl() :
        GT::GTL::NullStatementDriver()
        {}

    virtual void executeDefinition(
        GT::GTL::DefinitionPtr*
    ) {
        executedDefinitions++;
    }

    virtual void executeQuery(
        GT::GTL::QueryPtr*
    ) {
        executedQueries++;
    }

    unsigned int getExecutedDefinitions() {
        return executedDefinitions;
    }

    unsigned int getExecutedQueries() {
        return executedQueries;
    }
}; /* END class ParserTestStatementDriverImpl */

////////////////////////////////////////////////////////////////////////////////

class ParserTestValueDriverImpl : public GT::GTL::NullValueDriver {
    unsigned int usedParameters;
public:
    ParserTestValueDriverImpl() :
        GT::GTL::NullValueDriver(),
        usedParameters(0)
        {}

    virtual GT::GTL::ParamPtr* get(
        GT::IdentifierPtr* identifier
    ) {
        usedParameters++;
        return GT::GTL::NullValueDriver::get(identifier);
    }

    virtual GT::GTL::ParamPtr* get(
        GT::NumberPtr* number
    ) {
        usedParameters++;
        return GT::GTL::NullValueDriver::get(number);
    }
}; /* END class ParserTestValueDriverImpl */

////////////////////////////////////////////////////////////////////////////////

class ParserTestDriverImpl : public GT::GTL::Driver {
    unsigned int shownErrors;
public:
    ParserTestDriverImpl() :
        shownErrors(0)
        {}

    ParserTestCoordinateDriverImpl                       coordinate;
    ParserTestCollectionsDriverImpl<GT::GTL::Coordinate> coordinates;
    ParserTestConditionDriverImpl                        condition;
    ParserTestCollectionsDriverImpl<GT::GTL::Condition>  conditions;
    ParserTestGameDriverImpl                             game;
    ParserTestCollectionsDriverImpl<GT::Identifier>      identifiers;
    ParserTestCollectionsDriverImpl<GT::GTL::Object>     objects;
    ParserTestCollectionsDriverImpl<GT::GTL::Param>      params;
    ParserTestValueDriverImpl                            value;
    ParserTestStatementDriverImpl                        statement;

    virtual GT::GTL::CoordinateDriver& forCoordinate() {
        return coordinate;
    }

    virtual GT::GTL::CollectionsDriver<GT::GTL::Coordinate>& forCoordinates() {
        return coordinates;
    }

    virtual GT::GTL::ConditionDriver& forCondition() {
        return condition;
    }
    
    virtual GT::GTL::CollectionsDriver<GT::GTL::Condition>& forConditions() {
        return conditions;
    }

    virtual GT::GTL::GameDriver& forGame() {
        return game;
    }
    
    virtual GT::GTL::CollectionsDriver<GT::Identifier>& forIdentifiers() {
        return identifiers;
    }
    
    virtual GT::GTL::CollectionsDriver<GT::GTL::Object>& forObjects() {
        return objects;
    }
    
    virtual GT::GTL::CollectionsDriver<GT::GTL::Param>& forParams() {
        return params;
    }

    virtual GT::GTL::ValueDriver& forValue() {
        return value;
    }

    virtual GT::GTL::StatementDriver& forStatement() {
        return statement;
    }

    virtual void showError(
        const GT::Message&
    ) {
        shownErrors++;
    }

    unsigned int getShownErrors() {
        return shownErrors;
    }
}; /* END class ParserTestDriverImpl */

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( Parser_valueParam  ) {
    // given
    std::string content =
        "LET value1 BE 10;\n"
        "LET value2 BE 20;\n"
        "LET value3 BE 30;\n"
    ;
    std::istringstream  stream(content);
    GT::GTL::ScannerPtr scanner = GT::GTL::ScannerPtr(new GT::GTL::Scanner(&stream));
    GT::GTL::DriverPtr  driver  = GT::GTL::NullFactory::getInstance().createDriver(); 

    // when
    GT::GTL::Parser parser(*scanner, *driver);

    // then
    BOOST_CHECK(parser.parse());
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
