//Write a C program to add two numbers using pointers.

#include <stdio.h>

int main()
{
    int num;
    int *p=NULL;
    printf("enter a number\n");
    scanf("%d",&num);
    p=&num;
    printf("value stored in variable num is %d\n",num);
    printf("address of num is %p\n",&num);
    printf("value stored in pointer variable %p\n",p);
    printf("address of pointer variable %p\n",&p);
    printf("dereference of a pointer variable (value is)%d\n",*p);
    return 0;
}

