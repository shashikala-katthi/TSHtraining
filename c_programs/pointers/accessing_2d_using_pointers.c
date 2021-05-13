// Write a C program to access two dimensional array using pointers.

#include <stdio.h>
#include<stdlib.h>
int main()
{
    int row,col;
    int i=0,j=0;
    int temp;
    int **arr1;
    printf("enter row &colunms of 2d array");
    scanf("%d %d",&row,&col);
    arr1=(int**)malloc(row*sizeof(int*));
    for(i=0;i<row;i++)
    {  
        arr1[i]=(int*)calloc(col,sizeof(int));
    }
    for(i=0;i<row;i++)
    {   printf("Enter %d array\n",i+1);
        for(j=0;j<col;j++)
        {
            printf("Enter %d element",j+1);
            scanf("%d",*(arr1+i)+j);
        }
    }
    printf("\n2d array is\n");
    for(i=0;i<row;i++)
    {   printf("\n\t");
        for(j=0;j<col;j++)
        {
            printf("%d ",*(*(arr1+i)+j));
        }
    }
    printf("\nEnter 1d array index to see elements\n");
    scanf("%d",&temp);
    
    for(j=0;j<col;j++)
    printf("%d ",*(*(arr1+temp)+j));
    
    printf("\nEnter 1d array index and element position to see element\n");
    scanf("%d %d",&temp,&i);
    printf("element at %d 1d and %d pos is %d",temp,i,arr1[temp][i]);

    return 0;
}
