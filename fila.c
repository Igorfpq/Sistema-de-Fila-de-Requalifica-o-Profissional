#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Worker {
    char name[50];
    char course[50];
} Worker;

typedef struct Node {
    Worker data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

void enqueue(Queue* q, char* name, char* course) {
    Node* temp = (Node*)malloc(sizeof(Node));
    strcpy(temp->data.name, name);
    strcpy(temp->data.course, course);
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

void dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Fila vazia\n");
        return;
    }

    Node* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

void printQueue(Queue* q) {
    Node* temp = q->front;
    while (temp != NULL) {
        printf("Nome: %s - Curso: %s\n", temp->data.name, temp->data.course);
        temp = temp->next;
    }
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, "Ana", "IA Básica");
    enqueue(&q, "Pedro", "Lógica de Programação");

    printQueue(&q);

    dequeue(&q);

    printQueue(&q);

    return 0;
}