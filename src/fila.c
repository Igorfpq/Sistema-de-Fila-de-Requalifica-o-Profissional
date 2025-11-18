#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

int enqueue(Queue* q, const char* name, const char* course) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (!temp) {
        printf("Erro: memoria insuficiente.\n");
        return 0;
    }

    strncpy(temp->data.name, name, MAX - 1);
    strncpy(temp->data.course, course, MAX - 1);

    temp->data.name[MAX - 1] = '\0';
    temp->data.course[MAX - 1] = '\0';

    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return 1;
    }

    q->rear->next = temp;
    q->rear = temp;
    return 1;
}

int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Fila vazia.\n");
        return 0;
    }

    Node* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return 1;
}

void printQueue(const Queue* q) {
    Node* temp = q->front;

    printf("\n=== FILA DE REQUALIFICACAO ===\n");

    if (!temp) {
        printf("Fila vazia.\n");
        return;
    }

    while (temp != NULL) {
        printf("Nome: %-20s Curso: %s\n", temp->data.name, temp->data.course);
        temp = temp->next;
    }
}

void destroyQueue(Queue* q) {
    while (q->front != NULL)
        dequeue(q);
}
