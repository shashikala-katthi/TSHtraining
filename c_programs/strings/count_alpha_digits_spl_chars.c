//Write a C program to find total number of alphabets, digits or special character in a string

#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int main()
{
    char *p;
    int i;
    p=(char*)malloc(MAX*sizeof(char));
    int alphabets_count=0,digits_count=0,special_char_count=0;
    printf("enter string");
    scanf("%[^\n]",p);
    for(i=0;p[i]!='\0';i++)
    if(p[i]>='a'&&p[i]<='z'||p[i]>='A'&&p[i]<='Z')
    alphabets_count++;
    else if(p[i]>='0'&&p[i]<='9')
    digits_count++;
    else
    special_char_count++;
    printf("alphabets_count =%d,digits_count=%d,special_char_count=%d",
    alphabets_count,digits_count,special_char_count);

}
