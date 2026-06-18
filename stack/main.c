#include "main.h"
#include <stdio.h>
#include <stdlib.h>

Node *top = NULL;

int init(int data) {
    top = (Node *)malloc(sizeof(Node));

    if (top == NULL) {
        return -1; // Memory allocation failed
    }

    top->data = data;
    top->next = NULL;

    printf("Initialized stack with %d.\n", top->data);

    return 0; // Success
}

int push(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));

    if (new_node == NULL) {
        return -1; // Memory allocation failed
    }

    new_node->data = data;
    new_node->next = top;

    top = new_node;

    printf("Pushed %d onto the stack.\n", data);

    return 0; // Success
}

int pop(void) {
    if (top == NULL) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Stack is empty
    }

    Node *temp = top;
    int data = temp->data;

    top = top->next;

    free(temp);

    printf("Popped %d from the stack.\n", data);

    return data; // Return the popped data
}

int traverse(void) {
    Node *current = top;

    while (current != NULL) {
        printf("Data: %d\n", current->data);
        current = current->next;
    }

    return 0; // Success
}

int peek(void) {
    if (top == NULL) {
        printf("Stack is empty. Cannot peek.\n");
        return -1; // Stack is empty
    }

    return top->data; // Return the data at the top of the stack
}

void test(void) {
    init(1);

    push(10);
    push(20);
    push(30);
    push(40);

    traverse();

    pop();
    pop();

    traverse();

    push(50);
    push(60);

    printf("Top: %d\n", peek());

    peek();
}

int main(void) {
    test();

    return 0;
}