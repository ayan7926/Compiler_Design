%{
	#include<stdio.h>
	int yylex(void);
	int yyerror(const char *s);
%}

%start DEBUG

%token LPAREN_TOK RPAREN_TOK LBRACES_TOK RBRACES_TOK SEMICOL_TOK
%token TYPE_TOK DIGIT_TOK COMMA_TOK ID_TOK CHAR_TOK STRING_TOK
%token EQL_TOK GRTR_TOK LES_TOK GRTREQL_TOK LESEQL_TOK QUES_TOK COL_TOK CHKEQL_TOK
%token IF_TOK ELSE_TOK ELSEIF_TOK FOR_TOK
%token PLUS_TOK MINUS_TOK MULT_TOK DIV_TOK XOR_TOK MOD_TOK
%token INCRMNT_TOK DECRMNT_TOK

%define parse.error verbose

%%

DEBUG:	START

START:	vardec START
	|	funcdef START
	|	%empty
	;

vardec:	TYPE_TOK vardefass
	;

vardefass:	ID_TOK SEMICOL_TOK											{printf("Variable Declared in correct ways\n");}
	|	ID_TOK COMMA_TOK vardefass
	|	ID_TOK EQL_TOK const COMMA_TOK vardefass
	|	ID_TOK EQL_TOK const SEMICOL_TOK								{printf("Variable Declared in correct ways\n");}
	;

const:	DIGIT_TOK
	|	CHAR_TOK
	|	STRING_TOK
	;

funcdef:	TYPE_TOK ID_TOK LPAREN_TOK defparameter RPAREN_TOK LBRACES_TOK insidefun RBRACES_TOK	{printf("Function Completed\n");}
	;

defparameter:	TYPE_TOK ID_TOK COMMA_TOK defparameter
	|		TYPE_TOK ID_TOK
	|		TYPE_TOK ID_TOK EQL_TOK const COMMA_TOK defparameter
	|		TYPE_TOK ID_TOK EQL_TOK const
	|		%empty
	;

insidefun:	vardec insidefun
	|		ifoperation insidefun																
	|		FOR_TOK LPAREN_TOK insidefor RPAREN_TOK loopstat insidefun							{printf("FOR LOOP Compelted\n");}
	|		assignstat insidefun																	
	|		funcalstat insidefun
	|		%empty
	;

ifoperation: IF_TOK LPAREN_TOK check RPAREN_TOK	LBRACES_TOK insidefun RBRACES_TOK elifstat				{printf("IF Completed\n");}
	;

insidefor:	ID_TOK EQL_TOK const SEMICOL_TOK ID_TOK comparator const SEMICOL_TOK ID_TOK boostoperator
	|		TYPE_TOK ID_TOK EQL_TOK const SEMICOL_TOK ID_TOK comparator const SEMICOL_TOK ID_TOK boostoperator
	;

comparator:	GRTREQL_TOK
	|		LES_TOK
	|		GRTR_TOK
	|		LESEQL_TOK
	|		CHKEQL_TOK
	;

boostoperator:	INCRMNT_TOK
	|	DECRMNT_TOK
	;

check:	ID_TOK comparator const
	;

elifstat:	ELSE_TOK LBRACES_TOK insidefun RBRACES_TOK elifstat
	|		ELSEIF_TOK LPAREN_TOK ID_TOK CHKEQL_TOK const RPAREN_TOK LBRACES_TOK insidefun RBRACES_TOK elifstat
	|		%empty
	;

loopstat:	LBRACES_TOK insidefun RBRACES_TOK
	;

assignstat:	ID_TOK EQL_TOK ID_TOK operator ID_TOK SEMICOL_TOK						{printf("Operator assigned\n");}
	|		ID_TOK EQL_TOK ID_TOK operator const SEMICOL_TOK						{printf("Operator assigned\n");}
	|		ID_TOK EQL_TOK const operator const SEMICOL_TOK							{printf("Operator assigned\n");}
	|		ID_TOK EQL_TOK const SEMICOL_TOK										{printf("Operator assigned\n");}
	;

operator:	PLUS_TOK
	|		MULT_TOK
	|		MINUS_TOK
	|		DIV_TOK
	|		MOD_TOK
	|		XOR_TOK
	;

funcalstat:	ID_TOK LPAREN_TOK parameter RPAREN_TOK SEMICOL_TOK				{printf(" Function Called\n");}
	;

parameter:	ID_TOK COMMA_TOK parameter
	|	ID_TOK
	|	%empty
	;

%%

int main() 
{
    return yyparse();
}

int yyerror(const char *s )
{ 
	extern int yylineno;
	printf("%s\n", s); 
}
