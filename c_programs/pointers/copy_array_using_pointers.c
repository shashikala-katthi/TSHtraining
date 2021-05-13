// Write a C program to copy one array to another using pointers.

#include <stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    int i;
    int *p=NULL;
    int *temp=NULL;
    printf("enter lenth of the array\n");
    scanf("%d",&n);
    p=(int*)malloc(sizeof(int)*n);
    temp=(int*)calloc(sizeof(int),n);
    printf("enter array of %d numbers\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    printf("1st array\n");
        for(i=0;i<n;i++)
    {
        printf("%d ",p[i]);
    }
    printf("\n2nd array before copying\n");
        for(i=0;i<n;i++)
    {
        printf("%d ",temp[i]);
    }
    for(i=0;i<n;i++)
    {
        temp[i]=p[i];
    }
    printf("\n2nd array after copying\n");
        for(i=0;i<n;i++)
    {
        printf("%d ",temp[i]);
    }
    
    return 0;
}
