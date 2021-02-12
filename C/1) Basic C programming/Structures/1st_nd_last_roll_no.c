// To implement a student database using structures and display info of roll no 1 and n
#include <stdio.h>
struct student
{
    char name[50];
    int roll;
    float marks;
} s[100];

int main()
{
    int i,n;

    printf("Enter no. of students: ");
    scanf("%d",&n);
	printf("\nEnter their information:\n\n");
    for(i=0; i<n; ++i)
    {
		printf("Student %d:\n",i+1);
        printf("Enter name: ");
        scanf("%s",s[i].name);

		printf("Enter Roll No: ");
        scanf("%d",&s[i].roll);

        printf("Enter marks: ");
        scanf("%f",&s[i].marks);

        printf("\n");
    }

	for(i=0;i<n;i++)
	{
		if(s[i].roll==1)
			printf("\nRoll No 1\nName: %s\nMarks: %f",s[i].name,s[i].marks);
			
		else if(s[i].roll==n)
			printf("\nRoll No %d\nName: %s\nMarks: %f",n,s[i].name,s[i].marks);
	}

}

