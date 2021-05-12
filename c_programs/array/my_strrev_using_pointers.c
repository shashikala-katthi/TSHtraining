//Write a C program to find reverse of a string using pointers.

#include <stdio.h>
#include<string.h>
#include<stdlib.h>

void my_strrev(char *p)
{
   int i,j;
   int len=strlen(p);
   int temp;
   for(i=0,j=len-1;i<len/2;i++,j--)
  {
      temp=p[i];
      p[i]=p[j];
      p[j]=temp;
  }
  //return p;
}
int main()
{
    char *p;
    char *q;
    int i;
    int n;
    printf("Enter size of string\n");
    scanf("%d",&n);
    p=(char*)malloc(n*sizeof(char));
    q=(char*)malloc(n*sizeof(char));
    printf("Enter string\n");
    scanf(" %[^\n]",p);
    strcpy(q,p);
    my_strrev(p);
    printf("Before reverse string is %s\n",q);
    printf("After reversing string %s is %s\n",q,p);
    
}
