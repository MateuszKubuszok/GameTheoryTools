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
#line 10 "f_n_b/parser.yy"

    /**
     * @brief Parser used for processing input for GTL.
     *
     * @author Mateusz Kubuszok
     */

    /* System libraries */
    #include <iostream> /* Default I/O streams library */
    #include <fstream>  /* File Streams library */
    #include <sstream>  /* StringStream */
    #include <cstdlib>  /* C Standard library */

    /* GTL prototypes */
    #include "gt/gtl/common.hpp"

    /**
     * @brief Macro used to cleanup symbols.
     */
    #define CLEANUP(symbol) (delete(symbol), (symbol)=nullptr)

    using namespace GT::GTL;

    /**
     * @brief Override default yylex function.
     *
     * @param lvalue   matched content
     * @param location current location
     * @param driver   driver instance
     * @param scanner  scanner instance
     * @return         next found token number
     */
    static int yylex(
        Parser::semantic_type* lvalue,
        Parser::location_type* location,
        Scanner&               scanner,
        Driver&                driver
    );



/* Line 286 of lalr1.cc  */
#line 79 "src/gt/gtl/parser.cpp"


/* First part of user declarations.  */


/* Line 293 of lalr1.cc  */
#line 86 "src/gt/gtl/parser.cpp"


#include "parser.hpp"

/* User implementation prologue.  */


