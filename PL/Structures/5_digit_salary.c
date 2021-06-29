//To find employees having 5 digit salary
#include <stdio.h>
struct employee
{
    char name[50];
    char qual[50];
    int id;
    int salary;
};

int main()
{
	struct employee e[100];
    int i,n,count=0,flag=0,temp;
	

    printf("Enter no. of employees: ");
    scanf("%d",&n);
	printf("\nEnter their information:\n\n");
    for(i=0; i<n; ++i)
    {
		printf("Employee %d:\n",i+1);
        printf("Enter name: ");
        scanf("%s",e[i].name);

		printf("Enter ID: ");
        scanf("%d",&e[i].id);
        
         printf("Enter qualification: ");
        scanf("%s",e[i].qual);

        printf("Enter salary: ");
        scanf("%d",&e[i].salary);

        printf("\n");
    }
    for(i=0;i<n;i++)
    {
    	count=0;
    	flag=0;
    	temp=e[i].salary;
    	while(e[i].salary>0)
    	{
    		e[i].salary=e[i].salary/10;
    		count++;
		}
		if(count==5)
		{
			flag=1;
			printf("Employee %d has 5 digit salary\nHis details are:\n",i+1);
			printf("Name: %s\nID: %d\nQualification: %s\nSalary: %d\n",e[i].name,e[i].id,e[i].qual,temp);
		}
	}
	if(flag==0)
		printf("Employee not found");

}


