// Write a C program to find sum of all even or odd numbers in given range using recursion.
#include<stdio.h>
int sum_of_odd_natural_numbers(int min,int max)
{   
    if(min>max)
    return 0;
    else if(min%2!=0)//change logic for even or odd here
    {
      return min+sum_of_odd_natural_numbers(min+1,max);
    }
    else
    {
        sum_of_odd_natural_numbers(min+1,max);
    }
}
int main()
{
int min,max,sum=0;
printf("enter range\n");
scanf("%d %d",&min,&max);
sum=sum_of_odd_natural_numbers(min,max);
printf("sum of odd natural numbers in range of %d,%d is %d",min,max,sum);
}
/*
enter range
2
10
sum of odd natural numbers in range of 2,10 is 24
*/
