// procurar elemento

#include<stdio.h>
#include<stdlib.h>

#define maxtam 10
typedef int  Apontador;

typedef struct 
{
    int codigo[maxtam];
    Apontador topo;
}tipopilha;

void inicializar(tipopilha *p){
p->topo = -1;
}

void inserir(tipopilha *p, int c){

    if (p->topo  == maxtam -1)
    {
        printf("pilha cheia\n");
        return;
    }
    else{
        p->topo++;
        p->codigo[p->topo] = c;
    }
}

void procurar(tipopilha *p, int c){

    if (p->topo == -1)
    {
        printf("pilha vazia\n");
        return;
    }
    else{
        for (int i = 0; i < p->topo; i++)
        {
            if (p->codigo[i] == c)
            {
                printf("valor encontrado foi %d\n",p->codigo[i]);
            }
            else{
                printf("erro valor nao encontrado\n");
                return;
            }
        }
        
    }
}

int main(){

    tipopilha pilha;
    inicializar(&pilha);
    int opcao,c;

    do
    {   printf("1- enserir\n");
        printf("2 - procurar\n");
        printf("0 - sair\n");
        scanf("%d",&opcao);
        
        switch (opcao)
        {
        case 1:
            printf("digite os valores para serem inseridos\n");
            scanf("%d",&c);
            inserir(&pilha,c);
            break;
        

        case 2:
        printf("digite os valores para sereminseridos\n");
        scanf("%d",&c);
        procurar(&pilha,c);
        break;
        default:
        printf("encerrando\n");
            break;
        }

    } while (opcao != 0);
    

    return 0;
}
