%{
#include<stdio.h>
#include<stdlib.h>
int comment = 0;
%}

identifier [a-zA-Z][a-zA-Z0-9]*
digit [0-9]+

%%
#.* printf("\n is a header file");
int printf("\nINT keyword");
float printf("\nFLOAT keyword");
for printf("\nFOR keyword");
while printf("\nWHILE keyword");
break printf("\nBREAK keyword");
"/*" comment = 1;
"*/" comment = 0;
"//"+.*$ if(!comment)printf("\n %s is a COMMENT",yytext);
\{  if(!comment)printf("\n %s CURLY BRACES START\n",yytext);
\}  if(!comment)printf("\n %s CURLY BRACES END\n",yytext);
\(  if(!comment)printf("\n %s PARENTHESIS START\n",yytext);
\)  if(!comment)printf("\n %s PARENTHESIS END\n",yytext);
{identifier}(\[[0-9]*\])? if(!comment) printf("\n %s IDENTIFIER",yytext);
[0-9]+ printf("\n %s is digit",yytext);
\+ | \- | \* | \/ if(!comment) printf("\n %s Arithmetic Operator",yytext);
[<][=] | [>][=] | [<] | [>] | [!][=] | [=][=] if(!comment) printf("\n %s is a RELATIONAL OPERATOR",yytext);
%%

int main(int argc, char* argv[])
{
	if(argc<2)
	{
		printf("error");
		return 0;
	}
	int token;
	yyin = fopen(argv[1],"r");
	while((token = yylex())>0)
	{
		printf("%s ==== %d",yytext,token);
	}
}
