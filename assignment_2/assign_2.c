#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define IDENTIFIER 100
#define KEYWORD 101
#define RELATIONAL_OPERATOR 102
#define DIGIT 103
#define ARITMETIC 104
#define BOOLEAN_OPERATOR 105
#define ASSIGNMENT_OPERATOR 106
#define BITWISE_OPERATOR 107
#define CURLY_BRACES 108
#define PARENTHESIS 109
#define DELIMETER 110
#define OTHER 200


FILE *yyin;
char ch;

int yylex()
{
	int state = 0;
	while(ch!=EOF)
	{
		switch(state)
		{
			case 0:	
					if(ch == ' ' || ch == '\t' || ch == '\n')
					{
						state = DELIMETER;
						return state;
					}
					else if(ch == '<')
					{
						state = 1;
					}
					else if(ch == '=')
					{
						state = 5;
					}
					else if(ch == '>')
					{
						state = 6;
					}
					else if(ch == 'f')
					{
						state = 10;							// f- 10, o- 11, r- Z 	//---Z --> Keyword // f-10, l- 12, o- 13, a- 14, t- Z'
					}
					else if(ch == 'w')
					{
						state = 15;							// w- 15, h- 16, i- 17, l- 18, e- Z
					}
					else if(ch == 'c')
					{
						state = 19;							// c- 19, h- 20, a- 21, r- Z'
					}
					else if(ch == 'i')
					{
						state = 22;							// i- 22, n- 23, t- Z'	// i- 22, f- Z
					}
					else if(ch == 'e')
					{
						state = 24;							// e- 24, l- 25, s- 26, e- Z
					}
					else if(isdigit(ch))
					{
						state = 32;							// Numeric- 27
					}
					else if(ch == '+')
					{
						state = ARITMETIC;
						return state;
					}
					else if(ch == '-')
					{
						state = ARITMETIC;
						return state;
					}
					else if(ch == '*')
					{
						state = ARITMETIC;
						return state;
					}
					else if(ch == '/')
					{
						state = ARITMETIC;
						return state;
					}
					else if(ch == '&')
					{
						state = 28;
					}
					else if(ch == '|')
					{
						state = 29;
					}
					else if(ch == '{')
					{
						state = CURLY_BRACES;
						return state;
					}
					else if(ch == '}')
					{
						state = CURLY_BRACES;
						return state;
					}
					else if(ch == '(')
					{
						state = PARENTHESIS;
						return state;
					}
					else if(ch == ')')
					{
						state = PARENTHESIS;
						return state;
					}
					else
					{
						//printf("H");
						state = 30;
					}
			break;
			case 1:	ch = fgetc(yyin);
					if(ch == '=')
					{
						state = RELATIONAL_OPERATOR;
						return state;
					}
					else if(ch == '>')
					{
						state = RELATIONAL_OPERATOR;
						return state;
					}
					else
					{
						state = RELATIONAL_OPERATOR;
						return state;
					}
			break;
			case 5:	ch = fgetc(yyin);
					if(ch=='=')
					{
						state = RELATIONAL_OPERATOR;
						return state;
					}
					else
					{
						state = ASSIGNMENT_OPERATOR;
						return state;
					}
			break;
			case 6:	ch = fgetc(yyin);
					if(ch == '=')
					{
						state = 8;
						return state;
					}
					else
					{
						state = 9;
						return state;
					}
			break;
			case 10:ch = fgetc(yyin);
					if(ch == 'o')
					{
						state = 11;
					}
					else if(ch == 'l')
					{
						state = 12;
					}
					else
					{
						state = 30;
					}
			break;
			case 11:ch = fgetc(yyin);
					if(ch == 'r')
					{
						state = 31;
					}
					else
					{
						state = 30;
					}
			break;
			case 12:ch = fgetc(yyin);
					if(ch == 'o')
					{
						state = 13;
					}
					else
					{
						state  = 30;
					}
			break;
			case 13:ch = fgetc(yyin);
					if(ch == 'a')
					{
						state = 14;
					}
					else
					{
						state = 30;
					}
			break;
			case 14:ch = fgetc(yyin);
					if(ch == 't')
					{
						state = 31;
					}
					else
					{
						state = 30;
					}
			break;
			case 15:ch = fgetc(yyin);
					if(ch == 'h')
					{
						state = 16;
					}
					else
					{
						state = 30;
					}
			break;
			case 16:ch = fgetc(yyin);
					if(ch == 'i')
					{
						state = 17;
					}
					else
					{
						state = 30;
					}
			break;
			case 17:ch = fgetc(yyin);
					if(ch == 'l')
					{
						state = 18;
					}
					else
					{
						state = 30;
					}
			break;
			case 18:ch = fgetc(yyin);
					if(ch == 'e')
					{
						state = 31;
					}
					else
					{
						state = 30;
					}
			break;
			case 19:ch = fgetc(yyin);
					if(ch == 'h')
					{
						state = 20;
					}
					else
					{
						state = 30;
					}
			break;
			case 20:ch = fgetc(yyin);
					if(ch == 'a')
					{
						state = 21;
					}
					else
					{
						state = 30;
					}
			break;
			case 21:ch = fgetc(yyin);
					if(ch == 'r')
					{
						state = 31;
					}
					else
					{
						state = 30;
					}
			break;
			case 22:ch = fgetc(yyin);
					if(ch == 'n')
					{
						state = 23;
					}
					else if(ch == 'f')
					{
						state = 31;
					}
					else
					{
						state = 30;
					}
			break;
			case 23:ch = fgetc(yyin);
					if(ch == 't')
					{
						state = 31;
					}
					else
					{
						state = 30;
					}
			break;
			case 24:ch = fgetc(yyin);
					if(ch == 'l')
					{
						state = 25;
					}
					else
					{
						state = 30;
					}
			break;
			case 25:ch = fgetc(yyin);
					if(ch == 's')
					{
						state = 26;
					}
					else
					{
						state = 30;
					}
			break;
			case 26:ch = fgetc(yyin);
					if(ch == 'e')
					{
						state = 31;
					}
					else
					{
						state = 30;
					}
			break;
			case 27:ch = fgetc(yyin);
					if(isdigit(ch))
					{
						//printf("P\n");
						state = 32;
					}
					else
					{
						state = 32;
					}
			break;
			case 28:ch = fgetc(yyin);
					if(ch == '&')
					{
						state = BOOLEAN_OPERATOR;
						return state;
					}
					else
					{
						state = BITWISE_OPERATOR;
						return state;
					}
			break;
			case 29:ch = fgetc(yyin);
					if(ch == '|')
					{
						state = BOOLEAN_OPERATOR;
						return state;
					}
					else
					{
						state = BITWISE_OPERATOR;
						return state;
					}
			break;
			case 30:ch = fgetc(yyin);
					if(ch == ' ' || ch == '\n' || ch == '\t' || ch == EOF)
					{
						state = OTHER;
						return state;
					}
					else
					{
						state = 30;
					}
			break;
			case 31:ch = fgetc(yyin);
					if(ch == ' ' || ch == '\n' || ch == '\t' || ch == EOF)
					{
						state = KEYWORD;
						return state;
					}
					else
					{
						state = 30;
					}
			break;
			case 32:ch = fgetc(yyin);
					if(ch == ' ' || ch == '\n' || ch == '\t'||ch==EOF)
					{
						state = DIGIT;
						return state;
					}
					else if(isdigit(ch))
					{
						state = 32;
					}
					else
					{
						state = 30;
					}
			break;
		}
	}
}

int main(int argc, char *argv[])
{
	int token;
	if(argc!=2)
	{
		printf("Error\n");
	}
	else
	{
		yyin = fopen(argv[1],"r");
		while(!feof(yyin))
		{
			ch = fgetc(yyin);
			//printf("Char =>:%c\n",ch);
			token = yylex();
			printf("STATE: %d\n",token);
			//printf("Char: %c\n",ch);
		}
	}
}

