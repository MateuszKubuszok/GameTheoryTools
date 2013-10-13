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
        GT::GTL::NullStatementDriver(),
        executedDefinitions(0),
        executedQueries(0)
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

    unsigned int getUsedParameters() {
        return usedParameters;
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
        const GT::Message& message
    ) {
        std::cerr << message << std::endl;
        shownErrors++;
    }

    unsigned int getShownErrors() {
        return shownErrors;
    }

    virtual GT::Message toString() {
        return GT::Message("ParserTestDriverImpl");
    }
}; /* END class ParserTestDriverImpl */

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( Parser_emptyProgramIsValid  ) {
    // given
    std::string content;
    std::istringstream   stream(content);
    GT::GTL::Scanner     scanner(&stream);
    ParserTestDriverImpl driver;

    // when
    GT::GTL::Parser parser(scanner, driver);
    // parser.set_debug_level(1);

    // then
    BOOST_REQUIRE_EQUAL( parser.parse(), 0 ); // no errors occured
    BOOST_CHECK_EQUAL( driver.getShownErrors(), 0 ); // no errors shown
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( Parser_valueParamDefinition  ) {
    // given
    std::string content =
        "LET value1 BE 10;\n"
        "LET value2 BE 20.0;\n"
        "LET value3 BE 3e1;\n"
        "LET value4 BE 4.0e1;\n"
    ;
    std::istringstream   stream(content);
    GT::GTL::Scanner     scanner(&stream);
    ParserTestDriverImpl driver;

    // when
    GT::GTL::Parser parser(scanner, driver);
    // parser.set_debug_level(1);

    // then
    BOOST_REQUIRE_EQUAL( parser.parse(), 0 ); // no errors occured
    BOOST_CHECK_EQUAL( driver.getShownErrors(), 0 ); // no errors shown
    BOOST_CHECK_EQUAL( driver.statement.getExecutedDefinitions(), 4 ); // parsed 4 definitions
    BOOST_CHECK_EQUAL( driver.value.getUsedParameters(), 4 ); // created 4 parameters from numbers
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( Parser_identifierParamDefinition  ) {
    // given
    std::string content =
        "LET value1 BE id;\n"
        "LET value2 BE _id;\n"
    ;
    std::istringstream   stream(content);
    GT::GTL::Scanner     scanner(&stream);
    ParserTestDriverImpl driver;

    // when
    GT::GTL::Parser parser(scanner, driver);
    // parser.set_debug_level(1);

    // then
    BOOST_REQUIRE_EQUAL( parser.parse(), 0 ); // no errors occured
    BOOST_CHECK_EQUAL( driver.getShownErrors(), 0 ); // no errors shown
    BOOST_CHECK_EQUAL( driver.statement.getExecutedDefinitions(), 2 ); // parsed 2 definitions
    BOOST_CHECK_EQUAL( driver.value.getUsedParameters(), 2 ); // created 2 parameters from identifiers
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( Parser_playerDefinition  ) {
    // given
    std::string content =
        "LET _player BE\n"
        "PLAYER p1 {\n"
        "  s1,\n"
        "  s2\n"
        "};\n"
    ;
    std::istringstream   stream(content);
    GT::GTL::Scanner     scanner(&stream);
    ParserTestDriverImpl driver;

    // when
    GT::GTL::Parser parser(scanner, driver);
    // parser.set_debug_level(1);

    // then
    BOOST_REQUIRE_EQUAL( parser.parse(), 0 ); // no errors occured
    BOOST_CHECK_EQUAL( driver.getShownErrors(), 0 ); // no errors shown
    BOOST_CHECK_EQUAL( driver.statement.getExecutedDefinitions(), 1 ); // parsed 1 definition 
    BOOST_CHECK_EQUAL( driver.game.getCreatedPlayers(), 1 ); // created 1 player
    BOOST_CHECK_EQUAL( driver.identifiers.getAddedElements(), 2 ); // created collection of 2 strategies
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( Parser_strategicGameDefinition  ) {
    // given
    std::string content =
        "LET _game BE\n"
        "STRATEGIC GAME WITH\n"
        "  PLAYER p1 {\n"
        "    s1,\n"
        "    s2\n"
        "  },\n"
        "  PLAYER p2 {\n"
        "    s1,\n"
        "    s2\n"
        "  }\n"
        "SUCH AS\n"
        "  { p1=s1, p2=s1 : 10, param1 },\n"
        "  { p1=s1, p2=s2 : param2, 20.0 },\n"
        "  { p1=s2 :\n"
        "     { p2=s1 : 3e1, param3 },\n"
        "     { p2=s2 : param4, 4.0e1 }\n"
        "  };\n"
    ;
    std::istringstream   stream(content);
    GT::GTL::Scanner     scanner(&stream);
    ParserTestDriverImpl driver;

    // when
    GT::GTL::Parser parser(scanner, driver);
    // parser.set_debug_level(1);

    // then
    BOOST_REQUIRE_EQUAL( parser.parse(), 0 ); // no errors occured
    BOOST_CHECK_EQUAL( driver.getShownErrors(), 0 ); // no errors shown
    BOOST_CHECK_EQUAL( driver.statement.getExecutedDefinitions(), 1 ); // parsed 1 definition
    BOOST_CHECK_EQUAL( driver.game.getCreatedPlayers(), 2 ); // created 2 players
    BOOST_CHECK_EQUAL( driver.value.getUsedParameters(), 8 ); // created 8 parameters from numbers
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( Parser_treeGameDefinition  ) {
    // given
    std::string content =
        "LET _game BE\n"
        "TREE GAME WITH\n"
        "  PLAYER p1 {\n"
        "    s1,\n"
        "    s2\n"
        "  },\n"
        "  PLAYER p2 {\n"
        "    s1,\n"
        "    s2\n"
        "  }\n"
        "SUCH AS\n"
        "  { p1=s1 :\n"
        "     { p2=s1 : 10, param1 },\n"
        "     { p2=s2 : param2, 20.0 }\n"
        "  },\n"
        "  { p1=s2 :\n"
        "     { p2=s1 : 3e1, param3 },\n"
        "     { p2=s2 : param4, 4.0e1 }\n"
        "  };\n"
    ;
    std::istringstream   stream(content);
    GT::GTL::Scanner     scanner(&stream);
    ParserTestDriverImpl driver;

    // when
    GT::GTL::Parser parser(scanner, driver);
    // parser.set_debug_level(1);

    // then
    BOOST_REQUIRE_EQUAL( parser.parse(), 0 ); // no errors occured
    BOOST_CHECK_EQUAL( driver.getShownErrors(), 0 ); // no errors shown
    BOOST_CHECK_EQUAL( driver.statement.getExecutedDefinitions(), 1 ); // parsed 1 definition
    BOOST_CHECK_EQUAL( driver.game.getCreatedPlayers(), 2 ); // created 2 players
    BOOST_CHECK_EQUAL( driver.value.getUsedParameters(), 8 ); // created 8 parameters from numbers
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( Parser_queryForType ) {
    // given
    std::string content =
        "FIND type\n"
        "FOR\n"
        "  10,\n"
        "  20.0,\n"
        "  3e1,\n"
        "  4.0e1,\n"
        "  identifier,\n"
        "  PLAYER p { s1, s2 },\n"
        "  STRATEGIC GAME\n"
        "  WITH\n"
        "    PLAYER p1 { s },\n"
        "    PLAYER p2 { s }\n"
        "  SUCH AS\n"
        "    { p1=s, p2=s : 10, 20 }\n"
        "  END,\n"
        "  TREE GAME\n"
        "  WITH\n"
        "    PLAYER p1 { s },\n"
        "    PLAYER p2 { s }\n"
        "  SUCH AS\n"
        "    { p1=s :\n"
        "      { p2=s : 10, 20 }\n"
        "    }\n"
        "  END;\n"
    ;
    std::istringstream   stream(content);
    GT::GTL::Scanner     scanner(&stream);
    ParserTestDriverImpl driver;

    // when
    GT::GTL::Parser parser(scanner, driver);
    // parser.set_debug_level(1);

    // then
    BOOST_REQUIRE_EQUAL( parser.parse(), 0 ); // no errors occured
    BOOST_CHECK_EQUAL( driver.getShownErrors(), 0 ); // no errors shown
    BOOST_CHECK_EQUAL( driver.statement.getExecutedQueries(), 1 ); // parser 1 query
    BOOST_CHECK_EQUAL( driver.value.getUsedParameters(), 9 ); // created 9 parameters from numbers (8) nad identifiers (1)
    BOOST_CHECK_EQUAL( driver.game.getCreatedPlayers(), 5 ); // crated 5 players
    BOOST_CHECK_EQUAL( driver.game.getCreatedStrategicGames(), 1 ); // created 1 strategy game
    BOOST_CHECK_EQUAL( driver.game.getCreatedTreeGames(), 1 ); // created 1 tree game
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( Parser_queryForValue ) {
    // given
    std::string content =
        "FIND value\n"
        "FOR\n"
        "  10,\n"
        "  20.0,\n"
        "  3e1,\n"
        "  4.0e1,\n"
        "  identifier;\n"
    ;
    std::istringstream   stream(content);
    GT::GTL::Scanner     scanner(&stream);
    ParserTestDriverImpl driver;

    // when
    GT::GTL::Parser parser(scanner, driver);
    // parser.set_debug_level(1);

    // then
    BOOST_REQUIRE_EQUAL( parser.parse(), 0 ); // no errors occured
    BOOST_CHECK_EQUAL( driver.getShownErrors(), 0 ); // no errors shown
    BOOST_CHECK_EQUAL( driver.statement.getExecutedQueries(), 1 ); // parser 1 query
    BOOST_CHECK_EQUAL( driver.value.getUsedParameters(), 5 ); // created 5 parameters from numbers (4) nad identifiers (1)
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( Parser_queryForEquilibrium ) {
    // given
    std::string content =
        "FIND pure_equilibrium, mixed_equilibrium\n"
        "FOR\n"
        "  STRATEGIC GAME\n"
        "  WITH\n"
        "    PLAYER p1 { s },\n"
        "    PLAYER p2 { s }\n"
        "  SUCH AS\n"
        "    { p1=s, p2=s : 10, 20 }\n"
        "  END,\n"
        "  TREE GAME\n"
        "  WITH\n"
        "    PLAYER p1 { s },\n"
        "    PLAYER p2 { s }\n"
        "  SUCH AS\n"
        "    { p1=s :\n"
        "      { p2=s : 10, 20 }\n"
        "    }\n"
        "  END;\n"
    ;
    std::istringstream   stream(content);
    GT::GTL::Scanner     scanner(&stream);
    ParserTestDriverImpl driver;

    // when
    GT::GTL::Parser parser(scanner, driver);
    // parser.set_debug_level(1);

    // then
    BOOST_REQUIRE_EQUAL( parser.parse(), 0 ); // no errors occured
    BOOST_CHECK_EQUAL( driver.getShownErrors(), 0 ); // no errors shown
    BOOST_CHECK_EQUAL( driver.statement.getExecutedQueries(), 1 ); // parsed 1 query
    BOOST_CHECK_EQUAL( driver.value.getUsedParameters(), 4 ); // created 4 parameters from numbers
    BOOST_CHECK_EQUAL( driver.game.getCreatedPlayers(), 4 ); // crated 4 players
    BOOST_CHECK_EQUAL( driver.game.getCreatedStrategicGames(), 1 ); // created 1 strategy game
    BOOST_CHECK_EQUAL( driver.game.getCreatedTreeGames(), 1 ); // created 1 tree game
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( Parser_defineThenQuery ) {
    // given
    std::string content =
        "LET player1 BE\n"
        "  PLAYER p1 { s };\n"
        "LET player2 BE\n"
        "  PLAYER p2 { s };\n"
        "FIND pure_equilibrium, mixed_equilibrium\n"
        "FOR\n"
        "  STRATEGIC GAME\n"
        "  WITH\n"
        "    player1,\n"
        "    player2\n"
        "  SUCH AS\n"
        "    { p1=s, p2=s : 10, 20 };\n"
    ;
    std::istringstream   stream(content);
    GT::GTL::Scanner     scanner(&stream);
    ParserTestDriverImpl driver;

    // when
    GT::GTL::Parser parser(scanner, driver);
    // parser.set_debug_level(1);

    // then
    BOOST_REQUIRE_EQUAL( parser.parse(), 0 ); // no errors occured
    BOOST_CHECK_EQUAL( driver.getShownErrors(), 0 ); // no errors shown
    BOOST_CHECK_EQUAL( driver.statement.getExecutedDefinitions(), 2 ); // parsed 2 definitions
    BOOST_CHECK_EQUAL( driver.statement.getExecutedQueries(), 1 ); // parsed 1 query
    BOOST_CHECK_EQUAL( driver.value.getUsedParameters(), 4 ); // created 4 parameters from numbers (2) and identifiers (2)
    BOOST_CHECK_EQUAL( driver.game.getCreatedPlayers(), 2 ); // crated 2 players
    BOOST_CHECK_EQUAL( driver.game.getCreatedStrategicGames(), 1 ); // created 1 strategy game
}

////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( Parser_recoverFromErrorAtStatement ) {
    // given
    std::string content =
        "error;\n"
        "LET player1 BE\n"
        "  PLAYER p1 { s };\n"
        "LET player2 BE\n"
        "  PLAYER p2 { s };\n"
    ;
    std::istringstream   stream(content);
    GT::GTL::Scanner     scanner(&stream);
    ParserTestDriverImpl driver;

    // when
    GT::GTL::Parser parser(scanner, driver);
    // parser.set_debug_level(1);

    // then
    BOOST_REQUIRE_EQUAL( parser.parse(), 0 ); // recovered from parsing error
    BOOST_CHECK_EQUAL( driver.getShownErrors(), 1 ); // 1 error occured
    BOOST_CHECK_EQUAL( driver.statement.getExecutedDefinitions(), 2 ); // parsed 2 definitions
    BOOST_CHECK_EQUAL( driver.game.getCreatedPlayers(), 2 ); // created 2 players
}

BOOST_AUTO_TEST_SUITE_END()
