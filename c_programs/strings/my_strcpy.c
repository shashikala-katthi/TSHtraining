// Write a C program to copy one string to another string.
#include<stdio.h>
#include<stdlib.h>
#define MAX 15
void my_strcpy(char *a,char *b)
{
    int i=0;
    for(;a[i]!='\0';i++)
    b[i]=a[i];
    b[i]='\0';
}

int main()
{
char a[MAX]={0},b[MAX]={0};
int len,n1,n2;
printf("enter string:\n");
gets(a);
printf("Before copy str1 = %s and str2 = %s ",a,b);
my_strcpy(a,b);
printf("\nAfter copy str1 = %s and str2 = %s ",a,b);
}