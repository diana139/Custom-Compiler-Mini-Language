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
#line 12 "limbaj.y"

#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <vector>
#include "AST.h"  

#include "SymTable.h"



using namespace std;
vector<ASTNode*> mainBlockASTs;
vector<ASTNode*> globalInitASTs; 

SymTable* globalTable = nullptr;
SymTable* currentClassTable = nullptr;
SymTable* currentScope = nullptr;
string currentExpectedReturnType = "";
int errorCount = 0;

extern FILE* yyin;
extern int yylineno;
extern int yylex();
void yyerror(const char * s);

#line 99 "y.tab.c"

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
/* "%code requires" blocks.  */
#line 1 "limbaj.y"

 
    #include <string>
    #include <vector>
#include "SymTable.h"
    extern SymTable* globalTable;
    extern SymTable* currentClassTable;
    extern SymTable* currentScope;
    extern int errorCount;

#line 145 "y.tab.c"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NEW = 258,                     /* NEW  */
    NR_INT = 259,                  /* NR_INT  */
    NR_FLOAT = 260,                /* NR_FLOAT  */
    STRING_VAL = 261,              /* STRING_VAL  */
    ID = 262,                      /* ID  */
    TYPE = 263,                    /* TYPE  */
    BOOL_VAL = 264,                /* BOOL_VAL  */
    CLASS = 265,                   /* CLASS  */
    FUNCTION = 266,                /* FUNCTION  */
    RETURN = 267,                  /* RETURN  */
    IF = 268,                      /* IF  */
    WHILE = 269,                   /* WHILE  */
    PRINT = 270,                   /* PRINT  */
    BGIN = 271,                    /* BGIN  */
    END = 272,                     /* END  */
    PUBLIC = 273,                  /* PUBLIC  */
    PRIVATE = 274,                 /* PRIVATE  */
    PROTECTED = 275,               /* PROTECTED  */
    FOR = 276,                     /* FOR  */
    ELSE = 277,                    /* ELSE  */
    ASSIGN = 278,                  /* ASSIGN  */
    TRUE = 279,                    /* TRUE  */
    FALSE = 280,                   /* FALSE  */
    EQ = 281,                      /* EQ  */
    NEQ = 282,                     /* NEQ  */
    LT = 283,                      /* LT  */
    GT = 284,                      /* GT  */
    LE = 285,                      /* LE  */
    GE = 286,                      /* GE  */
    OR = 287,                      /* OR  */
    AND = 288,                     /* AND  */
    NOT = 289,                     /* NOT  */
    LOWER_THAN_ELSE = 290,         /* LOWER_THAN_ELSE  */
    UMINUS = 291                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NEW 258
#define NR_INT 259
#define NR_FLOAT 260
#define STRING_VAL 261
#define ID 262
#define TYPE 263
#define BOOL_VAL 264
#define CLASS 265
#define FUNCTION 266
#define RETURN 267
#define IF 268
#define WHILE 269
#define PRINT 270
#define BGIN 271
#define END 272
#define PUBLIC 273
#define PRIVATE 274
#define PROTECTED 275
#define FOR 276
#define ELSE 277
#define ASSIGN 278
#define TRUE 279
#define FALSE 280
#define EQ 281
#define NEQ 282
#define LT 283
#define GT 284
#define LE 285
#define GE 286
#define OR 287
#define AND 288
#define NOT 289
#define LOWER_THAN_ELSE 290
#define UMINUS 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 41 "limbaj.y"

    int Int;
    float Float;
    char* Str;
    bool BoolVal;
    const char* TypeName;
    std::string* Id;
    struct {
        std::vector<std::string>* list;
    } StrList;
    struct {
        std::vector<std::pair<std::string, std::string>>* params;
    } ParamList;
    struct {
        SymTable* table;
    } Scope;
    struct {
        std::vector<ASTNode*>* nodes;  
    } AstList;
    ASTNode* astNode;

