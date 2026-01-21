#include<stdio.h>
#include<stdlib.h>

#define maxtam 10

typedef int Apontador;

typedef struct 
{
    int nota;
}tipoitem;


typedef struct 
{
    tipoitem item[maxtam];
    Apontador primeiro;
    Apontador ultimo;
}tipolista;


void inserir(tipolista *l, tipoitem notas){

    if (l->ultimo >= maxtam)
    {
        printf("lista cheia, nao pode mais inserir\n");
    }
    else{
        l->item[l->ultimo] = notas;
        l->ultimo++;
    }

}

// void quant(tipolista *l){

// if (l->primeiro == l->ultimo)
// {
//     printf("A lista está vazia (0 elementos)\n");
// }
// else{
//     int qnt;
    
// }


// }


void qnt2(tipolista *l){

    int qnt2 = l->ultimo - l->primeiro;
    printf("A quantidade de elementos é: %d\n", qnt2);

}

void inverte(tipolista *l){

  if (l->primeiro == l->ultimo)
  {
    printf(" a lista esta vazia\n");
  }
  else{
     
    for (int  i = l->ultimo - 1; i >= l->primeiro; i--)
    {
        printf("%d\n", l->item[i].nota);
    }
    
  }
  
}

void soma(tipolista *l){

    int soma = 0;

    if (l->primeiro == l->ultimo)
    {
        printf("lista vazia");
        return;
    }
    
    else{
        for (int i = l->primeiro; i < l->ultimo; i++)   
        {
            soma += l->item[i].nota;
        }
        
    }
    printf(" A soma e:%d\n",soma);
}

float media(tipolista *l){

    float m = 0;
    int s= 0;

    if (l->primeiro == l->ultimo)
    {
        printf("erro nao ha valores para somar a media\n");
    }
    
    else{
        for (int i = l->primeiro; i < l->ultimo; i++)
        {
            s += l->item[i].nota;

            m = (float)s / (l->ultimo - l->primeiro
            );
        }
        
    }
    printf("A media e:%.2f\n",m);
}

float acimamedia(tipolista *l){

    float m = 0;
    int s= 0;

    if (l->primeiro == l->ultimo)
    {
        printf("erro nao ha valores para somar a media\n");
    }
    
    else{
        for (int i = l->primeiro; i < l->ultimo; i++)
        {
            s += l->item[i].nota;

            m = (float)s / (l->ultimo - l->primeiro
            );
        }
        
    }
    int encontrou = 0;
  
    for (int i = l->primeiro; i < l->ultimo; i++)
    {
        if (l->item[i].nota > m)
        {
            printf("valor acima da media:%d\n",l->item[i].nota);
            encontrou = 1;
        }
        
    }
    
    if(!encontrou){
        printf("nao ha vlores acima da media\n");
        return;

    }

}

void abaixode7(tipolista *l){

    

    float m = 0;
    int s= 0;

    if (l->primeiro == l->ultimo)
    {
        printf("erro nao ha valores para somar a media\n");
    }
    
    else{
        for (int i = l->primeiro; i < l->ultimo; i++)
        {
            s += l->item[i].nota;

            m = (float)s / (l->ultimo - l->primeiro
            );
        }
        
    }
    int encontrou = 0;
  
    for (int i = l->primeiro; i < l->ultimo; i++)
    {
        if (l->item[i].nota < 7)
        {
            printf("valor abaixo de 7:%d\n",l->item[i].nota);
            encontrou = 1;
        }
        
    }
    
    if(!encontrou){
        printf("nao ha valor abaixo de 7\n");
    }

}

int main(){
    tipolista lista;

    lista.primeiro = 0;
    lista.ultimo = 0;

    tipoitem notas;

    int opcao,n;

    do
    {
        printf(" 1 -para enserir:\n");
        printf("2 - quantidade de valores digitados:\n");
        printf("3 - para inverter a lista:\n");
        printf("4 - Para a soma:\n");
        printf("5 - para media:\n");
        printf("6 - acima da media:\n");
        printf("7 - valores abaixo de 7:\n");
        printf("-1 sair:\n");
        scanf("%d",&opcao);
        system("cls");

        switch (opcao)
        {
        case 1:
            printf("digite a nota que quer enserir\n");
            scanf("%d", &n);
            notas.nota = n;
            inserir(&lista, notas);
            break;

            system("cls");

        case 2:
            qnt2(&lista);
            break;
               system("cls");
        
        case 3:
            inverte(&lista);
        break;
           system("cls");

        case 4:
                soma(&lista);
        break;
           system("cls");

        case 5:
                media(&lista);
        break;

        case 6:
                acimamedia(&lista);
        break;

        case 7:
                abaixode7(&lista);
        break;
        
        default:
        printf("Encerrando");
            return 0;

            system("pause");
            system("cls");
        }
    } while (opcao != -1);
    
    return 0;
}
