#include <iostream>
#include <cstdlib>
#include <stdio.h>

struct Fila {
    char *array;
    int capacidade;
    int tamanho;
    int frente;
    int traseira;
};

Fila criaFila(int capacidade) {
    Fila fila;
    fila.array = new char[capacidade];
    fila.capacidade = capacidade;
    fila.tamanho = 0;
    fila.frente = 0;
    fila.traseira = -1;
    return fila;
}

void enfileira(char elemento, Fila &fila) {
    if (fila.tamanho < fila.capacidade) {
        fila.traseira = (fila.traseira + 1) % fila.capacidade;
        fila.array[fila.traseira] = elemento;
        fila.tamanho++;
    } else {
        std::cerr << "Fila cheia. Não é possível enfileirar " << elemento << std::endl;
    }
}

int vaziaf(const Fila &fila) {
    return (fila.tamanho == 0);
}

char desenfileira(Fila &fila) {
    if (fila.tamanho > 0) {
        char elemento = fila.array[fila.frente];
        fila.frente = (fila.frente + 1) % fila.capacidade;
        fila.tamanho--;
        return elemento;
    } else {
        std::cerr << "Fila vazia. Não é possível desenfileirar." << std::endl;
        return '\0'; // Valor de retorno indicando erro
    }
}

void destroif(Fila &fila) {
    delete[] fila.array;
}

int main() {
    Fila F = criaFila(5);

    for (int i = 0; i <= 3; i++) {
        enfileira('A' + i, F);
    }

    while (!vaziaf(F)) {
        printf("%c\n", desenfileira(F));
    }


    destroif(F);

    return 0;
}
