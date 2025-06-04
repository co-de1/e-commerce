#include <stdio.h>
#include <stdlib.h>
#include "crud.h"
#include "pedidos.h"
#include "atendimento.h"


// Esta função apresenta as opções do menu inicial
void menu_inicial(){

        printf("\n\t\t\t\t------- Menu Inicial -------\n");
        printf("\n\t\t\t\t 1. Gestao de Produtos");
        printf("\n\t\t\t\t 2. Processamento de Produtos");
        printf("\n\t\t\t\t 3. Atendimento ao Cliente");
        printf("\n\t\t\t\t 0. Sair\n");

}


// Esta função apresenta as opçoes do CRUD de usarios
void crud_de_usuarios(){


        int opcao2;

        printf("\n\t\t\t\t === MENU ===\n");
        printf("\t\t\t\t 1. Cadastrar Produtos\n");
        printf("\t\t\t\t 2. Listar Produtos\n");
        printf("\t\t\t\t 3. Atualizar Produtos\n");
        printf("\t\t\t\t 4. Apagar Produtos\n");
        printf("\t\t\t\t 5. Voltar ao Menu Inicial\n");
        printf("\t\t\t\t 0. Sair\n");

        printf("\t\t\t\t Escolha: ");
        scanf("%d", &opcao2);

        system("clear");

        switch (opcao2) {
            case 1:
                processamento_de_produtos();
                system("clear"); // Por estar usando linux limpar tela é clear (se usar windows use cls)
                break;
            case 2:
                listarProdutos();
                break;
            case 3:
                atualizarProduto();
                break;
            case 4:
                apagarProduto();
                break;
            case 5:
                return;
                break;
            case 0:
                printf("Saindo...\n");
                exit(0);
            default:
                printf("Opcao invalida.\n");
                crud_de_usuarios();
                break;
        }
}


// Esta função apresenta as opções do atendimento ao  cliente
// Cadastro de reclamações
// Cadastro de Sugestões
// Consultar histórico

void atendimento_ao_cliente(){

        int opcao3;

        printf("\n\t\t\t\t === MENU ===\n");
        printf("\t\t\t\t 1. Cadastrar Reclamacao\n");
        printf("\t\t\t\t 2. Cadastrar Sugestao\n");
        printf("\t\t\t\t 3. Consultar Historico de Mensagens\n");
        printf("\t\t\t\t 4. Voltar no Menu Inicial\n");
        printf("\t\t\t\t 0. Sair\n");

        printf("\t\t\t\t Escolha: ");
        scanf("%d", &opcao3);

        system("clear");

        switch (opcao3){
            case 1:
                cadastrarReclamacao();
                break;
            case 2:
                cadastrarSugestao();
                break;
            case 3:
                consultarHistoricoMensagens();
                break;
            case 4:
                main();
                break;
            case 0:
                printf("Saindo...\n");
                exit(0);
            default:
                system("clear");
                printf("\nOpcao invalida!");
                atendimento_ao_cliente();
                break;

        }

}


// Esta função apresenta as opções do processamento de dados
// Compra de produtos e Consulta

void processamento_de_produtos(){

        int opcao4;

        printf("\n\t\t\t\t === MENU ===\n");
        printf("\t\t\t\t 1. Comprar um Produto\n");
        printf("\t\t\t\t 2. Consultar Produtos Disponiveis\n");
        printf("\t\t\t\t 3. Voltar no Menu Inicial\n");
        printf("\t\t\t\t 0. Sair\n");

        printf("\t\t\t\t Escolha: ");
        scanf("%d", &opcao4);

        system("clear");

        switch (opcao4) {
            case 1:
                processarPedido();
                break;
            case 2:
                listarProdutos();
                break;
            case 3:
                return;
                break;
            case 0:
                printf("Saindo...\n");
                exit(0);
            default:
                printf("Opcao invalida.\n");
                processamento_de_produtos();
                break;
        }
}

int main(){

    int opcao1;

    do {

        menu_inicial();

        printf("\n\t\t\t\t Escolha: ");
        scanf("%d", &opcao1);

        system("clear");

        switch(opcao1){
            case 1:
                crud_de_usuarios();
                break;
            case 2:
                processamento_de_produtos();
                break;
            case 3:
                atendimento_ao_cliente();
                break;
            case 0:
                printf("\nAte a proxima!\n");
                exit(0);
            default:
                system("clear");
                printf("\nOpcao invalida.\n");
                menu_inicial();
                break;
        }

    } while (opcao1 != 0);

    return 0;
}
