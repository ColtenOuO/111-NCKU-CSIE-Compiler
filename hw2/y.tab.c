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
#line 4 "compiler.y"

    #include "compiler_common.h"  //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;
    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    int yylex_destroy ();
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    typedef struct Node
    {
        char name[50];
        char type[50];
        int address;
        int lineno;
        int mut;
        char element_type[50];
    } NODE;

    /* Symbol table function - you can add new functions if needed. */
    /* parameters and return type can be changed */
    static void create_symbol();
    static int insert_symbol(char* name, char* type, char* element_type);
    static NODE lookup_symbol(char* name, int flag);
    static void dump_symbol(int scope);

    /* Global variables */
    bool HAS_ERROR = false;

    int cs_idx = -1;

    int table_len[50] = {}; 
    NODE table[50][50];
    int address = 0;  
    int type = 0;
    char now_type[10] = "none";
    char now_op[10] = "none";
    char now_id[10] = "none";
    NODE *global_node , node_saving;

    char variable_name[20] = {};
    int variable_address = 0;
    int block_create = 0;
    bool func_first = 1;

#line 126 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    LET = 258,                     /* LET  */
    MUT = 259,                     /* MUT  */
    NEWLINE = 260,                 /* NEWLINE  */
    INT = 261,                     /* INT  */
    FLOAT = 262,                   /* FLOAT  */
    BOOL = 263,                    /* BOOL  */
    STR = 264,                     /* STR  */
    TRUE = 265,                    /* TRUE  */
    FALSE = 266,                   /* FALSE  */
    GEQ = 267,                     /* GEQ  */
    LEQ = 268,                     /* LEQ  */
    EQL = 269,                     /* EQL  */
    NEQ = 270,                     /* NEQ  */
    LOR = 271,                     /* LOR  */
    LAND = 272,                    /* LAND  */
    ADD_ASSIGN = 273,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 274,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 275,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 276,              /* DIV_ASSIGN  */
    REM_ASSIGN = 277,              /* REM_ASSIGN  */
    IF = 278,                      /* IF  */
    ELSE = 279,                    /* ELSE  */
    FOR = 280,                     /* FOR  */
    WHILE = 281,                   /* WHILE  */
    LOOP = 282,                    /* LOOP  */
    PRINT = 283,                   /* PRINT  */
    PRINTLN = 284,                 /* PRINTLN  */
    FUNC = 285,                    /* FUNC  */
    RETURN = 286,                  /* RETURN  */
    BREAK = 287,                   /* BREAK  */
    ID = 288,                      /* ID  */
    ARROW = 289,                   /* ARROW  */
    AS = 290,                      /* AS  */
    IN = 291,                      /* IN  */
    DOTDOT = 292,                  /* DOTDOT  */
    RSHIFT = 293,                  /* RSHIFT  */
    LSHIFT = 294,                  /* LSHIFT  */
    INT_LIT = 295,                 /* INT_LIT  */
    FLOAT_LIT = 296,               /* FLOAT_LIT  */
    STRING_LIT = 297               /* STRING_LIT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define LET 258
#define MUT 259
#define NEWLINE 260
#define INT 261
#define FLOAT 262
#define BOOL 263
#define STR 264
#define TRUE 265
#define FALSE 266
#define GEQ 267
#define LEQ 268
#define EQL 269
#define NEQ 270
#define LOR 271
#define LAND 272
#define ADD_ASSIGN 273
#define SUB_ASSIGN 274
#define MUL_ASSIGN 275
#define DIV_ASSIGN 276
#define REM_ASSIGN 277
#define IF 278
#define ELSE 279
#define FOR 280
#define WHILE 281
#define LOOP 282
#define PRINT 283
#define PRINTLN 284
#define FUNC 285
#define RETURN 286
#define BREAK 287
#define ID 288
#define ARROW 289
#define AS 290
#define IN 291
#define DOTDOT 292
#define RSHIFT 293
#define LSHIFT 294
#define INT_LIT 295
#define FLOAT_LIT 296
#define STRING_LIT 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 65 "compiler.y"

    int i_val;
    float f_val;
    char *s_val;
    /* ... */

