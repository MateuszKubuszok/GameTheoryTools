%require  "2.5"
%skeleton "lalr1.cc"
%debug
%locations

%defines
%define namespace         "GT::GTL"
%define parser_class_name "Parser"

%code top {
    /**
     * @brief Parser used for processing input for GTL.
     *
     * @author Mateusz Kubuszok
     */
     
    /* System libraries */
    #include <iostream> /* Default I/O streams library */
    #include <fstream>  /* File Streams library */
    #include <sstream>  /* StringStream */
    #include <cstdlib>  /* C Standard library */

    /* GTL prototypes */
    #include "gt/gtl/common.hpp"

    using namespace GT::GTL;

    /**
     * @brief Override default yylex function.
     * 
     * @param lvalue   matched content
     * @param location current location
     * @param driver   driver instance
     * @param scanner  scanner instance
     * @return         next found token number
     */
    static int yylex(
        Parser::semantic_type* lvalue,
        Parser::location_type* location,
        Scanner&               scanner,
        Driver&                driver
    );
}

%code requires {
    /* Declares classes used in Parser */
    namespace GT {
        namespace GTL {
            class Scanner;
            class Driver;
        }
    }
}

%lex-param   { Scanner& scanner }
%parse-param { Scanner& scanner }

%lex-param   { Driver& driver }
%parse-param { Driver& driver }

/* Union containing values as either double or string */
%union {
    IdentifierPtr*  identifier;
    IdentifiersPtr* identifiers;
    NumberPtr*      number;
    ConditionPtr*   condition;
    ConditionsPtr*  conditions;
    CoordinatePtr*  coordinate;
    CoordinatesPtr* coordinates;
    DefinitionPtr*  definition;
    DetailsPtr*     details;
    GamePtr*        game;
    QueryPtr*       query;
    ObjectPtr*      object;
    ObjectsPtr*     objects;
    ParamPtr*       param;
    ParamsPtr*      params;
    PlayerPtr*      player;
}

/* Declared tokens */

/* Driving tokens */
%token TERMINATE 0 /* End of File */

/* Keywords and symbols */
%token LET       /* LET keyword */
%token BE        /* BE keyword */
%token PLAYER    /* PLAYER keyword */
%token GAME      /* GAME keyword */
%token STRATEGIC /* STRATEGIC keyword */
%token TREE      /* TREE keyword */
%token WITH      /* WITH keyword */
%token SUCH      /* SUCH keyword */
%token AS        /* AS keyword */
%token END       /* END keyword */
%token FIND      /* FIND keyword */
%token FOR       /* FOR keyword */
%token CHOOSE    /* CHOOSE keyword */
%token LCBR      /* { charakter */
%token RCBR      /* } charakter */
%token EQUAL     /* = charakter */
%token COLON     /* : charakter */
%token COMA      /* , charakter */
%token EOC       /* ; charakter */

/* Input */
%token <identifier> lexer_error  /* Error */
%token <identifier> identifier   /* Identifier */
%token <number>     number       /* Double number */

 /* Declared types */
 
%type <condition>    condition
%type <coordinate>   coordinate
%type <coordinate>   coordinates
%type <coordinates>  data
%type <coordinate>   data_coordinate
%type <definition>   definition
%type <details>      details
%type <game>         game
%type <query>        query
%type <object>       object
%type <param>        param
%type <player>       player

%type <conditions>   condition_collection
%type <conditions>   conditions
%type <coordinates>  data_coordinates
%type <identifiers>  identifiers
%type <objects>      objects
%type <params>       params

/* Destructor rules */

%destructor { if ($$) { delete($$); ($$) = nullptr; } } <identifier>
%destructor { if ($$) { delete($$); ($$) = nullptr; } } <identifiers>
%destructor { if ($$) { delete($$); ($$) = nullptr; } } <number>
%destructor { if ($$) { delete($$); ($$) = nullptr; } } <condition>
%destructor { if ($$) { delete($$); ($$) = nullptr; } } <conditions>
%destructor { if ($$) { delete($$); ($$) = nullptr; } } <coordinate>
%destructor { if ($$) { delete($$); ($$) = nullptr; } } <coordinates>
%destructor { if ($$) { delete($$); ($$) = nullptr; } } <definition>
%destructor { if ($$) { delete($$); ($$) = nullptr; } } <details>
%destructor { if ($$) { delete($$); ($$) = nullptr; } } <game>
%destructor { if ($$) { delete($$); ($$) = nullptr; } } <query>
%destructor { if ($$) { delete($$); ($$) = nullptr; } } <object>
%destructor { if ($$) { delete($$); ($$) = nullptr; } } <objects>
%destructor { if ($$) { delete($$); ($$) = nullptr; } } <param>
%destructor { if ($$) { delete($$); ($$) = nullptr; } } <params>
%destructor { if ($$) { delete($$); ($$) = nullptr; } } <player>

