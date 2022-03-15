// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison GLR parsers in C

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// C++ GLR parser skeleton written by Valentin Tolmer.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr2.cc"



/* Substitute the variable and function names.  */
#define yyparse parseparse
#define yylex   parselex
#define yyerror parseerror
#define yydebug parsedebug



# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parsetiger.hh"

namespace
{
  /* Default (constant) value used for initialization for null
     right-hand sides.  Unlike the standard yacc.c template, here we set
     the default value of $$ to a zeroed-out value.  Since the default
     value is undefined, this behavior is technically correct.  */
  parse::parser::value_type yyval_default;
}


// Unqualified %code blocks.
#line 112 "parse/parsetiger.yy"

# include <parse/scantiger.hh>
# include <parse/tweast.hh>
# include <misc/separator.hh>
# include <misc/symbol.hh>
# include <ast/all.hh>
# include <ast/libast.hh>
# include <parse/tiger-driver.hh>

  namespace
  {

    /// Get the metavar from the specified map.
    template <typename T>
    T*
    metavar(parse::TigerParser& tp, unsigned key)
    {
      parse::Tweast* input = tp.input_;
      return input->template take<T>(key);
    }

  }

  /// Use our local scanner object.
  inline
  ::parse::parser::symbol_type
  parselex(parse::TigerParser& tp)
  {
    return tp.scanner_->parselex(tp);
  }

#line 116 "parse/parsetiger.cc"


#include <cstdio>
#include <cstdlib>

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(Env) setjmp (Env)
/* Pacify Clang and ICC.  */
# define YYLONGJMP(Env, Val)                    \
 do {                                           \
   longjmp (Env, Val);                          \
   YYASSERT (0);                                \
 } while (false)
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* The _Noreturn keyword of C11.  */
#ifndef _Noreturn
# if (defined __cplusplus \
      && ((201103 <= __cplusplus && !(__GNUC__ == 4 && __GNUC_MINOR__ == 7)) \
          || (defined _MSC_VER && 1900 <= _MSC_VER)))
#  define _Noreturn [[noreturn]]
# elif ((!defined __cplusplus || defined __clang__) \
        && (201112 <= (defined __STDC_VERSION__ ? __STDC_VERSION__ : 0) \
            || (!defined __STRICT_ANSI__ \
                && (4 < __GNUC__ + (7 <= __GNUC_MINOR__) \
                    || (defined __apple_build_version__ \
                        ? 6000000 <= __apple_build_version__ \
                        : 3 < __clang_major__ + (5 <= __clang_minor__))))))
   /* _Noreturn works as-is.  */
# elif (2 < __GNUC__ + (8 <= __GNUC_MINOR__) || defined __clang__ \
        || 0x5110 <= __SUNPRO_C)
#  define _Noreturn __attribute__ ((__noreturn__))
# elif 1200 <= (defined _MSC_VER ? _MSC_VER : 0)
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#if defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_NULL_DEREFERENCE_BEGIN                               \
  _Pragma ("GCC diagnostic push")                                       \
  _Pragma ("GCC diagnostic ignored \"-Wnull-dereference\"")
# define YY_IGNORE_NULL_DEREFERENCE_END         \
  _Pragma ("GCC diagnostic pop")
#else
# define YY_IGNORE_NULL_DEREFERENCE_BEGIN
# define YY_IGNORE_NULL_DEREFERENCE_END
#endif

# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif
# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif

// FIXME: Use the same conventions as lalr1.cc.

#ifndef YYASSERT
# define YYASSERT(Condition) ((void) ((Condition) || (abort (), 0)))
#endif

#ifdef YYDEBUG
# define YYDASSERT(Condition) YYASSERT(Condition)
#else
# define YYDASSERT(Condition)
#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  56
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   755

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  230
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 9
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

namespace
{
#if PARSEDEBUG
  /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
  const short yyrline[] =
  {
       0,   253,   253,   255,   260,   261,   262,   266,   267,   272,
     274,   278,   279,   283,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   309,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   330,   331,
     332,   333,   337,   338,   344,   345,   346,   347,   351,   352,
     356,   357,   361,   365,   366,   370,   393,   394,   396,   397,
     398,   399,   409,   410,   415,   416,   417,   421,   422,   423,
     424,   425,   426,   427,   431,   432,   435,   436,   439,   440,
     444,   445,   449,   450,   454,   459,   462
  };
#endif

#define YYPACT_NINF -120
#define YYTABLE_NINF -96

  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
// STATE-NUM.
  const short yypact[] =
  {
     192,  -120,    24,  -120,  -120,   -16,    26,    36,    39,   321,
      51,    62,   321,   321,    18,  -120,    70,    77,    82,   321,
      65,    69,    71,    73,   106,   642,    21,  -120,    -8,    62,
      62,  -120,    62,    -6,    64,   247,   321,    -2,    99,    76,
     358,    62,    84,    72,   389,  -120,  -120,  -120,    90,    95,
       3,   425,   111,   118,   119,   120,  -120,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     123,   321,  -120,  -120,  -120,  -120,  -120,     2,   321,  -120,
      86,   456,   487,    18,   -23,   321,   129,   321,  -120,   321,
    -120,   321,   129,    20,   321,    18,   321,    89,    93,    97,
      98,   686,  -120,   707,   707,   707,   707,   707,    -7,   707,
     665,    -7,  -120,   642,   103,   510,   121,  -120,   104,   533,
    -120,   321,    20,   113,   142,  -120,   105,   -23,  -120,    96,
     139,   108,   141,  -120,   565,   140,  -120,   112,   124,    27,
     155,  -120,  -120,   642,   152,   642,  -120,  -120,    62,  -120,
     284,  -120,   321,  -120,   125,  -120,   117,   -23,   134,  -120,
    -120,   321,    18,    30,   129,   321,  -120,   156,    18,    18,
     -18,   157,   127,   154,  -120,   321,  -120,  -120,   126,   596,
     321,  -120,   131,   129,   619,  -120,    18,   321,  -120,   642,
      18,  -120,   144,  -120,   133,    18,  -120,   155,   642,  -120,
     174,  -120,   642,  -120,   136,   321,   160,   642,  -120,    48,
    -120,  -120,  -120,   164,    60,   642,   321,  -120,   143,   321,
      18,   321,   642,  -120,   596,   165,   642,  -120,   321,   642
  };

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
// Performed when YYTABLE does not specify something else to do.  Zero
// means the default is an error.
  const signed char yydefact[] =
  {
      66,    15,    48,    13,    41,     0,     0,     0,     0,     0,
       0,    66,     6,     0,     0,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,    19,    65,    63,    66,
      66,     3,    66,    72,     0,     0,     0,     0,     0,     0,
       0,    66,     0,     0,     4,    22,    95,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    64,    68,    69,    67,    73,     0,     0,    20,
       0,    11,     0,     0,     0,     0,    58,     0,    71,     6,
      35,     6,    58,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    26,    27,    31,    29,    32,    30,    24,    28,
      34,    23,    25,    36,    49,     0,     0,    17,     0,     0,
      21,     0,     0,     0,     0,    86,     0,    84,    87,     0,
       0,     0,    59,    61,    37,     0,     5,     0,     0,     0,
      90,    74,    77,    52,     0,    39,    47,    51,    66,    96,
       0,    50,     0,    18,     0,    12,     0,     0,     0,    75,
      85,     0,     0,     0,     0,     0,    42,    56,     0,     0,
       0,     0,     0,    91,    93,     0,    70,    44,     0,     7,
       0,    46,     0,    58,     0,    62,     0,     0,    60,    38,
       0,    79,     0,    80,     0,     0,    78,     0,    53,    45,
       0,     8,    16,    76,     0,     0,     0,    54,    57,     0,
      81,    94,    92,     0,     0,    40,     0,    82,     0,     0,
       0,     0,    55,    83,     9,     0,    88,    10,     0,    89
  };

  // YYPGOTO[NTERM-NUM].
  const short yypgoto[] =
  {
    -120,  -120,     9,  -120,   -39,  -111,     0,  -120,  -120,  -120,
     -88,  -120,    25,   162,   -81,    -9,   158,  -120,    66,  -119,
    -120,  -120,  -120,  -120,    -5,   -13
  };

  // YYDEFGOTO[NTERM-NUM].
  const unsigned char yydefgoto[] =
  {
       0,    24,    43,   118,   201,    80,    44,    26,    27,    28,
     131,   132,   133,    29,    30,    31,    32,    33,   141,   126,
     127,   128,   172,   173,   174,    34
  };

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
// positive, shift that token.  If negative, reduce the rule whose
// number is the opposite.  If YYTABLE_NINF, syntax error.
  const short yytable[] =
  {
      25,    47,    42,   125,   137,     6,   116,    58,   160,    40,
     155,    94,   124,    45,     8,    95,    36,   124,    83,    51,
      73,    74,    46,    75,    46,   193,    84,   138,    18,    69,
      37,   139,    88,    18,    16,    81,    82,    70,   182,   178,
      38,    68,   186,    39,    17,   117,   125,   169,   140,   187,
      71,   194,   -95,   -48,    41,   170,    35,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     123,   115,   220,     6,    48,    23,   125,    23,   119,   221,
     142,    49,   144,   124,     8,   129,    50,   134,    10,   125,
     218,   217,    77,    78,   143,   204,   145,    52,   135,    18,
     136,    53,    57,    54,    16,    55,    56,    85,    86,   142,
      58,    89,    17,    18,    93,    59,    97,    90,    22,    60,
      61,    81,    92,    98,    99,   100,    62,   114,   125,    63,
      64,   120,    65,   130,   146,   150,    66,    67,   147,   176,
     152,   157,   148,   149,    68,   161,   158,   153,   159,   185,
      81,   162,   179,   163,   164,   191,   192,   167,   166,   171,
     175,   184,   181,   168,   180,   189,   183,   197,   190,   195,
     196,   199,   209,   206,   203,   198,   210,   208,   213,   216,
     202,   214,   211,   219,   228,   227,   223,   207,   156,   188,
      72,    76,   212,     0,     0,     1,     2,     3,     0,     0,
       0,     4,     5,     6,     0,   215,     0,   225,     0,     0,
       0,     0,     0,     7,     8,     0,   222,     9,    10,   224,
       0,   226,     0,    11,    12,     0,    13,     0,   229,    14,
      15,     0,     0,     0,    16,     0,     0,     0,     0,     0,
       0,     0,    17,    18,    19,     0,    20,    21,    22,    23,
       1,     2,     3,     0,     0,     0,     4,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     0,
       0,     0,     9,     0,     0,     0,     0,     0,    11,    12,
       0,    13,     0,     0,    14,    15,     0,     1,     2,     3,
       0,     0,    79,     4,     5,     0,     0,     0,     0,    19,
       0,    20,    21,     0,    23,     7,     0,     0,     0,     9,
       0,     0,     0,     0,     0,    11,    12,     0,    13,     0,
       0,    14,    15,     0,     1,     2,     3,     0,     0,   177,
       4,     5,     0,     0,     0,     0,    19,     0,    20,    21,
       0,    23,     7,     0,     0,     0,     9,     0,     0,     0,
       0,     0,    11,    12,     0,    13,     0,     0,    14,    15,
       0,     0,     0,     0,    57,     0,     0,     0,     0,     0,
       0,     0,    58,    19,     0,    20,    21,    59,    23,     0,
       0,    60,    61,     0,     0,     0,     0,     0,    62,     0,
       0,    63,    64,     0,    65,    57,     0,     0,    66,    67,
       0,     0,     0,    58,     0,    87,    68,     0,    59,     0,
       0,     0,    60,    61,     0,     0,     0,     0,     0,    62,
       0,     0,    63,    64,     0,    65,     0,     0,     0,    66,
      67,    57,     0,     0,     0,    91,     0,    68,     0,    58,
      96,     0,     0,     0,    59,     0,     0,     0,    60,    61,
       0,     0,     0,     0,     0,    62,     0,     0,    63,    64,
       0,    65,    57,     0,     0,    66,    67,     0,     0,   121,
      58,     0,     0,    68,     0,    59,     0,     0,     0,    60,
      61,     0,     0,     0,     0,     0,    62,     0,     0,    63,
      64,     0,    65,    57,     0,     0,    66,    67,     0,     0,
     122,    58,     0,     0,    68,     0,    59,     0,     0,     0,
      60,    61,     0,     0,     0,     0,    57,    62,     0,     0,
      63,    64,     0,    65,    58,     0,     0,    66,    67,    59,
       0,     0,     0,    60,    61,    68,     0,     0,     0,    57,
      62,     0,     0,    63,    64,     0,    65,    58,     0,     0,
      66,    67,    59,     0,   151,     0,    60,    61,    68,     0,
       0,     0,     0,    62,     0,     0,    63,    64,     0,    65,
       0,    57,     0,    66,    67,     0,     0,   154,     0,    58,
       0,    68,   165,     0,    59,     0,     0,     0,    60,    61,
       0,     0,     0,     0,     0,    62,     0,     0,    63,    64,
       0,    65,    57,     0,     0,    66,    67,     0,     0,   200,
      58,     0,     0,    68,     0,    59,     0,     0,     0,    60,
      61,     0,     0,     0,     0,    57,    62,     0,     0,    63,
      64,     0,    65,    58,   205,     0,    66,    67,    59,     0,
       0,     0,    60,    61,    68,     0,     0,     0,    57,    62,
       0,     0,    63,    64,     0,    65,    58,     0,     0,    66,
      67,    59,     0,     0,     0,    60,    61,    68,     0,     0,
       0,    57,    62,     0,     0,    63,    64,     0,    65,    58,
       0,     0,    66,    67,    59,     0,     0,     0,    60,    61,
      68,     0,     0,     0,     0,    62,     0,     0,    63,    64,
      58,    65,     0,     0,     0,    59,    67,     0,     0,    60,
      61,     0,     0,    68,     0,     0,    62,     0,     0,    63,
      64,    58,    65,     0,     0,     0,   -96,    67,     0,     0,
     -96,   -96,     0,     0,    68,     0,     0,   -96,     0,     0,
     -96,    64,     0,   -96,     0,     0,     0,     0,    67,     0,
       0,     0,     0,     0,     0,    68
  };

  const short yycheck[] =
  {
       0,    14,    11,    84,    92,    11,     4,    14,   127,     9,
     121,     8,    35,    13,    22,    12,    32,    35,    20,    19,
      29,    30,     4,    32,     4,    43,    28,     7,    51,     8,
       4,    11,    41,    51,    42,    35,    36,    16,   157,   150,
       4,    48,    12,     4,    50,    43,   127,    20,    28,    19,
      29,   170,    28,    29,     3,    28,    32,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      83,    71,    12,    11,     4,    57,   157,    57,    78,    19,
      93,     4,    95,    35,    22,    85,     4,    87,    26,   170,
     209,    43,    28,    29,    94,   183,    96,    32,    89,    51,
      91,    32,     6,    32,    42,    32,     0,     8,    32,   122,
      14,    27,    50,    51,    19,    19,     5,    45,    56,    23,
      24,   121,    32,     5,     5,     5,    30,     4,   209,    33,
      34,    45,    36,     4,    45,    32,    40,    41,    45,   148,
      19,    28,    45,    45,    48,    49,     4,    43,    43,   162,
     150,    12,   152,    45,    13,   168,   169,    45,    18,     4,
       8,   161,    45,    39,    39,   165,    32,    13,    12,    12,
      43,    45,    28,   186,    43,   175,    43,   190,     4,    19,
     180,    45,   195,    19,    19,   224,    43,   187,   122,   164,
      28,    33,   197,    -1,    -1,     3,     4,     5,    -1,    -1,
      -1,     9,    10,    11,    -1,   205,    -1,   220,    -1,    -1,
      -1,    -1,    -1,    21,    22,    -1,   216,    25,    26,   219,
      -1,   221,    -1,    31,    32,    -1,    34,    -1,   228,    37,
      38,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    52,    -1,    54,    55,    56,    57,
       3,     4,     5,    -1,    -1,    -1,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    31,    32,
      -1,    34,    -1,    -1,    37,    38,    -1,     3,     4,     5,
      -1,    -1,    45,     9,    10,    -1,    -1,    -1,    -1,    52,
      -1,    54,    55,    -1,    57,    21,    -1,    -1,    -1,    25,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    34,    -1,
      -1,    37,    38,    -1,     3,     4,     5,    -1,    -1,    45,
       9,    10,    -1,    -1,    -1,    -1,    52,    -1,    54,    55,
      -1,    57,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    -1,    31,    32,    -1,    34,    -1,    -1,    37,    38,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    14,    52,    -1,    54,    55,    19,    57,    -1,
      -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    -1,    36,     6,    -1,    -1,    40,    41,
      -1,    -1,    -1,    14,    -1,    47,    48,    -1,    19,    -1,
      -1,    -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    33,    34,    -1,    36,    -1,    -1,    -1,    40,
      41,     6,    -1,    -1,    -1,    46,    -1,    48,    -1,    14,
      15,    -1,    -1,    -1,    19,    -1,    -1,    -1,    23,    24,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,
      -1,    36,     6,    -1,    -1,    40,    41,    -1,    -1,    13,
      14,    -1,    -1,    48,    -1,    19,    -1,    -1,    -1,    23,
      24,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    -1,    36,     6,    -1,    -1,    40,    41,    -1,    -1,
      13,    14,    -1,    -1,    48,    -1,    19,    -1,    -1,    -1,
      23,    24,    -1,    -1,    -1,    -1,     6,    30,    -1,    -1,
      33,    34,    -1,    36,    14,    -1,    -1,    40,    41,    19,
      -1,    -1,    -1,    23,    24,    48,    -1,    -1,    -1,     6,
      30,    -1,    -1,    33,    34,    -1,    36,    14,    -1,    -1,
      40,    41,    19,    -1,    44,    -1,    23,    24,    48,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    33,    34,    -1,    36,
      -1,     6,    -1,    40,    41,    -1,    -1,    44,    -1,    14,
      -1,    48,    17,    -1,    19,    -1,    -1,    -1,    23,    24,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,
      -1,    36,     6,    -1,    -1,    40,    41,    -1,    -1,    13,
      14,    -1,    -1,    48,    -1,    19,    -1,    -1,    -1,    23,
      24,    -1,    -1,    -1,    -1,     6,    30,    -1,    -1,    33,
      34,    -1,    36,    14,    15,    -1,    40,    41,    19,    -1,
      -1,    -1,    23,    24,    48,    -1,    -1,    -1,     6,    30,
      -1,    -1,    33,    34,    -1,    36,    14,    -1,    -1,    40,
      41,    19,    -1,    -1,    -1,    23,    24,    48,    -1,    -1,
      -1,     6,    30,    -1,    -1,    33,    34,    -1,    36,    14,
      -1,    -1,    40,    41,    19,    -1,    -1,    -1,    23,    24,
      48,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,
      14,    36,    -1,    -1,    -1,    19,    41,    -1,    -1,    23,
      24,    -1,    -1,    48,    -1,    -1,    30,    -1,    -1,    33,
      34,    14,    36,    -1,    -1,    -1,    19,    41,    -1,    -1,
      23,    24,    -1,    -1,    48,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    36,    -1,    -1,    -1,    -1,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    48
  };

  // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
// state STATE-NUM.
  const signed char yystos[] =
  {
       0,     3,     4,     5,     9,    10,    11,    21,    22,    25,
      26,    31,    32,    34,    37,    38,    42,    50,    51,    52,
      54,    55,    56,    57,    59,    64,    65,    66,    67,    71,
      72,    73,    74,    75,    83,    32,    32,     4,     4,     4,
      64,     3,    73,    60,    64,    64,     4,    83,     4,     4,
       4,    64,    32,    32,    32,    32,     0,     6,    14,    19,
      23,    24,    30,    33,    34,    36,    40,    41,    48,     8,
      16,    29,    71,    73,    73,    73,    74,    28,    29,    45,
      63,    64,    64,    20,    28,     8,    32,    47,    73,    27,
      45,    46,    32,    19,     8,    12,    15,     5,     5,     5,
       5,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,     4,    64,     4,    43,    61,    64,
      45,    13,    13,    83,    35,    72,    77,    78,    79,    64,
       4,    68,    69,    70,    64,    60,    60,    68,     7,    11,
      28,    76,    83,    64,    83,    64,    45,    45,    45,    45,
      32,    44,    19,    43,    44,    63,    76,    28,     4,    43,
      77,    49,    12,    45,    13,    17,    18,    45,    39,    20,
      28,     4,    80,    81,    82,     8,    73,    45,    63,    64,
      39,    45,    77,    32,    64,    83,    12,    19,    70,    64,
      12,    83,    83,    43,    77,    12,    43,    13,    64,    45,
      13,    62,    64,    43,    68,    15,    83,    64,    83,    28,
      43,    83,    82,     4,    45,    64,    19,    43,    77,    19,
      12,    19,    64,    43,    64,    83,    64,    62,    19,    64
  };

  // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
  const signed char yyr1[] =
  {
       0,    58,    59,    59,    60,    60,    60,    61,    61,    62,
      62,    63,    63,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    65,    65,
      65,    65,    66,    66,    67,    67,    67,    67,    68,    68,
      69,    69,    70,    71,    71,    72,    73,    73,    73,    73,
      73,    73,    74,    74,    75,    75,    75,    76,    76,    76,
      76,    76,    76,    76,    77,    77,    78,    78,    79,    79,
      80,    80,    81,    81,    82,    83,    83
  };

  // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
  const signed char yyr2[] =
  {
       0,     2,     1,     1,     1,     3,     0,     3,     4,     4,
       5,     1,     3,     1,     1,     1,     6,     3,     4,     1,
       3,     4,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     6,     4,
       8,     1,     5,     2,     5,     6,     6,     4,     1,     3,
       4,     4,     4,     6,     7,     9,     5,     7,     0,     1,
       3,     1,     3,     1,     2,     1,     0,     2,     2,     2,
       5,     3,     1,     2,     4,     5,     7,     1,     3,     3,
       3,     4,     5,     6,     1,     2,     1,     1,     7,     9,
       0,     1,     3,     1,     3,     1,     4
  };


