#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node_t;

typedef struct list {
  int count;
  node_t *first;
} list_t;

void init_list(list_t *l) {
  l->count = 0;
  l->first = NULL;
}

void append_to_list(list_t *l, int data) {
  node_t *new = (node_t *) malloc(sizeof(node_t));
  new->data = data;
  new->next = NULL;
  if (l->count == 0)
    l->first = new;
  else {
    node_t *i = l->first;
    while (i->next != NULL)
      i = i->next;
    i->next = new;
  }
  l->count++;
}

void print_list(list_t *l) {
  printf("Length: %d\n", l->count);
  node_t *i = l->first;
  while (i != NULL) {
    printf("%d ", i->data);
    i = i->next;
  }
  printf("\n");
}

void delete_list(list_t *l) {
  node_t *i = l->first;
  while (i != NULL) {
    node_t *to_remove = i;
    i = i->next;
    free(to_remove);
  }
}

int main() {
  list_t l;
  
  init_list(&l);

  append_to_list(&l, 5);
  append_to_list(&l, -3);
  append_to_list(&l, 328);

  print_list(&l);

  delete_list(&l);
}
