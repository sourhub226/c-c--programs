// To implement student database using structures
#include <stdio.h>
#include <stdlib.h>

struct semester
{
	int marks[6];
	int total;	
};
struct student
{
	char *name,*sclass;
	struct semester sem[8];
	int rollno;
	int year;
	int semtotal;
	float per;
};

int input(struct student *s,int n)
{
	int i,j,k,x,y;
	for(i=0;i<n;i++)
	{
		s->name=(char*)malloc(20*sizeof(char)); //dynamically allocating memory for char array
		s->sclass=(char*)malloc(20*sizeof(char));
		
		printf("Enter Student %d details\n",i+1);
		printf("Enter Name: ",i+1);
		scanf("%s",s->name); //pointing to structure variable
		printf("Enter Roll No: ");
		scanf("%d",&s->rollno);
		printf("Enter Year of study: ");
		scanf("%d",&s->year);
		x=2*(s->year)-1;
		y=x+1;
		printf("Enter marks of 6 subs of Sem %d:\n",x);
			for(k=0;k<6;k++)
				scanf("%d",&s->sem[x].marks[k]);
		printf("Enter marks of 6 subs of Sem %d:\n",y);
			for(k=0;k<6;k++)
				scanf("%d",&s->sem[y].marks[k]);
		printf("\n");
		s++;
	}
	return s; //returning pointer
}

int operate(struct student *s,int n)
{
	int i,j,x,y;
	float per;
	
	for(i=0;i<n;i++)
	{
		x=2*(s->year)-1;
		y=x+1;
		s->sem[x].total=0;
		s->sem[y].total=0;
		s->semtotal=0;
		for(j=0;j<6;j++)
		{
			s->sem[x].total+=s->sem[x].marks[j];
			s->sem[y].total+=s->sem[y].marks[j];
		}
		s->semtotal=s->sem[x].total+s->sem[y].total;
		s->per=(s->semtotal/1200.0)*100.0;
		
		if (s->per>=75)
			s->sclass="DISTINCTION";
		else if(s->per>=60&&s->per<75)
			s->sclass="FIRST CLASS";
		else if(s->per>=50&&s->per<60)
			s->sclass="SECOND CLASS";
		else if(s->per>=40&&s->per<50)
			s->sclass="PASS CLASS";
		else
			s->sclass="FAIL";
		s++;
	}
	return s;
}

int output(struct student *s,int n)
{
	int i,x,y,j;
	printf("MARKSHEET\n");
	for(i=0;i<n;i++)
	{
		x=2*(s->year)-1;
		y=x+1;
		printf("-----------------------------------------------------------------\n");
		printf("Name:%s\tRoll no:%d\tYear of study:%d\n",s->name,s->rollno,s->year);
  		printf("Marks\t\tSem %d\t\tSem %d\n",x,y);
   		for(j=0;j<6;j++)
   			printf("SUB %d\t\t%d\t\t%d\n",j+1,s->sem[x].marks[j],s->sem[y].marks[j]);
		printf("Total\t\t%d/600\t\t%d/600\n\n",s->sem[x].total,s->sem[y].total);
		printf("PERCENTAGE: %.2f%%\n",s->per);
		printf("OVERALL RESULT: %s",s->sclass);
		printf("\n");
		s++;
	}
	printf("-----------------------------------------------------------------\n");
	return s;
}

int main()
{
	struct student s1[20]; //declaring array of structures
	struct student *s; //array pointer
	int n;
	s=s1;
	printf("Enter no of students: ");
	scanf("%d",&n);
	input(s,n); //passing pointer to function
	operate(s,n);
	output(s,n);
}
