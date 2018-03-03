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
#include "tree.h"
ast_program* root;
#define YYSTYPE List<ast_external_declaration>*

#line 84 "c.tab.cpp" /* yacc.c:339  */

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
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_C_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 211 "c.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  52
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2394

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  100
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  79
/* YYNRULES -- Number of rules.  */
#define YYNRULES  276
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  481

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
       2,     2,     2,    90,     2,     2,     2,    92,    85,     2,
      76,    77,    86,    87,    78,    88,    82,    91,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    79,    99,
      93,    98,    94,    97,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    80,     2,    81,    95,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    83,    96,    84,    89,     2,     2,     2,
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
       0,    39,    39,    43,    44,    45,    46,    47,    51,    52,
      53,    57,    61,    62,    66,    70,    71,    75,    76,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    93,
      94,    98,    99,   100,   101,   102,   103,   104,   108,   109,
     110,   111,   112,   113,   117,   118,   122,   123,   124,   125,
     129,   130,   131,   135,   136,   137,   141,   142,   143,   144,
     145,   149,   150,   151,   155,   156,   160,   161,   165,   166,
     170,   171,   175,   176,   180,   181,   185,   186,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   204,
     205,   209,   213,   214,   215,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   232,   233,   237,   238,   242,
     243,   244,   245,   246,   247,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   270,   271,   272,   276,   277,   281,   282,   286,   287,
     288,   292,   293,   294,   295,   299,   300,   304,   305,   306,
     310,   311,   312,   313,   314,   318,   319,   323,   324,   328,
     332,   333,   334,   335,   339,   340,   344,   345,   349,   350,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   371,   372,   373,   374,   378,   379,
     384,   385,   389,   390,   394,   395,   396,   400,   401,   405,
     406,   410,   411,   412,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   440,   441,   442,   446,   447,
     448,   449,   453,   457,   458,   462,   463,   467,   471,   472,
     473,   474,   475,   476,   480,   481,   482,   486,   487,   491,
     492,   496,   497,   501,   502,   506,   507,   508,   512,   513,
     514,   515,   516,   517,   521,   522,   523,   524,   525,   529,
     530,   534,   535,   539,   540,   544,   545
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
  "')'", "','", "':'", "'['", "']'", "'.'", "'{'", "'}'", "'&'", "'*'",
  "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'",
  "'?'", "'='", "';'", "$accept", "program", "primary_expression",
  "constant", "enumeration_constant", "string", "generic_selection",
  "generic_assoc_list", "generic_association", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "atomic_type_specifier", "type_qualifier", "function_specifier",
  "alignment_specifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "static_assert_declaration", "statement", "labeled_statement",
  "compound_statement", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", "declaration_list", YY_NULLPTR
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
     325,   326,   327,   328,   329,   330,    40,    41,    44,    58,
      91,    93,    46,   123,   125,    38,    42,    43,    45,   126,
      33,    47,    37,    60,    62,    94,   124,    63,    61,    59
};
# endif