  /* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
  const signed char yydprec[] =
  {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
  };

  /* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
  const signed char yymerger[] =
  {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
  };

  /* YYIMMEDIATE[RULE-NUM] -- True iff rule #RULE-NUM is not to be deferred, as
     in the case of predicates.  */
  const bool yyimmediate[] =
  {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
  };

  /* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
     list of conflicting reductions corresponding to action entry for
     state STATE-NUM in yytable.  0 means no conflicts.  The list in
     yyconfl is terminated by a rule number of 0.  */
  const signed char yyconflp[] =
  {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0
  };

  /* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
     0, pointed into by YYCONFLP.  */
        const short yyconfl[] =
  {
       0,    95,     0
  };
} // namespace


/* Error token number */
#define YYTERROR 1


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif

# define YYRHSLOC(Rhs, K) ((Rhs)[K].getState().yyloc)


enum YYRESULTTAG { yyok, yyaccept, yyabort, yyerr };

#define YYCHK(YYE)                              \
  do {                                          \
    YYRESULTTAG yychk_flag = YYE;               \
    if (yychk_flag != yyok)                     \
      return yychk_flag;                        \
  } while (false)

#if PARSEDEBUG

#define YYCDEBUG if (!yydebug) {} else std::cerr

# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                  \
  do {                                                                  \
    if (yydebug)                                                        \
      {                                                                 \
        std::cerr << Title << ' ';                                      \
        yyparser.yy_symbol_print_ (Kind, Value, Location); \
        std::cerr << '\n';                                              \
      }                                                                 \
  } while (false)

# define YY_REDUCE_PRINT(Args)                  \
  do {                                          \
    if (yydebug)                                \
      yystateStack.yy_reduce_print Args;        \
  } while (false)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

namespace
{
  using glr_stack = parse::parser::glr_stack;
  using glr_state = parse::parser::glr_state;

  void yypstack (const glr_stack& yystack, size_t yyk)
    YY_ATTRIBUTE_UNUSED;
  void yypdumpstack (const glr_stack& yystack)
    YY_ATTRIBUTE_UNUSED;
}

#else /* !PARSEDEBUG */

# define YYCDEBUG if (true) {} else std::cerr
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location) {}
# define YY_REDUCE_PRINT(Args) {}

#endif /* !PARSEDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
# define YYSTACKEXPANDABLE 1
#endif

namespace
{
  template <typename Parameter>
  class strong_index_alias
  {
  public:
    static strong_index_alias create (std::ptrdiff_t value)
    {
      strong_index_alias result;
      result.value_ = value;
      return result;
    }

    std::ptrdiff_t const& get () const { return value_; }

    size_t uget () const { return static_cast<size_t> (value_); }

    strong_index_alias operator+ (std::ptrdiff_t other) const
    {
      return strong_index_alias (get () + other);
    }

    void operator+= (std::ptrdiff_t other)
    {
      value_ += other;
    }

    strong_index_alias operator- (std::ptrdiff_t other)
    {
      return strong_index_alias (get () - other);
    }

    void operator-= (std::ptrdiff_t other)
    {
      value_ -= other;
    }

    size_t operator- (strong_index_alias other)
    {
      return strong_index_alias (get () - other.get ());
    }

    strong_index_alias& operator++ ()
    {
      ++value_;
      return *this;
    }

    bool isValid () const
    {
      return value_ != INVALID_INDEX;
    }

    void setInvalid()
    {
      value_ = INVALID_INDEX;
    }

    bool operator== (strong_index_alias other)
    {
      return get () == other.get ();
    }

    bool operator!= (strong_index_alias other)
    {
      return get () != other.get ();
    }

    bool operator< (strong_index_alias other)
    {
      return get () < other.get ();
    }

  private:
    static const std::ptrdiff_t INVALID_INDEX;

    // WARNING: 0-initialized.
    std::ptrdiff_t value_;
  }; // class strong_index_alias

  template<typename T>
  const std::ptrdiff_t strong_index_alias<T>::INVALID_INDEX =
    std::numeric_limits<std::ptrdiff_t>::max ();

  using state_set_index = strong_index_alias<struct glr_state_set_tag>;

  state_set_index create_state_set_index (std::ptrdiff_t value)
  {
    return state_set_index::create (value);
  }

  /** State numbers, as in LALR(1) machine */
  using state_num = int;

  /** Rule numbers, as in LALR(1) machine */
  using rule_num = int;

  using parser_type = parse::parser;
  using glr_state = parser_type::glr_state;
  using symbol_kind = parser_type::symbol_kind;
  using symbol_kind_type = parser_type::symbol_kind_type;
  using symbol_type = parser_type::symbol_type;
  using value_type = parser_type::value_type;
  using location_type = parser_type::location_type;

  // Forward declarations.
  class glr_stack_item;
  class semantic_option;
} // namespace

namespace
{
  /** Accessing symbol of state YYSTATE.  */
  inline symbol_kind_type
  yy_accessing_symbol (state_num yystate)
  {
    return YY_CAST (symbol_kind_type, yystos[yystate]);
  }

  /** Left-hand-side symbol for rule #YYRULE.  */
  inline symbol_kind_type
  yylhsNonterm (rule_num yyrule)
  {
    return static_cast<symbol_kind_type>(yyr1[yyrule]);
  }

  /** Number of symbols composing the right hand side of rule #RULE.  */
  inline int
  yyrhsLength (rule_num yyrule)
  {
    return yyr2[yyrule];
  }
}

namespace parse
{
  class parser::glr_state
  {
  public:
    glr_state ()
      : yyresolved (false)
      , yylrState (0)
      , yyposn (0)
      , yypred (0)
      , yyfirstVal (0)
      , yyloc ()
    {}

    /// Build with a semantic value.
    glr_state (state_num lrState, size_t posn, const value_type& val, const location_type& loc)
      : yyresolved (true)
      , yylrState (lrState)
      , yyposn (posn)
      , yypred (0)
      , yyval ()
      , yyloc (loc)
    {
      switch (yy_accessing_symbol (lrState))
    {
      case symbol_kind::S_78_classfields_1: // classfields.1
        yyval.copy< ast::ChunkInterface* > (val);
        break;

      case symbol_kind::S_chunks: // chunks
      case symbol_kind::S_classfields: // classfields
        yyval.copy< ast::ChunkList* > (val);
        break;

      case symbol_kind::S_exp: // exp
        yyval.copy< ast::Exp* > (val);
        break;

      case symbol_kind::S_tyfield: // tyfield
        yyval.copy< ast::Field* > (val);
        break;

      case symbol_kind::S_funchunk: // funchunk
        yyval.copy< ast::FunctionChunk* > (val);
        break;

      case symbol_kind::S_fundec: // fundec
        yyval.copy< ast::FunctionDec* > (val);
        break;

      case symbol_kind::S_classfield: // classfield
        yyval.copy< ast::MethodChunk* > (val);
        break;

      case symbol_kind::S_typeid: // typeid
        yyval.copy< ast::NameTy* > (val);
        break;

      case symbol_kind::S_ty: // ty
        yyval.copy< ast::Ty* > (val);
        break;

      case symbol_kind::S_tychunk: // tychunk
        yyval.copy< ast::TypeChunk* > (val);
        break;

      case symbol_kind::S_tydec: // tydec
        yyval.copy< ast::TypeDec* > (val);
        break;

      case symbol_kind::S_lvalue: // lvalue
        yyval.copy< ast::Var* > (val);
        break;

      case symbol_kind::S_funfields: // funfields
      case symbol_kind::S_69_funfields_1: // funfields.1
      case symbol_kind::S_varchunk: // varchunk
        yyval.copy< ast::VarChunk* > (val);
        break;

      case symbol_kind::S_vardec: // vardec
      case symbol_kind::S_funfield: // funfield
        yyval.copy< ast::VarDec* > (val);
        break;

      case symbol_kind::S_exps: // exps
      case symbol_kind::S_function_param: // function_param
        yyval.copy< ast::exps_type* > (val);
        break;

      case symbol_kind::S_record_creation: // record_creation
      case symbol_kind::S_record_init: // record_init
        yyval.copy< ast::fieldinits_type* > (val);
        break;

      case symbol_kind::S_tyfields: // tyfields
      case symbol_kind::S_81_tyfields_1: // tyfields.1
        yyval.copy< ast::fields_type* > (val);
        break;

      case symbol_kind::S_INT: // "integer"
        yyval.copy< int > (val);
        break;

      case symbol_kind::S_ID: // "identifier"
        yyval.copy< misc::symbol > (val);
        break;

      case symbol_kind::S_STRING: // "string"
        yyval.copy< std::string > (val);
        break;

      default:
        break;
    }
}

    /// Build with a semantic option.
    glr_state (state_num lrState, size_t posn)
      : yyresolved (false)
      , yylrState (lrState)
      , yyposn (posn)
      , yypred (0)
      , yyfirstVal (0)
      , yyloc ()
    {}

    glr_state (const glr_state& other)
      : yyresolved (other.yyresolved)
      , yylrState (other.yylrState)
      , yyposn (other.yyposn)
      , yypred (0)
      , yyloc (other.yyloc)
    {
      setPred (other.pred ());
      if (other.yyresolved)
        {
          new (&yyval) value_type ();
          switch (yy_accessing_symbol (other.yylrState))
    {
      case symbol_kind::S_78_classfields_1: // classfields.1
        yyval.copy< ast::ChunkInterface* > (other.value ());
        break;

      case symbol_kind::S_chunks: // chunks
      case symbol_kind::S_classfields: // classfields
        yyval.copy< ast::ChunkList* > (other.value ());
        break;

      case symbol_kind::S_exp: // exp
        yyval.copy< ast::Exp* > (other.value ());
        break;

      case symbol_kind::S_tyfield: // tyfield
        yyval.copy< ast::Field* > (other.value ());
        break;

      case symbol_kind::S_funchunk: // funchunk
        yyval.copy< ast::FunctionChunk* > (other.value ());
        break;

      case symbol_kind::S_fundec: // fundec
        yyval.copy< ast::FunctionDec* > (other.value ());
        break;

      case symbol_kind::S_classfield: // classfield
        yyval.copy< ast::MethodChunk* > (other.value ());
        break;

      case symbol_kind::S_typeid: // typeid
        yyval.copy< ast::NameTy* > (other.value ());
        break;

      case symbol_kind::S_ty: // ty
        yyval.copy< ast::Ty* > (other.value ());
        break;

      case symbol_kind::S_tychunk: // tychunk
        yyval.copy< ast::TypeChunk* > (other.value ());
        break;

      case symbol_kind::S_tydec: // tydec
        yyval.copy< ast::TypeDec* > (other.value ());
        break;

      case symbol_kind::S_lvalue: // lvalue
        yyval.copy< ast::Var* > (other.value ());
        break;

      case symbol_kind::S_funfields: // funfields
      case symbol_kind::S_69_funfields_1: // funfields.1
      case symbol_kind::S_varchunk: // varchunk
        yyval.copy< ast::VarChunk* > (other.value ());
        break;

      case symbol_kind::S_vardec: // vardec
      case symbol_kind::S_funfield: // funfield
        yyval.copy< ast::VarDec* > (other.value ());
        break;

      case symbol_kind::S_exps: // exps
      case symbol_kind::S_function_param: // function_param
        yyval.copy< ast::exps_type* > (other.value ());
        break;

      case symbol_kind::S_record_creation: // record_creation
      case symbol_kind::S_record_init: // record_init
        yyval.copy< ast::fieldinits_type* > (other.value ());
        break;

      case symbol_kind::S_tyfields: // tyfields
      case symbol_kind::S_81_tyfields_1: // tyfields.1
        yyval.copy< ast::fields_type* > (other.value ());
        break;

      case symbol_kind::S_INT: // "integer"
        yyval.copy< int > (other.value ());
        break;

      case symbol_kind::S_ID: // "identifier"
        yyval.copy< misc::symbol > (other.value ());
        break;

      case symbol_kind::S_STRING: // "string"
        yyval.copy< std::string > (other.value ());
        break;

      default:
        break;
    }

        }
      else
        {
          yyfirstVal = 0;
          setFirstVal (other.firstVal ());
        }
    }

    ~glr_state ()
    {
      if (yyresolved)
        {
          symbol_kind_type yykind = yy_accessing_symbol (yylrState);
          // FIXME: User destructors.
          // Value type destructor.
          switch (yykind)
    {
      case symbol_kind::S_78_classfields_1: // classfields.1
        yyval.template destroy< ast::ChunkInterface* > ();
        break;

      case symbol_kind::S_chunks: // chunks
      case symbol_kind::S_classfields: // classfields
        yyval.template destroy< ast::ChunkList* > ();
        break;

      case symbol_kind::S_exp: // exp
        yyval.template destroy< ast::Exp* > ();
        break;

      case symbol_kind::S_tyfield: // tyfield
        yyval.template destroy< ast::Field* > ();
        break;

      case symbol_kind::S_funchunk: // funchunk
        yyval.template destroy< ast::FunctionChunk* > ();
        break;

      case symbol_kind::S_fundec: // fundec
        yyval.template destroy< ast::FunctionDec* > ();
        break;

      case symbol_kind::S_classfield: // classfield
        yyval.template destroy< ast::MethodChunk* > ();
        break;

      case symbol_kind::S_typeid: // typeid
        yyval.template destroy< ast::NameTy* > ();
        break;

      case symbol_kind::S_ty: // ty
        yyval.template destroy< ast::Ty* > ();
        break;

      case symbol_kind::S_tychunk: // tychunk
        yyval.template destroy< ast::TypeChunk* > ();
        break;

      case symbol_kind::S_tydec: // tydec
        yyval.template destroy< ast::TypeDec* > ();
        break;

      case symbol_kind::S_lvalue: // lvalue
        yyval.template destroy< ast::Var* > ();
        break;

      case symbol_kind::S_funfields: // funfields
      case symbol_kind::S_69_funfields_1: // funfields.1
      case symbol_kind::S_varchunk: // varchunk
        yyval.template destroy< ast::VarChunk* > ();
        break;

      case symbol_kind::S_vardec: // vardec
      case symbol_kind::S_funfield: // funfield
        yyval.template destroy< ast::VarDec* > ();
        break;

      case symbol_kind::S_exps: // exps
      case symbol_kind::S_function_param: // function_param
        yyval.template destroy< ast::exps_type* > ();
        break;

      case symbol_kind::S_record_creation: // record_creation
      case symbol_kind::S_record_init: // record_init
        yyval.template destroy< ast::fieldinits_type* > ();
        break;

      case symbol_kind::S_tyfields: // tyfields
      case symbol_kind::S_81_tyfields_1: // tyfields.1
        yyval.template destroy< ast::fields_type* > ();
        break;

      case symbol_kind::S_INT: // "integer"
        yyval.template destroy< int > ();
        break;

      case symbol_kind::S_ID: // "identifier"
        yyval.template destroy< misc::symbol > ();
        break;

      case symbol_kind::S_STRING: // "string"
        yyval.template destroy< std::string > ();
        break;

      default:
        break;
    }

          yyval.~value_type ();
        }
    }

    glr_state& operator= (const glr_state& other)
    {
      if (!yyresolved && other.yyresolved)
        new (&yyval) value_type;
      yyresolved = other.yyresolved;
      yylrState = other.yylrState;
      yyposn = other.yyposn;
      setPred (other.pred ());
      if (other.yyresolved)
        switch (yy_accessing_symbol (other.yylrState))
    {
      case symbol_kind::S_78_classfields_1: // classfields.1
        yyval.copy< ast::ChunkInterface* > (other.value ());
        break;

      case symbol_kind::S_chunks: // chunks
      case symbol_kind::S_classfields: // classfields
        yyval.copy< ast::ChunkList* > (other.value ());
        break;

      case symbol_kind::S_exp: // exp
        yyval.copy< ast::Exp* > (other.value ());
        break;

      case symbol_kind::S_tyfield: // tyfield
        yyval.copy< ast::Field* > (other.value ());
        break;

      case symbol_kind::S_funchunk: // funchunk
        yyval.copy< ast::FunctionChunk* > (other.value ());
        break;

      case symbol_kind::S_fundec: // fundec
        yyval.copy< ast::FunctionDec* > (other.value ());
        break;

      case symbol_kind::S_classfield: // classfield
        yyval.copy< ast::MethodChunk* > (other.value ());
        break;

      case symbol_kind::S_typeid: // typeid
        yyval.copy< ast::NameTy* > (other.value ());
        break;

      case symbol_kind::S_ty: // ty
        yyval.copy< ast::Ty* > (other.value ());
        break;

      case symbol_kind::S_tychunk: // tychunk
        yyval.copy< ast::TypeChunk* > (other.value ());
        break;

      case symbol_kind::S_tydec: // tydec
        yyval.copy< ast::TypeDec* > (other.value ());
        break;

      case symbol_kind::S_lvalue: // lvalue
        yyval.copy< ast::Var* > (other.value ());
        break;

      case symbol_kind::S_funfields: // funfields
      case symbol_kind::S_69_funfields_1: // funfields.1
      case symbol_kind::S_varchunk: // varchunk
        yyval.copy< ast::VarChunk* > (other.value ());
        break;

      case symbol_kind::S_vardec: // vardec
      case symbol_kind::S_funfield: // funfield
        yyval.copy< ast::VarDec* > (other.value ());
        break;

      case symbol_kind::S_exps: // exps
      case symbol_kind::S_function_param: // function_param
        yyval.copy< ast::exps_type* > (other.value ());
        break;

      case symbol_kind::S_record_creation: // record_creation
      case symbol_kind::S_record_init: // record_init
        yyval.copy< ast::fieldinits_type* > (other.value ());
        break;

      case symbol_kind::S_tyfields: // tyfields
      case symbol_kind::S_81_tyfields_1: // tyfields.1
        yyval.copy< ast::fields_type* > (other.value ());
        break;

      case symbol_kind::S_INT: // "integer"
        yyval.copy< int > (other.value ());
        break;

      case symbol_kind::S_ID: // "identifier"
        yyval.copy< misc::symbol > (other.value ());
        break;

      case symbol_kind::S_STRING: // "string"
        yyval.copy< std::string > (other.value ());
        break;

      default:
        break;
    }

      else
        setFirstVal (other.firstVal ());
      yyloc = other.yyloc;
      return *this;
    }

    /** Type tag for the semantic value.  If true, yyval applies, otherwise
     *  yyfirstVal applies.  */
    bool yyresolved;
    /** Number of corresponding LALR(1) machine state.  */
    state_num yylrState;
    /** Source position of the last token produced by my symbol */
    size_t yyposn;

    /// Only call pred() and setPred() on objects in yyitems, not temporaries.
    glr_state* pred ();
    const glr_state* pred () const;
    void setPred (const glr_state* state);

    /// Only call firstVal() and setFirstVal() on objects in yyitems, not
    /// temporaries.
    semantic_option* firstVal ();
    const semantic_option* firstVal () const;
    void setFirstVal (const semantic_option* option);

    value_type& value ()
    {
      return yyval;
    }

    const value_type& value () const
    {
      return yyval;
    }

    void
    destroy (char const *yymsg, parse::parser& yyparser);

    /* DEBUGGING ONLY */
  #if PARSEDEBUG
    void yy_yypstack () const
    {
      if (pred () != YY_NULLPTR)
        {
          pred ()->yy_yypstack ();
          std::cerr << " -> ";
        }
      std::cerr << yylrState << "@" << yyposn;
    }
  #endif

    std::ptrdiff_t indexIn (const glr_stack_item* array) const YY_ATTRIBUTE_UNUSED;

    glr_stack_item* asItem ()
    {
      return asItem(this);
    }

    const glr_stack_item* asItem () const
    {
      return asItem (this);
    }

  private:
    template <typename T>
    static const glr_stack_item* asItem (const T* state)
    {
      return reinterpret_cast<const glr_stack_item*>(state);
    }
    template <typename T>
    static glr_stack_item* asItem (T* state)
    {
      return reinterpret_cast<glr_stack_item*> (state);
    }
    static const char *as_pointer_ (const glr_state *state)
    {
      return reinterpret_cast<const char *> (state);
    }
    static char *as_pointer_ (glr_state *state)
    {
      return reinterpret_cast<char *> (state);
    }
    /** Preceding state in this stack */
    std::ptrdiff_t yypred;
    union {
      /** First in a chain of alternative reductions producing the
       *  nonterminal corresponding to this state, threaded through
       *  yyfirstVal.  Value "0" means empty.  */
      std::ptrdiff_t yyfirstVal;
      /** Semantic value for this state.  */
      value_type yyval;
    };
   // FIXME: Why public?
   public:
    /** Source location for this state.  */
    location_type yyloc;


  }; // class parser::glr_state
} // namespace parse


namespace
{
  /** A stack of GLRState representing the different heads during
    * nondeterministic evaluation. */
  class glr_state_set
  {
  public:
    /** Initialize YYSET to a singleton set containing an empty stack.  */
    glr_state_set ()
      : yylastDeleted (YY_NULLPTR)
    {
      yystates.push_back (YY_NULLPTR);
      yylookaheadNeeds.push_back (false);
    }

    // Behave like a vector of states.
    glr_state*& operator[] (state_set_index index)
    {
      return yystates[index.uget()];
    }

    glr_state* operator[] (state_set_index index) const
    {
      return yystates[index.uget()];
    }

    size_t size () const
    {
      return yystates.size ();
    }

    std::vector<glr_state*>::iterator begin ()
    {
      return yystates.begin ();
    }

    std::vector<glr_state*>::iterator end ()
    {
      return yystates.end ();
    }

    bool lookaheadNeeds (state_set_index index) const
    {
      return yylookaheadNeeds[index.uget ()];
    }

    bool setLookaheadNeeds (state_set_index index, bool value)
    {
      return yylookaheadNeeds[index.uget ()] = value;
    }

