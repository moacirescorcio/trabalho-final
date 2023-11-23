#include <stdio.h>
#include <stdlib.h>

#define MAX_TAMANHO 100

// Definição da estrutura da pilha
typedef struct {
    char items[MAX_TAMANHO];
    int topo;
} Pilha;

// Função para inicializar a pilha
void inicializaPilha(Pilha *p) {
    p->topo = -1;
}

// Função para empilhar um item
void empilha(Pilha *p, char item) {
    if (p->topo == MAX_TAMANHO - 1) {
        printf("Erro: Pilha cheia\n");
        exit(1);
    }
    p->topo++;
    p->items[p->topo] = item;
}

// Função para desempilhar um item
char desempilha(Pilha *p) {
    if (p->topo == -1) {
        printf("Erro: Pilha vazia\n");
        exit(1);
    }
    char item = p->items[p->topo];
    p->topo--;
    return item;
}

// Função para verificar os delimitadores na expressão
int verificaDelimitadores(char expressao[]) {
    Pilha pilha;
    inicializaPilha(&pilha);

    // Loop pela expressão
    for (int i = 0; expressao[i] != '\0'; i++) {
        // Se for um delimitador de abertura, empilha na pilha
        if (expressao[i] == '(' || expressao[i] == '{' || expressao[i] == '[') {
            empilha(&pilha, expressao[i]);
        }
        // Se for um delimitador de fechamento
        else if (expressao[i] == ')' || expressao[i] == '}' || expressao[i] == ']') {
            // Verifica se a pilha está vazia ou se o delimitador de fechamento corresponde ao delimitador de abertura no topo da pilha
            if (pilha.topo == -1 || 
                (expressao[i] == ')' && pilha.items[pilha.topo] != '(') ||
                (expressao[i] == '}' && pilha.items[pilha.topo] != '{') ||
                (expressao[i] == ']' && pilha.items[pilha.topo] != '[')) {
                return 0; // Expressão incorreta
            }
            // Desempilha o delimitador de abertura correspondente
            desempilha(&pilha);
        }
    }

    // A expressão está correta se a pilha estiver vazia no final
    return pilha.topo == -1;
}

// Função principal
int main() {
    // Exemplos de expressões
    char expressao1[] = "((A+B) ou A+B(";
    char expressao2[] = "{)A+B( – C ou (A+B))}– (C + D";
    char expressao3[] = "{m +(x+5)+3}";
    char expressao4[] = "m +x+5+3}";

    // Verifica as expressões e imprime o resultado
    printf("%s\n", verificaDelimitadores(expressao1) ? "CORRETO" : "ERRO");
    printf("%s\n", verificaDelimitadores(expressao2) ? "CORRETO" : "ERRO");
    printf("%s\n", verificaDelimitadores(expressao3) ? "CORRETO" : "ERRO");
    printf("%s\n", verificaDelimitadores(expressao4) ? "CORRETO" : "ERRO");

    return 0;
}
