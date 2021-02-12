//To find avg marks of all students
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
	float sum=0;

    printf("Enter no. of students: ");
    scanf("%d",&n);
	printf("\nEnter their information:\n\n");
    for(i=0; i<n;i++)
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
    	sum=sum+s[i].marks;
	}
    printf("Avg of marks = %f",sum/n);
}

