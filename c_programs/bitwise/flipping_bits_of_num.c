 // Write a C program to flip bits of a binary number using bitwise operator.
#include <stdio.h>
unsigned int flipbts(unsigned int);
int main()
{
unsigned int n1,n;
printf("enter number\n");
scanf("%d",&n);
printf("Before flipping bits of a number is %d\n",n);
unsigned int (*fun)(unsigned int)=flipbts;
n1=fun(n);
printf("After flipping bits of a number is %d",n1);
}
unsigned int flipbts(unsigned int n)
{
//unsigned int n1;
n=~n;
return n;

}
/*katthi@katthi-Inspiron-15-3567:~/Downloads/c_programs/bitwise$ ./a.out
enter number
15
Before flipping bits of a number is 15
After flipping bits of a number is -16
katthi@katthi-Inspiron-15-3567:~/Downloads/c_programs/bitwise$ ./a.out
enter number
0
Before flipping bits of a number is 0
After flipping bits of a number is -1
katthi@katthi-Inspiron-15-3567:~/Downloads/c_programs/bitwise$ ./a.out
enter number
11
Before flipping bits of a number is 11
After flipping bits of a number is -12
*/
