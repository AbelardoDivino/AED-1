#include<stdio.h>
#include<stdlib.h>

#define maxtam 10

typedef  int Apontador;

typedef struct 
{
    int item;
}tipoitem;


typedef struct 
{
    tipoitem item[maxtam];
    Apontador primeiro;
    Apontador ultimo;
}tipolista;

void inicializar(tipolista *l){
    l->primeiro = 0;
    l->ultimo = 0;
}

void inserir(tipolista  *l, tipoitem item){

    if (l->ultimo == maxtam)
    {
        printf("lista cheia\n");
    }
    else{
        l->item[l->ultimo] = item;
        l->ultimo++;
    }

}

void maior(tipolista *l)
{

    float maior = l->item[l->primeiro].item;

    if (l->primeiro == l->ultimo)
    {
        printf("lista vazia\n");
    }
    else{
        for (int i = l->primeiro; i < l->ultimo; i++)
        {
            if (l->item[i].item > maior)
            {
                maior = l->item[i].item;
            }
            
        }
        
         printf("o maior valor e: %.2f\n", maior);
    }
    

}

void menor(tipolista *l){

    if (l->primeiro == l->ultimo)
    {
        printf("lista esta vazia\n");
    }
    else{
        float menor = l->item[l->primeiro].item;

        for (int i = l->primeiro; i < l->ultimo; i++)
        {
            if (l->item[i].item < menor)
            {
                menor = l->item[i].item;
        
            }
            
        }
          printf("o menor valor e: %.2f\n", menor);
    }
    

}

void media(tipolista * l){

    float m = 0;
    int s = 0;

    if (l->primeiro == l->ultimo)
    {
        printf("lista vazia\n");
    }
    else{
        for (int i = l->primeiro; i < l->ultimo; i++)
        {
            s += l->item[i].item;
            m = s / l->ultimo;
        }
        
        printf(" A media e: %.2f\n",m);

    }
    

}

  int main() {
    tipolista lista;
    tipoitem item;
    int n;

    inicializar(&lista);

    printf("Digite os 10 valores inteiros:\n");

    for (int i = 0; i < maxtam; i++) {
        scanf("%d", &n);
        item.item = n;
        inserir(&lista, item);
    }


    maior(&lista);

    menor(&lista);

    media(&lista);

}