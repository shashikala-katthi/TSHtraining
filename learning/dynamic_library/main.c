#include<stdio.h>
#include"calc.h"


int main()
{
int a,b,c;
printf("enter any two numbers for calculation\n");
scanf("%d %d",&a,&b);
		printf("%d + %d = %d\n", a, b, add(a,b));   //addition
		
	
		printf("%d - %d = %d\n", a, b, subtract(a,b));   //subtraction
	
		printf("%d * %d = %d\n", a, b, multiply(a,b));  //multiplication
		
		printf("%d / %d = %d\n", a, b, divide(a,b));    //division
		


return 0;
}
