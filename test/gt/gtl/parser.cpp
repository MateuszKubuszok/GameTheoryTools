#include "gt/gtl/test_common.hpp"

BOOST_AUTO_TEST_SUITE( Parser )

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( Parser_emptyProgramIsValid  ) {
    // given
    std::string content;
    std::istringstream   stream(content);
    GT::GTL::Scanner     scanner(&stream);
    TestDriverImpl driver;

    // when
    GT::GTL::Parser parser(scanner, driver);
    // parser.set_debug_level(1);

    // then
    BOOST_REQUIRE_EQUAL( parser.parse(), 0 ); // no errors occured
    BOOST_CHECK_EQUAL( driver.getShownErrors(), 0 ); // no errors shown
}

BOOST_AUTO_TEST_CASE( Parser_valueParamDefinition  ) {
    // given
    std::string content =
        "LET value1 BE 10;\n"
        "LET value2 BE 20.0;\n"
        "LET value3 BE 3e1;\n"
        "LET value4 BE 4.0e1;\n"
    ;
    std::istringstream stream(content);
    GT::GTL::Scanner   scanner(&stream);
    TestDriverImpl     driver;

    // when
    GT::GTL::Parser parser(scanner, driver);
    // parser.set_debug_level(1);

    // then
    BOOST_REQUIRE_EQUAL( parser.parse(), 0 ); // no errors occured
    BOOST_CHECK_EQUAL( driver.getShownErrors(), 0 ); // no errors shown
    BOOST_CHECK_EQUAL( driver.statement.getExecutedDefinitions(), 4 ); // parsed 4 definitions
    BOOST_CHECK_EQUAL( driver.value.getUsedParameters(), 4 ); // created 4 parameters from numbers
}

BOOST_AUTO_TEST_CASE( Parser_identifierParamDefinition  ) {
    // given
    std::string content =
        "LET value1 BE id;\n"
        "LET value2 BE _id;\n"
    ;
    std::istringstream stream(content);
    GT::GTL::Scanner   scanner(&stream);
    TestDriverImpl     driver;

    // when
    GT::GTL::Parser parser(scanner, driver);
    // parser.set_debug_level(1);

    // then
    BOOST_REQUIRE_EQUAL( parser.parse(), 0 ); // no errors occured
    BOOST_CHECK_EQUAL( driver.getShownErrors(), 0 ); // no errors shown
    BOOST_CHECK_EQUAL( driver.statement.getExecutedDefinitions(), 2 ); // parsed 2 definitions
    BOOST_CHECK_EQUAL( driver.value.getUsedParameters(), 2 ); // created 2 parameters from identifiers
}

