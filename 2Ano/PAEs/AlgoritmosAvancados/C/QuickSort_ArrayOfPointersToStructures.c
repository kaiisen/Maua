//Qsort [array of pointers to structures]

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
 char *str;
};

/* compare function for qsort */
static int cmpr(const void *a, const void *b);

int main(void) {
 struct node **strarray = NULL;
 int i = 0, count = 0;
 char line[1024];

 while(fgets(line, 1024, stdin) != NULL) {
  /* add ONE element to the array */
  strarray = (struct node **)realloc(strarray, (count + 1) * sizeof(struct node *));

  /* allocate memory for ONE `struct node` */
  strarray[count] = (struct node *)malloc(sizeof(struct node));

  /* copy the data into the new element (structure) */
  strarray[count]->str = strdup(line);
  count++;
 }

 /* before sorting ... */
 printf("Before:\n");
 for(i = 0; i < count; i++) {
  printf("[%d]->str: %s", i, strarray[i]->str);
 }

 /* qsort array of structures */
 qsort(strarray, count, sizeof(*strarray), cmpr);

 /* after sorting ... */
 printf("\n--\nAfter:\n");
 for(i = 0; i < count; i++) {
  printf("[%d]->str: %s", i, strarray[i]->str);
 }

 /* free all strarray elements */
 for(i = 0; i < count; i++) {
  free(strarray[i]->str);
  free(strarray[i]);
  i++;
 }
 free(strarray);
  
 return 0;
}

/* compare function for qsort */
static int cmpr(const void *a, const void *b) { 
 struct node * const *one = a;
 struct node * const *two = b;

 return strcmp((*one)->str, (*two)->str);
}
