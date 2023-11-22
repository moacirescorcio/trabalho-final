#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

// Implementação fictícia da fila
struct Fila {
    int *array;
    int capacidade;
    int tamanho;
    int frente;
    int traseira;
};

Fila criaFila(int capacidade) {
    Fila fila;
    fila.array = (int *)malloc(sizeof(int) * capacidade);
    fila.capacidade = capacidade;
    fila.tamanho = 0;
    fila.frente = 0;
    fila.traseira = -1;
    return fila;
}

void enfileira(int elemento, Fila &fila) {
    if (fila.tamanho < fila.capacidade) {
        fila.traseira = (fila.traseira + 1) % fila.capacidade;
        fila.array[fila.traseira] = elemento;
        fila.tamanho++;
    } else {
        printf("Fila cheia. Não é possível enfileirar %d\n", elemento);
    }
}

int desenfileira(Fila &fila) {
    if (fila.tamanho > 0) {
        int elemento = fila.array[fila.frente];
        fila.frente = (fila.frente + 1) % fila.capacidade;
        fila.tamanho--;
        return elemento;
    } else {
        printf("Fila vazia. Não é possível desenfileirar.\n");
        return -1; // Valor de retorno indicando erro
    }
}

int vaziaf(const Fila &fila) {
    return (fila.tamanho == 0);
}

void destroif(Fila &fila) {
    delete[] fila.array;
}

int main() {
    Fila F = criaFila(5);

    enfileira(1, F);
    enfileira(2, F);
    enfileira(3, F);

    enfileira(desenfileira(F), F);
    enfileira(desenfileira(F), F);

    printf("%d\n", desenfileira(F));

    return 0;
}
