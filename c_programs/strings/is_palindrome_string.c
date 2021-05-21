//Write a C program to check whether a string is palindrome or not.
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 20
void my_strrev(char *p)
{
    int i,j;
    int temp;
    int len=0;
    len=strlen(p);
    for(i=0,j=len-1;i<len/2;i++,j--)
    {
      temp=p[i];
      p[i]=p[j];
      p[j]=temp;
    }
    
}
int is_palindrome(char *p,char *q)
{
  return strcmp(p,q);
}
int main()
{
   char *p,*q;
   int result=0;
   p=(char*)malloc(MAX*sizeof(char));
   q=(char*)malloc(MAX*sizeof(char));
   printf("Enter string\n");
   scanf("%[^\n]",p);
   strcpy(q,p);
   my_strrev(p);
   result=is_palindrome(p,q);
   printf("\nAfter my_strrev %s",p);
   if(result)
   printf("\n%s and %s are not equal",p,q);
   else
   printf("\n%s and %s are equal",p,q);
}
