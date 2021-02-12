//String Compare fn
#include <stdio.h>
#include <string.h>

int main()
{
	char s1[30],s2[30];
	printf("Enter string 1: ");
	gets(s1);
	printf("Enter string 2: ");
	gets(s2);
	if(strcmp(s1,s2)==0)
		printf("The 2 strings are equal");
	else
		printf("The 2 strings are not equal");
}
