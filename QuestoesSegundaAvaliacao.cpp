#include <iostream>

#include "pilha_Incompleta3.cpp"

// Questão 2.1
/*
    int main() {
        Pilha P = pilha(3);

        empilha(1, P);
        empilha(2, P);
        
        printf("%d\n", desempilha(P));
        printf("%d\n", desempilha(P));
        printf("%d\n", desempilha(P));

        return 0;
    }
*/

//Questão 2.2
/*
int main() {
        Pilha P = pilha(100);
        empilha(8, P);

    while (topo(P) > 0) {
        empilha(topo(P) / 2, P);
    }

    while (!vaziap(P)) {
       printf("%f ", (float)desempilha(P));
    }
    }

*/

//Questão 2.3
/*
Usando uma pilha, crie um programa para inverter a ordem das letras nas palavras de uma frase digitada pelo usuario. 
POr exemplo, se for digitada a frase " apenas um teste" , o programa devera exibir " sanepa mu etset"
string inverterPalavra(string palavra){

}
    typedef struct pilha {
        int tam= 15;  
        char texto[15];
        int topo =-1 ;
    } Pilha;

    // Função para empilhar uma string
    void empilhar(Pilha &p, const char *str) {
        int i = 0;
        while (str[i] != '\0') {
            if (p.topo < p.tam - 1) {
                p.topo++;
                p.texto[p.topo] = str[i];
                i++;
            } else {
                cout << "Pilha cheia" << endl;
                return;
            }
        }
    }

    // Função para desempilhar um caractere
    char desempilhar(Pilha &p) {
        if (p.topo >= 0) {// verifica se a pilha esta vazia
            char c = p.texto[p.topo];
            p.topo--;
            return c;
        } else {
            cout << "Pilha vazia" << endl;
            return '\0';  // Caractere nulo para indicar erro
        }
    }

    int main() {
        Pilha minhaPilha;


        // Teste empilhando
        empilhar(minhaPilha, "Apenas outro teste");
        

        // Teste desempilhando e exibindo
        cout << "Texto desempilhado: ";
        while (minhaPilha.topo >= 0) {
            cout << desempilhar(minhaPilha);
        }

        cout << endl;

        return 0;
    }

*/

//Questão 2.4
/*
Criar um programa que usa dus pilhas A e B para ordenar um sequencia
de n numeros reais dados pelo usuario. A ideia é organizar A 
de modo que nenhum item seja empilhado sobre outro menor
a pilha B é apenas para espaço de manobra , depois descarrege 
e exiba a pilha A

#include <iostream>
using namespace std;

const int TAM_MAX = 100;

// Definição da estrutura da pilha
struct Pilha {
    float itens[TAM_MAX];
    int topo;
};

// Função para inicializar uma pilha
void inicializar(Pilha &p) {
    p.topo = -1;
}

// Função para empilhar um elemento em uma pilha
void empilhar(Pilha &p, float valor) {
    if (p.topo < TAM_MAX - 1) {
        p.topo++;
        p.itens[p.topo] = valor;
    } else {
        cout << "Erro: pilha cheia." << endl;
    }
}

// Função para desempilhar um elemento de uma pilha
float desempilhar(Pilha &p) {
    if (p.topo >= 0) {
        float valor = p.itens[p.topo];
        p.topo--;
        return valor;
    } else {
        cout << "Erro: pilha vazia." << endl;
        return 0.0;  // Valor padrão para indicar erro
    }
}

// Função para exibir uma pilha
void exibir(Pilha &p) {
    for (int i = p.topo; i >= 0; i--) {
        cout << p.itens[i] << " ";
    }
    cout << endl;
}

// Função para ordenar uma sequência de números usando duas pilhas
void ordenarSequencia() {
    Pilha A, B;
    inicializar(A);
    inicializar(B);

    int n;
    cout << "Digite a quantidade de numeros a serem ordenados: ";
    cin >> n;

    cout << "Digite os numeros separados por espaco: ";
    for (int i = 0; i < n; i++) {
        float numero;
        cin >> numero;
        empilhar(A, numero);
    }

    // Ordenação usando duas pilhas
    while (A.topo >= 0) {
        float temp = desempilhar(A);

        // Transferir itens maiores de A para B
        while (B.topo >= 0 && B.itens[B.topo] > temp) {
            empilhar(A, desempilhar(B));
        }

        // Empilhar o item temporário em B
        empilhar(B, temp);
    }

    // Descarregar B para A
    while (B.topo >= 0) {
        empilhar(A, desempilhar(B));
    }

    // Exibir pilha ordenada
    cout << "Pilha ordenada: ";
    exibir(A);
}

int main() {
    ordenarSequencia();
    return 0;
}
*/

