//Write a C program to compare two strings using pointers
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int my_strcmp(char *p,char *q)
{
    int i;
    for(i=0;*(p+i)!='\0';i++)
    if(*(p+i)==*(q+i))
    continue;
    else
    break;
    
    if(*(p+i)=='\0'&&*(q+i)=='\0')
    return 0;
    else 
    return 1;
    
    
}
int main()
{
   char p[MAX],q[MAX]={0};
   int result;
   int i;
   printf("Enter string1:");
   gets(p);
   printf("Enter string2:");
   gets(q);
   if(strlen(p)!=strlen(q))
   {
       printf("%s,%s are not equal\n",p,q);
       return 0;
   }
   printf("str1=%s,str2=%s\n",p,q);
   result=my_strcmp(p,q);
   if(result)
   printf("%s,%s are not equal\n",p,q);
   else
   printf("%s,%s are equal\n",p,q);
   return 0;
}