BOOST_AUTO_TEST_CASE( Parser_playerDefinition  ) {
    // given
    std::string content =
        "LET _player BE\n"
        "PLAYER p1 {\n"
        "  s1,\n"
        "  s2\n"
        "};\n"
    ;
    std::istringstream stream(content);
    GT::GTL::Scanner   scanner(&stream);
    TestDriverImpl     driver;

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
    std::istringstream stream(content);
    GT::GTL::Scanner   scanner(&stream);
    TestDriverImpl     driver;

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

BOOST_AUTO_TEST_CASE( Parser_extensiveGameDefinition  ) {
    // given
    std::string content =
        "LET _game BE\n"
        "EXTENSIVE GAME WITH\n"
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
    std::istringstream stream(content);
    GT::GTL::Scanner   scanner(&stream);
    TestDriverImpl     driver;

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
        "  EXTENSIVE GAME\n"
        "  WITH\n"
        "    PLAYER p1 { s },\n"
        "    PLAYER p2 { s }\n"
        "  SUCH AS\n"
        "    { p1=s :\n"
        "      { p2=s : 10, 20 }\n"
        "    }\n"
        "  END;\n"
    ;
    std::istringstream stream(content);
    GT::GTL::Scanner   scanner(&stream);
    TestDriverImpl     driver;

    // when
    GT::GTL::Parser parser(scanner, driver);
    // parser.set_debug_level(1);

    // then
    BOOST_REQUIRE_EQUAL( parser.parse(), 0 ); // no errors occured
    BOOST_CHECK_EQUAL( driver.getShownErrors(), 0 ); // no errors shown
    BOOST_CHECK_EQUAL( driver.statement.getExecutedQueries(), 1 ); // parser 1 query
    BOOST_CHECK_EQUAL( driver.value.getUsedParameters(), 9 ); // created 9 parameters from numbers (8)
                                                              // and identifiers (1)
    BOOST_CHECK_EQUAL( driver.game.getCreatedPlayers(), 5 ); // crated 5 players
    BOOST_CHECK_EQUAL( driver.game.getCreatedStrategicGames(), 1 ); // created 1 strategy game
    BOOST_CHECK_EQUAL( driver.game.getCreatedExtensiveGames(), 1 ); // created 1 extensive game
}

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
    std::istringstream stream(content);
    GT::GTL::Scanner   scanner(&stream);
    TestDriverImpl     driver;

    // when
    GT::GTL::Parser parser(scanner, driver);
    // parser.set_debug_level(1);

    // then
    BOOST_REQUIRE_EQUAL( parser.parse(), 0 ); // no errors occured
    BOOST_CHECK_EQUAL( driver.getShownErrors(), 0 ); // no errors shown
    BOOST_CHECK_EQUAL( driver.statement.getExecutedQueries(), 1 ); // parser 1 query
    BOOST_CHECK_EQUAL( driver.value.getUsedParameters(), 5 ); // created 5 parameters from numbers (4)
                                                              // and identifiers (1)
}

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
        "  EXTENSIVE GAME\n"
        "  WITH\n"
        "    PLAYER p1 { s },\n"
        "    PLAYER p2 { s }\n"
        "  SUCH AS\n"
        "    { p1=s :\n"
        "      { p2=s : 10, 20 }\n"
        "    }\n"
        "  END;\n"
    ;
    std::istringstream stream(content);
    GT::GTL::Scanner   scanner(&stream);
    TestDriverImpl     driver;

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
    BOOST_CHECK_EQUAL( driver.game.getCreatedExtensiveGames(), 1 ); // created 1 extensive game
}

BOOST_AUTO_TEST_CASE( Parser_queryWithAllConditions ) {
    // given
    std::string content =
        "FIND pure_equilibrium\n"
        "FOR\n"
        "  STRATEGIC GAME\n"
        "  WITH\n"
        "    PLAYER p1 { s },\n"
        "    PLAYER p2 { s }\n"
        "  SUCH AS\n"
        "    { p1=s, p2=s : 10, 20 }\n"
        "  END,\n"
        "  EXTENSIVE GAME\n"
        "  WITH\n"
        "    PLAYER p1 { s },\n"
        "    PLAYER p2 { s }\n"
        "  SUCH AS\n"
        "    { p1=s :\n"
        "      { p2=s : 10, 20 }\n"
        "    }\n"
        "  END\n"
        "WITH\n"
        "  PLAYER p1 CHOOSE s,\n"
        "  PLAYER p2 IN { s },\n"
        "  PLAYER p1 AT \"1\" CHOOSE s,\n"
        "  PLAYER p2 AT \"1\" IN { s };\n"
    ;
    std::istringstream stream(content);
    GT::GTL::Scanner   scanner(&stream);
    TestDriverImpl     driver;

    // when
    GT::GTL::Parser parser(scanner, driver);
    // parser.set_debug_level(1);

    // then
    BOOST_REQUIRE_EQUAL( parser.parse(), 0 ); // no errors occured
    BOOST_CHECK_EQUAL( driver.getShownErrors(), 0 ); // no errors shown
    BOOST_CHECK_EQUAL( driver.statement.getExecutedQueries(), 1 ); // parsed 1 query
    BOOST_CHECK_EQUAL( driver.condition.getCreatedConditions(), 4 ); // created 1 extensive game
}

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
    std::istringstream stream(content);
    GT::GTL::Scanner   scanner(&stream);
    TestDriverImpl     driver;

    // when
    GT::GTL::Parser parser(scanner, driver);
    // parser.set_debug_level(1);

    // then
    BOOST_REQUIRE_EQUAL( parser.parse(), 0 ); // no errors occured
    BOOST_CHECK_EQUAL( driver.getShownErrors(), 0 ); // no errors shown
    BOOST_CHECK_EQUAL( driver.statement.getExecutedDefinitions(), 2 ); // parsed 2 definitions
    BOOST_CHECK_EQUAL( driver.statement.getExecutedQueries(), 1 ); // parsed 1 query
    BOOST_CHECK_EQUAL( driver.value.getUsedParameters(), 4 ); // created 4 parameters from numbers (2)
                                                              // and identifiers (2)
    BOOST_CHECK_EQUAL( driver.game.getCreatedPlayers(), 2 ); // crated 2 players
    BOOST_CHECK_EQUAL( driver.game.getCreatedStrategicGames(), 1 ); // created 1 strategy game
}

