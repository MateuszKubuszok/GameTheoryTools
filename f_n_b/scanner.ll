/******************************* Code for header ****************************/

%{
/**
 * @brief Scanner used for processing input for GTL.
 *
 * @author Mateusz Kubuszok
 */

/* System libraries */
#include <cstdlib>         /* Standard library */

/* GTL prototypes */
#include "gt/gtl/inner_common.hpp"

/* Shorten token's type name */
typedef GT::GTL::Parser::token token;

/* Defines termination token */
#define yyterminate() return (token::TERMINATE)

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
    /* Sets output filename */
%option outfile="src/gt/gtl/scanner.cpp"
    /* Do not use Unix-specific unistd.h */
%option nounistd

 /* Defines states used for ommitnig comments */
%x block_comment
%x inline_comment

 /* RegEx definitions */
number[0-9]+
integer(-?){number}
float(-?){number}\.{number}
scientific(-?){number}(\.{number})?[eE]{integer}
identifier[_a-zA-Z]([_a-zA-Z0-9]*)

%%

 /* Keywords and symbols definitions */
(?i:LET)       { return (token::LET); }
(?i:BE)        { return (token::BE); }
(?i:PLAYER)    { return (token::PLAYER); }
(?i:GAME)      { return (token::GAME); }
(?i:STRATEGIC) { return (token::STRATEGIC); }
(?i:EXTENSIVE) { return (token::EXTENSIVE); }
(?i:WITH)      { return (token::WITH); }
(?i:SUCH)      { return (token::SUCH); }
(?i:AS)        { return (token::AS); }
(?i:END)       { return (token::END); }
(?i:FIND)      { return (token::FIND); }
(?i:FOR)       { return (token::FOR); }
(?i:CHOOSE)    { return (token::CHOOSE); }
"="            { return (token::EQUAL); }
"{"            { return (token::LCBR); }
"}"            { return (token::RCBR); }
":"            { return (token::COLON); }
","            { return (token::COMA); }
";"            { return (token::EOC); }

 /* Numbers definitions */
{scientific}|{float}|{integer} {
        lval->number = new GT::NumberPtr(new GT::Number(yytext));
        return (token::number);
    }

 /* Identifiers */
{identifier} {
        lval->identifier = new GT::IdentifierPtr(new GT::Identifier(yytext));
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
.                     {
        lval->identifier = new GT::IdentifierPtr(new GT::Identifier(yytext));
        return (token::lexer_error);
    }

%%

 /*********************** Code after scanner definition **********************/

/**
 * @brief Mock implementation for yyFlexLexer::yylex() - without it compiler throws error.
 */
int yyFlexLexer::yylex() {
    return 0;
}
