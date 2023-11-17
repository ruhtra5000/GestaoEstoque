#include <stdio.h>
#include <stdlib.h>
#include "estoque.h"

int inserirInicio(produto* p, estoque* e) {
    e->produtos = realloc(e->produtos, (e->qtdeProdutos + 1) * sizeof(produto*));
    int i;
    for (i = e->qtdeProdutos + 1; i > 0; i--) {
        e->produtos[i] = e->produtos[i - 1];
    }
    e->produtos[0] = *p;
    e->qtdeProdutos++;
    return 1;
}

int inserirFim(produto* p, estoque* e) {
    e->produtos = realloc(e->produtos, (e->qtdeProdutos + 1) * sizeof(produto*));
    e->produtos[e->qtdeProdutos] = *p;
    e->qtdeProdutos++;
    return 1;
}

int inserirPosicao(produto* p, int pos, estoque* e){

}

void listar(estoque *e){

}
