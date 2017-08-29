//Qsort [string, dynamic pointer array]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sortstrarr(void *array, unsigned n);
static int cmpr(const void *a, const void *b);

int main (void) {
 char **strarray = NULL;
 int i = 0, strcount = 0;
 char line[1024];
 
 while((fgets(line, 1024, stdin)) != NULL) {
  if(strlen(line) == 1)
   continue;

  strarray = (char **)realloc(strarray, (strcount + 1) * sizeof(char *));
  strarray[strcount++] = strdup(line);
 }
                  
 printf("### Before ###\n");
 for(i = 0; i < strcount; i++)
  printf("%2d: %s", i, strarray[i]);

 sortstrarr(strarray, strcount);

 printf("### After ###\n");
 for(i = 0; i < strcount; i++)
  printf("%2d: %s", i, strarray[i]);

 /* free mem... */
 for(i = 0; i < strcount; i++)
  free(strarray[i]);

 free(strarray);
 return 0;
}

static int cmpr(const void *a, const void *b) { 
 return strcmp(*(char **)a, *(char **)b);
}

void sortstrarr(void *array, unsigned n) { 
 qsort(array, n, sizeof(char *), cmpr);
}
