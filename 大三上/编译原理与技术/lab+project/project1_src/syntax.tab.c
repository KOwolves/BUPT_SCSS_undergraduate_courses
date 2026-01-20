/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "syntax.y"

    #include "lex.yy.c"
    #include "parse_tree.h"
    int exit_code = 0;
    Tree result = NULL;
    void yyerror(const char *s);
    void log_err(char type, size_t line_no, const char *msg);

#line 80 "syntax.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

#include "syntax.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_FLOAT = 5,                      /* FLOAT  */
  YYSYMBOL_CHAR = 6,                       /* CHAR  */
  YYSYMBOL_STRUCT = 7,                     /* STRUCT  */
  YYSYMBOL_RETURN = 8,                     /* RETURN  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_ELSE = 10,                      /* ELSE  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_PLUS = 12,                      /* PLUS  */
  YYSYMBOL_MINUS = 13,                     /* MINUS  */
  YYSYMBOL_MUL = 14,                       /* MUL  */
  YYSYMBOL_DIV = 15,                       /* DIV  */
  YYSYMBOL_AND = 16,                       /* AND  */
  YYSYMBOL_OR = 17,                        /* OR  */
  YYSYMBOL_LT = 18,                        /* LT  */
  YYSYMBOL_LE = 19,                        /* LE  */
  YYSYMBOL_GT = 20,                        /* GT  */
  YYSYMBOL_GE = 21,                        /* GE  */
  YYSYMBOL_NE = 22,                        /* NE  */
  YYSYMBOL_EQ = 23,                        /* EQ  */
  YYSYMBOL_NOT = 24,                       /* NOT  */
  YYSYMBOL_ASSIGN = 25,                    /* ASSIGN  */
  YYSYMBOL_TYPE = 26,                      /* TYPE  */
  YYSYMBOL_LP = 27,                        /* LP  */
  YYSYMBOL_RP = 28,                        /* RP  */
  YYSYMBOL_LB = 29,                        /* LB  */
  YYSYMBOL_RB = 30,                        /* RB  */
  YYSYMBOL_LC = 31,                        /* LC  */
  YYSYMBOL_RC = 32,                        /* RC  */
  YYSYMBOL_SEMI = 33,                      /* SEMI  */
  YYSYMBOL_COMMA = 34,                     /* COMMA  */
  YYSYMBOL_DOT = 35,                       /* DOT  */
  YYSYMBOL_ILLEGAL = 36,                   /* ILLEGAL  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_Program = 38,                   /* Program  */
  YYSYMBOL_ExtDefList = 39,                /* ExtDefList  */
  YYSYMBOL_ExtDef = 40,                    /* ExtDef  */
  YYSYMBOL_ExtDecList = 41,                /* ExtDecList  */
  YYSYMBOL_Specifier = 42,                 /* Specifier  */
  YYSYMBOL_StructSpecifier = 43,           /* StructSpecifier  */
  YYSYMBOL_VarDec = 44,                    /* VarDec  */
  YYSYMBOL_FunDec = 45,                    /* FunDec  */
  YYSYMBOL_VarList = 46,                   /* VarList  */
  YYSYMBOL_ParamDec = 47,                  /* ParamDec  */
  YYSYMBOL_CompSt = 48,                    /* CompSt  */
  YYSYMBOL_StmtList = 49,                  /* StmtList  */
  YYSYMBOL_Stmt = 50,                      /* Stmt  */
  YYSYMBOL_DefList = 51,                   /* DefList  */
  YYSYMBOL_Def = 52,                       /* Def  */
  YYSYMBOL_DecList = 53,                   /* DecList  */
  YYSYMBOL_Dec = 54,                       /* Dec  */
  YYSYMBOL_Exp = 55,                       /* Exp  */
  YYSYMBOL_Args = 56                       /* Args  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   415

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  140

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    29,    29,    33,    37,    40,    45,    49,    54,    57,
      60,    65,    70,    73,    76,    83,    89,    92,    98,   104,
     109,   112,   115,   120,   123,   129,   135,   139,   142,   145,
     149,   152,   157,   160,   167,   176,   183,   188,   192,   195,
     200,   203,   206,   211,   214,   217,   224,   229,   234,   239,
     244,   249,   254,   259,   264,   269,   274,   279,   284,   289,
     294,   298,   302,   308,   313,   316,   319,   325,   330,   333,
     336,   339,   342,   345,   348,   353
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "INT", "FLOAT",
  "CHAR", "STRUCT", "RETURN", "IF", "ELSE", "WHILE", "PLUS", "MINUS",
  "MUL", "DIV", "AND", "OR", "LT", "LE", "GT", "GE", "NE", "EQ", "NOT",
  "ASSIGN", "TYPE", "LP", "RP", "LB", "RB", "LC", "RC", "SEMI", "COMMA",
  "DOT", "ILLEGAL", "$accept", "Program", "ExtDefList", "ExtDef",
  "ExtDecList", "Specifier", "StructSpecifier", "VarDec", "FunDec",
  "VarList", "ParamDec", "CompSt", "StmtList", "Stmt", "DefList", "Def",
  "DecList", "Dec", "Exp", "Args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-61)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      50,    19,   -61,    11,   -61,    50,    22,   -61,    -7,   -61,
     -61,   -61,     0,   -61,    27,   -19,    32,    50,    95,   -61,
     -61,    49,    65,    50,   -61,    16,    41,    50,   -61,   -61,
      65,    44,    61,    45,   -61,   -61,   180,    76,    37,    28,
      66,   -61,   -61,    69,   -61,   -61,    50,   -61,   -20,   -61,
     -61,   -61,   193,    51,    72,   193,   193,   193,   103,   -61,
      85,   151,    68,   -61,   193,   -61,   -61,    16,   -61,    43,
     193,    93,   193,   193,   165,    29,   218,   -61,   -61,   -61,
      50,   -61,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   -61,   117,   338,   -61,
     -61,   -61,   242,    64,   118,   -61,   -61,   266,   290,   -61,
     180,   165,   165,    29,    29,   380,   380,   136,   136,   136,
     136,   136,   136,   362,   314,   -61,   193,   -61,   -61,   -61,
     180,   180,   123,   -61,   -61,   115,   -61,   -61,   180,   -61
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,    12,     0,     2,     4,     0,    13,    15,     1,
       3,     9,    16,     6,     0,    11,     0,    38,     0,     8,
       5,     0,     0,    38,     7,     0,     0,    38,    21,    19,
       0,     0,    23,     0,    16,    10,    27,     0,    44,     0,
      41,    14,    37,    24,    20,    18,     0,    17,    68,    69,
      70,    71,     0,     0,     0,     0,     0,     0,     0,    30,
       0,    27,     0,    43,     0,    40,    39,     0,    22,     0,
       0,     0,     0,     0,    60,    61,     0,    73,    25,    26,
      38,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    29,     0,    45,    42,
      65,    63,    75,     0,     0,    32,    31,     0,     0,    59,
      27,    55,    56,    57,    58,    47,    48,    49,    50,    51,
      52,    53,    54,    46,     0,    67,     0,    64,    62,    72,
       0,     0,     0,    66,    74,    33,    35,    28,     0,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -61,   -61,   122,   -61,   107,     8,   -61,   -16,   -61,    96,
     -61,   130,   -60,    14,   -21,   100,    99,   -61,   -52,    42
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,    14,    25,     7,    15,    16,    31,
      32,    59,    60,    61,    26,    27,    39,    40,    62,   103
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      71,    79,    36,    74,    75,    76,    42,    69,     6,    38,
      21,     9,    98,     6,    43,    22,    70,   102,   104,    34,
     107,   108,     8,    11,    17,    12,    30,    18,    19,    65,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   100,    44,    48,    49,    50,    51,
     132,    38,    37,    33,    30,    13,    55,     1,    95,   110,
      20,    66,    64,    23,    97,   127,    21,    56,    34,    81,
      57,   101,    45,    41,   102,    47,     2,    63,    72,    58,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,   128,    94,   105,    46,    28,    95,    21,    73,
      67,    96,     1,    97,    77,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    78,    94,   129,
     125,     2,    95,    29,   137,   138,   106,    10,    97,    35,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    68,    94,   135,   136,    24,    95,    82,    83,
      84,    85,   139,    97,    48,    49,    50,    51,     1,    52,
      53,    80,    54,     0,    55,    95,    99,     0,   134,     0,
       0,    97,     0,     0,     0,    56,     0,     2,    57,    84,
      85,     0,    23,    48,    49,    50,    51,    58,    52,    53,
       0,    54,     0,    55,    95,     0,    48,    49,    50,    51,
      97,     0,     0,     0,    56,     0,    55,    57,     0,     0,
       0,    23,     0,     0,     0,     0,    58,    56,     0,     0,
      57,     0,     0,     0,     0,     0,     0,     0,     0,    58,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,     0,    94,     0,     0,   109,    95,     0,     0,
       0,     0,     0,    97,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,     0,    94,     0,     0,
       0,    95,     0,     0,     0,     0,   126,    97,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
       0,    94,     0,     0,   130,    95,     0,     0,     0,     0,
       0,    97,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,     0,    94,     0,     0,   131,    95,
       0,     0,     0,     0,     0,    97,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,    94,
       0,     0,     0,    95,   133,     0,     0,     0,     0,    97,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,     0,    94,     0,     0,     0,    95,     0,     0,
       0,     0,     0,    97,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,     0,     0,     0,     0,
       0,    95,    82,    83,    84,    85,     0,    97,    88,    89,
      90,    91,    92,    93,     0,     0,     0,     0,     0,    95,
       0,     0,     0,     0,     0,    97
};

static const yytype_int16 yycheck[] =
{
      52,    61,    23,    55,    56,    57,    27,    27,     0,    25,
      29,     0,    64,     5,    30,    34,    36,    69,    70,     3,
      72,    73,     3,     1,    31,     3,    18,    27,     1,     1,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,     1,     1,     3,     4,     5,     6,
     110,    67,    36,     4,    46,    33,    13,     7,    29,    80,
      33,    33,    25,    31,    35,     1,    29,    24,     3,     1,
      27,    28,    28,    32,   126,    30,    26,     1,    27,    36,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    28,    25,     1,    34,     1,    29,    29,    27,
      34,    33,     7,    35,     1,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    32,    25,     1,
       3,    26,    29,    28,     1,    10,    33,     5,    35,    22,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    46,    25,   130,   131,    16,    29,    12,    13,
      14,    15,   138,    35,     3,     4,     5,     6,     7,     8,
       9,    61,    11,    -1,    13,    29,    67,    -1,   126,    -1,
      -1,    35,    -1,    -1,    -1,    24,    -1,    26,    27,    14,
      15,    -1,    31,     3,     4,     5,     6,    36,     8,     9,
      -1,    11,    -1,    13,    29,    -1,     3,     4,     5,     6,
      35,    -1,    -1,    -1,    24,    -1,    13,    27,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    36,    24,    -1,    -1,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    25,    -1,    -1,    28,    29,    -1,    -1,
      -1,    -1,    -1,    35,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    25,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    34,    35,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    25,    -1,    -1,    28,    29,    -1,    -1,    -1,    -1,
      -1,    35,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    25,    -1,    -1,    28,    29,
      -1,    -1,    -1,    -1,    -1,    35,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    25,
      -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    35,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    35,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    29,    12,    13,    14,    15,    -1,    35,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,    26,    38,    39,    40,    42,    43,     3,     0,
      39,     1,     3,    33,    41,    44,    45,    31,    27,     1,
      33,    29,    34,    31,    48,    42,    51,    52,     1,    28,
      42,    46,    47,     4,     3,    41,    51,    36,    44,    53,
      54,    32,    51,    44,     1,    28,    34,    30,     3,     4,
       5,     6,     8,     9,    11,    13,    24,    27,    36,    48,
      49,    50,    55,     1,    25,     1,    33,    34,    46,    27,
      36,    55,    27,    27,    55,    55,    55,     1,    32,    49,
      52,     1,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    25,    29,    33,    35,    55,    53,
       1,    28,    55,    56,    55,     1,    33,    55,    55,    28,
      51,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,     3,    34,     1,    28,     1,
      28,    28,    49,    30,    56,    50,    50,     1,    10,    50
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    40,    40,    40,
      41,    41,    42,    42,    43,    43,    44,    44,    45,    45,
      45,    45,    46,    46,    47,    48,    49,    49,    49,    50,
      50,    50,    50,    50,    50,    50,    50,    51,    51,    52,
      52,    53,    53,    53,    54,    54,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    56,    56
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     3,     3,     2,
       3,     1,     1,     1,     5,     2,     1,     4,     4,     3,
       4,     3,     3,     1,     2,     4,     2,     0,     5,     2,
       1,     3,     3,     5,     7,     5,     2,     2,     0,     3,
       3,     1,     3,     2,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     4,     3,     4,     3,     4,     3,     1,     1,
       1,     1,     4,     2,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* Program: ExtDefList  */
