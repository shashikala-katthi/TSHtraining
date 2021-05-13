// Write a C program to search an element in array using pointers.

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
    printf("\nEnter element need to search");
    scanf("%d",&temp);
    
    printf("Elements of arr\n");
    for(i=0;i<n;i++)
    {   printf("%d ",arr1[i]);
    }

    for(i=0;i<n;i++)
    if(arr1[i]==temp)
    {
        printf("\nElement %d is found at %d position",temp,i+1);
        break;
    }
    
    
    if(i==n)
    printf("\nElement %d is not found",temp);

    return 0;
}
