#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int top = -1,i;
char arr[10];

void push(char a[]){
	for(i=0;a[i]!='\0';i++){
    	if(top<9)
    	arr[++top] = a[i];
  	}
}
void pop(){
	if(top >= 0)
    	arr[top--]='\0';
}
void print_stack(){
	for(i=0;i<=top;i++){
		printf("%c",arr[i]);
	}
}
void print_ip_str(char a[], int x){
	printf("\t");
	for(i=x;a[i] != '\0';i++){
		printf("%c",a[i]);
	}
}
char *strrev(char *str){
    i = strlen(str) - 1;
    int j = 0;
    char ch;
    while (i > j){
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}
int main(){
	char input[20],rev[20];
	char curr_sym,s_top;
	int r,c;
	char table[5][6][10]={// i 	   +     *     (      )    $

		/*E*/				"TA", "$" , "$" , "TA" , "$", "$",
		/*A*/				"$" ,"+TA", "$" , "$"  , "e", "e",
		/*T*/ 				"FB", "$" , "$" , "FB" , "$", "$",
		/*B*/		   		"$" , "e" ,"*FB", "$"  , "e", "e",
		/*F*/ 			 	"i" , "$" , "$" , "(E)", "$", "$"
		   				 };

	fflush(stdin);
	printf("Enter the input string(Put $ in the end) : ");
	fgets(input,20,stdin);
	input[strlen(input)-1] = '\0';
	printf("\n");
	printf("Stack\tInput\tOutput\n");
  	push("$E");
  	print_stack();
  	printf("\t%s\n",input);

	int k = 0;
	while(input[k] != '\0'){
		if(arr[top] == curr_sym){
		    pop();
		    print_stack();
		    print_ip_str(input,k+1);
		    printf("\tPOP\n");
	  	    k++;
    	}
    	curr_sym = input[k];
		s_top = arr[top];

		if(s_top == 'E')
			r = 0;
		else if(s_top == 'A')
			r = 1;
		else if(s_top == 'T')
			r = 2;
		else if(s_top == 'B')
			r = 3;
		else if(s_top == 'F')
			r = 4;
		else{
			printf("Syntax Error\n");
			break;
		}

		if(curr_sym >= 'a' && curr_sym <='z'){
	        c = 0;
	        curr_sym ='i';
	    }
	    else if(curr_sym >= 'A' && curr_sym <= 'Z'){
	    	printf("\nThere is a non-terminal : %c\n",curr_sym);
	    	break;
	    }
		else if(curr_sym == '+')
			c = 1;
		else if(curr_sym == '*')
			c = 2;
		else if(curr_sym == '(')
			c = 3;
		else if(curr_sym == ')')
			c = 4;
		else if(curr_sym == '$')
			c = 5;
		
		strcpy(rev,strrev(table[r][c]));
		strrev(table[r][c]);
		pop();
		push(rev);
		
		if(arr[top] == 'e'){
		    pop();
		    print_stack();
		    print_ip_str(input,k);
		    printf("\t%c->%c\n",s_top,'e');
	    }
	    else{
	    	print_stack();
	      	print_ip_str(input,k);
	      	printf("\t%c->%s\n",s_top,table[r][c]);
	    }
	    if(arr[top] == '$' && curr_sym =='$')
	      	break;
	    if(arr[top] == '$'){
			printf("\nSYNTAX ERROR\n");
			break;
		}
	}
	
	int temp = strcmp(arr,"$");
    if(temp == 0 && i == strlen(input))
    	printf("\nGiven String is accepted.\n");
    else
    	printf("\nGiven String is not accepted.\n");
	return 0;
}

