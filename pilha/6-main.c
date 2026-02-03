#include<stdio.h>
#include<stdlib.h>
#define maxtam 12
typedef int Apontador;

typedef struct 
{
    int elemento[maxtam];
    Apontador topo;
}tipopilha;

void inicializar(tipopilha *p){
p->topo=-1;
}

void inserir(tipopilha *p, tipopilha *p1, tipopilha *p2, int e){

    if (p->topo == maxtam - 1)
    {
        printf("pilha cheia\n");
        return;
    }
    p->topo++;
    p->elemento[p->topo] = e;

    if (e % 2 == 0)
    {
        if (p1->topo == maxtam -1)
        {
            printf("pilha esta cheia\n");
            return;
        }
        
            p->topo++;
            p->elemento[p->topo] = e;
    }
    else{
        if (p2->topo == maxtam -1)
        {
            printf("pilha esta cheia\n");
            return;
        }
        
            p->topo++;
            p->elemento[p->topo] = e;
    }


}

int main(){

    tipopilha pilha,p1,p2;
    inicializar(&pilha);

    int e,opcao;
   
    do
    {
        printf("1 - enserir\n");
        printf("0 -  sair\n");
        scanf("%d",&opcao);

        switch (opcao)
        {
        case 1:
    printf("digite o valor para ser onserido\n");
    scanf("%d",&e);
    inserir(&pilha,&p1,&p2,e);
        break;
        
        default:
        printf("encerrando\n");
            break;
        }
    } while (opcao != 0);
    

    return 0;
}