#line 259 "y.tab.c"

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
  YYSYMBOL_NEW = 3,                        /* NEW  */
  YYSYMBOL_NR_INT = 4,                     /* NR_INT  */
  YYSYMBOL_NR_FLOAT = 5,                   /* NR_FLOAT  */
  YYSYMBOL_STRING_VAL = 6,                 /* STRING_VAL  */
  YYSYMBOL_ID = 7,                         /* ID  */
  YYSYMBOL_TYPE = 8,                       /* TYPE  */
  YYSYMBOL_BOOL_VAL = 9,                   /* BOOL_VAL  */
  YYSYMBOL_CLASS = 10,                     /* CLASS  */
  YYSYMBOL_FUNCTION = 11,                  /* FUNCTION  */
  YYSYMBOL_RETURN = 12,                    /* RETURN  */
  YYSYMBOL_IF = 13,                        /* IF  */
  YYSYMBOL_WHILE = 14,                     /* WHILE  */
  YYSYMBOL_PRINT = 15,                     /* PRINT  */
  YYSYMBOL_BGIN = 16,                      /* BGIN  */
  YYSYMBOL_END = 17,                       /* END  */
  YYSYMBOL_PUBLIC = 18,                    /* PUBLIC  */
  YYSYMBOL_PRIVATE = 19,                   /* PRIVATE  */
  YYSYMBOL_PROTECTED = 20,                 /* PROTECTED  */
  YYSYMBOL_FOR = 21,                       /* FOR  */
  YYSYMBOL_ELSE = 22,                      /* ELSE  */
  YYSYMBOL_ASSIGN = 23,                    /* ASSIGN  */
  YYSYMBOL_TRUE = 24,                      /* TRUE  */
  YYSYMBOL_FALSE = 25,                     /* FALSE  */
  YYSYMBOL_EQ = 26,                        /* EQ  */
  YYSYMBOL_NEQ = 27,                       /* NEQ  */
  YYSYMBOL_LT = 28,                        /* LT  */
  YYSYMBOL_GT = 29,                        /* GT  */
  YYSYMBOL_LE = 30,                        /* LE  */
  YYSYMBOL_GE = 31,                        /* GE  */
  YYSYMBOL_OR = 32,                        /* OR  */
  YYSYMBOL_AND = 33,                       /* AND  */
  YYSYMBOL_NOT = 34,                       /* NOT  */
  YYSYMBOL_LOWER_THAN_ELSE = 35,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_36_ = 36,                       /* '+'  */
  YYSYMBOL_37_ = 37,                       /* '-'  */
  YYSYMBOL_38_ = 38,                       /* '*'  */
  YYSYMBOL_39_ = 39,                       /* '/'  */
  YYSYMBOL_40_ = 40,                       /* '%'  */
  YYSYMBOL_41_ = 41,                       /* '.'  */
  YYSYMBOL_UMINUS = 42,                    /* UMINUS  */
  YYSYMBOL_43_ = 43,                       /* ';'  */
  YYSYMBOL_44_ = 44,                       /* ','  */
  YYSYMBOL_45_ = 45,                       /* '('  */
  YYSYMBOL_46_ = 46,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_progr = 48,                     /* progr  */
  YYSYMBOL_49_1 = 49,                      /* $@1  */
  YYSYMBOL_50_2 = 50,                      /* $@2  */
  YYSYMBOL_global_definitions = 51,        /* global_definitions  */
  YYSYMBOL_global_decl_var = 52,           /* global_decl_var  */
  YYSYMBOL_vars = 53,                      /* vars  */
  YYSYMBOL_class_def = 54,                 /* class_def  */
  YYSYMBOL_55_3 = 55,                      /* $@3  */
  YYSYMBOL_class_body = 56,                /* class_body  */
  YYSYMBOL_access_modifier = 57,           /* access_modifier  */
  YYSYMBOL_class_members = 58,             /* class_members  */
  YYSYMBOL_class_member_list = 59,         /* class_member_list  */
  YYSYMBOL_class_member = 60,              /* class_member  */
  YYSYMBOL_constructor_def = 61,           /* constructor_def  */
  YYSYMBOL_class_field = 62,               /* class_field  */
  YYSYMBOL_class_method = 63,              /* class_method  */
  YYSYMBOL_64_4 = 64,                      /* $@4  */
  YYSYMBOL_func_def = 65,                  /* func_def  */
  YYSYMBOL_66_5 = 66,                      /* $@5  */
  YYSYMBOL_67_6 = 67,                      /* $@6  */
  YYSYMBOL_func_name = 68,                 /* func_name  */
  YYSYMBOL_func_block = 69,                /* func_block  */
  YYSYMBOL_func_item = 70,                 /* func_item  */
  YYSYMBOL_id_start_item = 71,             /* id_start_item  */
  YYSYMBOL_list_param = 72,                /* list_param  */
  YYSYMBOL_param_list = 73,                /* param_list  */
  YYSYMBOL_param = 74,                     /* param  */
  YYSYMBOL_main_block = 75,                /* main_block  */
  YYSYMBOL_76_7 = 76,                      /* $@7  */
  YYSYMBOL_simple_stmt = 77,               /* simple_stmt  */
  YYSYMBOL_control_stmt = 78,              /* control_stmt  */
  YYSYMBOL_expr = 79,                      /* expr  */
  YYSYMBOL_expr_bool = 80,                 /* expr_bool  */
  YYSYMBOL_stmt_list_ast = 81,             /* stmt_list_ast  */
  YYSYMBOL_statement_ast = 82,             /* statement_ast  */
  YYSYMBOL_ast_simple_stmt = 83,           /* ast_simple_stmt  */
  YYSYMBOL_ast_expr = 84,                  /* ast_expr  */
  YYSYMBOL_comp = 85,                      /* comp  */
  YYSYMBOL_call_list = 86,                 /* call_list  */
  YYSYMBOL_call_list_ast = 87,             /* call_list_ast  */
  YYSYMBOL_block_stmts = 88                /* block_stmts  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   495

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  145
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  313

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
       2,     2,     2,     2,     2,     2,     2,    40,     2,     2,
      45,    46,    38,    36,    44,    37,    41,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
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
      35,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   104,   104,   110,   104,   132,   133,   134,   135,   139,
     152,   168,   187,   204,   232,   253,   278,   283,   292,   291,
     306,   307,   311,   311,   311,   315,   319,   320,   324,   325,
     326,   329,   332,   349,   373,   372,   399,   398,   414,   413,
     428,   433,   434,   438,   447,   467,   468,   469,   478,   489,
     500,   517,   533,   548,   565,   594,   641,   645,   648,   654,
     657,   665,   671,   680,   680,   702,   715,   724,   746,   767,
     768,   769,   770,   798,   799,   800,   801,   805,   818,   826,
     834,   842,   850,   858,   859,   860,   861,   862,   873,   893,
     923,   952,   953,   954,   962,   963,   964,   965,   969,   970,
     975,   978,   981,   997,  1006,  1027,  1052,  1087,  1092,  1100,
    1104,  1108,  1113,  1117,  1122,  1131,  1140,  1149,  1158,  1167,
    1176,  1182,  1203,  1244,  1264,  1274,  1284,  1294,  1304,  1314,
    1317,  1327,  1337,  1350,  1350,  1350,  1350,  1350,  1350,  1353,
    1356,  1360,  1366,  1369,  1373,  1379
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
  "\"end of file\"", "error", "\"invalid token\"", "NEW", "NR_INT",
  "NR_FLOAT", "STRING_VAL", "ID", "TYPE", "BOOL_VAL", "CLASS", "FUNCTION",
  "RETURN", "IF", "WHILE", "PRINT", "BGIN", "END", "PUBLIC", "PRIVATE",
  "PROTECTED", "FOR", "ELSE", "ASSIGN", "TRUE", "FALSE", "EQ", "NEQ", "LT",
  "GT", "LE", "GE", "OR", "AND", "NOT", "LOWER_THAN_ELSE", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'.'", "UMINUS", "';'", "','", "'('", "')'",
  "$accept", "progr", "$@1", "$@2", "global_definitions",
  "global_decl_var", "vars", "class_def", "$@3", "class_body",
  "access_modifier", "class_members", "class_member_list", "class_member",
  "constructor_def", "class_field", "class_method", "$@4", "func_def",
  "$@5", "$@6", "func_name", "func_block", "func_item", "id_start_item",
  "list_param", "param_list", "param", "main_block", "$@7", "simple_stmt",
  "control_stmt", "expr", "expr_bool", "stmt_list_ast", "statement_ast",
  "ast_simple_stmt", "ast_expr", "comp", "call_list", "call_list_ast",
  "block_stmts", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-182)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -182,    12,  -182,  -182,   147,    30,    58,    61,    40,    57,
    -182,  -182,  -182,    43,    60,    82,  -182,    98,    98,  -182,
    -182,  -182,    11,  -182,   106,   118,  -182,    91,    94,  -182,
      99,   127,   134,   155,   171,  -182,  -182,   178,   178,   204,
    -182,  -182,  -182,  -182,  -182,     3,   152,   187,   161,   185,
    -182,   236,   -15,   282,   175,   257,   258,   264,  -182,   265,
    -182,  -182,   277,  -182,  -182,  -182,  -182,  -182,  -182,  -182,
    -182,   178,  -182,   116,   314,   305,   180,  -182,  -182,  -182,
      59,  -182,  -182,   175,   175,   322,   168,   168,   175,    34,
    -182,  -182,    32,   311,  -182,   320,   330,   322,   315,   175,
    -182,   332,   175,  -182,   205,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,  -182,  -182,
    -182,   123,  -182,  -182,   168,   139,   168,   352,   -19,    38,
     226,   -13,   168,   300,   303,   349,   350,   232,  -182,  -182,
    -182,  -182,  -182,  -182,   324,   175,   268,   326,   322,    64,
    -182,   439,   439,   210,   210,   210,   210,   337,   367,   188,
     188,  -182,  -182,  -182,   365,   139,  -182,   139,  -182,   247,
      42,  -182,  -182,  -182,  -182,  -182,  -182,   139,   139,   139,
     139,   139,   139,   168,   168,   368,   368,  -182,    90,   378,
     139,   352,   228,   139,   168,   343,  -182,   248,   342,    98,
     401,   412,   353,   322,  -182,   175,   175,  -182,   355,   231,
     105,   151,  -182,  -182,   241,   241,  -182,  -182,  -182,   231,
     369,  -182,  -182,   379,  -182,   403,   352,   228,   388,   121,
     444,    66,  -182,  -182,   366,   372,    62,   414,   168,   383,
    -182,  -182,   380,  -182,  -182,  -182,   157,   322,   139,   139,
    -182,   423,   368,   387,   139,  -182,  -182,    34,   418,   178,
     416,   126,   436,   139,    -5,   304,    85,   139,  -182,  -182,
     160,   231,  -182,  -182,   399,   231,   404,  -182,   408,   139,
     454,   231,   -12,   164,   175,  -182,  -182,  -182,   449,  -182,
    -182,   368,   434,  -182,   231,   411,   139,   139,  -182,   286,
    -182,  -182,  -182,   447,   419,   231,   244,  -182,  -182,  -182,
    -182,   445,  -182
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     5,     1,     3,     0,     0,     0,     0,     0,
       6,     7,     8,     0,    16,     0,    18,     0,     0,    63,
       4,    10,     0,     9,     0,     0,    40,     0,     0,    98,
       0,     0,     0,     0,     0,    17,    20,    57,    57,     0,
      11,    12,    13,    14,    15,     0,     0,     0,     0,    58,
      59,     0,     0,     0,     0,     0,     0,     0,    64,     0,
     101,    99,     0,    19,    22,    23,    24,    26,    62,    61,
      38,     0,    36,     0,     0,    16,     0,   109,   110,   111,
     120,   112,   113,     0,     0,   108,     0,     0,     0,     0,
     100,    21,    25,     0,    60,     0,     0,   105,     0,     0,
     103,     0,   142,   132,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,    85,
      86,    87,    91,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,    30,
      28,    29,    41,    41,     0,     0,     0,   123,   143,     0,
     129,   116,   117,   115,   114,   119,   118,   131,   130,   124,
     125,   126,   127,   128,     0,   139,    96,     0,    77,     0,
       0,   133,   138,   137,   136,   134,   135,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   107,     0,     0,
     139,    69,    70,     0,     0,     0,    16,     0,     0,     0,
       0,     0,     0,   106,   102,   142,     0,   122,    88,   140,
       0,     0,    83,    97,    78,    79,    80,    81,    82,    93,
      95,    94,    98,    73,    75,     0,    65,    66,     0,     0,
       0,     0,    33,    32,     0,     0,     0,     0,     0,     0,
      39,    42,     0,    45,    37,   104,     0,   144,   139,     0,
      90,     0,     0,     0,     0,    72,    71,     0,     0,    57,
      49,     0,     0,   139,     0,     0,     0,     0,    46,   121,
       0,   141,   145,    74,     0,    68,     0,    41,     0,     0,
       0,    51,     0,     0,     0,    43,    47,    48,     0,    89,
      67,     0,     0,    34,    50,     0,     0,   139,    54,     0,
      56,    76,    31,     0,     0,    53,     0,    44,    41,    52,
      55,     0,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -182,  -182,  -182,  -182,  -182,  -182,   -46,  -182,  -182,  -182,
    -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,
    -182,   -16,  -139,  -182,  -182,   -37,  -182,   393,  -182,  -182,
     214,   -36,  -101,   -82,   250,  -182,  -182,   -54,  -182,  -181,
     269,  -180
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,     9,     4,    10,    15,    11,    25,    45,
      67,    91,    92,   138,   139,   140,   141,   303,    12,    95,
      93,    27,   200,   241,   242,    48,    49,    50,    20,    29,
     134,   243,   127,   128,    39,    61,    62,   148,   182,   210,
     149,   223
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      85,    51,    28,    60,   201,   129,   224,    76,    73,   229,
     188,   296,     3,   183,   184,    30,    31,    32,   284,    97,
      63,    64,    65,    66,   168,   169,    74,   185,   189,   103,
     104,   191,   190,   297,   130,    33,    34,    13,   285,   135,
     136,   131,   166,   137,   170,   146,   132,    17,    18,   133,
     192,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   209,    14,   211,   270,    16,   260,
     183,   184,   273,    19,   183,   184,   214,   215,   216,   217,
     218,   219,   283,    22,   186,   261,    21,   226,   213,   209,
     197,   203,   230,   225,   118,   119,   120,   121,   183,   184,
     101,   220,   221,   262,   102,    26,   227,   263,   206,   257,
     207,   301,   231,    35,   122,   123,   306,   183,   184,    96,
      77,    78,    79,    80,   124,    23,    24,   125,   287,   280,
     118,   119,   120,   121,    36,   126,    37,   265,   292,    38,
      81,    82,    40,   118,   119,   120,   121,   209,   271,   249,
      83,   250,   247,   275,     5,     6,   266,     7,     8,    68,
     281,    84,   209,   125,   164,   249,   288,   255,   165,   311,
      41,   167,   118,   119,   120,   121,   125,    42,   294,    77,
      78,    79,    80,   235,   167,    46,    47,   177,   178,   179,
     180,   181,   122,   123,    69,   305,   209,   212,    43,    81,
      82,   206,   124,   269,   249,   125,   289,    70,   249,    83,
     298,    52,    53,   126,    44,    60,    54,    55,    56,    57,
      84,    58,   278,   100,    24,    59,   115,   116,   117,    71,
     299,   105,   106,   107,   108,   109,   110,   111,   112,   198,
     199,   113,   114,   115,   116,   117,   113,   114,   115,   116,
     117,   150,   105,   106,   107,   108,   109,   110,   111,   112,
     183,   184,   113,   114,   115,   116,   117,   177,   178,   179,
     180,   181,   187,   171,   172,   173,   174,   175,   176,   179,
     180,   181,    72,   177,   178,   179,   180,   181,   249,    75,
     310,   233,    24,   212,   105,   106,   107,   108,   109,   110,
     111,   112,    86,    87,   113,   114,   115,   116,   117,    88,
      89,   204,   105,   106,   107,   108,   109,   110,   111,   112,
      90,    98,   113,   114,   115,   116,   117,   142,    99,   307,
     171,   172,   173,   174,   175,   176,   143,   144,   145,   147,
     177,   178,   179,   180,   181,   193,   194,   286,   105,   106,
     107,   108,   109,   110,   111,   112,   195,   196,   113,   114,
     115,   116,   117,   105,   106,   107,   108,   109,   110,   202,
     112,   205,   208,   113,   114,   115,   116,   117,   171,   172,
     173,   174,   175,   176,   222,   228,   232,   234,   177,   178,
     179,   180,   181,   105,   106,   107,   108,   109,   110,   245,
     248,   252,   184,   113,   114,   115,   116,   117,   236,   237,
     253,   254,   258,   238,    55,    56,   239,   259,   240,   236,
     237,   264,    59,   268,   238,    55,    56,   239,   267,   244,
      52,    53,   274,    59,   277,    54,    55,    56,    57,   279,
     272,   236,   237,   282,    59,   290,   238,    55,    56,   239,
     291,   302,   236,   237,   293,    59,   304,   238,    55,    56,
     239,   295,   312,   308,    94,   309,    59,   107,   108,   109,
     110,   276,   251,     0,   246,   113,   114,   115,   116,   117,
     177,   178,   179,   180,   181,   177,   178,   179,   180,   181,
     256,     0,     0,     0,     0,   300
};

static const yytype_int16 yycheck[] =
{
      54,    38,    18,    39,   143,    87,   186,    53,    23,   190,
      23,    23,     0,    32,    33,     4,     5,     6,    23,    73,
      17,    18,    19,    20,   125,   126,    41,    46,    41,    83,
      84,   132,    45,    45,    88,    24,    25,     7,    43,     7,
       8,     7,   124,    11,   126,    99,    12,     7,     8,    15,
     132,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   165,     7,   167,   248,     7,     7,
      32,    33,   252,    16,    32,    33,   177,   178,   179,   180,
     181,   182,   263,    23,    46,    23,    43,   188,    46,   190,
     136,   145,   193,     3,     4,     5,     6,     7,    32,    33,
      41,   183,   184,    41,    45,     7,   188,    45,    44,    43,
      46,   291,   194,     7,    24,    25,   297,    32,    33,     3,
       4,     5,     6,     7,    34,    43,    44,    37,    43,     3,
       4,     5,     6,     7,    16,    45,    45,   238,   277,    45,
      24,    25,    43,     4,     5,     6,     7,   248,   249,    44,
      34,    46,   206,   254,     7,     8,   238,    10,    11,     7,
     261,    45,   263,    37,    41,    44,   267,    46,    45,   308,
      43,    45,     4,     5,     6,     7,    37,    43,   279,     4,
       5,     6,     7,   199,    45,     7,     8,    36,    37,    38,
      39,    40,    24,    25,     7,   296,   297,    46,    43,    24,
      25,    44,    34,    46,    44,    37,    46,    46,    44,    34,
      46,     7,     8,    45,    43,   251,    12,    13,    14,    15,
      45,    17,   259,    43,    44,    21,    38,    39,    40,    44,
     284,    26,    27,    28,    29,    30,    31,    32,    33,     7,
       8,    36,    37,    38,    39,    40,    36,    37,    38,    39,
      40,    46,    26,    27,    28,    29,    30,    31,    32,    33,
      32,    33,    36,    37,    38,    39,    40,    36,    37,    38,
      39,    40,    46,    26,    27,    28,    29,    30,    31,    38,
      39,    40,    46,    36,    37,    38,    39,    40,    44,     7,
      46,    43,    44,    46,    26,    27,    28,    29,    30,    31,
      32,    33,    45,    45,    36,    37,    38,    39,    40,    45,
      45,    43,    26,    27,    28,    29,    30,    31,    32,    33,
      43,     7,    36,    37,    38,    39,    40,    16,    23,    43,
      26,    27,    28,    29,    30,    31,    16,     7,    23,     7,
      36,    37,    38,    39,    40,    45,    43,    43,    26,    27,
      28,    29,    30,    31,    32,    33,     7,     7,    36,    37,
      38,    39,    40,    26,    27,    28,    29,    30,    31,    45,
      33,    45,     7,    36,    37,    38,    39,    40,    26,    27,
      28,    29,    30,    31,    16,     7,    43,    45,    36,    37,
      38,    39,    40,    26,    27,    28,    29,    30,    31,    46,
      45,    22,    33,    36,    37,    38,    39,    40,     7,     8,
       7,    23,    46,    12,    13,    14,    15,    45,    17,     7,
       8,     7,    21,    43,    12,    13,    14,    15,    45,    17,
       7,     8,    45,    21,    16,    12,    13,    14,    15,    23,
      17,     7,     8,     7,    21,    46,    12,    13,    14,    15,
      46,    17,     7,     8,    46,    21,    45,    12,    13,    14,
      15,     7,    17,    16,    71,    46,    21,    28,    29,    30,
      31,   257,   222,    -1,   205,    36,    37,    38,    39,    40,
      36,    37,    38,    39,    40,    36,    37,    38,    39,    40,
      46,    -1,    -1,    -1,    -1,    46
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    48,    49,     0,    51,     7,     8,    10,    11,    50,
      52,    54,    65,     7,     7,    53,     7,     7,     8,    16,
      75,    43,    23,    43,    44,    55,     7,    68,    68,    76,
       4,     5,     6,    24,    25,     7,    16,    45,    45,    81,
      43,    43,    43,    43,    43,    56,     7,     8,    72,    73,
      74,    72,     7,     8,    12,    13,    14,    15,    17,    21,
      78,    82,    83,    17,    18,    19,    20,    57,     7,     7,
      46,    44,    46,    23,    41,     7,    53,     4,     5,     6,
       7,    24,    25,    34,    45,    84,    45,    45,    45,    45,
      43,    58,    59,    67,    74,    66,     3,    84,     7,    23,
      43,    41,    45,    84,    84,    26,    27,    28,    29,    30,
      31,    32,    33,    36,    37,    38,    39,    40,     4,     5,
       6,     7,    24,    25,    34,    37,    45,    79,    80,    80,
      84,     7,    12,    15,    77,     7,     8,    11,    60,    61,
      62,    63,    16,    16,     7,    23,    84,     7,    84,    87,
      46,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    41,    45,    80,    45,    79,    79,
      80,    26,    27,    28,    29,    30,    31,    36,    37,    38,
      39,    40,    85,    32,    33,    46,    46,    46,    23,    41,
      45,    79,    80,    45,    43,     7,     7,    53,     7,     8,
      69,    69,    45,    84,    43,    45,    44,    46,     7,    79,
      86,    79,    46,    46,    79,    79,    79,    79,    79,    79,
      80,    80,    16,    88,    88,     3,    79,    80,     7,    86,
      79,    80,    43,    43,    45,    68,     7,     8,    12,    15,
      17,    70,    71,    78,    17,    46,    87,    84,    45,    44,
      46,    81,    22,     7,    23,    46,    46,    43,    46,    45,
       7,    23,    41,    45,     7,    79,    80,    45,    43,    46,
      86,    79,    17,    88,    45,    79,    77,    16,    72,    23,
       3,    79,     7,    86,    23,    43,    43,    43,    79,    46,
      46,    46,    69,    46,    79,     7,    23,    45,    46,    84,
      46,    88,    17,    64,    45,    79,    86,    43,    16,    46,
      46,    69,    17
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    49,    50,    48,    51,    51,    51,    51,    52,
      52,    52,    52,    52,    52,    52,    53,    53,    55,    54,
      56,    56,    57,    57,    57,    58,    59,    59,    60,    60,
      60,    61,    62,    62,    64,    63,    66,    65,    67,    65,
      68,    69,    69,    70,    70,    70,    70,    70,    70,    71,
      71,    71,    71,    71,    71,    71,    71,    72,    72,    73,
      73,    74,    74,    76,    75,    77,    77,    77,    77,    77,
      77,    77,    77,    78,    78,    78,    78,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    80,    80,    80,    80,    80,    80,    80,    81,    81,
      82,    82,    82,    82,    83,    83,    83,    83,    83,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    85,    85,    85,    85,    85,    85,    86,
      86,    86,    87,    87,    87,    88
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     4,     0,     2,     2,     2,     3,
       3,     5,     5,     5,     5,     5,     1,     3,     0,     6,
       0,     3,     1,     1,     1,     1,     0,     2,     1,     1,
       1,     7,     3,     3,     0,    10,     0,    10,     0,    10,
       1,     0,     2,     3,     5,     1,     2,     3,     3,     2,
       4,     3,     6,     5,     4,     6,     4,     0,     1,     1,
       3,     2,     2,     0,     4,     3,     3,     6,     5,     2,
       2,     4,     4,     5,     7,     5,     9,     2,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     3,     6,
       4,     1,     1,     3,     3,     3,     2,     3,     0,     2,
       2,     1,     5,     3,     6,     3,     5,     4,     2,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       1,     6,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     1,     1,     1,     1,     1,     1,     0,
       1,     3,     0,     1,     3,     3
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
  case 2: /* $@1: %empty  */
