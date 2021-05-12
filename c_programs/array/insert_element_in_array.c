//Write a C program to insert an element in an array
#include <stdio.h>
#define MAX 20

int main()
{  
   int size=0;
   int i;
   int negative_cnt=0;
   int element;
   int pos;
   int a[MAX];
   printf("Enter array size\n");
   scanf("%d",&size);
   printf("Enter array\n");
   for(i=0;i<size;i++)
   scanf("%d",a+i);
   printf("enter element to insert\n");
   scanf("%d",&element);
   printf("enter position\n");
   scanf("%d",&pos);
   if(pos>size)
   printf("array is full");
   else
   {
       size++;
       i=size;
       while(i>pos-1)
       {
           a[i+1]=a[i];
           i--;
       }
       a[pos]=element;
   }
   printf("Array After Insertion of %d at %d is\n",element,pos);
   for(i=0;i<size;i++)
   printf("%d ",a[i]);
}
