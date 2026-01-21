// #include<stdio.h>
// #include<stdlib.h>

// #define maxtam 

#include <stdio.h>
#include <stdlib.h>

#define maxtam 20

typedef struct {
    int dados[maxtam];
    int frente;
    int tras;
} Fila;

void inicializar(Fila *f) {
    f->frente = 0;
    f->tras = 0;
}

int vazia(Fila *f) {
    return f->frente == f->tras;
}

void inserir(Fila *f, int x) {
    f->dados[f->tras++] = x;
}

int remover(Fila *f) {
    return f->dados[f->frente++];
}

void intercalar(Fila *f1, Fila *f2, Fila *f3) {
    while (!vazia(f1) || !vazia(f2)) {
        if (!vazia(f1))
            inserir(f3, remover(f1));
        if (!vazia(f2))
            inserir(f3, remover(f2));
    }
}

int main() {
    Fila f1, f2, f3;
    int n1, n2, i, valor;

    inicializar(&f1);
    inicializar(&f2);
    inicializar(&f3);

    printf("Quantidade de elementos da fila 1: ");
    scanf("%d", &n1);

    for (i = 0; i < n1; i++) {
        printf("Digite o %d valor da fila 1: ", i + 1);
        scanf("%d", &valor);
        inserir(&f1, valor);
    }

    printf("\nQuantidade de elementos da fila 2: ");
    scanf("%d", &n2);

    for (i = 0; i < n2; i++) {
        printf("Digite o %d valor da fila 2: ", i + 1);
        scanf("%d", &valor);
        inserir(&f2, valor);
    }

    intercalar(&f1, &f2, &f3);

    printf("\nFila intercalada: ");
    while (!vazia(&f3)) {
        printf("%d ", remover(&f3));
    }

    return 0;
}
