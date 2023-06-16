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

    #include "compiler_common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;
    #define MAX_SCOPE 20
    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    int yylex_destroy ();
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    /* Used to generate code */
    /* As printf; the usage: CODEGEN("%d - %s\n", 100, "Hello world"); */
    /* We do not enforce the use of this macro */
    #define CODEGEN(...) \
        do { \
            for (int i = 0; i < g_indent_cnt; i++) { \
                fprintf(fout, "\t"); \
            } \
            fprintf(fout, __VA_ARGS__); \
        } while (0)

    /* Symbol table function - you can add new functions if needed. */
    /* parameters and return type can be changed */
    
    typedef struct Node
    {
        char name[20];
        char type[20];
        int address;
        int lineno;
        int mut;
        char element_type[20];
    } NODE;
    
    
    static void create_symbol();
    static int insert_symbol(char* name, char* type, char* element_type);
    static NODE lookup_symbol(char* name, int flag);
    static void dump_symbol(int scope);

    /* Global variables */

    bool g_has_error = false;
    FILE *fout = NULL;
    int g_indent_cnt = 0;
    bool HAS_ERROR = false;

    int as_type = 0;
    int cs_idx = -1;

    int table_len[MAX_SCOPE] = {}; // each table len
    NODE table[MAX_SCOPE][50]; // symbol table
    int address = 0;  
    int type = 0;
    char now_type[10] = "none";
    char now_op[10] = "none";
    char now_id[10] = "none";
    NODE *global_node , node_saving;

    char variable_name[20] = {};
    int variable_address = 0;
    int cmp_num = 1;
    int if_num = 1;
    int num_if_exit = 1 , level_if = 0 , prev_if = 0, now_if = 0 , loop_num;

    int array_data[105][105];
    int array_address[105][105];
    int queue[105] , queue_index = 0 , loop_break_address = 0 , foreach = 0;
    char str_saving[105];

#line 147 "y.tab.c"

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
#line 86 "compiler.y"

    int i_val;
    float f_val;
    char *s_val;
    /* ... */