//Questão 2.5
/*
Usando pilha, crie uma função para erificar se uma expressão composta por
chaves, colchetes e parentese, reprsentada por uma cadeia, esta ou não
balanceada. Por exemplo, [{()()}]

*/

//Questão 9.5
/*
Crie a função recursiva soma(L), que devolve a soma dos itens da
lista L. Ex:

   #include <iostream>
using namespace std;

//Definindo da lista
typedef struct lista{
    float num;
    lista*prox;
}Lista;

//Inserindo um elemento no inicio
Lista *inserirInicio( Lista *inicio, float valor){
    Lista *novo = new Lista{valor, nullptr};
    novo->prox = inicio;
    return novo;
}

// soma cada valor da lista com seu sucessor
float soma(lista *p){
    //se o ponteiro da lista fro nulo
    if (p == nullptr){
        return 0;
    }else {
        return p->num + soma(p->prox);
    }
}

// cria a lista a partir do tamanho
Lista *criarLista(int tam){
    //inicio inicialmente possui o valor nulo
    Lista *inicio = nullptr;

    for (int i = 0; i<tam;i++){
    
        float valor;
        cout << " digite um valor "<< i+1 << ": ";
        cin >> valor;
        inicio = inserirInicio( inicio, valor);
    }
    return inicio;
}

int main(){
    // define o tamanho da lista
    int tamanho;
    //solicita do usuario o tamanho da lista e atribui a tamnho
    cout<< " Informe o tamnho da lista"<<endl;
    cin >> tamanho;
    
    // Cria a lista com base no tamanho
    Lista* novaLista = criarLista(tamanho);
    
    cout << "Resultado: " << soma(novaLista) << endl;
    return 0;
}

*/

//Questão 9.6
/*
Crie a função recursiva Substitui(x,y,L), que substitue
toda ocorrencia do item x pelo item y na Lista L. Por exemplo 
se, L aponta a lista [b,o,b,o] apos a chamada deverá [b,a,b,a]

     //Definindo da lista
    typedef struct lista{
        char item;
        lista*prox;
    }Lista;

    // Criar um novo Nó (Nova struct)
    Lista *No (char item){
        Lista *novo = new Lista;
        novo->item = item;
        novo->prox = nullptr;
        return novo;
    }

    // Cria uma nova struct e insere no incio da lista
    Lista* inserirInicio(Lista* inicio, char item) {
        // cria uma noa struct
        Lista* novo = No(item);
        novo->prox = inicio;
        return novo;
    }

    //  Função para inserir um item no final
    Lista *inserirFinal (Lista *inicio, char item){
        Lista *novo = No(item);

        if(inicio == nullptr){
            // Se a lista estiver vazia, insere no inicio
            inicio = novo;
        } else {
            Lista *atual = inicio;
            while (atual->prox != nullptr){
                atual = atual ->prox;
            }
            atual->prox = novo;
        }
        return inicio;
    }

    // cria a lista dinamicamente a partir do tamanho
    Lista *criarLista(int tam){
        //inicio inicialmente possui o valor nulo
        Lista *inicio = nullptr;

        for (int i = 0; i<tam;i++){
            char item;
            cout << " digite um item "<< i+1 << ": ";
            cin >> item;
            inicio = inserirFinal(inicio, item);
        }
        return inicio;
    }

    void mostrarLista(lista *p){
        Lista *atual = p;
        while (atual!=nullptr){
            cout << atual->item<< " ";
            atual = atual -> prox;
        }
        {
            cout<< endl;
        }
        
    }

    // Função para substituir todos os itens 'x' por 'y' na lista
    void substituir(char x, char y, Lista* p) {
        Lista* atual = p;

        while (atual != nullptr) {
            if (atual->item == x) {
                atual->item = y;
            }
            atual = atual->prox;
        }
    }

    int main()
    {
        // define o tamanho da lista
        int tamanho;
        // solicita do usuario o tamanho da lista e atribui a tamnho
        cout << " Informe o tamnho da lista: ";
        cin >> tamanho;

        // Cria a lista com base no tamanho
        Lista *novaLista = criarLista(tamanho);
        mostrarLista(novaLista);
        char x,y;
        cout << "Qual letra deseja substituir ";
        cin >> x;
        cout << " Informa a letra de substituicao ";
        cin >> y;

        substituir(x, y, novaLista);

        cout << "Resultado: ";
        mostrarLista(novaLista);

        return 0;
}

*/

