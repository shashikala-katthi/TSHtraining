//Write a C program to swap two numbers using pointers

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
    printf("swapping two numbers\n");
    *p=*p^*q;
     *q=*p^*q;
      *p=*p^*q;
    printf("value stored in variable \"a\" and \"b\" after swap is %d,%d\n",a,b);
    return 0;
}
