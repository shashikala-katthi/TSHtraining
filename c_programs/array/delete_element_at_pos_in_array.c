//Write a C program to delete an element from an array at specified position.
#include <stdio.h>
#define MAX 20

int main()
{  
   int size=0;
   int i;
   int pos;
   int a[MAX]={0};
   printf("Enter array size\n");
   scanf("%d",&size);
   printf("Enter array\n");
   for(i=0;i<size;i++)
   scanf("%d",a+i);
   printf("enter position to delete\n");
   scanf("%d",&pos);
   if(pos>size)
   printf("%d position is out of array range",pos);
   else
   {
       i=0;
       while(i<pos)
       {
           i++;
       }
       while(i<size)
       {
           a[i]=a[i+1];
           i++;
       }
       size--;
   }
   printf("\nArray After Deletion at %d position\n",pos);
   for(i=0;i<size;i++)
   printf("%d ",a[i]);
}
