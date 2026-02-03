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

void partir2(tipopilha *p,tipopilha *p1, tipopilha *p2, int e){

 

    if (p->topo == -1)
    {
        printf("pilha vazia\n");
        return;
    }

    if (e % 2 == 0)
    {
     if (p1->topo == -1)
     {
        printf("pilha vazia\n");
        return;
     }
     p->topo++;
     p->codigo[p->topo] = e;
     
    }
    
    else{
       if (p2->topo == -1)
       {
           printf("pilha vazia\n");
        return;
       }
           p->topo++;
     p->codigo[p->topo] = e;
       
    }
    

}

void listar(tipopilha *p){

    if (p->topo == -1)
    {
        printf("erro\n");
        return;
    }
    else{
        for (int i = 0; i >= p->topo; i--)
        {
            printf("os valores sao:%d\n",p->codigo[i]);
            return;
        }
        
    }

}



int main(){

tipopilha pilha,p1,p2;
inicializar(&pilha);
inicializar(&p1);
inicializar(&p2);

int c,opcao;

do
{
    printf("1 - enserir\n");
    printf(" 2 - listar\n");
    printf("0 - sair\n");
    scanf("%d",&opcao);


switch (opcao)
{
case 1:
printf("digite os valores para partir a pilha\n");
scanf("%d",&c);
inserir(&pilha,c);
break;

case 2:
    
listar(&p1);
listar(&p2);
break;

default:
printf("encerrando\n");
    break;
}
    
} while (opcao != 0);


    return 0;

}

// void partirPilhaAleatoria(tipopilha *p, tipopilha *p1, tipopilha *p2)
// {
//     int e;

//     srand(time(NULL));  // inicializa o gerador aleatório

//     // tem que importar o time.h
    
//     while (p->topo != -1)
//     {
//         // POP da pilha original
//         e = p->elemento[p->topo];
//         p->topo--;

//         // 0 ou 1
//         int r = rand() % 2;

//         if (r == 0) {
//             // vai para p1
//             p1->topo++;
//             p1->elemento[p1->topo] = e;
//         } else {
//             // vai para p2
//             p2->topo++;
//             p2->elemento[p2->topo] = e;
//         }
//     }
// }
