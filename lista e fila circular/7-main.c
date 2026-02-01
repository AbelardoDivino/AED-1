#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;
    int frente;
    int tras;
    int tamanho;
} Fila;

void inicializar(Fila *f, int tam) {
    f->dados = (int *) malloc(tam * sizeof(int));
    f->frente = 0;
    f->tras = 0;
    f->tamanho = tam;
}

int vazia(Fila *f) {
    return f->frente == f->tras;
}

void dobrarTamanho(Fila *f) {
    f->tamanho *= 2;
    f->dados = (int *) realloc(f->dados, f->tamanho * sizeof(int));
    printf("\nFila cheia! Tamanho dobrado para %d\n", f->tamanho);
}

void inserir(Fila *f, int x) {
    if (f->tras == f->tamanho) {
        dobrarTamanho(f);
    }
    f->dados[f->tras++] = x;
}

int remover(Fila *f) {
    return f->dados[f->frente++];
}

int main() {
    Fila f;
    int tamInicial, valor, opcao;

    printf("Digite o tamanho inicial da fila: ");
    scanf("%d", &tamInicial);

    inicializar(&f, tamInicial);

    do {
        printf("\nDigite um valor para inserir: ");
        scanf("%d", &valor);
        inserir(&f, valor);

        printf("Deseja inserir outro valor? (1-sim / 0-nao): ");
        scanf("%d", &opcao);
    } while (opcao == 1);

    printf("\nElementos da fila: ");
    while (!vazia(&f)) {
        printf("%d ", remover(&f));
    }

    free(f.dados);
    return 0;
}
