/* A Bison parser, made by GNU Bison 3.0.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_GRAMMAR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 2 "grammar.y" /* yacc.c:1909  */

	#include "SyntaxTree.hpp"

#line 48 "grammar.tab.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MINUS = 258,
    IF = 259,
    WHILE = 260,
    ASSIGN = 261,
    PRINT = 262,
    INTEGER = 263,
    ADD = 264,
    SUBSTRACT = 265,
    VAR = 266,
    OPEN_PARENTHESIS = 267,
    CLOSE_PARENTHESIS = 268,
    FALSE = 269,
    SEMICOLON = 270,
    NUL = 271,
    FORSAKEN_BEGIN = 272,
    FORSAKEN_END = 273,
    DIVIDE = 274,
    EQUAL = 275,
    LT = 276,
    OPEN_BRACES = 277,
    CLOSE_BRACES = 278,
    MULTIPLY = 279,
    EXIT = 280,
    ABSOLUTE = 281,
    SIN = 282,
    GT = 283,
    SQRT = 284,
    COS = 285,
    NEGATIVE = 286,
    REAL = 287,
    INPUT = 288,
    TRUE = 289,
    INICIALIZE = 290
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef compiler::SyntaxTree* YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */
