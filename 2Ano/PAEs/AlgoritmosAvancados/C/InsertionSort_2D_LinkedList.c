//2d example insertion sort [linked list]

#include <stdio.h>
#include <stdlib.h>

struct node {
 int number;
 struct node *next;
};

struct node *head = NULL;

/* insert a node directly at the right place in the linked list */
void insert_node(int value);

int main(void) {
 struct node *current = NULL;
 struct node *next = NULL;
 int test[] = {8, 3, 2, 6, 1, 5, 4, 7, 9, 0};
 int i = 0;

 /* insert some numbers into the linked list */
 for(i = 0; i < 10; i++)
  insert_node(test[i]);

 /* print the list */
 printf(" before  after\n"), i = 0;
 while(head->next != NULL) {
  printf("%4d\t%4d\n", test[i++], head->number);
  head = head->next;
 }

 /* free the list */
 for(current = head; current != NULL; current = next)
  next = current->next, free(current);

 return 0;
}

void insert_node(int value) {
 struct node *temp = NULL;
 struct node *one = NULL;
 struct node *two = NULL;

 if(head == NULL) {
  head = (struct node *)malloc(sizeof(struct node *));
  head->next = NULL;
 }

 one = head;
 two = head->next;
 
 temp = (struct node *)malloc(sizeof(struct node *));
 temp->number = value;
 
 while(two != NULL && temp->number < two->number) {
  one = one->next;
  two = two->next;
 }

 one->next = temp;
 temp->next = two;
}
