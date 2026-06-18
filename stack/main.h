#ifndef __STACK_H__
#define __STACK_H__

typedef struct node {
    int data;
    struct node *next;
} Node;

int init(int data);
int push(int data);
int pop(void);
int peek(void);
int traverse(void);
void test(void);

#endif