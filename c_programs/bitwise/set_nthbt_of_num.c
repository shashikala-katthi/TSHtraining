 //Write a C program to set nth bit of a number.
#include <stdio.h>
unsigned int set_nthbt(unsigned int n,int pos);

int main()
{
unsigned int n,n1;
int pos;
printf("Enter a number\n");
scanf("%d",&n);
printf("Enter a position\n");
scanf("%d",&pos);
printf("Before setting %dth bit of a number %d\n",pos,n);
unsigned int (*fun)(unsigned int,int)=set_nthbt;
n1=fun(n,pos);
printf("After setting %dth bit of a number %d\n",pos,n1);

return 0;
}
unsigned int set_nthbt(unsigned int n,int pos)
{
//unsigned int n1;
n=n|(1<<pos);
return n;

}
/*
Enter a number
10
Enter a position
2
Before setting 2th bit of a number 10
After setting 2th bit of a number 14
*/
