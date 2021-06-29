//to check if an alphabet is a vowel or a consonant
#include <stdio.h>

int main()
{
	char ch;
	printf("Enter an alphabet: ");
	scanf("%c",&ch);
	
	if ((ch >= 'a' & ch <= 'z') | (ch >= 'A' & ch <= 'Z')) 
	{
		if(ch=='a'|ch=='e'|ch=='i'|ch=='o'|ch=='u'|ch=='A'|ch=='E'|ch=='I'|ch=='O'|ch=='U')
			printf("%c is a vowel",ch);
		else
			printf("%c is a consonant",ch);
	}
	else
		printf("%c is not an alphabet",ch);
	getch();
}
