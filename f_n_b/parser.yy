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

    /**
     * @brief Override default yylex function.
     * 
     * @param yylval  matched content
     * @param scanner scanner instance
     * @param driver  driver instance
     * @return        next found token number
     */
    static int yylex(
        Parser::semantic_type *yylval,
        Scanner               &scanner,
        Driver                &driver
    );
}

%code requires {
    namespace GT {
        namespace GTL {
            class Driver;
            class Scanner;
        }
    }
}

%lex-param   { Scanner &scanner }
%parse-param { Scanner &scanner }

%lex-param   { Driver &driver }
%parse-param { Driver &driver }

/* Union containing values as either double or string */
%union {
    Identifier    identifier;
    Identifiers   identifiers;
    Number        number;
    Condition     condition;
    Conditions    conditions;
    Data          data;
    DataPieceMap  dataPiece;
    DataPieces    dataPieces;
    Definition    definition;
    Details       details;
    Game          game;
    Query         query;
    Object        object;
    Objects       objects;
    Param         param;
    PathPair      pathPair;
    PathPairs     pathPairs;
    Player        player;
}

/* Declared tokens */

%token LET               /* LET keyword */
%token BE                /* BE keyword */
%token PLAYER            /* PLAYER keyword */
%token GAME              /* GAME keyword */
%token PURE              /* PURE keyword */
%token MIXED             /* MIXED keyword */
%token TREE              /* TREE keyword */
%token WITH              /* WITH keyword */
%token SUCH              /* SUCH keyword */
%token AS                /* AS keyword */
%token FIND              /* FIND keyword */
%token FOR               /* FOR keyword */
%token CHOOSE            /* CHOOSE keyword */
%token LCBR              /* { charakter */
%token RCBR              /* } charakter */
%token EQUAL             /* = charakter */
%token COLON             /* : charakter */
%token COMA              /* , charakter */
%token EOC               /* ; charakter */
%token error             /* Error marker */

%token <identifier> identifier /* Identifier */
%token <number>     number     /* Double number */

 /* Declared types */
 
%type <condition>    condition
%type <data>         data
%type <dataPiece>    data_piece
%type <definition>   definition
%type <details>      details
%type <game>         game
%type <query>        query
%type <object>       object
%type <param>        param
%type <pathPair>     path_pair
%type <player>       player

%type <conditions>   condition_collection
%type <conditions>   conditions
%type <dataPieces>   data_pieces
%type <identifiers>  identifiers
%type <objects>      objects
%type <pathPairs>    path_pairs

%%

/* Statements */

statement
 : definition EOC { driver.storeDefinedObject($1); }
 | query EOC      { driver.executeQuery($1); }
 ;

definition
 : LET identifier BE object { $$ = driver.createDefinition($4, $2); }
 ;
 
query
 : FIND identifiers FOR objects conditions { $$ = driver.createQuery($2, $4, $5); }
 ;

/* Objects */

objects
 : objects COMA object { $$ = driver.addObjectToCollection($3, $1); }
 | object              { $$ = driver.createObjectsCollection($1); }

object
 : game   { $$ = $1; }
 | player { $$ = $1; }
 | param  { $$ = $1; }
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
 : PLAYER identifier LCBR objects RCBR { $$ = driver.createPlayerWithStrategies($2, $4); }
 ;

/* Params */

param
 : identifier { $$ = driver.getValueForIdentifier($1); }
 | number     { $$ = driver.getValueForNumber($1); }
 ;

/* Identifiers */

identifiers
 : identifiers COMA identifier { $$ = driver.addIdentifierToCollection($3, $1); }
 | identifier                  { $$ = driver.createIdentifiersCollection($1); }
 ;

/* Conditions */

conditions
 : condition_collection { $$ = $1; }
 |                      { $$ = driver.emptyConditionCollection(); }
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
 : data_pieces { $$ = driver.createData($1); }
 ;

data_pieces
 : data_pieces COMA data_piece { $$ = driver.addDataPieceToCollection($3, $1); }
 | data_piece                  { $$ = driver.createDataPieceCollection($1); }
 ;

data_piece
 : LCBR path_pairs COLON data_pieces RCBR { $$ = driver.createMultiDimensionalDataPieces($2, $4); }
 | LCBR path_pairs COLON param RCBR { $$ = driver.createOneDimensionDataPieces($2, $4); }
 ;

path_pairs
 : path_pairs COMA path_pair {}
 | path_pair {}
 ;

path_pair
 : identifier EQUAL identifier {}
 ;

%%

/**
 * @brief Handles errors occuring during parsing.
 *
 * @param location location of error occurance
 * @param message  error message
 */
void Parser::error(
    const Parser::location_type &location,
    const std::string &message
) {
    driver.errorInformation(loc, message);
}

/**
 * @brief Include for scanner.yylex.
 *
 * @param yylval  matched content
 * @param scanner scanner instance
 * @param driver  driver instance
 */
static int yylex(
    Parser::semantic_type *yylval,
    Scanner &scanner,
    Driver  &driver
) {
    return scanner.yylex(yylval);
}
