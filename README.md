 1. Problema Escolhido

No contexto do Future Skills Lab, foi desenvolvido um sistema que gerencia uma fila de trabalhadores que aguardam cursos de requalificação profissional.

Cada trabalhador possui:

Nome

Curso desejado

O sistema permite:

Inserir um trabalhador na fila

Remover o primeiro trabalhador atendido

Mostrar toda a fila

Estrutura de dados utilizada:
➡️ Fila (Queue) implementada com lista encadeada (linked list).

 2. Prompt enviado para a IA
Crie em C um sistema usando FILA (queue) para gerenciar uma fila de trabalhadores que aguardam cursos de requalificação profissional. 
Cada trabalhador deve ter nome e curso desejado. 
Implemente funções: enqueue, dequeue e imprimirFila. 
A fila deve usar alocação dinâmica (struct Node + ponteiros). 
Retorne o código completo em C compilável.

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

A IA produziu um código funcional que:

Compilava corretamente

Implementava as funções enqueue, dequeue e printQueue

Utilizava nós encadeados para gerenciar a fila

 Problemas encontrados
Problema	Impacto
 Não verificava falha do malloc()	Pode causar crash
Uso de strcpy() inseguro	Possível overflow
 Falta de função para liberar memória	Vazamento de memória
 main() simples e pouco robusto	Limita aplicações reais
 5. Melhorias Implementadas

As melhorias realizadas foram:

Verificação de falha em malloc()

 Troca de strcpy() por strncpy() para maior segurança

 Remoção de acentos para evitar problemas no Windows

 Criação da função destroyQueue() para liberar memória

Impressão formatada e mais legível

 Separação do código em fila.h, fila.c e main.c

 Código final mais limpo, seguro e organizado

6. O que foi melhorado (Explicação)


Problema encontrado	Correção aplicada
malloc() sem verificação > Agora há checagem de erro e mensagem adequada
Uso de strcpy() inseguro >  Substituído por strncpy() para evitar overflow
Ausência de destrutor da fila > Criada a função destroyQueue()
Vazamento de memória > Toda memória alocada é corretamente liberada
Falta de robustez no main() > Adicionadas validações e estrutura mais clara
Strings sem limite seguro > Uso de MAX e truncamento garantindo segurança