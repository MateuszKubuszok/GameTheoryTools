#ifndef __GTL_SCANNER_HPP__
    #define __GTL_SCANNER_HPP__ 1

    #if ! defined(yyFlexLexerOnce)
        #include <FlexLexer.h>
    #endif /* END ! defined(yyFlexLexerOnce) */

    #undef  YY_DECL
    #define YY_DECL int GTL::Scanner::yylex()

    #include "gtl_parser.hpp"

    namespace GTL {
        class Scanner : public yyFlexLexer {
        public:
            Scanner(std::instream in) :
                yyFlexLexer(in),
                yylval(nullptr)
                {};
                
            int yylex(GTL::Parser::semantic_type *lval) {
                yylval = lval;
                return yylex();
            }
                
        private:
            /**
             * Actual lexer/scanner function.
             *
             * <p>
             * Uses source defined by the constructor.
             * </p>
             *
             * @return value used for communicating with Parser
             */
            int yylex();
            
            /**
             * Field used during token scanning - contains actual value of parsed chain.
             */
            GTL::Parser::semantic_type *yylval;
        }
    }
#endif /* END __GTL_SCANNER_HPP__ */

