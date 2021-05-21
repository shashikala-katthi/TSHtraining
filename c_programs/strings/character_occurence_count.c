//Write a C program to count frequency of each character in a string.

#include <stdio.h>
#include<stdlib.h>
#define MAX 20
int main()
{
    int i,j;
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
    {  count=1;
       if(a[i])
       {
            for(j=i+1;j<len;j++)
        {
            if(a[i]==a[j]&&a[i]!='\0')
            {
                count++;
                a[j]='\0';
            }
        }
        if(count)
        printf("\n%c is occured %d times",a[i],count);
        count=0;
       }
       
    }
    
}
/*
enter string
shashi

s is occured 2 times
h is occured 2 times
a is occured 1 times
i is occured 1 times
*/