#line 270 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LET = 3,                        /* LET  */
  YYSYMBOL_MUT = 4,                        /* MUT  */
  YYSYMBOL_NEWLINE = 5,                    /* NEWLINE  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_FLOAT = 7,                      /* FLOAT  */
  YYSYMBOL_BOOL = 8,                       /* BOOL  */
  YYSYMBOL_STR = 9,                        /* STR  */
  YYSYMBOL_TRUE = 10,                      /* TRUE  */
  YYSYMBOL_FALSE = 11,                     /* FALSE  */
  YYSYMBOL_GEQ = 12,                       /* GEQ  */
  YYSYMBOL_LEQ = 13,                       /* LEQ  */
  YYSYMBOL_EQL = 14,                       /* EQL  */
  YYSYMBOL_NEQ = 15,                       /* NEQ  */
  YYSYMBOL_LOR = 16,                       /* LOR  */
  YYSYMBOL_LAND = 17,                      /* LAND  */
  YYSYMBOL_ADD_ASSIGN = 18,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 19,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 20,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 21,                /* DIV_ASSIGN  */
  YYSYMBOL_REM_ASSIGN = 22,                /* REM_ASSIGN  */
  YYSYMBOL_IF = 23,                        /* IF  */
  YYSYMBOL_ELSE = 24,                      /* ELSE  */
  YYSYMBOL_FOR = 25,                       /* FOR  */
  YYSYMBOL_WHILE = 26,                     /* WHILE  */
  YYSYMBOL_LOOP = 27,                      /* LOOP  */
  YYSYMBOL_PRINT = 28,                     /* PRINT  */
  YYSYMBOL_PRINTLN = 29,                   /* PRINTLN  */
  YYSYMBOL_FUNC = 30,                      /* FUNC  */
  YYSYMBOL_RETURN = 31,                    /* RETURN  */
  YYSYMBOL_BREAK = 32,                     /* BREAK  */
  YYSYMBOL_ID = 33,                        /* ID  */
  YYSYMBOL_ARROW = 34,                     /* ARROW  */
  YYSYMBOL_AS = 35,                        /* AS  */
  YYSYMBOL_IN = 36,                        /* IN  */
  YYSYMBOL_DOTDOT = 37,                    /* DOTDOT  */
  YYSYMBOL_RSHIFT = 38,                    /* RSHIFT  */
  YYSYMBOL_LSHIFT = 39,                    /* LSHIFT  */
  YYSYMBOL_INT_LIT = 40,                   /* INT_LIT  */
  YYSYMBOL_FLOAT_LIT = 41,                 /* FLOAT_LIT  */
  YYSYMBOL_STRING_LIT = 42,                /* STRING_LIT  */
  YYSYMBOL_43_ = 43,                       /* '('  */
  YYSYMBOL_44_ = 44,                       /* ')'  */
  YYSYMBOL_45_ = 45,                       /* '>'  */
  YYSYMBOL_46_ = 46,                       /* '<'  */
  YYSYMBOL_47_ = 47,                       /* '+'  */
  YYSYMBOL_48_ = 48,                       /* '-'  */
  YYSYMBOL_49_ = 49,                       /* '*'  */
  YYSYMBOL_50_ = 50,                       /* '/'  */
  YYSYMBOL_51_ = 51,                       /* '%'  */
  YYSYMBOL_52_ = 52,                       /* ':'  */
  YYSYMBOL_53_ = 53,                       /* ','  */
  YYSYMBOL_54_ = 54,                       /* ';'  */
  YYSYMBOL_55_ = 55,                       /* '"'  */
  YYSYMBOL_56_ = 56,                       /* '['  */
  YYSYMBOL_57_ = 57,                       /* ']'  */
  YYSYMBOL_58_ = 58,                       /* '='  */
  YYSYMBOL_59_ = 59,                       /* '{'  */
  YYSYMBOL_60_ = 60,                       /* '}'  */
  YYSYMBOL_61_ = 61,                       /* '!'  */
  YYSYMBOL_62_ = 62,                       /* '&'  */
  YYSYMBOL_YYACCEPT = 63,                  /* $accept  */
  YYSYMBOL_Program = 64,                   /* Program  */
  YYSYMBOL_GlobalStatementList = 65,       /* GlobalStatementList  */
  YYSYMBOL_GlobalStatement = 66,           /* GlobalStatement  */
  YYSYMBOL_Func_opt = 67,                  /* Func_opt  */
  YYSYMBOL_return_stmt = 68,               /* return_stmt  */
  YYSYMBOL_FunctionDeclStmt = 69,          /* FunctionDeclStmt  */
  YYSYMBOL_70_1 = 70,                      /* $@1  */
  YYSYMBOL_71_2 = 71,                      /* $@2  */
  YYSYMBOL_break_stmt = 72,                /* break_stmt  */
  YYSYMBOL_array_stmt = 73,                /* array_stmt  */
  YYSYMBOL_74_3 = 74,                      /* $@3  */
  YYSYMBOL_array_stmt_again = 75,          /* array_stmt_again  */
  YYSYMBOL_new_element = 76,               /* new_element  */
  YYSYMBOL_Simpile_stmt = 77,              /* Simpile_stmt  */
  YYSYMBOL_if_stmt = 78,                   /* if_stmt  */
  YYSYMBOL_while_stmt = 79,                /* while_stmt  */
  YYSYMBOL_for_stmt = 80,                  /* for_stmt  */
  YYSYMBOL_81_4 = 81,                      /* $@4  */
  YYSYMBOL_for_block = 82,                 /* for_block  */
  YYSYMBOL_83_5 = 83,                      /* $@5  */
  YYSYMBOL_expr = 84,                      /* expr  */
  YYSYMBOL_term = 85,                      /* term  */
  YYSYMBOL_factor = 86,                    /* factor  */
  YYSYMBOL_ValueStmt = 87,                 /* ValueStmt  */
  YYSYMBOL_Block = 88,                     /* Block  */
  YYSYMBOL_89_6 = 89,                      /* $@6  */
  YYSYMBOL_90_7 = 90,                      /* $@7  */
  YYSYMBOL_PrintStmt = 91,                 /* PrintStmt  */
  YYSYMBOL_92_8 = 92,                      /* $@8  */
  YYSYMBOL_93_9 = 93,                      /* $@9  */
  YYSYMBOL_94_10 = 94,                     /* $@10  */
  YYSYMBOL_95_11 = 95,                     /* $@11  */
  YYSYMBOL_string_stmt = 96,               /* string_stmt  */
  YYSYMBOL_97_12 = 97,                     /* $@12  */
  YYSYMBOL_Stmt = 98,                      /* Stmt  */
  YYSYMBOL_Stmt_opt = 99                   /* Stmt_opt  */
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  71
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   488

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  139
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  256

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
       2,     2,     2,    61,    55,     2,     2,    51,    62,     2,
      43,    44,    49,    47,    53,    48,     2,    50,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    52,    54,
      46,    58,    45,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    57,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    59,     2,    60,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   109,   109,   110,   114,   115,   116,   117,   121,   122,
     123,   124,   128,   129,   130,   131,   132,   133,   134,   135,
     138,   139,   140,   141,   145,   145,   160,   161,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   182,
     186,   186,   187,   188,   189,   192,   195,   196,   200,   201,
     202,   203,   204,   205,   213,   218,   222,   229,   230,   233,
     236,   236,   243,   243,   244,   257,   258,   259,   260,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   274,   275,
     276,   277,   280,   281,   286,   287,   288,   291,   292,   293,
     294,   295,   296,   301,   305,   301,   306,   309,   310,   311,
     312,   315,   319,   319,   319,   320,   320,   320,   323,   323,
     326,   330,   335,   341,   345,   349,   353,   360,   364,   369,
     373,   377,   381,   385,   390,   394,   399,   403,   407,   411,
     416,   417,   419,   428,   435,   445,   446,   447,   448,   449
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "LET", "MUT",
  "NEWLINE", "INT", "FLOAT", "BOOL", "STR", "TRUE", "FALSE", "GEQ", "LEQ",
  "EQL", "NEQ", "LOR", "LAND", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN",
  "DIV_ASSIGN", "REM_ASSIGN", "IF", "ELSE", "FOR", "WHILE", "LOOP",
  "PRINT", "PRINTLN", "FUNC", "RETURN", "BREAK", "ID", "ARROW", "AS", "IN",
  "DOTDOT", "RSHIFT", "LSHIFT", "INT_LIT", "FLOAT_LIT", "STRING_LIT",
  "'('", "')'", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'%'", "':'",
  "','", "';'", "'\"'", "'['", "']'", "'='", "'{'", "'}'", "'!'", "'&'",
  "$accept", "Program", "GlobalStatementList", "GlobalStatement",
  "Func_opt", "return_stmt", "FunctionDeclStmt", "$@1", "$@2",
  "break_stmt", "array_stmt", "$@3", "array_stmt_again", "new_element",
  "Simpile_stmt", "if_stmt", "while_stmt", "for_stmt", "$@4", "for_block",
  "$@5", "expr", "term", "factor", "ValueStmt", "Block", "$@6", "$@7",
  "PrintStmt", "$@8", "$@9", "$@10", "$@11", "string_stmt", "$@12", "Stmt",
  "Stmt_opt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-35)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-132)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     226,    10,   -35,   -35,   -35,   -35,   -35,   173,   -35,     6,
     173,   -34,   -12,    35,   235,    -8,    15,   -35,   -35,   173,
     173,    89,   -35,   -35,   173,    45,   226,   -35,    25,   133,
      52,    21,   -35,   -35,    79,   -35,   -35,   -35,   371,    63,
     -35,   -35,   -35,    12,   -35,    78,    57,   -35,   434,    16,
     434,   304,   321,   -35,   -35,   -35,   -35,   -35,    99,   173,
     173,   173,   173,   173,   360,   382,   -35,   -35,   -35,   226,
     -35,   -35,   226,   -35,    91,   -35,   133,   -35,   117,   -35,
      50,   -35,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   -35,   173,   173,   173,   173,   -35,    62,    98,
      58,    14,   199,   121,   104,   140,   397,   145,   135,   419,
     157,   161,   152,   434,   434,   434,   434,   434,   166,   -17,
     434,   -35,   226,   226,   133,   168,    84,    84,    84,    84,
     440,   288,    84,    84,   -35,   -35,   -35,   -35,   -35,   -35,
     -35,     5,   108,   -35,   -35,   -35,   -35,   216,   -35,    -3,
     -35,   -35,   -35,   -35,   -35,   167,   -35,   -35,   -35,   170,
     -35,   -35,   159,   -35,   191,   175,   -35,   178,   179,    19,
     -35,   -35,   190,   185,   237,   265,   213,   205,   221,   -35,
     210,   -35,   -35,   -35,   -35,    94,   -35,   -35,   -35,   206,
     309,   223,   -11,   -35,   -35,   -35,   -35,   226,   265,   -35,
     -35,   -35,   -35,   189,   150,    89,   226,   159,     4,    -9,
     -35,   -35,   -35,   -35,   -35,   226,   -13,   232,   226,   265,
     -35,   224,   225,   -35,   -35,   226,    66,   227,   219,   231,
     -35,   236,   220,   255,   260,   253,   254,   -35,   258,   -35,
     -10,   -35,   -35,   -35,   -35,   256,   277,   284,   283,   268,
     -25,   -35,   -35,   272,   -35,   -35
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     7,    91,    92,    87,    88,     0,    58,     0,
       0,     0,     0,     0,     0,     0,    83,    89,    90,     0,
       0,     0,    45,    93,     0,     0,     2,     5,     0,     8,
       0,     0,    44,    43,     0,    30,    31,    34,    38,    65,
      81,    86,    10,     0,    27,     0,     0,    83,    57,     0,
      59,     0,     0,    24,    20,    21,    22,    23,     0,     0,
       0,     0,     0,     0,     0,     0,    84,    46,    47,     0,
      85,     1,     3,     4,    10,    36,     9,    33,     0,    32,
      42,    29,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,     0,    26,    97,     0,
       0,     0,     0,     0,    83,     0,     0,     0,    83,     0,
       0,     0,     0,    48,    49,    50,    52,    51,    83,     0,
      54,    82,    94,     6,    35,     0,    73,    74,    75,    76,
      71,    72,    68,    70,    66,    67,    69,    78,    79,    80,
      28,     0,     0,   135,   136,   137,   139,     0,   138,   111,
     128,   129,   126,   127,    60,     0,   108,   100,    98,     0,
     101,    99,     0,    39,     0,     0,    56,     0,     0,   123,
     124,   125,     0,     0,     0,     0,     0,     0,     0,    15,
       0,    16,    19,    17,    18,     0,    53,    55,    95,     0,
       0,     0,     0,   113,   114,   110,   112,     0,     0,    61,
     106,   109,   103,     0,    83,    18,     0,    12,    10,     0,
     119,   120,   117,   118,    40,     0,     0,     0,    62,     0,
      64,     0,     0,    13,    14,     0,     0,     0,    10,     0,
     116,     0,     0,     0,     0,    10,     0,   122,     0,   115,
       0,    63,   107,   104,   121,     0,     0,     0,     0,     0,
       0,    41,   133,     0,   134,   132
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -35,   -35,     0,     2,   176,   -35,   -28,   -35,   -35,   -35,
     -24,   -35,   -35,   -35,   -35,   -35,   -35,   -35,   -35,   155,
     -35,    -2,   -35,    -1,   -35,     3,   -35,   -35,   -33,   -35,
     -35,   -35,   -35,   287,   -35,   -35,   200
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    25,   123,    73,   207,    28,    29,   111,    99,    30,
      31,   227,    32,    33,    34,    35,    36,    37,   175,   220,
     232,    38,    39,    40,    41,    74,    69,   167,    43,   159,
     222,   155,   221,   107,   177,    44,   149
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      26,    76,    27,    42,   -25,    48,   173,    80,    50,    51,
      98,   143,   144,   145,    45,   253,   215,    65,   225,    66,
     143,   144,   145,    70,    78,   165,    72,   246,   189,   229,
     247,    52,   254,    59,    60,    61,    62,    63,   166,    49,
      11,    12,   230,    46,   216,    71,   226,    58,   124,   106,
     109,   217,   103,    78,   146,   174,    80,   113,   114,   115,
     116,   117,   120,   146,   -25,    98,    97,   148,    53,   122,
     147,    27,    42,    64,    21,    79,   148,   190,    22,    75,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      11,    12,   136,   137,   138,   139,   124,     1,    93,     2,
       3,     4,   179,    21,     5,     6,    77,    22,   236,   101,
     141,   100,    94,    95,    96,   102,   142,     7,     8,     9,
      10,   237,    11,    12,    13,    14,    15,   204,   181,    67,
      68,    90,    91,    81,    17,    18,     1,    19,   182,     3,
       4,   112,    20,     5,     6,   -96,   183,   205,   170,   171,
     125,    22,   140,    23,   154,    24,     7,     8,     9,    10,
    -105,    11,    12,    13,    14,    15,    16,   179,    59,    60,
      61,    62,    63,    17,    18,   198,    19,    27,    42,     3,
       4,    20,   156,     5,     6,   206,    21,    27,   208,   158,
      22,  -102,   180,   181,    24,   223,   224,   218,   219,    27,
      42,   161,   203,   182,   162,   164,    47,   163,    64,   150,
     151,   183,   184,    17,    18,   206,    19,    27,   228,   219,
     168,    20,   172,   176,   186,   206,   178,    27,   235,     1,
     187,     2,     3,     4,    24,   147,     5,     6,   188,   152,
     153,    54,    55,   192,   191,    56,    57,   193,   194,     7,
       8,     9,    10,   200,    11,    12,    13,    14,    15,    16,
     201,   202,   203,   214,   209,   231,    17,    18,     1,    19,
       2,     3,     4,  -130,    20,     5,     6,   195,   196,    21,
     241,   233,   234,    22,   238,    23,   239,    24,     7,     8,
       9,    10,   240,    11,    12,    13,    14,    15,    16,   242,
      82,    83,    84,    85,   243,    17,    18,  -131,    19,   244,
       3,     4,   248,    20,     5,     6,   245,   249,    21,   210,
     211,   250,    22,   251,   197,   252,    24,     3,     4,   255,
     199,     5,     6,    88,    89,    90,    91,   104,   185,   110,
       0,   169,     0,     0,    17,    18,     0,    19,     0,   212,
     213,     0,    20,     0,   108,     0,     0,     0,     0,   105,
       0,    17,    18,     0,    19,    24,     3,     4,     0,    20,
       5,     6,     0,     0,     0,     0,   105,     0,     0,     0,
       0,     0,    24,    82,    83,    84,    85,    86,    87,     0,
       0,     0,     0,   118,    82,    83,    84,    85,    86,    87,
      17,    18,     0,    19,     0,     0,     0,     0,    20,    82,
      83,    84,    85,    86,    87,   119,    88,    89,    90,    91,
       0,    24,     0,     0,     0,    92,   121,    88,    89,    90,
      91,    82,    83,    84,    85,    86,    87,     0,     0,     0,
       0,   157,    88,    89,    90,    91,    82,    83,    84,    85,
      86,    87,    82,    83,    84,    85,     0,    87,     0,     0,
       0,     0,     0,   160,    88,    89,    90,    91,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    88,
      89,    90,    91,     0,     0,    88,    89,    90,    91
};

