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
    int qtd;

    inicializar(&lista);

    printf("Quantas motos deseja cadastrar? (max %d): ", maxtam);
    scanf("%d", &qtd);

    if (qtd > maxtam) {
        printf("Quantidade excede o limite da lista!\n");
        return 0;
    }

    for (int i = 0; i < qtd; i++) {
        inserir(&lista);
    }

    maiseconomico(&lista);
    consumo100km(&lista);

    return 0;
}

