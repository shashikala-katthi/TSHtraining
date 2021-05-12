#include<stdio.h>
 
int main() {
   int arr[20], i, j, k, size;
 
   printf("\nEnter array size : ");
   scanf("%d", &size);
 
   printf("\nEnter Numbers : ");
   for (i = 0; i < size; i++)
      scanf("%d", &arr[i]);
 
   printf("\nArray with out duplicates : ");
   for (i = 0; i < size; i++) {
      for (j = i + 1; j < size;) {
         if (arr[j] == arr[i]) {
            for (k = j; k < size; k++) {
               arr[k] = arr[k + 1];
            }
            size--;
         } else
            j++;
      }
   }
 
   for (i = 0; i < size; i++) {
      printf("%d ", arr[i]);
   }
 
   return 0;
}
/*

Enter array size : 8

Enter Numbers : 2
3
4
3
5
6
5
1

Array with out duplicates : 2 3 4 5 6 1
*/