BOOST_AUTO_TEST_CASE( Parser_executeFile ) {
    // given
    std::string content =
        "EXECUTE \"../some_file.gtl\";"
    ;
    std::istringstream stream(content);
    GT::GTL::Scanner   scanner(&stream);
    TestDriverImpl     driver;

    // when
    GT::GTL::Parser parser(scanner, driver);
    // parser.set_debug_level(1);

    // then
    BOOST_REQUIRE_EQUAL( parser.parse(), 0 ); // no errors occured
    BOOST_CHECK_EQUAL( driver.getShownErrors(), 0 ); // no errors shown
    BOOST_CHECK_EQUAL( driver.getExecuted(), 1 ); // parsed 1 context loads
}

BOOST_AUTO_TEST_CASE( Parser_loadContext ) {
    // given
    std::string content =
        "LOAD \"../some_file.gtl\";"
    ;
    std::istringstream stream(content);
    GT::GTL::Scanner   scanner(&stream);
    TestDriverImpl     driver;

    // when
    GT::GTL::Parser parser(scanner, driver);
    // parser.set_debug_level(1);

    // then
    BOOST_REQUIRE_EQUAL( parser.parse(), 0 ); // no errors occured
    BOOST_CHECK_EQUAL( driver.getShownErrors(), 0 ); // no errors shown
    BOOST_CHECK_EQUAL( driver.getLoaded(), 1 ); // parsed 1 context loads
}

BOOST_AUTO_TEST_CASE( Parser_saveContext ) {
    // given
    std::string content =
        "SAVE TO \"../some_file.gtl\";"
    ;
    std::istringstream stream(content);
    GT::GTL::Scanner   scanner(&stream);
    TestDriverImpl     driver;

    // when
    GT::GTL::Parser parser(scanner, driver);
    // parser.set_debug_level(1);

    // then
    BOOST_REQUIRE_EQUAL( parser.parse(), 0 ); // no errors occured
    BOOST_CHECK_EQUAL( driver.getShownErrors(), 0 ); // no errors shown
    BOOST_CHECK_EQUAL( driver.getSaved(), 1 ); // parsed 1 context loads
}

BOOST_AUTO_TEST_CASE( Parser_recoverFromErrorAtStatement ) {
    // given
    std::string content =
        "error;\n"
        "LET player1 BE\n"
        "  PLAYER p1 { s };\n"
        "LET player2 BE\n"
        "  PLAYER p2 { s };\n"
    ;
    std::istringstream stream(content);
    GT::GTL::Scanner   scanner(&stream);
    TestDriverImpl     driver;

    // when
    GT::GTL::Parser parser(scanner, driver);
    // parser.set_debug_level(1);

    // then
    BOOST_REQUIRE_EQUAL( parser.parse(), 0 ); // recovered from parsing error
    BOOST_CHECK_EQUAL( driver.getShownErrors(), 1 ); // 1 error occured
    BOOST_CHECK_EQUAL( driver.statement.getExecutedDefinitions(), 2 ); // parsed 2 definitions
    BOOST_CHECK_EQUAL( driver.game.getCreatedPlayers(), 2 ); // created 2 players
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
