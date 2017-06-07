/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         HINT_PARSER_parse
#define yylex           HINT_PARSER_lex
#define yyerror         HINT_PARSER_error
#define yylval          HINT_PARSER_lval
#define yychar          HINT_PARSER_char
#define yydebug         HINT_PARSER_debug
#define yynerrs         HINT_PARSER_nerrs

/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 21 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"

#include "sql_class.h"
#include "parse_tree_hints.h"
#include "sql_lex_hints.h"
#include "sql_const.h"
#include "derror.h"

#define NEW_PTN new (thd->mem_root)

/* Line 371 of yacc.c  */
#line 85 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/dist_GPL/sql/sql_hints.yy.cc"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "sql_hints.yy.h".  */
#ifndef YY_HINT_PARSER_EXPORT_HOME2_PB2_BUILD_SB_2_22823765_1490244772_57_DIST_GPL_SQL_SQL_HINTS_YY_H_INCLUDED
# define YY_HINT_PARSER_EXPORT_HOME2_PB2_BUILD_SB_2_22823765_1490244772_57_DIST_GPL_SQL_SQL_HINTS_YY_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int HINT_PARSER_debug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     MAX_EXECUTION_TIME_HINT = 258,
     BKA_HINT = 259,
     BNL_HINT = 260,
     DUPSWEEDOUT_HINT = 261,
     FIRSTMATCH_HINT = 262,
     INTOEXISTS_HINT = 263,
     LOOSESCAN_HINT = 264,
     MATERIALIZATION_HINT = 265,
     NO_BKA_HINT = 266,
     NO_BNL_HINT = 267,
     NO_ICP_HINT = 268,
     NO_MRR_HINT = 269,
     NO_RANGE_OPTIMIZATION_HINT = 270,
     NO_SEMIJOIN_HINT = 271,
     MRR_HINT = 272,
     QB_NAME_HINT = 273,
     SEMIJOIN_HINT = 274,
     SUBQUERY_HINT = 275,
     DERIVED_MERGE_HINT = 276,
     NO_DERIVED_MERGE_HINT = 277,
     JOIN_PREFIX_HINT = 278,
     JOIN_SUFFIX_HINT = 279,
     JOIN_ORDER_HINT = 280,
     JOIN_FIXED_ORDER_HINT = 281,
     INDEX_MERGE_HINT = 282,
     NO_INDEX_MERGE_HINT = 283,
     HINT_ARG_NUMBER = 284,
     HINT_ARG_IDENT = 285,
     HINT_ARG_QB_NAME = 286,
     HINT_CLOSE = 287,
     HINT_ERROR = 288
   };
