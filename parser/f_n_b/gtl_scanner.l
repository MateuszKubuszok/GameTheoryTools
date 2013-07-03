/******************************* Code for header ****************************/

%{
    /************************************************************************
     * GTL Lexer 
     ************************************************************************/
     
    /* System libraries */
    #include <cstdlib>         /* Standard library */
    #include <string>          /* String library */

    /* GTL prototypes */
    #include "gtl_scanner.hpp" /* Lexer's prototypes */
    #include "gtl_parser.hpp"  /* Parser's prototypes */

    typedef                    /* Shorten token's type name */
        GTL::Parser::token
        token;

    /* Define yyterminate as this instead of NULL */
    #define yyterminate() return(token::EOF)
%}
/**************************** Options and states ****************************/

/* Lexer's options */
%option debug                         /* Allow debugging */
%option nodefault                     /* Doesn't allow usage of defult values */
%option noyywrap                      /* yylex wrapper should be created manually */
%option yylineno                      /* Allows following of error appearance */
%option c++                           /* Code should be generated for C++ instead of C */
%option yyclass="Scanner"             /* Names the C++ class */
%option outfile="gtl_scanner.cpp"     /* Sets output filename */
%option header-file="gtl_scanner.hpp" /* Sets header filename */

/* Defines states used for ommitnig comments */
%x block_comment
%x inline_comment

%%

/***************************** RegEx for tokens *****************************/

/* Keywords and symbols definitions */
(?i:LET)         { return (token::LET); }
(?i:BE)          { return (token::BE); }
(?i:PLAYERS)     { return (token::PLAYERS); }
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
(?i:EQUILIBRIUM) { return (token::EQUILIBRIUM); }
";"              { return (token::EOC); }

/* Numbers definitions */
-?([0-9]+)(\.([0-9]+))?[eE]([0-9]+) {
    yyval->dval = atof(yytext);
    return (token::number);
}
-?([0-9]+)\.([0-9]+) {
    yyval->dval = atof(yytext);
    return (token::number);
}
-?([0-9]+) {
    yyval->dval = (int) atoi(yytext);
    return (token::number);
}

/* Identifiers */
[_a-zA-Z]([_a-zA-Z0-9]*) {
    yyval->sval = new std::string(yytext);
    return (token::identifier);
}

/* Block comments */
\\\*                  { BEGIN(block_comment); }
<block_comment>\*\\   { BEGIN(0); }
<block_comment>(.|\n) /* Remove block comment content */

/* Inline comments */
\\\\                  { BEGIN(inline_comment); }
<inline_comment>\n    { BEGIN(0); }
<inline_comment>.     /* Remove inline comment content */

/* White spaces and errors */
[ \t\r\f\v\n]+        /* Removes white chars */
.                     { return lexerror; }

%%

/*********************** Code after scanner definition **********************/