#line 104 "limbaj.y"
      { 
        globalTable = new SymTable("Global", nullptr);
        currentScope = globalTable;
        globalInitASTs.clear();  // <-- ADAUGĂ
      }
#line 1574 "y.tab.c"
    break;

  case 3: /* $@2: %empty  */
#line 110 "limbaj.y"
      {
        cout << "\n========== INITIALIZING GLOBALS ==========\n";
        for(auto ast : globalInitASTs) {
            if(ast) ast->evaluate(globalTable);
        }
        cout << "========== END INITIALIZATION ==========\n\n";
      }
#line 1586 "y.tab.c"
    break;

  case 4: /* progr: $@1 global_definitions $@2 main_block  */
#line 118 "limbaj.y"
      {
        if (errorCount == 0) {
            cout << "Program corect sintactic si semantic!" << endl;
        }
        
        ofstream outFile("tables.txt");
        if(outFile.is_open()) {
            globalTable->printTable(outFile);
            outFile.close();
            cout << "Symbol tables written to tables.txt (post-execution)" << endl;
        }
      }
#line 1603 "y.tab.c"
    break;

  case 9: /* global_decl_var: TYPE vars ';'  */
#line 139 "limbaj.y"
                    {
        for(auto& id : *(yyvsp[-1].StrList).list) {
            if(globalTable->existsLocal(id)) {
                char errMsg[256];
                sprintf(errMsg, "Semantic Error: Variable '%s' already declared in this scope", id.c_str());
                yyerror(errMsg);
            } else {
                globalTable->addVariable(*(yyvsp[-2].Id), id, GenericValue());  
            }
        }
        delete (yyvsp[-1].StrList).list;
        delete (yyvsp[-2].Id);
    }
#line 1621 "y.tab.c"
    break;

  case 10: /* global_decl_var: ID ID ';'  */
#line 152 "limbaj.y"
                {
        if(!globalTable->classExists(*(yyvsp[-2].Id))) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Type '%s' not declared", (yyvsp[-2].Id)->c_str());
            yyerror(errMsg);
        }
        if(globalTable->existsLocal(*(yyvsp[-1].Id))) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Variable '%s' already declared", (yyvsp[-1].Id)->c_str());
            yyerror(errMsg);
        } else {
            globalTable->addVariable(*(yyvsp[-2].Id), *(yyvsp[-1].Id), GenericValue());  
        }
        delete (yyvsp[-2].Id);
        delete (yyvsp[-1].Id);
    }
#line 1642 "y.tab.c"
    break;

  case 11: /* global_decl_var: TYPE ID ASSIGN NR_INT ';'  */
#line 168 "limbaj.y"
                                {  
        if(!globalTable->existsLocal(*(yyvsp[-3].Id))) {
            globalTable->addVariable(*(yyvsp[-4].Id), *(yyvsp[-3].Id), GenericValue());
        }
        
        ASTNode* idNode = new ASTNode(*(yyvsp[-3].Id), "ID");
        idNode->expressionType = *(yyvsp[-4].Id);
        
        ASTNode* valNode = new ASTNode(to_string((yyvsp[-1].Int)), "LITERAL");
        valNode->expressionType = "int";
        
        ASTNode* assignNode = new ASTNode("<-", "STATEMENT", idNode, valNode);
        assignNode->expressionType = "void";
        
        globalInitASTs.push_back(assignNode);
        
        delete (yyvsp[-4].Id);
        delete (yyvsp[-3].Id);
    }
#line 1666 "y.tab.c"
    break;

  case 12: /* global_decl_var: TYPE ID ASSIGN NR_FLOAT ';'  */
#line 187 "limbaj.y"
                                  {
        if(!globalTable->existsLocal(*(yyvsp[-3].Id))) {
            globalTable->addVariable(*(yyvsp[-4].Id), *(yyvsp[-3].Id), GenericValue());
        }
        
        ASTNode* idNode = new ASTNode(*(yyvsp[-3].Id), "ID");
        idNode->expressionType = *(yyvsp[-4].Id);
        
        ASTNode* valNode = new ASTNode(to_string((yyvsp[-1].Float)), "LITERAL");
        valNode->expressionType = "float";
        
        ASTNode* assignNode = new ASTNode("<-", "STATEMENT", idNode, valNode);
        globalInitASTs.push_back(assignNode);
        
        delete (yyvsp[-4].Id);
        delete (yyvsp[-3].Id);
    }
#line 1688 "y.tab.c"
    break;

  case 13: /* global_decl_var: TYPE ID ASSIGN STRING_VAL ';'  */
#line 204 "limbaj.y"
                                    {
        if(!globalTable->existsLocal(*(yyvsp[-3].Id))) {
            string strVal = string((yyvsp[-1].Str));
            if(strVal.length() >= 2 && strVal[0] == '"' && 
               strVal[strVal.length()-1] == '"') {
                strVal = strVal.substr(1, strVal.length()-2);
            }
            
            GenericValue val(strVal);
            val.type = *(yyvsp[-4].Id);
            
            globalTable->addVariable(*(yyvsp[-4].Id), *(yyvsp[-3].Id), val);
            
            ASTNode* idNode = new ASTNode(*(yyvsp[-3].Id), "ID");
            idNode->expressionType = *(yyvsp[-4].Id);
            
            ASTNode* valNode = new ASTNode(strVal, "LITERAL");
            valNode->expressionType = "string";
            
            ASTNode* assignNode = new ASTNode("<-", "STATEMENT", idNode, valNode);
            assignNode->expressionType = "void";
            
            globalInitASTs.push_back(assignNode);
        }
        delete (yyvsp[-4].Id);
        delete (yyvsp[-3].Id);
        free((yyvsp[-1].Str));
    }
#line 1721 "y.tab.c"
    break;

  case 14: /* global_decl_var: TYPE ID ASSIGN TRUE ';'  */
#line 232 "limbaj.y"
                              {
    if(!globalTable->existsLocal(*(yyvsp[-3].Id))) {
        GenericValue val(true);
        val.type = *(yyvsp[-4].Id);
        globalTable->addVariable(*(yyvsp[-4].Id), *(yyvsp[-3].Id), val);
             cout<< "' = true" << endl;
        
        ASTNode* idNode = new ASTNode(*(yyvsp[-3].Id), "ID");
        idNode->expressionType = *(yyvsp[-4].Id);
        
        ASTNode* valNode = new ASTNode("true", "LITERAL");
        valNode->expressionType = "bool";
        
        ASTNode* assignNode = new ASTNode("<-", "STATEMENT", idNode, valNode);
        assignNode->expressionType = "void";
        
        globalInitASTs.push_back(assignNode);
    }
    delete (yyvsp[-4].Id);
    delete (yyvsp[-3].Id);
}
#line 1747 "y.tab.c"
    break;

  case 15: /* global_decl_var: TYPE ID ASSIGN FALSE ';'  */
#line 253 "limbaj.y"
                           {
    if(!globalTable->existsLocal(*(yyvsp[-3].Id))) {
        GenericValue val(false);
        val.type = *(yyvsp[-4].Id);
        globalTable->addVariable(*(yyvsp[-4].Id), *(yyvsp[-3].Id), val);
             cout<< "' = false" << endl;
        
        ASTNode* idNode = new ASTNode(*(yyvsp[-3].Id), "ID");
        idNode->expressionType = *(yyvsp[-4].Id);
        
        ASTNode* valNode = new ASTNode("false", "LITERAL");
        valNode->expressionType = "bool";
        
        ASTNode* assignNode = new ASTNode("<-", "STATEMENT", idNode, valNode);
        assignNode->expressionType = "void";
        
        globalInitASTs.push_back(assignNode);
    }
    delete (yyvsp[-4].Id);
    delete (yyvsp[-3].Id);
}
#line 1773 "y.tab.c"
    break;

  case 16: /* vars: ID  */
#line 278 "limbaj.y"
         {
        (yyval.StrList).list = new vector<string>();
        (yyval.StrList).list->push_back(*(yyvsp[0].Id));
        delete (yyvsp[0].Id);
    }
#line 1783 "y.tab.c"
    break;

  case 17: /* vars: vars ',' ID  */
