//Binary search [int array]

#include <stdio.h>

#define TRUE  0
#define FALSE 1

int main(void) {
 int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 int left = 0;
 int right = 10;
 int middle = 0;
 int number = 0;
 int bsearch = FALSE;
 int i = 0;

 printf("ARRAY: ");
 for(i = 1; i <= 10; i++)
  printf("[%d] ", i);

 printf("\nSearch for Number: ");
 scanf("%d", &number);

 while(bsearch == FALSE && left <= right) {
  middle = (left + right) / 2;

  if(number == array[middle]) {
   bsearch = TRUE;
   printf("** Number Found **\n");
  } else {
   if(number < array[middle]) right = middle - 1;
   if(number > array[middle]) left = middle + 1;
  }
 }

 if(bsearch == FALSE)
  printf("-- Number Not found --\n");

 return 0;
}
