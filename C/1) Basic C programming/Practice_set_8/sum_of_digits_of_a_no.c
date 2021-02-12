//sum of digits of a no
#include <stdio.h>
 
int sum(int n)
{
    if (n!=0)
        return (n%10+sum(n/10));
    else
       return 0;
}
int main()
{
    int n,ans;
    printf("Enter a no: ");
    scanf("%d",&n);
    ans=sum(n);
    printf("Sum of digits of %d = %d",n,ans);
    return 0;
}
 
