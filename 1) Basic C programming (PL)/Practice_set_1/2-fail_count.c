//to accept marks of 5 students and count how many have failed
#include <stdio.h>

int main()
{
	int a,b,c,d,e,count=0;
	printf("Enter marks of 5 students: ");
	scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
		
	if(a<40)
		count++;
	if(b<40)
		count++;
	if(c<40)
		count++;
	if(d<40)
		count++;
	if(e<40)
		count++;
			
	printf("\n%d students have failed",count);
	getch();
}