#line 29 "syntax.y"
                    {
        (yyval.node) = new_node("Program", (yyvsp[0].node)->line_no, NULL, (yyvsp[0].node), NULL);
        result = (yyval.node);
    }
#line 1266 "syntax.tab.c"
    break;

  case 3: /* ExtDefList: ExtDef ExtDefList  */
#line 33 "syntax.y"
                              {
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("ExtDefList", (yyvsp[-1].node)->line_no, NULL, (yyvsp[-1].node), NULL);
    }
#line 1275 "syntax.tab.c"
    break;

  case 4: /* ExtDefList: %empty  */
#line 37 "syntax.y"
                {
        (yyval.node) = new_node(NULL, 0, NULL, NULL, NULL);
    }
#line 1283 "syntax.tab.c"
    break;

  case 5: /* ExtDef: Specifier ExtDecList SEMI  */
#line 40 "syntax.y"
                                  {
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("ExtDef", (yyvsp[-2].node)->line_no, NULL, (yyvsp[-2].node), NULL);
    }
#line 1293 "syntax.tab.c"
    break;

  case 6: /* ExtDef: Specifier SEMI  */
#line 45 "syntax.y"
                     {
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("ExtDef", (yyvsp[-1].node)->line_no, NULL, (yyvsp[-1].node), NULL);
    }
