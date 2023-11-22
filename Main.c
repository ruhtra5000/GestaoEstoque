#include <stdio.h>
#include <stdlib.h>
#include "Estoque.h"

int main() {
    //Estoque
    estoque est;
    est.produtos = malloc(sizeof(produto));
    est.qtdeProdutos = 0;
    
    //Variaveis do menu
    int opc = 0, opc2 = 0; 
    
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

                if(opc2 == 1){
                    inserirInicio(&prod, &est);
                }
                else if(opc2 == 2){
                    inserirFim(&prod, &est);
                }
                else if(opc2 == 3){
                    inserirPosicao(&prod, 0, &est); //MUDAR
                }
                else {
                    printf("Comando invalido");
                    system("pause");
                }
            break;
            case 2:
                listar(&est);
            break;
            case 3:
                system("cls");
                printf("1. Remover por valor\n2. Remover por id\n");
                scanf("%d", &opc2);
            break;
            case 4:
            
            break;
            case 5:
            
            break;
            case 6:
                
            break;
            default:
                printf("Comando inválido\n");
                system("pause");
            break;
        } 
    }

    /*
    - Finalizar a inserção no inicio
    - Finalizar o menu
    - Finalizar as funções
    - Checar as funções de remoção
    */

    return 0;
}

