//To find which student has scored max marks
#include <stdio.h>
struct student
{
    char name[50];
    int roll;
    float marks;
} s[100];

int main()
{
    int i,n,max,pos=0;

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
    max=s[0].marks;
    for(i=0;i<n;i++)
    {
    	if(s[i].marks > max)
		{
			max=s[i].marks;
			pos=i;
		}
	}
    printf("Student %d has scored max marks",pos+1);
    

}
