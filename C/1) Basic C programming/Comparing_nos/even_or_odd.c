// To check if a no. is even or odd
#include <stdio.h>
void main()
{
    int a;

    printf("Enter an integer: ");
    scanf("%d", &a);

  
    if(a %2 == 0 )
        printf("%d is even.",a);
    else
        printf("%d is odd.",a);
        
    getch();

      
}
