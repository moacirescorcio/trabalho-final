#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char stack[MAX_SIZE];
    int top;
} Pilha;

void inicializar(Pilha *s) {
    s->top = -1;
}

int esta_vazia(Pilha *s) {
    return s->top == -1;
}

int eh_operando(char c) {
    return (c == 'V' || c == 'F');
}

int precedencia(char c) {
    switch (c) {
        case '~':
            return 3;
        case '&':
            return 2;
        case '|':
            return 1;
        default:
            return 0;
    }
}

void empilhar(Pilha *s, char c) {
    if (s->top == MAX_SIZE - 1) {
        printf("Erro: Estouro da Pilha\n");
        exit(EXIT_FAILURE);
    }
    s->stack[++s->top] = c;
}

char desempilhar(Pilha *s) {
    if (esta_vazia(s)) {
        printf("Erro: Pilha Vazia\n");
        exit(EXIT_FAILURE);
    }
    return s->stack[s->top--];
}

void infix_para_posfixa(char *infixa, char *posfixa) {
    Pilha pilha_operadores;
    inicializar(&pilha_operadores);

    int i, j;
    for (i = 0, j = 0; infixa[i] != '\0'; ++i) {
        char token = infixa[i];

        if (eh_operando(token)) {
            posfixa[j++] = token;
        } else if (token == '(') {
            empilhar(&pilha_operadores, token);
        } else if (token == ')') {
            while (!esta_vazia(&pilha_operadores) && pilha_operadores.stack[pilha_operadores.top] != '(') {
                posfixa[j++] = desempilhar(&pilha_operadores);
            }
            desempilhar(&pilha_operadores);  // Descarta o '('
        } else {
            while (!esta_vazia(&pilha_operadores) && precedencia(pilha_operadores.stack[pilha_operadores.top]) >= precedencia(token)) {
                posfixa[j++] = desempilhar(&pilha_operadores);
            }
            empilhar(&pilha_operadores, token);
        }
    }

    while (!esta_vazia(&pilha_operadores)) {
        posfixa[j++] = desempilhar(&pilha_operadores);
    }

    posfixa[j] = '\0';  // Adiciona o terminador nulo à expressão posfixa
}

int main() {
    char infixa[MAX_SIZE], posfixa[MAX_SIZE];

    printf("Digite uma expressão lógica infixa: ");
    fgets(infixa, sizeof(infixa), stdin);

    infix_para_posfixa(infixa, posfixa);

    printf("Expressão Infixa: %s", infixa);
    printf("Expressão Posfixa: %s\n", posfixa);

    return 0;
}
