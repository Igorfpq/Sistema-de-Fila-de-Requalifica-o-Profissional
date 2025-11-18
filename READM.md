1. Problema Escolhido

No contexto do Future Skills Lab, criei um sistema que gerencia uma fila de trabalhadores que aguardam cursos de requalificação profissional.

Cada trabalhador possui:
Nome
Curso desejado

O sistema deve permitir:
Inserir um trabalhador na fila
Remover o primeiro trabalhador atendido
Mostrar toda a fila

Estrutura de dados utilizada: FILA implementada com lista encadeada.

2. Prompt enviado para a IA

"Crie em C um sistema usando FILA (queue) para gerenciar uma fila de trabalhadores que aguardam cursos de requalificação profissional. 
Cada trabalhador deve ter nome e curso desejado. 
Implemente funções: enqueue, dequeue e imprimirFila. 
A fila deve usar alocação dinâmica (struct Node + ponteiros). 
Retorne o código completo em C compilável."

3. Código Gerado Pela IA

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


4. Análise Crítica da Solução da IA

Correção

.código compilava e funcionava.
.nqueue, dequeue e printQueue funcionavam como esperado.
.Estrutura de fila estava correta.

Problemas encontrados

Não verificava se malloc() falhou  -----> Possível crash
strcpy() inseguro  -----> Possível estouro de memória
Não tinha função para destruir a fila -----> Vazamento de memória
main() sem tratamento de saída -----> Limita aplicações reais

5. Melhorias implementadas

Verificação de erro em malloc()
Troca de strcpy por strncpy
Remoção de acentos para compatibilidade com Windows
Nova função destroyQueue
Impressão formatada
Saídas mais limpas e consistentes

