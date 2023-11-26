#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estoque.h"

int inserirInicio(produto* p, estoque* e) {
    if (procurar(p->id, e) != -1) {
        printf("O id especificado ja esta cadastrado!\n");
        return 0;
    }
    else {
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
void carregarDados(estoque* e) {
    FILE* arquivo;
    arquivo = fopen("baseDeDados.txt", "r");
    if (arquivo == NULL) {
        printf("\nA base de dados nao foi encontrada!\n");
        system("pause");
    }
    else {
        char linha[50]; //Recebe a linha atual.
        int i = 1; //Indica o dado da linha atual (id, descrição, categoria...).
        produto* temp = malloc(sizeof(produto));
        while (fscanf(arquivo, "%s", linha) != EOF) {
            if (i == 1) {
                //Checa se é necessário realocar memoria, cria um novo produto, 
                //associa seu id, e passa seu endereço para o ponteiro temp.
                realocarMemoria(e);
                produto novo;
                novo.id = atoi(linha);
                temp = &novo;
                i++;
            }
            else if (i == 2) {
                //Associa a descrição do produto.
                strcpy((*temp).descricao, linha);
                i++;
            }
            else if (i == 3) {
                //Associa a categoria do produto.
                (*temp).categoria = atoi(linha);
                i++;
            }
            else if (i == 4) {
                //Associa o valor do produto.
                (*temp).valor = atof(linha);
                i++;
            }
            else if (i == 5) {
                //Associa a quantidade do produto, adiciona o produto no estoque,
                //e aumenta a quantidade de produtos em estoque.
                (*temp).quantidade = atoi(linha);
                e->produtos[e->qtdeProdutos] = *temp;
                e->qtdeProdutos++;
                i = 1;
            }
        }
        fclose(arquivo);
    }
}

//Salvar os dados no arquivo de texto
void salvarDados(estoque* e) {
    FILE* arquivo;
    arquivo = fopen("baseDeDados.txt", "w");
    int i;
    for (i = 0; i < e->qtdeProdutos; i++) {
        //Escreve cada dado de cada produto em uma linha separada.
        fprintf(arquivo, "%d\n%s\n%d\n%f\n%d\n", e->produtos[i].id, e->produtos[i].descricao, 
            e->produtos[i].categoria, e->produtos[i].valor, e->produtos[i].quantidade);
    }
    fclose(arquivo);
}
