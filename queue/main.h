#ifndef __QUEUE_H__
#define __QUEUE_H__

typedef struct node {
    int data;
    struct node *next;
} Node;

int init(int data);
int enqueue(int data);
int dequeue(void);
int peek(void);
int traverse(void);
void test(void);

#endif