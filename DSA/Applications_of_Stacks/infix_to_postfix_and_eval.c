//Infix to Postfix and evaluate the expression
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 50
int top;
char infix[MAX],postfix[MAX];
long int stack[MAX];

int isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
int whitespace(char symbol)
{
	if(symbol==' '||symbol=='\t')
		return 1;
	else 
		return 0;
}
void push(long int symbol)
{
	if(top>MAX)
	{
		printf("Stack Overflow\n");
		exit(1);
	}
	top++;
	stack[top]=symbol;
}
long int pop()
{
	if(isEmpty())
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	return stack[top--];
}

int priority(char symbol)
{
	switch(symbol)
	{
		case '(':
			return 0;
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
		case '%':
			return 2;
		case '^':
			return 3;
		default:
			return 0;
	}
}
long int evalpost()
{
	long int a,b,temp,result;
	unsigned int i;
	for(i=0;i<strlen(postfix);i++)
	{
		if(postfix[i]<='9'&&postfix[i]>='0')
			push(postfix[i]-'0');
		else
		{
			a=pop();
			b=pop();
			switch(postfix[i])
			{
				case '+':
					temp=b+a;
					break;
				case '-':
					temp=b-a;
					break;
				case '*':
					temp=b*a;
					break;
				case '/':
					temp=b/a;
					break;
				case '%':
					temp=b%a;
					break;
				case '^':
					temp=pow(b,a);
					break;
			}
			push(temp);
		}
	}
	result=pop();
	return result;
}

void infixTOpostfix()
{
	unsigned int i,p=0;
	char next;
	char symbol;
	for(i=0;i<strlen(infix);i++)
	{
		symbol=infix[i];
		if(!whitespace(symbol))
		{
			switch(symbol)
			{
				case '(':
					push(symbol);
					break;
				case ')':
					while((next=pop())!='(')
						postfix[p++]=next;
					break;
				case '+':
				case '-':
				case '*':
				case '/':
				case '%':
				case '^':
					while(!isEmpty()&&priority(stack[top])>=priority(symbol))
						postfix[p++]=pop();
					push(symbol);
					break;
				default:
					postfix[p++]=symbol;
			}
		}
	}
	while(!isEmpty())
		postfix[p++]=pop();
	postfix[p]='\0';
}

int main()
{
	long int value;
	top=-1;
	printf("Enter infix exp: ");
	gets(infix);
	infixTOpostfix();
	printf("Postfix exp: ");
	puts(postfix);
	printf("Value of exp: %ld",evalpost());
}