    /** Invalidate stack #YYK.  */
    void
    yymarkStackDeleted (state_set_index yyk)
    {
      size_t k = yyk.uget ();
      if (yystates[k] != YY_NULLPTR)
        yylastDeleted = yystates[k];
      yystates[k] = YY_NULLPTR;
    }

    /** Undelete the last stack in *this that was marked as deleted.  Can
        only be done once after a deletion, and only when all other stacks have
        been deleted.  */
    void
    yyundeleteLastStack ()
    {
      if (yylastDeleted == YY_NULLPTR || !yystates.empty ())
        return;
      yystates.push_back (yylastDeleted);
      YYCDEBUG << "Restoring last deleted stack as stack #0.\n";
      clearLastDeleted ();
    }

    /** Remove the dead stacks (yystates[i] == YY_NULLPTR) and shift the later
     * ones.  */
    void
    yyremoveDeletes ()
    {
      size_t newsize = yystates.size ();
      /* j is the number of live stacks we have seen.  */
      for (size_t i = 0, j = 0; j < newsize; ++i)
        {
          if (yystates[i] == YY_NULLPTR)
            {
              if (i == j)
                {
                  YYCDEBUG << "Removing dead stacks.\n";
                }
              newsize -= 1;
            }
          else
            {
              yystates[j] = yystates[i];
              /* In the current implementation, it's unnecessary to copy
                 yylookaheadNeeds[i] since, after
                 yyremoveDeletes returns, the parser immediately either enters
                 deterministic operation or shifts a token.  However, it doesn't
                 hurt, and the code might evolve to need it.  */
              yylookaheadNeeds[j] = yylookaheadNeeds[i];
              if (j != i)
                {
                  YYCDEBUG << "Rename stack " << i << " -> " << j << ".\n";
                }
              j += 1;
            }
        }
      yystates.resize (newsize);
      yylookaheadNeeds.resize (newsize);
    }


    state_set_index
    yysplitStack (state_set_index yyk)
    {
      const size_t k = yyk.uget ();
      yystates.push_back (yystates[k]);
      yylookaheadNeeds.push_back (yylookaheadNeeds[k]);
      return create_state_set_index (static_cast<std::ptrdiff_t> (yystates.size () - 1));
    }

    void clearLastDeleted ()
    {
      yylastDeleted = YY_NULLPTR;
    }

  private:

    std::vector<glr_state*> yystates;
    /** During nondeterministic operation, yylookaheadNeeds tracks which
     *  stacks have actually needed the current lookahead.  During deterministic
     *  operation, yylookaheadNeeds[0] is not maintained since it would merely
     *  duplicate !yyla.empty ().  */
    std::vector<bool> yylookaheadNeeds;

    /** The last stack we invalidated.  */
    glr_state* yylastDeleted;
  }; // class glr_state_set
} // namespace

namespace
{
  class semantic_option
  {
  public:
    semantic_option ()
      : yyrule (0)
      , yystate (0)
      , yynext (0)
      , yyla ()
    {}

    semantic_option (rule_num rule)
      : yyrule (rule)
      , yystate (0)
      , yynext (0)
      , yyla ()
    {}

    semantic_option (const semantic_option& that)
      : yyrule (that.yyrule)
      , yystate (that.yystate)
      , yynext (that.yynext)
      , yyla (that.yyla)
    {
    }

    // Needed for the assignment in yynewSemanticOption.
    semantic_option& operator= (const semantic_option& that)
    {
      yyrule = that.yyrule;
      yystate = that.yystate;
      yynext = that.yynext;
      yyla = that.yyla;
      return *this;
    }

    /// Only call state() and setState() on objects in yyitems, not temporaries.
    glr_state* state();
    const glr_state* state() const;
    void setState(const glr_state* s);

    const semantic_option* next () const YY_ATTRIBUTE_UNUSED;
    semantic_option* next ();
    void setNext (const semantic_option* s);

    std::ptrdiff_t indexIn (const glr_stack_item* array) const YY_ATTRIBUTE_UNUSED;

    /** True iff YYY0 and YYY1 represent identical options at the top level.
     *  That is, they represent the same rule applied to RHS symbols
     *  that produce the same terminal symbols.  */
    bool
    isIdenticalTo (const semantic_option& yyy1) const
    {
      if (this->yyrule == yyy1.yyrule)
        {
          const glr_state *yys0, *yys1;
          int yyn;
          for (yys0 = this->state(),
               yys1 = yyy1.state(),
               yyn = yyrhsLength (this->yyrule);
               yyn > 0;
               yys0 = yys0->pred(),
               yys1 = yys1->pred(), yyn -= 1)
            if (yys0->yyposn != yys1->yyposn)
              return false;
          return true;
        }
      else
        return false;
    }

    /** Assuming identicalOptions (YYY0,YYY1), destructively merge the
     *  alternative semantic values for the RHS-symbols of YYY1 and YYY0.  */
    void
    mergeWith (semantic_option& yyy1)
    {
      glr_state *yys0 = this->state ();
      glr_state *yys1 = yyy1.state ();
      for (int yyn = yyrhsLength (this->yyrule);
           yyn > 0;
           yyn -= 1, yys0 = yys0->pred (), yys1 = yys1->pred ())
        {
          if (yys0 == yys1)
            break;
          else if (yys0->yyresolved)
            {
              yys1->yyresolved = true;
              YYASSERT (yys1->yylrState == yys0->yylrState);
              switch (yy_accessing_symbol (yys0->yylrState))
    {
      case symbol_kind::S_78_classfields_1: // classfields.1
        yys1->value ().copy< ast::ChunkInterface* > (yys0->value ());
        break;

      case symbol_kind::S_chunks: // chunks
      case symbol_kind::S_classfields: // classfields
        yys1->value ().copy< ast::ChunkList* > (yys0->value ());
        break;

      case symbol_kind::S_exp: // exp
        yys1->value ().copy< ast::Exp* > (yys0->value ());
        break;

      case symbol_kind::S_tyfield: // tyfield
        yys1->value ().copy< ast::Field* > (yys0->value ());
        break;

      case symbol_kind::S_funchunk: // funchunk
        yys1->value ().copy< ast::FunctionChunk* > (yys0->value ());
        break;

      case symbol_kind::S_fundec: // fundec
        yys1->value ().copy< ast::FunctionDec* > (yys0->value ());
        break;

      case symbol_kind::S_classfield: // classfield
        yys1->value ().copy< ast::MethodChunk* > (yys0->value ());
        break;

      case symbol_kind::S_typeid: // typeid
        yys1->value ().copy< ast::NameTy* > (yys0->value ());
        break;

      case symbol_kind::S_ty: // ty
        yys1->value ().copy< ast::Ty* > (yys0->value ());
        break;

      case symbol_kind::S_tychunk: // tychunk
        yys1->value ().copy< ast::TypeChunk* > (yys0->value ());
        break;

      case symbol_kind::S_tydec: // tydec
        yys1->value ().copy< ast::TypeDec* > (yys0->value ());
        break;

      case symbol_kind::S_lvalue: // lvalue
        yys1->value ().copy< ast::Var* > (yys0->value ());
        break;

      case symbol_kind::S_funfields: // funfields
      case symbol_kind::S_69_funfields_1: // funfields.1
      case symbol_kind::S_varchunk: // varchunk
        yys1->value ().copy< ast::VarChunk* > (yys0->value ());
        break;

      case symbol_kind::S_vardec: // vardec
      case symbol_kind::S_funfield: // funfield
        yys1->value ().copy< ast::VarDec* > (yys0->value ());
        break;

      case symbol_kind::S_exps: // exps
      case symbol_kind::S_function_param: // function_param
        yys1->value ().copy< ast::exps_type* > (yys0->value ());
        break;

      case symbol_kind::S_record_creation: // record_creation
      case symbol_kind::S_record_init: // record_init
        yys1->value ().copy< ast::fieldinits_type* > (yys0->value ());
        break;

      case symbol_kind::S_tyfields: // tyfields
      case symbol_kind::S_81_tyfields_1: // tyfields.1
        yys1->value ().copy< ast::fields_type* > (yys0->value ());
        break;

      case symbol_kind::S_INT: // "integer"
        yys1->value ().copy< int > (yys0->value ());
        break;

      case symbol_kind::S_ID: // "identifier"
        yys1->value ().copy< misc::symbol > (yys0->value ());
        break;

      case symbol_kind::S_STRING: // "string"
        yys1->value ().copy< std::string > (yys0->value ());
        break;

      default:
        break;
    }

            }
          else if (yys1->yyresolved)
            {
              yys0->yyresolved = true;
              YYASSERT (yys0->yylrState == yys1->yylrState);
              switch (yy_accessing_symbol (yys1->yylrState))
    {
      case symbol_kind::S_78_classfields_1: // classfields.1
        yys0->value ().copy< ast::ChunkInterface* > (yys1->value ());
        break;

      case symbol_kind::S_chunks: // chunks
      case symbol_kind::S_classfields: // classfields
        yys0->value ().copy< ast::ChunkList* > (yys1->value ());
        break;

      case symbol_kind::S_exp: // exp
        yys0->value ().copy< ast::Exp* > (yys1->value ());
        break;

      case symbol_kind::S_tyfield: // tyfield
        yys0->value ().copy< ast::Field* > (yys1->value ());
        break;

      case symbol_kind::S_funchunk: // funchunk
        yys0->value ().copy< ast::FunctionChunk* > (yys1->value ());
        break;

      case symbol_kind::S_fundec: // fundec
        yys0->value ().copy< ast::FunctionDec* > (yys1->value ());
        break;

      case symbol_kind::S_classfield: // classfield
        yys0->value ().copy< ast::MethodChunk* > (yys1->value ());
        break;

      case symbol_kind::S_typeid: // typeid
        yys0->value ().copy< ast::NameTy* > (yys1->value ());
        break;

      case symbol_kind::S_ty: // ty
        yys0->value ().copy< ast::Ty* > (yys1->value ());
        break;

      case symbol_kind::S_tychunk: // tychunk
        yys0->value ().copy< ast::TypeChunk* > (yys1->value ());
        break;

      case symbol_kind::S_tydec: // tydec
        yys0->value ().copy< ast::TypeDec* > (yys1->value ());
        break;

      case symbol_kind::S_lvalue: // lvalue
        yys0->value ().copy< ast::Var* > (yys1->value ());
        break;

      case symbol_kind::S_funfields: // funfields
      case symbol_kind::S_69_funfields_1: // funfields.1
      case symbol_kind::S_varchunk: // varchunk
        yys0->value ().copy< ast::VarChunk* > (yys1->value ());
        break;

      case symbol_kind::S_vardec: // vardec
      case symbol_kind::S_funfield: // funfield
        yys0->value ().copy< ast::VarDec* > (yys1->value ());
        break;

      case symbol_kind::S_exps: // exps
      case symbol_kind::S_function_param: // function_param
        yys0->value ().copy< ast::exps_type* > (yys1->value ());
        break;

      case symbol_kind::S_record_creation: // record_creation
      case symbol_kind::S_record_init: // record_init
        yys0->value ().copy< ast::fieldinits_type* > (yys1->value ());
        break;

      case symbol_kind::S_tyfields: // tyfields
      case symbol_kind::S_81_tyfields_1: // tyfields.1
        yys0->value ().copy< ast::fields_type* > (yys1->value ());
        break;

      case symbol_kind::S_INT: // "integer"
        yys0->value ().copy< int > (yys1->value ());
        break;

      case symbol_kind::S_ID: // "identifier"
        yys0->value ().copy< misc::symbol > (yys1->value ());
        break;

      case symbol_kind::S_STRING: // "string"
        yys0->value ().copy< std::string > (yys1->value ());
        break;

      default:
        break;
    }

            }
          else
            {
              semantic_option* yyz0prev = YY_NULLPTR;
              semantic_option* yyz0 = yys0->firstVal();
              semantic_option* yyz1 = yys1->firstVal();
              while (true)
                {
                  if (yyz1 == yyz0 || yyz1 == YY_NULLPTR)
                    break;
                  else if (yyz0 == YY_NULLPTR)
                    {
                      if (yyz0prev != YY_NULLPTR)
                        yyz0prev->setNext (yyz1);
                      else
                        yys0->setFirstVal (yyz1);
                      break;
                    }
                  else if (yyz0 < yyz1)
                    {
                      semantic_option* yyz = yyz0;
                      if (yyz0prev != YY_NULLPTR)
                        yyz0prev->setNext(yyz1);
                      else
                        yys0->setFirstVal(yyz1);
                      yyz1 = yyz1->next();
                      yyz0->setNext(yyz);
                    }
                  yyz0prev = yyz0;
                  yyz0 = yyz0->next();
                }
              yys1->setFirstVal(yys0->firstVal());
            }
        }
    }

#if PARSEDEBUG
    void yyreportTree (size_t yyindent = 2) const
    {
      int yynrhs = yyrhsLength (this->yyrule);
      const glr_state* yystates[1 + YYMAXRHS];
      glr_state yyleftmost_state;

      {
        const glr_state* yys = this->state();
        for (int yyi = yynrhs; 0 < yyi; yyi -= 1)
          {
            yystates[yyi] = yys;
            yys = yys->pred();
          }
        if (yys == YY_NULLPTR)
          {
            yyleftmost_state.yyposn = 0;
            yystates[0] = &yyleftmost_state;
          }
        else
          yystates[0] = yys;
      }

      std::string yylhs = parse::parser::symbol_name (yylhsNonterm (this->yyrule));
      YYASSERT(this->state());
      if (this->state()->yyposn < yystates[0]->yyposn + 1)
        std::cerr << std::string(yyindent, ' ') << yylhs << " -> <Rule "
                  << this->yyrule - 1 << ", empty>\n";
      else
        std::cerr << std::string(yyindent, ' ') << yylhs << " -> <Rule "
                  << this->yyrule - 1 << ", tokens "
                  << yystates[0]->yyposn + 1 << " .. "
                  << this->state()->yyposn << ">\n";
      for (int yyi = 1; yyi <= yynrhs; yyi += 1)
        {
          if (yystates[yyi]->yyresolved)
            {
              std::string yysym = parse::parser::symbol_name (yy_accessing_symbol (yystates[yyi]->yylrState));
              if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
                std::cerr << std::string(yyindent + 2, ' ') << yysym
                          << " <empty>\n";
              else
                std::cerr << std::string(yyindent + 2, ' ') << yysym
                          << " <tokens " << yystates[yyi-1]->yyposn + 1
                          << " .. " << yystates[yyi]->yyposn << ">\n";
            }
          else
            yystates[yyi]->firstVal ()->yyreportTree (yyindent+2);
        }
    }
#endif

    /** Rule number for this reduction */
    rule_num yyrule;

  private:
    template <typename T>
    static const glr_stack_item* asItem(const T* state)
    {
      return reinterpret_cast<const glr_stack_item*>(state);
    }
    template <typename T>
    static glr_stack_item* asItem(T* state)
    {
      return reinterpret_cast<glr_stack_item*>(state);
    }
    /** The last RHS state in the list of states to be reduced.  */
    std::ptrdiff_t yystate;
    /** Next sibling in chain of options.  To facilitate merging,
     *  options are chained in decreasing order by address.  */
    std::ptrdiff_t yynext;

  public:
    /** The lookahead for this reduction.  */
    symbol_type yyla;


  }; // class semantic_option
} // namespace

namespace
{
  /** Type of the items in the GLR stack.
   *  It can be either a glr_state or a semantic_option. The is_state_ field
   *  indicates which item of the union is valid.  */
  class glr_stack_item
  {
  public:
    glr_stack_item (bool state = true)
      : is_state_ (state)
    {
      if (is_state_)
        new (&raw_) glr_state;
      else
        new (&raw_) semantic_option;
    }

    glr_stack_item (const glr_stack_item& other) YY_NOEXCEPT YY_NOTHROW
      : is_state_ (other.is_state_)
    {
      std::memcpy (raw_, other.raw_, union_size);
    }

    glr_stack_item& operator= (glr_stack_item other)
    {
      std::swap (is_state_, other.is_state_);
      std::swap (raw_, other.raw_);
      return *this;
    }

    ~glr_stack_item ()
    {
      if (is_state ())
        getState ().~glr_state ();
      else
        getOption ().~semantic_option ();
    }

    void setState (const glr_state &state)
    {
      if (this != state.asItem ())
        {
          if (is_state_)
            getState ().~glr_state ();
          else
            getOption ().~semantic_option ();
          new (&raw_) glr_state (state);
          is_state_ = true;
        }
    }

    glr_state& getState ()
    {
      YYDASSERT (is_state ());
      void *yyp = raw_;
      glr_state& res = *static_cast<glr_state*> (yyp);
      return res;
    }

    const glr_state& getState () const
    {
      YYDASSERT (is_state ());
      const void *yyp = raw_;
      const glr_state& res = *static_cast<const glr_state*> (yyp);
      return res;
    }

    semantic_option& getOption ()
    {
      YYDASSERT (!is_state ());
      void *yyp = raw_;
      return *static_cast<semantic_option*> (yyp);
    }
    const semantic_option& getOption () const
    {
      YYDASSERT (!is_state ());
      const void *yyp = raw_;
      return *static_cast<const semantic_option*> (yyp);
    }
    bool is_state () const
    {
      return is_state_;
    }

  private:
    /// The possible contents of raw_. Since they have constructors, they cannot
    /// be directly included in the union.
    union contents
    {
      char yystate[sizeof (glr_state)];
      char yyoption[sizeof (semantic_option)];
    };
    enum { union_size = sizeof (contents) };
    union {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store the contents.
      char raw_[union_size];
    };
    /** Type tag for the union. */
    bool is_state_;

  }; // class glr_stack_item
} // namespace

glr_state* glr_state::pred ()
{
  YY_IGNORE_NULL_DEREFERENCE_BEGIN
  return yypred ? &asItem (as_pointer_ (this) - yypred)->getState () : YY_NULLPTR;
  YY_IGNORE_NULL_DEREFERENCE_END
}

const glr_state* glr_state::pred () const
{
  YY_IGNORE_NULL_DEREFERENCE_BEGIN
  return yypred ? &asItem (as_pointer_ (this) - yypred)->getState () : YY_NULLPTR;
  YY_IGNORE_NULL_DEREFERENCE_END
}

void glr_state::setPred (const glr_state* state)
{
  yypred = state ? as_pointer_ (this) - as_pointer_ (state) : 0;
}

semantic_option* glr_state::firstVal ()
{
  return yyfirstVal ? &(asItem(this) - yyfirstVal)->getOption() : YY_NULLPTR;
}

const semantic_option* glr_state::firstVal () const
{
  return yyfirstVal ? &(asItem(this) - yyfirstVal)->getOption() : YY_NULLPTR;
}

void glr_state::setFirstVal (const semantic_option* option)
{
  yyfirstVal = option ? asItem(this) - asItem(option) : 0;
}

std::ptrdiff_t glr_state::indexIn (const glr_stack_item* array) const
{
  return asItem(this) - array;
}

std::ptrdiff_t semantic_option::indexIn (const glr_stack_item* array) const
{
  return asItem(this) - array;
}

glr_state* semantic_option::state ()
{
  YY_IGNORE_NULL_DEREFERENCE_BEGIN
  return yystate ? &(asItem(this) - yystate)->getState() : YY_NULLPTR;
  YY_IGNORE_NULL_DEREFERENCE_END
}

const glr_state* semantic_option::state () const
{
  return yystate ? &(asItem(this) - yystate)->getState() : YY_NULLPTR;
}

void semantic_option::setState (const glr_state* s)
{
  yystate = s ? asItem(this) - asItem(s) : 0;
}

const semantic_option* semantic_option::next () const
{
  return yynext ? &(asItem(this) - yynext)->getOption() : YY_NULLPTR;
}

semantic_option* semantic_option::next ()
{
  return yynext ? &(asItem(this) - yynext)->getOption() : YY_NULLPTR;
}

void semantic_option::setNext (const semantic_option* s)
{
  yynext = s ? asItem(this) - asItem(s) : 0;
}

void glr_state::destroy (char const* yymsg, parse::parser& yyparser)
{
  if (yyresolved)
    yyparser.yy_destroy_ (yymsg, yy_accessing_symbol(yylrState),
                          value (), yyloc);
  else
    {
#if PARSEDEBUG
      YYCDEBUG << yymsg
               << (firstVal() ? " unresolved " : " incomplete ")
               << (yy_accessing_symbol (yylrState) < YYNTOKENS ? "token" : "nterm")
               << ' ' << yyparser.symbol_name (yy_accessing_symbol (yylrState))
               << " ("
               << yyloc << ": "
               << ")\n";
#endif
      if (firstVal() != YY_NULLPTR)
        {
          semantic_option& yyoption = *firstVal ();
          glr_state *yyrh = yyoption.state ();
          for (int yyn = yyrhsLength (yyoption.yyrule); yyn > 0; yyn -= 1)
            {
              yyrh->destroy (yymsg, yyparser);
              yyrh = yyrh->pred();
            }
        }
    }
}


#undef YYFILL
#define YYFILL(N) yyfill (yyvsp, yylow, (N), yynormal)

namespace
{
  class state_stack
  {
  public:
    using parser_type = parse::parser;
    using symbol_kind = parser_type::symbol_kind;
    using value_type = parser_type::value_type;
    using location_type = parser_type::location_type;

    /** Initialize to a single empty stack, with total maximum
     *  capacity for all stacks of YYSIZE.  */
    state_stack (size_t yysize)
      : yysplitPoint (YY_NULLPTR)
    {
      yyitems.reserve (yysize);
    }

#if YYSTACKEXPANDABLE
    /** Returns false if it tried to expand but could not. */
    bool
    yyexpandGLRStackIfNeeded ()
    {
      return YYHEADROOM <= spaceLeft () || yyexpandGLRStack ();
    }

