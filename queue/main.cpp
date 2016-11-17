#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct task {
  int value;
  struct task *next;
  struct task *prev;
};

struct task *head = NULL;
struct task *current = NULL;
struct task *lastNode = NULL;

void insert(int value) {
  struct task *newNode = (struct task*) malloc(sizeof(struct task));
  newNode->value = value;
  newNode->next = NULL;
  newNode->prev = NULL;

  if(head == NULL) {
    head = newNode;
    lastNode = head;
    return;
  }

  lastNode->next = newNode;
  newNode->prev = lastNode;

  lastNode = newNode;
}

void printQueue() {
  printf("Printing Queue\n");

  current = head;

  while(current != NULL) {
    printf("Value: %d\n", current->value);
    current = current->next;
  }

  printf("\n");
}

int pop() {
  if(head == NULL) {
    return -1;
  }

  int result = lastNode->value;

  lastNode = lastNode->prev;
  lastNode->next = NULL;

  return result;
}

int main() {
  insert(123);
  insert(222);
  insert(346);
  insert(42345);

  printQueue();


  printf("Popped Value: %d\n", pop());
  printf("Popped Value: %d\n", pop());

  printQueue();

  return 0;
}