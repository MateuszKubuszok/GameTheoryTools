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
        case 21: /* "lexer_error" */

/* Line 480 of lalr1.cc  */
#line 127 "f_n_b/parser.yy"
	{ if ((yyvaluep->identifier)) { delete((yyvaluep->identifier)); ((yyvaluep->identifier)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 243 "src/gt/gtl/parser.cpp"
	break;
      case 22: /* "identifier" */

/* Line 480 of lalr1.cc  */
#line 127 "f_n_b/parser.yy"
	{ if ((yyvaluep->identifier)) { delete((yyvaluep->identifier)); ((yyvaluep->identifier)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 252 "src/gt/gtl/parser.cpp"
	break;
      case 23: /* "number" */

/* Line 480 of lalr1.cc  */
#line 129 "f_n_b/parser.yy"
	{ if ((yyvaluep->number)) { delete((yyvaluep->number)); ((yyvaluep->number)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 261 "src/gt/gtl/parser.cpp"
	break;
      case 29: /* "definition" */

/* Line 480 of lalr1.cc  */
#line 134 "f_n_b/parser.yy"
	{ if ((yyvaluep->definition)) { delete((yyvaluep->definition)); ((yyvaluep->definition)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 270 "src/gt/gtl/parser.cpp"
	break;
      case 30: /* "query" */

/* Line 480 of lalr1.cc  */
#line 137 "f_n_b/parser.yy"
	{ if ((yyvaluep->query)) { delete((yyvaluep->query)); ((yyvaluep->query)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 279 "src/gt/gtl/parser.cpp"
	break;
      case 31: /* "objects" */

/* Line 480 of lalr1.cc  */
#line 139 "f_n_b/parser.yy"
	{ if ((yyvaluep->objects)) { delete((yyvaluep->objects)); ((yyvaluep->objects)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 288 "src/gt/gtl/parser.cpp"
	break;
      case 32: /* "object" */

/* Line 480 of lalr1.cc  */
#line 138 "f_n_b/parser.yy"
	{ if ((yyvaluep->object)) { delete((yyvaluep->object)); ((yyvaluep->object)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 297 "src/gt/gtl/parser.cpp"
	break;
      case 33: /* "game" */

/* Line 480 of lalr1.cc  */
#line 136 "f_n_b/parser.yy"
	{ if ((yyvaluep->game)) { delete((yyvaluep->game)); ((yyvaluep->game)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 306 "src/gt/gtl/parser.cpp"
	break;
      case 34: /* "details" */

/* Line 480 of lalr1.cc  */
#line 135 "f_n_b/parser.yy"
	{ if ((yyvaluep->details)) { delete((yyvaluep->details)); ((yyvaluep->details)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 315 "src/gt/gtl/parser.cpp"
	break;
      case 35: /* "player" */

/* Line 480 of lalr1.cc  */
#line 142 "f_n_b/parser.yy"
	{ if ((yyvaluep->player)) { delete((yyvaluep->player)); ((yyvaluep->player)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 324 "src/gt/gtl/parser.cpp"
	break;
      case 36: /* "param" */

/* Line 480 of lalr1.cc  */
#line 140 "f_n_b/parser.yy"
	{ if ((yyvaluep->param)) { delete((yyvaluep->param)); ((yyvaluep->param)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 333 "src/gt/gtl/parser.cpp"
	break;
      case 37: /* "params" */

/* Line 480 of lalr1.cc  */
#line 141 "f_n_b/parser.yy"
	{ if ((yyvaluep->params)) { delete((yyvaluep->params)); ((yyvaluep->params)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 342 "src/gt/gtl/parser.cpp"
	break;
      case 38: /* "identifiers" */

/* Line 480 of lalr1.cc  */
#line 128 "f_n_b/parser.yy"
	{ if ((yyvaluep->identifiers)) { delete((yyvaluep->identifiers)); ((yyvaluep->identifiers)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 351 "src/gt/gtl/parser.cpp"
	break;
      case 39: /* "conditions" */

/* Line 480 of lalr1.cc  */
#line 131 "f_n_b/parser.yy"
	{ if ((yyvaluep->conditions)) { delete((yyvaluep->conditions)); ((yyvaluep->conditions)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 360 "src/gt/gtl/parser.cpp"
	break;
      case 40: /* "condition_collection" */

/* Line 480 of lalr1.cc  */
#line 131 "f_n_b/parser.yy"
	{ if ((yyvaluep->conditions)) { delete((yyvaluep->conditions)); ((yyvaluep->conditions)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 369 "src/gt/gtl/parser.cpp"
	break;
      case 41: /* "condition" */

/* Line 480 of lalr1.cc  */
#line 130 "f_n_b/parser.yy"
	{ if ((yyvaluep->condition)) { delete((yyvaluep->condition)); ((yyvaluep->condition)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 378 "src/gt/gtl/parser.cpp"
	break;
      case 42: /* "data" */

/* Line 480 of lalr1.cc  */
#line 133 "f_n_b/parser.yy"
	{ if ((yyvaluep->coordinates)) { delete((yyvaluep->coordinates)); ((yyvaluep->coordinates)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 387 "src/gt/gtl/parser.cpp"
	break;
      case 43: /* "data_coordinates" */

/* Line 480 of lalr1.cc  */
#line 133 "f_n_b/parser.yy"
	{ if ((yyvaluep->coordinates)) { delete((yyvaluep->coordinates)); ((yyvaluep->coordinates)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 396 "src/gt/gtl/parser.cpp"
	break;
      case 44: /* "data_coordinate" */

/* Line 480 of lalr1.cc  */
#line 132 "f_n_b/parser.yy"
	{ if ((yyvaluep->coordinate)) { delete((yyvaluep->coordinate)); ((yyvaluep->coordinate)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 405 "src/gt/gtl/parser.cpp"
	break;
      case 45: /* "coordinates" */

/* Line 480 of lalr1.cc  */
#line 132 "f_n_b/parser.yy"
	{ if ((yyvaluep->coordinate)) { delete((yyvaluep->coordinate)); ((yyvaluep->coordinate)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 414 "src/gt/gtl/parser.cpp"
	break;
      case 46: /* "coordinate" */

/* Line 480 of lalr1.cc  */
#line 132 "f_n_b/parser.yy"
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
	  case 5:

/* Line 690 of lalr1.cc  */
#line 160 "f_n_b/parser.yy"
    { driver.forStatement().executeDefinition((yysemantic_stack_[(2) - (1)].definition)); }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 161 "f_n_b/parser.yy"
    { driver.forStatement().executeQuery((yysemantic_stack_[(2) - (1)].query)); }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 162 "f_n_b/parser.yy"
    {}
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 166 "f_n_b/parser.yy"
    { (yyval.definition) = driver.forStatement().createDefinition((yysemantic_stack_[(4) - (2)].identifier), (yysemantic_stack_[(4) - (4)].object)); }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 170 "f_n_b/parser.yy"
    { (yyval.query) = driver.forStatement().createQuery((yysemantic_stack_[(5) - (2)].identifiers), (yysemantic_stack_[(5) - (4)].objects), (yysemantic_stack_[(5) - (5)].conditions)); }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 176 "f_n_b/parser.yy"
    { (yyval.objects) = driver.forObjects().insert((yysemantic_stack_[(3) - (3)].object), (yysemantic_stack_[(3) - (1)].objects)); }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 177 "f_n_b/parser.yy"
    { (yyval.objects) = driver.forObjects().create((yysemantic_stack_[(1) - (1)].object)); }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 180 "f_n_b/parser.yy"
    { (yyval.object) = driver.forValue().toObject((yysemantic_stack_[(1) - (1)].game)); }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 181 "f_n_b/parser.yy"
    { (yyval.object) = driver.forValue().toObject((yysemantic_stack_[(1) - (1)].player)); }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 182 "f_n_b/parser.yy"
    { (yyval.object) = driver.forValue().toObject((yysemantic_stack_[(1) - (1)].param)); }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 188 "f_n_b/parser.yy"
    { (yyval.game) = driver.forGame().createStrategic((yysemantic_stack_[(3) - (3)].details)); }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 189 "f_n_b/parser.yy"
    { (yyval.game) = driver.forGame().createTree((yysemantic_stack_[(3) - (3)].details)); }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 193 "f_n_b/parser.yy"
    { (yyval.details) = driver.forGame().createDetails((yysemantic_stack_[(5) - (2)].objects), (yysemantic_stack_[(5) - (5)].coordinates)); }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 199 "f_n_b/parser.yy"
    { (yyval.player) = driver.forGame().createPlayer((yysemantic_stack_[(5) - (2)].identifier), (yysemantic_stack_[(5) - (4)].identifiers)); }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 205 "f_n_b/parser.yy"
    { (yyval.param) = driver.forValue().get((yysemantic_stack_[(1) - (1)].identifier)); }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 206 "f_n_b/parser.yy"
    { (yyval.param) = driver.forValue().get((yysemantic_stack_[(1) - (1)].number)); }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 210 "f_n_b/parser.yy"
    { (yyval.params) = driver.forParams().insert((yysemantic_stack_[(3) - (3)].param), (yysemantic_stack_[(3) - (1)].params)); }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 211 "f_n_b/parser.yy"
    { (yyval.params) = driver.forParams().create((yysemantic_stack_[(1) - (1)].param)); }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 217 "f_n_b/parser.yy"
    { (yyval.identifiers) = driver.forIdentifiers().insert((yysemantic_stack_[(3) - (3)].identifier), (yysemantic_stack_[(3) - (1)].identifiers)); }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 218 "f_n_b/parser.yy"
    { (yyval.identifiers) = driver.forIdentifiers().create((yysemantic_stack_[(1) - (1)].identifier)); }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 224 "f_n_b/parser.yy"
    { (yyval.conditions) = (yysemantic_stack_[(1) - (1)].conditions); }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 225 "f_n_b/parser.yy"
    { (yyval.conditions) = driver.forConditions().empty(); }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 229 "f_n_b/parser.yy"
    { (yyval.conditions) = driver.forConditions().insert((yysemantic_stack_[(3) - (3)].condition), (yysemantic_stack_[(3) - (1)].conditions)); }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 230 "f_n_b/parser.yy"
    { (yyval.conditions) = driver.forConditions().create((yysemantic_stack_[(2) - (2)].condition)); }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 234 "f_n_b/parser.yy"
    { (yyval.condition) = driver.forCondition().playerChoosed((yysemantic_stack_[(4) - (2)].object), (yysemantic_stack_[(4) - (4)].object)); }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 240 "f_n_b/parser.yy"
    { (yyval.coordinates) = (yysemantic_stack_[(1) - (1)].coordinates); }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 244 "f_n_b/parser.yy"
    { (yyval.coordinates) = driver.forCoordinates().insert((yysemantic_stack_[(3) - (3)].coordinate), (yysemantic_stack_[(3) - (1)].coordinates)); }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 245 "f_n_b/parser.yy"
    { (yyval.coordinates) = driver.forCoordinates().create((yysemantic_stack_[(1) - (1)].coordinate)); }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 249 "f_n_b/parser.yy"
    { (yyval.coordinate) = driver.forCoordinate().fillWithData((yysemantic_stack_[(5) - (2)].coordinate), (yysemantic_stack_[(5) - (4)].coordinates)); }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 250 "f_n_b/parser.yy"
    { (yyval.coordinate) = driver.forCoordinate().fillWithData((yysemantic_stack_[(5) - (2)].coordinate), (yysemantic_stack_[(5) - (4)].params)); }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 254 "f_n_b/parser.yy"
    { (yyval.coordinate) = driver.forCoordinate().merge((yysemantic_stack_[(3) - (1)].coordinate), (yysemantic_stack_[(3) - (3)].coordinate)); }
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 255 "f_n_b/parser.yy"
    { (yyval.coordinate) = (yysemantic_stack_[(1) - (1)].coordinate); }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 259 "f_n_b/parser.yy"
    { (yyval.coordinate) = driver.forCoordinate().create((yysemantic_stack_[(3) - (1)].identifier), (yysemantic_stack_[(3) - (3)].identifier)); }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 265 "f_n_b/parser.yy"
    { /* TODO: Passing errors */ }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 266 "f_n_b/parser.yy"
    { /* TODO: Passing errors */ }
    break;



/* Line 690 of lalr1.cc  */
#line 873 "src/gt/gtl/parser.cpp"
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
  const signed char Parser::yypact_ninf_ = -59;
  const signed char
  Parser::yypact_[] =
  {
       -59,    18,     0,   -59,   -59,   -16,    19,   -59,   -59,   -59,
       2,    22,   -59,    33,   -59,    12,   -59,   -59,     6,     6,
      21,    23,    -2,    32,   -59,   -59,   -59,   -59,   -59,   -59,
      -4,   -59,   -59,    29,    37,    37,    42,     6,   -59,    30,
      19,     6,   -59,   -59,     6,   -59,   -59,    42,     4,    -3,
      34,   -59,   -59,    39,     6,    36,   -59,    31,   -59,    35,
     -59,    38,    15,   -59,    36,    40,   -13,    31,   -59,   -59,
     -59,    11,    16,   -59,   -59,    17,   -59,   -59
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  Parser::yydefact_[] =
  {
         4,     0,     0,     1,    38,     0,     0,    39,     2,     3,
       0,     0,     7,     0,    24,     0,     5,     6,     0,     0,
       0,     0,     0,     0,    19,    20,     8,    12,    13,    14,
      26,    11,    23,     0,     0,     0,     0,     0,     9,    25,
       0,     0,    15,    16,     0,    28,    10,     0,     0,     0,
       0,    27,    18,     0,     0,     0,    29,     0,    17,    30,
      32,     0,     0,    36,     0,     0,     0,     0,    31,    37,
      22,     0,     0,    35,    34,     0,    33,    21
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  Parser::yypgoto_[] =
  {
       -59,   -59,   -59,   -59,   -59,   -59,    20,   -18,   -59,    24,
     -59,   -58,   -59,    25,   -59,   -59,     5,   -59,   -10,    -7,
     -59,    -9,   -59
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  Parser::yydefgoto_[] =
  {
        -1,     1,     2,     9,    10,    11,    30,    31,    27,    42,
      28,    29,    71,    15,    38,    39,    45,    58,    59,    60,
      62,    63,    12
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char Parser::yytable_ninf_ = -1;
  const unsigned char
  Parser::yytable_[] =
  {
        26,     4,    57,     5,    34,    36,    13,    53,    70,    24,
      25,    21,     6,    22,    23,    37,    37,    77,     3,    46,
      52,     7,    16,    20,     8,    19,    50,    74,    24,    25,
      75,    20,    76,    66,    67,    64,    56,    18,    35,    24,
      25,    14,    17,    32,    40,    33,    41,    44,    54,    47,
      55,    57,    51,    61,    64,    65,    72,    68,    73,    43,
       0,    49,    69,     0,     0,    48
  };

  /* YYCHECK.  */
  const signed char
  Parser::yycheck_[] =
  {
        18,     1,    15,     3,     6,     9,    22,    10,    66,    22,
      23,     5,    12,     7,     8,    19,    19,    75,     0,    37,
      16,    21,    20,    19,    24,    13,    44,    16,    22,    23,
      19,    19,    16,    18,    19,    19,    54,     4,     6,    22,
      23,    22,    20,    22,    15,    22,     9,     5,    14,    19,
      11,    15,    47,    22,    19,    17,    66,    64,    67,    35,
      -1,    41,    22,    -1,    -1,    40
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,    26,    27,     0,     1,     3,    12,    21,    24,    28,
      29,    30,    47,    22,    22,    38,    20,    20,     4,    13,
      19,     5,     7,     8,    22,    23,    32,    33,    35,    36,
      31,    32,    22,    22,     6,     6,     9,    19,    39,    40,
      15,     9,    34,    34,     5,    41,    32,    19,    38,    31,
      32,    41,    16,    10,    14,    11,    32,    15,    42,    43,
      44,    22,    45,    46,    19,    17,    18,    19,    44,    22,
      36,    37,    43,    46,    16,    19,    16,    36
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
         0,    25,    26,    27,    27,    28,    28,    28,    29,    30,
      31,    31,    32,    32,    32,    33,    33,    34,    35,    36,
      36,    37,    37,    38,    38,    39,    39,    40,    40,    41,
      42,    43,    43,    44,    44,    45,    45,    46,    47,    47
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     2,     2,     0,     2,     2,     1,     4,     5,
       3,     1,     1,     1,     1,     3,     3,     5,     5,     1,
       1,     3,     1,     3,     1,     1,     0,     3,     2,     4,
       1,     3,     1,     5,     5,     3,     1,     3,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Parser::yytname_[] =
  {
    "$end", "error", "$undefined", "LET", "BE", "PLAYER", "GAME",
  "STRATEGIC", "TREE", "WITH", "SUCH", "AS", "FIND", "FOR", "CHOOSE",
  "LCBR", "RCBR", "EQUAL", "COLON", "COMA", "EOC", "lexer_error",
  "identifier", "number", "TERMINATE", "$accept", "program", "statements",
  "statement", "definition", "query", "objects", "object", "game",
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
        26,     0,    -1,    27,    24,    -1,    27,    28,    -1,    -1,
      29,    20,    -1,    30,    20,    -1,    47,    -1,     3,    22,
       4,    32,    -1,    12,    38,    13,    31,    39,    -1,    31,
      19,    32,    -1,    32,    -1,    33,    -1,    35,    -1,    36,
      -1,     7,     6,    34,    -1,     8,     6,    34,    -1,     9,
      31,    10,    11,    42,    -1,     5,    22,    15,    38,    16,
      -1,    22,    -1,    23,    -1,    37,    19,    36,    -1,    36,
      -1,    38,    19,    22,    -1,    22,    -1,    40,    -1,    -1,
      40,    19,    41,    -1,     9,    41,    -1,     5,    32,    14,
      32,    -1,    43,    -1,    43,    19,    44,    -1,    44,    -1,
      15,    45,    18,    43,    16,    -1,    15,    45,    18,    37,
      16,    -1,    45,    19,    46,    -1,    46,    -1,    22,    17,
      22,    -1,     1,    -1,    21,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  Parser::yyprhs_[] =
  {
         0,     0,     3,     6,     9,    10,    13,    16,    18,    23,
      29,    33,    35,    37,    39,    41,    45,    49,    55,    61,
      63,    65,    69,    71,    75,    77,    79,    80,    84,    87,
      92,    94,    98,   100,   106,   112,   116,   118,   122,   124
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   149,   149,   153,   154,   160,   161,   162,   166,   170,
     176,   177,   180,   181,   182,   188,   189,   193,   199,   205,
     206,   210,   211,   217,   218,   224,   225,   229,   230,   234,
     240,   244,   245,   249,   250,   254,   255,   259,   265,   266
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
  const int Parser::yylast_ = 65;
  const int Parser::yynnts_ = 23;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 3;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 25;

  const unsigned int Parser::yyuser_token_number_max_ = 279;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1136 of lalr1.cc  */
#line 6 "f_n_b/parser.yy"
} } // GT::GTL

/* Line 1136 of lalr1.cc  */
#line 1331 "src/gt/gtl/parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 269 "f_n_b/parser.yy"


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
    driver.showError(message);
}

/**
 * @brief Include for scanner.yylex.
 *
 * @param lval    matched content
 * @param scanner scanner instance
 * @param driver  driver instance
 */
static int yylex(
    Parser::semantic_type* lval,
    Scanner&               scanner,
    Driver&                driver
) {
    return scanner.lex(lval);
}

