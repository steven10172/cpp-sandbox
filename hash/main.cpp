#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#define MAX 50

struct DataItem {
  int key;
  std::string data;
  struct DataItem *next;
};

struct DataItem *hashTable[MAX];
struct DataItem *current;


int gethash(std::string data) {
  int hash = 0;
  for(std::string::iterator it=data.begin(); it != data.end(); ++it) {
    hash += (int)(*it);
  }
  return hash;
}

void insert(std::string data) {
  struct DataItem *dItem = (struct DataItem*) malloc(sizeof(struct DataItem));

  int hashKey = gethash(data) % (sizeof(hashTable) / sizeof(struct DataItem*));

  dItem->data = data;
  dItem->next = NULL;

  if(hashTable[hashKey] == NULL) {
    hashTable[hashKey] = dItem;
  } else {
    current = hashTable[hashKey];
    while(current->next != NULL) {
      current = current->next;
    }

    current->next = dItem;
  }
}

void printHash() {
  for(int i=0; i<MAX; i++) {
    current = hashTable[i];

    while(current != NULL) {
      printf("Entry: %d\t Value: %s\n", i, current->data.c_str());
      current = current->next;
    }
  }
}

bool contains(std::string data) {
  int hashKey = gethash(data) % (sizeof(hashTable) / sizeof(struct DataItem*));

  current = hashTable[hashKey];

  while(current != NULL) {
    if(current->data == data) {
      return true;
    }
    current = current->next;
  }

  return false;
}

int main() {
  for(int i=0; i<MAX; i++) {
    hashTable[i] = NULL;
  }

  insert("A");
  insert("B");
  insert("C");
  insert("Steven");
  insert("Scott");

  printHash();
  
  if(contains("Steven")) {
    printf("Contains: Steven\n");
  }

  if(contains("Test")) {
    printf("Contains: Test\n");
  }

  return 0;
}