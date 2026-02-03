#include<stdio.h>
#include<stdlib.h>

#define maxtam 3

typedef int Apontador;


typedef struct 
{
    int cliente[maxtam];
    Apontador ultimo;
    Apontador primeiro;
}tipofila;


void inicializar(tipofila *f){
f->primeiro=0;
f->ultimo=0;
}

void inserir(tipofila *f, int n){

    if ((f->ultimo + 1) % maxtam == f->primeiro)
    {
        printf("fila cheia\n");
        return;
    }
    else{
        f->cliente[f->ultimo] = n;
        f->ultimo = (f->ultimo + 1) % maxtam;
    }

}

void remover(tipofila *f){

    if (f->ultimo  == f->primeiro)
    {
        printf("fila vaiza");
        return;
    }
    else{
        f->primeiro = (f->primeiro + 1) % maxtam;
    }

}

void proximo(tipofila *f){

    if (f->primeiro == f->ultimo)
    {
        printf("fila vazia\n");
    }
    else{
        printf(" o proximo sera: %d\n",f->cliente[f->primeiro ]);
    }
    

}
int main(){

    tipofila fila;
    inicializar(&fila);

int opcao,n;
    do
    {
        printf("1 enserir\n");
        printf("2 - remover\n");
        printf("3 - proximo\n");
        scanf("%d",&opcao);
        switch (opcao)
        {
        case 1:
            printf("digite os valores\n");
            scanf("%d",&n);
            inserir(&fila,n);
            break;

            case 2:
            remover(&fila);
            break;

            case 3:
            proximo(&fila);
            break;
        
        default:
            break;
        }
    } while (opcao != 0);
    

    return 0;
}