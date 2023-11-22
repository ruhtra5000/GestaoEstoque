#include <stdio.h>
#include <stdlib.h>
#include "estoque.h"

int inserirInicio(produto* p, estoque* e) { //NÃO ESTÁ FUNCIONANDO
    e->produtos = realloc(e->produtos, (e->qtdeProdutos + 1) * sizeof(produto));
    int i;
    for (i = e->qtdeProdutos; i > 0; i--) {
        e->produtos[i] = e->produtos[i - 1];
    }
    e->produtos[0] = *p;
    e->qtdeProdutos++;
    return 1;
}

int inserirFim(produto* p, estoque* e) {
    e->produtos = realloc(e->produtos, (e->qtdeProdutos + 1) * sizeof(produto));
    e->produtos[e->qtdeProdutos] = *p;
    e->qtdeProdutos++;
    return 1;
}

int inserirPosicao(produto* p, int pos, estoque* e){

}

void listar(estoque *e){
    if (e->qtdeProdutos < 1) {
        printf("Sem produtos cadastrados!\n");
        system("pause");
    }
    else {
        int i;
        for (i = 0; i < e->qtdeProdutos; i++) {
            printf("ID: %d\n", e->produtos[i].id);
            printf("Descricao: %s\n", e->produtos[i].descricao);
            printf("Categoria: %d\n", e->produtos[i].categoria);
            printf("Valor: R$%.2f\n", e->produtos[i].valor);
            printf("Quantidade: %d\n", e->produtos[i].quantidade);
            printf("=-=-=-=-=-=-=-=-=-=-=-=\n");
        }
        system("pause");
    }
}

int removerPosicao(int pos, estoque* e) {
    if (pos < 0 || pos >= e->qtdeProdutos) {
        printf("Posicao invalida");
        system("pause");
    }
    else {
        if (pos != e->qtdeProdutos - 1) {
            int i;
            for (i = pos; i < (e->qtdeProdutos - 1); i++) {
                e->produtos[i] = e->produtos[i + 1];
            }
        }
        e->produtos = realloc(e->produtos, (e->qtdeProdutos - 1) * sizeof(produto*));
        e->qtdeProdutos--;
    }
}

int removerValor(int id, estoque* e) {//TERMINAR
    int i, posEncontrada;
    for (i = 0; i < e->qtdeProdutos; i++) {

    }
}
