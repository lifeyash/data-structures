#ifndef __LIST_H__
#define __LIST_H__

typedef struct node {
    int data;
    struct node *next;
} Node;

int init(int data);
int add(int data);
int traverse(void);
int delete(int data);   
int search(int data);
int insert(int data, int position);
int add_end(int data);
void test(void);

#endif