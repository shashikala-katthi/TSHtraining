//Write a C program to sort array using pointers.
#include <stdio.h>
#define MAX 20
int main()
{
    int a[MAX];
    int n;
    int i,j;
    int temp;
    printf("enter size of array\n");
    scanf("%d",&n);
    printf("enter array with %d elements\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    printf("Array before sorting\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",*(a+i));
    }
    //Selection Sorting
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        if(*(a+j)<*(a+i))
        {
            temp=*(a+i);
            *(a+i)=*(a+j);
           *(a+j)=temp;
        }
        
    }
    printf("\nArray After sorting\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",*(a+i));
    }
       
}
