// Write a C program to find reverse of any number using recursion.
#include<stdio.h>
#include<math.h>
int reverse_function(int num);

int main(){
   int num,reverse_number;

   // input the number
   printf("\nEnter any number:");
   scanf("%d",&num);

   //Calling user defined function to perform reverse
   reverse_number=reverse_function(num);
   printf("\nAfter reverse the no is :%d",reverse_number);
   return 0;
}
int sum=0,rem;
int reverse_function(int num){
   if(num){
      rem=num%10;
      sum=sum*10+rem;
      reverse_function(num/10);
   }
   else
      return sum;
   return sum;
}
/*
./a.out

Enter any number:234

After reverse the no is :432
*/
