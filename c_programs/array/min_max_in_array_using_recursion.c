//Write a C program to find maximum and minimum element in an array. - using recursion

#include <stdio.h>
#include<stdlib.h>

void min_max_in_array(int *p,int length,int *min,int *max)
{
    if(length==0)
    return;
    else
    {
        if((p[0])>*max)
        *max=p[0];
        else if(p[0]<*min)
        *min=p[0];
        min_max_in_array(p+1,--length,min,max);
    }
}
int main()
{
    int size;
    int i;
    int *p;
    int min,max;
    printf("Enter sizeof array\n");
    scanf("%d",&size);
    printf("Enter Array\n");
    p=(int*)malloc(size*sizeof(int));
    for(i=0;i<size;i++)
    scanf("%d",p+i);
    min=max=p[0];
    min_max_in_array(p,size,&min,&max);
    printf("\nminimum=%d,maximum=%d",min,max);
    
}
