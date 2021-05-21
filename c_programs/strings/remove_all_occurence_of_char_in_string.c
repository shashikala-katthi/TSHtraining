// Write a C program to remove all occurrences of a character from string

#include <stdio.h>
#include<string.h>
#include<stdlib.h>

void removing_occurence_of_char_in_string(char *p,char ch)
{
   int i,j;
   int len=strlen(p);
   for(i=0;i<len;)
  {
      if(ch==p[i])
      {   j=i;
          while(j<len)
          {
              p[j]=p[j+1];
              j++;
          }
          
      }
      else
      i++;
  }
}
int main()
{
    char *p;
    char *q;
    int i;
    int n;
    char ch;
    printf("Enter size of string\n");
    scanf("%d",&n);
    p=(char*)malloc(n*sizeof(char));
    q=(char*)malloc(n*sizeof(char));
    printf("Enter string\n");
    scanf(" %[^\n]",p);
    printf("Enter character to be removed in its ocurence\n");
    scanf(" %c",&ch);
    strcpy(q,p);
    removing_occurence_of_char_in_string(p,ch);
    printf("string is %s\n",q);
    printf("After removing  %c character in its ocurence string %s is %s\n",ch,q,p);
    
}
