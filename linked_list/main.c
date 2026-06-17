#include "main.h"
#include <stdio.h>
#include <stdlib.h>

Node *head = NULL;

int init(int data) {
  head = (Node *)malloc(sizeof(Node));

  if (head == NULL) {
    return -1; // Memory allocation failed
  }

  head->data = data;
  head->next = NULL;

  printf("Initialized list with %d.\n", head->data);

  return 0; // Success
};

int add(int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));

  if (new_node == NULL) {
    return -1; // Memory allocation failed
  }

  new_node->data = data;
  new_node->next = head;
  head = new_node;

  printf("Added %d to the list.\n", new_node->data);

  return 0; // Success
};

int traverse(void) {
  Node *current = head;

  while (current != NULL) {
    printf("Data: %d\n", current->data);
    current = current->next;
  }

  return 0; // Success
}

int delete(int data) {
  Node *current = head;
  Node *previous = NULL;

  while (current != NULL) {
    if (current->data == data) {
      if (previous == NULL) {
        head = current->next; // Deleting the head node
      } else {
        previous->next = current->next; // Bypass the current node
      }
      free(current); // Free the memory of the deleted node

      printf("Deleted %d from the list.\n", data);
      return 0; // Success
    }

    previous = current;
    current = current->next;
  }

  return 0;
}

int search(int data) {
  Node *current = head;

  while (current != NULL) {
    if (current->data == data) {
      printf("Found %d in the list.\n", data);
      return 0; // Success
    }
    current = current->next;
  }

  printf("%d not found in the list.\n", data);

  return -1; // Not found
}

int main(void) {
  test();
  
  return (0);
}

void test(void) {
  init(10);
  add(20);
  add(30);

  traverse();

  delete(20);
  printf("After deletion:\n");

  traverse();

  search(30);
  search(20);
  search(40);
}