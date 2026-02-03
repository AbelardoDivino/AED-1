// maior menor media 

#include<stdio.h>
#include<stdlib.h>

#define maxtam 10
typedef int Apontador;

typedef struct 
{
    int idade[maxtam];
    Apontador topo;
}tipopilha;

void inicializar(tipopilha *p){
p->topo=-1;
}

void inserir(tipopilha *p, int i){

    if (p->topo ==  maxtam -1)
    {
        printf("pilha cheia\n");
        return;
    }
    else{
        p->topo++;
        p->idade[p->topo] = i;
    }
}

void maior(tipopilha *p){

    if (p->topo == -1)
    {
        printf("pilha vazia");
        return;
    }
    
    int maior = p->idade[0];

    
        for (int i = 1; i <= p->topo; i++)
        {
            if (p->idade[i] > maior)
            {
                maior = p->idade[i];
            }
            
        }
          printf("o maior idade e %d\n",maior);
    }
    



void menor(tipopilha *p){


      int menor = p->idade[0];

    if (p->topo == -1)
    {
        printf("pilha vazia");
        return;
    }
    else{
        for (int i = 0; i <= p->topo; i++)
        {
            if (p->idade[i] < menor)
            {
                menor = p->idade[i];
                printf("o maior idade e %d\n",menor);
                return;
            }
            
        }
        
    }
    
}

void media(tipopilha *p){

    float s = 0;
    float m = 0;
    int qnt = p->topo+ 1;

    if (p->topo == -1)
    {
        printf("pilha vazia\n");
        return;
    }
    else{
        for (int i = 0; i <= p->topo; i++)
        {
            s += p->idade[i];
        }
        m = s / qnt;
        printf("A media e  %.2f\n",m);
        
    }
    

}

int main(){

tipopilha pilha;
inicializar(&pilha);

int opcao,idade;
do
{
    printf("1 - para inserir\n");
    printf("2 - maior\n");
    printf("3 - menor\n");
    printf("4 - media\n");
    printf("0 - sair\n");
    scanf("%d",&opcao);
    switch (opcao)
    {
    case 1:
        printf("digite as idades para inserir\n");
        scanf("%d",&idade);
        inserir(&pilha,idade);
    break;
    
    case 2:
        maior(&pilha);
    break;

    case 3:
        menor(&pilha);
    break;

    case 4:
        media(&pilha);
    break;

    default:
    printf("Encerrando\n");
    break;
    }
} while (opcao != 0);



    return 0;
}