//Questão 9.7
/*
Crie a função recursiva igual(A,B), que erifica se a lista A, é igual a lista B.
Por exemplo, se I aponta para a lista [1,2,3], J aponta [1,2,3] e K aponta [1,3,2]
as chamadas igaual(I,J) e igual (I,K) devem devolver 1 e 0 respectivamente

#include <iostream>
using namespace std;

// Definindo da lista
typedef struct lista{
    int item;
    lista *prox;
} Lista;

// Criar um novo Nó (Nova struct)
Lista *No(int item)
{
    Lista *novo = new Lista;
    novo->item = item;
    novo->prox = nullptr;
    return novo;
}

// Cria uma nova struct e insere no incio da lista
Lista *inserirInicio(Lista *inicio, int item)
{
    // cria uma noa struct
    Lista *novo = No(item);
    novo->prox = inicio;
    return novo;
}

//  Função para inserir um item no final
Lista *inserirFinal(Lista *inicio, int item)
{
    Lista *novo = No(item);

    if (inicio == nullptr)
    {
        // Se a lista estiver vazia, insere no inicio
        inicio = novo;
    }
    else
    {
        Lista *atual = inicio;
        while (atual->prox != nullptr)
        {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
    return inicio;
}

// cria a lista dinamicamente a partir do tamanho
Lista *criarLista(int tam)
{
    // inicio inicialmente possui o valor nulo
    Lista *inicio = nullptr;

    for (int i = 0; i < tam; i++)
    {
        int item;
        cout << " digite um item " << i + 1 << ": ";
        cin >> item;
        inicio = inserirFinal(inicio, item);
    }
    return inicio;
}

void mostrarLista(lista *p)
{
    Lista *atual = p;
    while (atual != nullptr)
    {
        cout << atual->item << " ";
        atual = atual->prox;
    }
    {
        cout << endl;
    }
}

// Função para substituir todos os itens 'x' por 'y' na lista
void substituir(int x, int y, Lista *p)
{
    Lista *atual = p;

    while (atual != nullptr)
    {
        if (atual->item == x)
        {
            atual->item = y;
        }
        atual = atual->prox;
    }
}
// Função de verificar igualdade entre elementos de duas listas
int igual(Lista* A, Lista* B) {
    while (A != nullptr && B != nullptr) {
        if (A->item != B->item) {
            return 0;  // Se um elemento não corresponder, as listas não são iguais
        }
        A = A->prox;
        B = B->prox;
    }

    // Se ambas as listas chegarem ao final simultaneamente, elas são iguais
    return (A == nullptr && B == nullptr);
}

int main()
{
    // define o tamanho da lista
    int tamanho;
    // solicita do usuario o tamanho da lista e atribui a tamnho
    cout << " Informe o tamnho das listas: ";
    cin >> tamanho;

    // Cria a lista com base no tamanho
    Lista *listaA = nullptr;
    for (int i = 0; i < tamanho; i++)
    {
        int item;
        cout << " Digite um item " << i + 1 << ": ";
        cin >> item;
        listaA = inserirFinal(listaA, item);
    }

    // Mostra a lista A
    cout << "Lista A: ";
    mostrarLista(listaA);

    // Cria a lista B (por exemplo)
    Lista *listaB = nullptr;
    for (int i = 0; i < tamanho; i++) {
        int item;
        cout << " Digite um item para a lista B " << i + 1 << ": ";
        cin >> item;
        listaB = inserirFinal(listaB, item);
    }

    // Mostra a lista B
    cout << "Lista B: ";
    mostrarLista(listaB);

    // Verifica se as listas A e B são iguais
    if (igual(listaA, listaB))     {
        cout << "As listas A e B sao iguais." << endl;
    } else  {
        cout << "As listas A e B nao sao iguais." << endl;
    }

    return 0;
}
*/