#line 1302 "syntax.tab.c"
    break;

  case 7: /* ExtDef: Specifier FunDec CompSt  */
#line 49 "syntax.y"
                              {
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node); 
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("ExtDef", (yyvsp[-2].node)->line_no, NULL, (yyvsp[-2].node), NULL);
    }
#line 1312 "syntax.tab.c"
    break;

  case 8: /* ExtDef: Specifier ExtDecList error  */
#line 54 "syntax.y"
                                 {
        log_err(MISSING_SEMI, (yyvsp[-1].node)->line_no, "missing semicolon");
    }
#line 1320 "syntax.tab.c"
    break;

  case 9: /* ExtDef: Specifier error  */
#line 57 "syntax.y"
                      {
        log_err(MISSING_SEMI, (yyvsp[-1].node)->line_no, "missing semicolon");
    }
#line 1328 "syntax.tab.c"
    break;

  case 10: /* ExtDecList: VarDec COMMA ExtDecList  */
#line 60 "syntax.y"
                                    {
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node); 
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("ExtDecList", (yyvsp[-2].node)->line_no, NULL, (yyvsp[-2].node), NULL);
    }
#line 1338 "syntax.tab.c"
    break;

  case 11: /* ExtDecList: VarDec  */
#line 65 "syntax.y"
             {
        (yyval.node) = new_node("ExtDecList", (yyvsp[0].node)->line_no, NULL, (yyvsp[0].node), NULL);
    }
