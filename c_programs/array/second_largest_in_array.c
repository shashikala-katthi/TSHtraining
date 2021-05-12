//Write a C program to find second largest element in an array.

#include <stdio.h>
#include<stdlib.h>
#include<limits.h>
int main()
{
    int size;
    int i;
    int *p;
    int max1,max2;
    printf("Enter sizeof array\n");
    scanf("%d",&size);
    printf("Enter Array\n");
    p=(int*)malloc(size*sizeof(int));
    for(i=0;i<size;i++)
    scanf("%d",p+i);
    max1=max2=INT_MIN;
    for(i=0;i<size;i++)
    if(p[i]>max1)
    {   
        max2=max1;
        max1=p[i];
    }
    else if(p[i]>max2 && p[i]<max1)
    {
        max2=p[i];
    }
    printf("\nlargest=%d,second largest=%d",max1,max2);
    
}
