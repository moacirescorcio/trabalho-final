#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    float *itens;
    int topo;
    int capacidade;
} PilhaStruct;

typedef PilhaStruct *Pilha;

Pilha pilha(int capacidade) {
    Pilha P = (Pilha)malloc(sizeof(PilhaStruct));
    P->itens = (float *)malloc(capacidade * sizeof(float));
    P->topo = -1;
    P->capacidade = capacidade;
    return P;
}

int vaziap(Pilha P) {
    return P->topo == -1;
}

void empilha(float item, Pilha P) {
    P->itens[++P->topo] = item;
}

float desempilha(Pilha P) {
    return P->itens[P->topo--];
}

float topo(Pilha P) {
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

char *posfixa(char *e){
    static char s[256];
    Pilha P = pilha(256);
    int j=0;
    for(int i=0; e[i]; i++)
        if (e[i]=='(') empilha('(', P);
        else if(isdigit(e[i]) || e[i]=='.') s[j++] = e[i];
        else if(strchr("+*-/",e[i])){
            s[j++]= ' ';
            while(!vaziap(P) && prio(topo(P))>=prio(e[i]))
                s[j++] = desempilha(P);
            empilha(e[i],P);
        }
        else if(e[i] == ')'){
            while(topo(P) !='(') s[j++] = desempilha(P);
            desempilha(P);
        }
    while(!vaziap(P)) s[j++] = desempilha(P);
    s[j] = '\0';
    destroip(&P);
    return s;
}

float valor(char *e){
    Pilha P = pilha(256);
    for(int i=0; e[i]; i++)
        if(isdigit(e[i]) || e[i] == '.'){
            empilha(atof(e + i), P);
            while (isdigit(e[i+1]) || e[i+1] == '.') i++;
        }
        else if(strchr("+*-/", e[i])){
            float y = desempilha(P);
            float x = desempilha(P);
            switch(e[i]){
                case '+': empilha(x+y, P); break;
                case '-': empilha(x-y, P); break;
                case '*': empilha(x*y, P); break;
                case '/': empilha(x/y, P); break;
            }
        }
    float z = desempilha(P);
    destroip(&P);
    return z;
}

int main() {
    char expressao[256];

    printf("Digite a expressao infixa com numeros reais: ");
    scanf("%s", expressao);

    char *posfixa_resultado = posfixa(expressao);
    printf("Expressao posfixa: %s\n", posfixa_resultado);

    float valor_resultado = valor(posfixa_resultado);
    printf("Valor da expressao: %.2f\n", valor_resultado);

    return 0;
}
