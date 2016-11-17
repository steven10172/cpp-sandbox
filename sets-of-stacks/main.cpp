#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define MAX_PER_STACK 10

struct stack {
  int data[MAX_PER_STACK];
  struct stack *next;
  struct stack *prev;
};

class SetOfStacks {
  struct stack *current;
  struct stack *nextStack;
  int ndx;


  public:
    SetOfStacks() : ndx(0) {
      current = (struct stack*)malloc(sizeof(stack));
      current->next = NULL;
      current->prev = NULL;
    }
    ~SetOfStacks() {

    }
    void insert(int value) {
      printf("Inserting at %d\n", ndx % MAX_PER_STACK);
      current->data[ndx % MAX_PER_STACK] = value;
      ndx++;

      if(ndx % MAX_PER_STACK == 0) {
        nextStack = (struct stack*) malloc(sizeof(stack));
        nextStack->prev = current;
        nextStack->next = NULL;

        current->next = nextStack;

        current = nextStack;
        printf("Created new stack\n");
      }
    }
    void print() {
      struct stack *currStack;
      currStack = current;
      for(int i=ndx-1; i>=0; i--) {
        printf("Ndx: %d \t Value: %d\n", i % MAX_PER_STACK, currStack->data[i % MAX_PER_STACK]);
        if(ndx % MAX_PER_STACK == 0) {
          currStack = currStack->prev;
          if(currStack == NULL) {
            return;
          }
        }
      }
    }
    int pop() {
      return 0;
    }
};

int main() {
  SetOfStacks *stack = new SetOfStacks();

  for(int i=0; i<=9; i++) {
    stack->insert(i);
  }

  stack->print();

  return 0;
}