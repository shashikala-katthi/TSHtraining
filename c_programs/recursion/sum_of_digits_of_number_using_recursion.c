// Write a C program to find sum of digits of a given number using recursion.
#include<stdio.h>
#include<math.h>
int sum_of_digits_of_num(int n)
{   
    if(n==0)
    return 0;
    else
    return n%10+sum_of_digits_of_num(n/10);
}

int main()
{
int n,sum;
printf("enter number\n");
scanf("%d",&n);
sum=sum_of_digits_of_num(n);
printf("sum of digits of a number %d is %d ",n,sum);
}
/*
enter number
12
sum of digits of a number 12 is 3 
*/