#line 1346 "syntax.tab.c"
    break;

  case 12: /* Specifier: TYPE  */
#line 70 "syntax.y"
                {
        (yyval.node) = new_node("Specifier", (yyvsp[0].node)->line_no, NULL, (yyvsp[0].node), NULL);
    }
#line 1354 "syntax.tab.c"
    break;

  case 13: /* Specifier: StructSpecifier  */
#line 73 "syntax.y"
                      {
        (yyval.node) = new_node("Specifier", (yyvsp[0].node)->line_no, NULL, (yyvsp[0].node), NULL);
    }
#line 1362 "syntax.tab.c"
    break;

  case 14: /* StructSpecifier: STRUCT ID LC DefList RC  */
#line 76 "syntax.y"
                                         {
        (yyvsp[-4].node)->sibling = (yyvsp[-3].node); 
        (yyvsp[-3].node)->sibling = (yyvsp[-2].node);
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("StructSpecifier", (yyvsp[-4].node)->line_no, NULL, (yyvsp[-4].node), NULL);
    }
#line 1374 "syntax.tab.c"
    break;

  case 15: /* StructSpecifier: STRUCT ID  */
#line 83 "syntax.y"
                {
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("StructSpecifier", (yyvsp[-1].node)->line_no, NULL, (yyvsp[-1].node), NULL);
    }
#line 1383 "syntax.tab.c"
    break;

  case 16: /* VarDec: ID  */
#line 89 "syntax.y"
           {
        (yyval.node) = new_node("VarDec", (yyvsp[0].node)->line_no, NULL, (yyvsp[0].node), NULL);
    }
#line 1391 "syntax.tab.c"
    break;

  case 17: /* VarDec: VarDec LB INT RB  */
#line 92 "syntax.y"
                       {
        (yyvsp[-3].node)->sibling = (yyvsp[-2].node);
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("VarDec", (yyvsp[-3].node)->line_no, NULL, (yyvsp[-3].node), NULL);
    }
