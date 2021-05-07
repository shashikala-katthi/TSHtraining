//Write a C program to check Most Significant Bit (MSB) of a number is set or not.
#include <stdio.h>

int main()
{
unsigned int n;
int bits=sizeof(int)*8;
int msb=(1<<bits-1);
printf("Enter a number\n");
scanf("%d",&n);
printf("Most Significant Bit (MSB) of a number is ");
if(n&msb)
printf("set");
else
printf("reset");
printf("%x",n);
}