#include<stdio.h>
#include<stdlib.h>
#define maxtam 3

typedef int Apontador;

typedef struct 
{
    int consumo;
    int modelo;
}tipomoto;

typedef struct 
{
    tipomoto item[maxtam];
    Apontador primeiro;
    Apontador ultimo;
}tipolista;


void inicializar(tipolista *l){
l->primeiro = 0;
l->ultimo =0;
}

void inserir(tipolista *l){

    if (l->ultimo >= maxtam)
    {
        printf("lista cheia nao pode mais inserir\n");
        return;
    }
    else{

        tipomoto item;

        printf("digite o modelo da moto\n");
        scanf("%d",&item.modelo);

        printf("digite o consumo de 3 modelos de motos \n");
        scanf("%d",&item.consumo);
       

        l->item[l->ultimo] = item;
        l->ultimo++;

   

    }
    
}

void maiseconomico(tipolista *l){

    if (l->ultimo == l->primeiro)
    {
        printf("lista esta vazia\n");
        return;
    }
    else{
        int indice = l->primeiro;
        for (int i = l->primeiro + 1; i < l->ultimo; i++)
        {
            if (l->item[i].consumo < l->item[indice].consumo)
            {
                indice = i;
            }
            
        }
        printf("modelo de moto mais economica:%d\n",l->item[indice].modelo);
        printf("o consumo da moto mais economica:%d\n", l->item[indice].consumo);
    }
}

void consumo100(tipolista *l){

    if (l->ultimo == l->primeiro)
    {
        printf("lista vazia");
        return;
    }
    else{
        for (int i = l->primeiro; i < l->ultimo; i++)
        {
          float litros = 100.0 / l->item[i].consumo;
            printf("combustivel gasto em 100km :%d, %.2f\n",l->item[i].modelo, litros);
            
        }
      
    }
    

}


int main(){

tipolista lista;
inicializar(&lista);

int opcao;

do
{
    printf("1 para inserir\n");
    printf("2 para mais economico\n");
    printf(" 3 -consumo em 100 km \n");
    printf(" 0 sair\n");
    scanf("%d",&opcao);
printf("s\n");
 system("cls");
    switch (opcao)
    {
    case 1:
        inserir(&lista);
        break;
    
    case 2:
        maiseconomico(&lista);
    break;


    case 3:
        consumo100(&lista);
    break;
    default:
    printf("encerrando\n");
        break;
    }
    
} while (opcao != 0);



return 0;
}