#define YYPACT_NINF -274

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-274)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2124,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,
    -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,
    -274,  -274,  -274,  -274,  -274,    26,   -29,   -20,  -274,   -18,
    -274,    45,  -274,    48,  2214,  2214,  -274,    37,  -274,  -274,
    2214,  2214,  2214,  -274,  2124,  -274,  -274,    11,    64,   851,
    2323,  1599,  -274,  -274,    72,   134,  -274,   -21,  -274,  1810,
     -11,    93,  -274,  -274,    33,  2252,  -274,  -274,  -274,  -274,
      64,  -274,    -9,   105,  -274,  -274,  -274,  -274,  -274,  -274,
    1621,  1643,  1643,  -274,    67,    79,   851,  -274,  -274,  -274,
    -274,  -274,  -274,  -274,  -274,  -274,  -274,   223,  -274,  1599,
    -274,   -61,   129,   213,    21,    17,    95,    62,    97,   152,
      40,  -274,   120,  2323,   -48,  2323,   150,   162,   164,   179,
    -274,  -274,  -274,   134,    72,  -274,   407,  1357,  -274,    48,
    -274,  2026,  1764,   939,   -11,  2252,  1926,  -274,    52,  -274,
     118,  1599,    19,  -274,   851,  -274,   851,  -274,  -274,  2323,
    1599,   400,  -274,  -274,   159,   202,   282,  -274,  -274,  1379,
    1599,   293,  -274,  1599,  1599,  1599,  1599,  1599,  1599,  1599,
    1599,  1599,  1599,  1599,  1599,  1599,  1599,  1599,  1599,  1599,
    1599,  1599,  -274,  -274,  1877,   961,    74,  -274,   108,  -274,
    -274,  -274,   294,  -274,  -274,  -274,  -274,   209,   225,  1599,
     231,   226,   239,   241,   671,   243,   319,   228,   230,   715,
    -274,  -274,   101,  -274,  -274,  -274,  -274,   528,  -274,  -274,
    -274,  -274,  -274,  1335,  -274,  -274,  -274,  -274,  -274,  -274,
      59,   254,   261,  -274,   167,  1203,  -274,   265,   266,   983,
    1973,  -274,  -274,  1599,  -274,   104,  -274,   269,    23,  -274,
    -274,  -274,  -274,   272,   273,   274,   295,  -274,  -274,  -274,
    -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  1599,  -274,
    1599,  1467,  -274,  -274,   175,  -274,   132,  -274,  -274,  -274,
    -274,   -61,   -61,   129,   129,   213,   213,   213,   213,    21,
      21,    17,    95,    62,    97,   152,   181,  -274,   297,   299,
    1203,  -274,   296,   298,  1071,   108,  2078,  1093,   301,   671,
     302,   671,  1599,  1599,  1599,   318,   618,   283,  -274,  -274,
    -274,   109,  -274,  -274,  -274,  1599,   380,  -274,   128,  1357,
     142,  -274,  1709,  -274,    85,  -274,  -274,  2170,  -274,   381,
     304,  1203,  -274,  -274,  1599,  -274,   305,   306,  -274,  -274,
      73,  -274,  1599,  -274,   307,   307,  -274,  2289,  -274,  -274,
    1335,  -274,  -274,  1599,  -274,  1599,  -274,  -274,   308,  1203,
    -274,  -274,  1599,  -274,   311,  -274,   316,  1203,  -274,   313,
     314,  1115,   289,  -274,   671,  -274,   184,   187,   199,   320,
     761,   761,  -274,  -274,   317,  -274,  1225,  -274,  -274,  -274,
    -274,  -274,  -274,  -274,  -274,   321,   322,  -274,  -274,  -274,
    -274,   325,   204,  -274,   326,   131,  -274,  -274,  -274,   327,
     328,  -274,  -274,   335,  1203,  -274,  -274,  1599,  -274,   338,
    -274,  -274,   671,   671,   671,  1599,  1489,  1511,  -274,  -274,
    -274,  1357,  -274,  -274,  1599,  -274,  2289,  1599,  1247,  -274,
    -274,  -274,  -274,   349,   350,  -274,   339,  -274,  -274,   206,
     671,   210,   671,   216,  -274,  -274,  -274,  -274,  -274,  -274,
    -274,   671,   333,  -274,   671,  -274,   671,  -274,  -274,  -274,
    -274
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   130,   109,   110,   111,   113,   114,   164,   160,   161,
     162,   124,   116,   117,   118,   119,   122,   123,   120,   121,
     115,   125,   126,   134,   135,     0,     0,   163,   165,     0,
     112,     0,   272,     0,    96,    98,   128,     0,   129,   127,
     100,   102,   104,    94,     2,   269,   271,   154,     0,     0,
       0,     0,     1,   170,     0,   187,    92,     0,   105,   108,
     169,     0,    95,    97,   133,     0,    99,   101,   103,   270,
       0,    11,   158,     0,   155,     3,     8,     9,    12,    13,
       0,     0,     0,    10,     0,     0,     0,    38,    39,    40,
      41,    42,    43,    19,     4,     5,     7,    31,    44,     0,
      46,    50,    53,    56,    61,    64,    66,    68,    70,    72,
      74,    91,     0,   142,   200,   144,     0,     0,     0,     0,
     163,   188,   186,   185,     0,    93,     0,     0,   275,     0,
     274,     0,     0,     0,   168,     0,     0,   136,     0,   140,
       0,     0,     0,   150,     0,    35,     0,    32,    33,     0,
       0,    44,    76,    89,     0,     0,     0,    25,    26,     0,
       0,     0,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   167,   141,     0,     0,   202,   199,   203,   143,
     166,   159,     0,   171,   189,   184,   106,   108,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     247,   253,     0,   251,   252,   238,   239,     0,   249,   240,
     241,   242,   243,     0,   227,   107,   276,   273,   197,   182,
     196,     0,   191,   192,     0,     0,   172,    39,     0,     0,
       0,   131,   137,     0,   138,     0,   145,   149,     0,   152,
     157,   151,   156,     0,     0,     0,     0,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    78,     0,     6,
       0,     0,    24,    21,     0,    29,     0,    23,    47,    48,
      49,    51,    52,    54,    55,    59,    60,    57,    58,    62,
      63,    65,    67,    69,    71,    73,     0,   221,     0,     0,
       0,   205,    39,     0,     0,   201,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   265,   266,
     267,     0,   254,   248,   250,     0,     0,   229,     0,     0,
       0,   233,     0,   194,   202,   195,   181,     0,   183,     0,
       0,     0,   173,   180,     0,   179,    39,     0,   132,   147,
       0,   139,     0,   153,    36,     0,    37,     0,    77,    90,
       0,    45,    22,     0,    20,     0,   222,   204,     0,     0,
     206,   212,     0,   211,     0,   223,     0,     0,   213,    39,
       0,     0,     0,   244,     0,   246,     0,     0,     0,     0,
       0,     0,   264,   268,     0,   236,     0,   225,   228,   232,
     234,   190,   193,   198,   175,     0,     0,   176,   178,   146,
     148,     0,     0,    15,     0,     0,    30,    75,   208,     0,
       0,   210,   224,     0,     0,   214,   220,     0,   219,     0,
     237,   245,     0,     0,     0,     0,     0,     0,   235,   226,
     231,     0,   174,   177,     0,    14,     0,     0,     0,    27,
     207,   209,   216,     0,     0,   217,   256,   257,   258,     0,
       0,     0,     0,     0,   230,    18,    16,    17,    28,   215,
     218,     0,     0,   262,     0,   260,     0,   255,   259,   263,
     261
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,   -40,  -274,
    -274,   192,  -274,   -53,   158,   168,    77,   169,   224,   256,
     229,   255,   287,  -274,   -39,  -106,  -274,   -83,   -36,   -46,
       8,  -274,   312,  -274,   -45,  -274,  -274,   351,  -113,     6,
    -274,   135,  -274,   414,  -123,  -274,   -49,  -274,  -274,   -16,
     -54,   -31,   -79,  -121,  -274,   151,  -274,    32,  -100,  -168,
    -118,   127,  -273,  -274,   170,   -63,  -165,  -274,     1,  -274,
     284,  -223,  -274,  -274,  -274,  -274,   445,  -274,  -274
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    31,    93,    94,    72,    95,    96,   412,   413,    97,
     274,   151,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   152,   153,   268,   212,   112,    32,
     129,    57,    58,    34,    35,    36,    37,   136,   137,   114,
     245,   246,    38,    73,    74,    39,    40,    41,    42,   119,
      60,    61,   123,   298,   232,   233,   234,   414,   299,   188,
     327,   328,   329,   330,   331,    43,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    44,    45,    46,   131
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     115,   115,   139,   154,   113,   113,   121,   134,    33,   225,
     111,   231,   111,   128,   187,   118,   115,    59,   305,   252,
     113,   224,    71,   242,   122,   163,    71,   238,   184,    47,
     164,   165,   185,   174,   175,   170,   171,   115,    55,   315,
      64,   113,    62,    63,   256,    52,   162,    49,    66,    67,
      68,    53,    33,   275,   239,    53,    50,   124,    51,   180,
     130,   154,    53,   154,   115,   132,   115,    71,   113,   133,
     113,   138,   139,   139,   194,    53,    53,   276,   125,   303,
     213,   116,   117,   186,   121,   226,   115,   115,    53,   141,
     113,   113,   195,   391,    70,   115,    53,   115,   296,   113,
     115,   113,   111,   251,   113,   250,   304,   353,   197,    48,
     278,   279,   280,   197,   172,   173,   135,   224,   155,   183,
      65,   189,   247,   441,    54,   252,   321,   242,    54,   340,
     335,   243,   227,   347,    55,   332,   121,   181,    55,   185,
     230,   138,   138,   149,   383,    55,   385,    56,    54,    54,
     184,   244,   243,   186,   185,   150,   341,   177,    55,    55,
     111,   332,   358,   310,   359,   185,   305,   436,   437,    54,
     179,   213,     8,     9,    10,   441,   253,   139,   254,   270,
     176,   255,   350,   142,   306,   376,   121,   270,   307,   143,
     194,   115,   230,   178,   368,   113,   248,   182,   374,   334,
     322,   380,   249,   351,   111,   120,   396,   349,   393,   448,
     270,   398,   397,   364,   333,   449,   166,   167,   361,   431,
      55,   369,   325,   224,   326,   168,   169,   190,   381,   386,
     387,   388,   156,   157,   158,   405,   269,   270,   406,   191,
     399,    98,   192,    98,   338,   339,   138,   285,   286,   287,
     288,   121,   362,   363,   224,   194,   193,   416,   121,   270,
     365,   432,   270,   419,   433,   270,   420,   456,   457,   458,
     390,   423,   145,   147,   148,   429,   434,   270,   440,   271,
     134,   445,   446,   472,   270,   272,   111,   474,   270,   394,
     224,    98,   194,   476,   270,   473,   277,   475,   424,   159,
     308,   334,   312,   160,   309,   161,   477,   127,   115,   479,
     311,   480,   113,   111,   230,   313,   410,   314,   453,   316,
     194,   454,   317,   464,   281,   282,   417,   318,   121,   319,
     440,   336,   194,    98,   247,   224,   283,   284,   465,   337,
     230,   467,   224,   289,   290,   230,   342,   343,   352,   354,
     355,   356,   459,   461,   463,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,   357,   366,   194,   367,   370,   382,   371,
     389,   384,   392,   395,   403,   404,   407,   408,   430,   418,
     360,    98,   421,   422,   425,   426,   435,   115,   438,   471,
     291,   113,   442,   443,   444,   447,   466,   293,   450,   451,
     198,    76,    77,    78,    79,    80,   452,    81,    82,   455,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     469,   470,   478,   292,   294,    98,   196,     1,    83,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    98,   199,   200,   201,   295,   202,   203,
     204,   205,   206,   207,   208,   209,    26,    84,    27,    85,
      28,    29,    30,    86,   140,   409,   240,   415,   402,    69,
     126,   210,    87,    88,    89,    90,    91,    92,   267,     0,
     400,   324,     0,     0,     0,     0,   211,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   198,    76,    77,    78,    79,    80,     0,    81,    82,
       0,     0,     0,     0,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    98,     1,    83,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,   199,   200,   201,     0,   202,
     203,   204,   205,   206,   207,   208,   209,    26,    84,    27,
      85,    28,    29,    30,    86,     0,     0,     0,     0,     0,
       0,   126,   323,    87,    88,    89,    90,    91,    92,     0,
       0,    75,    76,    77,    78,    79,    80,   211,    81,    82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,    83,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   198,    76,    77,    78,    79,    80,
       0,    81,    82,     0,     0,     0,     0,    26,    84,    27,
      85,    28,    29,    30,    86,     0,     0,     0,     0,     0,
       0,     0,    83,    87,    88,    89,    90,    91,    92,     0,
       0,     0,     0,     0,     0,     0,     0,   211,    75,    76,
      77,    78,    79,    80,     0,    81,    82,     0,   199,   200,
     201,     0,   202,   203,   204,   205,   206,   207,   208,   209,
       0,    84,     0,    85,     0,     0,    83,    86,     0,     0,
       0,     0,     0,     0,   126,     0,    87,    88,    89,    90,
      91,    92,     0,     0,    75,    76,    77,    78,    79,    80,
     211,    81,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,     0,    85,     0,     0,
       0,    86,    83,     0,     0,     0,     0,     0,     0,     0,
      87,    88,    89,    90,    91,    92,     0,     0,     0,     0,
       0,     0,     0,     0,   320,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,     0,    85,     0,     0,     0,    86,     0,     0,
       0,     0,     0,     0,     0,     0,    87,    88,    89,    90,
      91,    92,     0,     0,    75,    76,    77,    78,    79,    80,
     211,    81,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,    83,     0,     0,     0,     0,     0,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,    27,    85,     0,     0,     0,    86,     0,     0,
       0,     0,     0,     0,     0,     0,    87,    88,    89,    90,
      91,    92,    75,    76,    77,    78,    79,    80,     0,    81,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    75,    76,    77,    78,    79,    80,
      83,    81,    82,   235,     0,     0,     0,     8,     9,    10,
       0,     0,     0,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    83,    81,    82,   300,     0,     0,     0,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,    84,
     120,    85,     0,     0,    83,    86,     0,   344,     0,     0,
     236,     8,     9,    10,    87,   237,    89,    90,    91,    92,
       0,    84,   120,    85,     0,     0,     0,    86,     0,     0,
       0,     0,   301,     0,     0,     0,    87,   302,    89,    90,
      91,    92,     0,    84,   120,    85,     0,     0,     0,    86,
       0,     0,     0,     0,   345,     0,     0,     0,    87,   346,
      89,    90,    91,    92,    75,    76,    77,    78,    79,    80,
       0,    81,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    83,    81,    82,   372,     0,     0,     0,     8,
       9,    10,     0,     0,     0,     0,     0,     0,    75,    76,
      77,    78,    79,    80,    83,    81,    82,   377,     0,     0,
       0,     8,     9,    10,     0,     0,     0,     0,     0,     0,
       0,    84,   120,    85,     0,     0,    83,    86,     0,   427,
       0,     0,   373,     8,     9,    10,    87,    88,    89,    90,
      91,    92,     0,    84,   120,    85,     0,     0,     0,    86,
       0,     0,     0,     0,   378,     0,     0,     0,    87,   379,
      89,    90,    91,    92,     0,    84,   120,    85,     0,     0,
       0,    86,     0,     0,     0,     0,   428,     0,     0,     0,
      87,    88,    89,    90,    91,    92,    75,    76,    77,    78,
      79,    80,     0,    81,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    75,    76,
      77,    78,    79,    80,    83,    81,    82,     0,     0,     0,
       0,     8,     9,    10,     0,     0,     0,     0,     0,     0,
      75,    76,    77,    78,    79,    80,    83,    81,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,   120,    85,     0,     0,    83,    86,
       0,     0,     0,     0,     0,     0,     0,     0,    87,    88,
      89,    90,    91,    92,     0,    84,     0,    85,     0,     0,
       0,    86,     0,     0,     0,   325,     0,   326,   223,   439,
      87,    88,    89,    90,    91,    92,     0,    84,     0,    85,
       0,     0,     0,    86,     0,     0,     0,   325,     0,   326,
     223,   468,    87,    88,    89,    90,    91,    92,    75,    76,
      77,    78,    79,    80,     0,    81,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      75,    76,    77,    78,    79,    80,    83,    81,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    75,    76,    77,    78,    79,    80,    83,    81,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,     0,    85,     0,     0,
      83,    86,     0,     0,     0,   325,     0,   326,   223,     0,
      87,    88,    89,    90,    91,    92,     0,    84,     0,    85,
       0,     0,     0,    86,     0,     0,     0,     0,     0,     0,
     223,     0,    87,    88,    89,    90,    91,    92,     0,    84,
       0,    85,     0,     0,     0,    86,   273,     0,     0,     0,
       0,     0,     0,     0,    87,    88,    89,    90,    91,    92,
      75,    76,    77,    78,    79,    80,     0,    81,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    75,    76,    77,    78,    79,    80,    83,    81,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    75,    76,    77,    78,    79,    80,
      83,    81,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,     0,    85,
       0,     0,    83,    86,     0,     0,     0,     0,     0,     0,
     360,     0,    87,    88,    89,    90,    91,    92,     0,    84,
       0,    85,     0,     0,     0,    86,   460,     0,     0,     0,
       0,     0,     0,     0,    87,    88,    89,    90,    91,    92,
       0,    84,     0,    85,     0,     0,     0,    86,   462,     0,
       0,     0,     0,     0,     0,     0,    87,    88,    89,    90,
      91,    92,    75,    76,    77,    78,    79,    80,     0,    81,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    75,    76,    77,    78,    79,    80,
      83,    81,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    83,    81,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
       0,    85,     0,     0,    83,    86,     0,     0,     0,     0,
       0,     0,     0,     0,    87,    88,    89,    90,    91,    92,
       0,    84,     0,    85,     0,     0,     0,   144,     0,     0,
       0,     0,     0,     0,     0,     0,    87,    88,    89,    90,
      91,    92,    53,    84,     0,    85,     0,     0,     0,   146,
       0,     0,     0,     0,     0,     0,     0,     0,    87,    88,
      89,    90,    91,    92,     0,     0,     0,     0,     0,     1,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,     0,   228,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
      27,     0,    28,     0,    30,   332,   297,     0,     0,   185,
       0,     0,     0,     0,     1,    55,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,    27,     0,    28,     0,    30,
       1,   229,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,    27,     0,    28,    29,    30,     0,     0,     0,     0,
       0,     0,     0,   126,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,   127,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,     0,    27,     0,
      28,     0,    30,   184,   297,     0,     1,   185,     0,     0,
       0,     0,     0,    55,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,     0,
      29,     0,     0,     1,     0,     0,     0,     0,     0,     0,
     241,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,     0,     0,    29,     0,     0,
       0,     0,     0,     0,     0,     0,     1,   348,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,    27,     0,    28,
      29,    30,     0,     0,     0,     0,     0,     0,     1,   126,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,     0,    27,
       0,    28,     0,    30,     1,   375,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,    27,     0,    28,    29,    30,
       1,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   401,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,    27,     0,    28,     1,    30,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,    26,     0,    27,     0,    28,     0,    30,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     0,     0,    27,     0,     0,    29,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,     0,   411,     0,     0,
       0,     0,     0,     1,     0,     0,     0,     0,     0,     0,
      27,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27
};