#line 291 "y.tab.c"

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
  YYSYMBOL_func_stmt = 72,                 /* func_stmt  */
  YYSYMBOL_73_3 = 73,                      /* $@3  */
  YYSYMBOL_74_4 = 74,                      /* $@4  */
  YYSYMBOL_75_5 = 75,                      /* $@5  */
  YYSYMBOL_func_element = 76,              /* func_element  */
  YYSYMBOL_break_stmt = 77,                /* break_stmt  */
  YYSYMBOL_array_stmt = 78,                /* array_stmt  */
  YYSYMBOL_79_6 = 79,                      /* $@6  */
  YYSYMBOL_array_stmt_again = 80,          /* array_stmt_again  */
  YYSYMBOL_new_element = 81,               /* new_element  */
  YYSYMBOL_Simpile_stmt = 82,              /* Simpile_stmt  */
  YYSYMBOL_if_stmt = 83,                   /* if_stmt  */
  YYSYMBOL_84_7 = 84,                      /* $@7  */
  YYSYMBOL_85_8 = 85,                      /* $@8  */
  YYSYMBOL_if_continue = 86,               /* if_continue  */
  YYSYMBOL_87_9 = 87,                      /* $@9  */
  YYSYMBOL_88_10 = 88,                     /* $@10  */
  YYSYMBOL_else_stmt = 89,                 /* else_stmt  */
  YYSYMBOL_while_stmt = 90,                /* while_stmt  */
  YYSYMBOL_91_11 = 91,                     /* $@11  */
  YYSYMBOL_92_12 = 92,                     /* $@12  */
  YYSYMBOL_for_stmt = 93,                  /* for_stmt  */
  YYSYMBOL_94_13 = 94,                     /* $@13  */
  YYSYMBOL_for_block = 95,                 /* for_block  */
  YYSYMBOL_96_14 = 96,                     /* $@14  */
  YYSYMBOL_expr = 97,                      /* expr  */
  YYSYMBOL_term = 98,                      /* term  */
  YYSYMBOL_factor = 99,                    /* factor  */
  YYSYMBOL_ValueStmt = 100,                /* ValueStmt  */
  YYSYMBOL_Block = 101,                    /* Block  */
  YYSYMBOL_102_15 = 102,                   /* $@15  */
  YYSYMBOL_103_16 = 103,                   /* $@16  */
  YYSYMBOL_PrintStmt = 104,                /* PrintStmt  */
  YYSYMBOL_105_17 = 105,                   /* $@17  */
  YYSYMBOL_106_18 = 106,                   /* $@18  */
  YYSYMBOL_107_19 = 107,                   /* $@19  */
  YYSYMBOL_108_20 = 108,                   /* $@20  */
  YYSYMBOL_string_stmt = 109,              /* string_stmt  */
  YYSYMBOL_110_21 = 110,                   /* $@21  */
  YYSYMBOL_Stmt = 111,                     /* Stmt  */
  YYSYMBOL_112_22 = 112,                   /* $@22  */
  YYSYMBOL_Stmt_opt = 113                  /* Stmt_opt  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  70
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   404

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  154
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  289

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
       0,   130,   130,   134,   135,   139,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   154,   155,   156,   157,   161,
     161,   165,   166,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   179,   179,   180,   180,   181,   181,
     184,   185,   186,   187,   188,   192,   202,   202,   207,   208,
     209,   212,   228,   232,   236,   251,   265,   280,   294,   309,
     317,   331,   339,   346,   347,   346,   352,   352,   352,   353,
     368,   369,   378,   380,   378,   391,   391,   404,   404,   405,
     418,   419,   423,   428,   453,   463,   466,   470,   471,   472,
     498,   513,   514,   516,   521,   526,   530,   533,   534,   547,
     548,   552,   559,   562,   565,   570,   574,   579,   588,   588,
     588,   591,   592,   593,   598,   607,   628,   628,   628,   637,
     637,   637,   645,   645,   649,   654,   667,   676,   681,   686,
     692,   699,   704,   710,   715,   720,   725,   732,   743,   749,
     754,   759,   764,   769,   775,   775,   784,   786,   802,   816,
     832,   833,   834,   835,   836
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
  "Func_opt", "return_stmt", "FunctionDeclStmt", "$@1", "$@2", "func_stmt",
  "$@3", "$@4", "$@5", "func_element", "break_stmt", "array_stmt", "$@6",
  "array_stmt_again", "new_element", "Simpile_stmt", "if_stmt", "$@7",
  "$@8", "if_continue", "$@9", "$@10", "else_stmt", "while_stmt", "$@11",
  "$@12", "for_stmt", "$@13", "for_block", "$@14", "expr", "term",
  "factor", "ValueStmt", "Block", "$@15", "$@16", "PrintStmt", "$@17",
  "$@18", "$@19", "$@20", "string_stmt", "$@21", "Stmt", "$@22",
  "Stmt_opt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-164)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-120)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     100,    24,  -164,  -164,  -164,  -164,  -164,    -9,  -164,    -4,
      32,    -7,   145,    42,    12,  -164,  -164,   251,   251,    74,
    -164,  -164,   251,    92,   100,  -164,    50,  -164,  -164,    62,
      37,  -164,  -164,    73,  -164,  -164,  -164,   289,   180,  -164,
    -164,  -164,   106,  -164,   104,   -23,   251,   108,   251,   178,
     195,  -164,  -164,  -164,  -164,  -164,   105,   251,   251,   251,
     251,   251,   234,  -164,   313,  -164,  -164,  -164,   100,  -164,
    -164,  -164,  -164,  -164,   121,  -164,    15,  -164,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,  -164,   251,
     251,   251,   251,  -164,   175,   109,    61,     9,    98,   350,
     125,   350,   110,   131,   332,   134,   127,   338,   137,   143,
     148,   152,   154,   144,   350,   350,   350,   350,   350,   173,
     -28,   350,  -164,   100,   168,   201,   201,   201,   201,   356,
     162,   201,   201,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
       4,   211,  -164,  -164,  -164,  -164,   216,  -164,    -3,  -164,
    -164,  -164,  -164,   166,  -164,   166,   171,  -164,  -164,  -164,
     176,  -164,  -164,   280,   204,   190,   -11,  -164,   209,   200,
    -164,   199,   207,    -2,  -164,  -164,   210,   202,   183,  -164,
     241,   139,  -164,   226,   213,   232,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,  -164,   263,   221,   166,   247,  -164,  -164,
      68,  -164,  -164,  -164,   218,   206,   238,    40,  -164,  -164,
    -164,  -164,   255,   100,   139,  -164,  -164,  -164,  -164,   280,
    -164,   274,  -164,  -164,  -164,   249,   -11,    19,  -164,  -164,
    -164,  -164,  -164,  -164,   -19,   248,  -164,   100,  -164,  -164,
     228,   233,   240,   290,   166,   -17,   243,   166,   253,  -164,
     254,   -10,   257,   265,   267,   285,   166,  -164,   264,  -164,
     262,  -164,  -164,     7,  -164,  -164,  -164,  -164,  -164,  -164,
     269,  -164,  -164,   275,   283,   301,   333,   300,   284,   -20,
     298,  -164,  -164,   299,  -164,   -11,  -164,    65,  -164
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,   106,   107,   102,   103,    63,     0,    72,     0,
       0,     0,     0,     0,    98,   104,   105,     0,     0,     0,
      51,   108,     0,     0,     2,     4,     0,     5,    30,     0,
       0,    50,    49,     0,    25,    26,    29,     0,    80,    96,
      99,    33,     0,    22,     0,     0,     0,     0,     0,     0,
       0,    19,    15,    16,    17,    18,     0,     0,     0,     0,
       0,     0,     0,    98,     0,   100,    52,    53,     0,   101,
       1,     3,    31,    28,     0,    27,    48,    24,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    32,     0,
       0,     0,     0,    21,   111,     0,     0,     0,     0,    64,
       0,    73,    98,     0,     0,     0,    98,     0,     0,     0,
       0,     0,     0,     0,    54,    55,    56,    58,    57,    98,
       0,    60,    97,   109,     0,    87,    88,    89,    90,    85,
      86,    83,    84,    81,    82,    91,    93,    94,    95,    23,
       0,     0,   150,   151,   152,   154,     0,   153,   125,   142,
     143,   140,   141,     0,    75,     0,     0,   122,   114,   112,
       0,   115,   113,     0,     0,     0,     0,    45,     0,     0,
      62,     0,     0,   137,   138,   139,     0,     0,     0,    65,
      69,     0,    74,     0,     0,     0,     8,     9,    10,     7,
      11,    14,    12,    13,     0,     0,     0,     0,    41,    42,
       0,    59,    61,   110,     0,     0,     0,     0,   127,   128,
     124,   126,     0,     0,     0,    76,   120,   123,   117,     6,
      20,     0,    37,    43,    44,     0,    40,     0,   133,   134,
     131,   132,    46,   144,     0,     0,    67,    77,     3,    79,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   130,
       0,     0,     0,     0,     0,     0,     0,   146,     0,   136,
       0,   145,   129,     0,    70,    68,    71,    78,   121,   118,
       0,    39,   135,     0,     0,     0,     0,     0,     0,     0,
       0,    47,   148,     0,   149,     0,   147,     0,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -164,  -164,     1,   -24,   212,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,  -163,  -164,   -22,  -164,  -164,  -164,  -164,
     123,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,   158,  -164,     2,  -164,   -13,  -164,  -151,  -164,
    -164,   -21,  -164,  -164,  -164,  -164,   331,  -164,  -164,  -164,
     250
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    23,   214,    25,   219,    26,    27,   109,    95,    28,
     110,   111,   112,   226,    29,    30,   246,    31,    32,    33,
      34,    46,   153,   179,   212,   251,   265,    35,    48,   155,
      36,   181,   215,   252,    37,    38,    39,    40,    41,    68,
     171,    42,   160,   241,   156,   240,   105,   184,    43,   247,
     148
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      71,    24,   180,   200,   182,    65,   177,   204,    76,    69,
     142,   143,   144,     6,   169,   142,   143,   144,    74,    64,
     283,    94,   197,   248,    47,   258,    51,   170,    44,    97,
      57,    58,    59,    60,    61,    98,   249,   284,   259,    49,
      74,   198,   199,   220,   274,   222,   244,   275,    99,    21,
     101,   104,   107,   145,    76,   178,   205,    45,   145,   114,
     115,   116,   117,   118,   121,   146,   147,   233,    19,   123,
      62,   147,    20,    94,   245,    50,   135,   136,   137,   138,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
      19,    75,    70,   257,    20,   234,   261,    56,   197,    71,
     266,   197,   235,     1,    72,   271,     2,     3,   149,   150,
       4,     5,   225,   140,    66,    67,    73,   198,   199,   141,
     198,   199,   287,     6,    21,     7,     8,    77,     9,    10,
      11,    12,    13,    14,     9,    10,   288,    96,   151,   152,
      15,    16,     1,    17,   100,     2,     3,   113,    18,     4,
       5,    52,    53,    19,   124,    54,    55,    20,   154,    21,
      93,    22,     6,   139,     7,     8,  -119,     9,    10,    11,
      12,    13,    14,   157,    78,    79,    80,    81,   159,    15,
      16,   162,    17,  -116,     2,     3,   163,    18,     4,     5,
     238,   164,    19,   208,   209,   165,    20,   166,   213,   167,
      22,     2,     3,     9,    10,     4,     5,    84,    85,    86,
      87,   102,   168,    71,   237,    89,   228,   229,    15,    16,
     172,    17,   176,   210,   211,    21,    18,   183,   106,    90,
      91,    92,   185,   103,   196,    15,    16,   195,    17,    22,
       2,     3,   201,    18,     4,     5,   230,   231,    86,    87,
     103,   174,   175,   223,   224,   202,    22,     2,     3,   203,
     207,     4,     5,   146,   206,   -66,   216,   119,   217,   186,
     187,   188,   218,   221,    15,    16,   227,    17,   232,   236,
     242,   250,    18,   243,    63,   253,   186,   187,   188,   120,
     254,    15,    16,   255,    17,    22,   189,   190,   256,    18,
     260,    78,    79,    80,    81,    82,    83,   191,   262,   268,
     263,   269,    22,   189,   190,   192,   193,   267,   270,   272,
     273,   276,    21,   278,   191,    78,    79,    80,    81,    82,
      83,   277,   192,   193,    84,    85,    86,    87,   279,   280,
     281,   282,   285,    88,    78,    79,    80,    81,    82,    83,
      78,    79,    80,    81,    82,    83,   286,   122,    84,    85,
      86,    87,    78,    79,    80,    81,    82,    83,    78,    79,
      80,    81,   239,    83,   264,   194,   158,    84,    85,    86,
      87,   108,   161,    84,    85,    86,    87,     0,     0,     0,
     173,     0,     0,     0,     0,    84,    85,    86,    87,     0,
       0,    84,    85,    86,    87
};

static const yytype_int16 yycheck[] =
{
      24,     0,   153,   166,   155,    18,     9,     9,    30,    22,
       6,     7,     8,    23,    42,     6,     7,     8,     3,    17,
      40,    42,    33,    42,    33,    42,    33,    55,     4,    52,
      18,    19,    20,    21,    22,    58,    55,    57,    55,    43,
       3,    52,    53,   194,    37,   196,    27,    40,    46,    59,
      48,    49,    50,    49,    76,    58,    58,    33,    49,    57,
      58,    59,    60,    61,    62,    56,    62,    27,    53,    68,
      58,    62,    57,    94,    55,    43,    89,    90,    91,    92,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      53,    54,     0,   244,    57,    55,   247,    55,    33,   123,
     251,    33,    62,     3,    54,   256,     6,     7,    10,    11,
      10,    11,    44,    52,    40,    41,    54,    52,    53,    58,
      52,    53,   285,    23,    59,    25,    26,    54,    28,    29,
      30,    31,    32,    33,    28,    29,   287,    33,    40,    41,
      40,    41,     3,    43,    36,     6,     7,    42,    48,    10,
      11,     6,     7,    53,    33,    10,    11,    57,    33,    59,
      54,    61,    23,    54,    25,    26,    56,    28,    29,    30,
      31,    32,    33,    42,    12,    13,    14,    15,    44,    40,
      41,    44,    43,    56,     6,     7,    43,    48,    10,    11,
     214,    43,    53,    10,    11,    43,    57,    43,    59,    55,
      61,     6,     7,    28,    29,    10,    11,    45,    46,    47,
      48,    33,    39,   237,   213,    35,    10,    11,    40,    41,
      52,    43,     6,    40,    41,    59,    48,    56,    33,    49,
      50,    51,    56,    55,    44,    40,    41,    33,    43,    61,
       6,     7,    33,    48,    10,    11,    40,    41,    47,    48,
      55,    40,    41,     6,     7,    55,    61,     6,     7,    60,
      58,    10,    11,    56,    54,    24,    40,    33,    55,     6,
       7,     8,    40,    52,    40,    41,    58,    43,    40,    24,
       6,    33,    48,    34,    33,    57,     6,     7,     8,    55,
      57,    40,    41,    53,    43,    61,    33,    34,     8,    48,
      57,    12,    13,    14,    15,    16,    17,    44,    55,    44,
      56,    44,    61,    33,    34,    52,    53,    60,    33,    55,
      58,    52,    59,    40,    44,    12,    13,    14,    15,    16,
      17,    56,    52,    53,    45,    46,    47,    48,    37,     6,
      40,    57,    44,    54,    12,    13,    14,    15,    16,    17,
      12,    13,    14,    15,    16,    17,    57,    44,    45,    46,
      47,    48,    12,    13,    14,    15,    16,    17,    12,    13,
      14,    15,   214,    17,   251,   163,    44,    45,    46,    47,
      48,    50,    44,    45,    46,    47,    48,    -1,    -1,    -1,
     140,    -1,    -1,    -1,    -1,    45,    46,    47,    48,    -1,
      -1,    45,    46,    47,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     6,     7,    10,    11,    23,    25,    26,    28,
      29,    30,    31,    32,    33,    40,    41,    43,    48,    53,
      57,    59,    61,    64,    65,    66,    68,    69,    72,    77,
      78,    80,    81,    82,    83,    90,    93,    97,    98,    99,
     100,   101,   104,   111,     4,    33,    84,    33,    91,    43,
      43,    33,     6,     7,    10,    11,    55,    18,    19,    20,
      21,    22,    58,    33,    97,    99,    40,    41,   102,    99,
       0,    66,    54,    54,     3,    54,    78,    54,    12,    13,
      14,    15,    16,    17,    45,    46,    47,    48,    54,    35,
      49,    50,    51,    54,   104,    71,    33,    52,    58,    97,
      36,    97,    33,    55,    97,   109,    33,    97,   109,    70,
      73,    74,    75,    42,    97,    97,    97,    97,    97,    33,
      55,    97,    44,    65,    33,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    99,    99,    99,    99,    54,
      52,    58,     6,     7,     8,    49,    56,    62,   113,    10,
      11,    40,    41,    85,    33,    92,   107,    42,    44,    44,
     105,    44,    44,    43,    43,    43,    43,    55,    39,    42,
      55,   103,    52,   113,    40,    41,     6,     9,    58,    86,
     101,    94,   101,    56,   110,    56,     6,     7,     8,    33,
      34,    44,    52,    53,    67,    33,    44,    33,    52,    53,
      76,    33,    55,    60,     9,    58,    54,    58,    10,    11,
      40,    41,    87,    59,    65,    95,    40,    55,    40,    67,
     101,    52,   101,     6,     7,    44,    76,    58,    10,    11,
      40,    41,    40,    27,    55,    62,    24,    65,    66,    95,
     108,   106,     6,    34,    27,    55,    79,   112,    42,    55,
      33,    88,    96,    57,    57,    53,     8,   101,    42,    55,
      57,   101,    55,    56,    83,    89,   101,    60,    44,    44,
      33,   101,    55,    58,    37,    40,    52,    56,    40,    37,
       6,    40,    57,    40,    57,    44,    57,    76,   101
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    65,    65,    66,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    68,    68,    68,    68,    70,
      69,    69,    71,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    73,    72,    74,    72,    75,    72,
      76,    76,    76,    76,    76,    77,    79,    78,    78,    78,
      78,    80,    81,    81,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    84,    85,    83,    87,    88,    86,    86,
      89,    89,    91,    92,    90,    94,    93,    96,    95,    95,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    98,    98,    98,    98,    99,    99,    99,
      99,    99,   100,   100,   100,   100,   100,   100,   102,   103,
     101,   104,   104,   104,   104,   104,   105,   106,   104,   107,
     108,   104,   110,   109,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   112,   111,   111,   111,   111,   111,
     113,   113,   113,   113,   113
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     0,
       6,     2,     0,     3,     2,     1,     1,     2,     2,     1,
       1,     2,     2,     1,     0,    14,     0,     6,     0,     9,
       2,     1,     1,     2,     2,     4,     0,    12,     2,     1,
       1,     1,     2,     2,     3,     3,     3,     3,     3,     5,
       3,     5,     4,     0,     0,     5,     0,     0,     5,     1,
       1,     1,     0,     0,     5,     0,     6,     0,     4,     2,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     1,     3,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     0,     0,
       5,     2,     4,     4,     4,     4,     0,     0,     9,     0,
       0,     9,     0,     4,     6,     4,     6,     6,     6,     9,
       8,     7,     7,     7,     7,    10,     9,     5,     5,     5,
       4,     4,     4,     4,     0,     9,     9,    13,    12,    12,
       1,     1,     1,     1,     1
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
  case 19: /* $@1: %empty  */
