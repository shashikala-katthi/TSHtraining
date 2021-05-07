//Write a C program to count total zeros and ones in a binary number
#include<stdio.h>
int main()
{
    int n,i,ones=0,zeros=0,mask;
    printf("enter number\n");
    scanf("%d",&n);
   while(n>0){
		
		if(n&1)
		ones++;
		else
		zeros++;
	n=n>>1;
		}
    printf("total zeros in given number is %d and ones is %d",zeros,ones);
    
}
/*
enter number
10
katthi@katthi-Inspiron-15-3567:~/Downloads/c_programs/bitwise$ ./a.out
enter number
16
total zeros in given number is 4 and ones is 1
*/
