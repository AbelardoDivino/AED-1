#include<stdio.h>
#include<stdlib.h>

#define maxtam 10
typedef int Apontador;

typedef struct 
{
    int cod[maxtam];
    Apontador primeiro;
    Apontador ultimo;
} tipofila;

/* Inicializa a fila */
void inicializar(tipofila *f){
    f->primeiro = 0;
    f->ultimo = 0;
}

/* Verifica se a fila está vazia */
int vazia(tipofila *f){
    return (f->primeiro == f->ultimo);
}

/* Verifica se a fila está cheia */
int cheia(tipofila *f){
    return (f->ultimo == maxtam);
}

/* Insere na fila */
void inserir(tipofila *f, int x){
    if(cheia(f)){
        printf("Fila cheia!\n");
        return;
    }
    f->cod[f->ultimo] = x;
    f->ultimo++;
}

/* Remove da fila */
int remover(tipofila *f){
    if(vazia(f)){
        printf("Fila vazia!\n");
        return -1;
    }
    int x = f->cod[f->primeiro];
    f->primeiro++;
    return x;
}

/* Intercala duas filas em uma terceira */
void intercalar(tipofila *A, tipofila *B, tipofila *C){
    inicializar(C);

    /* Enquanto as duas filas tiverem elementos */
    while(!vazia(A) && !vazia(B)){
        inserir(C, remover(A));
        inserir(C, remover(B));
    }

    /* Se sobrar elementos em A */
    while(!vazia(A)){
        inserir(C, remover(A));
    }

    /* Se sobrar elementos em B */
    while(!vazia(B)){
        inserir(C, remover(B));
    }
}

/* Mostra os elementos da fila */
void mostrar(tipofila *f){
    int i;
    for(i = f->primeiro; i < f->ultimo; i++){
        printf("%d ", f->cod[i]);
    }
    printf("\n");
}

/* Programa principal */
int main(){
    tipofila A, B, C;

    inicializar(&A);
    inicializar(&B);

    /* Exemplo */
    inserir(&A, 1);
    inserir(&A, 3);
    inserir(&A, 5);
    inserir(&A, 7);

    inserir(&B, 2);
    inserir(&B, 4);
    inserir(&B, 6);
    inserir(&B, 8);

    printf("Fila A: ");
    mostrar(&A);

    printf("Fila B: ");
    mostrar(&B);

    intercalar(&A, &B, &C);

    printf("Fila intercalada C: ");
    mostrar(&C);

    return 0;
}
