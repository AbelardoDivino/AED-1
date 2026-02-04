#include<stdio.h>
#include<stdlib.h>
#define maxatam 10
typedef int Apontador;

typedef struct 
{
    int cod[maxatam];
    Apontador primeiro;
    Apontador ultimo;
}tipolista;

void inicializar(tipolista *l){
l->primeiro=0;
l->ultimo=0;
}

void inserir(tipolista *l, int c){

    if (l->ultimo >= maxatam)
    {
        printf("cheia erro\n");
        return;
    }
    else{
        l->cod[l->ultimo] = c;
        l->ultimo++;
    }
    

}


    void remover(tipolista *l){

        if (l->ultimo == l->primeiro)
        {
            printf("erro vazia");
            return;
        }
        else{
            for (int i = l->primeiro; i < l->ultimo; i++)
            {
                l->cod[i] = l->cod[i + 1];
            }
            l->ultimo--;
        }
    }

    void maior(tipolista *l){
        if (l->ultimo == l->primeiro)
        {
            printf("erro\n");
            return;
        }
    
              int maior = l->cod[l->primeiro];
        
            for (int i = l->primeiro + 1; i < l->ultimo; i++)
            {
                
                if (l->cod[i] > maior)
                {
                    maior = l->cod[i];
                }
                

            }
            printf("o maior valor e: %d\n",maior);
        }
        
    

    void menor(tipolista *l){

        if (l->ultimo == l->primeiro)
        {
            printf("erro\n");
            return;
        }
        int menor = l->cod[l->primeiro];
        
        for (int i = l->primeiro; i < l->ultimo; i++)
        {
            if (l->cod[i] < menor)
            {
                menor = l->cod[i];
            }
            
        }
        
        printf(" o menor valor e: %d\n",menor);
    }

    void media(tipolista *l){

        if (l->ultimo == l->primeiro)
        {
            printf("erro\n");
            return;
        }
        else{
                float s = 0,m = 0;
            for (int i = l->primeiro; i < l->ultimo; i++)
            {


                s += l->cod[i];
                m = s / (l->ultimo - l->primeiro);

            }
            
            printf("A media e: %.2f\n",m);
        }
        

    }

    void procurar(tipolista *l, int c){

        if (l->ultimo == l->primeiro)
        {
            printf("erro\n");
            return;
        }
        else{
            for (int i = l->primeiro; i < l->ultimo; i++)
            {
                if (l->cod[i] == c)
                {
                    printf("valor encontrado e: %d\n",l->cod[i]);
                }
                
            }
            
        }
        

    }

    void listar(tipolista *l){

        if (l->ultimo == l->primeiro)
        {
            printf("erro\n");
            return;
        }
        else{
            for (int i = l->primeiro; i < l->ultimo; i++)
            {
                printf("os elementos e: %d\n",l->cod[i]);
            }
            
        }
        

    }

int main(){

tipolista lista;
inicializar(&lista);


int opcao,c;

do
{
    printf("1 inserir\n");
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
        printf("digite os valores para inserir\n");
        scanf("%d",&c);
        inserir(&lista,c);
    break;

    case 2:
        remover(&lista);
    break;

    case 3:
        maior(&lista);
    break;

    case 4:
        menor(&lista);
    break;
    
    case 5:
        media(&lista);
    break;

    case 6:
        printf("digite o valor para procurar\n");
        scanf("%d",&c);
        procurar(&lista,c);
    break;

    case 7:
        listar(&lista);
    break;
    system("pause");
    default:
    printf("Encerrando\n");
    break;
    }

} while (opcao!= 0);


    return 0;
}