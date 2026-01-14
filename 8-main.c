#include<stdio.h>
#include<stdlib.h>

#define maxtam 20

typedef  int Apontador;

typedef struct 
{
    int pessoas[maxtam];
    Apontador frente;
    Apontador tras;
    int qnt;
}tipofila;


void inicializar(tipofila *f){

    f->frente = 0;
    f->tras = 0;
    f->qnt = 0;
}

void inserir(tipofila *f, int pessoas){

    if (f->qnt >= maxtam)
    {
        printf("fila esta cheia\n");
        return;
    }
    else{
        f->pessoas[f->tras] = pessoas;
        f->tras = (f->tras + 1) % maxtam;
        f->qnt++;
    }
    

}

void atender(tipofila *f){

    if (f->qnt == 0)
    {
        printf("fila esta vazia ERRO\n");   
        return;
    }
    else{
       printf(" Atendendo cliente:%d\n", f->pessoas[f->frente]);
       f->frente = (f->frente  + 1) % maxtam;
       f->qnt--;
    }

}

void proximo(tipofila *f){

    if(f->qnt == 0){
        printf("fila vazia Erro\n");
    }
    else{
            printf("o proximo sera: %d\n", f->pessoas[f->frente]);
    }


}

int main(){

    tipofila fila;

    inicializar(&fila);

    int p, opcao;


    do
    {
        printf("1 -digite um para enserir\n");
        printf("2 para atender\n");
        printf("3 para o proximo \n");
        scanf("%d",&opcao);
        
        switch (opcao)
        {
        case 1:
            printf("digite as pessoas para cadastrar\n");
            scanf("%d",&p);
            inserir(&fila,p);
        break;
        
        case 2:
        atender(&fila);
        break;
    
    case 3:
                proximo(&fila);
    break;


        default:
        printf("encerrando o programa\n");
            break;
        }

    } while (opcao !=0);
    
    return 0;

}