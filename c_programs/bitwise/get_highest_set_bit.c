 //Write a C program to get highest set bit of a number.
#include <stdio.h>

int main()
{
unsigned int n;
int i=0;
int bits=(sizeof(int)*8)-1;
printf("Enter a number\n");
scanf("%d",&n);
for(i=1<<(bits);i!=0;i=i>>1)
{
    if(i&n)
{
    printf("highest set bit of a number %d is %d\n",n,bits+1);

 break;
}
--bits;
}
//printf("%x",n);
}