/* Make parser start from program */
%start program

%%

/* Program */

program
 : statements TERMINATE
 | TERMINATE
 ;

/* Statements */

statements
 : statements statement
 | statement
 ;

statement
 : definition EOC { driver.forStatement().executeDefinition($1); }
 | query EOC      { driver.forStatement().executeQuery($1); }
 | parser_error
 ;

definition
 : LET identifier BE object { $$ = driver.forStatement().createDefinition(@1, $2, $4); }
 ;
 
query
 : FIND identifiers FOR objects conditions { $$ = driver.forStatement().createQuery(@1, $2, $4, $5); }
 ;

/* Objects */

objects
 : objects COMA object { $$ = driver.forObjects().insert($3, $1); }
 | object              { $$ = driver.forObjects().create($1); }
 ;

object
 : game   { $$ = driver.forValue().toObject($1); }
 | player { $$ = driver.forValue().toObject($1); }
 | param  { $$ = driver.forValue().toObject($1); }
 ;
 
/* Games */

game
 : STRATEGIC GAME details game_end { $$ = driver.forGame().createStrategic($3); }
 | TREE      GAME details game_end { $$ = driver.forGame().createTree($3); }
 ;

game_end
 : 
 | END
 ;

details
 : WITH objects SUCH AS data { $$ = driver.forGame().createDetails($2, $5); }
 ;
 
/* Players */

player
 : PLAYER identifier LCBR identifiers RCBR { $$ = driver.forGame().createPlayer($2, $4); }
 ;

/* Params */

param
 : identifier { $$ = driver.forValue().get($1); }
 | number     { $$ = driver.forValue().get($1); }
 ;

params
 : params COMA param { $$ = driver.forParams().insert($3, $1); }
 | param             { $$ = driver.forParams().create($1); }
 ;

/* Identifiers */

identifiers
 : identifiers COMA identifier { $$ = driver.forIdentifiers().insert($3, $1); }
 | identifier                  { $$ = driver.forIdentifiers().create($1); }
 ;

/* Conditions */

conditions
 : condition_collection { $$ = $1; }
 |                      { $$ = driver.forConditions().empty(); }
 ;

condition_collection
 : condition_collection COMA condition { $$ = driver.forConditions().insert($3, $1); }
 | WITH condition                      { $$ = driver.forConditions().create($2); }
 ;

condition
 : PLAYER object CHOOSE object { $$ = driver.forCondition().playerChoosed(@1, $2, $4); }
 ;
 
/* Data */

data
 : data_coordinates { $$ = $1; }
 ;

data_coordinates
 : data_coordinates COMA data_coordinate { $$ = driver.forCoordinates().insert($3, $1); }
 | data_coordinate                       { $$ = driver.forCoordinates().create($1); }
 ;

data_coordinate
 : LCBR coordinates COLON data_coordinates RCBR { $$ = driver.forCoordinate().fillWithData($2, $4); }
 | LCBR coordinates COLON params RCBR           { $$ = driver.forCoordinate().fillWithData($2, $4); }
 ;

coordinates
 : coordinates COMA coordinate { $$ = driver.forCoordinate().merge($1, $3); }
 | coordinate                  { $$ = $1; }
 ;

coordinate
 : identifier EQUAL identifier { $$ = driver.forCoordinate().create($1, $3); }
 ;

/* Errors */

parser_error
 : error
 | lexer_error {
        std::string message = std::string() + "not recognized symbols: \"" + (**$1) + "\"";
        error(@1, message);
    }
 ;

%%

/**
 * @brief Handles errors occuring during parsing.
 *
 * @param location location of error occurance
 * @param message  error message
 */
void Parser::error(
    const Parser::location_type& location,
    const std::string&           message
) {
    std::stringstream builder;
    builder << "Error:" << std::endl
            << '\t' << message << std::endl
            << "\tat line \""
            << location
            << "\"" << std::endl;
    std::string errorMessage(builder.str());
    driver.showError(errorMessage);
}

/**
 * @brief Include for scanner.yylex.
 *
 * @param lvalue  matched content
 * @param scanner scanner instance
 * @param driver  driver instance
 */
static int yylex(
    Parser::semantic_type* lvalue,
    Parser::location_type* location,
    Scanner&               scanner,
    Driver&                driver
) {
    return scanner.lex(lvalue);
}
