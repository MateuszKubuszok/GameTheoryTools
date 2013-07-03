%require  "2.5"
%skeleton "lalr1.cc"
%debug

%defines
%define namespace         "GTL"
%define parser_class_name "Parser"

%code requires{
    namespace GTL {
        class Driver;
        class Scanner;
    }
}

%lex-param   { Scanner &scanner }
%parse-param { Scanner &scanner }

%lex-param   { Driver &driver }
%parse-param { Driver &driver }

%code{
    /************************************************************************
     * GTL Parser
     ************************************************************************/
     
    /* System libraries */
    #include <iostream> /*  */
    #include <fstream>  /*  */
    #include <cstdlib>  /*  */
    #include <string>   /*  */

    /* GTL prototypes */
    #include "gtl_driver.hpp"   /**/
    
    /**/
    static int yylex(GTL::Parser::semantic_type *yylval, GTL::Scanner &scanner, GTL::Driver &driver);
}

%union {
    STD::string sval;
    double      dval;
}

/*  */
%token LET              /*  */
%token BE               /*  */
%token PLAYERS          /*  */
%token PLAYER           /*  */
%token GAME             /*  */
%token PURE             /*  */
%token MIXED            /*  */
%token TREE             /*  */
%token WITH             /*  */
%token SUCH             /*  */
%token AS               /*  */
%token FIND             /*  */
%token FOR              /*  */
%token EQUILIBRIUM      /*  */

/*  */
%token <svar>identifier /*  */
%token <dvar>number     /*  */
