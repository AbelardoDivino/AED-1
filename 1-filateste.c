#include<stdio.h>
#include<stdlib.h>
#define maxtam 10
typedef int Apontador;

typedef struct 
{
    int cod[maxtam];
    Apontador primeiro;
    Apontador ultimo;
}tipofila;


void inicializar(tipofila *f){
f->primeiro=0;
f->ultimo=0;
}

void inserir(tipofila *f, int c){

    if ((f->ultimo +1) % maxtam == f->primeiro)
    {
        printf("fila cheia\n");
        return;
    }
    else{
        f->cod[f->ultimo] = c;
        f->ultimo = (f->ultimo + 1) % maxtam;
    }

}

void remover(tipofila *f){

    if (f->ultimo == f->primeiro)
    {
        printf("vazia\n");
        return;
    }
    else{
        f->primeiro = (f->primeiro +1) % maxtam;
    }

}

void maior(tipofila *f){

    if (f->ultimo == f->primeiro)
    {
        printf("vazia\n");
        return;
    }
    int maior = f->cod[f->primeiro];
        for (int i = f->primeiro + 1; i < f->ultimo; i++)
        {
            if (f->cod[i] > maior)
            {
                maior = f->cod[i];
            }
            
        }
        printf(" o maior e: %d\n",maior);
}

void menor(tipofila *f){

    if (f->ultimo == f->primeiro)
    {
        printf("erro\n");
        return;
    }
    
    int menor = f->cod[f->primeiro];
    for (int i = f->primeiro; i < f->ultimo; i++)
    {
        if (f->cod[i < menor])
        {
            menor = f->cod[i];
        }
        
    }
    printf("o valor menor e: %d\n",menor);

}

void media(tipofila *f){

    if (f->ultimo == f->primeiro)
    {
        printf("erro\n");
        return;
    }
    float s=0,m=0;
    int qnt = (f->ultimo - f->primeiro);
    
        for (int i = f->primeiro; i < f->ultimo ; i++)
        {
            s += f->cod[i];
            m = s / qnt;            
        }
        
        printf("A media e: %.2f\n",m);
    }
    



void procurar(tipofila *f , int c){

    if (f->ultimo == f->primeiro)
    {
        printf("fila vazia\\n");
        return;
    }
    else{
        for (int i = f->primeiro; i < f->ultimo; i++)
        {
            if (f->cod[i] == c)
            {
                printf(" o valor encontrado e: %d\n",c);
                return;
            }
            
        }
        
    }
    

}

void listar(tipofila *f){

    if (f->ultimo == f->primeiro)
    {
        printf("erro\n");
        return;
    }
    else{
        for (int i = f->primeiro; i < f->ultimo; i++)
        {
            printf("os codigos sao:  %d\n",f->cod[i]);
        }
        
    }
    

}

int main(){

    tipofila fila;
    inicializar(&fila);

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
            printf(" insira os valores\n");
            scanf("%d",&c);
            inserir(&fila, c);
        break;

        case 2:
            remover(&fila);
        break;

        case 3:
            maior(&fila);
        break;

        case 4:
            menor(&fila);
        break;

        case 5:
            media(&fila);
        break;

        case 6:
            printf("digite o valor para procurar\n");
            scanf("%d",&c);
            procurar(&fila,c);
        break;

        case 7:
            listar(&fila);
        break;
        
        default:
        printf("encerrando\n");
        break;
        }
    } while (opcao != 0);
    

    return 0;
}