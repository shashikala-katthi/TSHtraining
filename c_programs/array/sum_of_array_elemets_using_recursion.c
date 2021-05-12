//Write a C program to find sum of all array elements. - using recursion.

#include <stdio.h>
#define MAX 20
int sum_of_array_elements(int *a,int size)
{  if(size==0)
   return 0;
    return a[0]+sum_of_array_elements(a+1,size-1);
}
int main()
{  
   int size=0;
   int result;
   int i;
   int a[MAX];
   printf("Enter array size");
   scanf("%d",&size);
   printf("Enter array\n");
   for(i=0;i<size;i++)
   scanf("%d",a+i);
   result=sum_of_array_elements(a,size);
   printf("%d",result);
}
