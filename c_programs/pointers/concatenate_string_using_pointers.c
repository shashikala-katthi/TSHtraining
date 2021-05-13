//Write a C program to concatenate two strings using pointers.
#include <stdio.h>
#include<stdlib.h>
#define MAX 100
void my_strcat(char *p,char *q)
{
    int i,j;
    for(i=0;*(p+i)!='\0';i++);
    for(j=i,i=0;*(q+i)!='\0';i++,j++)
    *(p+j)=*(q+i);
    *(p+j)='\0';
}
int main()
{
   char p[MAX],q[MAX]={0};
   int len1;
   int i;
   printf("Enter string1:");
   gets(p);
   printf("Enter string2:");
   gets(q);
   printf("Before concatenate str1=%s,str2=%s\n",p,q);
   my_strcat(p,q);
   printf("After concatenate str1=%s,str2=%s\n",p,q);
   return 0;
}
