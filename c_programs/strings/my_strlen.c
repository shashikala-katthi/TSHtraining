// Write a C program to find length of a string
#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int my_strlen(char *a)
{
    int i=0;
    for(;a[i]!='\0';i++);
    return i;
    
}

int main()
{
int *a,len;
a=(char*)malloc(MAX*sizeof(char));
printf("enter string\n");
scanf("%[^\n]",a);
len=my_strlen(a);
printf("length of the string %s is %d ",a,len);
}