#include <stdio.h>
 
int main()
{
	int arr[10],i,j,Size,Count = 0;
	
	printf("\n Enter size of an array  :   ");
	scanf("%d", &Size);
	
	printf("\n Enter %d elements of an Array  :  ", Size);
	for (i = 0;i<Size; i++)
	{
    	scanf("%d", &arr[i]);
   	}     
 
	for (i = 0; i < Size; i++)
	{
		for(j =i+1; j<Size;j++)
		{
    		if(arr[i]==arr[j])
    			{
    			Count++;
				break;
			}
		}
	}

 	printf("\n Duplicate Elements in this Array= %d ", Count);
	     
 	return 0;
}
/*Enter size of an array  :   7

Enter 7 elements of an Array  :  2
3
3
2
1
5
1

 Duplicate Elements in this Array= 3 
*/