#line 1402 "syntax.tab.c"
    break;

  case 18: /* FunDec: ID LP VarList RP  */
#line 98 "syntax.y"
                         {
        (yyvsp[-3].node)->sibling = (yyvsp[-2].node);
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("FunDec", (yyvsp[-3].node)->line_no, NULL, (yyvsp[-3].node), NULL);
    }
#line 1413 "syntax.tab.c"
    break;

  case 19: /* FunDec: ID LP RP  */
#line 104 "syntax.y"
               {
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("FunDec", (yyvsp[-2].node)->line_no, NULL, (yyvsp[-2].node), NULL);
    }
#line 1423 "syntax.tab.c"
    break;

  case 20: /* FunDec: ID LP VarList error  */
#line 109 "syntax.y"
                          {
        log_err(MISSING_CLOSING, (yyvsp[-1].node)->line_no, "missing closing symbol");
    }
#line 1431 "syntax.tab.c"
    break;

  case 21: /* FunDec: ID LP error  */
#line 112 "syntax.y"
                  {
        log_err(MISSING_CLOSING, (yyvsp[-1].node)->line_no, "missing closing symbol");
    }
#line 1439 "syntax.tab.c"
    break;

  case 22: /* VarList: ParamDec COMMA VarList  */
#line 115 "syntax.y"
                                {
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("VarList", (yyvsp[-2].node)->line_no, NULL, (yyvsp[-2].node), NULL);
    }
#line 1449 "syntax.tab.c"
    break;

  case 23: /* VarList: ParamDec  */
#line 120 "syntax.y"
               {
        (yyval.node) = new_node("VarList", (yyvsp[0].node)->line_no, NULL, (yyvsp[0].node), NULL);
    }
#line 1457 "syntax.tab.c"
    break;

  case 24: /* ParamDec: Specifier VarDec  */
#line 123 "syntax.y"
                           {
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("ParamDec", (yyvsp[-1].node)->line_no, NULL, (yyvsp[-1].node), NULL);
    }
#line 1466 "syntax.tab.c"
    break;

  case 25: /* CompSt: LC DefList StmtList RC  */
#line 129 "syntax.y"
                               {
        (yyvsp[-3].node)->sibling = (yyvsp[-2].node);
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("CompSt", (yyvsp[-3].node)->line_no, NULL, (yyvsp[-3].node), NULL);
    }
#line 1477 "syntax.tab.c"
    break;

  case 26: /* StmtList: Stmt StmtList  */
#line 135 "syntax.y"
                        {
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("StmtList", (yyvsp[-1].node)->line_no, NULL, (yyvsp[-1].node), NULL);
    }
#line 1486 "syntax.tab.c"
    break;

  case 27: /* StmtList: %empty  */
#line 139 "syntax.y"
                {
        (yyval.node) = new_node(NULL, 0, NULL, NULL, NULL);
    }
#line 1494 "syntax.tab.c"
    break;

  case 28: /* StmtList: Stmt Def DefList StmtList error  */
#line 142 "syntax.y"
                                      {
        log_err(DEF_AFTER_STMT, (yyvsp[-3].node)->line_no, "def after stmt");
    }
#line 1502 "syntax.tab.c"
    break;

  case 29: /* Stmt: Exp SEMI  */
#line 145 "syntax.y"
               {
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("Stmt", (yyvsp[-1].node)->line_no, NULL, (yyvsp[-1].node), NULL);
    }
#line 1511 "syntax.tab.c"
    break;

  case 30: /* Stmt: CompSt  */
#line 149 "syntax.y"
             {
        (yyval.node) = new_node("Stmt", (yyvsp[0].node)->line_no, NULL, (yyvsp[0].node), NULL);
    }
#line 1519 "syntax.tab.c"
    break;

  case 31: /* Stmt: RETURN Exp SEMI  */
#line 152 "syntax.y"
                      {
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("Stmt", (yyvsp[-2].node)->line_no, NULL, (yyvsp[-2].node), NULL);
    }
#line 1529 "syntax.tab.c"
    break;

  case 32: /* Stmt: RETURN Exp error  */
#line 157 "syntax.y"
                       {
        log_err(MISSING_SEMI, (yyvsp[-1].node)->line_no, "missing semicolon");
    }
#line 1537 "syntax.tab.c"
    break;

  case 33: /* Stmt: IF LP Exp RP Stmt  */
