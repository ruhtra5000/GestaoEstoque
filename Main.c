#include <stdio.h>
#include <stdlib.h>
#include "Estoque.h"

int main() {
    //Estoque
    estoque est;
    est.produtos = malloc(10 * sizeof(produto));
    est.qtdeProdutos = 0;
    carregarDados(&est);
    
    //Variaveis do menu
    int opc = 0, opc2 = 0, posicao = 0, tmp = 0; 
    
    //Menu
    while(opc != 6){
        system("cls");
        printf("<= GESTAO DE ESTOQUE =>\n\n1. Inserir produto\n2. Listar produtos\n");
        printf("3. Remover produto\n4. Procurar produto\n5. Tamanho do estoque\n6. Sair\n");
        scanf("%d", &opc);
        
        switch(opc){
            case 1:
                system("cls");
                printf("1. Inserir no inicio\n2. Inserir no fim\n3. Inserir em uma posicao\n");
                scanf("%d", &opc2);

                //Capturando dados do produto
                produto prod;
                printf("Informe o ID do produto: ");
                scanf("%d", &prod.id);
                printf("Informe a descricao do produto: ");
                scanf(" %[^\n]s", prod.descricao);
                printf("Informe a categoria do produto: ");
                scanf("%d", &prod.categoria);
                printf("Informe o valor do produto: ");
                scanf("%f", &prod.valor);
                printf("Informe o quantidade do produto: ");
                scanf("%d", &prod.quantidade);

                tmp = 0;
                if (opc2 == 1) {
                    tmp = inserirInicio(&prod, &est);
                }
                else if (opc2 == 2) {
                    tmp = inserirFim(&prod, &est);
                }
                else if(opc2 == 3){
                    printf("Informe a posicao para adicionar: ");
                    scanf("%d", &posicao);
                    tmp = inserirPosicao(&prod, posicao, &est);
                }
                else {
                    printf("Comando invalido");
                }

                //Checagem de inserção realizada
                if (tmp == 1) {
                    printf("\nInsercao realizada com sucesso!\n");
                    salvarDados(&est);
                }
                system("pause");
            break;
            case 2:
                system("cls");
                printf("1. Listar todos\n2. Listar por categoria\n3. Listar por preco\n");
                scanf("%d", &opc2);
                if (opc2 == 1) {
                    listar(&est);
                }
                else if (opc2 == 2) {
                    printf("\nInforme a categoria que deseja listar: ");
                    scanf("%d", &posicao);//posicao esta assumindo o valor da categoria
                    listarCategoria(&est, posicao);
                }
                else if (opc2 == 3) {
                    float p1, p2;
                    printf("\nInforme o valor inferior: ");
                    scanf("%f", &p1);
                    printf("\nInforme o valor superior: ");
                    scanf("%f", &p2);
                    listarPreco(&est, p1, p2);
                }
                else {
                    printf("Comando invalido\n");
                    system("pause");
                }
            break;
            case 3:
                system("cls");
                printf("1. Remover por posicao\n2. Remover por id\n");
                scanf("%d", &opc2);
                if (opc2 == 1) {
                    printf("\nInforme a posicao que deseja remover: ");
                    scanf("%d", &posicao);
                    tmp = removerPosicao(posicao, &est);
                }
                else if (opc2 == 2) {
                    printf("\nInforme o ID que deseja remover: ");
                    scanf("%d", &posicao);//posicao está assumindo o valor do ID
                    tmp = removerValor(posicao, &est);
                }
                else {
                    printf("Comando invalido\n");
                }

                //Checagem de remoção realizada
                if (tmp == 1) {
                    printf("Remocao realizada com sucesso!\n");
                    salvarDados(&est);
                }
                system("pause");
            break;
            case 4:
                system("cls");
                printf("Informe o ID que deseja buscar: ");
                scanf("%d", &posicao);//posicao está assumindo o valor de ID
                tmp = procurar(posicao, &est);
                
                if (tmp == -1) {
                    printf("O ID especificado nao existe!\n");
                }
                else {
                    printf("O elemento com ID %d se encontra na posicao %d\n", posicao, tmp);
                }
                system("pause");
            break;
            case 5:
                system("cls");
                printf("O estoque contem %d produtos\n", tamanho(&est));
                system("pause");
            break;
            case 6:
                salvarDados(&est);
            break;
            default:
                printf("Comando invalido\n");
                system("pause");
            break;
        } 
    }

    return 0;
}

