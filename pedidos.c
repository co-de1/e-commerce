#include <stdio.h>
#include <stdlib.h>
#include "pedidos.h"  // Modulo externo


// Esta função processa o pedido de algum cliente (compra ou consulta)
void processarPedido() {
    int idBusca, quantidade;
    int encontrado = 0;
    Pedido pedido;

    FILE *arquivo = fopen("produtos.txt", "rb");
    FILE *temp = fopen("temp.txt", "wb");
    FILE *registro = fopen("pedidos.txt", "a");  // registro do pedido

    if (!arquivo || !temp || !registro) {
        printf("Erro ao abrir os arquivos.\n");
        return;
    }

    printf("\nDigite o ID do produto que deseja comprar: ");
    scanf("%d", &idBusca);

    printf("Quantidade desejada: ");
    scanf("%d", &quantidade);

    while (fread(&pedido, sizeof(Pedido), 1, arquivo)) {
        if (pedido.id == idBusca) {
            encontrado = 1;

            if (pedido.estoque >= quantidade) {
                pedido.estoque -= quantidade;

                fprintf(registro, "Pedido - ID: %d | Nome: %s | Qtd: %d | Total: R$ %.2f\n",
                        pedido.id, pedido.nome, quantidade, pedido.preco * quantidade);

                printf("\nPedido processado com sucesso!\n");
                printf("Total a pagar: R$ %.2f\n", pedido.preco * quantidade);
            } else {
                printf("\nEstoque insuficiente! Estoque atual: %d\n", pedido.estoque);
            }
        }

        fwrite(&pedido, sizeof(Pedido), 1, temp);  // salva modificado ou não
    }

    fclose(arquivo);
    fclose(temp);
    fclose(registro);

    remove("produtos.txt");
    rename("temp.txt", "produtos.txt");

// Esta função apresenta uma mensagem em caso do produto não ser encontrado
    if (!encontrado) {
        printf("\nProduto com ID %d não encontrado.\n", idBusca);
    }
}
