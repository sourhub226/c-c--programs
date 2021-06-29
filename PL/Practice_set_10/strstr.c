//Substring fn
#include <stdio.h>
#include <string.h>

int main()
{
	char s1[30],s2[30];
	printf("Enter string 1: ");
	gets(s1);
	printf("Enter string 2: ");
	gets(s2);
	char *ret=strstr(s1,s2);
	printf("Substring = %s",ret);
}
