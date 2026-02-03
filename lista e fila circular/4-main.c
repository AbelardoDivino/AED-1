#include<stdio.h>
#include<stdlib.h>

#define maxtam 10

typedef int Apontador;

typedef struct 
{
    int nota[maxtam];
    Apontador primeiro;
    Apontador ultimo;
}tipolista;

void inicializar(tipolista *l){
l->primeiro=0;
l->ultimo=0;
}

void inserir(tipolista *l, int n){

    if (l->ultimo >= maxtam)
    {
        printf("lista cheia \n");
        return;
    }
    else{
        l->nota[l->ultimo] = n;
        l->ultimo++;
    }
}

void remover(tipolista *l){

    if (l->ultimo == l->primeiro)
    {
        printf("lista vazia\n");
        return;
    }
    else{
        for (int i = l->primeiro; i < l->ultimo; i++)
        {
            l->nota[i] = l->nota[i + 1]; 
        }
        
            l->ultimo--;
    }
    
    // else{
    //     l->nota[l->ultimo] = n;
    //     l->ultimo--;
    // }

}

void media(tipolista *l){

    int s = 0;
    float m = 0;

    if (l->ultimo == l->primeiro)
    {
        printf("erro lista vazia\n");
        return;
    }
    

    for (int i = l->primeiro; i < l->ultimo; i++)
    {
        s += l->nota[i];
        m = (float) s / (l->ultimo - l->primeiro);
    }
    printf(" a media e: %.2f\n",m);

}
void maior(tipolista *l){

    int m = 0;

    if (l->ultimo == l->primeiro)
    {
        printf("lista vazia\n");
        return;
    }
    else{
        for (int i = l->primeiro; i < l->ultimo; i++)
        {
            if (l->nota[i] > m )
            {
                m  = l->nota[i];
            }
            
        }
        printf("A maior nota e: %d\n",m);
    }
    

}

void menor(tipolista *l){

    int mneo;

    if (l->ultimo == l->primeiro)
    {
        printf("lista vazia\n");
        return;
    }
    else{
        for (int i = l->primeiro; i < l->ultimo; i++)
        {
            if (l->nota[i] < mneo)
            {
                mneo = l->nota[i];
            }
            
        }
        printf(" o menor valor e: %d\n",mneo);
    }

}

int main(){

    tipolista lista;
    inicializar(&lista);

    int opcao,n;

    do
    {
        printf("1 para inseirir\n");
        printf(" 2 - remover\n");
        printf(" 3 - media\n");
        printf(" 4 - maior valor\n");
        printf(" 5 - menor nota\n");
        printf("0 - sair\n");
        scanf("%d",&opcao);
        switch (opcao)
        {
        case 1:
            printf(" digite 10 valores\n");
            scanf("%d",&n);
            inserir(&lista,n);
        break;

        case 2:
            printf("digite um valor para ");

            remover(&lista);
        break;

        case 3:
            media(&lista);
        break;

        case 4:
            maior(&lista);
        break;

        case 5:
            menor(&lista);
        break;
        
        default:
        printf("Encerrando\n");
        break;
        }
    } while (opcao != 0);
    

    return 0;
}