#endif
/* Tokens.  */
#define MAX_EXECUTION_TIME_HINT 258
#define BKA_HINT 259
#define BNL_HINT 260
#define DUPSWEEDOUT_HINT 261
#define FIRSTMATCH_HINT 262
#define INTOEXISTS_HINT 263
#define LOOSESCAN_HINT 264
#define MATERIALIZATION_HINT 265
#define NO_BKA_HINT 266
#define NO_BNL_HINT 267
#define NO_ICP_HINT 268
#define NO_MRR_HINT 269
#define NO_RANGE_OPTIMIZATION_HINT 270
#define NO_SEMIJOIN_HINT 271
#define MRR_HINT 272
#define QB_NAME_HINT 273
#define SEMIJOIN_HINT 274
#define SUBQUERY_HINT 275
#define DERIVED_MERGE_HINT 276
#define NO_DERIVED_MERGE_HINT 277
#define JOIN_PREFIX_HINT 278
#define JOIN_SUFFIX_HINT 279
#define JOIN_ORDER_HINT 280
#define JOIN_FIXED_ORDER_HINT 281
#define INDEX_MERGE_HINT 282
#define NO_INDEX_MERGE_HINT 283
#define HINT_ARG_NUMBER 284
#define HINT_ARG_IDENT 285
#define HINT_ARG_QB_NAME 286
#define HINT_CLOSE 287
#define HINT_ERROR 288



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int HINT_PARSER_parse (void *YYPARSE_PARAM);
#else
int HINT_PARSER_parse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int HINT_PARSER_parse (class THD *thd, class Hint_scanner *scanner, class PT_hint_list **ret);
#else
int HINT_PARSER_parse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_HINT_PARSER_EXPORT_HOME2_PB2_BUILD_SB_2_22823765_1490244772_57_DIST_GPL_SQL_SQL_HINTS_YY_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 215 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/dist_GPL/sql/sql_hints.yy.cc"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  45
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   151

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNRULES -- Number of states.  */
#define YYNSTATES  129

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      34,    35,     2,     2,    36,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,    10,    13,    15,    18,    20,    22,
      24,    26,    28,    33,    34,    36,    38,    42,    43,    45,
      47,    51,    52,    54,    56,    60,    62,    64,    67,    69,
      72,    73,    75,    81,    87,    93,    98,   104,   109,   115,
     120,   126,   131,   132,   134,   138,   140,   142,   144,   146,
     148,   150,   155,   161,   166,   172,   178,   184,   186,   188,
     190,   192,   194,   196,   198,   200,   202,   204,   206,   208
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      38,     0,    -1,    39,    32,    -1,    39,     1,    32,    -1,
       1,    32,    -1,    40,    -1,    39,    40,    -1,    58,    -1,
      57,    -1,    53,    -1,    63,    -1,    41,    -1,     3,    34,
      29,    35,    -1,    -1,    43,    -1,    50,    -1,    43,    36,
      50,    -1,    -1,    45,    -1,    49,    -1,    45,    36,    49,
      -1,    -1,    47,    -1,    48,    -1,    47,    36,    48,    -1,
      30,    -1,    30,    -1,    30,    52,    -1,    50,    -1,    31,
      30,    -1,    -1,    31,    -1,    19,    34,    52,    54,    35,
      -1,    16,    34,    52,    54,    35,    -1,    20,    34,    52,
      56,    35,    -1,    23,    34,    42,    35,    -1,    23,    34,
      31,    44,    35,    -1,    24,    34,    42,    35,    -1,    24,
      34,    31,    44,    35,    -1,    25,    34,    42,    35,    -1,
      25,    34,    31,    44,    35,    -1,    26,    34,    52,    35,
      -1,    -1,    55,    -1,    54,    36,    55,    -1,     7,    -1,
       9,    -1,    10,    -1,     6,    -1,    10,    -1,     8,    -1,
      59,    34,    42,    35,    -1,    59,    34,    31,    44,    35,
      -1,    60,    34,    42,    35,    -1,    60,    34,    31,    44,
      35,    -1,    61,    34,    51,    46,    35,    -1,    62,    34,
      51,    46,    35,    -1,     4,    -1,     5,    -1,    21,    -1,
      11,    -1,    12,    -1,    22,    -1,    17,    -1,    15,    -1,
      27,    -1,    13,    -1,    14,    -1,    28,    -1,    18,    34,
      30,    35,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   127,   127,   129,   131,   136,   142,   150,   151,   152,
     153,   154,   159,   181,   182,   186,   192,   201,   202,   206,
     212,   221,   222,   226,   232,   241,   245,   253,   261,   262,
     270,   271,   275,   282,   289,   296,   303,   310,   317,   324,
     331,   338,   347,   348,   352,   359,   360,   361,   362,   366,
     368,   373,   379,   386,   392,   402,   409,   419,   423,   427,
     434,   438,   442,   449,   453,   457,   464,   468,   472,   479
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAX_EXECUTION_TIME_HINT", "BKA_HINT",
  "BNL_HINT", "DUPSWEEDOUT_HINT", "FIRSTMATCH_HINT", "INTOEXISTS_HINT",
  "LOOSESCAN_HINT", "MATERIALIZATION_HINT", "NO_BKA_HINT", "NO_BNL_HINT",
  "NO_ICP_HINT", "NO_MRR_HINT", "NO_RANGE_OPTIMIZATION_HINT",
  "NO_SEMIJOIN_HINT", "MRR_HINT", "QB_NAME_HINT", "SEMIJOIN_HINT",
  "SUBQUERY_HINT", "DERIVED_MERGE_HINT", "NO_DERIVED_MERGE_HINT",
  "JOIN_PREFIX_HINT", "JOIN_SUFFIX_HINT", "JOIN_ORDER_HINT",
  "JOIN_FIXED_ORDER_HINT", "INDEX_MERGE_HINT", "NO_INDEX_MERGE_HINT",
  "HINT_ARG_NUMBER", "HINT_ARG_IDENT", "HINT_ARG_QB_NAME", "HINT_CLOSE",
  "HINT_ERROR", "'('", "')'", "','", "$accept", "start", "hint_list",
  "hint", "max_execution_time_hint", "opt_hint_param_table_list",
  "hint_param_table_list", "opt_hint_param_table_list_empty_qb",
  "hint_param_table_list_empty_qb", "opt_hint_param_index_list",
  "hint_param_index_list", "hint_param_index", "hint_param_table_empty_qb",
  "hint_param_table", "hint_param_table_ext", "opt_qb_name",
  "qb_level_hint", "semijoin_strategies", "semijoin_strategy",
  "subquery_strategy", "table_level_hint", "index_level_hint",
  "table_level_hint_type_on", "table_level_hint_type_off",
  "key_level_hint_type_on", "key_level_hint_type_off", "qb_name_hint", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,    40,    41,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    38,    38,    39,    39,    40,    40,    40,
      40,    40,    41,    42,    42,    43,    43,    44,    44,    45,
      45,    46,    46,    47,    47,    48,    49,    50,    51,    51,
      52,    52,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    54,    54,    54,    55,    55,    55,    55,    56,
      56,    57,    57,    57,    57,    58,    58,    59,    59,    59,
      60,    60,    60,    61,    61,    61,    62,    62,    62,    63
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     2,     1,     2,     1,     1,     1,
       1,     1,     4,     0,     1,     1,     3,     0,     1,     1,
       3,     0,     1,     1,     3,     1,     1,     2,     1,     2,
       0,     1,     5,     5,     5,     4,     5,     4,     5,     4,
       5,     4,     0,     1,     3,     1,     1,     1,     1,     1,
       1,     4,     5,     4,     5,     5,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    57,    58,    60,    61,    66,    67,    64,
       0,    63,     0,     0,     0,    59,    62,     0,     0,     0,
       0,    65,    68,     0,     0,     5,    11,     9,     8,     7,
       0,     0,     0,     0,    10,     4,     0,    30,     0,    30,
      30,    13,    13,    13,    30,     1,     0,     2,     6,    13,
      13,     0,     0,     0,    31,    42,     0,    42,     0,    30,
      17,     0,    14,    15,    17,     0,    17,     0,     0,     3,
      17,     0,    17,     0,     0,    28,    21,    21,    12,    48,
      45,    46,    47,     0,    43,    69,     0,    50,    49,     0,
      27,    26,     0,    18,    19,    35,     0,     0,    37,     0,
      39,    41,     0,    51,     0,    53,    29,    25,     0,    22,
      23,     0,    33,     0,    32,    34,    36,     0,    16,    38,
      40,    52,    54,    55,     0,    56,    44,    20,    24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    23,    24,    25,    26,    61,    62,    92,    93,   108,
     109,   110,    94,    63,    76,    55,    27,    83,    84,    89,
      28,    29,    30,    31,    32,    33,    34
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -52
static const yytype_int8 yypact[] =
{
      35,   -29,   -26,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
      -2,   -52,     3,    33,    39,   -52,   -52,    43,    56,    57,
      58,   -52,   -52,    85,     1,   -52,   -52,   -52,   -52,   -52,
      59,    60,    61,    62,   -52,   -52,    68,    67,    70,    67,
      67,   -20,     0,    13,    67,   -52,    71,   -52,   -52,    40,
      50,    52,    52,    64,   -52,    69,    66,    69,    -1,    67,
      72,    73,    74,   -52,    72,    76,    72,    77,    78,   -52,
      72,    79,    72,    80,    75,   -52,    86,    86,   -52,   -52,
     -52,   -52,   -52,    51,   -52,   -52,    53,   -52,   -52,    82,
     -52,   -52,    83,    84,   -52,   -52,    89,    87,   -52,    88,
     -52,   -52,    90,   -52,    91,   -52,   -52,   -52,    92,    93,
     -52,    95,   -52,    69,   -52,   -52,   -52,    72,   -52,   -52,
     -52,   -52,   -52,   -52,    86,   -52,   -52,   -52,   -52
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -52,   -52,   -52,    97,   -52,    -8,   -52,     2,   -52,    27,
     -52,   -18,   -10,   -51,    81,    25,   -52,    94,    -4,   -52,
     -52,   -52,   -52,   -52,   -52,   -52,   -52
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      75,    75,    46,    35,     2,     3,     4,    87,    36,    88,
      59,    60,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      59,    64,    37,    47,    65,    67,     1,    38,     2,     3,
       4,    71,    73,    59,    66,   118,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    57,    58,    97,    39,    99,    68,
      59,    70,   102,    40,   104,    79,    80,    41,    81,    82,
      59,    72,    59,    74,    90,    45,   112,   113,   114,   113,
      42,    43,    44,    49,    50,    51,    52,    53,    54,    78,
      56,    85,    91,    69,   111,   106,   128,   127,    95,   126,
      96,    98,   100,   101,   103,   105,   107,   115,   116,    59,
     117,    48,   119,   120,     0,   121,   122,   123,     0,   124,
     125,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-52)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
      51,    52,     1,    32,     3,     4,     5,     8,    34,    10,
      30,    31,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      30,    31,    34,    32,    42,    43,     1,    34,     3,     4,
       5,    49,    50,    30,    31,    96,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    39,    40,    64,    34,    66,    44,
      30,    31,    70,    34,    72,     6,     7,    34,     9,    10,
      30,    31,    30,    31,    59,     0,    35,    36,    35,    36,
      34,    34,    34,    34,    34,    34,    34,    29,    31,    35,
      30,    35,    30,    32,    77,    30,   124,   117,    35,   113,
      36,    35,    35,    35,    35,    35,    30,    35,    35,    30,
      36,    24,    35,    35,    -1,    35,    35,    35,    -1,    36,
      35,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    38,    39,    40,    41,    53,    57,    58,
      59,    60,    61,    62,    63,    32,    34,    34,    34,    34,
      34,    34,    34,    34,    34,     0,     1,    32,    40,    34,
      34,    34,    34,    29,    31,    52,    30,    52,    52,    30,
      31,    42,    43,    50,    31,    42,    31,    42,    52,    32,
      31,    42,    31,    42,    31,    50,    51,    51,    35,     6,
       7,     9,    10,    54,    55,    35,    54,     8,    10,    56,
      52,    30,    44,    45,    49,    35,    36,    44,    35,    44,
      35,    35,    44,    35,    44,    35,    30,    30,    46,    47,
      48,    46,    35,    36,    35,    35,    35,    36,    50,    35,
      35,    35,    35,    35,    36,    35,    55,    49,    48
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      yyerror (thd, scanner, ret, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, scanner)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, thd, scanner, ret); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, class THD *thd, class Hint_scanner *scanner, class PT_hint_list **ret)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, thd, scanner, ret)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    class THD *thd;
    class Hint_scanner *scanner;
    class PT_hint_list **ret;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (thd);
  YYUSE (scanner);
  YYUSE (ret);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, class THD *thd, class Hint_scanner *scanner, class PT_hint_list **ret)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, thd, scanner, ret)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    class THD *thd;
    class Hint_scanner *scanner;
    class PT_hint_list **ret;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, thd, scanner, ret);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, class THD *thd, class Hint_scanner *scanner, class PT_hint_list **ret)