static const yytype_int16 yycheck[] =
{
       0,    29,     0,     0,     0,     7,     9,    31,    10,    43,
      43,     6,     7,     8,     4,    40,    27,    19,    27,    20,
       6,     7,     8,    24,     3,    42,    26,    37,     9,    42,
      40,    43,    57,    18,    19,    20,    21,    22,    55,    33,
      28,    29,    55,    33,    55,     0,    55,    55,    76,    51,
      52,    62,    36,     3,    49,    58,    80,    59,    60,    61,
      62,    63,    64,    49,    60,    98,    54,    62,    33,    69,
      56,    69,    69,    58,    53,    54,    62,    58,    57,    54,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      28,    29,    93,    94,    95,    96,   124,     3,    35,     5,
       6,     7,     8,    53,    10,    11,    54,    57,    42,    52,
      52,    33,    49,    50,    51,    58,    58,    23,    24,    25,
      26,    55,    28,    29,    30,    31,    32,    33,    34,    40,
      41,    47,    48,    54,    40,    41,     3,    43,    44,     6,
       7,    42,    48,    10,    11,    54,    52,    53,    40,    41,
      33,    57,    54,    59,    33,    61,    23,    24,    25,    26,
      56,    28,    29,    30,    31,    32,    33,     8,    18,    19,
      20,    21,    22,    40,    41,   175,    43,   175,   175,     6,
       7,    48,    42,    10,    11,   185,    53,   185,   185,    44,
      57,    56,    33,    34,    61,     6,     7,   197,   198,   197,
     197,    44,    52,    44,    43,    39,    33,    55,    58,    10,
      11,    52,    53,    40,    41,   215,    43,   215,   215,   219,
      52,    48,     6,    56,    33,   225,    56,   225,   225,     3,
      55,     5,     6,     7,    61,    56,    10,    11,    60,    40,
      41,     6,     7,    58,    54,    10,    11,    10,    11,    23,
      24,    25,    26,    40,    28,    29,    30,    31,    32,    33,
      55,    40,    52,    40,    58,    33,    40,    41,     3,    43,
       5,     6,     7,    54,    48,    10,    11,    40,    41,    53,
      60,    57,    57,    57,    57,    59,    55,    61,    23,    24,
      25,    26,    56,    28,    29,    30,    31,    32,    33,    44,
      12,    13,    14,    15,    44,    40,    41,    54,    43,    55,
       6,     7,    56,    48,    10,    11,    58,    40,    53,    10,
      11,    37,    57,    40,    59,    57,    61,     6,     7,    57,
     175,    10,    11,    45,    46,    47,    48,    33,   162,    52,
      -1,   141,    -1,    -1,    40,    41,    -1,    43,    -1,    40,
      41,    -1,    48,    -1,    33,    -1,    -1,    -1,    -1,    55,
      -1,    40,    41,    -1,    43,    61,     6,     7,    -1,    48,
      10,    11,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    61,    12,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    33,    12,    13,    14,    15,    16,    17,
      40,    41,    -1,    43,    -1,    -1,    -1,    -1,    48,    12,
      13,    14,    15,    16,    17,    55,    45,    46,    47,    48,
      -1,    61,    -1,    -1,    -1,    54,    44,    45,    46,    47,
      48,    12,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    12,    13,    14,    15,
      16,    17,    12,    13,    14,    15,    -1,    17,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    -1,    -1,    45,    46,    47,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     6,     7,    10,    11,    23,    24,    25,
      26,    28,    29,    30,    31,    32,    33,    40,    41,    43,
      48,    53,    57,    59,    61,    64,    65,    66,    68,    69,
      72,    73,    75,    76,    77,    78,    79,    80,    84,    85,
      86,    87,    88,    91,    98,     4,    33,    33,    84,    33,
      84,    43,    43,    33,     6,     7,    10,    11,    55,    18,
      19,    20,    21,    22,    58,    84,    86,    40,    41,    89,
      86,     0,    65,    66,    88,    54,    69,    54,     3,    54,
      73,    54,    12,    13,    14,    15,    16,    17,    45,    46,
      47,    48,    54,    35,    49,    50,    51,    54,    91,    71,
      33,    52,    58,    36,    33,    55,    84,    96,    33,    84,
      96,    70,    42,    84,    84,    84,    84,    84,    33,    55,
      84,    44,    65,    65,    69,    33,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    86,    86,    86,    86,
      54,    52,    58,     6,     7,     8,    49,    56,    62,    99,
      10,    11,    40,    41,    33,    94,    42,    44,    44,    92,
      44,    44,    43,    55,    39,    42,    55,    90,    52,    99,
      40,    41,     6,     9,    58,    81,    56,    97,    56,     8,
      33,    34,    44,    52,    53,    67,    33,    55,    60,     9,
      58,    54,    58,    10,    11,    40,    41,    59,    65,    82,
      40,    55,    40,    52,    33,    53,    65,    67,    88,    58,
      10,    11,    40,    41,    40,    27,    55,    62,    65,    65,
      82,    95,    93,     6,     7,    27,    55,    74,    88,    42,
      55,    33,    83,    57,    57,    88,    42,    55,    57,    55,
      56,    60,    44,    44,    55,    58,    37,    40,    56,    40,
      37,    40,    57,    40,    57,    57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    64,    65,    65,    65,    65,    66,    66,
      66,    66,    67,    67,    67,    67,    67,    67,    67,    67,
      68,    68,    68,    68,    70,    69,    69,    71,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    72,
      74,    73,    73,    73,    73,    75,    76,    76,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    78,    78,    79,
      81,    80,    83,    82,    82,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    85,    85,
      85,    85,    86,    86,    86,    86,    86,    87,    87,    87,
      87,    87,    87,    89,    90,    88,    88,    91,    91,    91,
      91,    91,    92,    93,    91,    94,    95,    91,    97,    96,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    99,    99,    99,    99,    99
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     2,     1,     1,     2,
       1,     1,     2,     3,     3,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     0,     6,     2,     0,     3,     2,
       1,     1,     2,     2,     1,     2,     2,     2,     1,     4,
       0,    12,     2,     1,     1,     1,     2,     2,     3,     3,
       3,     3,     3,     5,     3,     5,     4,     2,     1,     2,
       0,     6,     0,     4,     2,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     1,     3,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     0,     0,     5,     2,     2,     4,     4,
       4,     4,     0,     0,     9,     0,     0,     9,     0,     4,
       6,     4,     6,     6,     6,     9,     8,     7,     7,     7,
       7,    10,     9,     5,     5,     5,     4,     4,     4,     4,
       8,     9,    13,    12,    12,     1,     1,     1,     1,     1
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 13: /* Func_opt: ID ':' INT  */
#line 129 "compiler.y"
                 { insert_symbol((yyvsp[-2].s_val),"i32","-1"); }
#line 1837 "y.tab.c"
    break;

  case 14: /* Func_opt: ID ':' FLOAT  */
#line 130 "compiler.y"
                   { insert_symbol((yyvsp[-2].s_val),"f32","-1"); }
#line 1843 "y.tab.c"
    break;

  case 24: /* $@1: %empty  */
#line 145 "compiler.y"
              {
        if( func_first == 1 )
        {
            create_symbol();
            insert_symbol((yyvsp[0].s_val),"func","");
            func_first = 0;
        }
        else
        {
            insert_symbol((yyvsp[0].s_val),"func","");
            create_symbol();
            block_create = 1;
        } 
    }
#line 1862 "y.tab.c"
    break;

  case 25: /* FunctionDeclStmt: FUNC ID $@1 '(' Func_opt Block  */
#line 159 "compiler.y"
                       { dump_symbol(cs_idx); }
#line 1868 "y.tab.c"
    break;

  case 27: /* $@2: %empty  */
#line 161 "compiler.y"
           { ; }
#line 1874 "y.tab.c"
    break;

  case 39: /* break_stmt: BREAK '"' STRING_LIT '"'  */
#line 182 "compiler.y"
                                 { printf("STRING_LIT \"%s\"\n",(yyvsp[-1].s_val)); }
#line 1880 "y.tab.c"
    break;

  case 40: /* $@3: %empty  */
#line 186 "compiler.y"
                                     { printf("INT_LIT %d\n",(yyvsp[0].i_val)); }
#line 1886 "y.tab.c"
    break;

  case 41: /* array_stmt: LET ID ':' '[' INT ';' INT_LIT $@3 ']' '=' '[' INT_LIT  */
#line 186 "compiler.y"
                                                                                        { printf("INT_LIT %d\n",(yyvsp[0].i_val)) , strcpy(now_id,(yyvsp[-10].s_val)); }
#line 1892 "y.tab.c"
    break;

  case 45: /* array_stmt_again: ']'  */
#line 192 "compiler.y"
          { insert_symbol(now_id,"array","0"); }
#line 1898 "y.tab.c"
    break;

  case 46: /* new_element: ',' INT_LIT  */
#line 195 "compiler.y"
                  { printf("INT_LIT %d\n",(yyvsp[0].i_val)); }
#line 1904 "y.tab.c"
    break;

  case 47: /* new_element: ',' FLOAT_LIT  */
#line 196 "compiler.y"
                    { printf("FLOAT %f\n",(yyvsp[0].f_val)); }
#line 1910 "y.tab.c"
    break;

  case 48: /* Simpile_stmt: ID ADD_ASSIGN expr  */
#line 200 "compiler.y"
                         { printf("ADD_ASSIGN\n"); }
#line 1916 "y.tab.c"
    break;

  case 49: /* Simpile_stmt: ID SUB_ASSIGN expr  */
#line 201 "compiler.y"
                         { printf("SUB_ASSIGN\n"); }
#line 1922 "y.tab.c"
    break;

  case 50: /* Simpile_stmt: ID MUL_ASSIGN expr  */
#line 202 "compiler.y"
                         { printf("MUL_ASSIGN\n"); }
#line 1928 "y.tab.c"
    break;

  case 51: /* Simpile_stmt: ID REM_ASSIGN expr  */
#line 203 "compiler.y"
                         { printf("REM_ASSIGN\n"); }
#line 1934 "y.tab.c"
    break;

  case 52: /* Simpile_stmt: ID DIV_ASSIGN expr  */
#line 204 "compiler.y"
                         { printf("DIV_ASSIGN\n"); }
#line 1940 "y.tab.c"
    break;

  case 53: /* Simpile_stmt: ID '=' ID LSHIFT ID  */
#line 205 "compiler.y"
                          {
        node_saving = lookup_symbol((yyvsp[-2].s_val),1) , printf("IDENT (name=%s, address=%d)\n",(yyvsp[-2].s_val),node_saving.address);
        node_saving = lookup_symbol((yyvsp[0].s_val),1) , printf("IDENT (name=%s, address=%d)\n",(yyvsp[0].s_val),node_saving.address);
        
        printf("error:%d: invalid operation: LSHIFT (mismatched types i32 and f32)\n",yylineno+1);
        printf("LSHIFT\n");
        printf("ASSIGN\n");
    }
#line 1953 "y.tab.c"
    break;

  case 54: /* Simpile_stmt: ID '=' expr  */
#line 213 "compiler.y"
                  {
        node_saving = lookup_symbol((yyvsp[-2].s_val),"1");
        if( node_saving.address == 404 ) printf("error:%d: undefined: %s\n",yylineno+1,(yyvsp[-2].s_val));
        else printf("ASSIGN\n"); 
    }
#line 1963 "y.tab.c"
    break;

  case 55: /* Simpile_stmt: ID '=' '"' STRING_LIT '"'  */
#line 218 "compiler.y"
                                  { 
        printf("STRING_LIT \"%s\"\n",(yyvsp[-1].s_val));
        printf("ASSIGN\n"); 
    }
#line 1972 "y.tab.c"
    break;

  case 56: /* Simpile_stmt: ID '=' '"' '"'  */
#line 222 "compiler.y"
                       { // 空字串 
        printf("STRING LIT \"\"\n");
        printf("ASSIGN\n"); 
    }
#line 1981 "y.tab.c"
    break;

  case 60: /* $@4: %empty  */
#line 236 "compiler.y"
                   { 
        node_saving = lookup_symbol((yyvsp[0].s_val),1), printf("IDENT (name=%s, address=%d)\n",node_saving.name,node_saving.address);
        create_symbol();
        insert_symbol((yyvsp[-2].s_val),"i32","-1");
    }
#line 1991 "y.tab.c"
    break;

  case 62: /* $@5: %empty  */
#line 243 "compiler.y"
                               { dump_symbol(cs_idx); }
#line 1997 "y.tab.c"
    break;

  case 66: /* expr: expr '+' expr  */
#line 258 "compiler.y"
                     { printf("ADD\n"); }
#line 2003 "y.tab.c"
    break;

  case 67: /* expr: expr '-' expr  */
#line 259 "compiler.y"
                     { printf("SUB\n"); }
#line 2009 "y.tab.c"
    break;

  case 68: /* expr: expr '>' expr  */
#line 260 "compiler.y"
                    { 
        if( HAS_ERROR == true ) printf("error:%d: invalid operation: GTR (mismatched types undefined and i32)\n",yylineno+1);    
        printf("GTR\n"); 
    }
#line 2018 "y.tab.c"
    break;

  case 70: /* expr: expr '<' expr  */
#line 265 "compiler.y"
                    { printf("LSS\n"); }
#line 2024 "y.tab.c"
    break;

  case 71: /* expr: expr LOR expr  */
#line 266 "compiler.y"
                    { printf("LOR\n") , strcpy(node_saving.type,"bool"); }
#line 2030 "y.tab.c"
    break;

  case 72: /* expr: expr LAND expr  */
#line 267 "compiler.y"
                     { printf("LAND\n") , strcpy(node_saving.type,"bool"); }
#line 2036 "y.tab.c"
    break;

  case 73: /* expr: expr GEQ expr  */
#line 268 "compiler.y"
                    { printf("GEQ\n"); }
#line 2042 "y.tab.c"
    break;

  case 74: /* expr: expr LEQ expr  */
#line 269 "compiler.y"
                    { printf("LEQ\n"); }
#line 2048 "y.tab.c"
    break;

  case 75: /* expr: expr EQL expr  */
#line 270 "compiler.y"
                    { printf("EQL\n"); }
#line 2054 "y.tab.c"
    break;

  case 76: /* expr: expr NEQ expr  */
#line 271 "compiler.y"
                    { printf("NEQ\n"); }
#line 2060 "y.tab.c"
    break;

  case 78: /* term: term '*' factor  */
#line 274 "compiler.y"
                       { printf("MUL\n"); }
#line 2066 "y.tab.c"
    break;

  case 79: /* term: term '/' factor  */
#line 275 "compiler.y"
                       { printf("DIV\n"); }
#line 2072 "y.tab.c"
    break;

  case 80: /* term: term '%' factor  */
#line 276 "compiler.y"
                       { printf("REM\n"); }
#line 2078 "y.tab.c"
    break;

  case 83: /* factor: ID  */
#line 281 "compiler.y"
         { 
        node_saving = lookup_symbol((yyvsp[0].s_val),1);
        if( node_saving.address == 404 ) printf("error:%d: undefined: %s\n",yylineno+1,(yyvsp[0].s_val)) , HAS_ERROR = true;
        else printf("IDENT (name=%s, address=%d)\n",node_saving.name,node_saving.address);
    }
#line 2088 "y.tab.c"
    break;

  case 84: /* factor: '-' factor  */
#line 286 "compiler.y"
                 { printf("NEG\n"); }
#line 2094 "y.tab.c"
    break;

  case 85: /* factor: '!' factor  */
#line 287 "compiler.y"
                 { printf("NOT\n"); }
#line 2100 "y.tab.c"
    break;

  case 87: /* ValueStmt: TRUE  */
#line 291 "compiler.y"
           { printf("bool TRUE\n"); }
#line 2106 "y.tab.c"
    break;

  case 88: /* ValueStmt: FALSE  */
#line 292 "compiler.y"
            { printf("bool FALSE\n"); }
#line 2112 "y.tab.c"
    break;

  case 89: /* ValueStmt: INT_LIT  */
#line 293 "compiler.y"
              { strcpy(node_saving.type,"i32") ,  printf("INT_LIT %d\n",(yyvsp[0].i_val)); }
#line 2118 "y.tab.c"
    break;

  case 90: /* ValueStmt: FLOAT_LIT  */
#line 294 "compiler.y"
                { strcpy(node_saving.type,"f32" ) ,  printf("FLOAT_LIT %f\n",(yyvsp[0].f_val)); }
#line 2124 "y.tab.c"
    break;

  case 91: /* ValueStmt: INT  */
#line 295 "compiler.y"
          { printf("f2i\n"); }
#line 2130 "y.tab.c"
    break;

  case 92: /* ValueStmt: FLOAT  */
#line 296 "compiler.y"
            { printf("i2f\n"); }
#line 2136 "y.tab.c"
    break;

  case 93: /* $@6: %empty  */
#line 301 "compiler.y"
          { 
        if( block_create == 0 ) create_symbol();
        else block_create = 0;
    }
#line 2145 "y.tab.c"
    break;

  case 94: /* $@7: %empty  */
#line 305 "compiler.y"
                             { dump_symbol(cs_idx); }
#line 2151 "y.tab.c"
    break;

  case 98: /* PrintStmt: PRINT '(' string_stmt ')'  */
#line 310 "compiler.y"
                                { printf("PRINT str\n"); }
#line 2157 "y.tab.c"
    break;

  case 99: /* PrintStmt: PRINTLN '(' string_stmt ')'  */
#line 311 "compiler.y"
                                  { printf("PRINTLN str\n"); }
#line 2163 "y.tab.c"
    break;

  case 100: /* PrintStmt: PRINT '(' expr ')'  */
#line 312 "compiler.y"
                         {
        
        printf("PRINT %s\n",node_saving.type); }
#line 2171 "y.tab.c"
    break;

  case 101: /* PrintStmt: PRINTLN '(' expr ')'  */
#line 315 "compiler.y"
                           { 
        
        printf("PRINTLN %s\n",node_saving.type) ; }
#line 2179 "y.tab.c"
    break;

  case 102: /* $@8: %empty  */
#line 319 "compiler.y"
                     { node_saving = lookup_symbol((yyvsp[0].s_val),1) , printf("IDENT (name=%s, address=%d)\n",(yyvsp[0].s_val),node_saving.address); }
#line 2185 "y.tab.c"
    break;

  case 103: /* $@9: %empty  */
#line 319 "compiler.y"
                                                                                                                                                { printf("INT_LIT %d\n",(yyvsp[0].i_val)); }
#line 2191 "y.tab.c"
    break;

  case 104: /* PrintStmt: PRINTLN '(' ID $@8 '[' INT_LIT $@9 ']' ')'  */
#line 319 "compiler.y"
                                                                                                                                                                                       { printf("PRINTLN array\n"); }
#line 2197 "y.tab.c"
    break;

  case 105: /* $@10: %empty  */
#line 320 "compiler.y"
                   { node_saving = lookup_symbol((yyvsp[0].s_val),1) , printf("IDENT (name=%s, address=%d)\n",(yyvsp[0].s_val),node_saving.address); }
#line 2203 "y.tab.c"
    break;

  case 106: /* $@11: %empty  */
#line 320 "compiler.y"
                                                                                                                                              { printf("INT_LIT %d\n",6); }
#line 2209 "y.tab.c"
    break;

  case 107: /* PrintStmt: PRINT '(' ID $@10 '[' INT_LIT $@11 ']' ')'  */
#line 320 "compiler.y"
                                                                                                                                                                                     { printf("PRINT array\n"); }
#line 2215 "y.tab.c"
    break;

  case 108: /* $@12: %empty  */
#line 323 "compiler.y"
                      { printf("STRING_LIT \"%s\"\n",(yyvsp[0].s_val)); }
#line 2221 "y.tab.c"
    break;

  case 109: /* string_stmt: '"' STRING_LIT $@12 '"'  */
#line 323 "compiler.y"
                                                                 { (yyval.s_val) = (yyvsp[-2].s_val);  }
#line 2227 "y.tab.c"
    break;

  case 110: /* Stmt: LET ID ':' Stmt_opt '=' INT_LIT  */
#line 326 "compiler.y"
                                      {
        printf("INT_LIT %d\n",(yyvsp[0].i_val));
        insert_symbol((yyvsp[-4].s_val),"i32","-1");
    }
#line 2236 "y.tab.c"
    break;

  case 111: /* Stmt: LET ID ':' Stmt_opt  */
#line 330 "compiler.y"
                          {
        if( type == 1 ) insert_symbol((yyvsp[-2].s_val),"i32","-1");
        if( type == 2 ) insert_symbol((yyvsp[-2].s_val),"f32","-1");
    }
#line 2245 "y.tab.c"
    break;

  case 112: /* Stmt: LET ID ':' Stmt_opt '=' FLOAT_LIT  */
#line 335 "compiler.y"
                                        { 

        printf("FLOAT_LIT %f\n",(yyvsp[0].f_val));
        int index = insert_symbol((yyvsp[-4].s_val),"f32","-1");
    }
#line 2255 "y.tab.c"
    break;

  case 113: /* Stmt: LET ID ':' Stmt_opt '=' TRUE  */
#line 341 "compiler.y"
                                   {
        printf("bool TRUE\n");
        int index = insert_symbol((yyvsp[-4].s_val),"bool","-1");
    }
#line 2264 "y.tab.c"
    break;

  case 114: /* Stmt: LET ID ':' Stmt_opt '=' FALSE  */
#line 345 "compiler.y"
                                   {
        printf("bool FALSE\n");
        int index = insert_symbol((yyvsp[-4].s_val),"bool","-1");
    }
#line 2273 "y.tab.c"
    break;

  case 115: /* Stmt: LET ID ':' Stmt_opt STR '=' '"' STRING_LIT '"'  */
#line 349 "compiler.y"
                                                       { 
        printf("STRING_LIT \"%s\"\n",(yyvsp[-1].s_val)); 
        int index = insert_symbol((yyvsp[-7].s_val),"str","-1");
    }
#line 2282 "y.tab.c"
    break;

  case 116: /* Stmt: LET ID ':' Stmt_opt STR '=' '"' '"'  */
#line 353 "compiler.y"
                                            { // 空字串
        printf("STRING_LIT \"\"\n"); 
        int index = insert_symbol((yyvsp[-6].s_val),"str","-1");
    }
#line 2291 "y.tab.c"
    break;

  case 117: /* Stmt: LET MUT ID ':' Stmt_opt '=' INT_LIT  */
#line 360 "compiler.y"
                                          {
        printf("INT_LIT %d\n",(yyvsp[0].i_val));
        int index = insert_symbol((yyvsp[-4].s_val),"i32","1");
    }
#line 2300 "y.tab.c"
    break;

  case 118: /* Stmt: LET MUT ID ':' Stmt_opt '=' FLOAT_LIT  */
#line 364 "compiler.y"
                                            { 

        printf("FLOAT_LIT %f\n",(yyvsp[0].f_val));
        int index = insert_symbol((yyvsp[-4].s_val),"f32","1");
    }
#line 2310 "y.tab.c"
    break;

  case 119: /* Stmt: LET MUT ID ':' Stmt_opt '=' TRUE  */
#line 369 "compiler.y"
                                       {
        printf("bool TRUE\n");
        int index = insert_symbol((yyvsp[-4].s_val),"bool","1");
    }
#line 2319 "y.tab.c"
    break;

  case 120: /* Stmt: LET MUT ID ':' Stmt_opt '=' FALSE  */
#line 373 "compiler.y"
                                       {
        printf("bool FALSE\n");
        int index = insert_symbol((yyvsp[-4].s_val),"bool","1");
    }
#line 2328 "y.tab.c"
    break;

  case 121: /* Stmt: LET MUT ID ':' Stmt_opt STR '=' '"' STRING_LIT '"'  */
#line 377 "compiler.y"
                                                           { 
        printf("STRING_LIT \"%s\"\n",(yyvsp[-1].s_val)); 
        int index = insert_symbol((yyvsp[-7].s_val),"str","1");
    }
#line 2337 "y.tab.c"
    break;

  case 122: /* Stmt: LET MUT ID ':' Stmt_opt STR '=' '"' '"'  */
#line 381 "compiler.y"
                                                { // 空字串
        printf("STRING_LIT \"\"\n"); 
        int index = insert_symbol((yyvsp[-6].s_val),"str","1");
    }
#line 2346 "y.tab.c"
    break;

  case 123: /* Stmt: LET MUT ID ':' Stmt_opt  */
#line 385 "compiler.y"
                              {
        if( type == 1 ) insert_symbol((yyvsp[-2].s_val),"i32","1");
        if( type == 2 ) insert_symbol((yyvsp[-2].s_val),"f32","1");
    }
#line 2355 "y.tab.c"
    break;

  case 124: /* Stmt: LET MUT ID '=' INT_LIT  */
#line 390 "compiler.y"
                             {
        printf("INT_LIT %d\n",(yyvsp[0].i_val));
        insert_symbol((yyvsp[-2].s_val),"i32","1");
    }
#line 2364 "y.tab.c"
    break;

  case 125: /* Stmt: LET MUT ID '=' FLOAT_LIT  */
#line 394 "compiler.y"
                               {
        printf("FLOAT_LIT %f\n",(yyvsp[0].f_val));
        insert_symbol((yyvsp[-2].s_val),"f32","1");
    }
#line 2373 "y.tab.c"
    break;

  case 126: /* Stmt: LET ID '=' INT_LIT  */
#line 399 "compiler.y"
                        {
        printf("INT_LIT %d\n",(yyvsp[0].i_val));
        insert_symbol((yyvsp[-2].s_val),"i32","-1");
    }
#line 2382 "y.tab.c"
    break;

  case 127: /* Stmt: LET ID '=' FLOAT_LIT  */
#line 403 "compiler.y"
                          {
        printf("FLOAT_LIT %f\n",(yyvsp[0].f_val));
        insert_symbol((yyvsp[-2].s_val),"f32","-1");
    }
#line 2391 "y.tab.c"
    break;

  case 128: /* Stmt: LET ID '=' TRUE  */
#line 407 "compiler.y"
                      {
        printf("bool TRUE\n");
        insert_symbol((yyvsp[-2].s_val),"bool","-1");
    }
#line 2400 "y.tab.c"
    break;

  case 129: /* Stmt: LET ID '=' FALSE  */
#line 411 "compiler.y"
                       {
        printf("bool FALSE\n");
        insert_symbol((yyvsp[-2].s_val),"bool","-1");
    }
#line 2409 "y.tab.c"
    break;

  case 130: /* Stmt: LET ID ':' Stmt_opt STR '=' LOOP Block  */
#line 416 "compiler.y"
                                             {  insert_symbol((yyvsp[-6].s_val),"str","-1"); }
#line 2415 "y.tab.c"
    break;

  case 131: /* Stmt: LET MUT ID ':' Stmt_opt STR '=' LOOP Block  */
#line 417 "compiler.y"
                                                 {  insert_symbol((yyvsp[-6].s_val),"str","1"); }
#line 2421 "y.tab.c"
    break;

  case 132: /* Stmt: LET ID ':' Stmt_opt STR '=' '&' ID '[' INT_LIT DOTDOT INT_LIT ']'  */
#line 420 "compiler.y"
        {  
            node_saving = lookup_symbol((yyvsp[-5].s_val),"1");
            printf("IDENT (name=%s, address=%d)\n",node_saving.name,node_saving.address);
            printf("INT_LIT %d\n",(yyvsp[-3].i_val));
            printf("DOTDOT\n");
            printf("INT_LIT %d\n",(yyvsp[-1].i_val));
            insert_symbol((yyvsp[-11].s_val),"str","-1"); 
        }
#line 2434 "y.tab.c"
    break;

  case 133: /* Stmt: LET ID ':' Stmt_opt STR '=' '&' ID '[' DOTDOT INT_LIT ']'  */
#line 429 "compiler.y"
        {   node_saving = lookup_symbol((yyvsp[-4].s_val),"1");
            printf("IDENT (name=%s, address=%d)\n",node_saving.name,node_saving.address);
            printf("DOTDOT\n");
            printf("INT_LIT %d\n",(yyvsp[-1].i_val));
            insert_symbol((yyvsp[-10].s_val),"str","-1"); 
        }
#line 2445 "y.tab.c"
    break;

  case 134: /* Stmt: LET ID ':' Stmt_opt STR '=' '&' ID '[' INT_LIT DOTDOT ']'  */
#line 436 "compiler.y"
        {   
            node_saving = lookup_symbol((yyvsp[-4].s_val),"1");
            printf("IDENT (name=%s, address=%d)\n",node_saving.name,node_saving.address);
            printf("INT_LIT %d\n",(yyvsp[-2].i_val));
            printf("DOTDOT\n");
            insert_symbol((yyvsp[-10].s_val),"str","-1"); 
        }
#line 2457 "y.tab.c"
    break;

  case 135: /* Stmt_opt: INT  */
#line 445 "compiler.y"
          { type = 1; }
#line 2463 "y.tab.c"
    break;

  case 136: /* Stmt_opt: FLOAT  */
#line 446 "compiler.y"
            { type = 2; }
#line 2469 "y.tab.c"
    break;


#line 2473 "y.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 453 "compiler.y"


/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    yylineno = 0;
    yyparse();

	printf("Total lines: %d\n", yylineno);
    fclose(yyin);
    return 0;
}

