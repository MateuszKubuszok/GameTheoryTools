#ifndef __GT_GTL_SCANNER_HPP__
#define __GT_GTL_SCANNER_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif /* END ! defined(yyFlexLexerOnce) */

#undef  YY_DECL
#define YY_DECL int GT::GTL::Scanner::lex()

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Scanns for tokens declared by Parser class in given stream.
 *
 * @author Mateusz Kubuszok
 */
class Scanner : public yyFlexLexer {
    /**
     * @brief Field used during token scanning - contains actual value of parsed chain.
     */
    Parser::semantic_type* lval;

public:
    /**
     * @brief Initiates Scanner with input stream that serves as data source.
     *
     * @param inputStream input stream initiating Scanner
     */
    Scanner(
        std::istream* inputStream
    ) :
        yyFlexLexer(inputStream),
        lval(nullptr)
        {}

    /**
     * @brief Scans for next token.
     *
     * @param newlval initiates next scanning with value
     * @return        returns number of next token
     */
    virtual int lex(
        Parser::semantic_type* newlval
    ) {
        lval = newlval;
        return lex();
    }

private:
    /**
     * @brief Actual lexer/scanner function.
     *
     * <p>
     * Uses source defined by the constructor.
     * </p>
     *
     * @return value used for communicating with Parser
     */
    int lex();
}; /* END class Scanner */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_SCANNER_HPP__ */
