#include "crud.h"
#include <stdio.h>

int main() {
    Product stock[MAX_PRODUTOS];
    int total = 0;
    int opcao;
    
    do {
        printf("\n=== MENU ===\n");
        printf("1. Criar produto\n");
        printf("2. Listar produtos\n");
        printf("3. Atualizar produto\n");
        printf("4. Deletar produto\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1: criarProduto(stock, &total);
            break;
            case 2: listarProdutos(stock, total);
            break;
            case 3: atualizarProduto(stock, total);
            break;
            case 4: deletarProduto(stock, &total); 
            break;
        }
    } while(opcao != 0);
    
    return 0;
}