 //Write a C program to count trailing zeros in a binary number.
#include<stdio.h>
unsigned int counttrailingzeros(int n); 
int main() 
{ 
    int n;
unsigned int n1;
printf("enter any number\n");
scanf("%d",&n);
n1=counttrailingzeros(n);
printf("the trailing zeros %d\n",n1);
    return 0; 
} 

unsigned int counttrailingzeros(int n) 
{ 
 unsigned int count = 0; 
  while ((n & 1) == 0) 
  { 
      n = n >> 1; 
      count++; 
  } 
  return count; 
} 
/*
enter any number
16
the trailing zeros 4
katthi@katthi-Inspiron-15-3567:~/Downloads/chrome_training/pgms$ ./a.out
enter any number
32
the trailing zeros 5
katthi@katthi-Inspiron-15-3567:~/Downloads/chrome_training/pgms$ ./a.out
enter any number
4
the trailing zeros 2

logic in while condition (8(1000)&1(0001)==0)
increment count
next n value 100
condition true(100&0001==0)
increment count
n value 10
condition true(10&0001==0)
increment count 
n value 1
next time condition false(1&0001==0) because & will give 1 if both 1


*/
