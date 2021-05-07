//Write a C program to rotate bits of a given number.
#include <stdio.h>
int create(int num_of_bits)
{
int i=(1<<num_of_bits)-1;
//printf("%x",i);
return i;
}
int left_to_right_rotate(int n,int num_of_bits)
{
    int i=create(num_of_bits);
    int k=n&i<<(31-num_of_bits);
    n=n<<num_of_bits;
    n=n|k;
    printf("%x",n);
}
int right_to_left_rotate(int n,int num_of_bits)
{
    int i=create(num_of_bits);
    int k=n&i;
    k=k<<32-num_of_bits;
    n=n>>num_of_bits;
    n=n|k;
    printf("%x",n);
}
int main()
{
unsigned n;
int num_of_bits;
int choice;
printf("enter number,no_of_bits_to_shift,choice(0--left,1--right)\n");
scanf("%x,%d,%d",&n,&num_of_bits,&choice);
switch(choice):
case 0:
left_to_right_rotate(int n,int num_of_bits);
break
case 1:
right_to_left_rotate(n,num_of_bits);
}