#line 160 "syntax.y"
                                   {
        (yyvsp[-4].node)->sibling = (yyvsp[-3].node);
        (yyvsp[-3].node)->sibling = (yyvsp[-2].node);
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("Stmt", (yyvsp[-4].node)->line_no, NULL, (yyvsp[-4].node), NULL);
    }
#line 1549 "syntax.tab.c"
    break;

  case 34: /* Stmt: IF LP Exp RP Stmt ELSE Stmt  */
#line 167 "syntax.y"
                                  {
        (yyvsp[-6].node)->sibling = (yyvsp[-5].node);
        (yyvsp[-5].node)->sibling = (yyvsp[-4].node);
        (yyvsp[-4].node)->sibling = (yyvsp[-3].node);
        (yyvsp[-3].node)->sibling = (yyvsp[-2].node);
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("Stmt", (yyvsp[-6].node)->line_no, NULL, (yyvsp[-6].node), NULL);
    }
#line 1563 "syntax.tab.c"
    break;

  case 35: /* Stmt: WHILE LP Exp RP Stmt  */
#line 176 "syntax.y"
                           {
        (yyvsp[-4].node)->sibling = (yyvsp[-3].node);
        (yyvsp[-3].node)->sibling = (yyvsp[-2].node);
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("Stmt", (yyvsp[-4].node)->line_no, NULL, (yyvsp[-4].node), NULL);
    }
#line 1575 "syntax.tab.c"
    break;

  case 36: /* Stmt: Exp error  */
#line 183 "syntax.y"
                {
        log_err(MISSING_SEMI, (yyvsp[-1].node)->line_no, "missing semicolon");
    }
#line 1583 "syntax.tab.c"
    break;

  case 37: /* DefList: Def DefList  */
#line 188 "syntax.y"
                     {
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("DefList", (yyvsp[-1].node)->line_no, NULL, (yyvsp[-1].node), NULL);
    }
#line 1592 "syntax.tab.c"
    break;

  case 38: /* DefList: %empty  */
#line 192 "syntax.y"
                {
        (yyval.node) = new_node(NULL, 0, NULL, NULL, NULL);
    }
#line 1600 "syntax.tab.c"
    break;

  case 39: /* Def: Specifier DecList SEMI  */
#line 195 "syntax.y"
                            {
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("Def", (yyvsp[-2].node)->line_no, NULL, (yyvsp[-2].node), NULL);
    }
#line 1610 "syntax.tab.c"
    break;

  case 40: /* Def: Specifier DecList error  */
#line 200 "syntax.y"
                              {
        log_err(MISSING_SEMI, (yyvsp[-1].node)->line_no, "missing semicolon");
    }
#line 1618 "syntax.tab.c"
    break;

  case 41: /* DecList: Dec  */
#line 203 "syntax.y"
             {
        (yyval.node) = new_node("DecList", (yyvsp[0].node)->line_no, NULL, (yyvsp[0].node), NULL);
    }
#line 1626 "syntax.tab.c"
    break;

  case 42: /* DecList: Dec COMMA DecList  */
#line 206 "syntax.y"
                        {
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("DecList", (yyvsp[-2].node)->line_no, NULL, (yyvsp[-2].node), NULL);
    }
#line 1636 "syntax.tab.c"
    break;

  case 43: /* DecList: ILLEGAL error  */
#line 211 "syntax.y"
                    {
        log_err(LEXEME_ERROR, (yyvsp[-1].node)->line_no, (yyvsp[-1].node)->property);
    }
#line 1644 "syntax.tab.c"
    break;

  case 44: /* Dec: VarDec  */
#line 214 "syntax.y"
            {
        (yyval.node) = new_node("Dec", (yyvsp[0].node)->line_no, NULL, (yyvsp[0].node), NULL);
    }
#line 1652 "syntax.tab.c"
    break;

  case 45: /* Dec: VarDec ASSIGN Exp  */
#line 217 "syntax.y"
                        {
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("Dec", (yyvsp[-2].node)->line_no, NULL, (yyvsp[-2].node), NULL);
    }
#line 1662 "syntax.tab.c"
    break;

  case 46: /* Exp: Exp ASSIGN Exp  */
#line 224 "syntax.y"
                    {
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("Exp", (yyvsp[-2].node)->line_no, NULL, (yyvsp[-2].node), NULL);
    }
#line 1672 "syntax.tab.c"
    break;

  case 47: /* Exp: Exp AND Exp  */
#line 229 "syntax.y"
                  {
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("Exp", (yyvsp[-2].node)->line_no, NULL, (yyvsp[-2].node), NULL);
    }