#line 161 "compiler.y"
              { 
        create_symbol();
        insert_symbol((yyvsp[0].s_val),"func",""); }
#line 1879 "y.tab.c"
    break;

  case 20: /* FunctionDeclStmt: FUNC ID $@1 '(' Func_opt Block  */
#line 164 "compiler.y"
                       { dump_symbol(cs_idx); }
#line 1885 "y.tab.c"
    break;

  case 22: /* $@2: %empty  */
#line 166 "compiler.y"
           { ; }
#line 1891 "y.tab.c"
    break;

  case 34: /* $@3: %empty  */
#line 179 "compiler.y"
              { create_symbol() , insert_symbol((yyvsp[0].s_val),"func",""); }
#line 1897 "y.tab.c"
    break;

  case 35: /* func_stmt: FUNC ID $@3 '(' ID ':' INT ',' ID ':' INT ')' func_element Block  */
#line 179 "compiler.y"
                                                                                                                        { dump_symbol(cs_idx); }
#line 1903 "y.tab.c"
    break;

  case 36: /* $@4: %empty  */
#line 180 "compiler.y"
              { create_symbol() , insert_symbol((yyvsp[0].s_val),"func",""); }
#line 1909 "y.tab.c"
    break;

  case 37: /* func_stmt: FUNC ID $@4 '(' ')' Block  */
#line 180 "compiler.y"
                                                                               { dump_symbol(cs_idx); }
#line 1915 "y.tab.c"
    break;

  case 38: /* $@5: %empty  */
#line 181 "compiler.y"
              { create_symbol() , insert_symbol((yyvsp[0].s_val),"func",""); }
#line 1921 "y.tab.c"
    break;

  case 39: /* func_stmt: FUNC ID $@5 '(' func_element ')' ARROW BOOL Block  */
#line 181 "compiler.y"
                                                                                                       { dump_symbol(cs_idx); }
#line 1927 "y.tab.c"
    break;

  case 43: /* func_element: ID INT  */
#line 187 "compiler.y"
             { insert_symbol((yyvsp[-1].s_val),"i32","-1"); }
#line 1933 "y.tab.c"
    break;

  case 44: /* func_element: ID FLOAT  */
#line 188 "compiler.y"
               { insert_symbol((yyvsp[-1].s_val),"f32","-1"); }
#line 1939 "y.tab.c"
    break;

  case 45: /* break_stmt: BREAK '"' STRING_LIT '"'  */
