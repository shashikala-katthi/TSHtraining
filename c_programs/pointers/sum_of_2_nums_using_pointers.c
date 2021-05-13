//Write a C program to add two numbers using pointers.

#include <stdio.h>

int main()
{
    int a,b;
    int *p,*q=NULL;
    printf("enter 2 number\n");
    scanf("%d %d",&a,&b);
    p=&a;
    q=&b;
    printf("value stored in variable \"a\" is %d and \"b\" is %d\n",a,b);
    printf("sum of 2 numbers is %d\n",*p+*q);
    return 0;
}
