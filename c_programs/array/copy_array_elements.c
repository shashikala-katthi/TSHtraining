//Write a C program to copy all elements from an array to another array

#include <stdio.h>
#define MAX 20

int main()
{  
   int size=0;
   int i;
   int a[MAX],b[MAX]={};
   printf("Enter array size\n");
   scanf("%d",&size);
   printf("Enter array\n");
   for(i=0;i<size;i++)
   scanf("%d",a+i);
   printf("\nBefore Copy Array1:\n");
   for(i=0;i<size;i++)
   printf("%d ",*(a+i));
   printf("\nBefore Copy Array2:\n");
   for(i=0;i<size;i++)
   printf("%d ",*(b+i));
   for(i=0;i<size;i++)
   *(b+i)=*(a+i);
   printf("\nAfter Copy Array1:\n");
   for(i=0;i<size;i++)
   printf("%d ",*(a+i));
   printf("\nAfter Copy Array2:\n");
   for(i=0;i<size;i++)
   printf("%d ",*(b+i));
   
   
}
