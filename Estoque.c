#include <stdio.h>
#include <stdlib.h>
#include "estoque.h"

int inserirInicio(produto* p, estoque* e) {
    if (procurar(p->id, e) != -1) {
        printf("O id especificado ja esta cadastrado!\n");
        return 0;
    }
    else {
        //e->produtos = realloc(e->produtos, (e->qtdeProdutos + 1) * sizeof(produto));
        realocarMemoria(e);
        int i;
        for (i = e->qtdeProdutos; i > 0; i--) {
            e->produtos[i] = e->produtos[i - 1];
        }
        e->produtos[0] = *p;
        e->qtdeProdutos++;
        return 1;
    }
}

int inserirFim(produto* p, estoque* e) {
    if (procurar(p->id, e) != -1) {
        printf("O id especificado ja esta cadastrado!\n");
        return 0;
    }
    else {
        //e->produtos = realloc(e->produtos, (e->qtdeProdutos + 1) * sizeof(produto));
        realocarMemoria(e);
        e->produtos[e->qtdeProdutos] = *p;
        e->qtdeProdutos++;
        return 1;
    }
}

int inserirPosicao(produto* p, int pos, estoque* e){
    if (procurar(p->id, e) != -1) {
        printf("O id especificado ja esta cadastrado!\n");
        return 0;
    }
    else if (pos < 0 || pos > e->qtdeProdutos) {
        printf("A posicao especificada nao existe!\n");
        return 0;
    }
    else {
        realocarMemoria(e);
        int i;
        for (i = e->qtdeProdutos; i > pos; i--) {
            e->produtos[i] = e->produtos[i - 1];
        }
        e->produtos[pos] = *p;
        e->qtdeProdutos++;
        return 1;
    }
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
    if (e->qtdeProdutos == 0) {
        printf("Sem produtos no estoque!\n");
        return 0;
    }
    else if (pos < 0 || pos > e->qtdeProdutos) {
        printf("A posicao especificada nao existe!\n");
        return 0;
    }
    else {
        if (pos != e->qtdeProdutos - 1) {
            int i;
            for (i = pos; i < e->qtdeProdutos; i++) {
                e->produtos[i] = e->produtos[i + 1];
            }
        }
        //e->produtos = realloc(e->produtos, (e->qtdeProdutos - 1) * sizeof(produto));
        e->qtdeProdutos--;
        return 1;
    }
}

int removerValor(int id, estoque* e) {
    if (e->qtdeProdutos == 0) {
        printf("Sem produtos no estoque!\n");
        return 0;
    }
    
    int pos = procurar(id, e);
    if (pos == -1) {
        printf("O id especificado nao existe!\n");
        return 0;
    }
    else {
        //Reutilização da função removerPosicao em
        //conjunto com a função procurar
        return removerPosicao(pos, e);
    }
}

//Retorna o indice do elemento com o id especificado
//Ou -1, caso o elemento não seja encontrado.
int procurar(int id, estoque* e) { 
    for (int i = 0; i < e->qtdeProdutos; i++) {
        if (e->produtos[i].id == id) {
            return i;
        }
    }
    return -1;
}

//Retorna o tamanho do estoque
int tamanho(estoque* e) {
    return e->qtdeProdutos;
}

//Aloca memoria de 10 em 10
void realocarMemoria(estoque* e) {
    int i;
    for (i = 10; i <= (e->qtdeProdutos + 1); i += 10) {
        if ((e->qtdeProdutos + 1)  == i) {
            e->produtos = realloc(e->produtos, (i + 10) * sizeof(produto));
            return;
        }
    }
}

//Carregar os dados do arquivo de texto
void entrar(estoque* e) {
    FILE* arquivo;
    arquivo = fopen("baseDeDados.txt", "r");
    if (arquivo == NULL) {
        printf("\nA base de dados nao foi encontrada!\n");
        system("pause");
    }
    else {

    }

    fclose(arquivo);
}

//Salvar os dados no arquivo de texto
void sair(estoque* e) {
    FILE* arquivo;
    arquivo = fopen("baseDeDados.txt", "w");
    fprintf(arquivo, "teste massa");
    fclose(arquivo);
}
