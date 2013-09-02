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

    using namespace GT::GTL;

    /**
     * @brief Override default yylex function.
     * 
     * @param yylval  matched content
     * @param driver  driver instance
     * @param scanner scanner instance
     * @return        next found token number
     */
    static int yylex(
        Parser::semantic_type* yylval,
        Scanner&               scanner,
        Driver&                driver
    );



/* Line 286 of lalr1.cc  */
#line 71 "src/gt/gtl/parser.cpp"


/* First part of user declarations.  */


/* Line 293 of lalr1.cc  */
#line 78 "src/gt/gtl/parser.cpp"


#include "parser.hpp"

/* User implementation prologue.  */


/* Line 299 of lalr1.cc  */
#line 87 "src/gt/gtl/parser.cpp"

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
#line 175 "src/gt/gtl/parser.cpp"

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
        case 22: /* "parser_error" */

/* Line 480 of lalr1.cc  */
#line 126 "f_n_b/parser.yy"
	{ if ((yyvaluep->identifier)) { delete((yyvaluep->identifier)); ((yyvaluep->identifier)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 243 "src/gt/gtl/parser.cpp"
	break;
      case 23: /* "identifier" */

/* Line 480 of lalr1.cc  */
#line 126 "f_n_b/parser.yy"
	{ if ((yyvaluep->identifier)) { delete((yyvaluep->identifier)); ((yyvaluep->identifier)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 252 "src/gt/gtl/parser.cpp"
	break;
      case 24: /* "number" */

/* Line 480 of lalr1.cc  */
#line 128 "f_n_b/parser.yy"
	{ if ((yyvaluep->number)) { delete((yyvaluep->number)); ((yyvaluep->number)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 261 "src/gt/gtl/parser.cpp"
	break;
      case 27: /* "definition" */

/* Line 480 of lalr1.cc  */
#line 133 "f_n_b/parser.yy"
	{ if ((yyvaluep->definition)) { delete((yyvaluep->definition)); ((yyvaluep->definition)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 270 "src/gt/gtl/parser.cpp"
	break;
      case 28: /* "query" */

/* Line 480 of lalr1.cc  */
#line 136 "f_n_b/parser.yy"
	{ if ((yyvaluep->query)) { delete((yyvaluep->query)); ((yyvaluep->query)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 279 "src/gt/gtl/parser.cpp"
	break;
      case 29: /* "objects" */

/* Line 480 of lalr1.cc  */
#line 138 "f_n_b/parser.yy"
	{ if ((yyvaluep->objects)) { delete((yyvaluep->objects)); ((yyvaluep->objects)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 288 "src/gt/gtl/parser.cpp"
	break;
      case 30: /* "object" */

/* Line 480 of lalr1.cc  */
#line 137 "f_n_b/parser.yy"
	{ if ((yyvaluep->object)) { delete((yyvaluep->object)); ((yyvaluep->object)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 297 "src/gt/gtl/parser.cpp"
	break;
      case 31: /* "game" */

/* Line 480 of lalr1.cc  */
#line 135 "f_n_b/parser.yy"
	{ if ((yyvaluep->game)) { delete((yyvaluep->game)); ((yyvaluep->game)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 306 "src/gt/gtl/parser.cpp"
	break;
      case 32: /* "details" */

/* Line 480 of lalr1.cc  */
#line 134 "f_n_b/parser.yy"
	{ if ((yyvaluep->details)) { delete((yyvaluep->details)); ((yyvaluep->details)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 315 "src/gt/gtl/parser.cpp"
	break;
      case 33: /* "player" */

/* Line 480 of lalr1.cc  */
#line 141 "f_n_b/parser.yy"
	{ if ((yyvaluep->player)) { delete((yyvaluep->player)); ((yyvaluep->player)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 324 "src/gt/gtl/parser.cpp"
	break;
      case 34: /* "param" */

/* Line 480 of lalr1.cc  */
#line 139 "f_n_b/parser.yy"
	{ if ((yyvaluep->param)) { delete((yyvaluep->param)); ((yyvaluep->param)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 333 "src/gt/gtl/parser.cpp"
	break;
      case 35: /* "params" */

/* Line 480 of lalr1.cc  */
#line 140 "f_n_b/parser.yy"
	{ if ((yyvaluep->params)) { delete((yyvaluep->params)); ((yyvaluep->params)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 342 "src/gt/gtl/parser.cpp"
	break;
      case 36: /* "identifiers" */

/* Line 480 of lalr1.cc  */
#line 127 "f_n_b/parser.yy"
	{ if ((yyvaluep->identifiers)) { delete((yyvaluep->identifiers)); ((yyvaluep->identifiers)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 351 "src/gt/gtl/parser.cpp"
	break;
      case 37: /* "conditions" */

/* Line 480 of lalr1.cc  */
#line 130 "f_n_b/parser.yy"
	{ if ((yyvaluep->conditions)) { delete((yyvaluep->conditions)); ((yyvaluep->conditions)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 360 "src/gt/gtl/parser.cpp"
	break;
      case 38: /* "condition_collection" */

/* Line 480 of lalr1.cc  */
#line 130 "f_n_b/parser.yy"
	{ if ((yyvaluep->conditions)) { delete((yyvaluep->conditions)); ((yyvaluep->conditions)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 369 "src/gt/gtl/parser.cpp"
	break;
      case 39: /* "condition" */

/* Line 480 of lalr1.cc  */
#line 129 "f_n_b/parser.yy"
	{ if ((yyvaluep->condition)) { delete((yyvaluep->condition)); ((yyvaluep->condition)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 378 "src/gt/gtl/parser.cpp"
	break;
      case 40: /* "data" */

/* Line 480 of lalr1.cc  */
#line 132 "f_n_b/parser.yy"
	{ if ((yyvaluep->coordinates)) { delete((yyvaluep->coordinates)); ((yyvaluep->coordinates)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 387 "src/gt/gtl/parser.cpp"
	break;
      case 41: /* "data_coordinates" */

/* Line 480 of lalr1.cc  */
#line 132 "f_n_b/parser.yy"
	{ if ((yyvaluep->coordinates)) { delete((yyvaluep->coordinates)); ((yyvaluep->coordinates)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 396 "src/gt/gtl/parser.cpp"
	break;
      case 42: /* "data_coordinate" */

/* Line 480 of lalr1.cc  */
#line 131 "f_n_b/parser.yy"
	{ if ((yyvaluep->coordinate)) { delete((yyvaluep->coordinate)); ((yyvaluep->coordinate)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 405 "src/gt/gtl/parser.cpp"
	break;
      case 43: /* "coordinates" */

/* Line 480 of lalr1.cc  */
#line 131 "f_n_b/parser.yy"
	{ if ((yyvaluep->coordinate)) { delete((yyvaluep->coordinate)); ((yyvaluep->coordinate)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 414 "src/gt/gtl/parser.cpp"
	break;
      case 44: /* "coordinate" */

/* Line 480 of lalr1.cc  */
#line 131 "f_n_b/parser.yy"
	{ if ((yyvaluep->coordinate)) { delete((yyvaluep->coordinate)); ((yyvaluep->coordinate)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 423 "src/gt/gtl/parser.cpp"
	break;

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
#line 148 "f_n_b/parser.yy"
    { driver.storeDefinedObject((yysemantic_stack_[(2) - (1)].definition)); }
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 149 "f_n_b/parser.yy"
    { driver.executeQuery((yysemantic_stack_[(2) - (1)].query)); }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 154 "f_n_b/parser.yy"
    { (yyval.definition) = driver.createDefinition((yysemantic_stack_[(4) - (2)].identifier), (yysemantic_stack_[(4) - (4)].object)); }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 158 "f_n_b/parser.yy"
    { (yyval.query) = driver.createQuery((yysemantic_stack_[(5) - (2)].identifiers), (yysemantic_stack_[(5) - (4)].objects), (yysemantic_stack_[(5) - (5)].conditions)); }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 164 "f_n_b/parser.yy"
    { (yyval.objects) = driver.addObjectToCollection((yysemantic_stack_[(3) - (3)].object), (yysemantic_stack_[(3) - (1)].objects)); }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 165 "f_n_b/parser.yy"
    { (yyval.objects) = driver.createObjectsCollection((yysemantic_stack_[(1) - (1)].object)); }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 168 "f_n_b/parser.yy"
    { (yyval.object) = driver.convert((yysemantic_stack_[(1) - (1)].game)); }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 169 "f_n_b/parser.yy"
    { (yyval.object) = driver.convert((yysemantic_stack_[(1) - (1)].player)); }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 170 "f_n_b/parser.yy"
    { (yyval.object) = driver.convert((yysemantic_stack_[(1) - (1)].param)); }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 176 "f_n_b/parser.yy"
    { (yyval.game) = driver.createPureGameForDetails((yysemantic_stack_[(3) - (3)].details)); }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 177 "f_n_b/parser.yy"
    { (yyval.game) = driver.createMixedGameForDetails((yysemantic_stack_[(3) - (3)].details)); }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 178 "f_n_b/parser.yy"
    { (yyval.game) = driver.createTreeGameForDetails((yysemantic_stack_[(3) - (3)].details)); }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 182 "f_n_b/parser.yy"
    { (yyval.details) = driver.createDetailsForGame((yysemantic_stack_[(5) - (2)].objects), (yysemantic_stack_[(5) - (5)].coordinates)); }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 188 "f_n_b/parser.yy"
    { (yyval.player) = driver.createPlayerWithStrategies((yysemantic_stack_[(5) - (2)].identifier), (yysemantic_stack_[(5) - (4)].identifiers)); }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 194 "f_n_b/parser.yy"
    { (yyval.param) = driver.getValue((yysemantic_stack_[(1) - (1)].identifier)); }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 195 "f_n_b/parser.yy"
    { (yyval.param) = driver.getValue((yysemantic_stack_[(1) - (1)].number)); }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 199 "f_n_b/parser.yy"
    { (yyval.params) = driver.addParamToCollection((yysemantic_stack_[(3) - (3)].param), (yysemantic_stack_[(3) - (1)].params)); }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 200 "f_n_b/parser.yy"
    { (yyval.params) = driver.createParamsCollection((yysemantic_stack_[(1) - (1)].param)); }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 206 "f_n_b/parser.yy"
    { (yyval.identifiers) = driver.addIdentifierToCollection((yysemantic_stack_[(3) - (3)].identifier), (yysemantic_stack_[(3) - (1)].identifiers)); }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 207 "f_n_b/parser.yy"
    { (yyval.identifiers) = driver.createIdentifiersCollection((yysemantic_stack_[(1) - (1)].identifier)); }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 213 "f_n_b/parser.yy"
    { (yyval.conditions) = (yysemantic_stack_[(1) - (1)].conditions); }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 214 "f_n_b/parser.yy"
    { (yyval.conditions) = driver.emptyConditionsCollection(); }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 218 "f_n_b/parser.yy"
    { (yyval.conditions) = driver.addConditionToCollection((yysemantic_stack_[(3) - (3)].condition), (yysemantic_stack_[(3) - (1)].conditions)); }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 219 "f_n_b/parser.yy"
    { (yyval.conditions) = driver.createConditionsCollection((yysemantic_stack_[(2) - (2)].condition)); }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 223 "f_n_b/parser.yy"
    { (yyval.condition) = driver.createPlayerChoiceCondition((yysemantic_stack_[(4) - (2)].object), (yysemantic_stack_[(4) - (4)].object)); }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 229 "f_n_b/parser.yy"
    { (yyval.coordinates) = (yysemantic_stack_[(1) - (1)].coordinates); }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 233 "f_n_b/parser.yy"
    { (yyval.coordinates) = driver.addCoordinatesToCollection((yysemantic_stack_[(3) - (1)].coordinates), (yysemantic_stack_[(3) - (3)].coordinate)); }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 234 "f_n_b/parser.yy"
    { (yyval.coordinates) = driver.createCoordinatesCollection((yysemantic_stack_[(1) - (1)].coordinate)); }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 238 "f_n_b/parser.yy"
    { (yyval.coordinate) = driver.fillCoordinateWithData((yysemantic_stack_[(5) - (2)].coordinate), (yysemantic_stack_[(5) - (4)].coordinates)); }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 239 "f_n_b/parser.yy"
    { (yyval.coordinate) = driver.fillCoordinateWithData((yysemantic_stack_[(5) - (2)].coordinate), (yysemantic_stack_[(5) - (4)].params)); }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 243 "f_n_b/parser.yy"
    { (yyval.coordinate) = driver.mergeCoordinates((yysemantic_stack_[(3) - (1)].coordinate), (yysemantic_stack_[(3) - (3)].coordinate)); }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 244 "f_n_b/parser.yy"
    { (yyval.coordinate) = (yysemantic_stack_[(1) - (1)].coordinate); }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 248 "f_n_b/parser.yy"
    { (yyval.coordinate) = driver.createCoordinate((yysemantic_stack_[(3) - (1)].identifier), (yysemantic_stack_[(3) - (3)].identifier)); }
    break;



/* Line 690 of lalr1.cc  */
#line 859 "src/gt/gtl/parser.cpp"
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
  const signed char Parser::yypact_ninf_ = -56;
  const signed char
  Parser::yypact_[] =
  {
         3,   -12,    14,   -56,    34,    17,    19,    37,   -56,     8,
     -56,   -56,   -56,    -4,    -4,    20,    21,    36,    39,    40,
     -56,   -56,   -56,   -56,   -56,   -56,    -8,   -56,   -56,    31,
      38,    38,    38,    44,    -4,   -56,    30,    14,    -4,   -56,
     -56,   -56,    -4,   -56,   -56,    44,    -7,    -3,    41,   -56,
     -56,    42,    -4,    35,   -56,    29,   -56,    33,   -56,    43,
      11,   -56,    35,    32,    -9,    29,   -56,   -56,   -56,     6,
       7,   -56,   -56,     9,   -56,   -56
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  Parser::yydefact_[] =
  {
         0,     0,     0,     4,     0,     0,     0,     0,    22,     0,
       1,     2,     3,     0,     0,     0,     0,     0,     0,     0,
      17,    18,     5,     9,    10,    11,    24,     8,    21,     0,
       0,     0,     0,     0,     0,     6,    23,     0,     0,    12,
      13,    14,     0,    26,     7,     0,     0,     0,     0,    25,
      16,     0,     0,     0,    27,     0,    15,    28,    30,     0,
       0,    34,     0,     0,     0,     0,    29,    35,    20,     0,
       0,    33,    32,     0,    31,    19
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  Parser::yypgoto_[] =
  {
       -56,   -56,   -56,   -56,    22,   -13,   -56,     4,   -56,   -55,
     -56,    25,   -56,   -56,    12,   -56,    -6,     1,   -56,    -1
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  Parser::yydefgoto_[] =
  {
        -1,     4,     5,     6,    26,    27,    23,    39,    24,    25,
      69,     9,    35,    36,    43,    56,    57,    58,    60,    61
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char Parser::yytable_ninf_ = -1;
  const unsigned char
  Parser::yytable_[] =
  {
        22,    16,    33,    17,    18,    19,     1,    55,    51,    68,
      50,     7,    34,    15,    20,    21,     2,    34,    75,    20,
      21,    44,    14,    72,    74,     3,    73,    62,    15,    48,
      64,    65,    20,    21,    10,    40,    41,     8,    11,    54,
      12,    13,    30,    28,    29,    31,    32,    37,    38,    42,
      45,    55,    59,    62,    53,    67,    52,    49,    70,     0,
      47,    63,    46,    66,    71
  };

  /* YYCHECK.  */
  const signed char
  Parser::yycheck_[] =
  {
        13,     5,    10,     7,     8,     9,     3,    16,    11,    64,
      17,    23,    20,    20,    23,    24,    13,    20,    73,    23,
      24,    34,    14,    17,    17,    22,    20,    20,    20,    42,
      19,    20,    23,    24,     0,    31,    32,    23,    21,    52,
      21,     4,     6,    23,    23,     6,     6,    16,    10,     5,
      20,    16,    23,    20,    12,    23,    15,    45,    64,    -1,
      38,    18,    37,    62,    65
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,     3,    13,    22,    26,    27,    28,    23,    23,    36,
       0,    21,    21,     4,    14,    20,     5,     7,     8,     9,
      23,    24,    30,    31,    33,    34,    29,    30,    23,    23,
       6,     6,     6,    10,    20,    37,    38,    16,    10,    32,
      32,    32,     5,    39,    30,    20,    36,    29,    30,    39,
      17,    11,    15,    12,    30,    16,    40,    41,    42,    23,
      43,    44,    20,    18,    19,    20,    42,    23,    34,    35,
      41,    44,    17,    20,    17,    34
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  Parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Parser::yyr1_[] =
  {
         0,    25,    26,    26,    26,    27,    28,    29,    29,    30,
      30,    30,    31,    31,    31,    32,    33,    34,    34,    35,
      35,    36,    36,    37,    37,    38,    38,    39,    40,    41,
      41,    42,    42,    43,    43,    44
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     2,     2,     1,     4,     5,     3,     1,     1,
       1,     1,     3,     3,     3,     5,     5,     1,     1,     3,
       1,     3,     1,     1,     0,     3,     2,     4,     1,     3,
       1,     5,     5,     3,     1,     3
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Parser::yytname_[] =
  {
    "$end", "error", "$undefined", "LET", "BE", "PLAYER", "GAME", "PURE",
  "MIXED", "TREE", "WITH", "SUCH", "AS", "FIND", "FOR", "CHOOSE", "LCBR",
  "RCBR", "EQUAL", "COLON", "COMA", "EOC", "parser_error", "identifier",
  "number", "$accept", "statement", "definition", "query", "objects",
  "object", "game", "details", "player", "param", "params", "identifiers",
  "conditions", "condition_collection", "condition", "data",
  "data_coordinates", "data_coordinate", "coordinates", "coordinate", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
        26,     0,    -1,    27,    21,    -1,    28,    21,    -1,    22,
      -1,     3,    23,     4,    30,    -1,    13,    36,    14,    29,
      37,    -1,    29,    20,    30,    -1,    30,    -1,    31,    -1,
      33,    -1,    34,    -1,     7,     6,    32,    -1,     8,     6,
      32,    -1,     9,     6,    32,    -1,    10,    29,    11,    12,
      40,    -1,     5,    23,    16,    36,    17,    -1,    23,    -1,
      24,    -1,    35,    20,    34,    -1,    34,    -1,    36,    20,
      23,    -1,    23,    -1,    38,    -1,    -1,    38,    20,    39,
      -1,    10,    39,    -1,     5,    30,    15,    30,    -1,    41,
      -1,    41,    20,    42,    -1,    42,    -1,    16,    43,    19,
      41,    17,    -1,    16,    43,    19,    35,    17,    -1,    43,
      20,    44,    -1,    44,    -1,    23,    18,    23,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  Parser::yyprhs_[] =
  {
         0,     0,     3,     6,     9,    11,    16,    22,    26,    28,
      30,    32,    34,    38,    42,    46,    52,    58,    60,    62,
      66,    68,    72,    74,    76,    77,    81,    84,    89,    91,
      95,    97,   103,   109,   113,   115
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned char
  Parser::yyrline_[] =
  {
         0,   148,   148,   149,   150,   154,   158,   164,   165,   168,
     169,   170,   176,   177,   178,   182,   188,   194,   195,   199,
     200,   206,   207,   213,   214,   218,   219,   223,   229,   233,
     234,   238,   239,   243,   244,   248
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 64;
  const int Parser::yynnts_ = 20;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 10;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 25;

  const unsigned int Parser::yyuser_token_number_max_ = 279;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1136 of lalr1.cc  */
#line 6 "f_n_b/parser.yy"
} } // GT::GTL

/* Line 1136 of lalr1.cc  */
#line 1313 "src/gt/gtl/parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 251 "f_n_b/parser.yy"


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
    driver.errorInformation(message);
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

