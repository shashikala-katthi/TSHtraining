// Write a C program to print all even or odd numbers in given range using recursion.
#include<stdio.h>
void print_even_odd_in_range(int min,int max)
{   if(min%2==0)
    {
      printf("\n%d",min);
      print_even_odd_in_range(min+1,max);
      
    }
    else if(min>max)
    return;
    else
    {
        print_even_odd_in_range(min+1,max);
    }
    
}
int main()
{
int min,max;
printf("enter range");
scanf("%d %d",&min,&max);
print_even_odd_in_range(min,max);
}
/*
katthi@katthi-Inspiron-15-3567:~/Documents$ ./a.out
enter range2
8

2
4
6
*/
