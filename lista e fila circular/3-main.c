#include<stdio.h>
#include<stdlib.h>

#define maxtam 10
typedef int Apontador;

typedef struct 
{
int codigo[maxtam];
Apontador ultimo;
}tipolista;

void inicializar(tipolista *l){
l->ultimo=0;
}

void inserir(tipolista *l, int c){



    if (l->ultimo >= maxtam)
    {
        printf("fila cheia\n");
        return;
    }

          int posicao = 0;
    
        while (posicao < l->ultimo && l->codigo[posicao] < c)
        {
            posicao++;
            //encontrar a posiçao correta
        }
        

        for (int i = l->ultimo - 1; i >= posicao; i--)
        {
            l->codigo[i + 1] = l->codigo[i]; // deslocar para a direite
        }
        l->codigo[posicao] = c;
        l->ultimo++;
    }
  


void listar(tipolista *l){

    if (l->ultimo == 0)
    {
        printf("vazia\n");
        return;
    }
    
else{
    
    for (int i = 0; i < l->ultimo; i++)
    {
        printf(":%d\n",l->codigo[i]);
          if (i < l->ultimo - 1)
            printf(" ,"); 
    }
    
}

}

int main(){

    tipolista lista;

    inicializar(&lista);


    int c,opcao;
 


    do
    {
        printf("1 para enserir\n");
        printf("0 - sair\n");
        scanf("%d",&opcao);
        switch (opcao)
        {
        case 1:
            printf("enserir os codigos\n");
            scanf("%d",&c);
            inserir(&lista,c);

            listar(&lista);


            break;
        
        default:
            break;
        }
        
    } while (opcao != 0);
    

    return 0;
}