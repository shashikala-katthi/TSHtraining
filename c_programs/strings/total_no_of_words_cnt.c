// Write a C program to count total number of words in a string.
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 20

int my_word_count(char *p)
{
  int i=0;
  int word_count=0;
  while(p[i]==' ')
  i++;
  for(;p[i]!='\0';i++)
  if(p[i]==' '&& p[i+1]!=' ')
  word_count++;
  return ++word_count;
}
int main()
{
   char *p;
   int result=0;
   p=(char*)malloc(MAX*sizeof(char));
   printf("Enter string\n");
   scanf("%[^\n]",p);
   result=my_word_count(p);
   printf("word count in string %s is %d\n",p,result);
   
}
