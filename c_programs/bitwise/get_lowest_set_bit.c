 //Write a C program to get lowest set bit of a number.
#include <stdio.h>

int main()
{
unsigned int n;
int i=0;
int bits=1;
printf("Enter a number\n");
scanf("%d",&n);
for(i=1;i<=n;i=i<<1)
{
    if(i&n)
{
    printf("lowest set bit of a number %d is %d\n",n,bits);

 break;
}
++bits;
}
//printf("%x",n);
}