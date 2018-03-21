/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "c.y" /* yacc.c:339  */

#include <cstdio>
#include <iostream>
using namespace std;

// stuff from flex that bison needs to know about:
extern "C" int yylex();
int yyparse();
extern "C" FILE *yyin;
 
void yyerror(const char *s);

// Declare the constructed AST root.
#include "parser.h"
ast_program* program;

#line 83 "c.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "c.tab.hpp".  */
#ifndef YY_YY_C_TAB_HPP_INCLUDED
# define YY_YY_C_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    I_CONSTANT = 259,
    F_CONSTANT = 260,
    STRING_LITERAL = 261,
    FUNC_NAME = 262,
    SIZEOF = 263,
    PTR_OP = 264,
    INC_OP = 265,
    DEC_OP = 266,
    LEFT_OP = 267,
    RIGHT_OP = 268,
    LE_OP = 269,
    GE_OP = 270,
    EQ_OP = 271,
    NE_OP = 272,
    AND_OP = 273,
    OR_OP = 274,
    MUL_ASSIGN = 275,
    DIV_ASSIGN = 276,
    MOD_ASSIGN = 277,
    ADD_ASSIGN = 278,
    SUB_ASSIGN = 279,
    LEFT_ASSIGN = 280,
    RIGHT_ASSIGN = 281,
    AND_ASSIGN = 282,
    XOR_ASSIGN = 283,
    OR_ASSIGN = 284,
    TYPEDEF_NAME = 285,
    ENUMERATION_CONSTANT = 286,
    TYPEDEF = 287,
    EXTERN = 288,
    STATIC = 289,
    AUTO = 290,
    REGISTER = 291,
    INLINE = 292,
    CONST = 293,
    RESTRICT = 294,
    VOLATILE = 295,
    BOOL = 296,
    CHAR = 297,
    SHORT = 298,
    INT = 299,
    LONG = 300,
    SIGNED = 301,
    UNSIGNED = 302,
    FLOAT = 303,
    DOUBLE = 304,
    VOID = 305,
    COMPLEX = 306,
    IMAGINARY = 307,
    STRUCT = 308,
    UNION = 309,
    ENUM = 310,
    ELLIPSIS = 311,
    CASE = 312,
    DEFAULT = 313,
    IF = 314,
    ELSE = 315,
    SWITCH = 316,
    WHILE = 317,
    DO = 318,
    FOR = 319,
    GOTO = 320,
    CONTINUE = 321,
    BREAK = 322,
    RETURN = 323,
    ALIGNAS = 324,
    ALIGNOF = 325,
    ATOMIC = 326,
    GENERIC = 327,
    NORETURN = 328,
    STATIC_ASSERT = 329,
    THREAD_LOCAL = 330
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_C_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 210 "c.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   248

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  122

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   330

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    81,     2,     2,     2,     2,     2,     2,
      76,    77,    82,    83,    78,    80,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    86,
      84,    85,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    87,     2,    88,    79,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    77,    77,    82,    84,    86,    91,    93,    98,   100,
     102,   107,   109,   114,   116,   121,   123,   125,   130,   132,
     137,   139,   141,   146,   148,   150,   155,   157,   162,   164,
     169,   174,   179,   184,   187,   193,   198,   200,   202,   204,
     209,   214,   216,   218,   225,   227,   232,   235,   241,   246,
     248,   250,   252,   254,   259,   261,   266,   269,   275,   277,
     282,   284,   289,   291,   296,   298,   300,   302,   307,   309,
     314,   317,   323,   325,   330
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "I_CONSTANT", "F_CONSTANT",
  "STRING_LITERAL", "FUNC_NAME", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP",
  "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP",
  "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN",
  "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN",
  "OR_ASSIGN", "TYPEDEF_NAME", "ENUMERATION_CONSTANT", "TYPEDEF", "EXTERN",
  "STATIC", "AUTO", "REGISTER", "INLINE", "CONST", "RESTRICT", "VOLATILE",
  "BOOL", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT",
  "DOUBLE", "VOID", "COMPLEX", "IMAGINARY", "STRUCT", "UNION", "ENUM",
  "ELLIPSIS", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO",
  "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "ALIGNAS", "ALIGNOF",
  "ATOMIC", "GENERIC", "NORETURN", "STATIC_ASSERT", "THREAD_LOCAL", "'('",
  "')'", "','", "'~'", "'-'", "'!'", "'*'", "'+'", "'<'", "'='", "';'",
  "'{'", "'}'", "$accept", "program", "primary_expression", "constant",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "unary_operator", "multiplicative_expression", "additive_expression",
  "relational_expression", "equality_expression", "assignment_expression",
  "expression", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "type_specifier",
  "declarator", "direct_declarator", "parameter_type_list",
  "parameter_list", "parameter_declaration", "statement",
  "compound_statement", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,    40,    41,    44,   126,
      45,    33,    42,    43,    60,    61,    59,   123,   125
};
# endif

