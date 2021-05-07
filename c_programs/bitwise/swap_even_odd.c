#include <stdio.h>
 unsigned int swapbits(unsigned int x);

int main()
{
    unsigned int x,t;
int i,mask;
	printf("enter any number\n");
	scanf("%d",&x);
 
  printf("bit patteren of given number is \n");

	for(i=31;i>=0;i--){
		mask=1<<i;
		printf("%d",(x&mask)?1:0);
		}

	printf("\n");
t=swapbits(x);	
        printf("after reversing \n");
	for(i=31;i>=0;i--){
		mask=1<<i;
		printf("%d",(t&mask)?1:0);
		}

	printf("\n");
return 0;
}
unsigned int swapbits(unsigned int x)
{
   unsigned int even_bits,odd_bits;
    // Get all even bits of x
   even_bits = x & 0xAA;
 
    // Get all odd bits of x
     odd_bits  = x & 0x55;
 
    even_bits >>= 1;  // Right shift even bits
    odd_bits <<= 1;   // Left shift odd bits
 
    return (even_bits | odd_bits); 
}
 
/*enter any number
15
bit patteren of given number is 
00000000000000000000000000001111
after reversing 
00000000000000000000000000001111
katthi@katthi-Inspiron-15-3567:~/Downloads/c_programs/bitwise$ ./a.out
enter any number
5
bit patteren of given number is 
00000000000000000000000000000101
after reversing 
00000000000000000000000000001010
*/

