//To find if a given number is even or odd
#include <stdio.h>

int main()
{
    int a;
    printf("Enter an integer: ");
    scanf("%d",&a);

    if(a % 2 == 0 )
        printf("\n%d is even.",a);
    else
        printf("\n%d is odd.",a);
        
    getch();
}
