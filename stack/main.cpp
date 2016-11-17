#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

struct task {
  int value;
};

struct task *entries[MAX];
int lastNdx = -1;

void insert(int value) {
  struct task *newTask = (struct task*) malloc(sizeof(struct task));

  newTask->value = value;

  if(lastNdx == MAX) {
    return;
  }

  entries[++lastNdx] = newTask;
}

void printStack() {
  int position = 1;
  printf("\n\nResults:\n");
  for(int i=lastNdx; i >= 0; i--) {
    printf("Ndx: %d \t Entry: %d \t Value: %d\n", i, position++, entries[i]->value);
  }
}

struct task* peek() {
  return entries[lastNdx];
}

struct task* pop() {
  return entries[lastNdx--];
}

int main() {
  insert(1);
  insert(2);
  insert(3);

  printStack();

  pop();
  pop();

  printStack();

  return 0;
}