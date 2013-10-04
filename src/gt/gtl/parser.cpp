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
        case 22: /* "lexer_error" */

/* Line 480 of lalr1.cc  */
#line 128 "f_n_b/parser.yy"
	{ if ((yyvaluep->identifier)) { delete((yyvaluep->identifier)); ((yyvaluep->identifier)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 243 "src/gt/gtl/parser.cpp"
	break;
      case 23: /* "identifier" */

/* Line 480 of lalr1.cc  */
#line 128 "f_n_b/parser.yy"
	{ if ((yyvaluep->identifier)) { delete((yyvaluep->identifier)); ((yyvaluep->identifier)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 252 "src/gt/gtl/parser.cpp"
	break;
      case 24: /* "number" */

/* Line 480 of lalr1.cc  */
#line 130 "f_n_b/parser.yy"
	{ if ((yyvaluep->number)) { delete((yyvaluep->number)); ((yyvaluep->number)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 261 "src/gt/gtl/parser.cpp"
	break;
      case 30: /* "definition" */

/* Line 480 of lalr1.cc  */
#line 135 "f_n_b/parser.yy"
	{ if ((yyvaluep->definition)) { delete((yyvaluep->definition)); ((yyvaluep->definition)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 270 "src/gt/gtl/parser.cpp"
	break;
      case 31: /* "query" */

/* Line 480 of lalr1.cc  */
#line 138 "f_n_b/parser.yy"
	{ if ((yyvaluep->query)) { delete((yyvaluep->query)); ((yyvaluep->query)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 279 "src/gt/gtl/parser.cpp"
	break;
      case 32: /* "objects" */

/* Line 480 of lalr1.cc  */
#line 140 "f_n_b/parser.yy"
	{ if ((yyvaluep->objects)) { delete((yyvaluep->objects)); ((yyvaluep->objects)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 288 "src/gt/gtl/parser.cpp"
	break;
      case 33: /* "object" */

/* Line 480 of lalr1.cc  */
#line 139 "f_n_b/parser.yy"
	{ if ((yyvaluep->object)) { delete((yyvaluep->object)); ((yyvaluep->object)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 297 "src/gt/gtl/parser.cpp"
	break;
      case 34: /* "game" */

/* Line 480 of lalr1.cc  */
#line 137 "f_n_b/parser.yy"
	{ if ((yyvaluep->game)) { delete((yyvaluep->game)); ((yyvaluep->game)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 306 "src/gt/gtl/parser.cpp"
	break;
      case 35: /* "details" */

/* Line 480 of lalr1.cc  */
#line 136 "f_n_b/parser.yy"
	{ if ((yyvaluep->details)) { delete((yyvaluep->details)); ((yyvaluep->details)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 315 "src/gt/gtl/parser.cpp"
	break;
      case 36: /* "player" */

/* Line 480 of lalr1.cc  */
#line 143 "f_n_b/parser.yy"
	{ if ((yyvaluep->player)) { delete((yyvaluep->player)); ((yyvaluep->player)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 324 "src/gt/gtl/parser.cpp"
	break;
      case 37: /* "param" */

/* Line 480 of lalr1.cc  */
#line 141 "f_n_b/parser.yy"
	{ if ((yyvaluep->param)) { delete((yyvaluep->param)); ((yyvaluep->param)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 333 "src/gt/gtl/parser.cpp"
	break;
      case 38: /* "params" */

/* Line 480 of lalr1.cc  */
#line 142 "f_n_b/parser.yy"
	{ if ((yyvaluep->params)) { delete((yyvaluep->params)); ((yyvaluep->params)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 342 "src/gt/gtl/parser.cpp"
	break;
      case 39: /* "identifiers" */

/* Line 480 of lalr1.cc  */
#line 129 "f_n_b/parser.yy"
	{ if ((yyvaluep->identifiers)) { delete((yyvaluep->identifiers)); ((yyvaluep->identifiers)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 351 "src/gt/gtl/parser.cpp"
	break;
      case 40: /* "conditions" */

/* Line 480 of lalr1.cc  */
#line 132 "f_n_b/parser.yy"
	{ if ((yyvaluep->conditions)) { delete((yyvaluep->conditions)); ((yyvaluep->conditions)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 360 "src/gt/gtl/parser.cpp"
	break;
      case 41: /* "condition_collection" */

/* Line 480 of lalr1.cc  */
#line 132 "f_n_b/parser.yy"
	{ if ((yyvaluep->conditions)) { delete((yyvaluep->conditions)); ((yyvaluep->conditions)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 369 "src/gt/gtl/parser.cpp"
	break;
      case 42: /* "condition" */

/* Line 480 of lalr1.cc  */
#line 131 "f_n_b/parser.yy"
	{ if ((yyvaluep->condition)) { delete((yyvaluep->condition)); ((yyvaluep->condition)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 378 "src/gt/gtl/parser.cpp"
	break;
      case 43: /* "data" */

/* Line 480 of lalr1.cc  */
#line 134 "f_n_b/parser.yy"
	{ if ((yyvaluep->coordinates)) { delete((yyvaluep->coordinates)); ((yyvaluep->coordinates)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 387 "src/gt/gtl/parser.cpp"
	break;
      case 44: /* "data_coordinates" */

/* Line 480 of lalr1.cc  */
#line 134 "f_n_b/parser.yy"
	{ if ((yyvaluep->coordinates)) { delete((yyvaluep->coordinates)); ((yyvaluep->coordinates)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 396 "src/gt/gtl/parser.cpp"
	break;
      case 45: /* "data_coordinate" */

/* Line 480 of lalr1.cc  */
#line 133 "f_n_b/parser.yy"
	{ if ((yyvaluep->coordinate)) { delete((yyvaluep->coordinate)); ((yyvaluep->coordinate)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 405 "src/gt/gtl/parser.cpp"
	break;
      case 46: /* "coordinates" */

/* Line 480 of lalr1.cc  */
#line 133 "f_n_b/parser.yy"
	{ if ((yyvaluep->coordinate)) { delete((yyvaluep->coordinate)); ((yyvaluep->coordinate)) = 0; } };

/* Line 480 of lalr1.cc  */
#line 414 "src/gt/gtl/parser.cpp"
	break;
      case 47: /* "coordinate" */

/* Line 480 of lalr1.cc  */
#line 133 "f_n_b/parser.yy"
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
#line 161 "f_n_b/parser.yy"
    { driver.forStatement().executeDefinition((yysemantic_stack_[(2) - (1)].definition)); }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 162 "f_n_b/parser.yy"
    { driver.forStatement().executeQuery((yysemantic_stack_[(2) - (1)].query)); }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 163 "f_n_b/parser.yy"
    {}
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 167 "f_n_b/parser.yy"
    { (yyval.definition) = driver.forStatement().createDefinition((yysemantic_stack_[(4) - (2)].identifier), (yysemantic_stack_[(4) - (4)].object)); }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 171 "f_n_b/parser.yy"
    { (yyval.query) = driver.forStatement().createQuery((yysemantic_stack_[(5) - (2)].identifiers), (yysemantic_stack_[(5) - (4)].objects), (yysemantic_stack_[(5) - (5)].conditions)); }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 177 "f_n_b/parser.yy"
    { (yyval.objects) = driver.forObjects().insert((yysemantic_stack_[(3) - (3)].object), (yysemantic_stack_[(3) - (1)].objects)); }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 178 "f_n_b/parser.yy"
    { (yyval.objects) = driver.forObjects().create((yysemantic_stack_[(1) - (1)].object)); }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 181 "f_n_b/parser.yy"
    { (yyval.object) = driver.forValue().toObject((yysemantic_stack_[(1) - (1)].game)); }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 182 "f_n_b/parser.yy"
    { (yyval.object) = driver.forValue().toObject((yysemantic_stack_[(1) - (1)].player)); }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 183 "f_n_b/parser.yy"
    { (yyval.object) = driver.forValue().toObject((yysemantic_stack_[(1) - (1)].param)); }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 189 "f_n_b/parser.yy"
    { (yyval.game) = driver.forGame().createPure((yysemantic_stack_[(3) - (3)].details)); }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 190 "f_n_b/parser.yy"
    { (yyval.game) = driver.forGame().createMixed((yysemantic_stack_[(3) - (3)].details)); }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 191 "f_n_b/parser.yy"
    { (yyval.game) = driver.forGame().createTree((yysemantic_stack_[(3) - (3)].details)); }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 195 "f_n_b/parser.yy"
    { (yyval.details) = driver.forGame().createDetails((yysemantic_stack_[(5) - (2)].objects), (yysemantic_stack_[(5) - (5)].coordinates)); }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 201 "f_n_b/parser.yy"
    { (yyval.player) = driver.forGame().createPlayer((yysemantic_stack_[(5) - (2)].identifier), (yysemantic_stack_[(5) - (4)].identifiers)); }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 207 "f_n_b/parser.yy"
    { (yyval.param) = driver.forValue().get((yysemantic_stack_[(1) - (1)].identifier)); }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 208 "f_n_b/parser.yy"
    { (yyval.param) = driver.forValue().get((yysemantic_stack_[(1) - (1)].number)); }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 212 "f_n_b/parser.yy"
    { (yyval.params) = driver.forParams().insert((yysemantic_stack_[(3) - (3)].param), (yysemantic_stack_[(3) - (1)].params)); }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 213 "f_n_b/parser.yy"
    { (yyval.params) = driver.forParams().create((yysemantic_stack_[(1) - (1)].param)); }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 219 "f_n_b/parser.yy"
    { (yyval.identifiers) = driver.forIdentifiers().insert((yysemantic_stack_[(3) - (3)].identifier), (yysemantic_stack_[(3) - (1)].identifiers)); }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 220 "f_n_b/parser.yy"
    { (yyval.identifiers) = driver.forIdentifiers().create((yysemantic_stack_[(1) - (1)].identifier)); }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 226 "f_n_b/parser.yy"
    { (yyval.conditions) = (yysemantic_stack_[(1) - (1)].conditions); }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 227 "f_n_b/parser.yy"
    { (yyval.conditions) = driver.forConditions().empty(); }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 231 "f_n_b/parser.yy"
    { (yyval.conditions) = driver.forConditions().insert((yysemantic_stack_[(3) - (3)].condition), (yysemantic_stack_[(3) - (1)].conditions)); }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 232 "f_n_b/parser.yy"
    { (yyval.conditions) = driver.forConditions().create((yysemantic_stack_[(2) - (2)].condition)); }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 236 "f_n_b/parser.yy"
    { (yyval.condition) = driver.forCondition().playerChoosed((yysemantic_stack_[(4) - (2)].object), (yysemantic_stack_[(4) - (4)].object)); }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 242 "f_n_b/parser.yy"
    { (yyval.coordinates) = (yysemantic_stack_[(1) - (1)].coordinates); }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 246 "f_n_b/parser.yy"
    { (yyval.coordinates) = driver.forCoordinates().insert((yysemantic_stack_[(3) - (3)].coordinate), (yysemantic_stack_[(3) - (1)].coordinates)); }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 247 "f_n_b/parser.yy"
    { (yyval.coordinates) = driver.forCoordinates().create((yysemantic_stack_[(1) - (1)].coordinate)); }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 251 "f_n_b/parser.yy"
    { (yyval.coordinate) = driver.forCoordinate().fillWithData((yysemantic_stack_[(5) - (2)].coordinate), (yysemantic_stack_[(5) - (4)].coordinates)); }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 252 "f_n_b/parser.yy"
    { (yyval.coordinate) = driver.forCoordinate().fillWithData((yysemantic_stack_[(5) - (2)].coordinate), (yysemantic_stack_[(5) - (4)].params)); }
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 256 "f_n_b/parser.yy"
    { (yyval.coordinate) = driver.forCoordinate().merge((yysemantic_stack_[(3) - (1)].coordinate), (yysemantic_stack_[(3) - (3)].coordinate)); }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 257 "f_n_b/parser.yy"
    { (yyval.coordinate) = (yysemantic_stack_[(1) - (1)].coordinate); }
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 261 "f_n_b/parser.yy"
    { (yyval.coordinate) = driver.forCoordinate().create((yysemantic_stack_[(3) - (1)].identifier), (yysemantic_stack_[(3) - (3)].identifier)); }
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 267 "f_n_b/parser.yy"
    {}
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 268 "f_n_b/parser.yy"
    {}
    break;



/* Line 690 of lalr1.cc  */
#line 880 "src/gt/gtl/parser.cpp"
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
  const signed char Parser::yypact_ninf_ = -63;
  const signed char
  Parser::yypact_[] =
  {
       -63,     9,     0,   -63,   -63,    11,    17,   -63,   -63,   -63,
      22,    23,   -63,    13,   -63,     4,   -63,   -63,     3,     3,
      24,    25,    39,    40,    43,   -63,   -63,   -63,   -63,   -63,
     -63,    -6,   -63,   -63,    12,    41,    41,    41,    45,     3,
     -63,    32,    17,     3,   -63,   -63,   -63,     3,   -63,   -63,
      45,   -15,    -5,    38,   -63,   -63,    42,     3,    44,   -63,
      33,   -63,    35,   -63,    46,    18,   -63,    44,    34,     7,
      33,   -63,   -63,   -63,    15,    16,   -63,   -63,    -4,   -63,
     -63
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  Parser::yydefact_[] =
  {
         4,     0,     0,     1,    39,     0,     0,    40,     2,     3,
       0,     0,     7,     0,    25,     0,     5,     6,     0,     0,
       0,     0,     0,     0,     0,    20,    21,     8,    12,    13,
      14,    27,    11,    24,     0,     0,     0,     0,     0,     0,
       9,    26,     0,     0,    15,    16,    17,     0,    29,    10,
       0,     0,     0,     0,    28,    19,     0,     0,     0,    30,
       0,    18,    31,    33,     0,     0,    37,     0,     0,     0,
       0,    32,    38,    23,     0,     0,    36,    35,     0,    34,
      22
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  Parser::yypgoto_[] =
  {
       -63,   -63,   -63,   -63,   -63,   -63,    19,   -18,   -63,     5,
     -63,   -62,   -63,    21,   -63,   -63,     8,   -63,   -10,    -2,
     -63,    -9,   -63
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  Parser::yydefgoto_[] =
  {
        -1,     1,     2,     9,    10,    11,    31,    32,    28,    44,
      29,    30,    74,    15,    40,    41,    48,    61,    62,    63,
      65,    66,    12
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char Parser::yytable_ninf_ = -1;
  const unsigned char
  Parser::yytable_[] =
  {
        27,     4,    55,     5,    38,    20,    56,    73,    21,     3,
      22,    23,    24,     6,    39,    39,    80,    18,    19,    25,
      26,    49,     7,    60,    20,     8,    25,    26,    42,    53,
      25,    26,    77,    79,    13,    78,    67,    69,    70,    59,
      14,    45,    46,    16,    17,    35,    36,    33,    34,    37,
      47,    43,    50,    57,    58,    67,    64,    72,    54,    75,
      60,    76,    52,    51,    68,    71
  };

  /* YYCHECK.  */
  const unsigned char
  Parser::yycheck_[] =
  {
        18,     1,    17,     3,    10,    20,    11,    69,     5,     0,
       7,     8,     9,    13,    20,    20,    78,     4,    14,    23,
      24,    39,    22,    16,    20,    25,    23,    24,    16,    47,
      23,    24,    17,    17,    23,    20,    20,    19,    20,    57,
      23,    36,    37,    21,    21,     6,     6,    23,    23,     6,
       5,    10,    20,    15,    12,    20,    23,    23,    50,    69,
      16,    70,    43,    42,    18,    67
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,    27,    28,     0,     1,     3,    13,    22,    25,    29,
      30,    31,    48,    23,    23,    39,    21,    21,     4,    14,
      20,     5,     7,     8,     9,    23,    24,    33,    34,    36,
      37,    32,    33,    23,    23,     6,     6,     6,    10,    20,
      40,    41,    16,    10,    35,    35,    35,     5,    42,    33,
      20,    39,    32,    33,    42,    17,    11,    15,    12,    33,
      16,    43,    44,    45,    23,    46,    47,    20,    18,    19,
      20,    45,    23,    37,    38,    44,    47,    17,    20,    17,
      37
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  Parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Parser::yyr1_[] =
  {
         0,    26,    27,    28,    28,    29,    29,    29,    30,    31,
      32,    32,    33,    33,    33,    34,    34,    34,    35,    36,
      37,    37,    38,    38,    39,    39,    40,    40,    41,    41,
      42,    43,    44,    44,    45,    45,    46,    46,    47,    48,
      48
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     2,     2,     0,     2,     2,     1,     4,     5,
       3,     1,     1,     1,     1,     3,     3,     3,     5,     5,
       1,     1,     3,     1,     3,     1,     1,     0,     3,     2,
       4,     1,     3,     1,     5,     5,     3,     1,     3,     1,
       1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Parser::yytname_[] =
  {
    "$end", "error", "$undefined", "LET", "BE", "PLAYER", "GAME", "PURE",
  "MIXED", "TREE", "WITH", "SUCH", "AS", "FIND", "FOR", "CHOOSE", "LCBR",
  "RCBR", "EQUAL", "COLON", "COMA", "EOC", "lexer_error", "identifier",
  "number", "TERMINATE", "$accept", "program", "statements", "statement",
  "definition", "query", "objects", "object", "game", "details", "player",
  "param", "params", "identifiers", "conditions", "condition_collection",
  "condition", "data", "data_coordinates", "data_coordinate",
  "coordinates", "coordinate", "parser_error", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
        27,     0,    -1,    28,    25,    -1,    28,    29,    -1,    -1,
      30,    21,    -1,    31,    21,    -1,    48,    -1,     3,    23,
       4,    33,    -1,    13,    39,    14,    32,    40,    -1,    32,
      20,    33,    -1,    33,    -1,    34,    -1,    36,    -1,    37,
      -1,     7,     6,    35,    -1,     8,     6,    35,    -1,     9,
       6,    35,    -1,    10,    32,    11,    12,    43,    -1,     5,
      23,    16,    39,    17,    -1,    23,    -1,    24,    -1,    38,
      20,    37,    -1,    37,    -1,    39,    20,    23,    -1,    23,
      -1,    41,    -1,    -1,    41,    20,    42,    -1,    10,    42,
      -1,     5,    33,    15,    33,    -1,    44,    -1,    44,    20,
      45,    -1,    45,    -1,    16,    46,    19,    44,    17,    -1,
      16,    46,    19,    38,    17,    -1,    46,    20,    47,    -1,
      47,    -1,    23,    18,    23,    -1,     1,    -1,    22,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  Parser::yyprhs_[] =
  {
         0,     0,     3,     6,     9,    10,    13,    16,    18,    23,
      29,    33,    35,    37,    39,    41,    45,    49,    53,    59,
      65,    67,    69,    73,    75,    79,    81,    83,    84,    88,
      91,    96,    98,   102,   104,   110,   116,   120,   122,   126,
     128
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   150,   150,   154,   155,   161,   162,   163,   167,   171,
     177,   178,   181,   182,   183,   189,   190,   191,   195,   201,
     207,   208,   212,   213,   219,   220,   226,   227,   231,   232,
     236,   242,   246,   247,   251,   252,   256,   257,   261,   267,
     268
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25
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
  const int Parser::yyntokens_ = 26;

  const unsigned int Parser::yyuser_token_number_max_ = 280;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1136 of lalr1.cc  */
#line 6 "f_n_b/parser.yy"
} } // GT::GTL

/* Line 1136 of lalr1.cc  */
#line 1346 "src/gt/gtl/parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 271 "f_n_b/parser.yy"


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