#line 1682 "syntax.tab.c"
    break;

  case 48: /* Exp: Exp OR Exp  */
#line 234 "syntax.y"
                 {
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("Exp", (yyvsp[-2].node)->line_no, NULL, (yyvsp[-2].node), NULL);
    }
#line 1692 "syntax.tab.c"
    break;

  case 49: /* Exp: Exp LT Exp  */
#line 239 "syntax.y"
                 {
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("Exp", (yyvsp[-2].node)->line_no, NULL, (yyvsp[-2].node), NULL);
    }
#line 1702 "syntax.tab.c"
    break;

  case 50: /* Exp: Exp LE Exp  */
#line 244 "syntax.y"
                 {
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("Exp", (yyvsp[-2].node)->line_no, NULL, (yyvsp[-2].node), NULL);
    }
#line 1712 "syntax.tab.c"
    break;

  case 51: /* Exp: Exp GT Exp  */
#line 249 "syntax.y"
                 {
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("Exp", (yyvsp[-2].node)->line_no, NULL, (yyvsp[-2].node), NULL);
    }
#line 1722 "syntax.tab.c"
    break;

  case 52: /* Exp: Exp GE Exp  */
#line 254 "syntax.y"
                 {
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("Exp", (yyvsp[-2].node)->line_no, NULL, (yyvsp[-2].node), NULL);
    }
#line 1732 "syntax.tab.c"
    break;

  case 53: /* Exp: Exp NE Exp  */
#line 259 "syntax.y"
                 {
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("Exp", (yyvsp[-2].node)->line_no, NULL, (yyvsp[-2].node), NULL);
    }
#line 1742 "syntax.tab.c"
    break;

  case 54: /* Exp: Exp EQ Exp  */
#line 264 "syntax.y"
                 {
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("Exp", (yyvsp[-2].node)->line_no, NULL, (yyvsp[-2].node), NULL);
    }
#line 1752 "syntax.tab.c"
    break;

  case 55: /* Exp: Exp PLUS Exp  */
#line 269 "syntax.y"
                   {
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("Exp", (yyvsp[-2].node)->line_no, NULL, (yyvsp[-2].node), NULL);
    }
#line 1762 "syntax.tab.c"
    break;

  case 56: /* Exp: Exp MINUS Exp  */
#line 274 "syntax.y"
                    {
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("Exp", (yyvsp[-2].node)->line_no, NULL, (yyvsp[-2].node), NULL);
    }
#line 1772 "syntax.tab.c"
    break;

  case 57: /* Exp: Exp MUL Exp  */
#line 279 "syntax.y"
                  {
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("Exp", (yyvsp[-2].node)->line_no, NULL, (yyvsp[-2].node), NULL);
    }
#line 1782 "syntax.tab.c"
    break;

  case 58: /* Exp: Exp DIV Exp  */
#line 284 "syntax.y"
                  {
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("Exp", (yyvsp[-2].node)->line_no, NULL, (yyvsp[-2].node), NULL);
    }
#line 1792 "syntax.tab.c"
    break;

  case 59: /* Exp: LP Exp RP  */
#line 289 "syntax.y"
                {
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("Exp", (yyvsp[-2].node)->line_no, NULL, (yyvsp[-2].node), NULL);
    }
#line 1802 "syntax.tab.c"
    break;

  case 60: /* Exp: MINUS Exp  */
#line 294 "syntax.y"
                {
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("Exp", (yyvsp[-1].node)->line_no, NULL, (yyvsp[-1].node), NULL);
    }
#line 1811 "syntax.tab.c"
    break;

  case 61: /* Exp: NOT Exp  */
#line 298 "syntax.y"
              {
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("Exp", (yyvsp[-1].node)->line_no, NULL, (yyvsp[-1].node), NULL);
    }
#line 1820 "syntax.tab.c"
    break;

  case 62: /* Exp: ID LP Args RP  */
#line 302 "syntax.y"
                    {
        (yyvsp[-3].node)->sibling = (yyvsp[-2].node);
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("Exp", (yyvsp[-3].node)->line_no, NULL, (yyvsp[-3].node), NULL);
    }
#line 1831 "syntax.tab.c"
    break;

  case 63: /* Exp: ID LP RP  */
#line 308 "syntax.y"
               {
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("Exp", (yyvsp[-2].node)->line_no, NULL, (yyvsp[-2].node), NULL);
    }