  private:
    /** If *this is expandable, extend it.  WARNING: Pointers into the
        stack from outside should be considered invalid after this call.
        We always expand when there are 1 or fewer items left AFTER an
        allocation, so that we can avoid having external pointers exist
        across an allocation.  */
    bool
    yyexpandGLRStack ()
    {
      const size_t oldsize = yyitems.size();
      if (YYMAXDEPTH - YYHEADROOM < oldsize)
        return false;
      const size_t yynewSize = YYMAXDEPTH < 2 * oldsize ? YYMAXDEPTH : 2 * oldsize;
      const glr_stack_item *oldbase = &yyitems[0];

      yyitems.reserve (yynewSize);
      const glr_stack_item *newbase = &yyitems[0];

      // Adjust the pointers.  Perform raw pointer arithmetic, as there
      // is no reason for objects to be aligned on their size.
      const ptrdiff_t disp
        = reinterpret_cast<const char*> (newbase) - reinterpret_cast<const char*> (oldbase);
      if (yysplitPoint)
        const_cast<glr_state*&> (yysplitPoint)
          = reinterpret_cast<glr_state*> (reinterpret_cast<char*> (const_cast<glr_state*> (yysplitPoint)) + disp);

      for (std::vector<glr_state*>::iterator
             i = yytops.begin (),
             yyend = yytops.end ();
           i != yyend; ++i)
        if (glr_state_not_null (*i))
          *i = reinterpret_cast<glr_state*>(reinterpret_cast<char*>(*i) + disp);

      return true;
    }

  public:
#else
    bool yyexpandGLRStackIfNeeded ()
    {
      return YYHEADROOM <= spaceLeft ();
    }
#endif
#undef YYSTACKEXPANDABLE

    static bool glr_state_not_null (glr_state* s)
    {
      return s != YY_NULLPTR;
    }

    bool
    reduceToOneStack ()
    {
      using iterator = std::vector<glr_state*>::iterator;
      const iterator yybegin = yytops.begin();
      const iterator yyend = yytops.end();
      const iterator yyit = std::find_if(yybegin, yyend, glr_state_not_null);
      if (yyit == yyend)
        return false;
      for (state_set_index yyk = create_state_set_index(yyit + 1 - yybegin);
           yyk.uget() != numTops(); ++yyk)
        yytops.yymarkStackDeleted (yyk);
      yytops.yyremoveDeletes ();
      yycompressStack ();
      return true;
    }

    /** Called when returning to deterministic operation to clean up the extra
     * stacks. */
    void
    yycompressStack ()
    {
      if (yytops.size() != 1 || !isSplit())
        return;

      // yyr is the state after the split point.
      glr_state* yyr = YY_NULLPTR;
      for (glr_state *yyp = firstTop(), *yyq = yyp->pred();
           yyp != yysplitPoint;
           yyr = yyp, yyp = yyq, yyq = yyp->pred())
        yyp->setPred(yyr);

      // This const_cast is okay, since anyway we have access to the mutable
      // yyitems into which yysplitPoint points.
      glr_stack_item* nextFreeItem
        = const_cast<glr_state*> (yysplitPoint)->asItem () + 1;
      yysplitPoint = YY_NULLPTR;
      yytops.clearLastDeleted ();

      while (yyr != YY_NULLPTR)
        {
          nextFreeItem->setState (*yyr);
          glr_state& nextFreeState = nextFreeItem->getState();
          yyr = yyr->pred();
          nextFreeState.setPred(&(nextFreeItem - 1)->getState());
          setFirstTop (&nextFreeState);
          ++nextFreeItem;
        }
      yyitems.resize(static_cast<size_t>(nextFreeItem - yyitems.data()));
    }

    bool isSplit() const {
      return yysplitPoint != YY_NULLPTR;
    }

    // Present the interface of a vector of glr_stack_item.
    std::vector<glr_stack_item>::const_iterator begin () const
    {
      return yyitems.begin ();
    }

    std::vector<glr_stack_item>::const_iterator end () const
    {
      return yyitems.end ();
    }

    size_t size() const
    {
      return yyitems.size ();
    }

    glr_stack_item& operator[] (size_t i)
    {
      return yyitems[i];
    }

    glr_stack_item& stackItemAt (size_t index)
    {
      return yyitems[index];
    }

    size_t numTops () const
    {
      return yytops.size ();
    }

    glr_state* firstTop () const
    {
      return yytops[create_state_set_index (0)];
    }

    glr_state* topAt (state_set_index i) const
    {
      return yytops[i];
    }

    void setFirstTop (glr_state* value)
    {
      yytops[create_state_set_index (0)] = value;
    }

    void setTopAt (state_set_index i, glr_state* value)
    {
      yytops[i] = value;
    }

    void pop_back ()
    {
      yyitems.pop_back ();
    }

    void pop_back (size_t n)
    {
      yyitems.resize (yyitems.size () - n);
    }

    state_set_index
    yysplitStack (state_set_index yyk)
    {
      if (!isSplit ())
        {
          YYASSERT (yyk.get () == 0);
          yysplitPoint = topAt (yyk);
        }
      return yytops.yysplitStack (yyk);
    }

    /** Assuming that YYS is a GLRState somewhere on *this, update the
     *  splitpoint of *this, if needed, so that it is at least as deep as
     *  YYS.  */
    void
    yyupdateSplit (glr_state& yys)
    {
      if (isSplit() && &yys < yysplitPoint)
        yysplitPoint = &yys;
    }

    /** Return a fresh GLRState.
     * Callers should call yyreserveStack afterwards to make sure there is
     * sufficient headroom.  */
    glr_state& yynewGLRState (const glr_state& newState)
    {
      glr_state& state = yyitems[yynewGLRStackItem (true)].getState ();
#if false && 201103L <= YY_CPLUSPLUS
      state = std::move (newState);
#else
      state = newState;
#endif
      return state;
    }

    /** Return a fresh SemanticOption.
     * Callers should call yyreserveStack afterwards to make sure there is
     * sufficient headroom.  */
    semantic_option& yynewSemanticOption (semantic_option newOption)
    {
      semantic_option& option = yyitems[yynewGLRStackItem (false)].getOption ();
      option = std::move (newOption);
      return option;
    }

    /* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
     * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
     * For convenience, always return YYLOW1.  */
    int
    yyfill (glr_stack_item *yyvsp, int &yylow, int yylow1, bool yynormal)
    {
      if (!yynormal && yylow1 < yylow)
        {
          yyfillin (yyvsp, yylow, yylow1);
          yylow = yylow1;
        }
      return yylow1;
    }

    /** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
     *  at YYVSP[YYLOW0].getState().pred().  Leaves YYVSP[YYLOW1].getState().pred()
     *  containing the pointer to the next state in the chain.  */
    void
    yyfillin (glr_stack_item *yyvsp, int yylow0, int yylow1)
    {
      glr_state* s = yyvsp[yylow0].getState().pred();
      YYASSERT(s != YY_NULLPTR);
      for (int i = yylow0-1; i >= yylow1; i -= 1, s = s->pred())
        {
          glr_state& yys = yyvsp[i].getState();
#if PARSEDEBUG
          yys.yylrState = s->yylrState;
#endif
          yys.yyresolved = s->yyresolved;
          if (s->yyresolved)
            {
              new (&yys.value ()) value_type ();
              switch (yy_accessing_symbol (s->yylrState))
    {
      case symbol_kind::S_78_classfields_1: // classfields.1
        yys.value ().copy< ast::ChunkInterface* > (s->value ());
        break;

      case symbol_kind::S_chunks: // chunks
      case symbol_kind::S_classfields: // classfields
        yys.value ().copy< ast::ChunkList* > (s->value ());
        break;

      case symbol_kind::S_exp: // exp
        yys.value ().copy< ast::Exp* > (s->value ());
        break;

      case symbol_kind::S_tyfield: // tyfield
        yys.value ().copy< ast::Field* > (s->value ());
        break;

      case symbol_kind::S_funchunk: // funchunk
        yys.value ().copy< ast::FunctionChunk* > (s->value ());
        break;

      case symbol_kind::S_fundec: // fundec
        yys.value ().copy< ast::FunctionDec* > (s->value ());
        break;

      case symbol_kind::S_classfield: // classfield
        yys.value ().copy< ast::MethodChunk* > (s->value ());
        break;

      case symbol_kind::S_typeid: // typeid
        yys.value ().copy< ast::NameTy* > (s->value ());
        break;

      case symbol_kind::S_ty: // ty
        yys.value ().copy< ast::Ty* > (s->value ());
        break;

      case symbol_kind::S_tychunk: // tychunk
        yys.value ().copy< ast::TypeChunk* > (s->value ());
        break;

      case symbol_kind::S_tydec: // tydec
        yys.value ().copy< ast::TypeDec* > (s->value ());
        break;

      case symbol_kind::S_lvalue: // lvalue
        yys.value ().copy< ast::Var* > (s->value ());
        break;

      case symbol_kind::S_funfields: // funfields
      case symbol_kind::S_69_funfields_1: // funfields.1
      case symbol_kind::S_varchunk: // varchunk
        yys.value ().copy< ast::VarChunk* > (s->value ());
        break;

      case symbol_kind::S_vardec: // vardec
      case symbol_kind::S_funfield: // funfield
        yys.value ().copy< ast::VarDec* > (s->value ());
        break;

      case symbol_kind::S_exps: // exps
      case symbol_kind::S_function_param: // function_param
        yys.value ().copy< ast::exps_type* > (s->value ());
        break;

      case symbol_kind::S_record_creation: // record_creation
      case symbol_kind::S_record_init: // record_init
        yys.value ().copy< ast::fieldinits_type* > (s->value ());
        break;

      case symbol_kind::S_tyfields: // tyfields
      case symbol_kind::S_81_tyfields_1: // tyfields.1
        yys.value ().copy< ast::fields_type* > (s->value ());
        break;

      case symbol_kind::S_INT: // "integer"
        yys.value ().copy< int > (s->value ());
        break;

      case symbol_kind::S_ID: // "identifier"
        yys.value ().copy< misc::symbol > (s->value ());
        break;

      case symbol_kind::S_STRING: // "string"
        yys.value ().copy< std::string > (s->value ());
        break;

      default:
        break;
    }

            }
          else
            /* The effect of using yyval or yyloc (in an immediate
             * rule) is undefined.  */
            yys.setFirstVal (YY_NULLPTR);
          yys.yyloc = s->yyloc;
          yys.setPred(s->pred());
        }
    }

#if PARSEDEBUG

    /*----------------------------------------------------------------------.
    | Report that stack #YYK of *YYSTACKP is going to be reduced by YYRULE. |
    `----------------------------------------------------------------------*/

    void
    yy_reduce_print (bool yynormal, glr_stack_item* yyvsp, state_set_index yyk,
                     rule_num yyrule, parser_type& yyparser)
    {
      int yynrhs = yyrhsLength (yyrule);
      int yylow = 1;
      int yyi;
      std::cerr << "Reducing stack " << yyk.get() << " by rule " << yyrule - 1
                << " (line " << int (yyrline[yyrule]) << "):\n";
      if (! yynormal)
        yyfillin (yyvsp, 1, -yynrhs);
      /* The symbols being reduced.  */
      for (yyi = 0; yyi < yynrhs; yyi++)
        {
          std::cerr << "   $" << yyi + 1 << " = ";
          yyparser.yy_symbol_print_
            (yy_accessing_symbol (yyvsp[yyi - yynrhs + 1].getState().yylrState),
             yyvsp[yyi - yynrhs + 1].getState().value (),
             ((static_cast<glr_stack_item const *>(yyvsp))[YYFILL ((yyi + 1) - (yynrhs))].getState().yyloc));
          if (!yyvsp[yyi - yynrhs + 1].getState().yyresolved)
            std::cerr << " (unresolved)";
          std::cerr << '\n';
        }
    }


#define YYINDEX(YYX)                                                         \
      ((YYX) == YY_NULLPTR ? -1 : (YYX)->indexIn (yyitems.data ()))

    void
    dumpStack () const
    {
      for (size_t yyi = 0; yyi < size(); ++yyi)
        {
          const glr_stack_item& item = yyitems[yyi];
          std::cerr << std::setw(3) << yyi << ". ";
          if (item.is_state())
            {
              std::cerr << "Res: " << item.getState().yyresolved
                        << ", LR State: " << item.getState().yylrState
                        << ", posn: " << item.getState().yyposn
                        << ", pred: " << YYINDEX(item.getState().pred());
              if (! item.getState().yyresolved)
                std::cerr << ", firstVal: "
                          << YYINDEX(item.getState().firstVal());
            }
          else
            {
              std::cerr << "Option. rule: " << item.getOption().yyrule - 1
                        << ", state: " << YYINDEX(item.getOption().state())
                        << ", next: " << YYINDEX(item.getOption().next());
            }
          std::cerr << '\n';
        }
      std::cerr << "Tops:";
      for (state_set_index yyi = create_state_set_index(0); yyi.uget() < numTops(); ++yyi) {
        std::cerr << yyi.get() << ": " << YYINDEX(topAt(yyi)) << "; ";
      }
      std::cerr << '\n';
    }

#undef YYINDEX
#endif

    YYRESULTTAG
    yyreportAmbiguity (const semantic_option& yyx0,
                       const semantic_option& yyx1, parser_type& yyparser, const location_type& yyloc)
    {
      YY_USE (yyx0);
      YY_USE (yyx1);

#if PARSEDEBUG
      std::cerr << "Ambiguity detected.\n"
        "Option 1,\n";
      yyx0.yyreportTree ();
      std::cerr << "\nOption 2,\n";
      yyx1.yyreportTree ();
      std::cerr << '\n';
#endif

      yyparser.error (yyloc, YY_("syntax is ambiguous"));
      return yyabort;
    }

#if PARSEDEBUG
    /* Print YYS (possibly NULL) and its predecessors. */
    void
    yypstates (const glr_state* yys) const
    {
      if (yys != YY_NULLPTR)
        yys->yy_yypstack();
      else
        std::cerr << "<null>";
      std::cerr << '\n';
    }
#endif

  private:
    size_t spaceLeft() const
    {
      return yyitems.capacity() - yyitems.size();
    }

    /** Return a fresh GLRStackItem in this.  The item is an LR state
     *  if YYIS_STATE, and otherwise a semantic option.  Callers should call
     *  yyreserveStack afterwards to make sure there is sufficient
     *  headroom.  */
    size_t
    yynewGLRStackItem (bool yyis_state)
    {
      YYDASSERT(yyitems.size() < yyitems.capacity());
      yyitems.push_back(glr_stack_item(yyis_state));
      return yyitems.size() - 1;
    }


  public:
    std::vector<glr_stack_item> yyitems;
    // Where the stack splits. Anything below this address is deterministic.
    const glr_state* yysplitPoint;
    glr_state_set yytops;
  }; // class state_stack
} // namespace

#undef YYFILL
#define YYFILL(N) yystateStack.yyfill (yyvsp, yylow, (N), yynormal)

namespace parse
{
  class parser::glr_stack
  {
  public:

    // Needs access to yypact_value_is_default, etc.
    friend context;


    glr_stack (size_t yysize, parser_type& yyparser_yyarg, ::parse::TigerParser& tp_yyarg)
      : yyerrState (0)
      , yystateStack (yysize)
      , yyerrcnt (0)
      , yyla ()
      , yyparser (yyparser_yyarg),
      tp (tp_yyarg)
    {}

    ~glr_stack ()
    {
      if (!this->yyla.empty ())
        yyparser.yy_destroy_ ("Cleanup: discarding lookahead",
                              this->yyla.kind (), this->yyla.value, this->yyla.location);
      popall_ ();
    }

    int yyerrState;
  /* To compute the location of the error token.  */
    glr_stack_item yyerror_range[3];
    state_stack yystateStack;
    int yyerrcnt;
    symbol_type yyla;
    YYJMP_BUF yyexception_buffer;
    parser_type& yyparser;

  #define YYCHK1(YYE)                                                          \
    do {                                                                       \
      switch (YYE) {                                                           \
      case yyok:                                                               \
        break;                                                                 \
      case yyabort:                                                            \
        goto yyabortlab;                                                       \
      case yyaccept:                                                           \
        goto yyacceptlab;                                                      \
      case yyerr:                                                              \
        goto yyuser_error;                                                     \
      default:                                                                 \
        goto yybuglab;                                                         \
      }                                                                        \
    } while (false)

    int
    parse ()
    {
      int yyresult;
      size_t yyposn;

      YYCDEBUG << "Starting parse\n";

      this->yyla.clear ();

      switch (YYSETJMP (this->yyexception_buffer))
        {
        case 0: break;
        case 1: goto yyabortlab;
        case 2: goto yyexhaustedlab;
        default: goto yybuglab;
        }
      this->yyglrShift (create_state_set_index(0), 0, 0, this->yyla.value, this->yyla.location);
      yyposn = 0;

      while (true)
        {
          /* For efficiency, we have two loops, the first of which is
             specialized to deterministic operation (single stack, no
             potential ambiguity).  */
          /* Standard mode */
          while (true)
            {
              const state_num yystate = this->firstTopState()->yylrState;
              YYCDEBUG << "Entering state " << yystate << '\n';
              if (yystate == YYFINAL)
                goto yyacceptlab;
              if (yy_is_defaulted_state (yystate))
                {
                  const rule_num yyrule = yy_default_action (yystate);
                  if (yyrule == 0)
                    {
                      this->yyerror_range[1].getState().yyloc = this->yyla.location;
                      this->yyreportSyntaxError ();
                      goto yyuser_error;
                    }
                  YYCHK1 (this->yyglrReduce (create_state_set_index(0), yyrule, true));
                }
              else
                {
                  yyget_token ();
                  const short* yyconflicts;
                  const int yyaction = yygetLRActions (yystate, this->yyla.kind (), yyconflicts);
                  if (*yyconflicts != 0)
                    break;
                  if (yy_is_shift_action (yyaction))
                    {
                      YY_SYMBOL_PRINT ("Shifting", this->yyla.kind (), this->yyla.value, this->yyla.location);
                      yyposn += 1;
                      // FIXME: we should move yylval.
                      this->yyglrShift (create_state_set_index(0), yyaction, yyposn, this->yyla.value, this->yyla.location);
                      yyla.clear ();
                      if (0 < this->yyerrState)
                        this->yyerrState -= 1;
                    }
                  else if (yy_is_error_action (yyaction))
                    {
                      this->yyerror_range[1].getState().yyloc = this->yyla.location;
                      /* Don't issue an error message again for exceptions
                         thrown from the scanner.  */
                      if (this->yyla.kind () != symbol_kind::S_YYerror)
                        this->yyreportSyntaxError ();
                      goto yyuser_error;
                    }
                  else
                    YYCHK1 (this->yyglrReduce (create_state_set_index(0), -yyaction, true));
                }
            }

          while (true)
            {
              for (state_set_index yys = create_state_set_index(0); yys.uget() < this->yystateStack.numTops(); ++yys)
                this->yystateStack.yytops.setLookaheadNeeds(yys, !this->yyla.empty ());

              /* yyprocessOneStack returns one of three things:

                  - An error flag.  If the caller is yyprocessOneStack, it
                    immediately returns as well.  When the caller is finally
                    yyparse, it jumps to an error label via YYCHK1.

                  - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
                    (yys), which sets the top state of yys to NULL.  Thus,
                    yyparse's following invocation of yyremoveDeletes will remove
                    the stack.

                  - yyok, when ready to shift a token.

                 Except in the first case, yyparse will invoke yyremoveDeletes and
                 then shift the next token onto all remaining stacks.  This
                 synchronization of the shift (that is, after all preceding
                 reductions on all stacks) helps prevent double destructor calls
                 on yylval in the event of memory exhaustion.  */

              for (state_set_index yys = create_state_set_index (0); yys.uget () < this->yystateStack.numTops (); ++yys)
                YYCHK1 (this->yyprocessOneStack (yys, yyposn, &this->yyla.location));
              this->yystateStack.yytops.yyremoveDeletes ();
              if (this->yystateStack.yytops.size() == 0)
                {
                  this->yystateStack.yytops.yyundeleteLastStack ();
                  if (this->yystateStack.yytops.size() == 0)
                    this->yyFail (&this->yyla.location, YY_("syntax error"));
                  YYCHK1 (this->yyresolveStack ());
                  YYCDEBUG << "Returning to deterministic operation.\n";
                  this->yyerror_range[1].getState ().yyloc = this->yyla.location;
                  this->yyreportSyntaxError ();
                  goto yyuser_error;
                }

              /* If any yyglrShift call fails, it will fail after shifting.  Thus,
                 a copy of yylval will already be on stack 0 in the event of a
                 failure in the following loop.  Thus, yyla is emptied
                 before the loop to make sure the user destructor for yylval isn't
                 called twice.  */
              symbol_kind_type yytoken_to_shift = this->yyla.kind ();
              this->yyla.kind_ = symbol_kind::S_YYEMPTY;
              yyposn += 1;
              for (state_set_index yys = create_state_set_index (0); yys.uget () < this->yystateStack.numTops (); ++yys)
                {
                  const state_num yystate = this->topState (yys)->yylrState;
                  const short* yyconflicts;
                  const int yyaction = yygetLRActions (yystate, yytoken_to_shift, yyconflicts);
                  /* Note that yyconflicts were handled by yyprocessOneStack.  */
                  YYCDEBUG << "On stack " << yys.get() << ", ";
                  YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, this->yyla.value, this->yyla.location);
                  this->yyglrShift (yys, yyaction, yyposn, this->yyla.value, this->yyla.location);
                  YYCDEBUG << "Stack " << yys.get() << " now in state "
                           << this->topState(yys)->yylrState << '\n';
                }

                // FIXME: User destructors.
                // Value type destructor.
                switch (yytoken_to_shift)
    {
      case symbol_kind::S_78_classfields_1: // classfields.1
        this->yyla.value.template destroy< ast::ChunkInterface* > ();
        break;

      case symbol_kind::S_chunks: // chunks
      case symbol_kind::S_classfields: // classfields
        this->yyla.value.template destroy< ast::ChunkList* > ();
        break;

      case symbol_kind::S_exp: // exp
        this->yyla.value.template destroy< ast::Exp* > ();
        break;

      case symbol_kind::S_tyfield: // tyfield
        this->yyla.value.template destroy< ast::Field* > ();
        break;

      case symbol_kind::S_funchunk: // funchunk
        this->yyla.value.template destroy< ast::FunctionChunk* > ();
        break;

      case symbol_kind::S_fundec: // fundec
        this->yyla.value.template destroy< ast::FunctionDec* > ();
        break;

      case symbol_kind::S_classfield: // classfield
        this->yyla.value.template destroy< ast::MethodChunk* > ();
        break;

      case symbol_kind::S_typeid: // typeid
        this->yyla.value.template destroy< ast::NameTy* > ();
        break;

      case symbol_kind::S_ty: // ty
        this->yyla.value.template destroy< ast::Ty* > ();
        break;

      case symbol_kind::S_tychunk: // tychunk
        this->yyla.value.template destroy< ast::TypeChunk* > ();
        break;

      case symbol_kind::S_tydec: // tydec
        this->yyla.value.template destroy< ast::TypeDec* > ();
        break;

      case symbol_kind::S_lvalue: // lvalue
        this->yyla.value.template destroy< ast::Var* > ();
        break;

      case symbol_kind::S_funfields: // funfields
      case symbol_kind::S_69_funfields_1: // funfields.1
      case symbol_kind::S_varchunk: // varchunk
        this->yyla.value.template destroy< ast::VarChunk* > ();
        break;

      case symbol_kind::S_vardec: // vardec
      case symbol_kind::S_funfield: // funfield
        this->yyla.value.template destroy< ast::VarDec* > ();
        break;

      case symbol_kind::S_exps: // exps
      case symbol_kind::S_function_param: // function_param
        this->yyla.value.template destroy< ast::exps_type* > ();
        break;

      case symbol_kind::S_record_creation: // record_creation
      case symbol_kind::S_record_init: // record_init
        this->yyla.value.template destroy< ast::fieldinits_type* > ();
        break;

      case symbol_kind::S_tyfields: // tyfields
      case symbol_kind::S_81_tyfields_1: // tyfields.1
        this->yyla.value.template destroy< ast::fields_type* > ();
        break;

      case symbol_kind::S_INT: // "integer"
        this->yyla.value.template destroy< int > ();
        break;

      case symbol_kind::S_ID: // "identifier"
        this->yyla.value.template destroy< misc::symbol > ();
        break;

      case symbol_kind::S_STRING: // "string"
        this->yyla.value.template destroy< std::string > ();
        break;

      default:
        break;
    }


              if (this->yystateStack.yytops.size () == 1)
                {
                  YYCHK1 (this->yyresolveStack ());
                  YYCDEBUG << "Returning to deterministic operation.\n";
                  this->yystateStack.yycompressStack ();
                  break;
                }
            }
          continue;
        yyuser_error:
          this->yyrecoverSyntaxError (&this->yyla.location);
          yyposn = this->firstTopState()->yyposn;
        }

