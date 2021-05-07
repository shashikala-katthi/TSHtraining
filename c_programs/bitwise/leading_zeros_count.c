 //Write a C program to count leading zeros in a binary number.
#include<stdio.h>
#include<stdlib.h>
int main(){
   int number, i, lead = 0, Msb,size;
   printf("Enter a number\n");
   scanf("%d",&number);
   size = sizeof(number) * 8;
   Msb=1<<(size-1);
   for(i = 0; i < size; i++){
      if((number << i) & Msb) {
         break;
      }
      lead++;
   }
   printf("Number of Leading ZERO is = %d", lead);
   return 0;
}
/*
Enter a number
10
Number of Leading ZERO is = 28
*/