#line 283 "limbaj.y"
                  {
        (yyvsp[-2].StrList).list->push_back(*(yyvsp[0].Id));
        (yyval.StrList) = (yyvsp[-2].StrList);
        delete (yyvsp[0].Id);
    }
#line 1793 "y.tab.c"
    break;

  case 18: /* $@3: %empty  */
#line 292 "limbaj.y"
      {
          currentClassTable = new SymTable("Class_" + *(yyvsp[0].Id), globalTable);
          currentScope = currentClassTable; 
      }
#line 1802 "y.tab.c"
    break;

  case 19: /* class_def: CLASS ID $@3 BGIN class_body END  */
#line 297 "limbaj.y"
      {
          globalTable->addClass(*(yyvsp[-4].Id), currentClassTable);
          currentClassTable = nullptr;
          currentScope = globalTable; 
          delete (yyvsp[-4].Id);
      }
#line 1813 "y.tab.c"
    break;

  case 32: /* class_field: TYPE vars ';'  */
#line 332 "limbaj.y"
                    {
        if(currentClassTable == nullptr) {
            yyerror("Internal Error: No active class scope");
        } else {
            for(auto& id : *(yyvsp[-1].StrList).list) {
                if(currentClassTable->existsLocal(id)) {
                    char errMsg[256];
                    sprintf(errMsg, "Semantic Error: Field '%s' already declared in class", id.c_str());
                    yyerror(errMsg);
                } else {
                    currentClassTable->addVariable(*(yyvsp[-2].Id), id, GenericValue()); // adaugă membru
                }
            }
        }
        delete (yyvsp[-1].StrList).list;
        delete (yyvsp[-2].Id);
    }
#line 1835 "y.tab.c"
    break;

  case 33: /* class_field: ID ID ';'  */
#line 349 "limbaj.y"
                {
        if(currentClassTable == nullptr) {
            yyerror("Internal Error: No active class scope");
        } else {
            if(!globalTable->classExists(*(yyvsp[-2].Id))) {
                char errMsg[256];
                sprintf(errMsg, "Semantic Error: Type '%s' not declared", (yyvsp[-2].Id)->c_str());
                yyerror(errMsg);
            }
            if(currentClassTable->existsLocal(*(yyvsp[-1].Id))) {
                char errMsg[256];
                sprintf(errMsg, "Semantic Error: Field '%s' already declared", (yyvsp[-1].Id)->c_str());
                yyerror(errMsg);
            } else {
                currentClassTable->addVariable(*(yyvsp[-2].Id), *(yyvsp[-1].Id), GenericValue());  
            }
        }
        delete (yyvsp[-2].Id);
        delete (yyvsp[-1].Id);
    }
#line 1860 "y.tab.c"
    break;

  case 34: /* $@4: %empty  */
#line 373 "limbaj.y"
      {
        if (currentClassTable == nullptr) {
            yyerror("Internal Error: currentClassTable is null");
        } else {
            currentClassTable->addFunc(*(yyvsp[-4].Id), *(yyvsp[-3].Id), *(yyvsp[-1].ParamList).params);
            
            currentExpectedReturnType = *(yyvsp[-4].Id);

            SymTable* mScope = new SymTable("Method_" + *(yyvsp[-3].Id), currentClassTable);
            for(auto p : *(yyvsp[-1].ParamList).params) {
                mScope->addVariable(p.first, p.second, GenericValue());
            }
            currentClassTable->functionScopes[*(yyvsp[-3].Id)] = mScope;
            currentScope = mScope;
        }
      }
#line 1881 "y.tab.c"
    break;

  case 35: /* class_method: FUNCTION TYPE func_name '(' list_param ')' $@4 BGIN func_block END  */
#line 390 "limbaj.y"
      {
        currentScope = currentClassTable;
        currentExpectedReturnType = "";
        delete (yyvsp[-8].Id); delete (yyvsp[-7].Id); 
      }
#line 1891 "y.tab.c"
    break;

  case 36: /* $@5: %empty  */
#line 399 "limbaj.y"
      {
        currentExpectedReturnType = *(yyvsp[-4].Id); 
        SymTable* funcScope = new SymTable("Func_" + *(yyvsp[-3].Id), globalTable);
        for(auto p : *(yyvsp[-1].ParamList).params) funcScope->addVariable(p.first, p.second, GenericValue());
        globalTable->functionScopes[*(yyvsp[-3].Id)] = funcScope; 
        currentScope = funcScope; 
      }
#line 1903 "y.tab.c"
    break;

  case 37: /* func_def: FUNCTION TYPE func_name '(' list_param ')' $@5 BGIN func_block END  */
#line 407 "limbaj.y"
      {
        globalTable->addFunc(*(yyvsp[-8].Id), *(yyvsp[-7].Id), *(yyvsp[-5].ParamList).params);
        currentScope = globalTable; 
        currentExpectedReturnType = ""; 
      }
#line 1913 "y.tab.c"
    break;

  case 38: /* $@6: %empty  */
#line 414 "limbaj.y"
      {
        SymTable* funcScope = new SymTable("Func_" + *(yyvsp[-3].Id), globalTable);
        for(auto p : *(yyvsp[-1].ParamList).params) funcScope->addVariable(p.first, p.second,GenericValue());
        
        currentScope = funcScope;
      }
#line 1924 "y.tab.c"
    break;

  case 39: /* func_def: FUNCTION ID func_name '(' list_param ')' $@6 BGIN func_block END  */
#line 421 "limbaj.y"
      {
        globalTable->addFunc(*(yyvsp[-8].Id), *(yyvsp[-7].Id), *(yyvsp[-5].ParamList).params);
        currentScope = globalTable; 
      }
#line 1933 "y.tab.c"
    break;

  case 40: /* func_name: ID  */
#line 428 "limbaj.y"
         { (yyval.Id) = (yyvsp[0].Id); }
#line 1939 "y.tab.c"
    break;

  case 41: /* func_block: %empty  */
#line 433 "limbaj.y"
                  { (yyval.TypeName) = "void"; }
#line 1945 "y.tab.c"
    break;

  case 42: /* func_block: func_block func_item  */
#line 434 "limbaj.y"
                           { (yyval.TypeName) = "void"; }
#line 1951 "y.tab.c"
    break;

  case 43: /* func_item: TYPE ID ';'  */
#line 438 "limbaj.y"
                  {
        if(currentScope->existsLocal(*(yyvsp[-1].Id))) {
            yyerror(("Semantic Error: Variable '"+*(yyvsp[-1].Id)+"' already declared").c_str());
        } else {
            currentScope->addVariable(*(yyvsp[-2].Id), *(yyvsp[-1].Id), GenericValue()); 
        }
        (yyval.TypeName) = strdup("void");     
        delete (yyvsp[-2].Id); delete (yyvsp[-1].Id);
    }
#line 1965 "y.tab.c"
    break;

  case 44: /* func_item: TYPE ID ASSIGN ast_expr ';'  */
#line 447 "limbaj.y"
                                  {
    if(currentScope->existsLocal(*(yyvsp[-3].Id))) {
        yyerror(("Semantic Error: Variable '"+*(yyvsp[-3].Id)+"' already declared").c_str());
    } else {
        currentScope->addVariable(*(yyvsp[-4].Id), *(yyvsp[-3].Id), GenericValue());
        
        if(string(*(yyvsp[-4].Id)) != (yyvsp[-1].astNode)->expressionType) {  
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Type mismatch in initialization of '%s' (expected %s, got %s)",
                    (yyvsp[-3].Id)->c_str(), (yyvsp[-4].Id)->c_str(), (yyvsp[-1].astNode)->expressionType.c_str());  
            yyerror(errMsg);
        }
        
        GenericValue initVal = (yyvsp[-1].astNode)->evaluate(currentScope);
        currentScope->setValue(*(yyvsp[-3].Id), initVal);
    }
    (yyval.TypeName) = strdup("void");  
    delete (yyvsp[-4].Id); delete (yyvsp[-3].Id);
    delete (yyvsp[-1].astNode);  
}
#line 1990 "y.tab.c"
    break;

  case 45: /* func_item: control_stmt  */
#line 467 "limbaj.y"
                   {(yyval.TypeName) = strdup("void");   }
#line 1996 "y.tab.c"
    break;

  case 46: /* func_item: id_start_item ';'  */
#line 468 "limbaj.y"
                        { (yyval.TypeName) = (yyvsp[-1].TypeName); }
#line 2002 "y.tab.c"
    break;

  case 47: /* func_item: RETURN expr ';'  */
#line 469 "limbaj.y"
                       { 
        if (currentExpectedReturnType != "" && currentExpectedReturnType != string((yyvsp[-1].TypeName))) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Return type mismatch. Expected %s, got %s", 
                    currentExpectedReturnType.c_str(), (yyvsp[-1].TypeName));
            yyerror(errMsg);
        }
        (yyval.TypeName) = (yyvsp[-1].TypeName); 
    }
#line 2016 "y.tab.c"
    break;

  case 48: /* func_item: RETURN expr_bool ';'  */
#line 478 "limbaj.y"
                            {if (currentExpectedReturnType != "" && currentExpectedReturnType != "bool") {
        char errMsg[256];
        sprintf(errMsg, "Semantic Error: Return type mismatch. Expected %s, got bool", 
                currentExpectedReturnType.c_str());
        yyerror(errMsg);
    }
    (yyval.TypeName) = strdup("bool");
    }
#line 2029 "y.tab.c"
    break;

  case 49: /* id_start_item: ID ID  */
#line 489 "limbaj.y"
            {
        if(currentScope->existsLocal(*(yyvsp[0].Id))) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Variable '%s' already declared", (yyvsp[0].Id)->c_str());
            yyerror(errMsg);
        } else {
            currentScope->addVariable(*(yyvsp[-1].Id), *(yyvsp[0].Id), GenericValue());
        }
        (yyval.TypeName) = strdup((yyvsp[-1].Id)->c_str());
        delete (yyvsp[-1].Id); delete (yyvsp[0].Id);
    }
#line 2045 "y.tab.c"
    break;

  case 50: /* id_start_item: ID ID ASSIGN expr  */
#line 500 "limbaj.y"
                        {
        if(currentScope->existsLocal(*(yyvsp[-2].Id))) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Variable '%s' already declared", (yyvsp[-2].Id)->c_str());
            yyerror(errMsg);
        } else {
            if(string(*(yyvsp[-3].Id)) != string((yyvsp[0].TypeName))) {
                char errMsg[256];
                sprintf(errMsg, "Semantic Error: Type mismatch in initialization of '%s' (expected %s, got %s)",
                        (yyvsp[-2].Id)->c_str(), (yyvsp[-3].Id)->c_str(), (yyvsp[0].TypeName));
                yyerror(errMsg);
            }
            currentScope->addVariable(*(yyvsp[-3].Id), *(yyvsp[-2].Id), "");
        }
        (yyval.TypeName) = strdup((yyvsp[0].TypeName));
        delete (yyvsp[-3].Id); delete (yyvsp[-2].Id);
    }
#line 2067 "y.tab.c"
    break;

  case 51: /* id_start_item: ID ASSIGN expr  */
#line 517 "limbaj.y"
                     {
    if(!currentScope->exists(*(yyvsp[-2].Id))) {
        char errMsg[256];
        sprintf(errMsg, "Semantic Error: Variable '%s' not declared", (yyvsp[-2].Id)->c_str());
        yyerror(errMsg);
    }
    else if(currentScope->getType(*(yyvsp[-2].Id)) != (yyvsp[0].TypeName)) {
        char errMsg[256];
        sprintf(errMsg, "Semantic Error: Type mismatch in assignment to '%s' (expected %s, got %s)",
                (yyvsp[-2].Id)->c_str(), currentScope->getType(*(yyvsp[-2].Id)).c_str(), (yyvsp[0].TypeName));
        yyerror(errMsg);
    }

    (yyval.TypeName) = (yyvsp[0].TypeName);        
    delete (yyvsp[-2].Id);
    }
#line 2088 "y.tab.c"
    break;

  case 52: /* id_start_item: ID ASSIGN NEW ID '(' ')'  */
