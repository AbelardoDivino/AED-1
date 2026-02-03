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
        printf("lista cheia\n");
        return;
    }
    else{
        l->nota[l->ultimo] = n;
        l->ultimo++;
    }
}

void qnt(tipolista *l){
   int qnt2 = l->ultimo - l->primeiro;
    
    if(l->primeiro == l->ultimo)
    {
        printf("lista vazia\n");
        return;
    }
    else{
        printf("a quantidade de elementos cadastrados e: %d\n",qnt2);
    }
    

}

void listar(tipolista *l){

    if (l->ultimo == l->primeiro)
    {
        printf("lista vazia\n");
        return;
    }
    else{
        for (int i = l->primeiro; i < l->ultimo; i++)
        {
            printf(" valores inseridos :%d\n",l->nota[i]);
        }
        
    }
}


void listarinversa(tipolista *l){

    if (l->primeiro == l->ultimo)
    {
        printf("lista vazia\n");
        return;
    }
    else{
        for (int i = l->ultimo - 1; i >= l->primeiro; i--)
        {
            printf(" valores inseridos :%d\n",l->nota[i]);
        }
        
    }
}


void soma(tipolista *l){
int s = 0;
    if (l->ultimo == l->primeiro)
    {
        printf("lista vazia\n");
        return;
    }
    else{
        for (int i = l->primeiro; i < l->ultimo; i++)
        {
           s += l->nota[i];  
        }
        printf("A soma e: %d\n",s);
    }
    

}

void media(tipolista *l){
    int s = 0;
    float m = 0;
    if (l->ultimo == l->primeiro)
    {
        printf("lista vazia\n");
        return;
    }
    else{
           for (int i = l->primeiro; i < l->ultimo; i++)
        {
           s += l->nota[i];  
           m = s / (l->ultimo -l->primeiro);
        }
        printf("A media e: %.2f\n",m);
    }
    
}

void acimamedia(tipolista *l){
       int s = 0;
    float m = 0;
    if (l->ultimo == l->primeiro)
    {
        printf("lista vazia\n");
        return;
    }
    else{
           for (int i = l->primeiro; i < l->ultimo; i++)
        {
           s += l->nota[i];  
           m = s / (l->ultimo -l->primeiro);
        }
        printf("A media e: %.2f\n",m);
    }
  

    for (int i = l->primeiro; i < l->ultimo; i++)
    {
        if (l->nota[i] > m)
        {
            printf("valor acima da media e: %d\n",l->nota[i]);
        }
        
    }
    

}

void abaixo7(tipolista *l){

    if (l->ultimo == l->primeiro)
    {
        printf("lista vazia");
        return;
    }
    else{
        for (int i = l->primeiro; i < l->ultimo; i++)
        {
            if (l->nota[i < 7])
            {
                printf("valores menor que 7 :%d\n", l->nota[i]);
            }
            
        }
        
    }
    

}

int main(){

    tipolista lista;
    inicializar(&lista);

    int opcao,n;

    do
    {
        printf("1 para inserir\n");
        printf("2 - listar \n");
        printf("3 - quantidade de valores lidos\n");
        printf("4 - exibir inverso\n");
        printf(" 5- somar\n");  
        printf(" 6 - media\n");
        printf(" 7 - acima da media\n");
        printf(" 8 - abaixo de 7\n");
        printf(" -1 - sair\n");
        scanf("%d",&opcao);
        switch (opcao)
        {
        case 1:
        printf("digite as 10 notas\n");
        scanf("%d",&n);
        inserir(&lista,n);
        break;
        
        case 2:
            qnt(&lista);
        break;

        case 3:
            listar(&lista);
        break;

        case 4:
            listarinversa(&lista);
        break;

        case 5:
            soma(&lista);
        break;

        case 6:
            media(&lista);
        break;

        case 7:
            acimamedia(&lista);
        break;

        case 8:
            abaixo7(&lista);
        break;

        default:
        printf("encerrando\n");
        break;
        }
    } while (opcao != -1);
    

    return 0;
}