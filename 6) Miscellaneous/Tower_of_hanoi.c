#include <stdio.h>
#include <math.h>
 
int tower(int, char, char, char);
 
int main()
{
    int n,a;
    printf("Enter the number of disks : ");
    scanf("%d",&n);
	a=pow(2,n)-1;
    printf("No. of steps required = %d\n",a);
    printf("\nThe sequence of steps involved are :");
    tower(n,'A','C','B');
}
int tower(int n,char from,char to, char aux)
{
    if (n==1)
    {
        printf("\nMove disk 1 from %c to %c",from,to);
        return;
    }
    tower(n-1,from,aux,to);
    printf("\nMove disk %d from %c to %c",n,from,to);
    tower(n-1,aux,to,from);
}
