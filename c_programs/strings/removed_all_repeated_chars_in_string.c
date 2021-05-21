//Write a C program to remove all repeated characters from a given string.

#include <stdio.h>
#include<stdlib.h>
#define MAX 20
int main()
{
    int i,j,k;
    char a[MAX];
    int len;
    char *p;
    int count=0;
    printf("enter string\n");
    scanf("%[^\n]",a);
    for(i=0;a[i]!='\0';i++);
    len=i;
    p=(char*)calloc(len,sizeof(char));
    
    for(i=0;i<len;i++)
    {  
        for(j=i+1;j<len;j++)
        {
            if(a[i]==a[j])
            {
                for(k=j;k<len-1;k++)
                a[k]=a[k+1];
                len--;
            }
        }
    }
    for(i=0;i<len;i++)
    printf("%c",a[i]);
    
}
