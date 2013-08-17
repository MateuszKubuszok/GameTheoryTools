%require  "2.5"
%skeleton "lalr1.cc"
%debug

%defines
%define namespace         "GTL"
%define parser_class_name "Parser"

%code top {
    /************************************************************************
     *                              GTL Parser                              *
     ************************************************************************/
     
    /* System libraries */
    #include <iostream> /* Default I/O streams library */
    #include <fstream>  /* File Streams library */
    #include <cstdlib>  /* C Standard library */
    #include <string>   /* String library */

    /* GTL prototypes */
    #include "gtl/driver.hpp"  /* GTL::Driver class */
    #include "gtl/scanner.hpp" /* GTL::Scanner class */
    
    /* Override default yylex function */
    static int yylex(GTL::Parser::semantic_type *yylval, GTL::Scanner &scanner, GTL::Driver &driver);
}

%code requires {
    namespace GTL {
        class Driver;
        class Scanner;
    }
}

%lex-param   { Scanner &scanner }
%parse-param { Scanner &scanner }

%lex-param   { Driver &driver }
%parse-param { Driver &driver }

/* Union containing values as either double or string */
%union {
    STD::string sval;
    double      dval;
}

/* Declared tokens */

/* Non-terminals */
%token LET               /*  */
%token BE                /*  */
%token PLAYER            /*  */
%token GAME              /*  */
%token PURE              /*  */
%token MIXED             /*  */
%token TREE              /*  */
%token WITH              /*  */
%token SUCH              /*  */
%token AS                /*  */
%token FIND              /*  */
%token FOR               /*  */
%token LCBR              /* { */
%token RCBR              /* } */
%token COLON             /* : */
%token COMA              /* , */
%token EOC               /* ; */
%token error             /* error marker */

/* Terminals */
%token <svar> identifier /* Identifier */
%token <dvar> number     /* Double number */

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
 | param  { $$ = driver.getValueForIdentifier($1); }
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
 : conditions COMA condition { $$ = driver.addConditionToCollection($3, $1); }
 | WITH condition            { $$ = driver.createConditionsCollection($2); }
 |                           { $$ = driver.emptyConditionCollection(); }
 ;

condition
 : PLAYER object CHOOSE object { $$ = driver.createPlayerChoiceCondition($2, $4); }
 ;
 
/* Data */

data
 : data COMA data_piece  { $$ = driver.addDataPieceToData($1, $3); }
 | data_piece            { $$ = driver.createData($1); }
 ;

data_piece
 : identifier param                              { $$ = driver.createOneDimensionData($1, $2); }
 | identifiers LCBR identifier COLON params RCBR { $$ = driver.createTwoDimensionalData($1, $3, $5); }
 | identifiers COLON data_piece                  { $$ = driver.createMultiDimensionalData($1, $3); }
 ;

params
 : params COMA param { $$ = driver.addParamToCollection($3, $1); }
 | param             { $$ = driver.createParamsCollection($1); }
 ;

%%

/* Error handling */
void GTL::Parser::error(const GTL::Parser::location_type &location, const std::string &message) {
    driver.errorInformation(loc, message);
}

/* Include for scanner.yylex */
static int yylex(GTL::Parser::semantic_type *yylval, GTL::Scanner &scanner, GTL::Driver &driver) {
    return scanner.yylex(yylval);
}