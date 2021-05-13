//  Write a C program to add two matrix using pointers.

#include <stdio.h>
#include<stdlib.h>
int main()
{
    int row,col;
    int i=0,j=0;
    int temp,k=0;
    int ***a;
    printf("enter row &colunms of 2d array");
    scanf("%d %d",&row,&col);
    a=(int***)malloc(3*sizeof(int**));
    for(k=0;k<3;k++)
    {
      a[k]=(int**)malloc(row*sizeof(int*));
    for(i=0;i<row;i++)
    {  
        a[k][i]=(int*)calloc(col,sizeof(int));
    }  
    }
    
    for(temp=0;temp<2;temp++)
    { printf("Enter %d 2d array\n",temp+1);
      for(i=0;i<row;i++)
    {   printf("Enter %d array\n",i+1);
        for(j=0;j<col;j++)
        {
            printf("Enter %d element",j+1);
            scanf("%d",*(*(a+temp)+i)+j);
        }
    }  
    }
    for(temp=0;temp<2;temp++)
    {
       printf("\n%d 2d array is\n",temp+1);
    for(i=0;i<row;i++)
    {   printf("\n\t");
        for(j=0;j<col;j++)
        {
            printf("%d ",*(*(*(a+temp)+i)+j));
        }
    } 
    }

      
    for(i=0;i<row;i++)
    {   
        for(j=0;j<col;j++)
        {
            *(*(*(a+2)+i)+j)=*(*(*(a+0)+i)+j)+*(*(*(a+1)+i)+j);
        }
    }
    printf("\nMatrix after sum\n");
    for(i=0;i<row;i++)
    {   printf("\n\t");
        for(j=0;j<col;j++)
        {
            printf("%d ",*(*(*(a+2)+i)+j));
        }
    } 
    

    return 0;
}
