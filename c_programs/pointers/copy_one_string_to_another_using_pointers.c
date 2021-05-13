//Write a C program to copy one string to another using pointers.
#include <stdio.h>
#include<stdlib.h>
#define MAX 100
void my_str_cpy(char *p,char *q)
{
    int i;
    for(i=0;*(p+i)!='\0';i++)
    *(q+i)=*(p+i);
}
int main()
{
   char p[MAX],q[MAX]={0};
   int len1;
   int i;
   printf("Enter string1:");
   gets(p);
   printf("Before Copy str1=%s,str2=%s\n",p,q);
   my_str_cpy(p,q);
   printf("After Copy str1=%s,str2=%s\n",p,q);
   return 0;
}