// Write a C program to find sum of all natural numbers between 1 to n using recursion
#include<stdio.h>
int sum_natural_numbers_upto_n(int n)
{   if(n==0)
    return 0;
    else
    return n+sum_natural_numbers_upto_n(n-1);
}
int main()
{
int n,sum=0;
printf("enter n\n");
scanf("%d",&n);
sum=sum_natural_numbers_upto_n(n);
printf("sum of natural numbers upto %d is %d",n,sum);
}
/*
enter n
12
sum of natural numbers upto 12 is 78
*/
