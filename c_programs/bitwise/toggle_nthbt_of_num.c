 //Write a C program to toggle nth bit of a number.
#include <stdio.h>

int main()
{
unsigned int n;
int pos;
printf("Enter a number\n");
scanf("%d",&n);
printf("Enter a position\n");
scanf("%d",&pos);
printf("Before toggling %d bit of a number %d\n",pos,n);
n=n^(1<<pos);
printf("After toggling %d bit of a number %d\n",pos,n);

}
/*
Enter a number
10
Enter a position
2
Before toggling 2 bit of a number 10
After toggling 2 bit of a number 14
*/
