// #include <stdio.h>
// #include <stdlib.h>

// #define maxtam 20

// typedef int Apontador;

// typedef struct
// {
//     int pessoa[maxtam];
// } tipoitem;

// typedef struct
// {
//     tipoitem pessoa;
//     Apontador frente;
//     Apontador tras;
// } tipofila;

// // void inicializar(tipofila *f)
// // {

// //     f->frente = 0;
// //     f->tras = 0;
// // }

// void cadastrar(tipofila *f, tipoitem *item)
// {

//     if ((f->tras + 1) % maxtam == f->frente)
//     {
//         printf("fila esta cheia");
//     }

//     else{

//         printf("digite as para cadastrar\n");
//         scanf("%d", &item->pessoa[f->tras]);

//         f->tras = f->tras + 1 % maxtam;


//     }


// }

// void atender(tipofila *f){

//     if (f->frente == f->tras)
//     {
//         printf("fila esta vazia \n");
//     }
//     else{
//         f->tras --;
//     }
    

// }

// void proximo(tipofila *f){

//     if (f->frente == f->tras)
//     {
//         printf("fila esta vazia \n");
//     }
//     else{
//         printf(" o prixmo da fila sera \n", f->frente +1);
//     }
    

// }

// int main()
// {


//     tipofila f;
//     tipoitem item;

//     f.frente = 0;
//     f.tras = 0;

//     cadastrar(&f,&item);

//     return 0;
// }