static const yytype_int16 yycheck[] =
{
      49,    50,    65,    86,    49,    50,    55,    61,     0,   127,
      49,   132,    51,    59,   114,    51,    65,    33,   186,   142,
      65,   127,     3,   136,    55,    86,     3,   133,    76,     3,
      91,    92,    80,    16,    17,    14,    15,    86,    86,   204,
       3,    86,    34,    35,   150,     0,    99,    76,    40,    41,
      42,     3,    44,   159,   133,     3,    76,    78,    76,    19,
      59,   144,     3,   146,   113,    76,   115,     3,   113,    80,
     115,    65,   135,   136,   123,     3,     3,   160,    99,   185,
     126,    49,    50,   114,   133,   131,   135,   136,     3,    98,
     135,   136,   123,   316,    83,   144,     3,   146,   181,   144,
     149,   146,   141,    84,   149,   141,   185,    84,   124,    83,
     163,   164,   165,   129,    93,    94,    83,   223,    86,   113,
      83,   115,   138,   396,    76,   248,   209,   240,    76,   235,
     230,    79,   131,   239,    86,    76,   185,    97,    86,    80,
     132,   135,   136,    76,   309,    86,   311,    99,    76,    76,
      76,    99,    79,   184,    80,    76,   235,    95,    86,    86,
     199,    76,   268,   199,   270,    80,   334,   390,   391,    76,
      18,   217,    38,    39,    40,   448,   144,   240,   146,    78,
      85,   149,    78,    78,    76,   306,   235,    78,    80,    84,
     239,   240,   184,    96,   300,   240,    78,    77,   304,   230,
      99,   307,    84,    99,   243,    71,    78,   243,    99,    78,
      78,   329,    84,    81,   230,    84,    87,    88,   271,   384,
      86,   300,    80,   329,    82,    12,    13,    77,   307,   312,
     313,   314,     9,    10,    11,   341,    77,    78,   344,    77,
      98,    49,    78,    51,    77,    78,   240,   170,   171,   172,
     173,   300,    77,    78,   360,   304,    77,   363,   307,    78,
      79,    77,    78,   369,    77,    78,   372,   432,   433,   434,
     316,   377,    80,    81,    82,   381,    77,    78,   396,    77,
     334,    77,    78,    77,    78,     3,   325,    77,    78,   325,
     396,    99,   341,    77,    78,   460,     3,   462,   377,    76,
       6,   332,    76,    80,    79,    82,   471,    98,   357,   474,
      79,   476,   357,   352,   306,    76,   352,    76,   424,    76,
     369,   427,     3,   441,   166,   167,   365,    99,   377,    99,
     448,    77,   381,   141,   350,   441,   168,   169,   444,    78,
     332,   447,   448,   174,   175,   337,    81,    81,    79,    77,
      77,    77,   435,   436,   437,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,    78,    77,   424,    77,    81,    77,    81,
      62,    79,    99,     3,     3,    81,    81,    81,    99,    81,
      83,   199,    81,    77,    81,    81,    76,   446,    81,    60,
     176,   446,    81,    81,    79,    79,   446,   178,    81,    81,
       3,     4,     5,     6,     7,     8,    81,    10,    11,    81,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      81,    81,    99,   177,   179,   243,   124,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,   271,    57,    58,    59,   180,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    70,   350,   135,   360,   337,    44,
      83,    84,    85,    86,    87,    88,    89,    90,    98,    -1,
     330,   217,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   325,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,   352,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   365,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    58,    59,    -1,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    85,    86,    87,    88,    89,    90,    -1,
      -1,     3,     4,     5,     6,     7,     8,    99,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    85,    86,    87,    88,    89,    90,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    57,    58,
      59,    -1,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    -1,    72,    -1,    -1,    31,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    -1,    85,    86,    87,    88,
      89,    90,    -1,    -1,     3,     4,     5,     6,     7,     8,
      99,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    -1,    -1,
      -1,    76,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    87,    88,    89,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,    -1,    -1,     3,     4,     5,     6,     7,     8,
      99,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      31,    10,    11,    34,    -1,    -1,    -1,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    31,    10,    11,    34,    -1,    -1,    -1,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    -1,    -1,    31,    76,    -1,    34,    -1,    -1,
      81,    38,    39,    40,    85,    86,    87,    88,    89,    90,
      -1,    70,    71,    72,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,    -1,    70,    71,    72,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    90,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    31,    10,    11,    34,    -1,    -1,    -1,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,    31,    10,    11,    34,    -1,    -1,
      -1,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    -1,    -1,    31,    76,    -1,    34,
      -1,    -1,    81,    38,    39,    40,    85,    86,    87,    88,
      89,    90,    -1,    70,    71,    72,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    90,    -1,    70,    71,    72,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      85,    86,    87,    88,    89,    90,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,    31,    10,    11,    -1,    -1,    -1,
      -1,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    31,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    -1,    -1,    31,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    90,    -1,    70,    -1,    72,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    80,    -1,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    70,    -1,    72,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    80,    -1,    82,
      83,    84,    85,    86,    87,    88,    89,    90,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    31,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    31,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    -1,    -1,
      31,    76,    -1,    -1,    -1,    80,    -1,    82,    83,    -1,
      85,    86,    87,    88,    89,    90,    -1,    70,    -1,    72,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    -1,    85,    86,    87,    88,    89,    90,    -1,    70,
      -1,    72,    -1,    -1,    -1,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    31,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      31,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,
      -1,    -1,    31,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    -1,    85,    86,    87,    88,    89,    90,    -1,    70,
      -1,    72,    -1,    -1,    -1,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
      -1,    70,    -1,    72,    -1,    -1,    -1,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      31,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    31,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    72,    -1,    -1,    31,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
      -1,    70,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,     3,    70,    -1,    72,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    90,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      71,    -1,    73,    -1,    75,    76,    77,    -1,    -1,    80,
      -1,    -1,    -1,    -1,    30,    86,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    71,    -1,    73,    -1,    75,
      30,    77,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,    -1,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    98,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    -1,
      73,    -1,    75,    76,    77,    -1,    30,    80,    -1,    -1,
      -1,    -1,    -1,    86,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      74,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    84,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    -1,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    30,    83,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,
      -1,    73,    -1,    75,    30,    77,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    71,    -1,    73,    74,    75,
      30,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,    -1,    73,    30,    75,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    69,    -1,    71,    -1,    73,    -1,    75,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    71,    -1,    -1,    74,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    69,    71,    73,    74,
      75,   101,   129,   130,   133,   134,   135,   136,   142,   145,
     146,   147,   148,   165,   175,   176,   177,     3,    83,    76,
      76,    76,     0,     3,    76,    86,    99,   131,   132,   149,
     150,   151,   130,   130,     3,    83,   130,   130,   130,   176,
      83,     3,   104,   143,   144,     3,     4,     5,     6,     7,
       8,    10,    11,    31,    70,    72,    76,    85,    86,    87,
      88,    89,    90,   102,   103,   105,   106,   109,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   128,   134,   139,   146,   157,   157,   128,   149,
      71,   146,   151,   152,    78,    99,    83,    98,   129,   130,
     168,   178,    76,    80,   150,    83,   137,   138,   139,   165,
     143,    98,    78,    84,    76,   111,    76,   111,   111,    76,
      76,   111,   124,   125,   127,   157,     9,    10,    11,    76,
      80,    82,   113,    86,    91,    92,    87,    88,    12,    13,
      14,    15,    93,    94,    16,    17,    85,    95,    96,    18,
      19,    97,    77,   139,    76,    80,   151,   158,   159,   139,
      77,    77,    78,    77,   146,   151,   132,   149,     3,    57,
      58,    59,    61,    62,    63,    64,    65,    66,    67,    68,
      84,    99,   127,   129,   166,   167,   168,   169,   170,   171,
     172,   173,   174,    83,   125,   160,   129,   168,     3,    77,
     130,   153,   154,   155,   156,    34,    81,    86,   125,   152,
     137,    84,   138,    79,    99,   140,   141,   149,    78,    84,
     128,    84,   144,   157,   157,   157,   125,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    98,   126,    77,
      78,    77,     3,    77,   110,   125,   127,     3,   113,   113,
     113,   114,   114,   115,   115,   116,   116,   116,   116,   117,
     117,   118,   119,   120,   121,   122,   127,    77,   153,   158,
      34,    81,    86,   125,   152,   159,    76,    80,     6,    79,
     128,    79,    76,    76,    76,   166,    76,     3,    99,    99,
      99,   127,    99,    84,   170,    80,    82,   160,   161,   162,
     163,   164,    76,   149,   151,   158,    77,    78,    77,    78,
     125,   152,    81,    81,    34,    81,    86,   125,    84,   128,
      78,    99,    79,    84,    77,    77,    77,    78,   125,   125,
      83,   113,    77,    78,    81,    79,    77,    77,   125,   152,
      81,    81,    34,    81,   125,    77,   153,    34,    81,    86,
     125,   152,    77,   166,    79,   166,   127,   127,   127,    62,
     129,   171,    99,    99,   128,     3,    78,    84,   160,    98,
     164,    56,   155,     3,    81,   125,   125,    81,    81,   141,
     128,    58,   107,   108,   157,   161,   125,   124,    81,   125,
     125,    81,    77,   125,   152,    81,    81,    34,    81,   125,
      99,   166,    77,    77,    77,    76,   171,   171,    81,    84,
     160,   162,    81,    81,    79,    77,    78,    79,    78,    84,
      81,    81,    81,   125,   125,    81,   166,   166,   166,   127,
      77,   127,    77,   127,   160,   125,   108,   125,    84,    81,
      81,    60,    77,   166,    77,   166,    77,   166,    99,   166,
     166
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   100,   101,   102,   102,   102,   102,   102,   103,   103,
     103,   104,   105,   105,   106,   107,   107,   108,   108,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   110,
     110,   111,   111,   111,   111,   111,   111,   111,   112,   112,
     112,   112,   112,   112,   113,   113,   114,   114,   114,   114,
     115,   115,   115,   116,   116,   116,   117,   117,   117,   117,
     117,   118,   118,   118,   119,   119,   120,   120,   121,   121,
     122,   122,   123,   123,   124,   124,   125,   125,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   127,
     127,   128,   129,   129,   129,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   131,   131,   132,   132,   133,
     133,   133,   133,   133,   133,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   135,   135,   135,   136,   136,   137,   137,   138,   138,
     138,   139,   139,   139,   139,   140,   140,   141,   141,   141,
     142,   142,   142,   142,   142,   143,   143,   144,   144,   145,
     146,   146,   146,   146,   147,   147,   148,   148,   149,   149,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   151,   151,   151,   151,   152,   152,
     153,   153,   154,   154,   155,   155,   155,   156,   156,   157,
     157,   158,   158,   158,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   160,   160,   160,   161,   161,
     161,   161,   162,   163,   163,   164,   164,   165,   166,   166,
     166,   166,   166,   166,   167,   167,   167,   168,   168,   169,
     169,   170,   170,   171,   171,   172,   172,   172,   173,   173,
     173,   173,   173,   173,   174,   174,   174,   174,   174,   175,
     175,   176,   176,   177,   177,   178,   178
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     6,     1,     3,     3,     3,     1,
       4,     3,     4,     3,     3,     2,     2,     6,     7,     1,
       3,     1,     2,     2,     2,     2,     4,     4,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     5,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     2,     3,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     1,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     5,     2,     1,     1,     1,     2,     2,     3,
       1,     2,     1,     2,     1,     1,     3,     2,     3,     1,
       4,     5,     5,     6,     2,     1,     3,     3,     1,     4,
       1,     1,     1,     1,     1,     1,     4,     4,     2,     1,
       1,     3,     3,     4,     6,     5,     5,     6,     5,     4,
       4,     4,     3,     4,     3,     2,     2,     1,     1,     2,
       3,     1,     1,     3,     2,     2,     1,     1,     3,     2,
       1,     2,     1,     1,     3,     2,     3,     5,     4,     5,
       4,     3,     3,     3,     4,     6,     5,     5,     6,     4,
       4,     2,     3,     3,     4,     3,     4,     1,     2,     1,
       4,     3,     2,     1,     2,     3,     2,     7,     1,     1,
       1,     1,     1,     1,     3,     4,     3,     2,     3,     1,
       2,     1,     1,     1,     2,     7,     5,     5,     5,     7,
       6,     7,     6,     7,     3,     2,     2,     2,     3,     1,
       2,     1,     1,     4,     3,     1,     2
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
#line 39 "c.y" /* yacc.c:1646  */
    { root = new ast_program((yyvsp[0])); }
#line 2048 "c.tab.cpp" /* yacc.c:1646  */
    break;


#line 2052 "c.tab.cpp" /* yacc.c:1646  */
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
#line 548 "c.y" /* yacc.c:1906  */

#include <stdio.h>

void yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "*** %s\n", s);
}
