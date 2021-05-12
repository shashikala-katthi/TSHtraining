// Write a C program to count total number of even and odd elements in an array.

#include <stdio.h>
#define MAX 20

int main()
{  
   int size=0;
   int i;
   int even_cnt=0;
   int odd_cnt=0;
   int a[MAX];
   printf("Enter array size\n");
   scanf("%d",&size);
   printf("Enter array\n");
   for(i=0;i<size;i++)
   scanf("%d",a+i);
   for(i=0;i<size;i++)
  if(a[i]%2==0)
  even_cnt++;
  else
  odd_cnt++;
   printf("even numbers count is %d,odd numbers count %d",even_cnt,odd_cnt);
}
