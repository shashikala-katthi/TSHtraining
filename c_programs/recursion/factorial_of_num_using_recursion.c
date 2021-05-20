// Write a C program to find factorial of any number using recursion.
#include<stdio.h>
#include<math.h>
int factorial_of_a_num(int n)
{   if(n==1 || n==0)
    return 1;
    else
    return n*factorial_of_a_num(n-1);
}

int main()
{
int n,result;
printf("enter number\n");
scanf("%d",&n);
result=factorial_of_a_num(n);
printf("factorial of a number %d is %d ",n,result);
}
/*
 enter number
5
factorial of a number 5 is 120 
*/
