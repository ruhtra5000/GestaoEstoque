#pragma once
//Defini��o das estruturas utilizadas
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

//Prot�tipo das fun��es

//Fun��es de inser��o e remo��o retornam 0 ou 1, dependendo da
//inser��o ser realizada com sucesso, ou n�o.
int inserirInicio(produto* p, estoque* e);

int inserirFim(produto* p, estoque* e);

int inserirPosicao(produto* p, int pos, estoque* e);

void listar();

int removerPosicao(int pos, estoque* e);

int removerValor(int id, estoque* e);

//Retorna a posi��o em que o item de ID id est�
//ou -1, caso o id n�o seja encontrado.
int procurar(int id, estoque* e);

int tamanho(estoque* e);

void sair();