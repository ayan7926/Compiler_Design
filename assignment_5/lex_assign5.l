%option yylineno
%{
	#include"y.tab.h"
%}

lalpha [a-z]
calpha [A-Z]
dgt [0-9]

%%

";" {return SEMICOL_TOK;}
"(" {return LPAREN_TOK;}
")" {return RPAREN_TOK;}
"{"	{return LBRACES_TOK;}
"}"	{return RBRACES_TOK;}
"int"|"char" {return TYPE_TOK;}
{dgt}+ {return DIGIT_TOK;}
"," {return COMMA_TOK;}
"\'"."\'"   {return CHAR_TOK;}
"\""."\""   {return STRING_TOK;}
"=" {return EQL_TOK;}
">"	{return GRTR_TOK;}
"<"	{return LES_TOK;}
">=" {return GRTREQL_TOK;}
"<=" {return LESEQL_TOK;}
"?" {return QUES_TOK;}
":" {return COL_TOK;}
"==" {return CHKEQL_TOK;}
"if" {return IF_TOK;}
"else" {return ELSE_TOK;}
"else if" {return ELSEIF_TOK;}
"for" {return FOR_TOK;}
"+" {return PLUS_TOK;}
"-" {return MINUS_TOK;}
"*" {return MULT_TOK;}
"/" {return DIV_TOK;}
"^" {return XOR_TOK;}
"%" {return MOD_TOK;}
"++" {return INCRMNT_TOK;}
"--" {return DECRMNT_TOK;}
[a-zA-Z_][a-zA-Z0-9_]* {return ID_TOK;}
%%

int yywrap(){
    return 1;
}
