// Write a C program to replace all occurrences of a character with another in a string.

#include <stdio.h>
#include<string.h>
#include<stdlib.h>

void replace_character_with_another(char *p,char ch1,char ch2)
{
   int i,j;
   int len=strlen(p);
   for(i=0;i<len;i++)
  {
      if(p[i]==ch1)
      p[i]=ch2;
  }
}
int main()
{
    char *p;
    char *q;
    int i;
    int n;
    char ch1,ch2;
    printf("Enter size of string\n");
    scanf("%d",&n);
    p=(char*)malloc(n*sizeof(char));
    q=(char*)malloc(n*sizeof(char));
    printf("Enter string\n");
    scanf(" %[^\n]",p);
    printf("Enter char1 which need to replace with char2 in its ocurence\n");
    scanf(" %c,%c",&ch1,&ch2);
    strcpy(q,p);
    replace_character_with_another(p,ch1,ch2);
    printf("string is %s\n",q);
    printf("After replacing  %c character with %c character in its ocurence in string %s is %s\n",ch1,ch2,q,p);
    
}
