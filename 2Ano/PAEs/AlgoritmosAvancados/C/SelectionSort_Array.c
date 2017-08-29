//Ssort, selection sort [array]

#include <stdio.h>

void selection_sort(int a[], int size);

int main(void) {
 int arr[10] = {10, 2, 4, 1, 6, 5, 8, 7, 3, 9};
 int i = 0;

 printf("before:\n");
 for(i = 0; i < 10; i++) printf("%d ", arr[i]);
 printf("\n");

 selection_sort(arr, 10);

 printf("after:\n");
 for(i = 0; i < 10; i++) printf("%d ", arr[i]);
 printf("\n");

 return 0;
}

void selection_sort(int a[], int size) {
 int i = 0;
 int j = 0;
 int large = 0;
 int index = 0;

 for(i = size - 1; i > 0; i--) {
  large = a[0];
  index = 0;
  for(j = 1; j <= i; j++)
   if(a[j] > large) {
    large = a[j];
    index = j;
   }
   a[index] = a[i];
   a[i] = large;
 }
}
