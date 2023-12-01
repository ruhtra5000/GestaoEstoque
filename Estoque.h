#pragma once
//Definição das estruturas utilizadas
typedef struct {
    int id;
    char descricao[50];
    int categoria;
    float valor;
    int quantidade;
} produto;

typedef struct {
    produto* produtos;
    int qtdeProdutos;
} estoque;

//Protótipo das funções

//Funções de inserção e remoção retornam 0 ou 1, dependendo da
//inserção ser realizada com sucesso, ou não.
int inserirInicio(produto* p, estoque* e);

int inserirFim(produto* p, estoque* e);

int inserirPosicao(produto* p, int pos, estoque* e);

void listar(estoque* e);

void listarCategoria(estoque* e, int categoria);

void listarPreco(estoque* e, float pInferior, float pSuperior);

void imprimirDadosProduto(produto p);

int removerPosicao(int pos, estoque* e);

int removerValor(int id, estoque* e);

int procurar(int id, estoque* e);

int tamanho(estoque* e);

void realocarMemoria(estoque* e);

void carregarDados(estoque *e);

void salvarDados(estoque* e);