    yyacceptlab:
      yyresult = 0;
      goto yyreturn;

    yybuglab:
      YYASSERT (false);
      goto yyabortlab;

    yyabortlab:
      yyresult = 1;
      goto yyreturn;

    yyexhaustedlab:
      yyparser.error (this->yyla.location, YY_("memory exhausted"));
      yyresult = 2;
      goto yyreturn;

    yyreturn:
      return yyresult;
    }
  #undef YYCHK1

    void yyreserveGlrStack ()
    {
      if (!yystateStack.yyexpandGLRStackIfNeeded ())
        yyMemoryExhausted ();
    }

    _Noreturn void
    yyMemoryExhausted ()
    {
      YYLONGJMP (yyexception_buffer, 2);
    }

    _Noreturn void
    yyFail (location_type* yylocp, const char* yymsg)
    {
      if (yymsg != YY_NULLPTR)
        yyparser.error (*yylocp, yymsg);
      YYLONGJMP (yyexception_buffer, 1);
    }

                                  /* GLRStates */


    /** Add a new semantic action that will execute the action for rule
     *  YYRULE on the semantic values in YYRHS to the list of
     *  alternative actions for YYSTATE.  Assumes that YYRHS comes from
     *  stack #YYK of *this. */
    void
    yyaddDeferredAction (state_set_index yyk, glr_state* yystate,
                         glr_state* yyrhs, rule_num yyrule)
    {
      semantic_option& yyopt = yystateStack.yynewSemanticOption (semantic_option (yyrule));
      yyopt.setState (yyrhs);
      yyopt.setNext (yystate->firstVal ());
      if (yystateStack.yytops.lookaheadNeeds (yyk))
        yyopt.yyla = this->yyla;
      yystate->setFirstVal (&yyopt);

      yyreserveGlrStack ();
    }

  #if PARSEDEBUG
    void yypdumpstack () const
    {
      yystateStack.dumpStack();
    }
  #endif

    void
    yyreportSyntaxError ()
    {
      if (yyerrState != 0)
        return;

      context yyctx (*this, yyla);
      std::string msg = yyparser.yysyntax_error_ (yyctx);
      yyparser.error (yyla.location, YY_MOVE (msg));
      yyerrcnt += 1;
    }

    /* Recover from a syntax error on this, assuming that yytoken,
       yylval, and yylloc are the syntactic category, semantic value, and location
       of the lookahead.  */
    void
    yyrecoverSyntaxError (location_type* yylocp)
    {
      if (yyerrState == 3)
        /* We just shifted the error token and (perhaps) took some
           reductions.  Skip tokens until we can proceed.  */
        while (true)
          {
            if (this->yyla.kind () == symbol_kind::S_YYEOF)
              yyFail (yylocp, YY_NULLPTR);
            if (this->yyla.kind () != symbol_kind::S_YYEMPTY)
              {
                /* We throw away the lookahead, but the error range
                   of the shifted error token must take it into account.  */
                glr_state *yys = firstTopState();
                yyerror_range[1].getState().yyloc = yys->yyloc;
                yyerror_range[2].getState().yyloc = this->yyla.location;
                YYLLOC_DEFAULT ((yys->yyloc), yyerror_range, 2);
                yyparser.yy_destroy_ ("Error: discarding",
                                      this->yyla.kind (), this->yyla.value, this->yyla.location);
                // Value type destructor.
                switch (this->yyla.kind ())
    {
      case symbol_kind::S_78_classfields_1: // classfields.1
        this->yyla.value.template destroy< ast::ChunkInterface* > ();
        break;

      case symbol_kind::S_chunks: // chunks
      case symbol_kind::S_classfields: // classfields
        this->yyla.value.template destroy< ast::ChunkList* > ();
        break;

      case symbol_kind::S_exp: // exp
        this->yyla.value.template destroy< ast::Exp* > ();
        break;

      case symbol_kind::S_tyfield: // tyfield
        this->yyla.value.template destroy< ast::Field* > ();
        break;

      case symbol_kind::S_funchunk: // funchunk
        this->yyla.value.template destroy< ast::FunctionChunk* > ();
        break;

      case symbol_kind::S_fundec: // fundec
        this->yyla.value.template destroy< ast::FunctionDec* > ();
        break;

      case symbol_kind::S_classfield: // classfield
        this->yyla.value.template destroy< ast::MethodChunk* > ();
        break;

      case symbol_kind::S_typeid: // typeid
        this->yyla.value.template destroy< ast::NameTy* > ();
        break;

      case symbol_kind::S_ty: // ty
        this->yyla.value.template destroy< ast::Ty* > ();
        break;

      case symbol_kind::S_tychunk: // tychunk
        this->yyla.value.template destroy< ast::TypeChunk* > ();
        break;

      case symbol_kind::S_tydec: // tydec
        this->yyla.value.template destroy< ast::TypeDec* > ();
        break;

      case symbol_kind::S_lvalue: // lvalue
        this->yyla.value.template destroy< ast::Var* > ();
        break;

      case symbol_kind::S_funfields: // funfields
      case symbol_kind::S_69_funfields_1: // funfields.1
      case symbol_kind::S_varchunk: // varchunk
        this->yyla.value.template destroy< ast::VarChunk* > ();
        break;

      case symbol_kind::S_vardec: // vardec
      case symbol_kind::S_funfield: // funfield
        this->yyla.value.template destroy< ast::VarDec* > ();
        break;

      case symbol_kind::S_exps: // exps
      case symbol_kind::S_function_param: // function_param
        this->yyla.value.template destroy< ast::exps_type* > ();
        break;

      case symbol_kind::S_record_creation: // record_creation
      case symbol_kind::S_record_init: // record_init
        this->yyla.value.template destroy< ast::fieldinits_type* > ();
        break;

      case symbol_kind::S_tyfields: // tyfields
      case symbol_kind::S_81_tyfields_1: // tyfields.1
        this->yyla.value.template destroy< ast::fields_type* > ();
        break;

      case symbol_kind::S_INT: // "integer"
        this->yyla.value.template destroy< int > ();
        break;

      case symbol_kind::S_ID: // "identifier"
        this->yyla.value.template destroy< misc::symbol > ();
        break;

      case symbol_kind::S_STRING: // "string"
        this->yyla.value.template destroy< std::string > ();
        break;

      default:
        break;
    }

                this->yyla.kind_ = symbol_kind::S_YYEMPTY;
              }
            yyget_token ();
            int yyj = yypact[firstTopState()->yylrState];
            if (yypact_value_is_default (yyj))
              return;
            yyj += this->yyla.kind ();
            if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != this->yyla.kind ())
              {
                if (yydefact[firstTopState()->yylrState] != 0)
                  return;
              }
            else if (! yytable_value_is_error (yytable[yyj]))
              return;
          }

      if (!yystateStack.reduceToOneStack())
        yyFail (yylocp, YY_NULLPTR);

