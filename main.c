#include "main.h"

int main() {
  Data test[N] = {5, 17, -3, 1337};
  Stack *st = create();
  // assert(sizeof(test) == sizeof(st.a));

  printf("empty: %s\n", is_empty(st) ? "yes" : "no");
  printf("full: %s\n", is_full(st) ? "yes" : "no");

  for (int i = 0; i < N; i++) {
    push(st, test[i]);
    printf("PUSH: %d\n", test[i]);
    print(st);
  }

  printf("empty: %s\n", is_empty(st) ? "yes" : "no");
  printf("full: %s\n", is_full(st) ? "yes" : "no");

  while (!is_empty(st)) {
    printf("POP: %d\n", pop(st));
    print(st);
  }

  printf("empty: %s\n", is_empty(st) ? "yes" : "no");
  printf("full: %s\n", is_full(st) ? "yes" : "no");

  st = destroy(st);

  return 0;
}

void print(Stack *st) {
  printf("stack: ");
  for (uint i = 0; i < st->n; i++) {
    printf("%d ", st->a[i]);
  }
  printf("\n");
}

void init(Stack *st) {
  st->n = 0;
  st->size = 0;
  st->a = NULL;
}

void clear(Stack *st) {
  free(st->a);
  init(st);
}

Stack *create() {
  Stack *st = malloc(sizeof(Stack));
  init(st);
  return st;
}

Stack *destroy(Stack *st) {
  if (st != NULL) {
    free(st->a);
    free(st);
  }
  init(st);
  return NULL;
}

void push(Stack *st, Data d) {
  if (is_full(st)) {
    st->size += N;
    st->a = realloc(st->a, st->size * sizeof(Data));
  }
  st->a[st->n++] = d;
}

Data pop(Stack *st) { return st->a[--st->n]; }

int is_empty(Stack *st) { return st->n == 0; }

int is_full(Stack *st) { return st->n == st->size; }