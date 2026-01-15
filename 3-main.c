#include<stdio.h>
#include<stdlib.h>

#define maxtam 10

typedef int Apontador;

typedef struct {
    int valor[maxtam];
    Apontador primeiro;
    Apontador ultimo;
} tipolista;

void inicializar(tipolista *l){
    l->primeiro = 0;
    l->ultimo = 0;
}

void inserir(tipolista *l, int v){
    int i;

    if (l->ultimo >= maxtam) {
        printf("Lista esta cheia\n");
        return;
    }

    i = l->primeiro;

    // encontra posição
    while (i < l->ultimo && l->valor[i] < v) {
        i++;
    }

    // desloca para a direita
    for (int j = l->ultimo; j > i; j--) {
        l->valor[j] = l->valor[j - 1];
    }

    l->valor[i] = v;
    l->ultimo++;
}

void imprimir(tipolista *l) {
    printf("\nLista ordenada: ");
    for (int i = l->primeiro; i < l->ultimo; i++) {
        printf("%d ", l->valor[i]);
    }
    printf("\n");
}

int main(){
    tipolista lista;
    int p, opcao;

    inicializar(&lista);

    do {

         printf("Digite 0 para sair ou 1 para continuar: ");
        scanf("%d", &opcao);

        printf("\nDigite um valor: ");
        scanf("%d", &p);

        inserir(&lista, p);
        imprimir(&lista);

       

    } while (opcao != 0);

    return 0;
}
