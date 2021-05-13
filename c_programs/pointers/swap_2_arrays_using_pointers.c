//Write a C program to swap two arrays using pointers.

#include <stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    int i=0;
    int temp;
    int *arr1;
    int *arr2;
    printf("enter size of array");
    scanf("%d",&n);
    arr1=(int*)malloc(n*sizeof(int));
    arr2=(int*)malloc(n*sizeof(int));
    printf("Enter elements of arr1");
    for(i;i<n;i++)
    {   printf("\n%d element :",i+1);
        scanf("%d",&arr1[i]);
    }
    printf("Enter elements of arr2");
    for(i=0;i<n;i++)
    {   printf("\n%d element :",i+1);
        scanf("%d",&arr2[i]);
    }
    
    printf("Before Swap\n");
    printf("Elements of arr1\n");
    for(i=0;i<n;i++)
    {   printf("%d ",arr1[i]);
    }
    printf("\nElements of arr2\n");
    for(i=0;i<n;i++)
    {   printf("%d ",arr2[i]);
    }
    for(i=0;i<n;i++)
    {   temp=*(arr1+i);
    *(arr1+i)=*(arr2+i);
    *(arr2+i)=temp;
    }
    
    printf("\nAfter Swap\n");
    printf("Elements of arr1\n");
    for(i=0;i<n;i++)
    {   printf("%d ",arr1[i]);
    }
    printf("\nElements of arr2\n");
    for(i=0;i<n;i++)
    {   printf("%d ",arr2[i]);
    }
    return 0;
}
