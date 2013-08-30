/* A Bison parser, made by GNU Bison 2.5.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */
/* "%code top" blocks.  */

/* Line 286 of lalr1.cc  */
#line 9 "f_n_b/parser.yy"

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
        Parser::semantic_type* yylval,
        Scanner&               scanner,
        Driver&                driver
    );



/* Line 286 of lalr1.cc  */
#line 69 "src/gt/gtl/parser.cpp"


/* First part of user declarations.  */


/* Line 293 of lalr1.cc  */
#line 76 "src/gt/gtl/parser.cpp"


#include "parser.hpp"

/* User implementation prologue.  */


/* Line 299 of lalr1.cc  */
#line 85 "src/gt/gtl/parser.cpp"

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                               \
 do                                                                    \
   if (N)                                                              \
     {                                                                 \
       (Current).begin = YYRHSLOC (Rhs, 1).begin;                      \
       (Current).end   = YYRHSLOC (Rhs, N).end;                        \
     }                                                                 \
   else                                                                \
     {                                                                 \
       (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;        \
     }                                                                 \
 while (false)
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


/* Line 382 of lalr1.cc  */
#line 6 "f_n_b/parser.yy"
namespace GT { namespace GTL {

/* Line 382 of lalr1.cc  */
#line 173 "src/gt/gtl/parser.cpp"

  /// Build a parser object.
  Parser::Parser (Scanner& scanner_yyarg, Driver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {
  }

  Parser::~Parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  Parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  Parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  Parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  Parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, scanner, driver);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yy_table_value_is_error_ (yyn))
	  goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:

/* Line 690 of lalr1.cc  */
#line 127 "f_n_b/parser.yy"
    { driver.storeDefinedObject((yysemantic_stack_[(2) - (1)].definition)); }
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 128 "f_n_b/parser.yy"
    { driver.executeQuery((yysemantic_stack_[(2) - (1)].query)); }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 132 "f_n_b/parser.yy"
    { (yyval.definition) = driver.createDefinition((yysemantic_stack_[(4) - (4)].object), (yysemantic_stack_[(4) - (2)].identifier)); }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 136 "f_n_b/parser.yy"
    { (yyval.query) = driver.createQuery((yysemantic_stack_[(5) - (2)].identifiers), (yysemantic_stack_[(5) - (4)].objects), (yysemantic_stack_[(5) - (5)].conditions)); }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 142 "f_n_b/parser.yy"
    { (yyval.objects) = driver.addObjectToCollection((yysemantic_stack_[(3) - (3)].object), (yysemantic_stack_[(3) - (1)].objects)); }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 143 "f_n_b/parser.yy"
    { (yyval.objects) = driver.createObjectsCollection((yysemantic_stack_[(1) - (1)].object)); }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 146 "f_n_b/parser.yy"
    { (yyval.object) = (yysemantic_stack_[(1) - (1)].game); }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 147 "f_n_b/parser.yy"
    { (yyval.object) = (yysemantic_stack_[(1) - (1)].player); }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 148 "f_n_b/parser.yy"
    { (yyval.object) = (yysemantic_stack_[(1) - (1)].param); }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 154 "f_n_b/parser.yy"
    { (yyval.game) = driver.createPureGameForDetails((yysemantic_stack_[(3) - (3)].details)); }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 155 "f_n_b/parser.yy"
    { (yyval.game) = driver.createMixedGameForDetails((yysemantic_stack_[(3) - (3)].details)); }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 156 "f_n_b/parser.yy"
    { (yyval.game) = driver.createTreeGameForDetails((yysemantic_stack_[(3) - (3)].details)); }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 160 "f_n_b/parser.yy"
    { (yyval.details) = driver.createDetailsForGame((yysemantic_stack_[(5) - (2)].objects), (yysemantic_stack_[(5) - (5)].data)); }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 166 "f_n_b/parser.yy"
    { (yyval.player) = driver.createPlayerWithStrategies((yysemantic_stack_[(5) - (2)].identifier), (yysemantic_stack_[(5) - (4)].objects)); }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 172 "f_n_b/parser.yy"
    { (yyval.param) = driver.getValueForIdentifier((yysemantic_stack_[(1) - (1)].identifier)); }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 173 "f_n_b/parser.yy"
    { (yyval.param) = driver.getValueForNumber((yysemantic_stack_[(1) - (1)].number)); }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 177 "f_n_b/parser.yy"
    { (yyval.params) = driver.addParamToCollection((yysemantic_stack_[(3) - (3)].param), (yysemantic_stack_[(3) - (1)].params)); }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 178 "f_n_b/parser.yy"
    { (yyval.params) = driver.createParams((yysemantic_stack_[(1) - (1)].param)); }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 184 "f_n_b/parser.yy"
    { (yyval.identifiers) = driver.addIdentifierToCollection((yysemantic_stack_[(3) - (3)].identifier), (yysemantic_stack_[(3) - (1)].identifiers)); }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 185 "f_n_b/parser.yy"
    { (yyval.identifiers) = driver.createIdentifiersCollection((yysemantic_stack_[(1) - (1)].identifier)); }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 191 "f_n_b/parser.yy"
    { (yyval.conditions) = (yysemantic_stack_[(1) - (1)].conditions); }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 192 "f_n_b/parser.yy"
    { (yyval.conditions) = driver.emptyConditionCollection(); }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 196 "f_n_b/parser.yy"
    { (yyval.conditions) = driver.addConditionToCollection((yysemantic_stack_[(3) - (3)].condition), (yysemantic_stack_[(3) - (1)].conditions)); }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 197 "f_n_b/parser.yy"
    { (yyval.conditions) = driver.createConditionsCollection((yysemantic_stack_[(2) - (2)].condition)); }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 201 "f_n_b/parser.yy"
    { (yyval.condition) = driver.createPlayerChoiceCondition((yysemantic_stack_[(4) - (2)].object), (yysemantic_stack_[(4) - (4)].object)); }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 207 "f_n_b/parser.yy"
    { (yyval.data) = driver.createData((yysemantic_stack_[(1) - (1)].coordinate)); }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 211 "f_n_b/parser.yy"
    { (yyval.coordinate) = driver.addCoordinatesToCollection((yysemantic_stack_[(3) - (1)].coordinate), (yysemantic_stack_[(3) - (3)].coordinate)); }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 212 "f_n_b/parser.yy"
    { (yyval.coordinate) = driver.createCoordinatesCollection((yysemantic_stack_[(1) - (1)].coordinate)); }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 216 "f_n_b/parser.yy"
    { (yyval.coordinate) = driver.fillCoordinatesWithData((yysemantic_stack_[(5) - (2)].coordinate), (yysemantic_stack_[(5) - (4)].coordinate)); }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 217 "f_n_b/parser.yy"
    { (yyval.coordinate) = driver.fillCoordinatesWithData((yysemantic_stack_[(5) - (2)].coordinate), (yysemantic_stack_[(5) - (4)].params)); }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 221 "f_n_b/parser.yy"
    { (yyval.coordinate) = driver.mergeCoordinates((yysemantic_stack_[(3) - (1)].coordinate), (yysemantic_stack_[(3) - (3)].coordinate)); }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 222 "f_n_b/parser.yy"
    { (yyval.coordinate) = (yysemantic_stack_[(1) - (1)].coordinate); }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 226 "f_n_b/parser.yy"
    { (yyval.coordinate) = driver.createCoordinate((yysemantic_stack_[(3) - (1)].identifier), (yysemantic_stack_[(3) - (3)].identifier)); }
    break;



/* Line 690 of lalr1.cc  */
#line 668 "src/gt/gtl/parser.cpp"
	default:
          break;
      }
    /* User semantic actions sometimes alter yychar, and that requires
       that yytoken be updated with the new translation.  We take the
       approach of translating immediately before every use of yytoken.
       One alternative is translating here after every semantic action,
       but that translation would be missed if the semantic action
       invokes YYABORT, YYACCEPT, or YYERROR immediately after altering
       yychar.  In the case of YYABORT or YYACCEPT, an incorrect
       destructor might then be invoked immediately.  In the case of
       YYERROR, subsequent parser actions might lead to an incorrect
       destructor call or verbose syntax error message before the
       lookahead is translated.  */
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yytranslate_ (yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	if (yychar == yyempty_)
	  yytoken = yyempty_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[1] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[1] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (!yy_pact_value_is_default_ (yyn))
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      {
        /* Make sure we have latest lookahead translation.  See comments
           at user semantic actions for why this is necessary.  */
        yytoken = yytranslate_ (yychar);
        yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval,
                     &yylloc);
      }

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (int, int)
  {
    return YY_("syntax error");
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char Parser::yypact_ninf_ = -53;
  const signed char
  Parser::yypact_[] =
  {
        -1,   -13,     4,    38,    19,    20,    39,   -53,    -6,   -53,
     -53,   -53,    -4,    -4,    22,    23,    36,    40,    41,   -53,
     -53,   -53,   -53,   -53,   -53,    -3,   -53,   -53,    32,    42,
      42,    42,    44,    -4,   -53,    30,    -4,    -4,   -53,   -53,
     -53,    -4,   -53,   -53,    44,    -7,    -5,    43,   -53,   -53,
      45,    -4,    35,   -53,    31,   -53,    34,   -53,    37,    11,
     -53,    35,    46,     0,    31,   -53,   -53,   -53,     7,     8,
     -53,   -53,    10,   -53,   -53
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  Parser::yydefact_[] =
  {
         0,     0,     0,     0,     0,     0,     0,    21,     0,     1,
       2,     3,     0,     0,     0,     0,     0,     0,     0,    16,
      17,     4,     8,     9,    10,    23,     7,    20,     0,     0,
       0,     0,     0,     0,     5,    22,     0,     0,    11,    12,
      13,     0,    25,     6,     0,     0,     0,     0,    24,    15,
       0,     0,     0,    26,     0,    14,    27,    29,     0,     0,
      33,     0,     0,     0,     0,    28,    34,    19,     0,     0,
      32,    31,     0,    30,    18
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  Parser::yypgoto_[] =
  {
       -53,   -53,   -53,   -53,    -2,   -12,   -53,     6,   -53,   -52,
     -53,   -53,   -53,   -53,    12,   -53,     1,     2,   -53,     3
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  Parser::yydefgoto_[] =
  {
        -1,     3,     4,     5,    25,    26,    22,    38,    23,    24,
      68,     8,    34,    35,    42,    55,    56,    57,    59,    60
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char Parser::yytable_ninf_ = -1;
  const unsigned char
  Parser::yytable_[] =
  {
        21,    15,     1,    16,    17,    18,    50,    32,    13,     6,
      49,    67,     2,    33,    14,    33,    54,    33,    19,    20,
      74,    43,    19,    20,    71,    73,     7,    72,    61,    47,
      63,    64,    19,    20,    45,    46,    39,    40,     9,    53,
      10,    11,    29,    12,    27,    28,    30,    31,    36,    41,
      44,    54,    37,    58,    61,    62,    48,    52,    51,     0,
       0,     0,     0,    65,    69,     0,     0,    70,    66
  };

  /* YYCHECK.  */
  const signed char
  Parser::yycheck_[] =
  {
        12,     5,     3,     7,     8,     9,    11,    10,    14,    22,
      17,    63,    13,    20,    20,    20,    16,    20,    22,    23,
      72,    33,    22,    23,    17,    17,    22,    20,    20,    41,
      19,    20,    22,    23,    36,    37,    30,    31,     0,    51,
      21,    21,     6,     4,    22,    22,     6,     6,    16,     5,
      20,    16,    10,    22,    20,    18,    44,    12,    15,    -1,
      -1,    -1,    -1,    61,    63,    -1,    -1,    64,    22
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,     3,    13,    25,    26,    27,    22,    22,    35,     0,
      21,    21,     4,    14,    20,     5,     7,     8,     9,    22,
      23,    29,    30,    32,    33,    28,    29,    22,    22,     6,
       6,     6,    10,    20,    36,    37,    16,    10,    31,    31,
      31,     5,    38,    29,    20,    28,    28,    29,    38,    17,
      11,    15,    12,    29,    16,    39,    40,    41,    22,    42,
      43,    20,    18,    19,    20,    41,    22,    33,    34,    40,
      43,    17,    20,    17,    33
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  Parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Parser::yyr1_[] =
  {
         0,    24,    25,    25,    26,    27,    28,    28,    29,    29,
      29,    30,    30,    30,    31,    32,    33,    33,    34,    34,
      35,    35,    36,    36,    37,    37,    38,    39,    40,    40,
      41,    41,    42,    42,    43
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     2,     2,     4,     5,     3,     1,     1,     1,
       1,     3,     3,     3,     5,     5,     1,     1,     3,     1,
       3,     1,     1,     0,     3,     2,     4,     1,     3,     1,
       5,     5,     3,     1,     3
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Parser::yytname_[] =
  {
    "$end", "error", "$undefined", "LET", "BE", "PLAYER", "GAME", "PURE",
  "MIXED", "TREE", "WITH", "SUCH", "AS", "FIND", "FOR", "CHOOSE", "LCBR",
  "RCBR", "EQUAL", "COLON", "COMA", "EOC", "identifier", "number",
  "$accept", "statement", "definition", "query", "objects", "object",
  "game", "details", "player", "param", "params", "identifiers",
  "conditions", "condition_collection", "condition", "data",
  "data_coordinates", "data_coordinate", "coordinates", "coordinate", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
        25,     0,    -1,    26,    21,    -1,    27,    21,    -1,     3,
      22,     4,    29,    -1,    13,    35,    14,    28,    36,    -1,
      28,    20,    29,    -1,    29,    -1,    30,    -1,    32,    -1,
      33,    -1,     7,     6,    31,    -1,     8,     6,    31,    -1,
       9,     6,    31,    -1,    10,    28,    11,    12,    39,    -1,
       5,    22,    16,    28,    17,    -1,    22,    -1,    23,    -1,
      34,    20,    33,    -1,    33,    -1,    35,    20,    22,    -1,
      22,    -1,    37,    -1,    -1,    37,    20,    38,    -1,    10,
      38,    -1,     5,    29,    15,    29,    -1,    40,    -1,    40,
      20,    41,    -1,    41,    -1,    16,    42,    19,    40,    17,
      -1,    16,    42,    19,    34,    17,    -1,    42,    20,    43,
      -1,    43,    -1,    22,    18,    22,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  Parser::yyprhs_[] =
  {
         0,     0,     3,     6,     9,    14,    20,    24,    26,    28,
      30,    32,    36,    40,    44,    50,    56,    58,    60,    64,
      66,    70,    72,    74,    75,    79,    82,    87,    89,    93,
      95,   101,   107,   111,   113
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned char
  Parser::yyrline_[] =
  {
         0,   127,   127,   128,   132,   136,   142,   143,   146,   147,
     148,   154,   155,   156,   160,   166,   172,   173,   177,   178,
     184,   185,   191,   192,   196,   197,   201,   207,   211,   212,
     216,   217,   221,   222,   226
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 68;
  const int Parser::yynnts_ = 20;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 9;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 24;

  const unsigned int Parser::yyuser_token_number_max_ = 278;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1136 of lalr1.cc  */
#line 6 "f_n_b/parser.yy"
} } // GT::GTL

/* Line 1136 of lalr1.cc  */
#line 1122 "src/gt/gtl/parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 229 "f_n_b/parser.yy"


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
    Parser::semantic_type* yylval,
    Scanner&               scanner,
    Driver&                driver
) {
    return scanner.yylex(yylval);
}

