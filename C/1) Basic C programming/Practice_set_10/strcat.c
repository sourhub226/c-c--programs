//String Concatenate fn
#include <stdio.h>
#include <string.h>

int main()
{
	char source[30],target[30];
	printf("Enter source string: ");
	gets(source);
	printf("Enter target string: ");
	gets(target);
	strcat(target,source);
	printf("\nSource = %s\n",source);
	printf("Target = %s",target);
}
