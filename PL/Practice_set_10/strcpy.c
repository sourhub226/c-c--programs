//String Copy fn
#include <stdio.h>
#include <string.h>

int main()
{
	char source[30],target[30];
	printf("Enter source string: ");
	gets(source);
	printf("Enter target string: ");
	gets(target);
	strcpy(target,source);
	printf("Source = %s\n",source);
	printf("Target = %s",target);
}
