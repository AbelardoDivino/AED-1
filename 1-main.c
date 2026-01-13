// #include<stdio.h>
// #include<stdlib.h>

// #define maxtam 3

// typedef int Apontador;

// typedef struct 
// {
//     int motos;
//     int consumo;
// }tipoitem;

// typedef struct 
// {
//     tipoitem motos[maxtam];
//     tipoitem consumo;
//     Apontador primeiro;
//     Apontador ultimo;
// }tipolista;

// void inicializar(tipolista *l){
//     l->primeiro = 0;
//     l->ultimo = 0;
// }

// void inserir(tipolista *l, tipoitem motos){

// int m1 = 0,m2 = 0,m3 = 0;

//     if (l->ultimo == maxtam)
//     {
//         printf("lista cheia nao pode mais enserir\n");
//     }
//     else{
//         printf("digite o consumo das 3 motos respectivamente\n");
//         scanf("%d %d %d",&m1,&m2,&m3);
//     }
    
//         l->motos[l->ultimo] = motos;
//         l->ultimo++;


// }

// void maiseconomico(tipolista *l, tipoitem consumo){

//     int m = 0;

 

//     for (int i = 0; i < l->ultimo; i++)
//     {
//         if (l->motos[i].consumo < m)
//         {
//                 m = l->motos[i].consumo;
//         }
        
//         l->motos[i].consumo / 100;

//     }
//     printf("quilometros pecorridos : %d\n",m/100);



// }

// int main(){

//     tipolista lista;

//     tipoitem motos;

//     inicializar(&lista);

//     int m1 = 0,m2 = 0,m3 = 0;

//     inserir(&lista, motos);
//     printf("consumo das motos: %d :%d :%d\n",m1,m2,m3);

//     maiseconomico(&lista, motos);

//     return 0;

// }

#include <stdio.h>

#define maxtam 3

typedef struct {
    int modelo;
    int consumo; // km por litro
} tipoitem;

typedef struct {
    tipoitem motos[maxtam];
    int ultimo;
} tipolista;

void inicializar(tipolista *l) {
    l->ultimo = 0;
}

void inserir(tipolista *l) {
    if (l->ultimo == maxtam) {
        printf("Lista cheia!\n");
        return;
    }

    printf("Digite o modelo da moto: ");
    scanf("%d", &l->motos[l->ultimo].modelo);

    printf("Digite o consumo (km por litro): ");
    scanf("%d", &l->motos[l->ultimo].consumo);

    l->ultimo++;
}

void maiseconomico(tipolista *l) {
    int indice = 0;

    for (int i = 1; i < l->ultimo; i++) {
        if (l->motos[i].consumo > l->motos[indice].consumo) {
            indice = i;
        }
    }

    printf("\nMoto mais economica:\n");
    printf("Modelo: %d\n", l->motos[indice].modelo);
}

void consumo100km(tipolista *l) {
    printf("\nConsumo para percorrer 100 km:\n");

    for (int i = 0; i < l->ultimo; i++) {
        float litros = 100.0 / l->motos[i].consumo;
        printf("Moto modelo %d: %.2f litros\n",
               l->motos[i].modelo, litros);
    }
}

int main() {
    tipolista lista;

    inicializar(&lista);

    for (int i = 0; i < maxtam; i++) {
        inserir(&lista);
    }

    maiseconomico(&lista);
    consumo100km(&lista);

    return 0;
}