      /* Now pop stack until we find a state that shifts the error token.  */
      yyerrState = 3;
      while (firstTopState () != YY_NULLPTR)
        {
          glr_state *yys = firstTopState ();
          int yyj = yypact[yys->yylrState];
          if (! yypact_value_is_default (yyj))
            {
              yyj += YYTERROR;
              if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYTERROR
                  && yy_is_shift_action (yytable[yyj]))
                {
                  /* Shift the error token.  */
                  /* First adjust its location.*/
                  location_type yyerrloc;
                  yyerror_range[2].getState().yyloc = this->yyla.location;
                  YYLLOC_DEFAULT (yyerrloc, (yyerror_range), 2);
                  YY_SYMBOL_PRINT ("Shifting", yy_accessing_symbol (yytable[yyj]),
                                   this->yyla.value, yyerrloc);
                  yyglrShift (create_state_set_index(0), yytable[yyj],
                              yys->yyposn, yyla.value, yyerrloc);
                  yys = firstTopState();
                  break;
                }
            }
          yyerror_range[1].getState().yyloc = yys->yyloc;
          if (yys->pred() != YY_NULLPTR)
            yys->destroy ("Error: popping", yyparser);
          yystateStack.setFirstTop(yys->pred());
          yystateStack.pop_back();
        }
      if (firstTopState() == YY_NULLPTR)
        yyFail (yylocp, YY_NULLPTR);
    }

    YYRESULTTAG
    yyprocessOneStack (state_set_index yyk,
                       size_t yyposn, location_type* yylocp)
    {
      while (yystateStack.topAt(yyk) != YY_NULLPTR)
        {
          const state_num yystate = topState(yyk)->yylrState;
          YYCDEBUG << "Stack " << yyk.get()
                   << " Entering state " << yystate << '\n';

          YYASSERT (yystate != YYFINAL);

          if (yy_is_defaulted_state (yystate))
            {
              const rule_num yyrule = yy_default_action (yystate);
              if (yyrule == 0)
                {
                  YYCDEBUG << "Stack " << yyk.get() << " dies.\n";
                  yystateStack.yytops.yymarkStackDeleted (yyk);
                  return yyok;
                }
              const YYRESULTTAG yyflag
                = yyglrReduce (yyk, yyrule, yyimmediate[yyrule]);
              if (yyflag == yyerr)
                {
                  YYCDEBUG << "Stack " << yyk.get() << " dies"
                    " (predicate failure or explicit user error).\n";
                  yystateStack.yytops.yymarkStackDeleted (yyk);
                  return yyok;
                }
              if (yyflag != yyok)
                return yyflag;
            }
          else
            {
              yystateStack.yytops.setLookaheadNeeds(yyk, true);
              yyget_token ();
              const short* yyconflicts;
              const int yyaction = yygetLRActions (yystate, this->yyla.kind (), yyconflicts);

              for (; *yyconflicts != 0; ++yyconflicts)
                {
                  state_set_index yynewStack = yystateStack.yysplitStack (yyk);
                  YYCDEBUG << "Splitting off stack " << yynewStack.get()
                           << " from " << yyk.get() << ".\n";
                  YYRESULTTAG yyflag =
                    yyglrReduce (yynewStack, *yyconflicts, yyimmediate[*yyconflicts]);
                  if (yyflag == yyok)
                    YYCHK (yyprocessOneStack (yynewStack,
                                              yyposn, yylocp));
                  else if (yyflag == yyerr)
                    {
                      YYCDEBUG << "Stack " << yynewStack.get() << " dies.\n";
                      yystateStack.yytops.yymarkStackDeleted (yynewStack);
                    }
                  else
                    return yyflag;
                }

              if (yy_is_shift_action (yyaction))
                break;
              else if (yy_is_error_action (yyaction))
                {
                  YYCDEBUG << "Stack " << yyk.get() << " dies.\n";
                  yystateStack.yytops.yymarkStackDeleted (yyk);
                  break;
                }
              else
                {
                  YYRESULTTAG yyflag
                    = yyglrReduce (yyk, -yyaction, yyimmediate[-yyaction]);
                  if (yyflag == yyerr)
                    {
                      YYCDEBUG << "Stack " << yyk.get() << " dies"
                        " (predicate failure or explicit user error).\n";
                      yystateStack.yytops.yymarkStackDeleted (yyk);
                      break;
                    }
                  else if (yyflag != yyok)
                    return yyflag;
                }
            }
        }
      return yyok;
    }

    /** Perform user action for rule number YYN, with RHS length YYRHSLEN,
     *  and top stack item YYVSP.  YYVALP points to place to put semantic
     *  value ($$), and yylocp points to place for location information
     *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
     *  yyerr for YYERROR, yyabort for YYABORT.  */
    YYRESULTTAG
    yyuserAction (rule_num yyrule, int yyrhslen, glr_stack_item* yyvsp, state_set_index yyk,
                  value_type* yyvalp, location_type* yylocp)
    {
      bool yynormal YY_ATTRIBUTE_UNUSED = !yystateStack.isSplit();
      int yylow = 1;
  YY_USE (yyvalp);
  YY_USE (yylocp);
  YY_USE (tp);
      YY_USE (yyk);
      YY_USE (yyrhslen);
    # undef yyerrok
    # define yyerrok (yyerrState = 0)
    # undef YYACCEPT
    # define YYACCEPT return yyaccept
    # undef YYABORT
    # define YYABORT return yyabort
    # undef YYERROR
    # define YYERROR return yyerrok, yyerr
    # undef YYRECOVERING
    # define YYRECOVERING() (yyerrState != 0)
    # undef yytoken
    # define yytoken this->yyla.kind_
    # undef yyclearin
    # define yyclearin (yytoken = symbol_kind::S_YYEMPTY)
    # undef YYBACKUP
    # define YYBACKUP(Token, Value)                                              \
      return yyparser.error (*yylocp, YY_("syntax error: cannot back up")),     \
             yyerrok, yyerr


      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      // However we really need to prepare yyvsp now if we want to get
      // correct locations, so invoke YYFILL for $1 anyway.
      (void) YYFILL (1-yyrhslen);
      switch (yylhsNonterm (yyrule))
    {
      case symbol_kind::S_78_classfields_1: // classfields.1
        (*yyvalp).emplace< ast::ChunkInterface* > ();
        break;

      case symbol_kind::S_chunks: // chunks
      case symbol_kind::S_classfields: // classfields
        (*yyvalp).emplace< ast::ChunkList* > ();
        break;

      case symbol_kind::S_exp: // exp
        (*yyvalp).emplace< ast::Exp* > ();
        break;

      case symbol_kind::S_tyfield: // tyfield
        (*yyvalp).emplace< ast::Field* > ();
        break;

      case symbol_kind::S_funchunk: // funchunk
        (*yyvalp).emplace< ast::FunctionChunk* > ();
        break;

      case symbol_kind::S_fundec: // fundec
        (*yyvalp).emplace< ast::FunctionDec* > ();
        break;

      case symbol_kind::S_classfield: // classfield
        (*yyvalp).emplace< ast::MethodChunk* > ();
        break;

      case symbol_kind::S_typeid: // typeid
        (*yyvalp).emplace< ast::NameTy* > ();
        break;

      case symbol_kind::S_ty: // ty
        (*yyvalp).emplace< ast::Ty* > ();
        break;

      case symbol_kind::S_tychunk: // tychunk
        (*yyvalp).emplace< ast::TypeChunk* > ();
        break;

      case symbol_kind::S_tydec: // tydec
        (*yyvalp).emplace< ast::TypeDec* > ();
        break;

      case symbol_kind::S_lvalue: // lvalue
        (*yyvalp).emplace< ast::Var* > ();
        break;

      case symbol_kind::S_funfields: // funfields
      case symbol_kind::S_69_funfields_1: // funfields.1
      case symbol_kind::S_varchunk: // varchunk
        (*yyvalp).emplace< ast::VarChunk* > ();
        break;

      case symbol_kind::S_vardec: // vardec
      case symbol_kind::S_funfield: // funfield
        (*yyvalp).emplace< ast::VarDec* > ();
        break;

      case symbol_kind::S_exps: // exps
      case symbol_kind::S_function_param: // function_param
        (*yyvalp).emplace< ast::exps_type* > ();
        break;

      case symbol_kind::S_record_creation: // record_creation
      case symbol_kind::S_record_init: // record_init
        (*yyvalp).emplace< ast::fieldinits_type* > ();
        break;

      case symbol_kind::S_tyfields: // tyfields
      case symbol_kind::S_81_tyfields_1: // tyfields.1
        (*yyvalp).emplace< ast::fields_type* > ();
        break;

      case symbol_kind::S_INT: // "integer"
        (*yyvalp).emplace< int > ();
        break;

      case symbol_kind::S_ID: // "identifier"
        (*yyvalp).emplace< misc::symbol > ();
        break;

      case symbol_kind::S_STRING: // "string"
        (*yyvalp).emplace< std::string > ();
        break;

      default:
        break;
    }

      /* Default location. */
      YYLLOC_DEFAULT ((*yylocp), (yyvsp - yyrhslen), yyrhslen);
      yyerror_range[1].getState().yyloc = *yylocp;

    /* If yyk == -1, we are running a deferred action on a temporary
       stack.  In that case, YY_REDUCE_PRINT must not play with YYFILL,
       so pretend the stack is "normal". */
    YY_REDUCE_PRINT ((yynormal || yyk == create_state_set_index (-1), yyvsp, yyk, yyrule, yyparser));
    #if YY_EXCEPTIONS
      try
      {
    #endif // YY_EXCEPTIONS
      switch (yyrule)
        {
      case 2: // program: exp
#line 253 "parse/parsetiger.yy"
              { tp.ast_ = (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Exp* > (); }
#line 3597 "parse/parsetiger.cc"
    break;

  case 3: // program: chunks
#line 255 "parse/parsetiger.yy"
              { tp.ast_ = (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::ChunkList* > (); }
#line 3603 "parse/parsetiger.cc"
    break;

  case 4: // exps: exp
#line 260 "parse/parsetiger.yy"
        { (*yyvalp).as < ast::exps_type* > () = tp.td_.make_exps_type((static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Exp* > ()); }
#line 3609 "parse/parsetiger.cc"
    break;

  case 5: // exps: exp ";" exps
#line 261 "parse/parsetiger.yy"
                 { (*yyvalp).as < ast::exps_type* > () = (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::exps_type* > (); (*yyvalp).as < ast::exps_type* > ()->insert((*yyvalp).as < ast::exps_type* > ()->begin(), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < ast::Exp* > ()); }
#line 3615 "parse/parsetiger.cc"
    break;

  case 6: // exps: %empty
#line 262 "parse/parsetiger.yy"
          { (*yyvalp).as < ast::exps_type* > () = tp.td_.make_exps_type(); }
#line 3621 "parse/parsetiger.cc"
    break;

  case 7: // record_creation: "identifier" "=" exp
#line 266 "parse/parsetiger.yy"
            { (*yyvalp).as < ast::fieldinits_type* > () = tp.td_.make_fieldinits_type<ast::fieldinits_type>({tp.td_.make_FieldInit((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < misc::symbol > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Exp* > ())}); }
#line 3627 "parse/parsetiger.cc"
    break;

  case 8: // record_creation: "identifier" "=" exp record_init
#line 267 "parse/parsetiger.yy"
                        { (*yyvalp).as < ast::fieldinits_type* > () = (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::fieldinits_type* > ();
                          (*yyvalp).as < ast::fieldinits_type* > ()->push_back({tp.td_.make_FieldInit((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-3)].getState().value ().as < misc::symbol > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-1)].getState().value ().as < ast::Exp* > ())}); }
#line 3634 "parse/parsetiger.cc"
    break;

  case 9: // record_init: "," "identifier" "=" exp
#line 272 "parse/parsetiger.yy"
                              { (*yyvalp).as < ast::fieldinits_type* > () = new ast::fieldinits_type();
                                (*yyvalp).as < ast::fieldinits_type* > ()->push_back({tp.td_.make_FieldInit((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < misc::symbol > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Exp* > ())}); }
#line 3641 "parse/parsetiger.cc"
    break;

  case 10: // record_init: "," "identifier" "=" exp record_init
#line 274 "parse/parsetiger.yy"
                              { (*yyvalp).as < ast::fieldinits_type* > () = (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::fieldinits_type* > (); (*yyvalp).as < ast::fieldinits_type* > ()->push_back({tp.td_.make_FieldInit((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-3)].getState().value ().as < misc::symbol > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-1)].getState().value ().as < ast::Exp* > ())}); }
#line 3647 "parse/parsetiger.cc"
    break;

  case 11: // function_param: exp
#line 278 "parse/parsetiger.yy"
      { (*yyvalp).as < ast::exps_type* > () = new ast::exps_type{(static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Exp* > ()}; }
#line 3653 "parse/parsetiger.cc"
    break;

  case 12: // function_param: exp "," function_param
#line 279 "parse/parsetiger.yy"
                           { (*yyvalp).as < ast::exps_type* > () = (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::exps_type* > (); (*yyvalp).as < ast::exps_type* > ()->push_back((static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < ast::Exp* > ()); }
#line 3659 "parse/parsetiger.cc"
    break;

  case 13: // exp: "integer"
#line 283 "parse/parsetiger.yy"
                { (*yyvalp).as < ast::Exp* > () = tp.td_.make_IntExp((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < int > ()); }
#line 3665 "parse/parsetiger.cc"
    break;

  case 14: // exp: "nil"
#line 285 "parse/parsetiger.yy"
                { (*yyvalp).as < ast::Exp* > () = tp.td_.make_NilExp((*yylocp)); }
#line 3671 "parse/parsetiger.cc"
    break;

  case 15: // exp: "string"
#line 286 "parse/parsetiger.yy"
                { (*yyvalp).as < ast::Exp* > () = tp.td_.make_StringExp((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < std::string > ()); }
#line 3677 "parse/parsetiger.cc"
    break;

  case 16: // exp: typeid "[" exp "]" "of" exp
#line 287 "parse/parsetiger.yy"
                                      { (*yyvalp).as < ast::Exp* > () = tp.td_.make_ArrayExp((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-5)].getState().value ().as < ast::NameTy* > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-3)].getState().value ().as < ast::Exp* > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Exp* > ()); }
#line 3683 "parse/parsetiger.cc"
    break;

  case 17: // exp: typeid "{" "}"
#line 288 "parse/parsetiger.yy"
                                          { (*yyvalp).as < ast::Exp* > () = tp.td_.make_RecordExp((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < ast::NameTy* > (), new ast::fieldinits_type()); }
#line 3689 "parse/parsetiger.cc"
    break;

  case 18: // exp: typeid "{" record_creation "}"
#line 289 "parse/parsetiger.yy"
                                          { (*yyvalp).as < ast::Exp* > () = tp.td_.make_RecordExp((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-3)].getState().value ().as < ast::NameTy* > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-1)].getState().value ().as < ast::fieldinits_type* > ()); }
#line 3695 "parse/parsetiger.cc"
    break;

  case 19: // exp: lvalue
#line 290 "parse/parsetiger.yy"
                { (*yyvalp).as < ast::Exp* > () = (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Var* > (); }
#line 3701 "parse/parsetiger.cc"
    break;

  case 20: // exp: "identifier" "(" ")"
#line 291 "parse/parsetiger.yy"
                       { (*yyvalp).as < ast::Exp* > () = tp.td_.make_CallExp((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < misc::symbol > (), new ast::exps_type()); }
#line 3707 "parse/parsetiger.cc"
    break;

  case 21: // exp: "identifier" "(" function_param ")"
#line 292 "parse/parsetiger.yy"
                                    { (*yyvalp).as < ast::Exp* > () = tp.td_.make_CallExp((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-3)].getState().value ().as < misc::symbol > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-1)].getState().value ().as < ast::exps_type* > ()); }
#line 3713 "parse/parsetiger.cc"
    break;

  case 22: // exp: "-" exp
#line 293 "parse/parsetiger.yy"
                            { (*yyvalp).as < ast::Exp* > () = tp.td_.make_OpExp((*yylocp), tp.td_.make_IntExp(((static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-1)].getState().yyloc), 0), ast::OpExp::Oper::sub, (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Exp* > ()); }
#line 3719 "parse/parsetiger.cc"
    break;

  case 23: // exp: exp "+" exp
#line 294 "parse/parsetiger.yy"
                      { (*yyvalp).as < ast::Exp* > () = tp.td_.make_OpExp((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < ast::Exp* > (), ast::OpExp::Oper::add, (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Exp* > ()); }
#line 3725 "parse/parsetiger.cc"
    break;

  case 24: // exp: exp "-" exp
#line 295 "parse/parsetiger.yy"
                      { (*yyvalp).as < ast::Exp* > () = tp.td_.make_OpExp((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < ast::Exp* > (), ast::OpExp::Oper::sub, (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Exp* > ()); }
#line 3731 "parse/parsetiger.cc"
    break;

  case 25: // exp: exp "*" exp
#line 296 "parse/parsetiger.yy"
                      { (*yyvalp).as < ast::Exp* > () = tp.td_.make_OpExp((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < ast::Exp* > (), ast::OpExp::Oper::mul, (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Exp* > ()); }
#line 3737 "parse/parsetiger.cc"
    break;

  case 26: // exp: exp "/" exp
#line 297 "parse/parsetiger.yy"
                      { (*yyvalp).as < ast::Exp* > () = tp.td_.make_OpExp((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < ast::Exp* > (), ast::OpExp::Oper::div, (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Exp* > ()); }
#line 3743 "parse/parsetiger.cc"
    break;

  case 27: // exp: exp "=" exp
#line 298 "parse/parsetiger.yy"
                      { (*yyvalp).as < ast::Exp* > () = tp.td_.make_OpExp((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < ast::Exp* > (), ast::OpExp::Oper::eq, (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Exp* > ()); }
#line 3749 "parse/parsetiger.cc"
    break;

  case 28: // exp: exp "<>" exp
#line 299 "parse/parsetiger.yy"
                      { (*yyvalp).as < ast::Exp* > () = tp.td_.make_OpExp((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < ast::Exp* > (), ast::OpExp::Oper::ne, (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Exp* > ()); }
#line 3755 "parse/parsetiger.cc"
    break;

  case 29: // exp: exp ">" exp
#line 300 "parse/parsetiger.yy"
                      { (*yyvalp).as < ast::Exp* > () = tp.td_.make_OpExp((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < ast::Exp* > (), ast::OpExp::Oper::gt, (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Exp* > ()); }
#line 3761 "parse/parsetiger.cc"
    break;

  case 30: // exp: exp "<" exp
#line 301 "parse/parsetiger.yy"
                      { (*yyvalp).as < ast::Exp* > () = tp.td_.make_OpExp((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < ast::Exp* > (), ast::OpExp::Oper::lt, (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Exp* > ()); }
#line 3767 "parse/parsetiger.cc"
    break;

  case 31: // exp: exp ">=" exp
#line 302 "parse/parsetiger.yy"
                      { (*yyvalp).as < ast::Exp* > () = tp.td_.make_OpExp((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < ast::Exp* > (), ast::OpExp::Oper::ge, (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Exp* > ()); }
#line 3773 "parse/parsetiger.cc"
    break;

  case 32: // exp: exp "<=" exp
#line 303 "parse/parsetiger.yy"
                      { (*yyvalp).as < ast::Exp* > () = tp.td_.make_OpExp((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < ast::Exp* > (), ast::OpExp::Oper::le, (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Exp* > ()); }
#line 3779 "parse/parsetiger.cc"
    break;

  case 33: // exp: exp "&" exp
#line 304 "parse/parsetiger.yy"
                      { (*yyvalp).as < ast::Exp* > () = tp.td_.make_IfExp(((static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().yyloc), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < ast::Exp* > (),
                                                   tp.td_.make_IfExp(((static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-1)].getState().yyloc), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Exp* > (),
                                                            tp.td_.make_IntExp((*yylocp), 1),
                                                            tp.td_.make_IntExp((*yylocp), 0)),
                                                   tp.td_.make_IntExp((*yylocp), 0)); }
#line 3789 "parse/parsetiger.cc"
    break;

  case 34: // exp: exp "|" exp
#line 309 "parse/parsetiger.yy"
                      { (*yyvalp).as < ast::Exp* > () = tp.td_.make_IfExp(((static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().yyloc), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < ast::Exp* > (),
                                                   tp.td_.make_IntExp((*yylocp), 1),
                                                   tp.td_.make_IfExp(((static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-1)].getState().yyloc), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Exp* > (),
                                                            tp.td_.make_IntExp((*yylocp), 1),
                                                            tp.td_.make_IntExp((*yylocp), 0))); }
#line 3799 "parse/parsetiger.cc"
    break;

  case 35: // exp: "(" exps ")"
#line 314 "parse/parsetiger.yy"
                        { (*yyvalp).as < ast::Exp* > () = tp.td_.make_SeqExp((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-1)].getState().value ().as < ast::exps_type* > ()); }
#line 3805 "parse/parsetiger.cc"
    break;

  case 36: // exp: lvalue ":=" exp
#line 315 "parse/parsetiger.yy"
                      { (*yyvalp).as < ast::Exp* > () = tp.td_.make_AssignExp((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < ast::Var* > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Exp* > ()); }
#line 3811 "parse/parsetiger.cc"
    break;

  case 37: // exp: "if" exp "then" exp
#line 316 "parse/parsetiger.yy"
                     { (*yyvalp).as < ast::Exp* > () = tp.td_.make_IfExp((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < ast::Exp* > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Exp* > ()); }
#line 3817 "parse/parsetiger.cc"
    break;

  case 38: // exp: "if" exp "then" exp "else" exp
#line 317 "parse/parsetiger.yy"
                             { (*yyvalp).as < ast::Exp* > () = tp.td_.make_IfExp((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-4)].getState().value ().as < ast::Exp* > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < ast::Exp* > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Exp* > ()); }
#line 3823 "parse/parsetiger.cc"
    break;

  case 39: // exp: "while" exp "do" exp
#line 318 "parse/parsetiger.yy"
                      { (*yyvalp).as < ast::Exp* > () = tp.td_.make_WhileExp((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < ast::Exp* > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Exp* > ()); }
#line 3829 "parse/parsetiger.cc"
    break;

  case 40: // exp: "for" "identifier" ":=" exp "to" exp "do" exp
#line 319 "parse/parsetiger.yy"
                                    { (*yyvalp).as < ast::Exp* > () = tp.td_.make_ForExp((*yylocp), tp.td_.make_VarDec(((static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-6)].getState().yyloc), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-6)].getState().value ().as < misc::symbol > (), nullptr, (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-4)].getState().value ().as < ast::Exp* > ()), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < ast::Exp* > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Exp* > ()); }
#line 3835 "parse/parsetiger.cc"
    break;

  case 41: // exp: "break"
#line 320 "parse/parsetiger.yy"
          { (*yyvalp).as < ast::Exp* > () = tp.td_.make_BreakExp((*yylocp)); }
#line 3841 "parse/parsetiger.cc"
    break;

  case 42: // exp: "let" chunks "in" exps "end"
#line 321 "parse/parsetiger.yy"
                           { (*yyvalp).as < ast::Exp* > () = tp.td_.make_LetExp((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-3)].getState().value ().as < ast::ChunkList* > (), tp.td_.make_SeqExp((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-1)].getState().value ().as < ast::exps_type* > ())); }
#line 3847 "parse/parsetiger.cc"
    break;

  case 43: // exp: "new" typeid
#line 322 "parse/parsetiger.yy"
                { (*yyvalp).as < ast::Exp* > () = tp.td_.make_ObjectExp((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::NameTy* > ()); }
#line 3853 "parse/parsetiger.cc"
    break;

  case 44: // exp: lvalue "." "identifier" "(" ")"
#line 323 "parse/parsetiger.yy"
                                { (*yyvalp).as < ast::Exp* > () = tp.td_.make_MethodCallExp((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < misc::symbol > (), new ast::exps_type(), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-4)].getState().value ().as < ast::Var* > ()); }
#line 3859 "parse/parsetiger.cc"
    break;

  case 45: // exp: lvalue "." "identifier" "(" function_param ")"
#line 324 "parse/parsetiger.yy"
                                                { (*yyvalp).as < ast::Exp* > () = tp.td_.make_MethodCallExp((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-3)].getState().value ().as < misc::symbol > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-1)].getState().value ().as < ast::exps_type* > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-5)].getState().value ().as < ast::Var* > ()); }
#line 3865 "parse/parsetiger.cc"
    break;

  case 46: // exp: "_cast" "(" exp "," ty ")"
#line 325 "parse/parsetiger.yy"
                                    { (*yyvalp).as < ast::Exp* > () = tp.td_.make_CastExp((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-3)].getState().value ().as < ast::Exp* > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-1)].getState().value ().as < ast::Ty* > ()); }
#line 3871 "parse/parsetiger.cc"
    break;

  case 47: // exp: "_exp" "(" "integer" ")"
#line 326 "parse/parsetiger.yy"
                          { (*yyvalp).as < ast::Exp* > () = metavar<ast::Exp>(tp, (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-1)].getState().value ().as < int > ()); }
#line 3877 "parse/parsetiger.cc"
    break;

  case 48: // lvalue: "identifier"
#line 330 "parse/parsetiger.yy"
       { (*yyvalp).as < ast::Var* > () = tp.td_.make_SimpleVar((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < misc::symbol > ()); }
#line 3883 "parse/parsetiger.cc"
    break;

  case 49: // lvalue: lvalue "." "identifier"
#line 331 "parse/parsetiger.yy"
                  { (*yyvalp).as < ast::Var* > () = tp.td_.make_FieldVar((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < ast::Var* > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < misc::symbol > ()); }
#line 3889 "parse/parsetiger.cc"
    break;

  case 50: // lvalue: lvalue "[" exp "]"
#line 332 "parse/parsetiger.yy"
                             { (*yyvalp).as < ast::Var* > () = tp.td_.make_SubscriptVar((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-3)].getState().value ().as < ast::Var* > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-1)].getState().value ().as < ast::Exp* > ()); }
#line 3895 "parse/parsetiger.cc"
    break;

  case 51: // lvalue: "_lvalue" "(" "integer" ")"
#line 333 "parse/parsetiger.yy"
                             { (*yyvalp).as < ast::Var* > () = metavar<ast::Var>(tp, (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-1)].getState().value ().as < int > ()); }
#line 3901 "parse/parsetiger.cc"
    break;

  case 52: // vardec: "var" "identifier" ":=" exp
#line 337 "parse/parsetiger.yy"
                    { (*yyvalp).as < ast::VarDec* > () = tp.td_.make_VarDec((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < misc::symbol > (), nullptr, (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Exp* > ()); }
#line 3907 "parse/parsetiger.cc"
    break;

  case 53: // vardec: "var" "identifier" ":" typeid ":=" exp
#line 338 "parse/parsetiger.yy"
                                 { (*yyvalp).as < ast::VarDec* > () = tp.td_.make_VarDec((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-4)].getState().value ().as < misc::symbol > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < ast::NameTy* > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Exp* > ()); }
#line 3913 "parse/parsetiger.cc"
    break;

  case 54: // fundec: "function" "identifier" "(" funfields ")" "=" exp
#line 344 "parse/parsetiger.yy"
                                               { (*yyvalp).as < ast::FunctionDec* > () = tp.td_.make_FunctionDec((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-5)].getState().value ().as < misc::symbol > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-3)].getState().value ().as < ast::VarChunk* > (), nullptr,(static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Exp* > ()); }
#line 3919 "parse/parsetiger.cc"
    break;

  case 55: // fundec: "function" "identifier" "(" funfields ")" ":" typeid "=" exp
#line 345 "parse/parsetiger.yy"
                                                            { (*yyvalp).as < ast::FunctionDec* > () = tp.td_.make_FunctionDec((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-7)].getState().value ().as < misc::symbol > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-5)].getState().value ().as < ast::VarChunk* > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < ast::NameTy* > (),(static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Exp* > ()); }
#line 3925 "parse/parsetiger.cc"
    break;

  case 56: // fundec: "primitive" "identifier" "(" funfields ")"
#line 346 "parse/parsetiger.yy"
                                         { (*yyvalp).as < ast::FunctionDec* > () = tp.td_.make_FunctionDec((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-3)].getState().value ().as < misc::symbol > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-1)].getState().value ().as < ast::VarChunk* > (), nullptr, nullptr); }
#line 3931 "parse/parsetiger.cc"
    break;

  case 57: // fundec: "primitive" "identifier" "(" funfields ")" ":" typeid
#line 347 "parse/parsetiger.yy"
                                                      { (*yyvalp).as < ast::FunctionDec* > () = tp.td_.make_FunctionDec((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-5)].getState().value ().as < misc::symbol > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-3)].getState().value ().as < ast::VarChunk* > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::NameTy* > (), nullptr); }
#line 3937 "parse/parsetiger.cc"
    break;

  case 58: // funfields: %empty
#line 351 "parse/parsetiger.yy"
                       { (*yyvalp).as < ast::VarChunk* > () = tp.td_.make_VarChunk((*yylocp)); }
#line 3943 "parse/parsetiger.cc"
    break;

  case 59: // funfields: funfields.1
