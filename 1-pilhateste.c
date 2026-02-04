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
        printf("pilha cheia\n");
        return;
    }
    else{
        p->topo++;
        p->codigo[p->topo] = c;
    }
    
}

void remover(tipopilha *p){

    if (p->topo == -1)
    {
        printf("vazia\n");
        return;
    }
    else{
            p->topo--;
    }
}

void maior(tipopilha *p){

    if (p->topo == -1)
    {
        printf("vazia\n");
        return;
    }
    int maior = p->codigo[p->topo];
        for (int i = 0; i < p->topo; i++)
        {
            if (p->codigo[i] > maior)
            {
                maior = p->codigo[i];
            }
                   
        }
        printf("o maior e : %d\n",maior);
    }

void menor(tipopilha *p){

    if (p->topo == -1)
    {
        printf("vazia\n");
        return;
    }

    int menor = p->codigo[p->topo];
    for (int i = 0; i <= p->topo; i++)
    {
        if (p->codigo[i] < menor)
        {
            menor = p->codigo[i];
        }
        
    }
    printf("o menor valor e: %d\n",menor);
}

void media(tipopilha *p){

    if (p->topo == -1)
    {
        printf("erro\n");
        return;
    }

    float m = 0, s = 0;
    float qnt = p->topo + 1;
     for (int i = 0; i <= p->topo; i++)
    {
        s += p->codigo[i];
        m = s / qnt;
    }
    printf(" a media e: %.2f\n",m);
}

void procurar(tipopilha *p , int c){

    if (p->topo == -1)
    {
        printf("erro\n");
        return;
    }
    else{
        for (int i = 0; i <=p->topo; i++)
        {
            if (p->codigo[i] == c)
            {
                printf("valor encontrado e: %d\n", c);
            }
            
        }
        
    }
    

}

void listar(tipopilha *p){

    if (p->topo == -1)
    {
        printf("erro\n");
        return;
    }
    else{
        for (int i = 0; i <= p->topo; i++)
        {
            printf("os codigos sao\n%d",p->codigo[i]);
        }
        
    }
    

}

int main(){

    tipopilha pilha;
    inicializar(&pilha);

    int opcao,c;

    do
    {
        printf("1 - inserir\n");
        printf("2 - remover\n");
        printf("3 - maior\n");
        printf("4 - menor\n");
        printf("5 - media\n");
        printf("6 - procurar\n");
        printf("7 - listar\n");
        printf("0 - sair\n");
        scanf("%d",&opcao);
        
        switch (opcao)
        {
        case 1:
            printf("digite os valores para inserir\n");
            scanf("%d",&c);
            inserir(&pilha,c);
        break;

        case 2:
            remover(&pilha);
        break;

        case 3:
            maior(&pilha);
        break;

        case 4:
            menor(&pilha);
        break;
        
        case 5:
            media(&pilha);
        break;

        case 6:
            printf("digite o valor para procuralo\n");
            scanf("%d",&c);
            procurar(&pilha,c);
        break;

        case 7:
            listar(&pilha);
        break;

        default:
        printf("Encerrando\n");
        break;
        }

    } while (opcao != 0);
    

    return 0;
}