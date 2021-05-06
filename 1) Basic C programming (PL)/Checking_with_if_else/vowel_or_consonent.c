// To check if the entered letter is vowel or consonent
#include <stdio.h>

int main()
{
	char ch;
	printf("Enter a letter: ");
	scanf("%c",&ch);
	
	if ((ch >= 'a' & ch <= 'z') | (ch >= 'A' & ch <= 'Z')) 
	{
		if(ch=='a'|ch=='e'|ch=='i'|ch=='o'|ch=='u'|ch=='A'|ch=='E'|ch=='I'|ch=='O'|ch=='U')
		{
			printf("\n%c is a vowel",ch);
		}
		else
		{
			printf("\n%c is a consonant",ch);
		}
	}
	else
	{
		printf("\n%c is neither a vowel nor a consonant",ch);
	}
	getch();
}
