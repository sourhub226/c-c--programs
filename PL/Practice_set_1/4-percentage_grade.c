/*to input marks of 5 subs and calc the percentage and grade acc to the foll condition 
%>90  A
 >80  B
 >70  C
 >60  D
 <60  F*/
 
#include <stdio.h>

int main()
{
	int a,b,c,d,e,sum;
	float p;
	printf("Enter marks obtained in 5 subjects (out of 100):");
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);	

	p=((a+b+c+d+e)/500.00)*100.00;

	
	if(a>0&b>0&c>0&d>0&e>0)
	{	
		printf("\nPercentage:%2.2f %%",p);
		if(p>=90)
			printf("\nGrade:A");
		if(p>=80 && p<=89)
			printf("\nGrade:B");
		if(p>=70 && p<=79)
			printf("\nGrade:C");
		if(p>=60 && p<=69)
			printf("\nGrade:D");
		if(p<60)
			printf("\nGrade:F");
	}
	else
		printf("The marks cannot be negative.");
	getch();
}

