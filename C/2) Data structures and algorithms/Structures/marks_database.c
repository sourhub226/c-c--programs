// To implement student database using structures
#include <stdio.h>
#include<stdlib.h>
struct results
{
	int no_of_students;
	int sum;
	float percentage;
	char *final_result;
	
};
struct subject
{
	int marks;
	char *result;
};
struct student
{
   int rollno;
   char name[100];
   int year;
   struct subject s[100];
   struct results r;
};


struct student input(void)
{
	struct student s1[100];
	int i, j,no;
	printf("Enter number of students: ");
	scanf("%d", &s1[50].r.no_of_students);
	for(i = 0; i <s1[50].r.no_of_students ; i++)
   {
	j=0;
	printf("\nEnter Student %d info:\n",i+1);
	printf("Name: ");
	scanf("%s",&s1[i].name);
	printf("Roll No: ");
	scanf("%d",&s1[i].rollno);
	printf("Year of study: ");
	scanf("%d",&s1[i].year);
	printf("Enter marks: \n");
		for(j=0;j<6;j++)
		{
			printf("Sub %d: ",j+1);
			scanf("%d",&s1[i].s[j].marks);
		}
        
   }
   return s1[i];
}
struct student operate(void)
{
	struct student s1[100];
	int i,j,flag;
	for(i = 0; i <s1[50].r.no_of_students;i++)
   {
  		flag=0;
   		for(j=0;j<6;j++)
   		{
   			if(s1[i].s[j].marks>=40)
   				s1[i].s[j].result="PASS";
   			else
   				s1[i].s[j].result="FAIL";		
		}
		for(j=0;j<6;j++)
   		{
   			s1[i].r.sum+=s1[i].s[j].marks;		
		}
		s1[i].r.percentage=(s1[i].r.sum/600.00)*100.00;
		for(j=0;j<6;j++)
		{
			if(s1[i].s[j].result=="FAIL")
				flag=1;
		}
		if(flag==0)
		{
			if (s1[i].r.percentage>=75)
				s1[i].r.final_result="DISTINCTION";
			else if(s1[i].r.percentage>=60&&s1[i].r.percentage<75)
				s1[i].r.final_result="FIRST CLASS";
			else if(s1[i].r.percentage>=50&&s1[i].r.percentage<60)
				s1[i].r.final_result="SECOND CLASS";
			else if(s1[i].r.percentage>=40&&s1[i].r.percentage<50)
				s1[i].r.final_result="PASS CLASS";
		}
		else
			s1[i].r.final_result="FAIL";
	}
	return s1[i];
}
struct student output(void)
{
	struct student s1[100];
	int i,j;
	
	
	printf("\nMARKSHEET:\n");
   for(i = 0; i <s1[50].r.no_of_students;i++)
   {
  	j=0;
  	printf("Name:%s\tRoll no:%d\tYear of study:%d\n",s1[i].name,s1[i].rollno,s1[i].year);
  	printf("Subject\t\tMarks\t\tResult\n");
   		for(j=0;j<6;j++)
   		{
   			printf("Sub %d\t\t%d\t\t%s\n",j+1,s1[i].s[j].marks,s1[i].s[j].result);
   			
		}
		printf("TOTAL: %d/600\n",s1[i].r.sum);
		printf("PERCENTAGE: %.2f%%\n",s1[i].r.percentage);
		printf("OVERALL RESULT: %s\n",s1[i].r.final_result);
		printf("\n");
	}
	return s1[i];
}
int main()
{
	struct student s1[100];
  	input();
  	operate();
   	output();
 
   return 0;
}
