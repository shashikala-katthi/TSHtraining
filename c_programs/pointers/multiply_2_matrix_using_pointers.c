//Write a C program to multiply two matrix using pointers.
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int r1,c1;
    int r2,c2;
    int i,j,k;
    int **arr1;
    int **arr2;
    int **arr3;
    printf("enter row and col of 1st array\n");
    scanf("%d %d",&r1,&c1);
    
    printf("enter row and col of 2nd array\n");
    scanf("%d %d",&r2,&c2);
    if(c1!=r2)
    {
        printf("multiplication is not possible");
        return 0;
    }
    
    arr1=(int**)malloc(r1*sizeof(int*));
    
    for(i=0;i<r1;i++)
    {
       *(arr1+i)=(int*)malloc(c1*sizeof(int));
    }
    arr2=(int**)malloc(r2*sizeof(int*));
    
    for(i=0;i<r2;i++)
    {
       *(arr2+i)=(int*)malloc(c2*sizeof(int));
    }
    arr3=(int**)malloc(r1*sizeof(int*));
    
    for(i=0;i<r1;i++)
    {
       *(arr3+i)=(int*)calloc(c2,sizeof(int));
    }
    printf("enter 1st array with r1=%d,c1=%d",r1,c1);
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("\nenter element at %d row and %d column:",r1,c1);
            scanf("%d",*(arr1+i)+j);
        }
    }
    printf("enter 2nd array with r1=%d,c1=%d",r1,c1);
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("\nenter element at %d row and %d column:",r2,c2);
            scanf("%d",*(arr2+i)+j);
        }
    }
    printf("\n1st array is \n");
    for(i=0;i<r1;i++)
    {   printf("\n\t");
        for(j=0;j<c1;j++)
        {
            
            printf("%d",*(*(arr1+i)+j));
        }
    }
    printf("\n2nd array is \n");
    for(i=0;i<r2;i++)
    {   printf("\n\t");
        for(j=0;j<c2;j++)
        {
            
            printf("%d",*(*(arr2+i)+j));
        }
    }
    //multiplication 
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            for(k=0;k<c1;k++)
            {
                *(*(arr3+i)+j)+=*(*(arr1+i)+k)**(*(arr2+k)+j);
            }
        }
    }
    printf("\nAfter Multiplication array is\n");
    for(i=0;i<r1;i++)
        {
            printf("\n\t");
            for(k=0;k<c2;k++)
            {
                printf("%d ",arr3[i][k]);
            }
        }
    
}