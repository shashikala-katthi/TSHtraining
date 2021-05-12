// Write a C program to count total number of negative elements in an array.

#include <stdio.h>
#define MAX 20

int main()
{  
   int size=0;
   int i;
   int negative_cnt=0;
   int a[MAX];
   printf("Enter array size\n");
   scanf("%d",&size);
   printf("Enter array\n");
   for(i=0;i<size;i++)
   scanf("%d",a+i);
   for(i=0;i<size;i++)
   if(a[i]<0)
   negative_cnt++;
   printf("all negstive numbers count in array is %d",negative_cnt);
}
