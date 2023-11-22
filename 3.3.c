#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    char *itens;
    int topo;
    int capacidade;
} PilhaStruct;

typedef PilhaStruct *Pilha;

Pilha pilha(int capacidade) {
    Pilha P = (Pilha)malloc(sizeof(PilhaStruct));
    P->itens = (char *)malloc(capacidade * sizeof(char));
    P->topo = -1;
    P->capacidade = capacidade;
    return P;
}

int vaziap(Pilha P) {
    return P->topo == -1;
}

void empilha(char item, Pilha P) {
    P->itens[++P->topo] = item;
}

char desempilha(Pilha P) {
    return P->itens[P->topo--];
}

char topo(Pilha P) {
    return P->itens[P->topo];
}

void destroip(Pilha *P) {
    free((*P)->itens);
    free(*P);
    *P = NULL;
}

int prio(char o) {
    switch (o) {
        case '(': return 0;
        case '+':
        case '-':  return 1;
        case '*':
        case '/': return 2;
    } 

    return -1; // operador inválido 
}

char *infixa_para_posfixa(char *infixa) {
    static char posfixa[256];
    Pilha P = pilha(256);
    int j = 0;

    for (int i = 0; infixa[i]; i++) {
        if (isalpha(infixa[i])) {
            posfixa[j++] = infixa[i];
        } else if (strchr("+-*/", infixa[i])) {
            posfixa[j++] = ' ';
            while (!vaziap(P) && prio(topo(P)) >= prio(infixa[i])) {
                posfixa[j++] = desempilha(P);
            }
            empilha(infixa[i], P);
        } else if (infixa[i] == '(') {
            empilha('(', P);
        } else if (infixa[i] == ')') {
            while (topo(P) != '(') {
                posfixa[j++] = desempilha(P);
            }
            desempilha(P);
        }
    }

    while (!vaziap(P)) {
        posfixa[j++] = desempilha(P);
    }

    posfixa[j] = '\0';
    destroip(&P);
    return posfixa;
}

int main() {
    char expressao_infixa[256];

    printf("Digite a expressao infixa com operandos representados por letras: ");
    scanf("%s", expressao_infixa);

    char *expressao_posfixa = infixa_para_posfixa(expressao_infixa);
    printf("Expressao posfixa: %s\n", expressao_posfixa);

    return 0;
}
