#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef int Data;
typedef unsigned int uint;
typedef struct {
  Data *a;
  uint n;
  size_t size;
} Stack;

void print(Stack *st);
void init(Stack *st);
void clear(Stack *st);
Stack *create();
Stack *destroy(Stack *st);
void push(Stack *st, Data d);
Data pop(Stack *st);
int is_empty(Stack *st);
int is_full(Stack *st);