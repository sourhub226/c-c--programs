#include <stdio.h>
#include <math.h>

int main()
{
	float a,b,op=0;
	int x,y,i;
	char c='y';
	printf("Calculator 2.0\n\nGood Day Folks!\nWhat do you want to do?\n");
	
	while(c=='y')
	{
		printf("\nOperations available:\n1 --> Addition\n2 --> Subtraction\n3 --> Multiplication\n4 --> Division");
		printf("\n5 --> Sin\n6 --> Cos\n7 --> Tan\n8 --> Sin inverse\n9 --> Cos inverse\n10 --> Tan inverse");
		printf("\n11 --> Cosec\n12 --> Sec\n13 --> Cot\n14 --> Cosec inverse\n15 --> Sec inverse\n16 --> Cot inverse");
		printf("\n17 --> Log (to the base e)\n18 --> Log (to the base 10)\n19 --> Log (to any base)\n20 --> e raised to a no.");
		printf("\n21 --> A no. raised to a no.\n22 --> Square root\n23 --> Factorial\n24 --> Modulus\n");
		printf("\nEnter the operation no: ");
		scanf("%d",&y);
		
		switch(y)
		{
			case 1:
				printf("How many nos do you want to add?\n");
				scanf("%d",&x);
				for(i=1;i<=x;i++)
				{
					printf("Enter no %d: ",i);
					scanf("%f",&a);
					op=op+a;
				}
				printf("Sum=%.2f",op);
				break;
				
			case 2:
				op=0;
				printf("How many nos do you want to subtract?\n");
				scanf("%d",&x);
				for(i=1;i<=x;i++)
				{
					printf("Enter no %d: ",i);
					scanf("%f",&a);
					if(i==1)
						op=op+a;
					else
						op=op-a;
				}
				printf("Difference=%.2f",op);	
				break;
			
			case 3:
				op=1;
				printf("How many nos do you want to multiply?\n");
				scanf("%d",&x);
				for(i=1;i<=x;i++)
				{
					printf("Enter no %d: ",i);
					scanf("%f",&a);
					op=op*a;
				}
				printf("Product=%.2f",op);	
				break;
				
			case 4:
				printf("Enter 2 nos: ");
				scanf("%d %d",&a,&b);
				if(b==0)
					printf("Infinity");
				else
					printf("Quotient=%.4f",a/b);	
				break;
				
			case 5:
				printf("Enter the angle in degrees: ");
				scanf("%f",&a);
				b=a*(3.14159265359/180);
				printf("Sin(%.2f)=%.4f",a,sin(b));
				break;
				
			case 6:
				printf("Enter the angle in degrees: ");
				scanf("%f",&a);
				b=a*(3.14159265359/180);
				printf("Cos(%.2f)=%.4f",a,cos(b));
				break;
				
			case 7:
				printf("Enter the angle in degrees: ");
				scanf("%f",&a);
				b=a*(3.14159265359/180);
				printf("Tan(%.2f)=%.4f",a,tan(b));
				break;
				
			case 8:
				printf("Enter the value: ");
				scanf("%f",&a);
				b=asin(a)*(180/3.14159265359);
				printf("Sin inv(%.4f)=%.4f degrees",a,b);
				break;
				
			case 9:
				printf("Enter the value: ");
				scanf("%f",&a);
				b=acos(a)*(180/3.14159265359);
				printf("Cos inv(%.4f)=%.4f degrees",a,b);
				break;
				
			case 10:
				printf("Enter the value: ");
				scanf("%f",&a);
				b=atan(a)*(180/3.14159265359);
				printf("Tan inv(%.4f)=%.4f degrees",a,b);
				break;
				
			case 11:
				printf("Enter the angle in degrees: ");
				scanf("%f",&a);
				b=a*(3.14159265359/180);
				printf("Cosec(%.2f)=%.4f",a,1/sin(b));
				break;
				
			case 12:
				printf("Enter the angle in degrees: ");
				scanf("%f",&a);
				b=a*(3.14159265359/180);
				printf("Sec(%.2f)=%.4f",a,1/cos(b));
				break;
				
			case 13:
				printf("Enter the angle in degrees: ");
				scanf("%f",&a);
				b=a*(3.14159265359/180);
				printf("Cot(%.2f)=%.4f",a,1/tan(b));
				break;
				
			case 14:
				printf("Enter the value: ");
				scanf("%f",&a);
				b=asin(1/a)*(180/3.14159265359);
				printf("Cosec inv(%.4f)=%.4f degrees",a,b);
				break;
				
			case 15:
				printf("Enter the value: ");
				scanf("%f",&a);
				b=acos(1/a)*(180/3.14159265359);
				printf("Sec inv(%.4f)=%.4f degrees",a,b);
				break;
				
			case 16:
				printf("Enter the value: ");
				scanf("%f",&a);
				b=atan(1/a)*(180/3.14159265359);
				printf("Cot inv(%.4f)=%.4f degrees",a,b);
				break;
				
			case 17:
				printf("Enter the no: ");
				scanf("%f",&a);
				printf("ln(%.4f)=%.4f",a,log(a));
				break;
				
			case 18:
				printf("Enter the no: ");
				scanf("%f",&a);
				printf("log(%.4f)=%.4f",a,log(a)/log(10));
				break;
				
			case 19:
				printf("Enter the no: ");
				scanf("%f",&a);
				printf("Enter the base: ");
				scanf("%f",&b);
				printf("log(%.4f)=%.4f",a,log(a)/log(b));
				break;
				
			case 20:
				printf("Enter the power: ");
				scanf("%f",&a);
				b=pow(2.71828182,a);
				printf("e^%.2f=%.2f",a,b);
				break;
				
			case 21:
				printf("Enter the base: ");
				scanf("%f",&a);
				printf("Enter the power: ");
				scanf("%f",&b);
				printf("%.2f^%.2f=%.2f",a,b,pow(a,b));
				break;
				
			case 22:
				printf("Enter the no: ");
				scanf("%f",&a);
				if(a>0)
					printf("Sq. root of %.2f=%.4f",a,sqrt(a));
				else
					printf("Sq. root of %.2f=%.4fi",a,sqrt(-a));
				break;
				
			case 23:
				op=1;
				printf("Enter the no: ");
				scanf("%f",&a);
				
				for(x=1;x<=a;x++)
				{
					op=op*x;
				}
				printf("%.0f!=%.0f",a,op);
				break;
				
			case 24:
				printf("Enter the no: ");
				scanf("%f",&a);
				if(a>0)
					printf("|%.2f|=%.2f",a,a);
				else
					printf("|%.2f|=%.2f",a,-a);
					break;
		}
		printf("\n\nDo you want to do another operation? (y/n)\n");
		scanf(" %c",&c);	
	}
	printf("\nHave a Nice Day!");
	getch();
}