#line 192 "compiler.y"
                                 { 
        printf("STRING_LIT \"%s\"\n",(yyvsp[-1].s_val));
        
        CODEGEN("\tldc \"%s\"\n",(yyvsp[-1].s_val));
        CODEGEN("\tastore %d\n",loop_break_address);
        
    }
#line 1951 "y.tab.c"
    break;

  case 46: /* $@6: %empty  */
#line 202 "compiler.y"
                                     { printf("INT_LIT %d\n",(yyvsp[0].i_val)); }
#line 1957 "y.tab.c"
    break;

  case 47: /* array_stmt: LET ID ':' '[' INT ';' INT_LIT $@6 ']' '=' '[' INT_LIT  */
#line 202 "compiler.y"
                                                                                        { printf("INT_LIT %d\n",(yyvsp[0].i_val));
    
        queue[queue_index++] = (yyvsp[0].i_val);
        strcpy(now_id,(yyvsp[-10].s_val)); 
    }
#line 1967 "y.tab.c"
    break;

  case 51: /* array_stmt_again: ']'  */
#line 212 "compiler.y"
          { insert_symbol(now_id,"array","0"); 
        node_saving = lookup_symbol(now_id,1);
        int ouo = 0;
        for(int i=0;i<queue_index;i++)
        {
            array_data[node_saving.address][i] = queue[i];
            array_address[node_saving.address][i] = address;
            CODEGEN("\tldc %d\n",queue[i]);
            CODEGEN("\tistore %d\n",address);
            address++;
        }
        
        queue_index = 0;
    }
#line 1986 "y.tab.c"
    break;

  case 52: /* new_element: ',' INT_LIT  */
#line 228 "compiler.y"
                  { 
        printf("INT_LIT %d\n",(yyvsp[0].i_val));
        queue[queue_index++] = (yyvsp[0].i_val);
    }
#line 1995 "y.tab.c"
    break;

  case 53: /* new_element: ',' FLOAT_LIT  */
#line 232 "compiler.y"
                    { printf("FLOAT %f\n",(yyvsp[0].f_val)); }
#line 2001 "y.tab.c"
    break;

  case 54: /* Simpile_stmt: ID ADD_ASSIGN expr  */
#line 236 "compiler.y"
                         { printf("ADD_ASSIGN\n"); 

        node_saving = lookup_symbol((yyvsp[-2].s_val),1);

        if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 ) CODEGEN("\tiload %d\n",node_saving.address);
        else CODEGEN("\tfload %d\n",node_saving.address);
        
        CODEGEN("\tswap\n"); // 交換後將數值加入
        
        if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 ) CODEGEN("\tiadd\n");
        else CODEGEN("\tfadd\n");
        
       if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 ) CODEGEN("\tistore %d\n",node_saving.address); // istore 儲存
       else CODEGEN("\tfstore %d\n",node_saving.address); // istore 儲存
    }
#line 2021 "y.tab.c"
    break;

  case 55: /* Simpile_stmt: ID SUB_ASSIGN expr  */
#line 251 "compiler.y"
                         { printf("SUB_ASSIGN\n"); 
        node_saving = lookup_symbol((yyvsp[-2].s_val),1);

        if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 ) CODEGEN("\tiload %d\n",node_saving.address);
        else CODEGEN("\tfload %d\n",node_saving.address);

        CODEGEN("\tswap\n"); // 交換後將數值加入
        
        if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 ) CODEGEN("\tisub\n");
        else CODEGEN("\tfsub\n");

        if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 ) CODEGEN("\tistore %d\n",node_saving.address); // istore 儲存
        else CODEGEN("\tfstore %d\n",node_saving.address); // istore 儲存
    }
#line 2040 "y.tab.c"
    break;

  case 56: /* Simpile_stmt: ID MUL_ASSIGN expr  */
#line 265 "compiler.y"
                         { printf("MUL_ASSIGN\n"); 
        
        node_saving = lookup_symbol((yyvsp[-2].s_val),1);
        
        if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 ) CODEGEN("\tiload %d\n",node_saving.address);
        else CODEGEN("\tfload %d\n",node_saving.address);

        CODEGEN("\tswap\n"); // 交換後將數值加入
        
        if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 ) CODEGEN("\timul\n");
        else CODEGEN("\tfmul\n");
        
        if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 ) CODEGEN("\tistore %d\n",node_saving.address); // istore 儲存
        else CODEGEN("\tfstore %d\n",node_saving.address); // istore 儲存
    }
#line 2060 "y.tab.c"
    break;

  case 57: /* Simpile_stmt: ID REM_ASSIGN expr  */
#line 280 "compiler.y"
                         { printf("REM_ASSIGN\n"); 
        
        node_saving = lookup_symbol((yyvsp[-2].s_val),1);
        
        if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 ) CODEGEN("\tiload %d\n",node_saving.address);
        else CODEGEN("\tfload %d\n",node_saving.address);
        
        CODEGEN("\tswap\n"); // 交換後將數值加入
        
        if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 ) CODEGEN("\tirem\n");
        
        if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 ) CODEGEN("\tistore %d\n",node_saving.address); // istore 儲存
        else CODEGEN("\tfstore %d\n",node_saving.address); // istore 儲存
    }
#line 2079 "y.tab.c"
    break;

  case 58: /* Simpile_stmt: ID DIV_ASSIGN expr  */
#line 294 "compiler.y"
                         { printf("DIV_ASSIGN\n"); 
        
        node_saving = lookup_symbol((yyvsp[-2].s_val),1);
        
        if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 ) CODEGEN("\tiload %d\n",node_saving.address);
        else CODEGEN("\tfload %d\n",node_saving.address);
        
        CODEGEN("\tswap\n"); // 交換後將數值加入
        
        if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 ) CODEGEN("\tidiv\n");
        else CODEGEN("\tfdiv\n");

        if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 ) CODEGEN("\tistore %d\n",node_saving.address); // istore 儲存
        else CODEGEN("\tfstore %d\n",node_saving.address); // istore 儲存
    }
#line 2099 "y.tab.c"
    break;

  case 59: /* Simpile_stmt: ID '=' ID LSHIFT ID  */
#line 309 "compiler.y"
                          {
        node_saving = lookup_symbol((yyvsp[-2].s_val),1) , printf("IDENT (name=%s, address=%d)\n",(yyvsp[-2].s_val),node_saving.address);
        node_saving = lookup_symbol((yyvsp[0].s_val),1) , printf("IDENT (name=%s, address=%d)\n",(yyvsp[0].s_val),node_saving.address);
        
        printf("error:%d: invalid operation: LSHIFT (mismatched types i32 and f32)\n",yylineno+1);
        printf("LSHIFT\n");
        printf("ASSIGN\n");
    }
#line 2112 "y.tab.c"
    break;

  case 60: /* Simpile_stmt: ID '=' expr  */
#line 317 "compiler.y"
                  {
        node_saving = lookup_symbol((yyvsp[-2].s_val),1);
        if( node_saving.address == 404 ) printf("error:%d: undefined: %s\n",yylineno+1,(yyvsp[-2].s_val));
        else printf("ASSIGN\n"); 
        
        if( strcmp(node_saving.type,"i32") == 0 || strcmp(node_saving.type,"bool") == 0 || type == 1 )
        {
            CODEGEN("\tistore %d\n",node_saving.address); // istore 儲存
            type = 0;
        }
        else if( strcmp(node_saving.type,"str") ) CODEGEN("\tastore %d\n",node_saving.address);
        else CODEGEN("\tfstore %d\n",node_saving.address); // istore 儲存

    }
#line 2131 "y.tab.c"
    break;

  case 61: /* Simpile_stmt: ID '=' '"' STRING_LIT '"'  */
#line 331 "compiler.y"
                                  { 
        printf("STRING_LIT \"%s\"\n",(yyvsp[-1].s_val));

        CODEGEN("\tldc \"%s\"\n",(yyvsp[-1].s_val));
        CODEGEN("\tastore %d\n",node_saving.address);

        printf("ASSIGN\n"); 
    }
#line 2144 "y.tab.c"
    break;

  case 62: /* Simpile_stmt: ID '=' '"' '"'  */
#line 339 "compiler.y"
                       { // 空字串 
        printf("STRING LIT \"\"\n");
        printf("ASSIGN\n"); 
    }