#line 533 "limbaj.y"
                               {
        if(!currentScope->exists(*(yyvsp[-5].Id))) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Variable '%s' not declared", (yyvsp[-5].Id)->c_str());
            yyerror(errMsg);
        }
        if(!globalTable->classExists(*(yyvsp[-2].Id))) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Class '%s' not declared", (yyvsp[-2].Id)->c_str());
            yyerror(errMsg);
        }
        currentScope->addVariable(*(yyvsp[-5].Id), *(yyvsp[-2].Id),GenericValue()); 
        (yyval.TypeName) = strdup((yyvsp[-2].Id)->c_str());
        delete (yyvsp[-5].Id); delete (yyvsp[-2].Id);
    }
#line 2108 "y.tab.c"
    break;

  case 53: /* id_start_item: ID '.' ID ASSIGN expr  */
#line 548 "limbaj.y"
                            {
        string classType = currentScope->getType(*(yyvsp[-4].Id));
        if(!globalTable->classHasField(classType, *(yyvsp[-2].Id))) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Field '%s' does not exist in class '%s'", (yyvsp[-2].Id)->c_str(), classType.c_str());
            yyerror(errMsg);
        } else {
            if(globalTable->getFieldType(classType, *(yyvsp[-2].Id)) != string((yyvsp[0].TypeName))) {
                char errMsg[256];
                sprintf(errMsg, "Semantic Error: Field type mismatch for '%s.%s' (expected %s, got %s)",
                        (yyvsp[-4].Id)->c_str(), (yyvsp[-2].Id)->c_str(), globalTable->getFieldType(classType, *(yyvsp[-2].Id)).c_str(), (yyvsp[0].TypeName));
                yyerror(errMsg);
            }
        }
        (yyval.TypeName) = strdup("void");
        delete (yyvsp[-4].Id); delete (yyvsp[-2].Id);
    }
#line 2130 "y.tab.c"
    break;

  case 54: /* id_start_item: ID '(' call_list ')'  */
#line 565 "limbaj.y"
                           {
    if(!globalTable->functionExists(*(yyvsp[-3].Id))) {
        char errMsg[256];
        sprintf(errMsg, "Semantic Error: Function '%s' not declared", (yyvsp[-3].Id)->c_str());
        yyerror(errMsg);
        (yyval.TypeName) = "error";
    } else {
        vector<pair<string,string>> expected = globalTable->getFunctionParams(*(yyvsp[-3].Id));

        if(expected.size() != (yyvsp[-1].StrList).list->size()) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Wrong number of arguments for function '%s' (expected %lu, got %lu)",
                    (yyvsp[-3].Id)->c_str(), expected.size(), (yyvsp[-1].StrList).list->size());
            yyerror(errMsg);
        } else {
            for(size_t i = 0; i < expected.size(); i++) {
                if(expected[i].first != (*(yyvsp[-1].StrList).list)[i]) {
                    char errMsg[256];
                    sprintf(errMsg, "Semantic Error: Argument %lu type mismatch in call to '%s' (expected %s, got %s)",
                            i+1, (yyvsp[-3].Id)->c_str(), expected[i].first.c_str(), (*(yyvsp[-1].StrList).list)[i].c_str());
                    yyerror(errMsg);
                }
            }
        }
        (yyval.TypeName) = strdup(globalTable->getFunctionReturnType(*(yyvsp[-3].Id)).c_str());
    }
    delete (yyvsp[-3].Id);
    delete (yyvsp[-1].StrList).list;
}
#line 2164 "y.tab.c"
    break;

  case 55: /* id_start_item: ID '.' ID '(' call_list ')'  */
#line 594 "limbaj.y"
                                  {
    string classType;
    if(!currentScope->exists(*(yyvsp[-5].Id))) {
        char errMsg[256];
        sprintf(errMsg, "Semantic Error: Variable '%s' not declared", (yyvsp[-5].Id)->c_str());
        yyerror(errMsg);
        (yyval.TypeName) = strdup("error");
    } else {
        classType = currentScope->getType(*(yyvsp[-5].Id));
        // Verificăm dacă clasa există
        if(!globalTable->classExists(classType)) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Class '%s' not declared", classType.c_str());
            yyerror(errMsg);
            (yyval.TypeName) = strdup("error");
        } 
        else {
            // Obținem lista de parametri a metodei
            vector<pair<string,string>> expected = globalTable->getMethodParams(classType, *(yyvsp[-3].Id));

            // Verificăm numărul de argumente
            if(expected.size() != (yyvsp[-1].StrList).list->size()) {
                char errMsg[256];
                sprintf(errMsg, "Semantic Error: Wrong number of arguments for method '%s' (expected %lu, got %lu)",
                        (yyvsp[-3].Id)->c_str(), expected.size(), (yyvsp[-1].StrList).list->size());
                yyerror(errMsg);
            } 
            else {
                for(size_t i=0; i<expected.size(); i++) {
                    if(expected[i].first != (*(yyvsp[-1].StrList).list)[i]) {
                        char errMsg[256];
                        sprintf(errMsg, "Semantic Error: Argument %lu type mismatch in call to '%s' (expected %s, got %s)",
                                i+1, (yyvsp[-3].Id)->c_str(), expected[i].first.c_str(), (*(yyvsp[-1].StrList).list)[i].c_str());
                        yyerror(errMsg);
                    }
                }
            }

            (yyval.TypeName) = strdup(globalTable->getMethodReturnType(classType, *(yyvsp[-3].Id)).c_str());
        }
    }

    delete (yyvsp[-5].Id);
    delete (yyvsp[-3].Id);
    delete (yyvsp[-1].StrList).list;
}
#line 2215 "y.tab.c"
    break;

  case 56: /* id_start_item: PRINT '(' expr ')'  */
#line 641 "limbaj.y"
                         {(yyval.TypeName) = strdup("void"); delete (yyvsp[-1].TypeName); }
#line 2221 "y.tab.c"
    break;

  case 57: /* list_param: %empty  */
#line 645 "limbaj.y"
                  { 
        (yyval.ParamList).params = new vector<pair<string, string>>(); 
    }
#line 2229 "y.tab.c"
    break;

  case 58: /* list_param: param_list  */
#line 648 "limbaj.y"
                 {
        (yyval.ParamList) = (yyvsp[0].ParamList);  
    }
#line 2237 "y.tab.c"
    break;

  case 59: /* param_list: param  */
#line 654 "limbaj.y"
            {
        (yyval.ParamList) = (yyvsp[0].ParamList);  
    }
#line 2245 "y.tab.c"
    break;

  case 60: /* param_list: param_list ',' param  */
#line 657 "limbaj.y"
                           {
        (yyvsp[-2].ParamList).params->insert((yyvsp[-2].ParamList).params->end(), (yyvsp[0].ParamList).params->begin(), (yyvsp[0].ParamList).params->end());
        (yyval.ParamList) = (yyvsp[-2].ParamList);
        delete (yyvsp[0].ParamList).params;
    }
#line 2255 "y.tab.c"
    break;

  case 61: /* param: TYPE ID  */
#line 665 "limbaj.y"
              {
        (yyval.ParamList).params = new vector<pair<string, string>>();
        (yyval.ParamList).params->push_back(make_pair(*(yyvsp[-1].Id), *(yyvsp[0].Id)));
        delete (yyvsp[-1].Id);
        delete (yyvsp[0].Id);
    }
#line 2266 "y.tab.c"
    break;

  case 62: /* param: ID ID  */
#line 671 "limbaj.y"
            {
        (yyval.ParamList).params = new vector<pair<string, string>>();
        (yyval.ParamList).params->push_back(make_pair(*(yyvsp[-1].Id), *(yyvsp[0].Id)));
        delete (yyvsp[-1].Id);
        delete (yyvsp[0].Id);
    }
#line 2277 "y.tab.c"
    break;

  case 63: /* $@7: %empty  */
#line 680 "limbaj.y"
           {
        mainBlockASTs.clear();
        currentScope = globalTable;
      }
#line 2286 "y.tab.c"
    break;

  case 64: /* main_block: BGIN $@7 stmt_list_ast END  */
#line 685 "limbaj.y"
          {
        cout << "\n========== EXECUTING MAIN BLOCK ==========\n";
        
        for(size_t i = 0; i < mainBlockASTs.size(); i++) {
            if(mainBlockASTs[i] == nullptr) {
                cout << "nullptr (skipped)" << endl;
            } else {

                mainBlockASTs[i]->evaluate(currentScope);
            }
        }
        cout << "========== END EXECUTION ==========\n\n";
      }
#line 2304 "y.tab.c"
    break;

  case 65: /* simple_stmt: ID ASSIGN expr  */
#line 702 "limbaj.y"
                     {
          if(!currentScope->exists(*(yyvsp[-2].Id))) {
              char errMsg[256];
              sprintf(errMsg, "Semantic Error: Variable '%s' used before declaration", (yyvsp[-2].Id)->c_str());
              yyerror(errMsg);
          } else if(currentScope->getType(*(yyvsp[-2].Id)) != string((yyvsp[0].TypeName))) {
              char errMsg[256];
              sprintf(errMsg, "Semantic Error: Type mismatch in assignment to '%s' (expected %s, got %s)", (yyvsp[-2].Id)->c_str(), globalTable->getType(*(yyvsp[-2].Id)).c_str(), (yyvsp[0].TypeName));
              yyerror(errMsg);
          }
          (yyval.TypeName) = "void";
          delete (yyvsp[-2].Id);
      }
#line 2322 "y.tab.c"
    break;

  case 66: /* simple_stmt: ID ASSIGN expr_bool  */
#line 715 "limbaj.y"
                          { 
        if(!currentScope->exists(*(yyvsp[-2].Id))) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Variable '%s' used before declaration", (yyvsp[-2].Id)->c_str());
            yyerror(errMsg);
        }
        (yyval.TypeName) = "void";
        delete (yyvsp[-2].Id);
    }
#line 2336 "y.tab.c"
    break;

  case 67: /* simple_stmt: ID ASSIGN NEW ID '(' ')'  */
#line 724 "limbaj.y"
                               {
          if(!currentScope->exists(*(yyvsp[-5].Id))) {
              char errMsg[256];
              sprintf(errMsg, "Semantic Error: Variable '%s' not declared", (yyvsp[-5].Id)->c_str());
              yyerror(errMsg);
          }
          if(!globalTable->classExists(*(yyvsp[-2].Id))) {
              char errMsg[256];
              sprintf(errMsg, "Semantic Error: Class '%s' not declared", (yyvsp[-2].Id)->c_str());
              yyerror(errMsg);
          }
          // Only check type if variable exists
          else if(currentScope->exists(*(yyvsp[-5].Id)) && currentScope->getType(*(yyvsp[-5].Id)) != *(yyvsp[-2].Id)) {
              char errMsg[256];
              sprintf(errMsg, "Semantic Error: Type mismatch in object creation (expected %s, got %s)", 
                      currentScope->getType(*(yyvsp[-5].Id)).c_str(), (yyvsp[-2].Id)->c_str());
              yyerror(errMsg);
          }
          (yyval.TypeName) = "void";
          delete (yyvsp[-5].Id);
          delete (yyvsp[-2].Id);
      }
#line 2363 "y.tab.c"
    break;

  case 68: /* simple_stmt: ID '.' ID ASSIGN expr  */
#line 746 "limbaj.y"
                            {
          if(!currentScope->exists(*(yyvsp[-4].Id))) {
              char errMsg[256];
              sprintf(errMsg, "Semantic Error: Variable '%s' not declared", (yyvsp[-4].Id)->c_str());
              yyerror(errMsg);
          } else {
              string classType = currentScope->getType(*(yyvsp[-4].Id));
              if(!globalTable->classHasField(classType, *(yyvsp[-2].Id))) {
                  char errMsg[256];
                  sprintf(errMsg, "Semantic Error: Field '%s' does not exist in class '%s'", (yyvsp[-2].Id)->c_str(), classType.c_str());
                  yyerror(errMsg);
              } else if(currentScope->getFieldType(classType, *(yyvsp[-2].Id)) != string((yyvsp[0].TypeName))) {
                  char errMsg[256];
                  sprintf(errMsg, "Semantic Error: Field type mismatch for '%s.%s' (expected %s, got %s)", (yyvsp[-4].Id)->c_str(), (yyvsp[-2].Id)->c_str(), globalTable->getFieldType(classType, *(yyvsp[-2].Id)).c_str(), (yyvsp[0].TypeName));
                  yyerror(errMsg);
              }
          }
          (yyval.TypeName) = "void";
          delete (yyvsp[-4].Id);
          delete (yyvsp[-2].Id);
      }
#line 2389 "y.tab.c"
    break;

  case 69: /* simple_stmt: RETURN expr  */
