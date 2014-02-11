%{

/****************************************** Required by scanner.cpp *****************************************/

/**
 * @brief Scanner used for processing input for GTL.
 *
 * @author Mateusz Kubuszok
 */

/* Make GTLFlexLexer be defined only once */
#ifndef __GTL_FLEX_LEXER__
#define __GTL_FLEX_LEXER__
#endif /* END #ifndef __GTL_FLEX_LEXER__ */

/* Standard library */
#include <cstdlib>

/* GTL prototypes */
#include "gt/gtl/inner_common.hpp"

/** @brief Shorten token's type name */
typedef GT::GTL::Parser::token token;

/** @brief Defines termination token */
#define yyterminate() return (token::TERMINATE)

/** @brief Updates inner buffer variable used for current column tracking. */
#define UPDATE_COLUMNS ( YY_CURRENT_BUFFER != NULL ? YY_CURRENT_BUFFER->yy_bs_column += yyleng : 0 )

/** @brief Resets inner buffer variable used for current column tracking. */
#define RESET_COLUMNS  ( YY_CURRENT_BUFFER != NULL ? YY_CURRENT_BUFFER->yy_bs_column = 1 : 0 )

/** @brief Obtains current column. */
#define CURRENT_COLUMN ( YY_CURRENT_BUFFER != NULL ? YY_CURRENT_BUFFER->yy_bs_column : 1 )

/** @brief Action called after each rule initialization - updates column tracking. */
#define YY_USER_ACTION UPDATE_COLUMNS;

%}

 /******************************************* Options and states ********************************************/

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
    /* Changes generated class name to GTLFlexLexer */
%option prefix="GTL"
    /* Sets output filename */
%option outfile="src/gt/gtl/scanner.cpp"
    /* Do not use Unix-specific unistd.h */
%option nounistd

 /* Defines states used for ommitnig comments */
%x string
%x block_comment
%x inline_comment

 /* RegEx definitions */
number[0-9]+
integer(-?){number}
float(-?){number}\.{number}
scientific(-?){number}(\.{number})?[eE]{integer}
identifier[_a-zA-Z]([_a-zA-Z0-9]*)

%%

 /******************************************* Tokens definitions ********************************************/

 /* Keywords and symbols definitions */
(?i:EXECUTE)   { return (token::EXECUTE); }
(?i:LOAD)      { return (token::LOAD); }
(?i:SAVE)      { return (token::SAVE); }
(?i:TO)        { return (token::TO); }
(?i:LET)       { return (token::LET); }
(?i:BE)        { return (token::BE); }
(?i:PLAYER)    { return (token::PLAYER); }
(?i:GAME)      { return (token::GAME); }
(?i:STRATEGIC) { return (token::STRATEGIC); }
(?i:EXTENSIVE) { return (token::EXTENSIVE); }
(?i:WITH)      { return (token::WITH); }
(?i:SUCH)      { return (token::SUCH); }
(?i:AS)        { return (token::AS); }
(?i:AT)        { return (token::AT); }
(?i:IN)        { return (token::IN); }
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

 /* String (identifier) */
"\""           { BEGIN(string); }
<string>[^\"]* {
        lval->identifier = new GT::IdentifierPtr(new GT::Identifier(yytext));
        return (token::identifier);
    }
<string>"\""   { BEGIN(0); }

 /* Block comments */
"\/\*"                 { BEGIN(block_comment); }
<block_comment>"\*\/"  { BEGIN(0); }
<block_comment>(.|\n)  { /* Remove block comment content */ }

 /* Inline comments */
"\/\/"                 { BEGIN(inline_comment); }
<inline_comment>"\\\n" { /* Don't end comment with \ symbol at the end of line */ }
<inline_comment>\n     { BEGIN(0); }
<inline_comment>.      { /* Remove inline comment content */ }

 /* White spaces and errors */
"\n"                   { RESET_COLUMNS; }
[ \t\r\f\v]+           { /* Removes white chars */ }
.                      {
        lval->identifier = new GT::IdentifierPtr(new GT::Identifier(yytext));
        return (token::lexer_error);
    }

%%

/******************************* Not-generated Scanner's methods definition's *******************************/

namespace GT {
namespace GTL {

// class Scanner : public GTLFlexLexer {
// public:

Scanner::Scanner(
    InputStream* inputStream
) :
    GTLFlexLexer(inputStream),
    lval(nullptr)
    {}

bool Scanner::isInteractive() const {
    return YY_CURRENT_BUFFER && YY_CURRENT_BUFFER->yy_is_interactive;
}

void Scanner::setInteractive(
    bool isNowInteractive
) {
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wnull-conversion"

    yy_set_interactive(isNowInteractive);

#   pragma clang diagnostic pop
}

// private:

int Scanner::lex(
    Parser::semantic_type* newlval,
    Parser::location_type& newlocation
) {
    lval = newlval;

    newlocation.begin.line   = yylineno;
    newlocation.begin.column = CURRENT_COLUMN;

    int result = lex();

    newlocation.end.line   = yylineno;
    newlocation.end.column = CURRENT_COLUMN;

    return result;
}

// }; /* END class Scanner */

} /* END namespace GTL */
} /* END namespace GT */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Mock implementation for GTLFlexLexer::yylex() - without it compiler would throw error.
 */
int GTLFlexLexer::yylex() {
    return 0;
}
