//String Reverse fn
#include <stdio.h>
#include <string.h>

int main()
{
	char s1[30];
	printf("Enter string: ");
	gets(s1);
	strrev(s1);
	printf("Reversed String = %s",s1);
}