#line 352 "parse/parsetiger.yy"
                        { (*yyvalp).as < ast::VarChunk* > () = (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::VarChunk* > (); }
#line 3949 "parse/parsetiger.cc"
    break;

  case 60: // funfields.1: funfields.1 "," funfield
#line 356 "parse/parsetiger.yy"
                           { (*yyvalp).as < ast::VarChunk* > () = (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < ast::VarChunk* > (); (*yyvalp).as < ast::VarChunk* > ()->emplace_back(*(static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::VarDec* > ()); }
#line 3955 "parse/parsetiger.cc"
    break;

  case 61: // funfields.1: funfield
#line 357 "parse/parsetiger.yy"
                           { (*yyvalp).as < ast::VarChunk* > () = tp.td_.make_VarChunk((*yylocp)); (*yyvalp).as < ast::VarChunk* > ()->emplace_back(*(static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::VarDec* > ());}
#line 3961 "parse/parsetiger.cc"
    break;

  case 62: // funfield: "identifier" ":" typeid
#line 361 "parse/parsetiger.yy"
                    { (*yyvalp).as < ast::VarDec* > () = tp.td_.make_VarDec((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < misc::symbol > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::NameTy* > (), nullptr); }
#line 3967 "parse/parsetiger.cc"
    break;

  case 63: // funchunk: fundec
#line 365 "parse/parsetiger.yy"
                       { (*yyvalp).as < ast::FunctionChunk* > () = tp.td_.make_FunctionChunk(((static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().yyloc)); (*yyvalp).as < ast::FunctionChunk* > ()->push_front(*(static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::FunctionDec* > ()); }
#line 3973 "parse/parsetiger.cc"
    break;

  case 64: // funchunk: fundec funchunk
#line 366 "parse/parsetiger.yy"
                        { (*yyvalp).as < ast::FunctionChunk* > () = (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::FunctionChunk* > (); (*yyvalp).as < ast::FunctionChunk* > ()->push_front(*(static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-1)].getState().value ().as < ast::FunctionDec* > ()); }
#line 3979 "parse/parsetiger.cc"
    break;

  case 65: // varchunk: vardec
#line 370 "parse/parsetiger.yy"
                       { (*yyvalp).as < ast::VarChunk* > () = tp.td_.make_VarChunk(((static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().yyloc)); (*yyvalp).as < ast::VarChunk* > ()->push_front(*(static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::VarDec* > ()); }
#line 3985 "parse/parsetiger.cc"
    break;

  case 66: // chunks: %empty
#line 393 "parse/parsetiger.yy"
                          { (*yyvalp).as < ast::ChunkList* > () = tp.td_.make_ChunkList((*yylocp)); }
#line 3991 "parse/parsetiger.cc"
    break;

  case 67: // chunks: tychunk chunks
#line 394 "parse/parsetiger.yy"
                          { (*yyvalp).as < ast::ChunkList* > () = (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::ChunkList* > (); (*yyvalp).as < ast::ChunkList* > ()->push_front((static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-1)].getState().value ().as < ast::TypeChunk* > ()); }
#line 3997 "parse/parsetiger.cc"
    break;

  case 68: // chunks: funchunk chunks
#line 396 "parse/parsetiger.yy"
                          { (*yyvalp).as < ast::ChunkList* > () = (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::ChunkList* > (); (*yyvalp).as < ast::ChunkList* > ()->push_front((static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-1)].getState().value ().as < ast::FunctionChunk* > ()); }
#line 4003 "parse/parsetiger.cc"
    break;

  case 69: // chunks: varchunk chunks
#line 397 "parse/parsetiger.yy"
                          { (*yyvalp).as < ast::ChunkList* > () = (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::ChunkList* > (); (*yyvalp).as < ast::ChunkList* > ()->push_front((static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-1)].getState().value ().as < ast::VarChunk* > ()); }
#line 4009 "parse/parsetiger.cc"
    break;

  case 70: // chunks: "_chunks" "(" "integer" ")" chunks
#line 398 "parse/parsetiger.yy"
                                  { (*yyvalp).as < ast::ChunkList* > () = (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::ChunkList* > (); (*yyvalp).as < ast::ChunkList* > ()->splice_front(*metavar<ast::ChunkList>(tp, (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < int > ())); }
#line 4015 "parse/parsetiger.cc"
    break;

  case 71: // chunks: "import" "string" chunks
#line 399 "parse/parsetiger.yy"
                          { (*yyvalp).as < ast::ChunkList* > () = tp.parse_import((static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-1)].getState().value ().as < std::string > (), (*yylocp)); }
#line 4021 "parse/parsetiger.cc"
    break;

  case 72: // tychunk: tydec
#line 409 "parse/parsetiger.yy"
                      { (*yyvalp).as < ast::TypeChunk* > () = tp.td_.make_TypeChunk(((static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().yyloc)); (*yyvalp).as < ast::TypeChunk* > ()->push_front(*(static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::TypeDec* > ()); }
#line 4027 "parse/parsetiger.cc"
    break;

  case 73: // tychunk: tydec tychunk
#line 410 "parse/parsetiger.yy"
                      { (*yyvalp).as < ast::TypeChunk* > () = (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::TypeChunk* > (); (*yyvalp).as < ast::TypeChunk* > ()->push_front(*(static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-1)].getState().value ().as < ast::TypeDec* > ()); }
#line 4033 "parse/parsetiger.cc"
    break;

  case 74: // tydec: "type" "identifier" "=" ty
#line 415 "parse/parsetiger.yy"
                   { (*yyvalp).as < ast::TypeDec* > () = tp.td_.make_TypeDec((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < misc::symbol > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Ty* > ()); }
#line 4039 "parse/parsetiger.cc"
    break;

  case 75: // tydec: "class" "identifier" "{" classfields "}"
#line 416 "parse/parsetiger.yy"
                                     { (*yyvalp).as < ast::TypeDec* > () = tp.td_.make_TypeDec((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-3)].getState().value ().as < misc::symbol > (), tp.td_.make_ClassTy((*yylocp), tp.td_.make_NameTy(((static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-4)].getState().yyloc), "Object"), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-1)].getState().value ().as < ast::ChunkList* > ())); }
#line 4045 "parse/parsetiger.cc"
    break;

  case 76: // tydec: "class" "identifier" "extends" typeid "{" classfields "}"
#line 417 "parse/parsetiger.yy"
                                                    { (*yyvalp).as < ast::TypeDec* > () = tp.td_.make_TypeDec((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-5)].getState().value ().as < misc::symbol > (), tp.td_.make_ClassTy((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-3)].getState().value ().as < ast::NameTy* > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-1)].getState().value ().as < ast::ChunkList* > ())); }
#line 4051 "parse/parsetiger.cc"
    break;

  case 77: // ty: typeid
#line 421 "parse/parsetiger.yy"
                       { (*yyvalp).as < ast::Ty* > () = (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::NameTy* > (); }
#line 4057 "parse/parsetiger.cc"
    break;

  case 78: // ty: "{" tyfields "}"
#line 422 "parse/parsetiger.yy"
                       { (*yyvalp).as < ast::Ty* > () = tp.td_.make_RecordTy((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-1)].getState().value ().as < ast::fields_type* > ()); }
#line 4063 "parse/parsetiger.cc"
    break;

  case 79: // ty: "array" "of" typeid
#line 423 "parse/parsetiger.yy"
                       { (*yyvalp).as < ast::Ty* > () = tp.td_.make_ArrayTy((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::NameTy* > ()); }
#line 4069 "parse/parsetiger.cc"
    break;

  case 80: // ty: "class" "{" "}"
#line 424 "parse/parsetiger.yy"
                      { (*yyvalp).as < ast::Ty* > () = tp.td_.make_ClassTy((*yylocp), tp.td_.make_NameTy(((static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().yyloc), "Object"), nullptr); }
#line 4075 "parse/parsetiger.cc"
    break;

  case 81: // ty: "class" "{" classfields "}"
#line 425 "parse/parsetiger.yy"
                                  { (*yyvalp).as < ast::Ty* > () = tp.td_.make_ClassTy((*yylocp), tp.td_.make_NameTy(((static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-3)].getState().yyloc), "Object"), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-1)].getState().value ().as < ast::ChunkList* > ()); }
#line 4081 "parse/parsetiger.cc"
    break;

  case 82: // ty: "class" "extends" typeid "{" "}"
#line 426 "parse/parsetiger.yy"
                                      { (*yyvalp).as < ast::Ty* > () = tp.td_.make_ClassTy((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < ast::NameTy* > (), nullptr); }
#line 4087 "parse/parsetiger.cc"
    break;

  case 83: // ty: "class" "extends" typeid "{" classfields "}"
#line 427 "parse/parsetiger.yy"
                                                  { (*yyvalp).as < ast::Ty* > () = tp.td_.make_ClassTy((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-3)].getState().value ().as < ast::NameTy* > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-1)].getState().value ().as < ast::ChunkList* > ()); }
#line 4093 "parse/parsetiger.cc"
    break;

  case 84: // classfields: classfields.1
#line 431 "parse/parsetiger.yy"
                { (*yyvalp).as < ast::ChunkList* > () = tp.td_.make_ChunkList((*yylocp)); (*yyvalp).as < ast::ChunkList* > ()->push_front((static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::ChunkInterface* > ()); }
#line 4099 "parse/parsetiger.cc"
    break;

  case 85: // classfields: classfields.1 classfields
#line 432 "parse/parsetiger.yy"
                            { (*yyvalp).as < ast::ChunkList* > () = (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::ChunkList* > (); (*yyvalp).as < ast::ChunkList* > ()->push_front((static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-1)].getState().value ().as < ast::ChunkInterface* > ()); }
#line 4105 "parse/parsetiger.cc"
    break;

  case 86: // classfields.1: varchunk
#line 435 "parse/parsetiger.yy"
           { (*yyvalp).as < ast::ChunkInterface* > () = (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::VarChunk* > (); }
#line 4111 "parse/parsetiger.cc"
    break;

  case 87: // classfields.1: classfield
#line 436 "parse/parsetiger.yy"
             { (*yyvalp).as < ast::ChunkInterface* > () = (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::MethodChunk* > (); }
#line 4117 "parse/parsetiger.cc"
    break;

  case 88: // classfield: "method" "identifier" "(" funfields ")" "=" exp
#line 439 "parse/parsetiger.yy"
                                            { (*yyvalp).as < ast::MethodChunk* > () = tp.td_.make_MethodChunk(((static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-6)].getState().yyloc)); (*yyvalp).as < ast::MethodChunk* > ()->push_front(*tp.td_.make_MethodDec((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-5)].getState().value ().as < misc::symbol > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-3)].getState().value ().as < ast::VarChunk* > (), nullptr, (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Exp* > ())); }
#line 4123 "parse/parsetiger.cc"
    break;

  case 89: // classfield: "method" "identifier" "(" funfields ")" ":" typeid "=" exp
#line 440 "parse/parsetiger.yy"
                                                        { (*yyvalp).as < ast::MethodChunk* > () = tp.td_.make_MethodChunk(((static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-8)].getState().yyloc)); (*yyvalp).as < ast::MethodChunk* > ()->push_front(*tp.td_.make_MethodDec((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-7)].getState().value ().as < misc::symbol > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-5)].getState().value ().as < ast::VarChunk* > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < ast::NameTy* > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Exp* > ())); }
#line 4129 "parse/parsetiger.cc"
    break;

  case 90: // tyfields: %empty
#line 444 "parse/parsetiger.yy"
                       { (*yyvalp).as < ast::fields_type* > () = tp.td_.make_fields_type(); }
#line 4135 "parse/parsetiger.cc"
    break;

  case 91: // tyfields: tyfields.1
#line 445 "parse/parsetiger.yy"
                       { (*yyvalp).as < ast::fields_type* > () = (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::fields_type* > (); }
#line 4141 "parse/parsetiger.cc"
    break;

  case 92: // tyfields.1: tyfields.1 "," tyfield
#line 449 "parse/parsetiger.yy"
                         { (*yyvalp).as < ast::fields_type* > () = (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < ast::fields_type* > (); (*yyvalp).as < ast::fields_type* > ()->emplace_back((static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Field* > ()); }
#line 4147 "parse/parsetiger.cc"
    break;

  case 93: // tyfields.1: tyfield
#line 450 "parse/parsetiger.yy"
                         { (*yyvalp).as < ast::fields_type* > () = tp.td_.make_fields_type((static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::Field* > ()); }
#line 4153 "parse/parsetiger.cc"
    break;

  case 94: // tyfield: "identifier" ":" typeid
#line 454 "parse/parsetiger.yy"
                    { (*yyvalp).as < ast::Field* > () = tp.td_.make_Field((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-2)].getState().value ().as < misc::symbol > (), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < ast::NameTy* > ()); }
#line 4159 "parse/parsetiger.cc"
    break;

  case 95: // typeid: "identifier"
#line 459 "parse/parsetiger.yy"
                        { (*yyvalp).as < ast::NameTy* > () = tp.td_.make_NameTy((*yylocp), (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (0)].getState().value ().as < misc::symbol > ()); }
#line 4165 "parse/parsetiger.cc"
    break;

  case 96: // typeid: "_namety" "(" "integer" ")"
#line 462 "parse/parsetiger.yy"
                        { (*yyvalp).as < ast::NameTy* > () = metavar<ast::NameTy>(tp, (static_cast<glr_stack_item const *>(yyvsp))[YYFILL (-1)].getState().value ().as < int > ()); }
#line 4171 "parse/parsetiger.cc"
    break;


#line 4175 "parse/parsetiger.cc"

          default: break;
        }
    #if YY_EXCEPTIONS
      }
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          *yylocp = yyexc.location;
          yyparser.error (*yylocp, yyexc.what ());
          YYERROR;
        }
    #endif // YY_EXCEPTIONS
    YY_SYMBOL_PRINT ("-> $$ =", yylhsNonterm (yyrule), *yyvalp, *yylocp);

      return yyok;
    # undef yyerrok
    # undef YYABORT
    # undef YYACCEPT
    # undef YYERROR
    # undef YYBACKUP
    # undef yytoken
    # undef yyclearin
    # undef YYRECOVERING
    }

    YYRESULTTAG
    yyresolveStack ()
    {
      if (yystateStack.isSplit ())
        {
          int yyn = 0;
          for (glr_state* yys = firstTopState ();
               yys != yystateStack.yysplitPoint;
               yys = yys->pred ())
            yyn += 1;
          YYCHK (yyresolveStates (*firstTopState (), yyn));
        }
      return yyok;
    }

    /** Pop the symbols consumed by reduction #YYRULE from the top of stack
     *  #YYK of *YYSTACKP, and perform the appropriate semantic action on their
     *  semantic values.  Assumes that all ambiguities in semantic values
     *  have been previously resolved.  Set *YYVALP to the resulting value,
     *  and *YYLOCP to the computed location (if any).  Return value is as
     *  for userAction.  */
    YYRESULTTAG
    yydoAction (state_set_index yyk, rule_num yyrule,
                value_type* yyvalp, location_type* yylocp)
    {
      const int yynrhs = yyrhsLength (yyrule);

      if (!yystateStack.isSplit())
        {
          /* Standard special case: single stack.  */
          YYASSERT (yyk.get() == 0);
          glr_stack_item* yyrhs = yystateStack.firstTop()->asItem();
          const YYRESULTTAG res
            = yyuserAction (yyrule, yynrhs, yyrhs, yyk, yyvalp, yylocp);
          yystateStack.pop_back(static_cast<size_t>(yynrhs));
          yystateStack.setFirstTop(&yystateStack[yystateStack.size() - 1].getState());
          return res;
        }
      else
        {
          glr_stack_item yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
          glr_state* yys = yystateStack.topAt(yyk);
          yyrhsVals[YYMAXRHS + YYMAXLEFT].getState().setPred(yys);
          if (yynrhs == 0)
            /* Set default location.  */
            yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].getState().yyloc = yys->yyloc;
          for (int yyi = 0; yyi < yynrhs; yyi += 1)
            {
              yys = yys->pred();
              YYASSERT (yys != YY_NULLPTR);
            }
          yystateStack.yyupdateSplit (*yys);
          yystateStack.setTopAt(yyk, yys);
          return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                               yyk,
                               yyvalp, yylocp);
        }
    }

    /** Pop items off stack #YYK of *YYSTACKP according to grammar rule YYRULE,
     *  and push back on the resulting nonterminal symbol.  Perform the
     *  semantic action associated with YYRULE and store its value with the
     *  newly pushed state, if YYFORCEEVAL or if *YYSTACKP is currently
     *  unambiguous.  Otherwise, store the deferred semantic action with
     *  the new state.  If the new state would have an identical input
     *  position, LR state, and predecessor to an existing state on the stack,
     *  it is identified with that existing state, eliminating stack #YYK from
     *  *YYSTACKP.  In this case, the semantic value is
     *  added to the options for the existing state's semantic value.
     */
    YYRESULTTAG
    yyglrReduce (state_set_index yyk, rule_num yyrule, bool yyforceEval)
    {
      size_t yyposn = topState(yyk)->yyposn;

      if (yyforceEval || !yystateStack.isSplit())
        {
          value_type val;
          location_type loc;

          YYRESULTTAG yyflag = yydoAction (yyk, yyrule, &val, &loc);
          if (yyflag == yyerr && yystateStack.isSplit())
            {
              YYCDEBUG << "Parse on stack " << yyk.get ()
                       << " rejected by rule " << yyrule - 1
                       << " (line " << int (yyrline[yyrule]) << ").\n";
            }
          if (yyflag != yyok)
            return yyflag;
          yyglrShift (yyk,
                      yyLRgotoState (topState(yyk)->yylrState,
                                     yylhsNonterm (yyrule)),
                      yyposn, val, loc);
          // FIXME: User destructors.
          // Value type destructor.
          switch (yylhsNonterm (yyrule))
    {
      case symbol_kind::S_78_classfields_1: // classfields.1
        val.template destroy< ast::ChunkInterface* > ();
        break;

      case symbol_kind::S_chunks: // chunks
      case symbol_kind::S_classfields: // classfields
        val.template destroy< ast::ChunkList* > ();
        break;

      case symbol_kind::S_exp: // exp
        val.template destroy< ast::Exp* > ();
        break;

      case symbol_kind::S_tyfield: // tyfield
        val.template destroy< ast::Field* > ();
        break;

      case symbol_kind::S_funchunk: // funchunk
        val.template destroy< ast::FunctionChunk* > ();
        break;

      case symbol_kind::S_fundec: // fundec
        val.template destroy< ast::FunctionDec* > ();
        break;

      case symbol_kind::S_classfield: // classfield
        val.template destroy< ast::MethodChunk* > ();
        break;

      case symbol_kind::S_typeid: // typeid
        val.template destroy< ast::NameTy* > ();
        break;

      case symbol_kind::S_ty: // ty
        val.template destroy< ast::Ty* > ();
        break;

      case symbol_kind::S_tychunk: // tychunk
        val.template destroy< ast::TypeChunk* > ();
        break;

      case symbol_kind::S_tydec: // tydec
        val.template destroy< ast::TypeDec* > ();
        break;

      case symbol_kind::S_lvalue: // lvalue
        val.template destroy< ast::Var* > ();
        break;

      case symbol_kind::S_funfields: // funfields
      case symbol_kind::S_69_funfields_1: // funfields.1
      case symbol_kind::S_varchunk: // varchunk
        val.template destroy< ast::VarChunk* > ();
        break;

      case symbol_kind::S_vardec: // vardec
      case symbol_kind::S_funfield: // funfield
        val.template destroy< ast::VarDec* > ();
        break;

      case symbol_kind::S_exps: // exps
      case symbol_kind::S_function_param: // function_param
        val.template destroy< ast::exps_type* > ();
        break;

      case symbol_kind::S_record_creation: // record_creation
      case symbol_kind::S_record_init: // record_init
        val.template destroy< ast::fieldinits_type* > ();
        break;

      case symbol_kind::S_tyfields: // tyfields
      case symbol_kind::S_81_tyfields_1: // tyfields.1
        val.template destroy< ast::fields_type* > ();
        break;

      case symbol_kind::S_INT: // "integer"
        val.template destroy< int > ();
        break;

      case symbol_kind::S_ID: // "identifier"
        val.template destroy< misc::symbol > ();
        break;

      case symbol_kind::S_STRING: // "string"
        val.template destroy< std::string > ();
        break;

      default:
        break;
    }

        }
      else
        {
          glr_state *yys = yystateStack.topAt(yyk);
          glr_state *yys0 = yys;
          for (int yyn = yyrhsLength (yyrule); 0 < yyn; yyn -= 1)
            {
              yys = yys->pred();
              YYASSERT (yys != YY_NULLPTR);
            }
          yystateStack.yyupdateSplit (*yys);
          state_num yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
          YYCDEBUG << "Reduced stack " << yyk.get ()
                   << " by rule " << yyrule - 1 << " (line " << int (yyrline[yyrule])
                   << "); action deferred.  Now in state " << yynewLRState
                   << ".\n";
          for (state_set_index yyi = create_state_set_index(0); yyi.uget() < yystateStack.numTops(); ++yyi)
            if (yyi != yyk && yystateStack.topAt(yyi) != YY_NULLPTR)
              {
                const glr_state* yysplit = yystateStack.yysplitPoint;
                glr_state* yyp = yystateStack.topAt(yyi);
                while (yyp != yys && yyp != yysplit
                       && yyp->yyposn >= yyposn)
                  {
                    if (yyp->yylrState == yynewLRState
                        && yyp->pred() == yys)
                      {
                        yyaddDeferredAction (yyk, yyp, yys0, yyrule);
                        yystateStack.yytops.yymarkStackDeleted (yyk);
                        YYCDEBUG << "Merging stack " << yyk.get ()
                                 << " into stack " << yyi.get () << ".\n";
                        return yyok;
                      }
                    yyp = yyp->pred();
                  }
              }
          yystateStack.setTopAt(yyk, yys);
          yyglrShiftDefer (yyk, yynewLRState, yyposn, yys0, yyrule);
        }
      return yyok;
    }

    /** Shift stack #YYK of *YYSTACKP, to a new state corresponding to LR
     *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
     *  semantic value of YYRHS under the action for YYRULE.  */
    void
    yyglrShiftDefer (state_set_index yyk, state_num yylrState,
                     size_t yyposn, glr_state* yyrhs, rule_num yyrule)
    {
      glr_state& yynewState = yystateStack.yynewGLRState (
        glr_state (yylrState, yyposn));
      yynewState.setPred (yystateStack.topAt (yyk));
      yystateStack.setTopAt (yyk, &yynewState);

      /* Invokes yyreserveStack.  */
      yyaddDeferredAction (yyk, &yynewState, yyrhs, yyrule);
    }

    /** Shift to a new state on stack #YYK of *YYSTACKP, corresponding to LR
     * state YYLRSTATE, at input position YYPOSN, with (resolved) semantic
     * value YYVAL_ARG and source location YYLOC_ARG.  */
    void
    yyglrShift (state_set_index yyk, state_num yylrState,
                size_t yyposn,
                const value_type& yyval_arg, const location_type& yyloc_arg)
    {
      glr_state& yynewState = yystateStack.yynewGLRState (
        glr_state (yylrState, yyposn, yyval_arg, yyloc_arg));
      yynewState.setPred (yystateStack.topAt(yyk));
      yystateStack.setTopAt (yyk, &yynewState);
      yyreserveGlrStack ();
    }

#if PARSEDEBUG
    void
    yypstack (state_set_index yyk) const
    {
      yystateStack.yypstates (yystateStack.topAt (yyk));
    }
