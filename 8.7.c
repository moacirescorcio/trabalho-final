#include <stdio.h>

// Função recursiva para busca binária
int binarySearch(int x, int v[], int p, int u) {
    if (p > u) {
        return -1;  // Elemento não encontrado
    }

    int meio = (p + u) / 2;

    if (v[meio] == x) {
        return meio;  // Elemento encontrado, retorna o índice
    } else if (v[meio] < x) {
        // Se o elemento no meio for menor que x, busca na metade direita
        return binarySearch(x, v, meio + 1, u);
    } else {
        // Se o elemento no meio for maior que x, busca na metade esquerda
        return binarySearch(x, v, p, meio - 1);
    }
}

int main() {
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int elemento = 7;

    // Chama a função de busca binária
    int resultado = binarySearch(elemento, vetor, 0, tamanho - 1);

    // Verifica o resultado da busca
    if (resultado != -1) {
        printf("Elemento %d encontrado no índice %d\n", elemento, resultado);
    } else {
        printf("Elemento %d não encontrado no vetor\n", elemento);
    }

    return 0;
}
