//Write a C program to print all natural numbers between 1 to n using recursion
#include<stdio.h>
void print_natural_numbers(int n)
{
    if(n==1)
    {
       printf("\n%d",n);
    return ;  
    }
    else
    {
        print_natural_numbers(n-1);
        printf("%d\n",n);
    }
}
int main()
{
int n;
printf("enter n");
scanf("%d",&n);
print_natural_numbers(n);
}
/*
enter n
5
1
2
3
4
5
*/