#define YYPACT_NINF -73

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-73)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      87,   -73,   -73,   -73,   -73,    13,   -73,     0,   -73,    87,
     -73,   -73,   -73,   -48,   -64,   -73,   -72,   -73,   -73,    -6,
       0,   -73,    -3,   -73,   -73,    26,   -42,   -29,   -73,   -73,
     -73,   -65,   -73,   -73,   -22,   -21,    64,   155,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,     3,   -25,   -37,
      -4,    42,   -73,   -27,   -73,     0,   -73,   -73,    22,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,   107,   117,   155,   155,
      88,   -73,   -24,   -14,   -73,   -73,   167,   167,   167,   167,
     167,   167,   -73,   -73,   -73,   -73,   -73,   -73,   -59,   -73,
     -73,     5,   109,   109,   -73,   -73,    12,   -73,   -25,   -25,
     -37,   -37,    -4,   -73,   155,    47,   143,   149,   -73,    29,
      47,    17,    47,    18,    47,   -73,    47,   -73,    47,   -73,
     -73,   -73
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    37,    38,    39,    36,     0,    73,     0,    32,     2,
      70,    72,     1,    41,     0,    33,    35,    40,    71,     0,
       0,    31,     0,    74,    43,     0,     0,    44,    46,    34,
      35,     3,     6,     7,     0,     0,     0,     0,    15,    16,
      17,    60,    54,     8,     4,    13,    18,     0,    20,    23,
      26,    28,    30,     0,    58,     0,    59,    49,     0,    56,
      50,    51,    52,    53,    48,    42,     0,     0,     0,     0,
       0,    68,     0,     0,     3,    14,     0,     0,     0,     0,
       0,     0,    61,    55,    57,    45,    47,     9,     0,    11,
      29,     0,     0,     0,    69,     5,     3,    19,    22,    21,
      25,    24,    27,    10,     0,     0,     0,     0,    12,    63,
       0,     0,     0,     0,     0,    66,     0,    64,     0,    62,
      67,    65
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -73,   -73,    49,   -73,   -73,   -73,    23,   -73,   -54,   -46,
      16,   -73,   -51,   -32,   -10,    21,   -73,    80,   -73,    97,
     -73,   -73,   -73,    39,    68,    91,   -73,    58,   -61,   -73,
     -73,   -73,   -73,   108,   -73
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,    43,    44,    45,    88,    46,    47,    48,    49,
      50,    51,    52,    53,     6,    55,    14,    15,     8,    30,
      17,    26,    27,    28,    56,    57,    58,    59,    60,    61,
      62,    63,     9,    10,    11
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      31,    32,    33,    13,    72,    73,    74,    32,    33,    93,
      79,    67,    54,    12,    20,    22,    89,    90,   103,   104,
      68,     7,    21,    98,    99,    31,    32,    33,    19,    64,
       7,   106,   107,   100,   101,    65,     1,    91,     2,     1,
      25,     2,     3,    77,     4,     3,    78,     4,    54,    66,
      31,    32,    33,   108,    69,    70,    34,    76,    81,    82,
      92,    35,    94,    95,     1,    36,     2,    31,    32,    33,
       3,    24,     4,    37,   111,   113,    38,    39,    40,    37,
      80,    34,   105,    41,    22,    42,    35,    25,    67,   114,
      36,    31,    32,    33,   116,   118,    75,   102,    37,    97,
      29,    38,    39,    40,    16,    86,    34,    23,    41,    22,
      83,    35,    31,    32,    33,    36,    84,    18,     0,     0,
      31,    32,    33,    37,     0,     0,    38,    39,    40,     1,
       1,     2,     2,    41,    22,     3,     3,     4,     4,     0,
      37,     0,     0,    38,    39,    40,    31,    32,    33,     1,
      71,     2,    31,    32,    33,     3,     0,     4,    31,    32,
      33,     0,     0,    85,    37,     0,     0,    38,    39,    40,
      96,    32,    33,   109,    41,     0,     0,     0,   115,     0,
     117,     0,   119,     0,   120,    37,   121,     0,    38,    39,
      40,     0,     0,    37,    87,    41,    38,    39,    40,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
     110,     0,    38,    39,    40,    37,   112,     0,    38,    39,
      40,    37,     0,     0,    38,    39,    40,     0,     0,     0,
       0,     0,     0,    37,     0,     0,    38,    39,    40
};

