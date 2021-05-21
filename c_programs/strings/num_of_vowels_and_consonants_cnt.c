//Write a C program to find first occurrence of a character in a given string.

#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int main()
{   
    int i;
    char *p;
    char ch;
    p=(char*)malloc(MAX*sizeof(char));
    printf("enter string\n");
    scanf("%[^\n]",p);
    printf("enter character\n");
    scanf(" %c",&ch);
    for(i=0;p[i]!='\0';i++)
    if(p[i]==ch)
    {
        printf("first occurrence of a %c is at %d",ch,i+1);
        return 0;
    }
    printf("%c is not found in %s",ch,p);
    

}
