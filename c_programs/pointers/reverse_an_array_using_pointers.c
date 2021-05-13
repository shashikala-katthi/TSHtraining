//Write a C program to reverse an array using pointers.

#include <stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    int i=0,j=0;
    int temp;
    int *arr1;
    printf("enter size of array");
    scanf("%d",&n);
    arr1=(int*)malloc(n*sizeof(int));
    printf("Enter elements of arr");
    for(i;i<n;i++)
    {   printf("\n%d element :",i+1);
        scanf("%d",&arr1[i]);
    }
    printf("\nBefore Reverse\n");
    printf("Elements of arr\n");
    for(i=0;i<n;i++)
    {   printf("%d ",arr1[i]);
    }

    for(i=0,j=n-1;i<n/2;i++,j--)
    {   temp=*(arr1+i);
    *(arr1+i)=*(arr1+j);
    *(arr1+j)=temp;
    }
    
    printf("\nAfter Reverse\n");
    printf("Elements of arr1\n");
    for(i=0;i<n;i++)
    {   printf("%d ",arr1[i]);
    }

    return 0;
}
