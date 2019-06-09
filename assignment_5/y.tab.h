/* A Bison parser, made by GNU Bison 3.2.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    LPAREN_TOK = 258,
    RPAREN_TOK = 259,
    LBRACES_TOK = 260,
    RBRACES_TOK = 261,
    SEMICOL_TOK = 262,
    TYPE_TOK = 263,
    DIGIT_TOK = 264,
    COMMA_TOK = 265,
    ID_TOK = 266,
    CHAR_TOK = 267,
    STRING_TOK = 268,
    EQL_TOK = 269,
    GRTR_TOK = 270,
    LES_TOK = 271,
    GRTREQL_TOK = 272,
    LESEQL_TOK = 273,
    QUES_TOK = 274,
    COL_TOK = 275,
    CHKEQL_TOK = 276,
    IF_TOK = 277,
    ELSE_TOK = 278,
    ELSEIF_TOK = 279,
    FOR_TOK = 280,
    PLUS_TOK = 281,
    MINUS_TOK = 282,
    MULT_TOK = 283,
    DIV_TOK = 284,
    XOR_TOK = 285,
    MOD_TOK = 286,
    INCRMNT_TOK = 287,
    DECRMNT_TOK = 288
  };
#endif
/* Tokens.  */
#define LPAREN_TOK 258
#define RPAREN_TOK 259
#define LBRACES_TOK 260
#define RBRACES_TOK 261
#define SEMICOL_TOK 262
#define TYPE_TOK 263
#define DIGIT_TOK 264
#define COMMA_TOK 265
#define ID_TOK 266
#define CHAR_TOK 267
#define STRING_TOK 268
#define EQL_TOK 269
#define GRTR_TOK 270
#define LES_TOK 271
#define GRTREQL_TOK 272
#define LESEQL_TOK 273
#define QUES_TOK 274
#define COL_TOK 275
#define CHKEQL_TOK 276
#define IF_TOK 277
#define ELSE_TOK 278
#define ELSEIF_TOK 279
#define FOR_TOK 280
#define PLUS_TOK 281
#define MINUS_TOK 282
#define MULT_TOK 283
#define DIV_TOK 284
#define XOR_TOK 285
#define MOD_TOK 286
#define INCRMNT_TOK 287
#define DECRMNT_TOK 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