#line 2153 "y.tab.c"
    break;

  case 63: /* $@7: %empty  */
#line 346 "compiler.y"
         { if_num++; if( level_if == 1 ) { prev_if = if_num;} }
#line 2159 "y.tab.c"
    break;

  case 64: /* $@8: %empty  */
#line 347 "compiler.y"
         { CODEGEN("\tifeq L%d_if_false \n",if_num); }
#line 2165 "y.tab.c"
    break;

  case 66: /* $@9: %empty  */
#line 352 "compiler.y"
            { CODEGEN("\tgoto L%d_if_exit\n", num_if_exit); }
#line 2171 "y.tab.c"
    break;

  case 67: /* $@10: %empty  */
#line 352 "compiler.y"
                                                                   { CODEGEN("L%d_if_false:\n",if_num); }
#line 2177 "y.tab.c"
    break;

  case 69: /* if_continue: Block  */
#line 353 "compiler.y"
            { 
        
        CODEGEN("\tgoto L%d_if_exit\n", num_if_exit); 
    
        if( level_if == 1 ) CODEGEN("L%d_if_false:\n",prev_if);
        else { CODEGEN("L%d_if_false:\n", if_num);
        
            if( loop_break_address != 0 ) CODEGEN("\tgoto loop_begin\n");
            CODEGEN("L%d_if_exit:\n", num_if_exit); // if_exit 離開 if block
            num_if_exit++;
            level_if--;
        }
    }
#line 2195 "y.tab.c"
    break;

  case 71: /* else_stmt: Block  */
#line 369 "compiler.y"
             {  CODEGEN("L%d_if_exit:\n", num_if_exit);
        num_if_exit++;
        level_if--;

       // if( loop_break_address != 0 ) CODEGEN("\tgoto loop_begin\n");
    }
#line 2206 "y.tab.c"
    break;

  case 72: /* $@11: %empty  */
#line 378 "compiler.y"
            {
        CODEGEN("while_begin:\n");
    }
#line 2214 "y.tab.c"
    break;

  case 73: /* $@12: %empty  */
#line 380 "compiler.y"
           {

        CODEGEN("\tifeq while_false\n"); // expr 內的判斷式已經將 true/false 的結果放到 stack 了
       // CODEGEN
    }
#line 2224 "y.tab.c"
    break;

  case 74: /* while_stmt: WHILE $@11 expr $@12 Block  */
#line 384 "compiler.y"
            {
        CODEGEN("\tgoto while_begin\n");
        CODEGEN("while_false:\n");
    }
#line 2233 "y.tab.c"
    break;

  case 75: /* $@13: %empty  */
#line 391 "compiler.y"
                   { 
        node_saving = lookup_symbol((yyvsp[0].s_val),1), printf("IDENT (name=%s, address=%d)\n",node_saving.name,node_saving.address);
        create_symbol();
        CODEGEN("\tldc 0\n");
        insert_symbol((yyvsp[-2].s_val),"i32","-1");

        node_saving = lookup_symbol((yyvsp[0].s_val),1);
        
        foreach = 1;

    }
#line 2249 "y.tab.c"
    break;

  case 77: /* $@14: %empty  */
#line 404 "compiler.y"
                               { dump_symbol(cs_idx); }
#line 2255 "y.tab.c"
    break;

  case 81: /* expr: expr '+' expr  */
#line 419 "compiler.y"
                     { printf("ADD\n"); 
        if( type == 1 ) CODEGEN("\tiadd\n");
        else CODEGEN("\tfadd\n");
    }
#line 2264 "y.tab.c"
    break;

  case 82: /* expr: expr '-' expr  */
#line 423 "compiler.y"
                     { 
        printf("SUB\n");
        if( type == 1 ) CODEGEN("\tisub\n");
        else CODEGEN("\tfsub\n"); 
    }
#line 2274 "y.tab.c"
    break;

  case 83: /* expr: expr '>' expr  */
#line 428 "compiler.y"
                    { 
        if( HAS_ERROR == true ) printf("error:%d: invalid operation: GTR (mismatched types undefined and i32)\n",yylineno+1);    
        printf("GTR\n");

        if( type == 1 ){
            CODEGEN("\tisub\n");
            CODEGEN("\tifgt L%d_cmp_0\n", cmp_num);
            CODEGEN("\ticonst_0\n");
            CODEGEN("\tgoto L%d_cmp_1\n", cmp_num);
            CODEGEN("L%d_cmp_0:\n", cmp_num);
            CODEGEN("\ticonst_1\n");
            CODEGEN("L%d_cmp_1:\n", cmp_num);
            cmp_num++;
        }else{
            CODEGEN("\tfcmpl\n");
            CODEGEN("\tifgt L%d_cmp_0\n", cmp_num);
            CODEGEN("\ticonst_0\n");
            CODEGEN("\tgoto L%d_cmp_1\n", cmp_num);
            CODEGEN("L%d_cmp_0:\n", cmp_num);
            CODEGEN("\ticonst_1\n");
            CODEGEN("L%d_cmp_1:\n", cmp_num);
            cmp_num++;
        }

    }
#line 2304 "y.tab.c"
    break;

  case 84: /* expr: expr '<' expr  */
#line 453 "compiler.y"
                    { printf("LSS\n"); 
    
        CODEGEN("\tisub\n");
        CODEGEN("\tiflt L%d_cmp_0\n", cmp_num); // 相減判斷是否 < 0 來判斷 LSS
        CODEGEN("\ticonst_0\n");
        CODEGEN("\tgoto L%d_cmp_1\n", cmp_num);
        CODEGEN("L%d_cmp_0:\n", cmp_num);
        CODEGEN("\ticonst_1\n");
        CODEGEN("L%d_cmp_1:\n", cmp_num);
    }
#line 2319 "y.tab.c"
    break;

  case 85: /* expr: expr LOR expr  */
#line 463 "compiler.y"
                    { printf("LOR\n") , strcpy(node_saving.type,"bool"); 
        CODEGEN("\tior\n");
    }
#line 2327 "y.tab.c"
    break;

  case 86: /* expr: expr LAND expr  */
#line 466 "compiler.y"
                     { printf("LAND\n");
        strcpy(node_saving.type,"bool");
        CODEGEN("\tiand\n"); 
    }
#line 2336 "y.tab.c"
    break;

  case 87: /* expr: expr GEQ expr  */
#line 470 "compiler.y"
                    { printf("GEQ\n"); }
#line 2342 "y.tab.c"
    break;

  case 88: /* expr: expr LEQ expr  */
#line 471 "compiler.y"
                    { printf("LEQ\n"); }
#line 2348 "y.tab.c"
    break;

  case 89: /* expr: expr EQL expr  */
#line 472 "compiler.y"
                    { 
        
        printf("EQL\n"); 
        if( type != 2 )
        {
            CODEGEN("\tisub\n"); // 透過減法判斷是否相等
            CODEGEN("\tifeq L%d_cmp_0\n", cmp_num);
            CODEGEN("\ticonst_0\n");
            CODEGEN("\tgoto L%d_cmp_1\n", cmp_num);
            CODEGEN("L%d_cmp_0:\n", cmp_num);
            CODEGEN("\ticonst_1\n");
            CODEGEN("L%d_cmp_1:\n", cmp_num);
            cmp_num++;
        }
        else // float
        {
            CODEGEN("\tfcmpl\n"); 
            CODEGEN("\tifeq L%d_cmp_0\n", cmp_num);
            CODEGEN("\ticonst_0\n");
            CODEGEN("\tgoto L%d_cmp_1\n", cmp_num);
            CODEGEN("L%d_cmp_0:\n", cmp_num);
            CODEGEN("\ticonst_1\n");
            CODEGEN("L%d_cmp_1:\n", cmp_num);
            cmp_num++;
        }
    }
#line 2379 "y.tab.c"
    break;

  case 90: /* expr: expr NEQ expr  */
#line 498 "compiler.y"
                    { 
        
        CODEGEN("\tisub\n");
        CODEGEN("\tifne L%d_cmp_0\n",cmp_num); // if not equal to zero
        CODEGEN("\ticonst_0\n");
        CODEGEN("\tgoto L%d_cmp_1\n", cmp_num);
        CODEGEN("L%d_cmp_0:\n", cmp_num);
        CODEGEN("\ticonst_1\n");
        CODEGEN("L%d_cmp_1:\n", cmp_num);

        cmp_num++;

        printf("NEQ\n"); 
    }
#line 2398 "y.tab.c"
    break;

  case 93: /* term: term '*' factor  */
#line 516 "compiler.y"
                       { 
        printf("MUL\n");
        if( type == 1 ) CODEGEN("\timul\n");
        else CODEGEN("\tfmul\n");
    }
#line 2408 "y.tab.c"
    break;

  case 94: /* term: term '/' factor  */
#line 521 "compiler.y"
                       { 
        printf("DIV\n");
        if( type == 1 ) CODEGEN("\tidiv\n");
        else CODEGEN("\tfdiv\n");
    }
#line 2418 "y.tab.c"
    break;

  case 95: /* term: term '%' factor  */
#line 526 "compiler.y"
                       { 
        printf("REM\n"); 
        CODEGEN("\tirem\n");
    }
#line 2427 "y.tab.c"
    break;

  case 98: /* factor: ID  */
#line 534 "compiler.y"
         { 
        node_saving = lookup_symbol((yyvsp[0].s_val),1);
        if( node_saving.address == 404 ) printf("error:%d: undefined: %s\n",yylineno+1,(yyvsp[0].s_val)) , HAS_ERROR = true;
        else printf("IDENT (name=%s, address=%d)\n",node_saving.name,node_saving.address);

        if( strcmp(node_saving.type,"i32") == 0 ) CODEGEN("\tiload %d\n",node_saving.address);
        else if( strcmp(node_saving.type,"f32") == 0 ) CODEGEN("\tfload %d\n",node_saving.address);
        else if( strcmp(node_saving.type,"str") == 0 ) CODEGEN("\taload %d\n",node_saving.address);
        else CODEGEN("\tiload %d\n",node_saving.address);

        if( strcmp(node_saving.type,"i32") == 0 ) type = 1 , as_type = 1;
        else as_type = 2 , type = 2;
    }
#line 2445 "y.tab.c"
    break;

  case 100: /* factor: '-' factor  */
#line 548 "compiler.y"
                 { printf("NEG\n");
        if( type == 1 ) CODEGEN("\tineg\n");
        else CODEGEN("\tfneg\n"); 
    }
#line 2454 "y.tab.c"
    break;

  case 101: /* factor: '!' factor  */
#line 552 "compiler.y"
                 { 
        printf("NOT\n");
        CODEGEN("\ticonst_1\n"); // 用 1 去 xor 做出 NOT 的效果
        CODEGEN("\tixor\n"); 
    }
#line 2464 "y.tab.c"
    break;

  case 102: /* ValueStmt: TRUE  */
#line 559 "compiler.y"
           { printf("bool TRUE\n"); 
        CODEGEN("\ticonst_1\n");
    }
#line 2472 "y.tab.c"
    break;

  case 103: /* ValueStmt: FALSE  */
#line 562 "compiler.y"
            { printf("bool FALSE\n");
        CODEGEN("\ticonst_0\n"); 
    }
#line 2480 "y.tab.c"
    break;

  case 104: /* ValueStmt: INT_LIT  */
#line 565 "compiler.y"
              { strcpy(node_saving.type,"i32") ,  printf("INT_LIT %d\n",(yyvsp[0].i_val)); 
        CODEGEN("\tldc %d\n",(yyvsp[0].i_val));
        type = 1;
        as_type = 1;
    }
#line 2490 "y.tab.c"
    break;

  case 105: /* ValueStmt: FLOAT_LIT  */
#line 570 "compiler.y"
                { strcpy(node_saving.type,"f32" ) ,  printf("FLOAT_LIT %f\n",(yyvsp[0].f_val)) , type = 2; 
        CODEGEN("\tldc %f\n",(yyvsp[0].f_val));
        as_type = 2;
    }
#line 2499 "y.tab.c"
    break;

  case 106: /* ValueStmt: INT  */
#line 574 "compiler.y"
          {
         CODEGEN("\tf2i\n");
         printf("f2i\n");
         type = 1;
    }
#line 2509 "y.tab.c"
    break;

  case 107: /* ValueStmt: FLOAT  */
#line 579 "compiler.y"
            { 
        CODEGEN("\ti2f\n");
        printf("i2f\n");
        type = 2; 
    }
#line 2519 "y.tab.c"
    break;

  case 108: /* $@15: %empty  */
#line 588 "compiler.y"
          {create_symbol();}
#line 2525 "y.tab.c"
    break;

  case 109: /* $@16: %empty  */
#line 588 "compiler.y"
                                                  { dump_symbol(cs_idx); }
#line 2531 "y.tab.c"
    break;

  case 112: /* PrintStmt: PRINT '(' string_stmt ')'  */
#line 592 "compiler.y"
                                { printf("PRINT str\n"); }
#line 2537 "y.tab.c"
    break;

  case 113: /* PrintStmt: PRINTLN '(' string_stmt ')'  */
#line 593 "compiler.y"
                                  { 
        
        print_j("str",1);
        printf("PRINTLN str\n"); 
    }
#line 2547 "y.tab.c"
    break;

  case 114: /* PrintStmt: PRINT '(' expr ')'  */
#line 598 "compiler.y"
                         {
        
        printf("PRINT %s\n",node_saving.type); 

        if( strcmp(node_saving.type,"i32") == 0 )  print_j("i32",0);
        else if( strcmp(node_saving.type,"f32") == 0 ) print_j("f32",0);
        else if( strcmp(node_saving.type,"bool") == 0 ) print_j("bool",0);
        else print_j("str",0);
    }
#line 2561 "y.tab.c"
    break;

  case 115: /* PrintStmt: PRINTLN '(' expr ')'  */
#line 607 "compiler.y"
                           { 
        
        printf("PRINTLN %s\n",node_saving.type) ;

        if( foreach == 1 )
        {
            int array_id = node_saving.address;
            for(int i=0;i<5;i++)
            {
                CODEGEN("\tiload %d\n",array_address[0][i]);
                print_j("i32",1);
            }

            foreach = 0;
        }
        else if( strcmp(node_saving.type,"i32") == 0 )  print_j("i32",1);
        else if( strcmp(node_saving.type,"f32") == 0 ) print_j("f32",1);
        else if( strcmp(node_saving.type,"bool") == 0 ) print_j("bool",1);
        else print_j("str",1);
    }
#line 2586 "y.tab.c"
    break;

  case 116: /* $@17: %empty  */
#line 628 "compiler.y"
                     { node_saving = lookup_symbol((yyvsp[0].s_val),1) , printf("IDENT (name=%s, address=%d)\n",(yyvsp[0].s_val),node_saving.address); }
#line 2592 "y.tab.c"
    break;

  case 117: /* $@18: %empty  */
#line 628 "compiler.y"
                                                                                                                                                { printf("INT_LIT %d\n",(yyvsp[0].i_val)); }
#line 2598 "y.tab.c"
    break;

  case 118: /* PrintStmt: PRINTLN '(' ID $@17 '[' INT_LIT $@18 ']' ')'  */
#line 628 "compiler.y"
                                                                                                                                                                                       { 
        printf("PRINTLN array\n");
        int array_id = node_saving.address;
        
        int idx = 0;
        
        CODEGEN("\tiload %d\n",array_address[array_id][(yyvsp[-3].i_val)]);
        print_j("i32",1);
    }
#line 2612 "y.tab.c"
    break;

  case 119: /* $@19: %empty  */
#line 637 "compiler.y"
                   { node_saving = lookup_symbol((yyvsp[0].s_val),1) , printf("IDENT (name=%s, address=%d)\n",(yyvsp[0].s_val),node_saving.address); }
#line 2618 "y.tab.c"
    break;

  case 120: /* $@20: %empty  */
#line 637 "compiler.y"
                                                                                                                                              { printf("INT_LIT %d\n",6); }
#line 2624 "y.tab.c"
    break;

  case 121: /* PrintStmt: PRINT '(' ID $@19 '[' INT_LIT $@20 ']' ')'  */