#line 767 "limbaj.y"
                  { (yyval.TypeName) = (yyvsp[0].TypeName); }
#line 2395 "y.tab.c"
    break;

  case 70: /* simple_stmt: RETURN expr_bool  */
#line 768 "limbaj.y"
                       { (yyval.TypeName) = "bool"; }
#line 2401 "y.tab.c"
    break;

  case 71: /* simple_stmt: PRINT '(' expr ')'  */
#line 769 "limbaj.y"
                         { (yyval.TypeName) = "void"; }
#line 2407 "y.tab.c"
    break;

  case 72: /* simple_stmt: ID '(' call_list ')'  */
#line 770 "limbaj.y"
                           {
          if(!globalTable->functionExists(*(yyvsp[-3].Id))) {
              char errMsg[256];
              sprintf(errMsg, "Semantic Error: Function '%s' not declared", (yyvsp[-3].Id)->c_str());
              yyerror(errMsg);
          } else {
              vector<pair<string,string>> expected = globalTable->getFunctionParams(*(yyvsp[-3].Id));
              if(expected.size() != (yyvsp[-1].StrList).list->size()) {
                  char errMsg[256];
                  sprintf(errMsg, "Semantic Error: Wrong number of arguments for function '%s' (expected %lu, got %lu)", (yyvsp[-3].Id)->c_str(), expected.size(), (yyvsp[-1].StrList).list->size());
                  yyerror(errMsg);
              } else {
                  for(size_t i = 0; i < expected.size(); i++) {
                      if(expected[i].first != (*(yyvsp[-1].StrList).list)[i]) {
                          char errMsg[256];
                          sprintf(errMsg, "Semantic Error: Argument %lu type mismatch in call to '%s' (expected %s, got %s)", i+1, (yyvsp[-3].Id)->c_str(), expected[i].first.c_str(), (*(yyvsp[-1].StrList).list)[i].c_str());
                          yyerror(errMsg);
                      }
                  }
              }
          }
          (yyval.TypeName) = "void";
          delete (yyvsp[-3].Id);
          delete (yyvsp[-1].StrList).list;
      }
#line 2437 "y.tab.c"
    break;

  case 77: /* expr: '-' expr  */
#line 805 "limbaj.y"
                            {
        // Verificăm tipul expresiei
        if(string((yyvsp[0].TypeName)) == "int") {
            (yyval.TypeName) = strdup("int");
        } else if(string((yyvsp[0].TypeName)) == "float") {
            (yyval.TypeName) = strdup("float");
        } else {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Unary '-' not allowed on type %s", (yyvsp[0].TypeName));
            yyerror(errMsg);
            (yyval.TypeName) = strdup("error");
        }
    }
#line 2455 "y.tab.c"
    break;

  case 78: /* expr: expr '+' expr  */
#line 818 "limbaj.y"
                    {
        if(string((yyvsp[-2].TypeName)) != string((yyvsp[0].TypeName))) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Operands must have the same type for '+' (got %s and %s)", (yyvsp[-2].TypeName), (yyvsp[0].TypeName));
            yyerror(errMsg);
        }
        (yyval.TypeName) = (yyvsp[-2].TypeName);
    }
#line 2468 "y.tab.c"
    break;

  case 79: /* expr: expr '-' expr  */
#line 826 "limbaj.y"
                    {
        if(string((yyvsp[-2].TypeName)) != string((yyvsp[0].TypeName))) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Operands must have the same type for '-' (got %s and %s)", (yyvsp[-2].TypeName), (yyvsp[0].TypeName));
            yyerror(errMsg);
        }
        (yyval.TypeName) = (yyvsp[-2].TypeName);
    }
#line 2481 "y.tab.c"
    break;

  case 80: /* expr: expr '*' expr  */
#line 834 "limbaj.y"
                    {
        if(string((yyvsp[-2].TypeName)) != string((yyvsp[0].TypeName))) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Operands must have the same type for '*' (got %s and %s)", (yyvsp[-2].TypeName), (yyvsp[0].TypeName));
            yyerror(errMsg);
        }
        (yyval.TypeName) = (yyvsp[-2].TypeName);
    }
#line 2494 "y.tab.c"
    break;

  case 81: /* expr: expr '/' expr  */
#line 842 "limbaj.y"
                    {
        if(string((yyvsp[-2].TypeName)) != string((yyvsp[0].TypeName))) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Operands must have the same type for '/' (got %s and %s)", (yyvsp[-2].TypeName), (yyvsp[0].TypeName));
            yyerror(errMsg);
        }
        (yyval.TypeName) = (yyvsp[-2].TypeName);
    }
#line 2507 "y.tab.c"
    break;

  case 82: /* expr: expr '%' expr  */
#line 850 "limbaj.y"
                    {
        if(string((yyvsp[-2].TypeName)) != string((yyvsp[0].TypeName))) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Operands must have the same type for '%%' (got %s and %s)", (yyvsp[-2].TypeName), (yyvsp[0].TypeName));
            yyerror(errMsg);
        }
        (yyval.TypeName) = (yyvsp[-2].TypeName);
    }
#line 2520 "y.tab.c"
    break;

  case 83: /* expr: '(' expr ')'  */
#line 858 "limbaj.y"
                   { (yyval.TypeName) = (yyvsp[-1].TypeName); }
#line 2526 "y.tab.c"
    break;

  case 84: /* expr: NR_INT  */
#line 859 "limbaj.y"
             { (yyval.TypeName) = "int"; }
#line 2532 "y.tab.c"
    break;

  case 85: /* expr: NR_FLOAT  */
#line 860 "limbaj.y"
               { (yyval.TypeName) = "float"; }
#line 2538 "y.tab.c"
    break;

  case 86: /* expr: STRING_VAL  */
#line 861 "limbaj.y"
                 { (yyval.TypeName) = "string"; }
#line 2544 "y.tab.c"
    break;

  case 87: /* expr: ID  */
#line 862 "limbaj.y"
         {
        if(!currentScope->exists(*(yyvsp[0].Id))) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Variable '%s' undefined", (yyvsp[0].Id)->c_str());
            yyerror(errMsg);
            (yyval.TypeName) = "error";
        } else {
            (yyval.TypeName) = strdup(currentScope->getType(*(yyvsp[0].Id)).c_str());
        }
        delete (yyvsp[0].Id);
    }
#line 2560 "y.tab.c"
    break;

  case 88: /* expr: ID '.' ID  */
#line 873 "limbaj.y"
                {
        if(!currentScope->exists(*(yyvsp[-2].Id))) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Variable '%s' not declared", (yyvsp[-2].Id)->c_str());
            yyerror(errMsg);
            (yyval.TypeName) = "error";
        } else {
            string classType = globalTable->getType(*(yyvsp[-2].Id));
            if(!globalTable->classHasField(classType, *(yyvsp[0].Id))) {
                char errMsg[256];
                sprintf(errMsg, "Semantic Error: Field '%s' not found in class '%s'", (yyvsp[0].Id)->c_str(), classType.c_str());
                yyerror(errMsg);
                (yyval.TypeName) = "error";
            } else {
                (yyval.TypeName) = strdup(globalTable->getFieldType(classType, *(yyvsp[0].Id)).c_str());
            }
        }
        delete (yyvsp[-2].Id);
        delete (yyvsp[0].Id);
    }
#line 2585 "y.tab.c"
    break;

  case 89: /* expr: ID '.' ID '(' call_list ')'  */
#line 893 "limbaj.y"
                                  { 
    if(!currentScope->exists(*(yyvsp[-5].Id))) {
        yyerror("Semantic Error: Variable not declared");
        (yyval.TypeName) = strdup("error");
    } else {
        string classType = currentScope->getType(*(yyvsp[-5].Id));
        if(!globalTable->classExists(classType)) {
            yyerror("Semantic Error: Class not declared");
            (yyval.TypeName) = strdup("error");
        } else {
            vector<pair<string,string>> expected = globalTable->getMethodParams(classType, *(yyvsp[-3].Id));
            if(expected.size() != (yyvsp[-1].StrList).list->size()) {
                char errMsg[256];
                sprintf(errMsg, "Semantic Error: Method '%s' expected %lu args, got %lu", (yyvsp[-3].Id)->c_str(), expected.size(), (yyvsp[-1].StrList).list->size());
                yyerror(errMsg);
            } else {
                for(size_t i=0; i<expected.size(); i++) {
                    if(expected[i].first != (*(yyvsp[-1].StrList).list)[i]) {
                        char errMsg[256];
                        sprintf(errMsg, "Semantic Error: Arg %lu mismatch (expected %s, got %s)", i+1, expected[i].first.c_str(), (*(yyvsp[-1].StrList).list)[i].c_str());
                        yyerror(errMsg);
                    }
                }
            }
            (yyval.TypeName) = strdup(globalTable->getMethodReturnType(classType, *(yyvsp[-3].Id)).c_str());
        }
    }
    delete (yyvsp[-5].Id); delete (yyvsp[-3].Id); delete (yyvsp[-1].StrList).list;

}
#line 2620 "y.tab.c"
    break;

  case 90: /* expr: ID '(' call_list ')'  */
#line 923 "limbaj.y"
                           {
        if(!globalTable->functionExists(*(yyvsp[-3].Id))) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Function '%s' not declared", (yyvsp[-3].Id)->c_str());
            yyerror(errMsg);
            (yyval.TypeName) = "error";
        } else {
            vector<pair<string,string>> expected = globalTable->getFunctionParams(*(yyvsp[-3].Id));
            if(expected.size() != (yyvsp[-1].StrList).list->size()) {
                char errMsg[256];
                sprintf(errMsg, "Semantic Error: Wrong number of arguments for function '%s' (expected %lu, got %lu)", (yyvsp[-3].Id)->c_str(), expected.size(), (yyvsp[-1].StrList).list->size());
                yyerror(errMsg);
            } else {
                for(size_t i = 0; i < expected.size(); i++) {
                    if(expected[i].first != (*(yyvsp[-1].StrList).list)[i]) {
                        char errMsg[256];
                        sprintf(errMsg, "Semantic Error: Argument %lu type mismatch in call to '%s' (expected %s, got %s)", i+1, (yyvsp[-3].Id)->c_str(), expected[i].first.c_str(), (*(yyvsp[-1].StrList).list)[i].c_str());
                        yyerror(errMsg);
                    }
                }
            }
            (yyval.TypeName) = strdup(globalTable->getFunctionReturnType(*(yyvsp[-3].Id)).c_str());
        }
        delete (yyvsp[-3].Id);
        delete (yyvsp[-1].StrList).list;
    }
#line 2651 "y.tab.c"
    break;

  case 91: /* expr_bool: TRUE  */
#line 952 "limbaj.y"
           { (yyval.TypeName) = "bool"; }
#line 2657 "y.tab.c"
    break;

  case 92: /* expr_bool: FALSE  */
#line 953 "limbaj.y"
            { (yyval.TypeName) = "bool"; }
#line 2663 "y.tab.c"
    break;

  case 93: /* expr_bool: expr comp expr  */
#line 954 "limbaj.y"
                     {
        if(string((yyvsp[-2].TypeName)) != string((yyvsp[0].TypeName))) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Comparison operands must have the same type (got %s and %s)", (yyvsp[-2].TypeName), (yyvsp[0].TypeName));
            yyerror(errMsg);
        }
        (yyval.TypeName) = "bool";  
    }
#line 2676 "y.tab.c"
    break;

  case 94: /* expr_bool: expr_bool AND expr_bool  */
#line 962 "limbaj.y"
                              { (yyval.TypeName) = "bool"; }
#line 2682 "y.tab.c"
    break;

  case 95: /* expr_bool: expr_bool OR expr_bool  */
#line 963 "limbaj.y"
                             { (yyval.TypeName) = "bool"; }
#line 2688 "y.tab.c"
    break;

  case 96: /* expr_bool: NOT expr_bool  */
#line 964 "limbaj.y"
                    { (yyval.TypeName) = "bool"; }
#line 2694 "y.tab.c"
    break;

  case 97: /* expr_bool: '(' expr_bool ')'  */
#line 965 "limbaj.y"
                        { (yyval.TypeName) = (yyvsp[-1].TypeName); }
#line 2700 "y.tab.c"
    break;

  case 100: /* statement_ast: ast_simple_stmt ';'  */
#line 975 "limbaj.y"
                          {
        mainBlockASTs.push_back((yyvsp[-1].astNode));
    }
