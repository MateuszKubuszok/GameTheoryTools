%require  "2.5"
%skeleton "lalr1.cc"
%debug

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
    #include <cstdlib>  /* C Standard library */

    /* GTL prototypes */
    #include "gt/gtl/common.hpp"

    using namespace GT::GTL;

    /**
     * @brief Override default yylex function.
     * 
     * @param yylval  matched content
     * @param driver  driver instance
     * @param scanner scanner instance
     * @return        next found token number
     */
    static int yylex(
        Parser::semantic_type* yylval,
        Scanner&               scanner,
        Driver&                driver
    );
}

%code requires {
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

%token LET    /* LET keyword */
%token BE     /* BE keyword */
%token PLAYER /* PLAYER keyword */
%token GAME   /* GAME keyword */
%token PURE   /* PURE keyword */
%token MIXED  /* MIXED keyword */
%token TREE   /* TREE keyword */
%token WITH   /* WITH keyword */
%token SUCH   /* SUCH keyword */
%token AS     /* AS keyword */
%token FIND   /* FIND keyword */
%token FOR    /* FOR keyword */
%token CHOOSE /* CHOOSE keyword */
%token LCBR   /* { charakter */
%token RCBR   /* } charakter */
%token EQUAL  /* = charakter */
%token COLON  /* : charakter */
%token COMA   /* , charakter */
%token EOC    /* ; charakter */

%token <identifier> parser_error /* Error */
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

%destructor { if ($$) { delete($$); ($$) = 0; } } <identifier>
%destructor { if ($$) { delete($$); ($$) = 0; } } <identifiers>
%destructor { if ($$) { delete($$); ($$) = 0; } } <number>
%destructor { if ($$) { delete($$); ($$) = 0; } } <condition>
%destructor { if ($$) { delete($$); ($$) = 0; } } <conditions>
%destructor { if ($$) { delete($$); ($$) = 0; } } <coordinate>
%destructor { if ($$) { delete($$); ($$) = 0; } } <coordinates>
%destructor { if ($$) { delete($$); ($$) = 0; } } <definition>
%destructor { if ($$) { delete($$); ($$) = 0; } } <details>
%destructor { if ($$) { delete($$); ($$) = 0; } } <game>
%destructor { if ($$) { delete($$); ($$) = 0; } } <query>
%destructor { if ($$) { delete($$); ($$) = 0; } } <object>
%destructor { if ($$) { delete($$); ($$) = 0; } } <objects>
%destructor { if ($$) { delete($$); ($$) = 0; } } <param>
%destructor { if ($$) { delete($$); ($$) = 0; } } <params>
%destructor { if ($$) { delete($$); ($$) = 0; } } <player>

%%

/* Statements */

statement
 : definition EOC { driver.storeDefinedObject($1); }
 | query EOC      { driver.executeQuery($1); }
 | parser_error
 ;

definition
 : LET identifier BE object { $$ = driver.createDefinition($2, $4); }
 ;
 
query
 : FIND identifiers FOR objects conditions { $$ = driver.createQuery($2, $4, $5); }
 ;

/* Objects */

objects
 : objects COMA object { $$ = driver.addObjectToCollection($3, $1); }
 | object              { $$ = driver.createObjectsCollection($1); }

object
 : game   { $$ = driver.convert($1); }
 | player { $$ = driver.convert($1); }
 | param  { $$ = driver.convert($1); }
 ;
 
/* Games */

game
 : PURE  GAME details { $$ = driver.createPureGameForDetails($3); }
 | MIXED GAME details { $$ = driver.createMixedGameForDetails($3); }
 | TREE  GAME details { $$ = driver.createTreeGameForDetails($3); }
 ;

details
 : WITH objects SUCH AS data { $$ = driver.createDetailsForGame($2, $5); }
 ;
 
/* Players */

player
 : PLAYER identifier LCBR identifiers RCBR { $$ = driver.createPlayerWithStrategies($2, $4); }
 ;

/* Params */

param
 : identifier { $$ = driver.getValue($1); }
 | number     { $$ = driver.getValue($1); }
 ;

params
 : params COMA param { $$ = driver.addParamToCollection($3, $1); }
 | param             { $$ = driver.createParamsCollection($1); }
 ;

/* Identifiers */

identifiers
 : identifiers COMA identifier { $$ = driver.addIdentifierToCollection($3, $1); }
 | identifier                  { $$ = driver.createIdentifiersCollection($1); }
 ;

/* Conditions */

conditions
 : condition_collection { $$ = $1; }
 |                      { $$ = driver.emptyConditionsCollection(); }
 ;

condition_collection
 : condition_collection COMA condition { $$ = driver.addConditionToCollection($3, $1); }
 | WITH condition                      { $$ = driver.createConditionsCollection($2); }
 ;

condition
 : PLAYER object CHOOSE object { $$ = driver.createPlayerChoiceCondition($2, $4); }
 ;
 
/* Data */

data
 : data_coordinates { $$ = $1; }
 ;

data_coordinates
 : data_coordinates COMA data_coordinate { $$ = driver.addCoordinatesToCollection($1, $3); }
 | data_coordinate                       { $$ = driver.createCoordinatesCollection($1); }
 ;

data_coordinate
 : LCBR coordinates COLON data_coordinates RCBR { $$ = driver.fillCoordinateWithData($2, $4); }
 | LCBR coordinates COLON params RCBR           { $$ = driver.fillCoordinateWithData($2, $4); }
 ;

coordinates
 : coordinates COMA coordinate { $$ = driver.mergeCoordinates($1, $3); }
 | coordinate                  { $$ = $1; }
 ;

coordinate
 : identifier EQUAL identifier { $$ = driver.createCoordinate($1, $3); }
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
    driver.errorInformation(message);
}

/**
 * @brief Include for scanner.yylex.
 *
 * @param yylval  matched content
 * @param scanner scanner instance
 * @param driver  driver instance
 */
static int yylex(
    Parser::semantic_type* yylval,
    Scanner&               scanner,
    Driver&                driver
) {
    return scanner.yylex(yylval);
}