#line 637 "compiler.y"
                                                                                                                                                                                     { 
        
        int array_id = node_saving.address;
        CODEGEN("\tiload %d\n",array_address[array_id][(yyvsp[-3].i_val)]);
        print_j("i32",1);
        printf("PRINT array\n"); }
#line 2635 "y.tab.c"
    break;

  case 122: /* $@21: %empty  */
#line 645 "compiler.y"
                      { CODEGEN("\tldc \"%s\"\n", (yyvsp[0].s_val));
     printf("STRING_LIT \"%s\"\n",(yyvsp[0].s_val)); }
#line 2642 "y.tab.c"
    break;

  case 123: /* string_stmt: '"' STRING_LIT $@21 '"'  */
#line 646 "compiler.y"
                                              { (yyval.s_val) = (yyvsp[-2].s_val);  }
#line 2648 "y.tab.c"
    break;

  case 124: /* Stmt: LET ID ':' Stmt_opt '=' INT_LIT  */
#line 649 "compiler.y"
                                      {
        printf("INT_LIT %d\n",(yyvsp[0].i_val));
        CODEGEN("\tldc %d\n",(yyvsp[0].i_val));
        insert_symbol((yyvsp[-4].s_val),"i32","-1");
    }
#line 2658 "y.tab.c"
    break;

  case 125: /* Stmt: LET ID ':' Stmt_opt  */
#line 654 "compiler.y"
                          {
        if( type == 1 )
        {
            CODEGEN("\tldc %d\n",0);
            insert_symbol((yyvsp[-2].s_val),"i32","-1");
        }
        if( type == 2 )
        {
            CODEGEN("\tldc %f\n",0.0);
            insert_symbol((yyvsp[-2].s_val),"f32","-1");
        }
    }
#line 2675 "y.tab.c"
    break;

  case 126: /* Stmt: LET ID ':' Stmt_opt '=' FLOAT_LIT  */
#line 667 "compiler.y"
                                        { 

        printf("FLOAT_LIT %f\n",(yyvsp[0].f_val));
        CODEGEN("\tldc %f\n",(yyvsp[0].f_val));
        
        int index = insert_symbol((yyvsp[-4].s_val),"f32","-1");

    }
#line 2688 "y.tab.c"
    break;

  case 127: /* Stmt: LET ID ':' Stmt_opt '=' TRUE  */
#line 676 "compiler.y"
                                   {
        printf("bool TRUE\n");
        CODEGEN("\ticonst_1\n");;
        int index = insert_symbol((yyvsp[-4].s_val),"bool","-1");
    }
#line 2698 "y.tab.c"
    break;

  case 128: /* Stmt: LET ID ':' Stmt_opt '=' FALSE  */
#line 681 "compiler.y"
                                   {
        printf("bool FALSE\n");
        CODEGEN("\ticonst_0\n");
        int index = insert_symbol((yyvsp[-4].s_val),"bool","-1");
    }
#line 2708 "y.tab.c"
    break;

  case 129: /* Stmt: LET ID ':' Stmt_opt STR '=' '"' STRING_LIT '"'  */
#line 686 "compiler.y"
                                                       { 
        printf("STRING_LIT \"%s\"\n",(yyvsp[-1].s_val)); 
        CODEGEN("\tldc \"%s\"\n",(yyvsp[-1].s_val));
        int index = insert_symbol((yyvsp[-7].s_val),"str","-1");
        strcpy(str_saving,(yyvsp[-1].s_val));
    }
#line 2719 "y.tab.c"
    break;

  case 130: /* Stmt: LET ID ':' Stmt_opt STR '=' '"' '"'  */
#line 692 "compiler.y"
                                            { // 空字串
        printf("STRING_LIT \"\"\n"); 
        int index = insert_symbol((yyvsp[-6].s_val),"str","-1");
    }
#line 2728 "y.tab.c"
    break;

  case 131: /* Stmt: LET MUT ID ':' Stmt_opt '=' INT_LIT  */
#line 699 "compiler.y"
                                          {
        printf("INT_LIT %d\n",(yyvsp[0].i_val));
        CODEGEN("\tldc %d\n",(yyvsp[0].i_val));
        int index = insert_symbol((yyvsp[-4].s_val),"i32","1");
    }
#line 2738 "y.tab.c"
    break;

  case 132: /* Stmt: LET MUT ID ':' Stmt_opt '=' FLOAT_LIT  */
#line 704 "compiler.y"
                                            { 

        printf("FLOAT_LIT %f\n",(yyvsp[0].f_val));
        CODEGEN("\tldc %f\n",(yyvsp[0].f_val));
        int index = insert_symbol((yyvsp[-4].s_val),"f32","1");
    }
#line 2749 "y.tab.c"
    break;

  case 133: /* Stmt: LET MUT ID ':' Stmt_opt '=' TRUE  */
#line 710 "compiler.y"
                                       {
        printf("bool TRUE\n");
        CODEGEN("\ticonst_1\n");
        int index = insert_symbol((yyvsp[-4].s_val),"bool","1");
    }
#line 2759 "y.tab.c"
    break;

  case 134: /* Stmt: LET MUT ID ':' Stmt_opt '=' FALSE  */
#line 715 "compiler.y"
                                       {
        printf("bool FALSE\n");
        CODEGEN("\ticonst_0\n");
        int index = insert_symbol((yyvsp[-4].s_val),"bool","1");
    }
#line 2769 "y.tab.c"
    break;

  case 135: /* Stmt: LET MUT ID ':' Stmt_opt STR '=' '"' STRING_LIT '"'  */
#line 720 "compiler.y"
                                                           { 
        printf("STRING_LIT \"%s\"\n",(yyvsp[-1].s_val)); 
        CODEGEN("\tldc \"%s\"\n",(yyvsp[-1].s_val));
        int index = insert_symbol((yyvsp[-7].s_val),"str","1");
    }
#line 2779 "y.tab.c"
    break;

  case 136: /* Stmt: LET MUT ID ':' Stmt_opt STR '=' '"' '"'  */
#line 725 "compiler.y"
                                                { // 空字串
        printf("STRING_LIT \"\"\n"); 

        CODEGEN("\tldc \"\"\n");

        int index = insert_symbol((yyvsp[-6].s_val),"str","1");
    }
#line 2791 "y.tab.c"
    break;

  case 137: /* Stmt: LET MUT ID ':' Stmt_opt  */
#line 732 "compiler.y"
                              {
        if( type == 1 ){
            CODEGEN("\tldc %d\n",0);
            insert_symbol((yyvsp[-2].s_val),"i32","1");
        }
        if( type == 2 ){
            CODEGEN("\tldc %f\n",0.0);
            insert_symbol((yyvsp[-2].s_val),"f32","1");
        }
    }
#line 2806 "y.tab.c"
    break;

  case 138: /* Stmt: LET MUT ID '=' INT_LIT  */
#line 743 "compiler.y"
                             {
        printf("INT_LIT %d\n",(yyvsp[0].i_val));

        CODEGEN("\tldc %d\n",(yyvsp[0].i_val));
        insert_symbol((yyvsp[-2].s_val),"i32","1");
    }
#line 2817 "y.tab.c"
    break;

  case 139: /* Stmt: LET MUT ID '=' FLOAT_LIT  */
#line 749 "compiler.y"
                               {
        printf("FLOAT_LIT %f\n",(yyvsp[0].f_val));
        insert_symbol((yyvsp[-2].s_val),"f32","1");
    }
#line 2826 "y.tab.c"
    break;

  case 140: /* Stmt: LET ID '=' INT_LIT  */
#line 754 "compiler.y"
                        {
        printf("INT_LIT %d\n",(yyvsp[0].i_val));
        CODEGEN("\tldc %d\n",(yyvsp[0].i_val));
        insert_symbol((yyvsp[-2].s_val),"i32","-1");
    }
#line 2836 "y.tab.c"
    break;

  case 141: /* Stmt: LET ID '=' FLOAT_LIT  */
#line 759 "compiler.y"
                          {
        printf("FLOAT_LIT %f\n",(yyvsp[0].f_val));
        CODEGEN("\tldc %f\n",(yyvsp[0].f_val));
        insert_symbol((yyvsp[-2].s_val),"f32","-1");
    }
