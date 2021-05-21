//Write a C program to find reverse of a string
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 20
char * my_strrev(char *p)
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
    return p;
    
}
int main()
{
   char *p,*q;
   p=(char*)malloc(MAX*sizeof(char));
   printf("Enter string\n");
   scanf("%[^\n]",p);
   q=my_strrev(p);
   printf("\nAfter my_strrev %s",p);
}