#else
static void
yy_reduce_print (yyvsp, yyrule, thd, scanner, ret)
    YYSTYPE *yyvsp;
    int yyrule;
    class THD *thd;
    class Hint_scanner *scanner;
    class PT_hint_list **ret;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       , thd, scanner, ret);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, thd, scanner, ret); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, class THD *thd, class Hint_scanner *scanner, class PT_hint_list **ret)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, thd, scanner, ret)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    class THD *thd;
    class Hint_scanner *scanner;
    class PT_hint_list **ret;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (thd);
  YYUSE (scanner);
  YYUSE (ret);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (class THD *thd, class Hint_scanner *scanner, class PT_hint_list **ret)
#else
int
yyparse (thd, scanner, ret)
    class THD *thd;
    class Hint_scanner *scanner;
    class PT_hint_list **ret;
#endif
#endif
{
/* The lookahead symbol.  */
int yychar;


#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
static YYSTYPE yyval_default;
# define YY_INITIAL_VALUE(Value) = Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
      yychar = YYLEX;
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
     `$$ = $1'.

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
/* Line 1792 of yacc.c  */
#line 128 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    { *ret= (yyvsp[(1) - (2)].hint_list); }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 130 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    { *ret= (yyvsp[(1) - (3)].hint_list); }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 132 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    { *ret= NULL; }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 137 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint_list)= NEW_PTN PT_hint_list(thd->mem_root);
            if ((yyval.hint_list) == NULL || (yyval.hint_list)->push_back((yyvsp[(1) - (1)].hint)))
              YYABORT; // OOM
          }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 143 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyvsp[(1) - (2)].hint_list)->push_back((yyvsp[(2) - (2)].hint));
            (yyval.hint_list)= (yyvsp[(1) - (2)].hint_list);
          }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 160 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            int error;
            char *end= const_cast<char *>((yyvsp[(3) - (4)].hint_string).str + (yyvsp[(3) - (4)].hint_string).length);
            longlong n= my_strtoll10((yyvsp[(3) - (4)].hint_string).str, &end, &error);
            if (error != 0 || end != (yyvsp[(3) - (4)].hint_string).str + (yyvsp[(3) - (4)].hint_string).length || n > UINT_MAX32)
            {
              scanner->syntax_warning(ER_THD(thd,
                                             ER_WARN_BAD_MAX_EXECUTION_TIME));
              (yyval.hint)= NULL;
            }
            else
            {
              (yyval.hint)= NEW_PTN PT_hint_max_execution_time(n);
              if ((yyval.hint) == NULL)
                YYABORT; // OOM
            }
          }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 181 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    { (yyval.hint_param_table_list).init(thd->mem_root); }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 187 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint_param_table_list).init(thd->mem_root);
            if ((yyval.hint_param_table_list).push_back((yyvsp[(1) - (1)].hint_param_table)))
              YYABORT; // OOM
          }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 193 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            if ((yyvsp[(1) - (3)].hint_param_table_list).push_back((yyvsp[(3) - (3)].hint_param_table)))
              YYABORT; // OOM
            (yyval.hint_param_table_list)= (yyvsp[(1) - (3)].hint_param_table_list);
          }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 201 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    { (yyval.hint_param_table_list).init(thd->mem_root); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 207 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint_param_table_list).init(thd->mem_root);
            if ((yyval.hint_param_table_list).push_back((yyvsp[(1) - (1)].hint_param_table)))
              YYABORT; // OOM
          }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 213 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            if ((yyvsp[(1) - (3)].hint_param_table_list).push_back((yyvsp[(3) - (3)].hint_param_table)))
              YYABORT; // OOM
            (yyval.hint_param_table_list)= (yyvsp[(1) - (3)].hint_param_table_list);
          }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 221 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    { (yyval.hint_param_index_list).init(thd->mem_root); }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 227 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint_param_index_list).init(thd->mem_root);
            if ((yyval.hint_param_index_list).push_back((yyvsp[(1) - (1)].hint_string)))
              YYABORT; // OOM
          }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 233 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            if ((yyvsp[(1) - (3)].hint_param_index_list).push_back((yyvsp[(3) - (3)].hint_string)))
              YYABORT; // OOM
            (yyval.hint_param_index_list)= (yyvsp[(1) - (3)].hint_param_index_list);
          }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 246 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint_param_table).table= (yyvsp[(1) - (1)].hint_string);
            (yyval.hint_param_table).opt_query_block= NULL_CSTR;
          }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 254 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint_param_table).table= (yyvsp[(1) - (2)].hint_string);
            (yyval.hint_param_table).opt_query_block= (yyvsp[(2) - (2)].hint_string);
          }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 263 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint_param_table).table= (yyvsp[(2) - (2)].hint_string);
            (yyval.hint_param_table).opt_query_block= (yyvsp[(1) - (2)].hint_string);
          }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 270 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    { (yyval.hint_string)= NULL_CSTR; }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 276 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint)= NEW_PTN PT_qb_level_hint((yyvsp[(3) - (5)].hint_string), TRUE, SEMIJOIN_HINT_ENUM, (yyvsp[(4) - (5)].ulong_num));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 283 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint)= NEW_PTN PT_qb_level_hint((yyvsp[(3) - (5)].hint_string), FALSE, SEMIJOIN_HINT_ENUM, (yyvsp[(4) - (5)].ulong_num));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 290 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint)= NEW_PTN PT_qb_level_hint((yyvsp[(3) - (5)].hint_string), TRUE, SUBQUERY_HINT_ENUM, (yyvsp[(4) - (5)].ulong_num));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 297 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint)= NEW_PTN PT_qb_level_hint(NULL_CSTR, TRUE, JOIN_PREFIX_HINT_ENUM, (yyvsp[(3) - (4)].hint_param_table_list));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 304 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint)= NEW_PTN PT_qb_level_hint((yyvsp[(3) - (5)].hint_string), TRUE, JOIN_PREFIX_HINT_ENUM, (yyvsp[(4) - (5)].hint_param_table_list));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 311 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint)= NEW_PTN PT_qb_level_hint(NULL_CSTR, TRUE, JOIN_SUFFIX_HINT_ENUM, (yyvsp[(3) - (4)].hint_param_table_list));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 318 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint)= NEW_PTN PT_qb_level_hint((yyvsp[(3) - (5)].hint_string), TRUE, JOIN_SUFFIX_HINT_ENUM, (yyvsp[(4) - (5)].hint_param_table_list));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 325 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint)= NEW_PTN PT_qb_level_hint(NULL_CSTR, TRUE, JOIN_ORDER_HINT_ENUM, (yyvsp[(3) - (4)].hint_param_table_list));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 332 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint)= NEW_PTN PT_qb_level_hint((yyvsp[(3) - (5)].hint_string), TRUE, JOIN_ORDER_HINT_ENUM, (yyvsp[(4) - (5)].hint_param_table_list));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 339 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint)= NEW_PTN PT_qb_level_hint((yyvsp[(3) - (4)].hint_string), TRUE, JOIN_FIXED_ORDER_HINT_ENUM, 0);
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 347 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    { (yyval.ulong_num)= 0; }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 349 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.ulong_num)= (yyvsp[(1) - (1)].ulong_num);
          }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 353 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.ulong_num)= (yyvsp[(1) - (3)].ulong_num) | (yyvsp[(3) - (3)].ulong_num);
          }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 359 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    { (yyval.ulong_num)= OPTIMIZER_SWITCH_FIRSTMATCH; }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 360 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    { (yyval.ulong_num)= OPTIMIZER_SWITCH_LOOSE_SCAN; }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 361 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    { (yyval.ulong_num)= OPTIMIZER_SWITCH_MATERIALIZATION; }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 362 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    { (yyval.ulong_num)= OPTIMIZER_SWITCH_DUPSWEEDOUT; }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 366 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    { (yyval.ulong_num)=
                                   Item_exists_subselect::EXEC_MATERIALIZATION; }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 368 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    { (yyval.ulong_num)= Item_exists_subselect::EXEC_EXISTS; }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 374 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint)= NEW_PTN PT_table_level_hint(NULL_CSTR, (yyvsp[(3) - (4)].hint_param_table_list), TRUE, (yyvsp[(1) - (4)].hint_type));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 381 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint)= NEW_PTN PT_table_level_hint((yyvsp[(3) - (5)].hint_string), (yyvsp[(4) - (5)].hint_param_table_list), TRUE, (yyvsp[(1) - (5)].hint_type));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 387 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint)= NEW_PTN PT_table_level_hint(NULL_CSTR, (yyvsp[(3) - (4)].hint_param_table_list), FALSE, (yyvsp[(1) - (4)].hint_type));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 394 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint)= NEW_PTN PT_table_level_hint((yyvsp[(3) - (5)].hint_string), (yyvsp[(4) - (5)].hint_param_table_list), FALSE, (yyvsp[(1) - (5)].hint_type));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 404 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint)= NEW_PTN PT_key_level_hint((yyvsp[(3) - (5)].hint_param_table), (yyvsp[(4) - (5)].hint_param_index_list), TRUE, (yyvsp[(1) - (5)].hint_type));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 411 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint)= NEW_PTN PT_key_level_hint((yyvsp[(3) - (5)].hint_param_table), (yyvsp[(4) - (5)].hint_param_index_list), FALSE, (yyvsp[(1) - (5)].hint_type));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 420 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint_type)= BKA_HINT_ENUM;
          }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 424 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint_type)= BNL_HINT_ENUM;
          }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 428 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint_type)= DERIVED_MERGE_HINT_ENUM;
          }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 435 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint_type)= BKA_HINT_ENUM;
          }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 439 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint_type)= BNL_HINT_ENUM;
          }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 443 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint_type)= DERIVED_MERGE_HINT_ENUM;
          }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 450 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint_type)= MRR_HINT_ENUM;
          }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 454 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint_type)= NO_RANGE_HINT_ENUM;
          }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 458 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint_type)= INDEX_MERGE_HINT_ENUM;
          }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 465 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint_type)= ICP_HINT_ENUM;
          }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 469 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint_type)= MRR_HINT_ENUM;
          }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 473 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint_type)= INDEX_MERGE_HINT_ENUM;
          }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 480 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/mysql-8.0.1-dmr-release-export-10982089_gpl/sql/sql_hints.yy"
    {
            (yyval.hint)= NEW_PTN PT_hint_qb_name((yyvsp[(3) - (4)].hint_string));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
    break;


/* Line 1792 of yacc.c  */
#line 2056 "/export/home2/pb2/build/sb_2-22823765-1490244772.57/dist_GPL/sql/sql_hints.yy.cc"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (thd, scanner, ret, YY_("syntax error"));
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
        yyerror (thd, scanner, ret, yymsgp);
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
		      yytoken, &yylval, thd, scanner, ret);
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
		  yystos[yystate], yyvsp, thd, scanner, ret);
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
  yyerror (thd, scanner, ret, YY_("memory exhausted"));
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
                  yytoken, &yylval, thd, scanner, ret);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, thd, scanner, ret);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


