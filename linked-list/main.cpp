#include <iostream>
#include <stdio.h>
#include <stdlib.h>


struct node {
  int key;
  int value;
  node *next;
};

struct node *head = NULL;
struct node *current = NULL;


bool isEmpty() {
  return head == NULL;
}

int length() {
  int len = 0;
  current = head;

  while(current != NULL) {
    len++;
    current = current->next;
  }

  return len;
}

struct node* getTail() {
  current = head;

  if(head == NULL) {
    return head;
  }

  while(current->next != NULL) {
    current = current->next;
  }

  return current;
}

void insertFirst(int key, int value) {
  struct node *link = (struct node*) malloc(sizeof(struct node));

  link->key = key;
  link->value = value;

  link->next = head;

  head = link;
}

void insertEnd(int key, int value) {
  struct node *link = (struct node*) malloc(sizeof(struct node));

  link->key = key;
  link->value = value;
  link->next = NULL;

  current = getTail();
  
  current->next = link;
}


void printList() {
  current = head;

  while(current != NULL) {
    printf("(%d, %d)\n", current->key, current->value);
    current = current->next;
  }
}

int main() {
  printf("Starting\n");

  if(isEmpty()) {
    printf("EMPTY\n");
  } else {
    printf("Size: %d\n", length());
  }

  insertFirst(1,10);
  insertFirst(2,20);
  insertFirst(3,30);

  printList();

  insertEnd(4,40);
  insertEnd(5,50);

  struct node *tail;
  tail = getTail();
  printf("Tail: (%d, %d)\n", tail->key, tail->value);

  if(isEmpty()) {
    printf("EMPTY\n");
  } else {
    printf("Size: %d\n", length());
  }
  
  printList();

  return 0;
}