#line 2708 "y.tab.c"
    break;

  case 101: /* statement_ast: control_stmt  */
#line 978 "limbaj.y"
                   {
        mainBlockASTs.push_back(nullptr);
    }
#line 2716 "y.tab.c"
    break;

  case 102: /* statement_ast: TYPE ID ASSIGN ast_expr ';'  */
#line 981 "limbaj.y"
                                  {
    
    if(!currentScope->existsLocal(*(yyvsp[-3].Id))) {
        currentScope->addVariable(*(yyvsp[-4].Id), *(yyvsp[-3].Id), GenericValue());
    }
    
    ASTNode* idNode = new ASTNode(*(yyvsp[-3].Id), "ID");
    idNode->expressionType = *(yyvsp[-4].Id);
    
    ASTNode* assignNode = new ASTNode("<-", "STATEMENT", idNode, (yyvsp[-1].astNode));
    assignNode->expressionType = "void";
    
    mainBlockASTs.push_back(assignNode);
    delete (yyvsp[-4].Id);
    delete (yyvsp[-3].Id);
}
#line 2737 "y.tab.c"
    break;

  case 103: /* statement_ast: TYPE vars ';'  */
#line 997 "limbaj.y"
                    {
        mainBlockASTs.push_back(nullptr);
        delete (yyvsp[-2].Id);
        delete (yyvsp[-1].StrList).list;
    }
#line 2747 "y.tab.c"
    break;

  case 104: /* ast_simple_stmt: ID ASSIGN NEW ID '(' ')'  */
#line 1006 "limbaj.y"
                                {
        if(!currentScope->exists(*(yyvsp[-5].Id))) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Variable '%s' not declared", (yyvsp[-5].Id)->c_str());
            yyerror(errMsg);
        }
        if(!globalTable->classExists(*(yyvsp[-2].Id))) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Class '%s' not declared", (yyvsp[-2].Id)->c_str());
            yyerror(errMsg);
        }
        
        ASTNode* idNode = new ASTNode(*(yyvsp[-5].Id), "ID");
        ASTNode* classNode = new ASTNode("new " + *(yyvsp[-2].Id), "OTHER");
        classNode->expressionType = *(yyvsp[-2].Id);
        
        (yyval.astNode) = new ASTNode("<-", "STATEMENT", idNode, classNode);
        (yyval.astNode)->expressionType = "void";
        delete (yyvsp[-5].Id);
        delete (yyvsp[-2].Id);
    }
#line 2773 "y.tab.c"
    break;

  case 105: /* ast_simple_stmt: ID ASSIGN ast_expr  */
#line 1027 "limbaj.y"
                         {
        if(!currentScope->exists(*(yyvsp[-2].Id))) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Variable '%s' not declared", (yyvsp[-2].Id)->c_str());
            yyerror(errMsg);
        } else {
            string lhsType = currentScope->getType(*(yyvsp[-2].Id));
            string rhsType = (yyvsp[0].astNode)->expressionType;

            if(lhsType != rhsType) {
                char errMsg[256];
                sprintf(errMsg, "Semantic Error: Type mismatch in assignment to '%s' (expected %s, got %s)",
                        (yyvsp[-2].Id)->c_str(), lhsType.c_str(), rhsType.c_str());
                yyerror(errMsg);
            }
        }

        ASTNode* idNode = new ASTNode(*(yyvsp[-2].Id), "ID");
        idNode->expressionType = currentScope->exists(*(yyvsp[-2].Id)) ? 
            currentScope->getType(*(yyvsp[-2].Id)) : "error";
        
        (yyval.astNode) = new ASTNode("<-", "STATEMENT", idNode, (yyvsp[0].astNode));
        (yyval.astNode)->expressionType = "void";
        delete (yyvsp[-2].Id);
    }
#line 2803 "y.tab.c"
    break;

  case 106: /* ast_simple_stmt: ID '.' ID ASSIGN ast_expr  */
#line 1052 "limbaj.y"
                                {
        if(!currentScope->exists(*(yyvsp[-4].Id))) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Variable '%s' not declared", (yyvsp[-4].Id)->c_str());
            yyerror(errMsg);
        } else {
            string classType = currentScope->getType(*(yyvsp[-4].Id));
            if(!globalTable->classHasField(classType, *(yyvsp[-2].Id))) {
                char errMsg[256];
                sprintf(errMsg, "Semantic Error: Field '%s' does not exist in class '%s'",
                        (yyvsp[-2].Id)->c_str(), classType.c_str());
                yyerror(errMsg);
            } else {
                string lhsType = globalTable->getFieldType(classType, *(yyvsp[-2].Id));
                string rhsType = (yyvsp[0].astNode)->expressionType;
                if(lhsType != rhsType) {
                    char errMsg[256];
                    sprintf(errMsg, "Semantic Error: Type mismatch in assignment to '%s.%s' (expected %s, got %s)",
                            (yyvsp[-4].Id)->c_str(), (yyvsp[-2].Id)->c_str(), lhsType.c_str(), rhsType.c_str());
                    yyerror(errMsg);
                }
            }
        }

        ASTNode* objNode = new ASTNode(*(yyvsp[-4].Id), "ID");
        ASTNode* fieldNode = new ASTNode(*(yyvsp[-2].Id), "FIELD");
        ASTNode* lhs = new ASTNode(".", "ACCESS", objNode, fieldNode);

        (yyval.astNode) = new ASTNode("<-", "STATEMENT", lhs, (yyvsp[0].astNode));
        (yyval.astNode)->expressionType = "void";

        delete (yyvsp[-4].Id);
        delete (yyvsp[-2].Id);
    }
#line 2842 "y.tab.c"
    break;

  case 107: /* ast_simple_stmt: PRINT '(' ast_expr ')'  */
#line 1087 "limbaj.y"
                             {
        (yyval.astNode) = new ASTNode("Print", "STATEMENT", (yyvsp[-1].astNode), nullptr);
        (yyval.astNode)->expressionType = "void";
    }
#line 2851 "y.tab.c"
    break;

  case 108: /* ast_simple_stmt: RETURN ast_expr  */
#line 1092 "limbaj.y"
                    {
        (yyval.astNode) = new ASTNode("Return", "STATEMENT", (yyvsp[0].astNode), nullptr);
        if((yyvsp[0].astNode)) (yyval.astNode)->expressionType = (yyvsp[0].astNode)->expressionType;
        else (yyval.astNode)->expressionType = "void";
    }
#line 2861 "y.tab.c"
    break;

  case 109: /* ast_expr: NR_INT  */
#line 1100 "limbaj.y"
             { 
        (yyval.astNode) = new ASTNode(to_string((yyvsp[0].Int)), "LITERAL");
        (yyval.astNode)->expressionType = "int";
    }
#line 2870 "y.tab.c"
    break;

  case 110: /* ast_expr: NR_FLOAT  */
#line 1104 "limbaj.y"
               { 
        (yyval.astNode) = new ASTNode(to_string((yyvsp[0].Float)), "LITERAL");
        (yyval.astNode)->expressionType = "float";
    }
#line 2879 "y.tab.c"
    break;

  case 111: /* ast_expr: STRING_VAL  */
#line 1108 "limbaj.y"
                 {  
        (yyval.astNode) = new ASTNode(string((yyvsp[0].Str)), "LITERAL");
        (yyval.astNode)->expressionType = "string";
        free((yyvsp[0].Str));
    }
#line 2889 "y.tab.c"
    break;

  case 112: /* ast_expr: TRUE  */
#line 1113 "limbaj.y"
           {
        (yyval.astNode) = new ASTNode("true", "LITERAL");
        (yyval.astNode)->expressionType = "bool";
    }
#line 2898 "y.tab.c"
    break;

  case 113: /* ast_expr: FALSE  */
#line 1117 "limbaj.y"
            {
        (yyval.astNode) = new ASTNode("false", "LITERAL");
        (yyval.astNode)->expressionType = "bool";
    }
#line 2907 "y.tab.c"
    break;

  case 114: /* ast_expr: ast_expr GT ast_expr  */
#line 1122 "limbaj.y"
                           {
        if((yyvsp[-2].astNode)->expressionType != (yyvsp[0].astNode)->expressionType) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Comparison '>' requires same types (got %s and %s)", (yyvsp[-2].astNode)->expressionType.c_str(), (yyvsp[0].astNode)->expressionType.c_str());
            yyerror(errMsg);
        }
        (yyval.astNode) = new ASTNode(">", "OP", (yyvsp[-2].astNode), (yyvsp[0].astNode));
        (yyval.astNode)->expressionType = "bool";
    }
#line 2921 "y.tab.c"
    break;

  case 115: /* ast_expr: ast_expr LT ast_expr  */
#line 1131 "limbaj.y"
                           {
        if((yyvsp[-2].astNode)->expressionType != (yyvsp[0].astNode)->expressionType) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Comparison '<' requires same types (got %s and %s)", (yyvsp[-2].astNode)->expressionType.c_str(), (yyvsp[0].astNode)->expressionType.c_str());
            yyerror(errMsg);
        }
        (yyval.astNode) = new ASTNode("<", "OP", (yyvsp[-2].astNode), (yyvsp[0].astNode));
        (yyval.astNode)->expressionType = "bool";
    }
#line 2935 "y.tab.c"
    break;

  case 116: /* ast_expr: ast_expr EQ ast_expr  */
#line 1140 "limbaj.y"
                           {
        if((yyvsp[-2].astNode)->expressionType != (yyvsp[0].astNode)->expressionType) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Comparison '==' requires same types (got %s and %s)", (yyvsp[-2].astNode)->expressionType.c_str(), (yyvsp[0].astNode)->expressionType.c_str());
            yyerror(errMsg);
        }
        (yyval.astNode) = new ASTNode("==", "OP", (yyvsp[-2].astNode), (yyvsp[0].astNode));
        (yyval.astNode)->expressionType = "bool";
    }
#line 2949 "y.tab.c"
    break;

  case 117: /* ast_expr: ast_expr NEQ ast_expr  */
#line 1149 "limbaj.y"
                            {
        if((yyvsp[-2].astNode)->expressionType != (yyvsp[0].astNode)->expressionType) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Comparison '!=' requires same types (got %s and %s)", (yyvsp[-2].astNode)->expressionType.c_str(), (yyvsp[0].astNode)->expressionType.c_str());
            yyerror(errMsg);
        }
        (yyval.astNode) = new ASTNode("!=", "OP", (yyvsp[-2].astNode), (yyvsp[0].astNode));
        (yyval.astNode)->expressionType = "bool";
    }
#line 2963 "y.tab.c"
    break;

  case 118: /* ast_expr: ast_expr GE ast_expr  */
#line 1158 "limbaj.y"
                           {
        if((yyvsp[-2].astNode)->expressionType != (yyvsp[0].astNode)->expressionType) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Comparison '>=' requires same types (got %s and %s)", (yyvsp[-2].astNode)->expressionType.c_str(), (yyvsp[0].astNode)->expressionType.c_str());
            yyerror(errMsg);
        }
        (yyval.astNode) = new ASTNode(">=", "OP", (yyvsp[-2].astNode), (yyvsp[0].astNode));
        (yyval.astNode)->expressionType = "bool";
    }
#line 2977 "y.tab.c"
    break;

  case 119: /* ast_expr: ast_expr LE ast_expr  */
#line 1167 "limbaj.y"
                           {
        if((yyvsp[-2].astNode)->expressionType != (yyvsp[0].astNode)->expressionType) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Comparison '<=' requires same types (got %s and %s)", (yyvsp[-2].astNode)->expressionType.c_str(), (yyvsp[0].astNode)->expressionType.c_str());
            yyerror(errMsg);
        }
        (yyval.astNode) = new ASTNode("<=", "OP", (yyvsp[-2].astNode), (yyvsp[0].astNode));
        (yyval.astNode)->expressionType = "bool";
    }
#line 2991 "y.tab.c"
    break;

  case 120: /* ast_expr: ID  */
#line 1176 "limbaj.y"
         {
        (yyval.astNode) = new ASTNode(*(yyvsp[0].Id), "ID");
        (yyval.astNode)->expressionType = currentScope->exists(*(yyvsp[0].Id)) ? 
            currentScope->getType(*(yyvsp[0].Id)) : "error";
        delete (yyvsp[0].Id);
    }
#line 3002 "y.tab.c"
    break;

  case 121: /* ast_expr: ID '.' ID '(' call_list_ast ')'  */
