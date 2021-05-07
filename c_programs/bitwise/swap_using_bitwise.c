//Write a C program to swap two numbers using bitwise operator.

#include <stdio.h>

int main()
{
    int a,b;
    printf("enter 2 number\n");
    scanf("%d %d",&a,&b);
    printf("value stored in variable a is %d and b is %d\n",a,b);
    printf("swapping two numbers\n");
    a=a^b;
    b=a^b;
    a=a^b;
    printf("value stored in variable a and b after swap is %d,%d\n",a,b);
    return 0;
}
/*
enter 2 number
10
20
value stored in variable a is 10 and b is 20
swapping two numbers
value stored in variable a and b after swap is 20,10
*/
