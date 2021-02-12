//String Length fn
#include <stdio.h>
#include <string.h>

int main()
{
	char arr[30];
	printf("Enter string: ");
	gets(arr);
	int l=strlen(arr);
	printf("Length=%d",l);
}