//Questão 9.8
/*
Crie uma função enesimo(n,L), que devolva o n-enesimo item da lista L,
Ex: L apontando {a,b,c,d}, a chamada enesimo(3,L) deve devolver o item c
// Definindo a estrutura da lista
typedef struct lista {
    char item;
    lista *prox;
} Lista;

// Criar um novo Nó (Nova struct)
Lista *No(char item) {
    Lista *novo = new Lista;
    novo->item = item;
    novo->prox = nullptr;
    return novo;
}

// Função para inserir um item no final
Lista *inserirFinal(Lista *inicio, char item) {
    Lista *novo = No(item);

    if (inicio == nullptr) {
        // Se a lista estiver vazia, insere no inicio
        inicio = novo;
    } else {
        Lista *atual = inicio;
        while (atual->prox != nullptr) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
    return inicio;
}

// Função para mostrar a lista
void mostrarLista(Lista *p) {
    Lista *atual = p;
    while (atual != nullptr) {
        cout << atual->item << " ";
        atual = atual->prox;
    }
    cout << endl;
}

// Função para substituir todos os itens 'x' por 'y' na lista
void substituir(char x, char y, Lista *p) {
    Lista *atual = p;

    while (atual != nullptr) {
        if (atual->item == x) {
            atual->item = y;
        }
        atual = atual->prox;
    }
}

// Função de verificar igualdade entre elementos de duas listas
int igual(Lista* A, Lista* B) {
    while (A != nullptr && B != nullptr) {
        if (A->item != B->item) {
            return 0;  // Se um elemento não corresponder, as listas não são iguais
        }
        A = A->prox;
        B = B->prox;
    }

    // Se ambas as listas chegarem ao final simultaneamente, elas são iguais
    return (A == nullptr && B == nullptr);
}

// Função para retornar o enésimo elemento da lista
char enesimo(int n, Lista *p) {
    int index = n-1;

    for (int i = 0; i < index; i++) {
        if (p == nullptr) {
            // Se a lista não tiver n elementos, ocorreu um erro
            cout << "Erro: Lista não tem " << n << " elementos." << endl;
            return '\0';  // Valor de erro (caractere nulo)
        }
        p = p->prox;
    }

    if (p != nullptr) {
        return p->item;
    } else {
        // Se chegou ao final da lista, ocorreu um erro
        cout << "Erro: Lista não tem " << n << " elementos." << endl;
        return '\0';  // Valor de erro (caractere nulo)
    }
}

int main() {
    // define o tamanho da lista
    int tamanho;
    // solicita do usuario o tamanho da lista e atribui a tamanho
    cout << " Informe o tamanho das listas: ";
    cin >> tamanho;

    // Cria a lista com base no tamanho
    Lista *listaA = nullptr;
    for (int i = 0; i < tamanho; i++) {
        char item;
        cout << " Digite um item " << i + 1 << ": ";
        cin >> item;
        listaA = inserirFinal(listaA, item);
    }

    // Mostra a lista A
    cout << "Lista A: ";
    mostrarLista(listaA);

    int x;
    cout << "Informe o termo procurado: ";
    cin >> x;

    char resultado = enesimo(x, listaA);
    if (resultado != '\0') {
        cout << "Resultado: " << resultado << endl;
    }

    return 0;
}


*/


