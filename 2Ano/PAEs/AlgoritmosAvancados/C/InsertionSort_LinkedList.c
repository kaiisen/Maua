//Insertion sort [linked list]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lnode {
 char *str;
 struct lnode *next;
};

struct lnode *insert(char *data, struct lnode *list);
void free_list(struct lnode *list);
void print_list(struct lnode *list);

int main(void) {
 char line[1024];
 struct lnode *list;

 list = NULL;
 while((fgets(line, 1024, stdin)) != NULL) 
  list = insert(line, list);

 print_list(list);
 free_list(list);
 return 0;
}

struct lnode *insert(char *data, struct lnode *list) {
 struct lnode *p;
 struct lnode *q;

 /* create a new node */
 p = (struct lnode *)malloc(sizeof(struct lnode));
 /* save data into new node */
 p->str = strdup(data);

 /* first, we handle the case where `data' should be the first element */
 if(list == NULL || strcmp(list->str, data) > 0) {
  /* apperently this !IS! the first element */
  /* now data should [be|becomes] the first element */
  p->next = list;
  return p;
 } else {  
  /* search the linked list for the right location */
  q = list;
  while(q->next != NULL && strcmp(q->next->str, data) < 0) {
   q = q->next;
  }
  p->next = q->next;
  q->next = p;
  return list;
 }
}
    
void free_list(struct lnode *list) {
 struct lnode *p;

 while(list != NULL) {
  p = list->next;
  free(list);
  list = p;
 }
}
  
void print_list(struct lnode *list) {
 struct lnode *p;
  
 for(p = list; p != NULL; p = p->next)
  printf("%s", p->str);
}