#line 2846 "y.tab.c"
    break;

  case 142: /* Stmt: LET ID '=' TRUE  */
#line 764 "compiler.y"
                      {
        printf("bool TRUE\n");
        CODEGEN("\ticonst_1\n");
        insert_symbol((yyvsp[-2].s_val),"bool","-1");
    }
#line 2856 "y.tab.c"
    break;

  case 143: /* Stmt: LET ID '=' FALSE  */
#line 769 "compiler.y"
                       {
        printf("bool FALSE\n");
        CODEGEN("\ticonst_0\n");
        insert_symbol((yyvsp[-2].s_val),"bool","-1");
    }
#line 2866 "y.tab.c"
    break;

  case 144: /* $@22: %empty  */
#line 775 "compiler.y"
                                       { 
        
        CODEGEN("ldc \"init\"\n");
        loop_break_address = insert_symbol((yyvsp[-5].s_val),"str","-1"); 
        CODEGEN("\tgoto loop_begin\n");
        CODEGEN("loop_begin:\n");
    
    }
#line 2879 "y.tab.c"
    break;

  case 146: /* Stmt: LET MUT ID ':' Stmt_opt STR '=' LOOP Block  */
#line 784 "compiler.y"
                                                 {  insert_symbol((yyvsp[-6].s_val),"str","1"); }
#line 2885 "y.tab.c"
    break;

  case 147: /* Stmt: LET ID ':' Stmt_opt STR '=' '&' ID '[' INT_LIT DOTDOT INT_LIT ']'  */
#line 787 "compiler.y"
        {  
            node_saving = lookup_symbol((yyvsp[-5].s_val),"1");
            printf("IDENT (name=%s, address=%d)\n",node_saving.name,node_saving.address);
            printf("INT_LIT %d\n",(yyvsp[-3].i_val));
            printf("DOTDOT\n");
            printf("INT_LIT %d\n",(yyvsp[-1].i_val));
            
            char u[100] = {};
            int idx = 0;
            for(int i=(yyvsp[-3].i_val);i<(yyvsp[-1].i_val);i++) u[idx++] = str_saving[i];

            CODEGEN("\tldc \"%s\"\n",u); 
            
            insert_symbol((yyvsp[-11].s_val),"str","-1"); 
        }
#line 2905 "y.tab.c"
    break;

  case 148: /* Stmt: LET ID ':' Stmt_opt STR '=' '&' ID '[' DOTDOT INT_LIT ']'  */
#line 803 "compiler.y"
        {   node_saving = lookup_symbol((yyvsp[-4].s_val),"1");
            printf("IDENT (name=%s, address=%d)\n",node_saving.name,node_saving.address);
            printf("DOTDOT\n");
            printf("INT_LIT %d\n",(yyvsp[-1].i_val));

            char u[100] = {};
            int idx = 0;
            for(int i=0;i<(yyvsp[-1].i_val);i++) u[idx++] = str_saving[i];
            CODEGEN("\tldc \"%s\"\n",u); 


            insert_symbol((yyvsp[-10].s_val),"str","-1"); 
        }
#line 2923 "y.tab.c"
    break;

  case 149: /* Stmt: LET ID ':' Stmt_opt STR '=' '&' ID '[' INT_LIT DOTDOT ']'  */
#line 817 "compiler.y"
        {   
            node_saving = lookup_symbol((yyvsp[-4].s_val),"1");
            printf("IDENT (name=%s, address=%d)\n",node_saving.name,node_saving.address);
            printf("INT_LIT %d\n",(yyvsp[-2].i_val));
            printf("DOTDOT\n");

            char u[100] = {};
            int idx = 0;
            for(int i=(yyvsp[-2].i_val);i<strlen(str_saving);i++) u[idx++] = str_saving[i];
            CODEGEN("\tldc \"%s\"\n",u); 

            insert_symbol((yyvsp[-10].s_val),"str","-1"); 
        }
#line 2941 "y.tab.c"
    break;

  case 150: /* Stmt_opt: INT  */
#line 832 "compiler.y"
          { type = 1; }
#line 2947 "y.tab.c"
    break;

  case 151: /* Stmt_opt: FLOAT  */
#line 833 "compiler.y"
            { type = 2; }
#line 2953 "y.tab.c"
    break;


#line 2957 "y.tab.c"

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

#line 839 "compiler.y"


/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }
    if (!yyin) {
        printf("file `%s` doesn't exists or cannot be opened\n", argv[1]);
        exit(1);
    }

    /* Codegen output init */
    char *bytecode_filename = "hw3.j";
    fout = fopen(bytecode_filename, "w");
    CODEGEN(".source hw3.j\n");
    CODEGEN(".class public Main\n");
    CODEGEN(".super java/lang/Object\n");
    CODEGEN(".method public static main([Ljava/lang/String;)V\n");
    CODEGEN(".limit stack 100 ; Define your storage size.\n");
    CODEGEN(".limit locals 100 ; Define your local space number.\n\n");

    /* Symbol table init */
    // Add your code

    yylineno = 0;
    yyparse();

    /* Symbol table dump */
    // Add your code
    CODEGEN("\treturn\n.end method\n");
	printf("Total lines: %d\n", yylineno);
    fclose(fout);
    fclose(yyin);

    if (HAS_ERROR) {
        remove(bytecode_filename);
    }

    yylex_destroy();
    return 0;
}

static void create_symbol() {
    cs_idx++;
    printf("> Create symbol table (scope level %d)\n", cs_idx );
}

static int insert_symbol(char* name, char* type, char* element_type) {
    
    NODE tmp = lookup_symbol(name, 0);
    if(tmp.address != -1){
        printf("error:%d: %s redeclared in this block. previous declaration at line %d\n", yylineno, name, tmp.lineno);
        return -1;
    }

    strcpy(table[cs_idx][table_len[cs_idx]].name, name);
    strcpy(table[cs_idx][table_len[cs_idx]].type, type);
    table[cs_idx][table_len[cs_idx]].address = address;
    table[cs_idx][table_len[cs_idx]].lineno = yylineno + 1;
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


    if( 0==strcmp(type, "str") ) CODEGEN("\tastore %d\n", address);
    else if( 0==strcmp(type, "i32") ) CODEGEN("\tistore %d\n", address);
    else if( 0==strcmp(type, "f32") ) CODEGEN("\tfstore %d\n", address);
    else if( 0==strcmp(type, "bool") ) CODEGEN("\tistore %d\n", address);

    if( strcmp(type,"func") != 0 ) address++;

    return address - 1;
}

static NODE lookup_symbol(char* name, int flag) {
    if(flag == 0){
        for(int j=0; j<table_len[cs_idx]; ++j){
            if(0 == strcmp(table[cs_idx][j].name, name))
                return table[cs_idx][j];
        }
        NODE node;
        node.address = -1;
        return node;
    }
    else{
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

void print_j(char *type,int newline) // newline = 要不要換行
{
    if( strcmp(type,"str") == 0 )
    {
        if( newline == 1 ) CODEGEN("\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n\n");
        else CODEGEN("\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n\n");
    }
    if( strcmp(type,"i32") == 0 )
    {
        if( newline == 1 ) CODEGEN("\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(I)V\n\n");
        else CODEGEN("\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/print(I)V\n\n");
    }
    if( strcmp(type,"f32") == 0 )
    {
        if( newline == 1 ) CODEGEN("\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(F)V\n\n");
        else CODEGEN("\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/print(F)V\n\n");
    }
    if( strcmp(type,"bool") == 0 )
    {
        CODEGEN("\tifne L%d_cmp_0\n", cmp_num); // ifne = if not equal to 0
        CODEGEN("\tldc \"false\"\n");
        CODEGEN("\tgoto L%d_cmp_1\n", cmp_num);
        CODEGEN("L%d_cmp_0:\n", cmp_num);
        CODEGEN("\tldc \"true\"\n");
        CODEGEN("L%d_cmp_1:\n", cmp_num);
        
        if( newline == 1 ) CODEGEN("\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n\n");
        else CODEGEN("\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n\n");
        cmp_num++;
    }
}
