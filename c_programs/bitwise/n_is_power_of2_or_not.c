//Write a C program to check if the given number is power of 2 using function pointer.
#include<stdio.h>

unsigned int powerof2(unsigned int n);

int main()
{
unsigned int n,n1;
printf("enter any number\n");
scanf("%d",&n);

unsigned int (*fun)(unsigned int)=powerof2;
n1=fun(n);

if(n1==0)
printf("%d is a power of 2\n",n);
else
printf("%d is not a power of 2\n",n);
return 0;
}

unsigned int powerof2(unsigned int n)
{
	if((n!=0)&& ((n&(n-1))==0))
		return 0;
	return 1;

}
/*
katthi@katthi-Inspiron-15-3567:~/Downloads/c_programs/bitwise$ ./a.out
enter any number
2
2 is a power of 2
katthi@katthi-Inspiron-15-3567:~/Downloads/c_programs/bitwise$ ./a.out
enter any number
3
3 is not a power of 2
katthi@katthi-Inspiron-15-3567:~/Downloads/c_programs/bitwise$ 
katthi@katthi-Inspiron-15-3567:~/Downloads/c_programs/bitwise$ ./a.out
enter any number
8
8 is a power of 2
*/
