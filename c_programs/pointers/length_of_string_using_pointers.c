//Write a C program to find length of string using pointers.
#include<stdio.h>
#define MAX 100
int my_strlen(char *a)
{  int i=0;
    for(;*(a+i)!='\0';i++);
    return i;
    
}
int main()
{   char a[MAX];
    printf("enter string\n");
    scanf("%[^\n]",a);
    printf("string len of %s is %d",a,my_strlen(a));
}