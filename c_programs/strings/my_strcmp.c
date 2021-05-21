
// Write a C program to compare two strings.
#include<stdio.h>
#include<stdlib.h>
#define MAX 15
int my_strcmp(char *a,char *b)
{
    int i=0;
    for(;a[i]!='\0';i++)
    if(a[i]==b[i])
    continue;
    else
    break;
    if(a[i]=='\0'&&b[i]=='\0')
    return 0;
    else
    return 1;

}

int main()
{
char a[MAX]={0},b[MAX]={0};
int result,n1,n2;
printf("enter string1:\n");
gets(a);
printf("enter string2:\n");
gets(b);
result=my_strcmp(a,b);
if(result)
printf("str1 = %s and str2 = %s are not equal",a,b);
else
printf("str1 = %s and str2 = %s are equal",a,b);
}