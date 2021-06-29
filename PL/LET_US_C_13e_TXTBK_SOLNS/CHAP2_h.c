// Write a program to receive values of an angle in degrees and check whether sum of squares sin and cosine of this angle is equal to 1.
#include<stdio.h>
#include<math.h>

int main()
{
    float a,sum; 
    printf("Enter the angle in degrees: ");
    scanf("%f",&a);
    
    sum=cos(a)*cos(a)+sin(a)*sin(a);
    
    if(sum==1)
        printf("\nThe sum is equal to one");
    else
        printf("\nThe sum is not equal to one");
    getch();
}
