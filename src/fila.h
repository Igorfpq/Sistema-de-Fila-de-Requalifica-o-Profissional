#ifndef FILA_H
#define FILA_H

#define MAX 50

typedef struct Worker {
    char name[MAX];
    char course[MAX];
} Worker;

typedef struct Node {
    Worker data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Funções da fila
void initQueue(Queue* q);
int enqueue(Queue* q, const char* name, const char* course);
int dequeue(Queue* q);
void printQueue(const Queue* q);
void destroyQueue(Queue* q);

#endif