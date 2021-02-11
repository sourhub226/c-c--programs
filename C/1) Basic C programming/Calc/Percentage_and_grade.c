#include <stdio.h>
#include <conio.h>

void main()
{
	int a,b,c,d,e,f,sum;
	float p;
	printf("Enter marks obtained in sub 1 (out of 100 marks):");
	scanf("%d",&a);
	printf("Enter marks obtained in sub 2 (out of 100 marks):");
	scanf("%d",&b);
	printf("Enter marks obtained in sub 3 (out of 100 marks):");
	scanf("%d",&c);
	printf("Enter marks obtained in sub 4 (out of 100 marks):");
	scanf("%d",&d);
	printf("Enter marks obtained in sub 5 (out of 100 marks):");
	scanf("%d",&e);
	printf("Enter marks obtained in sub 6 (out of 100 marks):");
	scanf("%d",&f);
	
	sum=a+b+c+d+e+f;
	p=(sum/600.00)*100.00;
	
	printf("\nTotal marks obtained:%d",sum);
	printf("\nPercentage:%2.2f %%",p);
	
	if(p>=90 && p<=100)
	{
		printf("\nGrade:A");
		printf("\nYour performance is Exceptional");
	}
	
	if(p>=80 && p<=89)
	{
		printf("\nGrade:B");
		printf("\nYour performance is Excellent");
	}
	
	if(p>=70 && p<=79)
	{
		printf("\nGrade:C");
		printf("\nYour performance is Good");
	}
	
	if(p>=60 && p<=69)
	{
		printf("\nGrade:D");
		printf("\nYour performance is Satisfactory");
	}
	
	if(p>=50 && p<=59)
	{
		printf("\nGrade:E");
		printf("\nYour performance is Barely Acceptable");
	}
	
	if(p>=0 && p<=49)
	{
		printf("\nGrade:F");
		printf("\nYour performance is Unacceptable");
	}
	
	
	getch();
	
}