#endif

    glr_state* topState(state_set_index i) {
      return yystateStack.topAt(i);
    }

    glr_state* firstTopState() {
      return yystateStack.firstTop();
    }

  private:

    void popall_ ()
    {
      /* If the stack is well-formed, pop the stack until it is empty,
         destroying its entries as we go.  But free the stack regardless
         of whether it is well-formed.  */
      for (state_set_index k = create_state_set_index(0); k.uget() < yystateStack.numTops(); k += 1)
        if (yystateStack.topAt(k) != YY_NULLPTR)
          {
            while (yystateStack.topAt(k) != YY_NULLPTR)
              {
                glr_state* state = topState(k);
                yyerror_range[1].getState().yyloc = state->yyloc;
                if (state->pred() != YY_NULLPTR)
                  state->destroy ("Cleanup: popping", yyparser);
                yystateStack.setTopAt(k, state->pred());
                yystateStack.pop_back();
              }
              break;
          }
    }

    /** Resolve the previous YYN states starting at and including state YYS
     *  on *YYSTACKP. If result != yyok, some states may have been left
     *  unresolved possibly with empty semantic option chains.  Regardless
     *  of whether result = yyok, each state has been left with consistent
     *  data so that destroy can be invoked if necessary.  */
    YYRESULTTAG
    yyresolveStates (glr_state& yys, int yyn)
    {
      if (0 < yyn)
        {
          YYASSERT (yys.pred() != YY_NULLPTR);
          YYCHK (yyresolveStates (*yys.pred(), yyn-1));
          if (! yys.yyresolved)
            YYCHK (yyresolveValue (yys));
        }
      return yyok;
    }

    static void
    yyuserMerge (int yyn, value_type& yy0, value_type& yy1)
    {
      YY_USE (yy0);
      YY_USE (yy1);

      switch (yyn)
        {

          default: break;
        }
    }

    /** Resolve the ambiguity represented in state YYS in *YYSTACKP,
     *  perform the indicated actions, and set the semantic value of YYS.
     *  If result != yyok, the chain of semantic options in YYS has been
     *  cleared instead or it has been left unmodified except that
     *  redundant options may have been removed.  Regardless of whether
     *  result = yyok, YYS has been left with consistent data so that
     *  destroy can be invoked if necessary.  */
    YYRESULTTAG
    yyresolveValue (glr_state& yys)
    {
      semantic_option* yybest = yys.firstVal();
      YYASSERT(yybest != YY_NULLPTR);
      bool yymerge = false;
      YYRESULTTAG yyflag;
      location_type *yylocp = &yys.yyloc;

      semantic_option* yypPrev = yybest;
      for (semantic_option* yyp = yybest->next();
           yyp != YY_NULLPTR; )
        {
          if (yybest->isIdenticalTo (*yyp))
            {
              yybest->mergeWith (*yyp);
              yypPrev->setNext(yyp->next());
              yyp = yypPrev->next();
            }
          else
            {
              switch (yypreference (*yybest, *yyp))
                {
                case 0:
                  yyresolveLocations (yys, 1);
                  return yystateStack.yyreportAmbiguity (*yybest, *yyp, yyparser, *yylocp);
                  break;
                case 1:
                  yymerge = true;
                  break;
                case 2:
                  break;
                case 3:
                  yybest = yyp;
                  yymerge = false;
                  break;
                default:
                  /* This cannot happen so it is not worth a YYASSERT (false),
                     but some compilers complain if the default case is
                     omitted.  */
                  break;
                }
              yypPrev = yyp;
              yyp = yyp->next();
            }
        }

      value_type val;
      if (yymerge)
        {
          int yyprec = yydprec[yybest->yyrule];
          yyflag = yyresolveAction (*yybest, &val, yylocp);
          if (yyflag == yyok)
            for (semantic_option* yyp = yybest->next();
                 yyp != YY_NULLPTR;
                 yyp = yyp->next())
              {
                if (yyprec == yydprec[yyp->yyrule])
                  {
                    value_type yyval_other;
                    location_type yydummy;
                    yyflag = yyresolveAction (*yyp, &yyval_other, &yydummy);
                    if (yyflag != yyok)
                      {
                        yyparser.yy_destroy_ ("Cleanup: discarding incompletely merged value for",
                                              yy_accessing_symbol (yys.yylrState),
                                              this->yyla.value, *yylocp);
                        break;
                      }
                    yyuserMerge (yymerger[yyp->yyrule], val, yyval_other);
                    // FIXME: User destructors.
                    // Value type destructor.
                    switch (yy_accessing_symbol (yys.yylrState))
    {
      case symbol_kind::S_78_classfields_1: // classfields.1
        yyval_other.template destroy< ast::ChunkInterface* > ();
        break;

      case symbol_kind::S_chunks: // chunks
      case symbol_kind::S_classfields: // classfields
        yyval_other.template destroy< ast::ChunkList* > ();
        break;

      case symbol_kind::S_exp: // exp
        yyval_other.template destroy< ast::Exp* > ();
        break;

      case symbol_kind::S_tyfield: // tyfield
        yyval_other.template destroy< ast::Field* > ();
        break;

      case symbol_kind::S_funchunk: // funchunk
        yyval_other.template destroy< ast::FunctionChunk* > ();
        break;

      case symbol_kind::S_fundec: // fundec
        yyval_other.template destroy< ast::FunctionDec* > ();
        break;

      case symbol_kind::S_classfield: // classfield
        yyval_other.template destroy< ast::MethodChunk* > ();
        break;

      case symbol_kind::S_typeid: // typeid
        yyval_other.template destroy< ast::NameTy* > ();
        break;

      case symbol_kind::S_ty: // ty
        yyval_other.template destroy< ast::Ty* > ();
        break;

      case symbol_kind::S_tychunk: // tychunk
        yyval_other.template destroy< ast::TypeChunk* > ();
        break;

      case symbol_kind::S_tydec: // tydec
        yyval_other.template destroy< ast::TypeDec* > ();
        break;

      case symbol_kind::S_lvalue: // lvalue
        yyval_other.template destroy< ast::Var* > ();
        break;

      case symbol_kind::S_funfields: // funfields
      case symbol_kind::S_69_funfields_1: // funfields.1
      case symbol_kind::S_varchunk: // varchunk
        yyval_other.template destroy< ast::VarChunk* > ();
        break;

      case symbol_kind::S_vardec: // vardec
      case symbol_kind::S_funfield: // funfield
        yyval_other.template destroy< ast::VarDec* > ();
        break;

      case symbol_kind::S_exps: // exps
      case symbol_kind::S_function_param: // function_param
        yyval_other.template destroy< ast::exps_type* > ();
        break;

      case symbol_kind::S_record_creation: // record_creation
      case symbol_kind::S_record_init: // record_init
        yyval_other.template destroy< ast::fieldinits_type* > ();
        break;

      case symbol_kind::S_tyfields: // tyfields
      case symbol_kind::S_81_tyfields_1: // tyfields.1
        yyval_other.template destroy< ast::fields_type* > ();
        break;

      case symbol_kind::S_INT: // "integer"
        yyval_other.template destroy< int > ();
        break;

      case symbol_kind::S_ID: // "identifier"
        yyval_other.template destroy< misc::symbol > ();
        break;

      case symbol_kind::S_STRING: // "string"
        yyval_other.template destroy< std::string > ();
        break;

      default:
        break;
    }

                  }
              }
        }
      else
        yyflag = yyresolveAction (*yybest, &val, yylocp);

      if (yyflag == yyok)
        {
          yys.yyresolved = true;
          YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
          new (&yys.value ()) value_type ();
          switch (yy_accessing_symbol (yys.yylrState))
    {
      case symbol_kind::S_78_classfields_1: // classfields.1
        yys.value ().copy< ast::ChunkInterface* > (val);
        break;

      case symbol_kind::S_chunks: // chunks
      case symbol_kind::S_classfields: // classfields
        yys.value ().copy< ast::ChunkList* > (val);
        break;

      case symbol_kind::S_exp: // exp
        yys.value ().copy< ast::Exp* > (val);
        break;

      case symbol_kind::S_tyfield: // tyfield
        yys.value ().copy< ast::Field* > (val);
        break;

      case symbol_kind::S_funchunk: // funchunk
        yys.value ().copy< ast::FunctionChunk* > (val);
        break;

      case symbol_kind::S_fundec: // fundec
        yys.value ().copy< ast::FunctionDec* > (val);
        break;

      case symbol_kind::S_classfield: // classfield
        yys.value ().copy< ast::MethodChunk* > (val);
        break;

      case symbol_kind::S_typeid: // typeid
        yys.value ().copy< ast::NameTy* > (val);
        break;

      case symbol_kind::S_ty: // ty
        yys.value ().copy< ast::Ty* > (val);
        break;

      case symbol_kind::S_tychunk: // tychunk
        yys.value ().copy< ast::TypeChunk* > (val);
        break;

      case symbol_kind::S_tydec: // tydec
        yys.value ().copy< ast::TypeDec* > (val);
        break;

      case symbol_kind::S_lvalue: // lvalue
        yys.value ().copy< ast::Var* > (val);
        break;

      case symbol_kind::S_funfields: // funfields
      case symbol_kind::S_69_funfields_1: // funfields.1
      case symbol_kind::S_varchunk: // varchunk
        yys.value ().copy< ast::VarChunk* > (val);
        break;

      case symbol_kind::S_vardec: // vardec
      case symbol_kind::S_funfield: // funfield
        yys.value ().copy< ast::VarDec* > (val);
        break;

      case symbol_kind::S_exps: // exps
      case symbol_kind::S_function_param: // function_param
        yys.value ().copy< ast::exps_type* > (val);
        break;

      case symbol_kind::S_record_creation: // record_creation
      case symbol_kind::S_record_init: // record_init
        yys.value ().copy< ast::fieldinits_type* > (val);
        break;

      case symbol_kind::S_tyfields: // tyfields
      case symbol_kind::S_81_tyfields_1: // tyfields.1
        yys.value ().copy< ast::fields_type* > (val);
        break;

      case symbol_kind::S_INT: // "integer"
        yys.value ().copy< int > (val);
        break;

      case symbol_kind::S_ID: // "identifier"
        yys.value ().copy< misc::symbol > (val);
        break;

      case symbol_kind::S_STRING: // "string"
        yys.value ().copy< std::string > (val);
        break;

      default:
        break;
    }


          YY_IGNORE_MAYBE_UNINITIALIZED_END
        }
      else
        yys.setFirstVal(YY_NULLPTR);

      // FIXME: User destructors.
      // Value type destructor.
      switch (yy_accessing_symbol (yys.yylrState))
    {
      case symbol_kind::S_78_classfields_1: // classfields.1
        val.template destroy< ast::ChunkInterface* > ();
        break;

      case symbol_kind::S_chunks: // chunks
      case symbol_kind::S_classfields: // classfields
        val.template destroy< ast::ChunkList* > ();
        break;

      case symbol_kind::S_exp: // exp
        val.template destroy< ast::Exp* > ();
        break;

      case symbol_kind::S_tyfield: // tyfield
        val.template destroy< ast::Field* > ();
        break;

      case symbol_kind::S_funchunk: // funchunk
        val.template destroy< ast::FunctionChunk* > ();
        break;

      case symbol_kind::S_fundec: // fundec
        val.template destroy< ast::FunctionDec* > ();
        break;

      case symbol_kind::S_classfield: // classfield
        val.template destroy< ast::MethodChunk* > ();
        break;

      case symbol_kind::S_typeid: // typeid
        val.template destroy< ast::NameTy* > ();
        break;

      case symbol_kind::S_ty: // ty
        val.template destroy< ast::Ty* > ();
        break;

      case symbol_kind::S_tychunk: // tychunk
        val.template destroy< ast::TypeChunk* > ();
        break;

      case symbol_kind::S_tydec: // tydec
        val.template destroy< ast::TypeDec* > ();
        break;

      case symbol_kind::S_lvalue: // lvalue
        val.template destroy< ast::Var* > ();
        break;

      case symbol_kind::S_funfields: // funfields
      case symbol_kind::S_69_funfields_1: // funfields.1
      case symbol_kind::S_varchunk: // varchunk
        val.template destroy< ast::VarChunk* > ();
        break;

      case symbol_kind::S_vardec: // vardec
      case symbol_kind::S_funfield: // funfield
        val.template destroy< ast::VarDec* > ();
        break;

      case symbol_kind::S_exps: // exps
      case symbol_kind::S_function_param: // function_param
        val.template destroy< ast::exps_type* > ();
        break;

      case symbol_kind::S_record_creation: // record_creation
      case symbol_kind::S_record_init: // record_init
        val.template destroy< ast::fieldinits_type* > ();
        break;

      case symbol_kind::S_tyfields: // tyfields
      case symbol_kind::S_81_tyfields_1: // tyfields.1
        val.template destroy< ast::fields_type* > ();
        break;

      case symbol_kind::S_INT: // "integer"
        val.template destroy< int > ();
        break;

      case symbol_kind::S_ID: // "identifier"
        val.template destroy< misc::symbol > ();
        break;

      case symbol_kind::S_STRING: // "string"
        val.template destroy< std::string > ();
        break;

      default:
        break;
    }

      return yyflag;
    }

    /** Resolve the states for the RHS of YYOPT on *YYSTACKP, perform its
     *  user action, and return the semantic value and location in *YYVALP
     *  and *YYLOCP.  Regardless of whether result = yyok, all RHS states
     *  have been destroyed (assuming the user action destroys all RHS
     *  semantic values if invoked).  */
    YYRESULTTAG
    yyresolveAction (semantic_option& yyopt, value_type* yyvalp, location_type* yylocp)
    {
      glr_state* yyoptState = yyopt.state();
      YYASSERT(yyoptState != YY_NULLPTR);
      int yynrhs = yyrhsLength (yyopt.yyrule);
      YYRESULTTAG yyflag = yyresolveStates (*yyoptState, yynrhs);
      if (yyflag != yyok)
        {
          for (glr_state *yys = yyoptState; yynrhs > 0; yys = yys->pred(), yynrhs -= 1)
            yys->destroy ("Cleanup: popping", yyparser);
          return yyflag;
        }

      glr_stack_item yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yyrhsVals[YYMAXRHS + YYMAXLEFT].getState().setPred(yyopt.state());
      if (yynrhs == 0)
        /* Set default location.  */
        yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].getState().yyloc = yyoptState->yyloc;
      {
        symbol_type yyla_current = std::move (this->yyla);
        this->yyla = std::move (yyopt.yyla);
        yyflag = yyuserAction (yyopt.yyrule, yynrhs,
                               yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                               create_state_set_index (-1),
                               yyvalp, yylocp);
        this->yyla = std::move (yyla_current);
      }
      return yyflag;
    }

    /** Resolve the locations for each of the YYN1 states in *YYSTACKP,
     *  ending at YYS1.  Has no effect on previously resolved states.
     *  The first semantic option of a state is always chosen.  */
    void
    yyresolveLocations (glr_state &yys1, int yyn1)
    {
      if (0 < yyn1)
        {
          yyresolveLocations (*yys1.pred(), yyn1 - 1);
          if (!yys1.yyresolved)
            {
              glr_stack_item yyrhsloc[1 + YYMAXRHS];
              YYASSERT (yys1.firstVal() != YY_NULLPTR);
              semantic_option& yyoption = *yys1.firstVal();
              const int yynrhs = yyrhsLength (yyoption.yyrule);
              if (0 < yynrhs)
                {
                  yyresolveLocations (*yyoption.state(), yynrhs);
                  const glr_state *yys = yyoption.state();
                  for (int yyn = yynrhs; yyn > 0; yyn -= 1)
                  {
                    yyrhsloc[yyn].getState().yyloc = yys->yyloc;
                    yys = yys->pred();
                  }
                }
              else
                {
                  /* Both yyresolveAction and yyresolveLocations traverse the GSS
                     in reverse rightmost order.  It is only necessary to invoke
                     yyresolveLocations on a subforest for which yyresolveAction
                     would have been invoked next had an ambiguity not been
                     detected.  Thus the location of the previous state (but not
                     necessarily the previous state itself) is guaranteed to be
                     resolved already.  */
                  YY_IGNORE_NULL_DEREFERENCE_BEGIN
                  yyrhsloc[0].getState().yyloc = yyoption.state()->yyloc;
                  YY_IGNORE_NULL_DEREFERENCE_END
                }
              YYLLOC_DEFAULT ((yys1.yyloc), yyrhsloc, yynrhs);
            }
        }
    }

    /** If yytoken is empty, fetch the next token.  */
    void
    yyget_token ()
    {
  YY_USE (tp);
      if (this->yyla.empty ())
        {
          YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
          try
#endif // YY_EXCEPTIONS
            {
              symbol_type yylookahead (yylex (tp));
              yyla.move (yylookahead);
            }
#if YY_EXCEPTIONS
          catch (const parser_type::syntax_error& yyexc)
            {
              YYCDEBUG << "Caught exception: " << yyexc.what () << '\n';
              this->yyla.location = yyexc.location;
              yyparser.error (this->yyla.location, yyexc.what ());
              // Map errors caught in the scanner to the error token, so that error
              // handling is started.
              this->yyla.kind_ = symbol_kind::S_YYerror;
            }
        }
#endif // YY_EXCEPTIONS
      if (this->yyla.kind () == symbol_kind::S_YYEOF)
        YYCDEBUG << "Now at end of input.\n";
      else
        YY_SYMBOL_PRINT ("Next token is", this->yyla.kind (), this->yyla.value, this->yyla.location);
    }


                                /* Bison grammar-table manipulation.  */

    /** The action to take in YYSTATE on seeing YYTOKEN.
     *  Result R means
     *    R < 0:  Reduce on rule -R.
     *    R = 0:  Error.
     *    R > 0:  Shift to state R.
     *  Set *YYCONFLICTS to a pointer into yyconfl to a 0-terminated list
     *  of conflicting reductions.
     */
    static int
    yygetLRActions (state_num yystate, symbol_kind_type yytoken, const short*& yyconflicts)
    {
      int yyindex = yypact[yystate] + yytoken;
      if (yytoken == symbol_kind::S_YYerror)
        {
          // This is the error token.
          yyconflicts = yyconfl;
          return 0;
        }
      else if (yy_is_defaulted_state (yystate)
               || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
        {
          yyconflicts = yyconfl;
          return -yydefact[yystate];
        }
      else if (! yytable_value_is_error (yytable[yyindex]))
        {
          yyconflicts = yyconfl + yyconflp[yyindex];
          return yytable[yyindex];
        }
      else
        {
          yyconflicts = yyconfl + yyconflp[yyindex];
          return 0;
        }
    }

    /** Compute post-reduction state.
     * \param yystate   the current state
     * \param yysym     the nonterminal to push on the stack
     */
    static state_num
    yyLRgotoState (state_num yystate, symbol_kind_type yysym)
    {
      const int yyr = yypgoto[yysym - YYNTOKENS] + yystate;
      if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
        return yytable[yyr];
      else
        return yydefgoto[yysym - YYNTOKENS];
    }

    static bool
    yypact_value_is_default (state_num yystate)
    {
      return ((yystate) == YYPACT_NINF);
    }

    static bool
    yytable_value_is_error (int yytable_value YY_ATTRIBUTE_UNUSED)
    {
      return ((yytable_value) == YYTABLE_NINF);
    }

    static bool
    yy_is_shift_action (int yyaction) YY_NOEXCEPT
    {
      return 0 < yyaction;
    }

    static bool
    yy_is_error_action (int yyaction) YY_NOEXCEPT
    {
      return yyaction == 0;
    }

    /** Whether LR state YYSTATE has only a default reduction
     *  (regardless of token).  */
    static bool
    yy_is_defaulted_state (state_num yystate)
    {
      return yypact_value_is_default (yypact[yystate]);
    }

    /** The default reduction for YYSTATE, assuming it has one.  */
    static rule_num
    yy_default_action (state_num yystate)
    {
      return yydefact[yystate];
    }

                                    /* GLRStacks */

    /** Y0 and Y1 represent two possible actions to take in a given
     *  parsing state; return 0 if no combination is possible,
     *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
    static int
    yypreference (const semantic_option& y0, const semantic_option& y1)
    {
      const rule_num r0 = y0.yyrule, r1 = y1.yyrule;
      const int p0 = yydprec[r0], p1 = yydprec[r1];

      if (p0 == p1)
        {
          if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
            return 0;
          else
            return 1;
        }
      else if (p0 == 0 || p1 == 0)
        return 0;
      else if (p0 < p1)
        return 3;
      else if (p1 < p0)
        return 2;
      else
        return 0;
    }


    // User arguments.
    ::parse::TigerParser& tp;
  }; // class parser::glr_stack
} // namespace parse


#if PARSEDEBUG
namespace
{
  void
  yypstack (const glr_stack& yystack, size_t yyk)
  {
    yystack.yypstack (create_state_set_index (static_cast<std::ptrdiff_t> (yyk)));
  }

  void
  yypdumpstack (const glr_stack& yystack)
  {
    yystack.yypdumpstack ();
  }
}
#endif

namespace parse {
#line 5170 "parse/parsetiger.cc"

  /// Build a parser object.
  parser::parser (::parse::TigerParser& tp_yyarg)
    :
#if PARSEDEBUG
      yycdebug_ (&std::cerr),
#endif
      tp (tp_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    glr_stack yystack(YYINITDEPTH, *this, tp);
    return yystack.parse ();
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }


#if PARSEDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\"string\"",
  "\"identifier\"", "\"integer\"", "\"&\"", "\"array\"", "\":=\"",
  "\"break\"", "\"_cast\"", "\"class\"", "\":\"", "\",\"", "\"/\"",
  "\"do\"", "\".\"", "\"else\"", "\"end\"", "\"=\"", "\"extends\"",
  "\"for\"", "\"function\"", "\">=\"", "\">\"", "\"if\"", "\"import\"",
  "\"in\"", "\"{\"", "\"[\"", "\"<=\"", "\"let\"", "\"(\"", "\"<\"",
  "\"-\"", "\"method\"", "\"<>\"", "\"new\"", "\"nil\"", "\"of\"", "\"|\"",
  "\"+\"", "\"primitive\"", "\"}\"", "\"]\"", "\")\"", "\";\"", "\"then\"",
  "\"*\"", "\"to\"", "\"type\"", "\"var\"", "\"while\"", "UMINUS",
  "\"_exp\"", "\"_lvalue\"", "\"_chunks\"", "\"_namety\"", "$accept",
  "program", "exps", "record_creation", "record_init", "function_param",
  "exp", "lvalue", "vardec", "fundec", "funfields", "funfields.1",
  "funfield", "funchunk", "varchunk", "chunks", "tychunk", "tydec", "ty",
  "classfields", "classfields.1", "classfield", "tyfields", "tyfields.1",
  "tyfield", "typeid", YY_NULLPTR
  };
#endif



  // parser::context.
  parser::context::context (glr_stack& yystack, const symbol_type& yyla)
    : yystack_ (yystack)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;
    const int yyn = yypact[yystack_.firstTopState()->yylrState];
    if (!yystack_.yypact_value_is_default (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for this
           state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        /* Stay within bounds of both yycheck and yytname.  */
        const int yychecklim = YYLAST - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yystack_.yytable_value_is_error (yytable[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }
    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }




  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }

  void
  parser::yy_destroy_ (const char* yymsg, symbol_kind_type yykind,
                           value_type& yyval,
                           location_type& yyloc)
  {
    YY_USE (yyval);
    YY_USE (yyloc);
    if (!yymsg)
      yymsg = "Deleting";
    parser& yyparser = *this;
    YY_USE (yyparser);
    YY_SYMBOL_PRINT (yymsg, yykind, yyval, yyloc);

    YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
    YY_USE (yykind);
    YY_IGNORE_MAYBE_UNINITIALIZED_END
  }

#if PARSEDEBUG
  /*--------------------.
  | Print this symbol.  |
  `--------------------*/

  void
  parser::yy_symbol_value_print_ (symbol_kind_type yykind,
                           const value_type& yyval,
                           const location_type& yyloc) const
  {
    YY_USE (yyloc);
    YY_USE (yyval);
    std::ostream& yyo = debug_stream ();
    YY_USE (yyo);
    switch (yykind)
    {
      case symbol_kind::S_STRING: // "string"
#line 75 "parse/parsetiger.yy"
                 { yyo << yyval.as < std::string > (); }
#line 5423 "parse/parsetiger.cc"
        break;

      case symbol_kind::S_ID: // "identifier"
#line 75 "parse/parsetiger.yy"
                 { yyo << yyval.as < misc::symbol > (); }
#line 5429 "parse/parsetiger.cc"
        break;

      case symbol_kind::S_INT: // "integer"
#line 75 "parse/parsetiger.yy"
                 { yyo << yyval.as < int > (); }
#line 5435 "parse/parsetiger.cc"
        break;

      default:
        break;
    }
  }

  void
  parser::yy_symbol_print_ (symbol_kind_type yykind,
                           const value_type& yyval,
                           const location_type& yyloc) const
  {
    *yycdebug_ << (yykind < YYNTOKENS ? "token" : "nterm")
               << ' ' << symbol_name (yykind) << " ("
               << yyloc << ": ";
    yy_symbol_value_print_ (yykind, yyval, yyloc);
    *yycdebug_ << ')';
  }

  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    // Actually, it is yydebug which is really used.
    yydebug = l;
  }
#endif // PARSEDEBUG




} // parse
#line 5486 "parse/parsetiger.cc"
#line 465 "parse/parsetiger.yy"


void
parse::parser::error(const location_type& l, const std::string& m)
{
  // DONE: Some code was deleted here.

      tp.error_ << misc::error::error_type::parse
                << l
                << ": "
                << m
                << '\n';

}
