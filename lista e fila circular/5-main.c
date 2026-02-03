#include<stdio.h>
#include<stdlib.h>
#define maxtam 10
typedef int Apontador;

typedef struct 
{
    int valor[maxtam];
    Apontador primeiro;
    Apontador ultimo;
}tipolista;

void inicializar(tipolista *l){
l->primeiro=0;
l->ultimo=0;
}

void inserir(tipolista *l, int v){

    if (l->ultimo >= maxtam)
    {
        printf("lista cheia \n");
        return;
    }
    else{
        l->valor[l->ultimo] = v;
        l->ultimo++;
    }
}

void maior(tipolista *l){

    int m = l->valor[l->primeiro];

    if (l->ultimo == l->primeiro)
    {
        printf("lista vazia\n");
        return;
    }
    else{
        for (int i = l->primeiro;  l->ultimo ; i++)
        {
          if (l->valor[i] > m)
          {
            m = l->valor[i];
          }
            
        }
        printf("o maior valor e: %d\n",m);
  }
    

}


void menor(tipolista *l){
         int m = l->valor[l->primeiro];

    if (l->ultimo == l->primeiro)
    {
        printf("lista vazia\n");
        return;
    }
    else{
        for (int i = l->primeiro;  i< l->ultimo ; i++)
        {
          if (l->valor[i] < m)
          {
            m = l->valor[i];
          }
            
        }
        printf("o menor valor e: %d\n",m);
  }

}

void media(tipolista *l){

    int s = 0;
    int m = 0;

    if (l->ultimo  == l->primeiro)
    {
        printf("lista vazia\n");
        return;
    }
    else{
         for (int i = l->primeiro; i < l->ultimo; i++)
    {
        s += l->valor[i];
        m = s / (l->ultimo - l->primeiro);
    }
    printf("a media e:%d\n", m);
    }
}

int main(){

    tipolista lista;
    inicializar(&lista);

    int opcao,n;

    do
    {
        printf(" 1 - para inserir\n");
        printf(" 2 - para maior\n");
        printf(" 3 - menor");
        printf(" 4 - media\n");
        printf(" 0 - sair\n");
        scanf(&opcao);
        switch (opcao)
        {
        case 1:
            printf("digite os valores \n");
            scanf("%d",&n);
            inserir(&lista,n);
    break;
    
    case 2:
            maior(&lista);
    break;

    case 3:
            menor(&lista);
    break;

    case 4:
            media(&lista);
    break;

        default:
        printf("encerrando\n");
            break;
        }
    } while (opcao != 0);
    

    return 0;
}