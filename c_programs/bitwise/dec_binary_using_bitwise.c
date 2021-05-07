//Write a C program to convert decimal to binary number system using bitwise operator.
#include <stdio.h>

int main()
{
    int num;
    int i;
    unsigned mask=1<<(8*sizeof(int)-1);
    printf("enter number\n");
    scanf("%d",&num);
printf("binary pattern of a given number\n");
    for(i=31;i>=0;i--){
		mask=1<<i;
		printf("%d",(num&mask)?1:0);
		}
}
/*
enter number
10
binary pattern of a given number
00000000000000000000000000001010
*/
