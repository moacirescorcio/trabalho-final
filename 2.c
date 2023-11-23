#include <stdio.h>
#include <stdlib.h>

#define MAX_TAMANHO 100

typedef struct {
    int items[MAX_TAMANHO];
    int topo;
} Pilha;

// Inicializa uma pilha
void inicializaPilha(Pilha *p) {
    p->topo = -1;
}

// Verifica se a pilha está cheia
int pilhaCheia(Pilha *p) {
    return p->topo == MAX_TAMANHO - 1;
}

// Verifica se a pilha está vazia
int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

// Empilha um item
void empilha(Pilha *p, int item) {
    if (pilhaCheia(p)) {
        printf("Erro: Pilha cheia\n");
        exit(1);
    }
    p->topo++;
    p->items[p->topo] = item;
}

// Desempilha um item
int desempilha(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Erro: Pilha vazia\n");
        exit(1);
    }
    int item = p->items[p->topo];
    p->topo--;
    return item;
}

// Insere um elemento na fila
void entrarNaFila(Pilha *entrada, int elemento) {
    empilha(entrada, elemento);
}

// Remove e retorna o elemento mais antigo da fila (implementando a operação dequeue)
int sairDaFila(Pilha *entrada, Pilha *saida) {
    if (pilhaVazia(saida)) {
        // Se a pilha de saída está vazia, transfere os elementos da pilha de entrada para a pilha de saída
        while (!pilhaVazia(entrada)) {
            int elemento = desempilha(entrada);
            empilha(saida, elemento);
        }
    }

    if (pilhaVazia(saida)) {
        // Se a pilha de saída ainda está vazia, a fila está vazia
        printf("Erro: Fila vazia\n");
        exit(1);
    }

    // Retorna o elemento mais antigo da fila
    return desempilha(saida);
}

int main() {
    Pilha pilhaEntrada, pilhaSaida;
    inicializaPilha(&pilhaEntrada);
    inicializaPilha(&pilhaSaida);

    entrarNaFila(&pilhaEntrada, 1);
    entrarNaFila(&pilhaEntrada, 2);
    entrarNaFila(&pilhaEntrada, 3);

    printf("Elemento removido: %d\n", sairDaFila(&pilhaEntrada, &pilhaSaida));
    printf("Elemento removido: %d\n", sairDaFila(&pilhaEntrada, &pilhaSaida));
    printf("Elemento removido: %d\n", sairDaFila(&pilhaEntrada, &pilhaSaida));

    return 0;
}
