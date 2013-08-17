/******************************* Code for header ****************************/

%{
/************************************************************************
 * GTL Lexer 
 ************************************************************************/
 
/* System libraries */
#include <cstdlib>         /* Standard library */
#include <string>          /* String library */

/* GTL prototypes */
#include "gtl/scanner.hpp" /* Lexer's prototypes */
#include "gtl/parser.hpp"  /* Parser's prototypes */

typedef                    /* Shorten token's type name */
    GTL::Parser::token
    token;

/* Define yyterminate as this instead of NULL */
#define yyterminate() return(token::EOF)
%}

 /**************************** Options and states ****************************/

 /* Lexer's options */
    /* Allow debugging */
%option debug
    /* Doesn't allow usage of default values */
%option nodefault
    /* yylex wrapper should be created manually */
%option noyywrap
    /* Allows following of error appearance */
%option yylineno
    /* Code should be generated for C++ instead of C */
%option c++
    /* Names the C++ class */
%option yyclass="Scanner"
    /* Sets output filename */
%option outfile="src/gtl/scanner.cpp"

 /* Defines states used for ommitnig comments */
%x block_comment
%x inline_comment

 /* RegEx definitions */
number[0-9]+
integer(-?){number}
float(-?){number}\.{number}
scientific(-?){number}\.{number}[eE]{integer}
identifier[_a-zA-Z]([_a-zA-Z0-9]*)

%%

 /* Keywords and symbols definitions */
(?i:LET)         { return (token::LET); }
(?i:BE)          { return (token::BE); }
(?i:PLAYER)      { return (token::PLAYER); }
(?i:GAME)        { return (token::GAME); }
(?i:PURE)        { return (token::PURE); }
(?i:MIXED)       { return (token::MIXED); }
(?i:TREE)        { return (token::TREE); }
(?i:WITH)        { return (token::WITH); }
(?i:SUCH)        { return (token::SUCH); }
(?i:AS)          { return (token::AS); }
(?i:FIND)        { return (token::FIND); }
(?i:FOR)         { return (token::FOR); }
(?i:CHOOSE)      { return (token::CHOOSE); }
{                { return (token::LCBR); }
}                { return (token::RCBR); }
:                { return (token::COLON); }
,                { return (token::COMA); }
;                { return (token::EOC); }

 /* Numbers definitions */
-?{scientific} {
        yyval->dval = atof(yytext);
        return (token::number);
    }
-?{float} {
        yyval->dval = atof(yytext);
        return (token::number);
    }
-?{integer} {
        yyval->dval = (int) atoi(yytext);
        return (token::number);
    }

 /* Identifiers */
{identifier} {
        yyval->sval = new std::string(yytext);
        return (token::identifier);
    }

 /* Block comments */
\\\*                  { BEGIN(block_comment); }
<block_comment>\*\\   { BEGIN(0); }
<block_comment>(.|\n) { /* Remove block comment content */ }

 /* Inline comments */
\\\\                  { BEGIN(inline_comment); }
<inline_comment>\\\n  { /* Don't end comment with \ symbol at the end of line */ }
<inline_comment>\n    { BEGIN(0); }
<inline_comment>.     { /* Remove inline comment content */ }

 /* White spaces and errors */
[ \t\r\f\v\n]+        { /* Removes white chars */ }
.                     { return (token::error); }

%%

 /*********************** Code after scanner definition **********************/
