#include <stdio.h>
#include "fila.h"

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, "Ana", "IA Basica");
    enqueue(&q, "Carlos", "Algoritmos");
    enqueue(&q, "Marina", "Habilidades Digitais");

    printQueue(&q);

    dequeue(&q);

    printQueue(&q);

    destroyQueue(&q);

    return 0;
}