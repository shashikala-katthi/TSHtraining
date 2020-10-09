#include<stdio.h>
#include"calc.h"
#include <stdlib.h>
#include <dlfcn.h>


int main()
{
int a,b,c;
void *handle;
int (*cosine)(int,int);
char *error;
printf("enter any two numbers for calculation\n");
scanf("%d %d",&a,&b);
		
handle = dlopen ("./libcalc.so", RTLD_LAZY);
        if (!handle) {
            fputs (dlerror(), stderr);
            exit(1);
        }
        cosine = dlsym(handle, "add");        //addition
        if ((error = dlerror()) != NULL)  {
            fputs(error, stderr);
            exit(1);
        }
        printf ("add:%d\n", (*cosine)(a,b));
 


        cosine = dlsym(handle, "subtract");    //subtraction
        if ((error = dlerror()) != NULL)  {
            fputs(error, stderr);
            exit(1);
        }

        printf ("sub:%d\n", cosine(a,b));
       


        cosine = dlsym(handle, "multiply");    //multiplication
       if ((error = dlerror()) != NULL)  {
            fputs(error, stderr);
            exit(1);
        }
        printf ("mul:%d\n", cosine(a,b));
       


        cosine = dlsym(handle, "divide");      //division
       if ((error = dlerror()) != NULL)  {
            fputs(error, stderr);
            exit(1);
        }
        printf ("div:%d\n", cosine(a,b));

        dlclose(handle);

return 0;
}
