 //Write a C program to get nth bit of a number.
#include <stdio.h>
unsigned int get_nthbt(unsigned int n,int pos);
int main()
{
unsigned int n,n1;
int pos;
printf("Enter a number\n");
scanf("%d",&n);
printf("Enter a position\n");
scanf("%d",&pos);
printf("%dth bit of a number %d is ",pos,n);
unsigned int (*fun)(unsigned int,int)=get_nthbt;
n1=fun(n,pos);
printf("%d\n",n1);
return 0;
}

unsigned int get_nthbt(unsigned int n,int pos)
{
//unsigned int n1;
n=(n&(1<<pos))?1:0;
return n;

}
/*katthi@katthi-Inspiron-15-3567:~/Downloads/c_programs/bitwise$ ./a.out
Enter a number
10
Enter a position
1
1th bit of a number 10 is 1
katthi@katthi-Inspiron-15-3567:~/Downloads/c_programs/bitwise$ ./a.out
Enter a number
10
Enter a position
2
2th bit of a number 10 is 0
*/
