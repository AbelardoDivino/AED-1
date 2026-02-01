#include<stdio.h>
#include<stdlib.h>

#define maxtam 10


typedef int Apontador;

typedef  struct 
{
    float nota;
    
}tipoitem;

typedef struct 
{
tipoitem nota[maxtam];
Apontador primeiro;
Apontador ultimo;

}tipolista;


void inicializar(tipolista *l){
    l->primeiro = 0;
    l->ultimo = 0;
}

void inserir(tipolista *l, tipoitem nota){

    if (l->ultimo == maxtam)
    {
        printf("lista esta cheia \n");
    }
    else{
        l->nota[l->ultimo] = nota;
        l->ultimo++;
    }

}

void remover(tipolista *l, tipoitem nota){

    if(l->primeiro == l->ultimo){
        printf("lista esta vazia \n");
    }
    else{
        l->nota[l->primeiro] = nota;
        l->primeiro++;
    }

}

void media(tipolista *l){

    float soma = 0;
    float media = 0;

    for (int i = l->primeiro; i < l->ultimo; i++)
    {
        soma += l->nota[i].nota;
        media = soma / (l->ultimo - l->primeiro);
    }
    printf(" A  media das notas e: %.2f\n", media);
}

void menormenor(tipolista *l){

    float menor = l->nota[l->primeiro].nota;
    float maior = l->nota[l->primeiro].nota;

    for (int i = l->primeiro; i < l->ultimo; i++)
    {
        if (l->nota[i].nota < menor)
        {
            menor = l->nota[i].nota;
        }
        
        else if(l->nota[i].nota > maior){
            maior = l->nota[i].nota;
        }

    }
    
    printf(" O menor valor e: %.2f\n", menor);
    printf(" O maior valor e: %.2f\n", maior);

}

int main(){

    int opcao;
    float n;


    tipoitem nota;

    tipolista lista;

    inicializar(&lista);

    do
    {
        printf("\n1 pare enserir\n");
        printf("2 para remover\n");
        printf("3 para calcular a media\n");
        printf("4 para mostrar o menor e o maior valor\n");
        printf("0 para sair\n");
        scanf("%d",&opcao);

        switch (opcao)
        {
        case 1:
                printf("digite as notas:");
                scanf("%f",&n);
                nota.nota = n;
                inserir(&lista,nota);
        break;

        case 2:
            printf("digite a nota para ser removida:\n");
            scanf("%f",&n);
            nota.nota = n;
            remover(&lista,nota);
        break;

        case 3:
            media(&lista);
        break;

        case 4:
            menormenor(&lista);
        break;
        
        default:
        printf("encerrando o programa\n");
            break;
        }
    } while (opcao != 0);
    

    return 0;

}