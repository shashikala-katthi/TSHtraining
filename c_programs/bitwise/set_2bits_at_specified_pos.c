//1. set 2 bits of number given pos1, pos2 
#include<stdio.h>
int main()
{
    int num;
    int pos1,pos2;
    printf("enter number\n");
    scanf("%d",&num);
    printf("enter number pos1,pos2\n");
    scanf("%d %d",&pos1,&pos2);
    printf("\nnumber before setting bits %d",num);
    num|=(1<<pos1)|(1<<pos2);
    printf("\nnumber after setting bits %d",num);
    num&=~(1<<pos1)|(1<<pos2);
    printf("\nnumber after resetting bits %d",num);
}
/*
enter number
10
enter number pos1,pos2
1
3

number before setting bits 10
number after setting bits 10
number after resetting bits 8
*/
