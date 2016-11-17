#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node *leftChild;
  struct Node *rightChild;
};

struct Node *root = NULL;
struct Node *parent = NULL;

void insert(int value) {
  struct Node *newNode = (struct Node*) malloc(sizeof(Node));
  newNode->value = value;
  newNode->leftChild = NULL;
  newNode->rightChild = NULL;

  if(root == NULL) {
    root = newNode;
  } else {
    parent = root;

    while(parent != NULL) {
      if(value < parent->value) {
        // Go to left side
        if(parent->leftChild == NULL) {
          parent->leftChild = newNode;
          break;
        } else {
          parent = parent->leftChild;          
        }
      } else {
        // Go to right side
        if(parent->rightChild == NULL) {
          parent->rightChild = newNode;
          break;
        } else {
          parent = parent->rightChild;          
        }
      }
    }

  }
}

void buildTree() {
  insert(50);
  insert(25);
  insert(40);
  insert(23);
  insert(80);
  insert(90);
  insert(85);
}

void preOrderTraversal(struct Node* root) {
  if(root != NULL) {
    printf("%d ", root->value);
    preOrderTraversal(root->leftChild);
    preOrderTraversal(root->rightChild);
  }
}

void inOrderTraversal(struct Node* root) {
  if(root != NULL) {
    inOrderTraversal(root->leftChild);
    printf("%d ", root->value);
    inOrderTraversal(root->rightChild);
  }
}

void postOrderTraversal(struct Node* root) {
  if(root != NULL) {
    postOrderTraversal(root->leftChild);
    postOrderTraversal(root->rightChild);
    printf("%d ", root->value);
  }
}

int main() {
  buildTree();
  printf("Pre Order:\n");
  preOrderTraversal(root);

  printf("\nIn Order:\n");
  inOrderTraversal(root);

  printf("\nPost Order:\n");
  postOrderTraversal(root);
  printf("\n");

  return 0;
}