static const yytype_int8 yycheck[] =
{
       3,     4,     5,     3,    36,    37,     3,     4,     5,    70,
      14,    76,    22,     0,    78,    87,    67,    68,    77,    78,
      85,     0,    86,    77,    78,     3,     4,     5,    76,     3,
       9,    92,    93,    79,    80,    77,    42,    69,    44,    42,
      19,    44,    48,    80,    50,    48,    83,    50,    58,    78,
       3,     4,     5,   104,    76,    76,    59,    82,    16,    86,
      70,    64,    86,    77,    42,    68,    44,     3,     4,     5,
      48,    77,    50,    76,   106,   107,    79,    80,    81,    76,
      84,    59,    77,    86,    87,    88,    64,    66,    76,    60,
      68,     3,     4,     5,    77,    77,    47,    81,    76,    76,
      20,    79,    80,    81,     7,    66,    59,    16,    86,    87,
      88,    64,     3,     4,     5,    68,    58,     9,    -1,    -1,
       3,     4,     5,    76,    -1,    -1,    79,    80,    81,    42,
      42,    44,    44,    86,    87,    48,    48,    50,    50,    -1,
      76,    -1,    -1,    79,    80,    81,     3,     4,     5,    42,
      86,    44,     3,     4,     5,    48,    -1,    50,     3,     4,
       5,    -1,    -1,    56,    76,    -1,    -1,    79,    80,    81,
       3,     4,     5,   105,    86,    -1,    -1,    -1,   110,    -1,
     112,    -1,   114,    -1,   116,    76,   118,    -1,    79,    80,
      81,    -1,    -1,    76,    77,    86,    79,    80,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      77,    -1,    79,    80,    81,    76,    77,    -1,    79,    80,
      81,    76,    -1,    -1,    79,    80,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    79,    80,    81
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,    44,    48,    50,    90,   103,   104,   107,   121,
     122,   123,     0,     3,   105,   106,   108,   109,   122,    76,
      78,    86,    87,   114,    77,   104,   110,   111,   112,   106,
     108,     3,     4,     5,    59,    64,    68,    76,    79,    80,
      81,    86,    88,    91,    92,    93,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   113,   114,   115,   116,
     117,   118,   119,   120,     3,    77,    78,    76,    85,    76,
      76,    86,   102,   102,     3,    91,    82,    80,    83,    14,
      84,    16,    86,    88,   116,    56,   112,    77,    94,   101,
     101,   102,   103,   117,    86,    77,     3,    95,    97,    97,
      98,    98,    99,    77,    78,    77,   117,   117,   101,   113,
      77,   102,    77,   102,    60,   113,    77,   113,    77,   113,
     113,   113
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    89,    90,    91,    91,    91,    92,    92,    93,    93,
      93,    94,    94,    95,    95,    96,    96,    96,    97,    97,
      98,    98,    98,    99,    99,    99,   100,   100,   101,   101,
     102,   103,   104,   105,   105,   106,   107,   107,   107,   107,
     108,   109,   109,   109,   110,   110,   111,   111,   112,   113,
     113,   113,   113,   113,   114,   114,   115,   115,   116,   116,
     117,   117,   118,   118,   119,   119,   119,   119,   120,   120,
     121,   121,   122,   122,   123
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     3,
       4,     1,     3,     1,     2,     1,     1,     1,     1,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     4,     3,     1,     3,     1,     3,     2,     1,
       1,     1,     1,     1,     2,     3,     1,     2,     1,     1,
       1,     2,     7,     5,     6,     7,     6,     7,     2,     3,
       1,     2,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 78 "c.y" /* yacc.c:1646  */
    { program = new ast_program((yyvsp[0].external_declarations)); }
#line 1425 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 83 "c.y" /* yacc.c:1646  */
    { (yyval.expression) = new ast_identifier_expression((yyvsp[0].symbol)); }
#line 1431 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 85 "c.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1437 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 87 "c.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[-1].expression); }
#line 1443 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 92 "c.y" /* yacc.c:1646  */
    { (yyval.expression) = new ast_i_constant((yyvsp[0].symbol)); }
#line 1449 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 94 "c.y" /* yacc.c:1646  */
    { (yyval.expression) = new ast_f_constant((yyvsp[0].symbol)); }
#line 1455 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 99 "c.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1461 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 101 "c.y" /* yacc.c:1646  */
    { (yyval.expression) = new ast_postfix_expression((yyvsp[-2].symbol),new ast_argument_list()); }
#line 1467 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 103 "c.y" /* yacc.c:1646  */
    { (yyval.expression) = new ast_postfix_expression((yyvsp[-3].symbol), (yyvsp[-1].arguments)); }
#line 1473 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 108 "c.y" /* yacc.c:1646  */
    { (yyval.arguments) = new ast_argument_list(); (yyval.arguments)->push_back((yyvsp[0].expression));  }
#line 1479 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 110 "c.y" /* yacc.c:1646  */
    { (yyval.arguments) = (yyvsp[-2].arguments); (yyval.arguments)->push_back((yyvsp[0].expression)); }
#line 1485 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 115 "c.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1491 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 117 "c.y" /* yacc.c:1646  */
    { (yyval.expression) = new ast_unary_expression((yyvsp[-1].unary), (yyvsp[0].expression)); }
#line 1497 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 122 "c.y" /* yacc.c:1646  */
    { (yyval.unary) = '~'; }
#line 1503 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 124 "c.y" /* yacc.c:1646  */
    { (yyval.unary) = '-'; }
#line 1509 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 126 "c.y" /* yacc.c:1646  */
    { (yyval.unary) = '!'; }
#line 1515 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 131 "c.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1521 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 133 "c.y" /* yacc.c:1646  */
    { (yyval.expression) = new ast_mul_expression((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1527 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 138 "c.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1533 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 140 "c.y" /* yacc.c:1646  */
    { (yyval.expression) = new ast_add_expression((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1539 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 142 "c.y" /* yacc.c:1646  */
    { (yyval.expression) = new ast_sub_expression((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1545 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 147 "c.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1551 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 149 "c.y" /* yacc.c:1646  */
    { (yyval.expression) = new ast_less_expression((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1557 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 151 "c.y" /* yacc.c:1646  */
    { (yyval.expression) = new ast_leq_expression((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1563 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 156 "c.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1569 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 158 "c.y" /* yacc.c:1646  */
    { (yyval.expression) = new ast_eq_expression((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1575 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 163 "c.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1581 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 165 "c.y" /* yacc.c:1646  */
    { (yyval.expression) = new ast_assign_expression((yyvsp[-2].symbol), (yyvsp[0].expression)); }
#line 1587 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 170 "c.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1593 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 175 "c.y" /* yacc.c:1646  */
    { (yyval.declaration) = new ast_declaration((yyvsp[-2].type_specifier), (yyvsp[-1].init_declarators)); }
#line 1599 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 180 "c.y" /* yacc.c:1646  */
    { (yyval.type_specifier) = (yyvsp[0].type_specifier); }
#line 1605 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 185 "c.y" /* yacc.c:1646  */
    { (yyval.init_declarators) = new ast_init_declarator_list();
		(yyval.init_declarators)->push_back((yyvsp[0].init_declarator)); }
#line 1612 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 188 "c.y" /* yacc.c:1646  */
    { (yyvsp[-2].init_declarators)->push_back((yyvsp[0].init_declarator));
		(yyval.init_declarators) = (yyvsp[-2].init_declarators); }
#line 1619 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 194 "c.y" /* yacc.c:1646  */
    { (yyval.init_declarator) = new ast_init_declarator((yyvsp[0].declarator)); }
#line 1625 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 199 "c.y" /* yacc.c:1646  */
    { (yyval.type_specifier) = new ast_type_specifier(id_table.add_string("void")); }
#line 1631 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 201 "c.y" /* yacc.c:1646  */
    { (yyval.type_specifier) = new ast_type_specifier(id_table.add_string("char")); }
#line 1637 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 203 "c.y" /* yacc.c:1646  */
    { (yyval.type_specifier) = new ast_type_specifier(id_table.add_string("int")); }
#line 1643 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 205 "c.y" /* yacc.c:1646  */
    { (yyval.type_specifier) = new ast_type_specifier(id_table.add_string("float")); }
#line 1649 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 210 "c.y" /* yacc.c:1646  */
    { (yyval.declarator) = new ast_declarator((yyvsp[0].direct_declarator)); }
#line 1655 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 215 "c.y" /* yacc.c:1646  */
    { (yyval.direct_declarator) = new ast_direct_declarator(new ast_identifier_declarator((yyvsp[0].symbol))); }
#line 1661 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 217 "c.y" /* yacc.c:1646  */
    { (yyval.direct_declarator) = new ast_direct_declarator(new ast_function_declarator((yyvsp[-3].symbol), (yyvsp[-1].parameter_types))); }
#line 1667 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 219 "c.y" /* yacc.c:1646  */
    { (yyval.direct_declarator) = new ast_direct_declarator(new ast_function_declarator(
		(yyvsp[-2].symbol), new ast_parameter_type_list(
			new ast_parameter_declaration_list(), false))); }
#line 1675 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 226 "c.y" /* yacc.c:1646  */
    { (yyval.parameter_types) = new ast_parameter_type_list((yyvsp[0].parameter_declarations), false); }
#line 1681 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 228 "c.y" /* yacc.c:1646  */
    { (yyval.parameter_types) = new ast_parameter_type_list((yyvsp[-2].parameter_declarations), true); }
#line 1687 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 233 "c.y" /* yacc.c:1646  */
    { (yyval.parameter_declarations) = new ast_parameter_declaration_list(); 
		(yyval.parameter_declarations)->push_back((yyvsp[0].parameter_declaration)); }
#line 1694 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 236 "c.y" /* yacc.c:1646  */
    { (yyvsp[-2].parameter_declarations)->push_back((yyvsp[0].parameter_declaration));
		(yyval.parameter_declarations) = (yyvsp[-2].parameter_declarations); }
#line 1701 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 242 "c.y" /* yacc.c:1646  */
    { (yyval.parameter_declaration) = new ast_parameter_declaration((yyvsp[-1].type_specifier), (yyvsp[0].symbol)); }
#line 1707 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 247 "c.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].compound_statement); }
#line 1713 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 249 "c.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].expression_statement); }
#line 1719 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 251 "c.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1725 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 253 "c.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1731 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 255 "c.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1737 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 260 "c.y" /* yacc.c:1646  */
    { (yyval.compound_statement) = new ast_compound_statement(new ast_block_item_list()); }
#line 1743 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 262 "c.y" /* yacc.c:1646  */
    { (yyval.compound_statement) = new ast_compound_statement((yyvsp[-1].block_items)); }
#line 1749 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 267 "c.y" /* yacc.c:1646  */
    { (yyval.block_items) = new ast_block_item_list();
		(yyval.block_items)->push_back((yyvsp[0].block_item)); }
#line 1756 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 270 "c.y" /* yacc.c:1646  */
    { (yyvsp[-1].block_items)->push_back((yyvsp[0].block_item));
		(yyval.block_items) = (yyvsp[-1].block_items); }
#line 1763 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 276 "c.y" /* yacc.c:1646  */
    { (yyval.block_item) = new ast_block_item((yyvsp[0].declaration)); }
#line 1769 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 278 "c.y" /* yacc.c:1646  */
    { (yyval.block_item) = new ast_block_item((yyvsp[0].statement)); }
#line 1775 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 283 "c.y" /* yacc.c:1646  */
    { (yyval.expression_statement) = new ast_expression_statement(new ast_no_expression()); }
#line 1781 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 285 "c.y" /* yacc.c:1646  */
    { (yyval.expression_statement) = new ast_expression_statement((yyvsp[-1].expression)); }
#line 1787 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 290 "c.y" /* yacc.c:1646  */
    { (yyval.statement) = new ast_mif_statement((yyvsp[-4].expression),(yyvsp[-2].statement),(yyvsp[0].statement)); }
#line 1793 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 292 "c.y" /* yacc.c:1646  */
    { (yyval.statement) = new ast_uif_statement((yyvsp[-2].expression), (yyvsp[0].statement)); }
#line 1799 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 297 "c.y" /* yacc.c:1646  */
    { (yyval.statement) = new ast_for_statement((yyvsp[-3].expression_statement), (yyvsp[-2].expression_statement), (yyvsp[0].statement)); }
#line 1805 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 299 "c.y" /* yacc.c:1646  */
    { (yyval.statement) = new ast_for_statement((yyvsp[-4].expression_statement), (yyvsp[-3].expression_statement), (yyvsp[-2].expression), (yyvsp[0].statement)); }
#line 1811 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 301 "c.y" /* yacc.c:1646  */
    { (yyval.statement) = new ast_for_statement((yyvsp[-3].declaration), (yyvsp[-2].expression_statement), (yyvsp[0].statement)); }
#line 1817 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 303 "c.y" /* yacc.c:1646  */
    { (yyval.statement) = new ast_for_statement((yyvsp[-4].declaration), (yyvsp[-3].expression_statement), (yyvsp[-2].expression), (yyvsp[0].statement)); }
#line 1823 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 308 "c.y" /* yacc.c:1646  */
    { (yyval.statement) = new ast_jump_statement(); }
#line 1829 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 310 "c.y" /* yacc.c:1646  */
    { (yyval.statement) = new ast_jump_statement((yyvsp[-1].expression)); }
#line 1835 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 315 "c.y" /* yacc.c:1646  */
    { (yyval.external_declarations) = new ast_external_declaration_list();
		(yyval.external_declarations)->push_back((yyvsp[0].external_declaration)); }
#line 1842 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 318 "c.y" /* yacc.c:1646  */
    { (yyvsp[-1].external_declarations)->push_back((yyvsp[0].external_declaration));
		(yyval.external_declarations) = (yyvsp[-1].external_declarations); }
#line 1849 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 324 "c.y" /* yacc.c:1646  */
    { (yyval.external_declaration) = new ast_external_declaration((yyvsp[0].function_definition)); }
#line 1855 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 326 "c.y" /* yacc.c:1646  */
    { (yyval.external_declaration) = new ast_external_declaration((yyvsp[0].declaration)); }
#line 1861 "c.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 331 "c.y" /* yacc.c:1646  */
    { (yyval.function_definition) = new ast_function_definition((yyvsp[-2].type_specifier), (yyvsp[-1].declarator), (yyvsp[0].compound_statement)); }
#line 1867 "c.tab.cpp" /* yacc.c:1646  */
    break;


#line 1871 "c.tab.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
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
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 334 "c.y" /* yacc.c:1906  */

#include <stdio.h>

void yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "*** %s\n", s);
}
