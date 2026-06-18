#include "main.h"
#include <stdio.h>
#include <stdlib.h>

Node *head = NULL;
Node *tail = NULL;

int init(int data) {
  head = (Node *)malloc(sizeof(Node));
  tail = head;

  if (head == NULL) {
    return -1; // Memory allocation failed
  }

  head->data = data;
  head->next = NULL;

  printf("Initialized queue with %d.\n", head->data);

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

int enqueue(int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));

  if (new_node == NULL) {
    return -1; // Memory allocation failed
  }

  new_node->data = data;
  new_node->next = NULL;

  if (tail == NULL) {
    head = new_node;
  } else {
    tail->next = new_node;
  }

  tail = new_node;

  printf("Enqueued %d to the queue.\n", data);

  return 0; // Success
}

int dequeue(void) {
  if (head == NULL) {
    printf("Queue is empty. Cannot dequeue.\n");
    return -1; // Queue is empty
  }

  Node *temp = head;
  int data = temp->data;

  head = head->next;

  if (head == NULL) {
    tail = NULL; // If the queue becomes empty, set tail to NULL
  }

  free(temp); // Free the memory of the dequeued node

  printf("Dequeued %d from the queue.\n", data);

  return data; // Return the dequeued data
}

int main(void) {
  test();

  return (0);
}

void test(void) {
  init(1);

  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);
  traverse();

  dequeue();
  dequeue();
  traverse();

  enqueue(50);
  enqueue(60);
}