/* Line 299 of lalr1.cc  */
#line 95 "src/gt/gtl/parser.cpp"

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
#line 7 "f_n_b/parser.yy"
namespace GT { namespace GTL {

/* Line 382 of lalr1.cc  */
#line 183 "src/gt/gtl/parser.cpp"

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
        case 22: /* "lexer_error" */

/* Line 480 of lalr1.cc  */
#line 141 "f_n_b/parser.yy"
	{ if ((yyvaluep->identifier)) { CLEANUP((yyvaluep->identifier)); } };

/* Line 480 of lalr1.cc  */
#line 251 "src/gt/gtl/parser.cpp"
	break;
      case 23: /* "identifier" */

/* Line 480 of lalr1.cc  */
#line 141 "f_n_b/parser.yy"
	{ if ((yyvaluep->identifier)) { CLEANUP((yyvaluep->identifier)); } };

/* Line 480 of lalr1.cc  */
#line 260 "src/gt/gtl/parser.cpp"
	break;
      case 24: /* "number" */

/* Line 480 of lalr1.cc  */
#line 143 "f_n_b/parser.yy"
	{ if ((yyvaluep->number)) { CLEANUP((yyvaluep->number)); } };

/* Line 480 of lalr1.cc  */
#line 269 "src/gt/gtl/parser.cpp"
	break;
      case 29: /* "definition" */

/* Line 480 of lalr1.cc  */
#line 148 "f_n_b/parser.yy"
	{ if ((yyvaluep->definition)) { CLEANUP((yyvaluep->definition)); } };

/* Line 480 of lalr1.cc  */
#line 278 "src/gt/gtl/parser.cpp"
	break;
      case 30: /* "query" */

/* Line 480 of lalr1.cc  */
#line 151 "f_n_b/parser.yy"
	{ if ((yyvaluep->query)) { CLEANUP((yyvaluep->query)); } };

/* Line 480 of lalr1.cc  */
#line 287 "src/gt/gtl/parser.cpp"
	break;
      case 31: /* "objects" */

/* Line 480 of lalr1.cc  */
#line 153 "f_n_b/parser.yy"
	{ if ((yyvaluep->objects)) { CLEANUP((yyvaluep->objects)); } };

/* Line 480 of lalr1.cc  */
#line 296 "src/gt/gtl/parser.cpp"
	break;
      case 32: /* "object" */

/* Line 480 of lalr1.cc  */
#line 152 "f_n_b/parser.yy"
	{ if ((yyvaluep->object)) { CLEANUP((yyvaluep->object)); } };

/* Line 480 of lalr1.cc  */
#line 305 "src/gt/gtl/parser.cpp"
	break;
      case 33: /* "game" */

/* Line 480 of lalr1.cc  */
#line 150 "f_n_b/parser.yy"
	{ if ((yyvaluep->game)) { CLEANUP((yyvaluep->game)); } };

/* Line 480 of lalr1.cc  */
#line 314 "src/gt/gtl/parser.cpp"
	break;
      case 35: /* "details" */

/* Line 480 of lalr1.cc  */
#line 149 "f_n_b/parser.yy"
	{ if ((yyvaluep->details)) { CLEANUP((yyvaluep->details)); } };

/* Line 480 of lalr1.cc  */
#line 323 "src/gt/gtl/parser.cpp"
	break;
      case 36: /* "player" */

/* Line 480 of lalr1.cc  */
#line 156 "f_n_b/parser.yy"
	{ if ((yyvaluep->player)) { CLEANUP((yyvaluep->player)); } };

/* Line 480 of lalr1.cc  */
#line 332 "src/gt/gtl/parser.cpp"
	break;
      case 37: /* "param" */

/* Line 480 of lalr1.cc  */
#line 154 "f_n_b/parser.yy"
	{ if ((yyvaluep->param)) { CLEANUP((yyvaluep->param)); } };

/* Line 480 of lalr1.cc  */
#line 341 "src/gt/gtl/parser.cpp"
	break;
      case 38: /* "params" */

/* Line 480 of lalr1.cc  */
#line 155 "f_n_b/parser.yy"
	{ if ((yyvaluep->params)) { CLEANUP((yyvaluep->params)); } };

/* Line 480 of lalr1.cc  */
#line 350 "src/gt/gtl/parser.cpp"
	break;
      case 39: /* "identifiers" */

/* Line 480 of lalr1.cc  */
#line 142 "f_n_b/parser.yy"
	{ if ((yyvaluep->identifiers)) { CLEANUP((yyvaluep->identifiers)); } };

/* Line 480 of lalr1.cc  */
#line 359 "src/gt/gtl/parser.cpp"
	break;
      case 40: /* "conditions" */

/* Line 480 of lalr1.cc  */
#line 145 "f_n_b/parser.yy"
	{ if ((yyvaluep->conditions)) { CLEANUP((yyvaluep->conditions)); } };

/* Line 480 of lalr1.cc  */
#line 368 "src/gt/gtl/parser.cpp"
	break;
      case 41: /* "condition_collection" */

/* Line 480 of lalr1.cc  */
#line 145 "f_n_b/parser.yy"
	{ if ((yyvaluep->conditions)) { CLEANUP((yyvaluep->conditions)); } };

/* Line 480 of lalr1.cc  */
#line 377 "src/gt/gtl/parser.cpp"
	break;
      case 42: /* "condition" */

/* Line 480 of lalr1.cc  */
#line 144 "f_n_b/parser.yy"
	{ if ((yyvaluep->condition)) { CLEANUP((yyvaluep->condition)); } };

/* Line 480 of lalr1.cc  */
#line 386 "src/gt/gtl/parser.cpp"
	break;
      case 43: /* "data" */

/* Line 480 of lalr1.cc  */
#line 147 "f_n_b/parser.yy"
	{ if ((yyvaluep->coordinates)) { CLEANUP((yyvaluep->coordinates)); } };

/* Line 480 of lalr1.cc  */
#line 395 "src/gt/gtl/parser.cpp"
	break;
      case 44: /* "data_coordinates" */

/* Line 480 of lalr1.cc  */
#line 147 "f_n_b/parser.yy"
	{ if ((yyvaluep->coordinates)) { CLEANUP((yyvaluep->coordinates)); } };

/* Line 480 of lalr1.cc  */
#line 404 "src/gt/gtl/parser.cpp"
	break;
      case 45: /* "data_coordinate" */

/* Line 480 of lalr1.cc  */
#line 146 "f_n_b/parser.yy"
	{ if ((yyvaluep->coordinate)) { CLEANUP((yyvaluep->coordinate)); } };

/* Line 480 of lalr1.cc  */
#line 413 "src/gt/gtl/parser.cpp"
	break;
      case 46: /* "coordinates" */

/* Line 480 of lalr1.cc  */
#line 146 "f_n_b/parser.yy"
	{ if ((yyvaluep->coordinate)) { CLEANUP((yyvaluep->coordinate)); } };

/* Line 480 of lalr1.cc  */
#line 422 "src/gt/gtl/parser.cpp"
	break;
      case 47: /* "coordinate" */

/* Line 480 of lalr1.cc  */
#line 146 "f_n_b/parser.yy"
	{ if ((yyvaluep->coordinate)) { CLEANUP((yyvaluep->coordinate)); } };

/* Line 480 of lalr1.cc  */
#line 431 "src/gt/gtl/parser.cpp"
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
	yychar = yylex (&yylval, &yylloc, scanner, driver);
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
	  case 6:

/* Line 690 of lalr1.cc  */
#line 178 "f_n_b/parser.yy"
    { driver.forStatement().executeDefinition((yysemantic_stack_[(2) - (1)].definition)); CLEANUP((yysemantic_stack_[(2) - (1)].definition)); }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 179 "f_n_b/parser.yy"
    { driver.forStatement().executeQuery((yysemantic_stack_[(2) - (1)].query)); CLEANUP((yysemantic_stack_[(2) - (1)].query)); }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 184 "f_n_b/parser.yy"
    { (yyval.definition) = driver.forStatement().createDefinition((yylocation_stack_[(4) - (1)]), (yysemantic_stack_[(4) - (2)].identifier), (yysemantic_stack_[(4) - (4)].object)); CLEANUP((yysemantic_stack_[(4) - (2)].identifier)); CLEANUP((yysemantic_stack_[(4) - (4)].object)); }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 188 "f_n_b/parser.yy"
    { (yyval.query) = driver.forStatement().createQuery((yylocation_stack_[(5) - (1)]), (yysemantic_stack_[(5) - (2)].identifiers), (yysemantic_stack_[(5) - (4)].objects), (yysemantic_stack_[(5) - (5)].conditions)); CLEANUP((yysemantic_stack_[(5) - (2)].identifiers)); CLEANUP((yysemantic_stack_[(5) - (4)].objects)); CLEANUP((yysemantic_stack_[(5) - (5)].conditions)); }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 194 "f_n_b/parser.yy"
    { (yyval.objects) = driver.forObjects().insert((yysemantic_stack_[(3) - (3)].object), (yysemantic_stack_[(3) - (1)].objects)); CLEANUP((yysemantic_stack_[(3) - (3)].object)); CLEANUP((yysemantic_stack_[(3) - (1)].objects)); }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 195 "f_n_b/parser.yy"
    { (yyval.objects) = driver.forObjects().create((yysemantic_stack_[(1) - (1)].object)); CLEANUP((yysemantic_stack_[(1) - (1)].object)); }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 199 "f_n_b/parser.yy"
    { (yyval.object) = driver.forValue().toObject((yysemantic_stack_[(1) - (1)].game)); CLEANUP((yysemantic_stack_[(1) - (1)].game)); }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 200 "f_n_b/parser.yy"
    { (yyval.object) = driver.forValue().toObject((yysemantic_stack_[(1) - (1)].player)); CLEANUP((yysemantic_stack_[(1) - (1)].player)); }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 201 "f_n_b/parser.yy"
    { (yyval.object) = driver.forValue().toObject((yysemantic_stack_[(1) - (1)].param)); CLEANUP((yysemantic_stack_[(1) - (1)].param)); }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 207 "f_n_b/parser.yy"
    { (yyval.game) = driver.forGame().createStrategic((yylocation_stack_[(4) - (1)]), (yysemantic_stack_[(4) - (3)].details)); CLEANUP((yysemantic_stack_[(4) - (3)].details)); }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 208 "f_n_b/parser.yy"
    { (yyval.game) = driver.forGame().createTree((yylocation_stack_[(4) - (1)]), (yysemantic_stack_[(4) - (3)].details)); CLEANUP((yysemantic_stack_[(4) - (3)].details)); }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 217 "f_n_b/parser.yy"
    { (yyval.details) = driver.forGame().createDetails((yylocation_stack_[(5) - (1)]), (yysemantic_stack_[(5) - (2)].objects), (yysemantic_stack_[(5) - (5)].coordinates)); CLEANUP((yysemantic_stack_[(5) - (2)].objects)); CLEANUP((yysemantic_stack_[(5) - (5)].coordinates)); }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 223 "f_n_b/parser.yy"
    { (yyval.player) = driver.forGame().createPlayer((yylocation_stack_[(5) - (1)]), (yysemantic_stack_[(5) - (2)].identifier), (yysemantic_stack_[(5) - (4)].identifiers)); CLEANUP((yysemantic_stack_[(5) - (2)].identifier)); CLEANUP((yysemantic_stack_[(5) - (4)].identifiers)); }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 229 "f_n_b/parser.yy"
    { (yyval.param) = driver.forValue().get((yylocation_stack_[(1) - (1)]), (yysemantic_stack_[(1) - (1)].identifier)); CLEANUP((yysemantic_stack_[(1) - (1)].identifier)); }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 230 "f_n_b/parser.yy"
    { (yyval.param) = driver.forValue().get((yylocation_stack_[(1) - (1)]), (yysemantic_stack_[(1) - (1)].number)); CLEANUP((yysemantic_stack_[(1) - (1)].number)); }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 234 "f_n_b/parser.yy"
    { (yyval.params) = driver.forParams().insert((yysemantic_stack_[(3) - (3)].param), (yysemantic_stack_[(3) - (1)].params)); CLEANUP((yysemantic_stack_[(3) - (3)].param)); CLEANUP((yysemantic_stack_[(3) - (1)].params)); }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 235 "f_n_b/parser.yy"
    { (yyval.params) = driver.forParams().create((yysemantic_stack_[(1) - (1)].param)); CLEANUP((yysemantic_stack_[(1) - (1)].param)); }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 241 "f_n_b/parser.yy"
    { (yyval.identifiers) = driver.forIdentifiers().insert((yysemantic_stack_[(3) - (3)].identifier), (yysemantic_stack_[(3) - (1)].identifiers)); CLEANUP((yysemantic_stack_[(3) - (3)].identifier)); CLEANUP((yysemantic_stack_[(3) - (1)].identifiers)); }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 242 "f_n_b/parser.yy"
    { (yyval.identifiers) = driver.forIdentifiers().create((yysemantic_stack_[(1) - (1)].identifier)); CLEANUP((yysemantic_stack_[(1) - (1)].identifier)); }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 248 "f_n_b/parser.yy"
    { (yyval.conditions) = (yysemantic_stack_[(1) - (1)].conditions); }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 249 "f_n_b/parser.yy"
    { (yyval.conditions) = driver.forConditions().empty(); }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 253 "f_n_b/parser.yy"
    { (yyval.conditions) = driver.forConditions().insert((yysemantic_stack_[(3) - (3)].condition), (yysemantic_stack_[(3) - (1)].conditions)); CLEANUP((yysemantic_stack_[(3) - (3)].condition)); CLEANUP((yysemantic_stack_[(3) - (1)].conditions)); }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 254 "f_n_b/parser.yy"
    { (yyval.conditions) = driver.forConditions().create((yysemantic_stack_[(2) - (2)].condition)); CLEANUP((yysemantic_stack_[(2) - (2)].condition)); }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 258 "f_n_b/parser.yy"
    { (yyval.condition) = driver.forCondition().playerChoosed((yylocation_stack_[(4) - (1)]), (yysemantic_stack_[(4) - (2)].object), (yysemantic_stack_[(4) - (4)].object)); CLEANUP((yysemantic_stack_[(4) - (2)].object)); CLEANUP((yysemantic_stack_[(4) - (4)].object)); }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 264 "f_n_b/parser.yy"
    { (yyval.coordinates) = (yysemantic_stack_[(1) - (1)].coordinates); }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 268 "f_n_b/parser.yy"
    { (yyval.coordinates) = driver.forCoordinates().insert((yysemantic_stack_[(3) - (3)].coordinate), (yysemantic_stack_[(3) - (1)].coordinates)); CLEANUP((yysemantic_stack_[(3) - (3)].coordinate)); CLEANUP((yysemantic_stack_[(3) - (1)].coordinates)); }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 269 "f_n_b/parser.yy"
    { (yyval.coordinates) = driver.forCoordinates().create((yysemantic_stack_[(1) - (1)].coordinate)); CLEANUP((yysemantic_stack_[(1) - (1)].coordinate)); }
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 273 "f_n_b/parser.yy"
    { (yyval.coordinate) = driver.forCoordinate().fillWithData((yylocation_stack_[(5) - (1)]), (yysemantic_stack_[(5) - (2)].coordinate), (yysemantic_stack_[(5) - (4)].coordinates)); CLEANUP((yysemantic_stack_[(5) - (2)].coordinate)); CLEANUP((yysemantic_stack_[(5) - (4)].coordinates)); }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 274 "f_n_b/parser.yy"
    { (yyval.coordinate) = driver.forCoordinate().fillWithData((yylocation_stack_[(5) - (1)]), (yysemantic_stack_[(5) - (2)].coordinate), (yysemantic_stack_[(5) - (4)].params)); CLEANUP((yysemantic_stack_[(5) - (2)].coordinate)); CLEANUP((yysemantic_stack_[(5) - (4)].params)); }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 278 "f_n_b/parser.yy"
    { (yyval.coordinate) = driver.forCoordinate().merge((yylocation_stack_[(3) - (1)]), (yysemantic_stack_[(3) - (1)].coordinate), (yysemantic_stack_[(3) - (3)].coordinate)); CLEANUP((yysemantic_stack_[(3) - (1)].coordinate)); CLEANUP((yysemantic_stack_[(3) - (3)].coordinate)); }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 279 "f_n_b/parser.yy"
    { (yyval.coordinate) = (yysemantic_stack_[(1) - (1)].coordinate); }
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 283 "f_n_b/parser.yy"
    { (yyval.coordinate) = driver.forCoordinate().create((yylocation_stack_[(3) - (1)]), (yysemantic_stack_[(3) - (1)].identifier), (yysemantic_stack_[(3) - (3)].identifier)); CLEANUP((yysemantic_stack_[(3) - (1)].identifier)); CLEANUP((yysemantic_stack_[(3) - (3)].identifier)); }
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 290 "f_n_b/parser.yy"
    {
        std::string message = std::string() + "not recognized symbols: \"" + (**(yysemantic_stack_[(1) - (1)].identifier)) + "\"";
        error((yylocation_stack_[(1) - (1)]), message);
        CLEANUP((yysemantic_stack_[(1) - (1)].identifier));
    }
    break;



/* Line 690 of lalr1.cc  */
#line 871 "src/gt/gtl/parser.cpp"
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
  const signed char Parser::yypact_ninf_ = -69;
  const signed char
  Parser::yypact_[] =
  {
         1,   -69,   -69,     2,    19,   -69,    37,     5,   -69,    22,
      23,   -69,    41,   -69,    14,   -69,   -69,   -69,   -69,   -69,
       8,     8,    24,    25,    40,    43,   -69,   -69,   -69,   -69,
     -69,   -69,     0,   -69,   -69,    34,    42,    42,    47,     8,
     -69,    33,    19,     8,    44,    44,     8,   -69,   -69,    47,
       4,    -3,   -69,   -69,   -69,    39,   -69,   -69,    46,     8,
      45,   -69,    32,   -69,    38,   -69,    48,    -9,   -69,    45,
      36,     6,    32,   -69,   -69,   -69,    16,    18,   -69,   -69,
      17,   -69,   -69
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  Parser::yydefact_[] =
  {
         0,     3,    41,     0,     0,    42,     0,     0,     5,     0,
       0,     8,     0,    27,     0,     1,     2,     4,     6,     7,
       0,     0,     0,     0,     0,     0,    22,    23,     9,    13,
      14,    15,    29,    12,    26,     0,     0,     0,     0,     0,
      10,    28,     0,     0,    18,    18,     0,    31,    11,     0,
       0,     0,    19,    16,    17,     0,    30,    21,     0,     0,
       0,    32,     0,    20,    33,    35,     0,     0,    39,     0,
       0,     0,     0,    34,    40,    25,     0,     0,    38,    37,
       0,    36,    24
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  Parser::yypgoto_[] =
  {
       -69,   -69,   -69,    53,   -69,   -69,    20,   -20,   -69,    26,
      27,   -69,   -68,   -69,    28,   -69,   -69,    13,   -69,    -6,
      -2,   -69,    -4,   -69
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  Parser::yydefgoto_[] =
  {
        -1,     6,     7,     8,     9,    10,    32,    33,    29,    53,
      44,    30,    31,    76,    14,    40,    41,    47,    63,    64,
      65,    67,    68,    11
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char Parser::yytable_ninf_ = -1;
  const unsigned char
  Parser::yytable_[] =
  {
        28,     1,     2,    75,     3,    16,     2,    58,     3,    38,
      71,    72,    82,    23,     4,    24,    25,    39,     4,    48,
      39,    57,    62,     5,    22,    12,    55,     5,    21,    26,
      27,    26,    27,    79,    22,    81,    80,    15,    69,    61,
      26,    27,    13,    18,    19,    20,    36,    34,    35,    37,
      42,    43,    46,    49,    59,    66,    52,    60,    69,    74,
      17,    62,    56,    51,    45,    77,    70,    73,    78,     0,
      50,    54
  };

  /* YYCHECK.  */
  const signed char
  Parser::yycheck_[] =
  {
        20,     0,     1,    71,     3,     0,     1,    10,     3,     9,
      19,    20,    80,     5,    13,     7,     8,    20,    13,    39,
      20,    17,    16,    22,    20,    23,    46,    22,    14,    23,
      24,    23,    24,    17,    20,    17,    20,     0,    20,    59,
      23,    24,    23,    21,    21,     4,     6,    23,    23,     6,
      16,     9,     5,    20,    15,    23,    12,    11,    20,    23,
       7,    16,    49,    43,    37,    71,    18,    69,    72,    -1,
      42,    45
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,     0,     1,     3,    13,    22,    26,    27,    28,    29,
      30,    48,    23,    23,    39,     0,     0,    28,    21,    21,
       4,    14,    20,     5,     7,     8,    23,    24,    32,    33,
      36,    37,    31,    32,    23,    23,     6,     6,     9,    20,
      40,    41,    16,     9,    35,    35,     5,    42,    32,    20,
      39,    31,    12,    34,    34,    32,    42,    17,    10,    15,
      11,    32,    16,    43,    44,    45,    23,    46,    47,    20,
      18,    19,    20,    45,    23,    37,    38,    44,    47,    17,
      20,    17,    37
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
         0,    25,    26,    26,    27,    27,    28,    28,    28,    29,
      30,    31,    31,    32,    32,    32,    33,    33,    34,    34,
      35,    36,    37,    37,    38,    38,    39,    39,    40,    40,
      41,    41,    42,    43,    44,    44,    45,    45,    46,    46,
      47,    48,    48
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     2,     1,     2,     1,     2,     2,     1,     4,
       5,     3,     1,     1,     1,     1,     4,     4,     0,     1,
       5,     5,     1,     1,     3,     1,     3,     1,     1,     0,
       3,     2,     4,     1,     3,     1,     5,     5,     3,     1,
       3,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Parser::yytname_[] =
  {
    "TERMINATE", "error", "$undefined", "LET", "BE", "PLAYER", "GAME",
  "STRATEGIC", "TREE", "WITH", "SUCH", "AS", "END", "FIND", "FOR",
  "CHOOSE", "LCBR", "RCBR", "EQUAL", "COLON", "COMA", "EOC", "lexer_error",
  "identifier", "number", "$accept", "program", "statements", "statement",
  "definition", "query", "objects", "object", "game", "game_end",
  "details", "player", "param", "params", "identifiers", "conditions",
  "condition_collection", "condition", "data", "data_coordinates",
  "data_coordinate", "coordinates", "coordinate", "parser_error", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
        26,     0,    -1,    27,     0,    -1,     0,    -1,    27,    28,
      -1,    28,    -1,    29,    21,    -1,    30,    21,    -1,    48,
      -1,     3,    23,     4,    32,    -1,    13,    39,    14,    31,
      40,    -1,    31,    20,    32,    -1,    32,    -1,    33,    -1,
      36,    -1,    37,    -1,     7,     6,    35,    34,    -1,     8,
       6,    35,    34,    -1,    -1,    12,    -1,     9,    31,    10,
      11,    43,    -1,     5,    23,    16,    39,    17,    -1,    23,
      -1,    24,    -1,    38,    20,    37,    -1,    37,    -1,    39,
      20,    23,    -1,    23,    -1,    41,    -1,    -1,    41,    20,
      42,    -1,     9,    42,    -1,     5,    32,    15,    32,    -1,
      44,    -1,    44,    20,    45,    -1,    45,    -1,    16,    46,
      19,    44,    17,    -1,    16,    46,    19,    38,    17,    -1,
      46,    20,    47,    -1,    47,    -1,    23,    18,    23,    -1,
       1,    -1,    22,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  Parser::yyprhs_[] =
  {
         0,     0,     3,     6,     8,    11,    13,    16,    19,    21,
      26,    32,    36,    38,    40,    42,    44,    49,    54,    55,
      57,    63,    69,    71,    73,    77,    79,    83,    85,    87,
      88,    92,    95,   100,   102,   106,   108,   114,   120,   124,
     126,   130,   132
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   166,   166,   167,   173,   174,   178,   179,   180,   184,
     188,   194,   195,   199,   200,   201,   207,   208,   211,   213,
     217,   223,   229,   230,   234,   235,   241,   242,   248,   249,
     253,   254,   258,   264,   268,   269,   273,   274,   278,   279,
     283,   289,   290
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
  const int Parser::yylast_ = 71;
  const int Parser::yynnts_ = 24;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 15;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 25;

  const unsigned int Parser::yyuser_token_number_max_ = 279;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1136 of lalr1.cc  */
#line 7 "f_n_b/parser.yy"
} } // GT::GTL

/* Line 1136 of lalr1.cc  */
#line 1339 "src/gt/gtl/parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 297 "f_n_b/parser.yy"


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
    std::stringstream builder;
    builder << "Error:" << std::endl
            << '\t' << message << std::endl
            << "\tat line \""
            << location
            << "\"" << std::endl;
    std::string errorMessage(builder.str());
    driver.showError(errorMessage);
}

/**
 * @brief Include for scanner.yylex.
 *
 * @param lvalue  matched content
 * @param scanner scanner instance
 * @param driver  driver instance
 */
static int yylex(
    Parser::semantic_type* lvalue,
    Parser::location_type* location,
    Scanner&               scanner,
    Driver&                driver
) {
    return scanner.lex(lvalue);
}

