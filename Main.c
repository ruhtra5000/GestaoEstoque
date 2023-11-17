#include <stdio.h>
#include <stdlib.h>
#include "estoque.h"

int main() {
    estoque est;
    est.produtos = malloc(sizeof(produto*));
    est.qtdeProdutos = 0;

    produto prod;
    prod.id = 1;
    scanf("%s", prod.descricao);
    prod.categoria = 1;
    prod.valor = 2.99;
    prod.quantidade = 5;

    
    if(inserirFim(&prod, &est)){
        printf("ohmaigo");
    }
    if (inserirFim(&prod, &est)) {
        printf("ohmaigo2");
    } 
    if (inserirInicio(&prod, &est)) {
        printf("ohmaigo3");
    }
    if (inserirInicio(&prod, &est)) {
        printf("ohmaigo4");
    }

    return 0;
}