static void dump_symbol(int scope) {
    // printf("> Dump symbol table (scope level: %d)\n", scope) , f = 1;
    printf("\n> Dump symbol table (scope level: %d)\n", scope);


    printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n",
           "Index", "Name", "Mut" , "Type", "Addr", "Lineno", "Func_sig");
    for(int i=0; i<table_len[scope]; ++i){
        
        int mut = 0;

        if( strcmp(table[scope][i].type,"func") == 0 ) mut = -1;

        if( mut == -1 )
        {
            printf("%-10d%-10s%-10d%-10s%-10d%-10d%-10s\n",
            i, table[scope][i].name, mut, table[scope][i].type, table[scope][i].address, table[scope][i].lineno, "(V)V");
        }     
        else 
        {
            printf("%-10d%-10s%-10d%-10s%-10d%-10d%-10s\n",
            i, table[scope][i].name, table[scope][i].mut, table[scope][i].type, table[scope][i].address, table[scope][i].lineno, "-");
        } 
    }
    table_len[cs_idx] = 0;
    cs_idx--;
}

static void create_symbol() {
    cs_idx++;
    printf("> Create symbol table (scope level %d)\n", cs_idx );
}

static int insert_symbol(char* name, char* type, char* element_type) {
    
    NODE tmp = lookup_symbol(name, 0);
    table[cs_idx][table_len[cs_idx]].address = address;
    table[cs_idx][table_len[cs_idx]].lineno = yylineno + 1;
    strcpy(table[cs_idx][table_len[cs_idx]].name, name);
    strcpy(table[cs_idx][table_len[cs_idx]].type, type);
    if( strcmp(element_type,"1") == 0 ) table[cs_idx][table_len[cs_idx]].mut = 1;  
    strcpy(table[cs_idx][table_len[cs_idx]].element_type, element_type);
    table_len[cs_idx]++;

    
    if( strcmp(type,"func") == 0 )
    {
        printf("func: %s\n",name); 
        printf("> Insert `%s` (addr: %d) to scope level %d\n", name, -1, cs_idx); 
        table[cs_idx][table_len[cs_idx-1]].address = -1;
      //  if( check_newline == 1 ) printf("\n");
        return -1;
    }
    else printf("> Insert `%s` (addr: %d) to scope level %d\n", name, address, cs_idx);

    if( strcmp(type,"func") != 0 ) address++;

    return address - 1;
}

static NODE lookup_symbol(char* name, int flag) {

    for(int i=cs_idx; i>=0; --i){
        for(int j=0; j<table_len[i]; ++j){
            if(0 == strcmp(table[i][j].name, name))
                return table[i][j];
        }
    }
    NODE node;
    node.address = 404; // 404 not found
    return node;
}
