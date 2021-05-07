 //Write a C program to clear nth bit of a number using function pointer.
#include <stdio.h>
void clr_nthbt(unsigned int,int);
int main()
{
unsigned int n;
int pos;
printf("Enter a number\n");
scanf("%d",&n);
printf("Enter a position\n");
scanf("%d",&pos);
printf("Before clearing %d bit of a number %d\n",pos,n);

void (*fun)(unsigned int,int)=clr_nthbt;
fun(n,pos);

return 0;
}
void clr_nthbt(unsigned int n,int pos)
{
//unsigned int n1;
n=n&~(1<<pos);
printf("After clearing %d bit of a number %d\n",pos,n);
}
/*
Enter a number
10
Enter a position
3
Before clearing 3 bit of a number 10
After clearing 3 bit of a number 2
*/
