/* 
#include <stdio.h>


FILE *yyin;
char *yytext;

int main(int argc, char const *argv[])
{
	int token;
	if (argc! = 2)
	{
		printf("error");
	}
	else
	{
		yyin=fopen(argv[1],"r");
		while(!feof(yyin))
		{
			token=yylex();
			printf("%d\n",token);
		}
		fclose(yyin);
	}
	return 0;
}

int yylex()
{
	char ch;
	if (yyin == NULL)
	{
		yyin = stdin;
	}
	ch=getc(fp);
	while (isspace(ch))
		ch =getc(fp);
	switch(ch)
	{
		case ';':case ',': case '=': // character tokens
		yytext[0]=ch;
		yyleng=1;
		return ch;
		case 'A': case 'B': case 'C': // lower case letter token
		case 'a': case 'b': case 'c': // uppper case letter token
	}
}
*/