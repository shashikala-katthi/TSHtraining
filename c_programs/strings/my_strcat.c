// Write a C program to concatenate two strings.
#include<stdio.h>
#include<stdlib.h>
#define MAX 15
void my_strcat(char *a,char *b)
{
    int i=0,j;
    for(;a[i]!='\0';i++);
    for(j=0;b[j]!='\0';j++,i++)
    a[i]=b[j];
    a[i]='\0';
}

int main()
{
char a[MAX]={0},b[MAX]={0};
int len,n1,n2;
printf("enter string1:\n");
gets(a);
printf("enter string2:\n");
gets(b);
printf("Before concatenate str1 = %s and str2 = %s ",a,b);
my_strcat(a,b);
printf("\nAfter concatenate str1 = %s and str2 = %s ",a,b);
}