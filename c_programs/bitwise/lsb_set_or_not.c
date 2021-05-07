//Write a C program to check Least Significant Bit (LSB) of a number is set or not.
#include <stdio.h>

int main()
{
int n;
printf("Enter a number\n");
scanf("%d",&n);
printf("Least Significant Bit (LSB) of a number is ");
if(n&1==1)
printf("set");
else
printf("reset");
}