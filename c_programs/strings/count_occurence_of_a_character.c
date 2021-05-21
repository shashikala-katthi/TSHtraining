// Write a C program to count occurrences of a character in given string.

#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int main()
{   
    int i;
    char *p;
    char ch;
    int count=0;
    p=(char*)malloc(MAX*sizeof(char));
    printf("enter string\n");
    scanf("%[^\n]",p);
    printf("enter character\n");
    scanf(" %c",&ch);
    for(i=0;p[i]!='\0';i++)
    if(p[i]==ch)
    {
        count++;
    }
    if(count)
    printf("%c is found in %d times in %s",ch,count,p);
    else
    printf("%c is not found in %s",ch,p);
    

}