#line 1841 "syntax.tab.c"
    break;

  case 64: /* Exp: ID LP Args error  */
#line 313 "syntax.y"
                       {
        log_err(MISSING_CLOSING, (yyvsp[-1].node)->line_no, "missing closing symbol");
    }
#line 1849 "syntax.tab.c"
    break;

  case 65: /* Exp: ID LP error  */
#line 316 "syntax.y"
                  {
        log_err(MISSING_CLOSING, (yyvsp[-1].node)->line_no, "missing closing symbol");
    }
#line 1857 "syntax.tab.c"
    break;

  case 66: /* Exp: Exp LB Exp RB  */
#line 319 "syntax.y"
                    {
        (yyvsp[-3].node)->sibling = (yyvsp[-2].node);
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("Exp", (yyvsp[-3].node)->line_no, NULL, (yyvsp[-3].node), NULL);
    }
#line 1868 "syntax.tab.c"
    break;

  case 67: /* Exp: Exp DOT ID  */
#line 325 "syntax.y"
                 {
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("Exp", (yyvsp[-2].node)->line_no, NULL, (yyvsp[-2].node), NULL);
    }
#line 1878 "syntax.tab.c"
    break;

  case 68: /* Exp: ID  */
#line 330 "syntax.y"
         {
        (yyval.node) = new_node("Exp", (yyvsp[0].node)->line_no, NULL, (yyvsp[0].node), NULL);
    }
#line 1886 "syntax.tab.c"
    break;

  case 69: /* Exp: INT  */
#line 333 "syntax.y"
          {
        (yyval.node) = new_node("Exp", (yyvsp[0].node)->line_no, NULL, (yyvsp[0].node), NULL);
    }
#line 1894 "syntax.tab.c"
    break;

  case 70: /* Exp: FLOAT  */
#line 336 "syntax.y"
            {
        (yyval.node) = new_node("Exp", (yyvsp[0].node)->line_no, NULL, (yyvsp[0].node), NULL);
    }
#line 1902 "syntax.tab.c"
    break;

  case 71: /* Exp: CHAR  */
#line 339 "syntax.y"
           {
        (yyval.node) = new_node("Exp", (yyvsp[0].node)->line_no, NULL, (yyvsp[0].node), NULL);
    }
#line 1910 "syntax.tab.c"
    break;

  case 72: /* Exp: ID ILLEGAL Exp error  */
#line 342 "syntax.y"
                           {
        log_err(ILLEGAL_OP, (yyvsp[-2].node)->line_no, "illegal operator");
    }
#line 1918 "syntax.tab.c"
    break;

  case 73: /* Exp: ILLEGAL error  */
#line 345 "syntax.y"
                    {
        log_err(LEXEME_ERROR, (yyvsp[-1].node)->line_no, (yyvsp[-1].node)->property);
    }
#line 1926 "syntax.tab.c"
    break;

  case 74: /* Args: Exp COMMA Args  */
#line 348 "syntax.y"
                     {
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node);
        (yyvsp[-1].node)->sibling = (yyvsp[0].node);
        (yyval.node) = new_node("Args", (yyvsp[-2].node)->line_no, NULL, (yyvsp[-2].node), NULL);
    }
#line 1936 "syntax.tab.c"
    break;

  case 75: /* Args: Exp  */
#line 353 "syntax.y"
          {
        (yyval.node) = new_node("Args", (yyvsp[0].node)->line_no, NULL, (yyvsp[0].node), NULL);
    }
#line 1944 "syntax.tab.c"
    break;


#line 1948 "syntax.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 356 "syntax.y"


void yyerror(const char *s) { /* fprintf(stderr, "%s\n", s); */ }

void log_err(char type, size_t line_no, const char *msg) {
    fprintf(stdout, "Error type %c at Line %lu: %s\n", type, line_no, msg);
    exit_code = 1;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        exit(1);
    }
    FILE *fin = fopen(argv[1], "rb"), *fout = stdout;
    if (!fin) {
        exit(1);
    }
    size_t len = strlen(argv[1]);
    if (!strcmp(argv[1] + len - 4, ".bpl")) {
        strcpy(argv[1] + len - 3, "out");
        fout = freopen(argv[1], "wb", stdout);
    }
    if (!fout) {
        exit(1);
    }
    yyin = fin;
    yyparse();
    if (!exit_code) {
        print_tree(stdout, result, 0);
    }
    empty_tree(result);
    if (result) {
        free(result);
        result = NULL;
    }
    return exit_code;
}
