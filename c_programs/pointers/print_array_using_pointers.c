//Write a C program to input and print array elements using pointer.

#include <stdio.h>
#include<malloc.h>
int main()
{
    int n;
    int i;
    int *p=NULL;
    int *temp=NULL;
    printf("enter lenth of the array\n");
    scanf("%d",&n);
    p=(int*)malloc(sizeof(int)*n);
    printf("enter array of %d numbers\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    printf("array elements are \n");
        for(i=0;i<n;i++)
    {
        printf("%d ",p[i]);
    }
    
    return 0;
}
