#include<stdio.h>
#include<stdlib.h>
#define maxtam 10
typedef int Apontador;

typedef struct 
{
    int codigo[maxtam];
    Apontador topo;
}tipopilha;

void inicializar(tipopilha *p){
p->topo=-1;
}

void inserir(tipopilha *p, int c){

    if (p->topo == maxtam -1)
    {
        printf("fila cheia\n");
        return;
    }
    else{
        p->topo++;
        p->codigo[p->topo] = c;
    }
}

void ordenar(tipopilha *p)
{
    tipopilha aux;
    inicializar(&aux);
    int x;

    while (p->topo != -1)
    {
        x = p->codigo[p->topo];
        p->topo--;

        while (aux.topo != -1 && aux.codigo[aux.topo] > x)
        {
            p->topo++;
            p->codigo[p->topo] = aux.codigo[aux.topo];
            aux.topo--;
        }

        aux.topo++;
        aux.codigo[aux.topo] = x;
    }

    while (aux.topo != -1)
    {
        x = aux.codigo[aux.topo];
        aux.topo--;
        p->topo++;
        p->codigo[p->topo] = x;
    }
}

void listar(tipopilha *p){

    if (p->topo == -1)
    {
        printf("pilha vazia\n");
        return;
    }
    else{
        for (int i = p->topo; i >= 0; i--)
        {
            printf("os valores em ordem crescente e:%d\n",p->codigo[i]);
        }
        
    }
    

}

int main(){
tipopilha pilha;
inicializar(&pilha);


int opcao,c;

do
{
    printf("1 - enserir\n");
    printf("2 - listar\n");
    printf("0 - sair\n");
    scanf("%d",&opcao);

    switch (opcao)
    {
    case 1:
    printf("digite o valor para enserir\n");
    scanf("%d",&c);
    inserir(&pilha,c);        
    ordenar(&pilha);
     break;
    
     case 2:
 listar(&pilha);
     break;

    default:
        break;
    }
} while (opcao != 0);

    return 0;

}

