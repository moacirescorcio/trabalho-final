#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool calcular_posfixa(char *posfixa) {
    Pilha operandos;
    inicializar(&operandos);

    int i;
    for (i = 0; posfixa[i] != '\0'; ++i) {
        char token = posfixa[i];

        if (token == 'V' || token == 'F') {
            // Se o token é um operando, empilhar seu valor lógico (V->true, F->false)
            empilhar(&operandos, token == 'V');
        } else if (token == '&' || token == '|') {
            // Se o token é um operador lógico, realizar a operação com os dois últimos operandos empilhados
            bool operand2 = desempilhar(&operandos);
            bool operand1 = desempilhar(&operandos);
            bool result;

            if (token == '&') {
                result = operand1 && operand2; // Operação lógica E
            } else {
                result = operand1 || operand2; // Operação lógica OU
            }

            // Empilhar o resultado de volta na pilha
            empilhar(&operandos, result);
        }
    }

    // O resultado final estará no topo da pilha
    return desempilhar(&operandos);
}

int main() {
    char posfixa[MAX_SIZE];

    printf("Digite uma expressão lógica posfixa: ");
    fgets(posfixa, sizeof(posfixa), stdin);

    bool resultado = calcular_posfixa(posfixa);

    printf("Resultado da Expressão Posfixa: %s é %s", posfixa, resultado ? "Verdadeiro" : "Falso");

    return 0;
}