#line 1182 "limbaj.y"
                                      {
        if(!currentScope->exists(*(yyvsp[-5].Id))) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Variable '%s' not declared", (yyvsp[-5].Id)->c_str());
            yyerror(errMsg);
        }
        string classType = currentScope->exists(*(yyvsp[-5].Id)) ? 
            currentScope->getType(*(yyvsp[-5].Id)) : "error";
        string returnType = "error";
        if(globalTable->classExists(classType)) {
            returnType = globalTable->getMethodReturnType(classType, *(yyvsp[-3].Id));
        }
        string methodCallInfo = *(yyvsp[-5].Id) + "." + *(yyvsp[-3].Id);
        ASTNode* methodCallNode = new ASTNode(methodCallInfo, "OTHER");
        methodCallNode->expressionType = returnType;
        if (!(yyvsp[-1].AstList).nodes->empty()) methodCallNode->left = (*(yyvsp[-1].AstList).nodes)[0];
        (yyval.astNode) = methodCallNode;
        delete (yyvsp[-5].Id);
        delete (yyvsp[-3].Id);
        delete (yyvsp[-1].AstList).nodes;
    }
#line 3028 "y.tab.c"
    break;

  case 122: /* ast_expr: ID '(' call_list_ast ')'  */
#line 1203 "limbaj.y"
                               {  
    if(!globalTable->functionExists(*(yyvsp[-3].Id))) {
        char errMsg[256];
        sprintf(errMsg, "Semantic Error: Function '%s' not declared", (yyvsp[-3].Id)->c_str());
        yyerror(errMsg);
        (yyval.astNode) = new ASTNode("error", "ERROR");
    } else {
        string returnType = globalTable->getFunctionReturnType(*(yyvsp[-3].Id));

        vector<pair<string,string>> expected = globalTable->getFunctionParams(*(yyvsp[-3].Id)); // pereche (tip, nume)
        if(expected.size() != (yyvsp[-1].AstList).nodes->size()) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Wrong number of arguments for function '%s' (expected %lu, got %lu)",
                    (yyvsp[-3].Id)->c_str(), expected.size(), (yyvsp[-1].AstList).nodes->size());
            yyerror(errMsg);
        } else {
            for(size_t i = 0; i < expected.size(); i++) {
                string argType = (*(yyvsp[-1].AstList).nodes)[i]->expressionType;
                if(expected[i].first != argType) {
                    char errMsg[256];
                    sprintf(errMsg, "Semantic Error: Argument %lu type mismatch in call to '%s' (expected %s, got %s)",
                            i+1, (yyvsp[-3].Id)->c_str(), expected[i].first.c_str(), argType.c_str());
                    yyerror(errMsg);
                }
            }
        }

        ASTNode* funcCallNode = new ASTNode(*(yyvsp[-3].Id) + "()", "CALL");
        funcCallNode->expressionType = returnType;

        if (!(yyvsp[-1].AstList).nodes->empty()) {
            funcCallNode->left = (*(yyvsp[-1].AstList).nodes)[0];
            if ((yyvsp[-1].AstList).nodes->size() > 1) funcCallNode->right = (*(yyvsp[-1].AstList).nodes)[1];
        }

        (yyval.astNode) = funcCallNode;
    }

    delete (yyvsp[-3].Id);
    delete (yyvsp[-1].AstList).nodes;
}
#line 3074 "y.tab.c"
    break;

  case 123: /* ast_expr: ID '.' ID  */
#line 1244 "limbaj.y"
                {
        if(!currentScope->exists(*(yyvsp[-2].Id))) {
            yyerror("Semantic Error: Object not declared");
            (yyval.astNode) = new ASTNode("error", "ERROR");
        } else {
            string classType = currentScope->getType(*(yyvsp[-2].Id));
            if(!globalTable->classHasField(classType, *(yyvsp[0].Id))) {
                yyerror("Semantic Error: Field not found");
                (yyval.astNode) = new ASTNode("error", "ERROR");
            } else {
                string fType = globalTable->getFieldType(classType, *(yyvsp[0].Id));
                ASTNode* obj = new ASTNode(*(yyvsp[-2].Id), "ID");
                ASTNode* field = new ASTNode(*(yyvsp[0].Id), "FIELD");
                (yyval.astNode) = new ASTNode(".", "ACCESS", obj, field);
                (yyval.astNode)->expressionType = fType; // Foarte important pentru oba.x * oba.y
            }
        }
        delete (yyvsp[-2].Id); delete (yyvsp[0].Id);
    }
#line 3098 "y.tab.c"
    break;

  case 124: /* ast_expr: ast_expr '+' ast_expr  */
#line 1264 "limbaj.y"
                            {
        if((yyvsp[-2].astNode)->expressionType != (yyvsp[0].astNode)->expressionType) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Operands of '+' must have the same type (got %s and %s)",
                    (yyvsp[-2].astNode)->expressionType.c_str(), (yyvsp[0].astNode)->expressionType.c_str());
            yyerror(errMsg);
        }
        (yyval.astNode) = new ASTNode("+", "OP", (yyvsp[-2].astNode), (yyvsp[0].astNode));
        (yyval.astNode)->expressionType = (yyvsp[-2].astNode)->expressionType;
    }
#line 3113 "y.tab.c"
    break;

  case 125: /* ast_expr: ast_expr '-' ast_expr  */
#line 1274 "limbaj.y"
                            {
        if((yyvsp[-2].astNode)->expressionType != (yyvsp[0].astNode)->expressionType) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Operands of '-' must have the same type (got %s and %s)",
                    (yyvsp[-2].astNode)->expressionType.c_str(), (yyvsp[0].astNode)->expressionType.c_str());
            yyerror(errMsg);
        }
        (yyval.astNode) = new ASTNode("-", "OP", (yyvsp[-2].astNode), (yyvsp[0].astNode));
        (yyval.astNode)->expressionType = (yyvsp[-2].astNode)->expressionType;
    }
#line 3128 "y.tab.c"
    break;

  case 126: /* ast_expr: ast_expr '*' ast_expr  */
#line 1284 "limbaj.y"
                            {
        if((yyvsp[-2].astNode)->expressionType != (yyvsp[0].astNode)->expressionType) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Operands of '*' must have the same type (got %s and %s)",
                    (yyvsp[-2].astNode)->expressionType.c_str(), (yyvsp[0].astNode)->expressionType.c_str());
            yyerror(errMsg);
        }
        (yyval.astNode) = new ASTNode("*", "OP", (yyvsp[-2].astNode), (yyvsp[0].astNode));
        (yyval.astNode)->expressionType = (yyvsp[-2].astNode)->expressionType;
    }
#line 3143 "y.tab.c"
    break;

  case 127: /* ast_expr: ast_expr '/' ast_expr  */
#line 1294 "limbaj.y"
                            {
        if((yyvsp[-2].astNode)->expressionType != (yyvsp[0].astNode)->expressionType) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Operands of '/' must have the same type (got %s and %s)",
                    (yyvsp[-2].astNode)->expressionType.c_str(), (yyvsp[0].astNode)->expressionType.c_str());
            yyerror(errMsg);
        }
        (yyval.astNode) = new ASTNode("/", "OP", (yyvsp[-2].astNode), (yyvsp[0].astNode));
        (yyval.astNode)->expressionType = (yyvsp[-2].astNode)->expressionType;
    }
#line 3158 "y.tab.c"
    break;

  case 128: /* ast_expr: ast_expr '%' ast_expr  */
#line 1304 "limbaj.y"
                            {
        if((yyvsp[-2].astNode)->expressionType != (yyvsp[0].astNode)->expressionType) {
            char errMsg[256];
            sprintf(errMsg, "Semantic Error: Operands of '%%' must have the same type (got %s and %s)",
                    (yyvsp[-2].astNode)->expressionType.c_str(), (yyvsp[0].astNode)->expressionType.c_str());
            yyerror(errMsg);
        }
        (yyval.astNode) = new ASTNode("%", "OP", (yyvsp[-2].astNode), (yyvsp[0].astNode));
        (yyval.astNode)->expressionType = (yyvsp[-2].astNode)->expressionType;
    }
#line 3173 "y.tab.c"
    break;

  case 129: /* ast_expr: '(' ast_expr ')'  */
#line 1314 "limbaj.y"
                       { 
        (yyval.astNode) = (yyvsp[-1].astNode); 
    }
#line 3181 "y.tab.c"
    break;

  case 130: /* ast_expr: ast_expr AND ast_expr  */
#line 1317 "limbaj.y"
                           {
        if ((yyvsp[-2].astNode)->expressionType != "bool" || (yyvsp[0].astNode)->expressionType != "bool") {
            yyerror("Operands of 'AND' must be bool");
            (yyval.astNode) = new ASTNode("AND", "OP");
            (yyval.astNode)->expressionType = "error";
        } else {
            (yyval.astNode) = new ASTNode("AND", "OP", (yyvsp[-2].astNode), (yyvsp[0].astNode));
            (yyval.astNode)->expressionType = "bool";
        }
    }
#line 3196 "y.tab.c"
    break;

  case 131: /* ast_expr: ast_expr OR ast_expr  */
#line 1327 "limbaj.y"
                           {
        if ((yyvsp[-2].astNode)->expressionType != "bool" || (yyvsp[0].astNode)->expressionType != "bool") {
            yyerror("Operands of 'OR' must be bool");
            (yyval.astNode) = new ASTNode("OR", "OP");
            (yyval.astNode)->expressionType = "error";
        } else {
            (yyval.astNode) = new ASTNode("OR", "OP", (yyvsp[-2].astNode), (yyvsp[0].astNode));
            (yyval.astNode)->expressionType = "bool";
        }
    }
#line 3211 "y.tab.c"
    break;

  case 132: /* ast_expr: NOT ast_expr  */
#line 1337 "limbaj.y"
                   {
        if ((yyvsp[0].astNode)->expressionType != "bool") {
            yyerror("Operand of 'NOT' must be bool");
            (yyval.astNode) = new ASTNode("NOT", "OP");
            (yyval.astNode)->expressionType = "error";
        } else {
            (yyval.astNode) = new ASTNode("NOT", "OP", (yyvsp[0].astNode), nullptr);
            (yyval.astNode)->expressionType = "bool";
        }
    }
#line 3226 "y.tab.c"
    break;

  case 139: /* call_list: %empty  */
#line 1353 "limbaj.y"
                  { 
        (yyval.StrList).list = new vector<string>(); 
    }
#line 3234 "y.tab.c"
    break;

  case 140: /* call_list: expr  */
#line 1356 "limbaj.y"
           {
        (yyval.StrList).list = new vector<string>();
        (yyval.StrList).list->push_back((yyvsp[0].TypeName));
    }
#line 3243 "y.tab.c"
    break;

  case 141: /* call_list: call_list ',' expr  */
#line 1360 "limbaj.y"
                         {
        (yyvsp[-2].StrList).list->push_back((yyvsp[0].TypeName));
        (yyval.StrList) = (yyvsp[-2].StrList);
    }
#line 3252 "y.tab.c"
    break;

  case 142: /* call_list_ast: %empty  */
#line 1366 "limbaj.y"
                  { 
        (yyval.AstList).nodes = new vector<ASTNode*>(); 
    }
#line 3260 "y.tab.c"
    break;

  case 143: /* call_list_ast: ast_expr  */
#line 1369 "limbaj.y"
               {
        (yyval.AstList).nodes = new vector<ASTNode*>();
        (yyval.AstList).nodes->push_back((yyvsp[0].astNode));
    }
#line 3269 "y.tab.c"
    break;

  case 144: /* call_list_ast: call_list_ast ',' ast_expr  */
#line 1373 "limbaj.y"
                                 {
        (yyvsp[-2].AstList).nodes->push_back((yyvsp[0].astNode));
        (yyval.AstList) = (yyvsp[-2].AstList);
    }
#line 3278 "y.tab.c"
    break;


#line 3282 "y.tab.c"

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

#line 1383 "limbaj.y"


void yyerror(const char * s){
    errorCount++;
    fprintf(stderr, "Error: %s at line: %d\n", s, yylineno);
}

int main(int argc, char** argv){
    if(argc < 2) {
        cout << "Usage: ./minilang file\n";
        return 1;
    }
    yyin = fopen(argv[1], "r");
    if(!yyin) {
        perror("File opening failed");
        return 1;
    }
    yyparse();
    return 0;
}
