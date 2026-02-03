#include<stdio.h>
#include<stdlib.h>
#define maxtam 10
typedef int Apontador;
typedef struct {
    int *dados;      // vetor dinâmico
    int capacidade; // tamanho atual do vetor
    Apontador primeiro;   // índice do primeiro
    Apontador ultimo;     // índice do próximo espaço livre
    int total;      // quantidade de elementos
} Fila;


void inicializar(Fila *f, int capacidadeInicial){
    f->capacidade = capacidadeInicial;
    f->dados = (int*) malloc(sizeof(int) * capacidadeInicial);
    f->primeiro = 0;
    f->ultimo = 0;
    f->total = 0;
}

int vazia(Fila *f){
    return f->total == 0;
}

int cheia(Fila *f){
    return f->total == f->capacidade;
}

void redimensionar(Fila *f){
    int novaCapacidade = f->capacidade * 2;
    int *novoVetor = (int*) malloc(sizeof(int) * novaCapacidade);

    int i, j = f->primeiro;

    for(i = 0; i < f->total; i++){
        novoVetor[i] = f->dados[j];
        j = (j + 1) % f->capacidade;
    }

    free(f->dados);

    f->dados = novoVetor;
    f->capacidade = novaCapacidade;
    f->primeiro = 0;
    f->ultimo = f->total;
}

void inserir(Fila *f, int valor){
    if(cheia(f)){
        redimensionar(f);
    }

    f->dados[f->ultimo] = valor;
    f->ultimo = (f->ultimo + 1) % f->capacidade;
    f->total++;
}
int remover(Fila *f){
    if(vazia(f)){
        printf("Fila vazia!\n");
        return -1;
    }

    int valor = f->dados[f->primeiro];
    f->primeiro = (f->primeiro + 1) % f->capacidade;
    f->total--;

    return valor;
}

void mostrar(Fila *f){
    int i, j = f->primeiro;

    for(i = 0; i < f->total; i++){
        printf("%d ", f->dados[j]);
        j = (j + 1) % f->capacidade;
    }
    printf("\n");
}
int main(){
    Fila f;
    inicializar(&f, 4);

    int i;

    for(i = 1; i <= 15; i++){
        inserir(&f, i * 10);
        printf("Inseriu %d | Capacidade = %d\n", i*10, f.capacidade);
    }

    printf("\nFila: ");
    mostrar(&f);

    return 0;
}
