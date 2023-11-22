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
        case '/': return 2;
    } 

    return -1; // operador inválido 
}

char *posfixa(char *e) {
    static char s[256];
    int j = 0;
    Pilha P = pilha(256);
    for (int i = 0; e[i]; i++)
        if (e[i] == '(') empilha('(', P);
        else if (isdigit(e[i])) s[j++] = e[i];
        else if (strchr("+-/*", e[i])) {
            while (!vaziap(P) && prio(topo(P)) >= prio(e[i]))
                s[j++] = desempilha(P);
            empilha(e[i], P);
        }
        else if (e[i] == ')') {
            while (topo(P) != '(')
                s[j++] = desempilha(P);
            desempilha(P);
        }
    while (!vaziap(P))
        s[j++] = desempilha(P);
    s[j] = '\0';
    destroip(&P);
    return s;
}

int valor(char *e) {
    Pilha P = pilha(256);
    for (int i = 0; e[i]; i++)
        if (isdigit(e[i]))
            empilha(e[i] - '0', P);
        else {
            int y = desempilha(P);
            int x = desempilha(P);
            switch (e[i]) {
                case '+': empilha(x + y, P); break;
                case '-': empilha(x - y, P); break;
                case '*': empilha(x * y, P); break;
                case '/': empilha(x / y, P); break;
            }
        }
    int z = desempilha(P);
    destroip(&P);
    return z;
}

int main() {
    char expressao[256];

    printf("Digite a expressao infixa com inteiros de um digito: ");
    scanf("%s", expressao);

    char *posfixa_resultado = posfixa(expressao);
    printf("Expressao posfixa: %s\n", posfixa_resultado);

    int valor_resultado = valor(posfixa_resultado);
    printf("Valor da expressao: %d\n", valor_resultado);

    return 0;
}
