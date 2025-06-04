#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 1000
#define MAX_NOME 100


// Esta função apresenta os atributos do Objeto produto
typedef struct Dados {
    int id;
    char nome[MAX_NOME];
    float preco;
    int estoque;
} Produto;  // Produto é o nome do tipo

// Esta função apresenta a opção de cadastrar os produtos
void cadastrarProduto() {
    int quantidadeProdutos = MAX_PRODUTOS;
    static int currentId = 0;

    // abre para adicionar no final
    FILE *arquivo = fopen("produtos.txt", "ab");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    printf("\nQuantos produtos vai cadastrar?\nOpcao: ");
    scanf("%d", &quantidadeProdutos);

    for (int i = 0; i < quantidadeProdutos; i++) {
        Produto produto;
        produto.id = ++currentId;

        printf("\n--- Produto %d ---\n", i + 1);
        printf("Nome: ");
        scanf("%s", produto.nome);
        printf("Preço: ");
        scanf("%f", &produto.preco);
        printf("Estoque: ");
        scanf("%d", &produto.estoque);

        fwrite(&produto, sizeof(Produto), 1, arquivo);  // salva no arquivo
    }

    fclose(arquivo);
}

// Esta função lista os produtos
void listarProdutos(){

    // abre para adicionar no final
    FILE *arquivo = fopen("produtos.txt", "rb");
    if (arquivo == NULL) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    Produto produto;

    printf("\n>>>>> Lista de Produtos <<<<<\n");

    while(fread(&produto, sizeof(Produto), 1, arquivo)){
        printf("ID: %d\n", produto.id);
        printf("Nome: %s\n", produto.nome);
        printf("Preço: %.2f\n", produto.preco);
        printf("Estoque: %d\n", produto.estoque);
        printf("------------------------\n");
    }

    fclose(arquivo);
}

// Esta função apresenta a opção de atualizar os produtos
void atualizarProduto() {
    int idBusca;
    int encontrado = 0;
    Produto produto;

    printf("\nDigite o ID do produto que deseja atualizar: ");
    scanf("%d", &idBusca);

    FILE *arquivo = fopen("produtos.txt", "rb");
    FILE *temp = fopen("temp.txt", "wb");

    if (!arquivo || !temp) {
        printf("Erro ao abrir arquivos.\n");
        return;
    }

    while (fread(&produto, sizeof(Produto), 1, arquivo)) {
        if (produto.id == idBusca) {
            encontrado = 1;

            printf("\n--- Produto encontrado ---\n");
            printf("ID: %d\n", produto.id);
            printf("Nome atual: %s\n", produto.nome);
            printf("Preço atual: %.2f\n", produto.preco);
            printf("Estoque atual: %d\n", produto.estoque);

            printf("\n--- Digite os novos dados ---\n");
            printf("Novo nome: ");
            scanf("%s", produto.nome);
            printf("Novo preço: ");
            scanf("%f", &produto.preco);
            printf("Novo estoque: ");
            scanf("%d", &produto.estoque);
        }

        fwrite(&produto, sizeof(Produto), 1, temp);  // Grava produto (editado ou não)
    }

    fclose(arquivo);
    fclose(temp);

    remove("produtos.txt");
    rename("temp.txt", "produtos.txt");

    if (encontrado) {
        printf("\nProduto atualizado com sucesso!\n");
    } else {
        printf("\nProduto com ID %d não encontrado.\n", idBusca);
    }
}

// Esta função apresenta a opção de apagar algum produto específico
void apagarProduto() {
    int idBusca;
    int encontrado = 0;
    Produto produto;

    printf("\nDigite o ID do produto que deseja apagar: ");
    scanf("%d", &idBusca);

    FILE *arquivo = fopen("produtos.txt", "rb");
    FILE *temp = fopen("temp.txt", "wb");

    if (!arquivo || !temp) {
        printf("Erro ao abrir arquivos.\n");
        return;
    }

    while (fread(&produto, sizeof(Produto), 1, arquivo)) {
        if (produto.id == idBusca) {
            encontrado = 1;
            printf("\nProduto com ID %d será removido.\n", produto.id);
            continue;  // pula o produto a ser removido
        }
        fwrite(&produto, sizeof(Produto), 1, temp);  // mantém os outros
    }

    fclose(arquivo);
    fclose(temp);

    remove("produtos.txt");
    rename("temp.txt", "produtos.txt");

    if (encontrado) {
        printf("\nProduto removido com sucesso!\n");
    } else {
        printf("\nProduto com ID %d não encontrado.\n", idBusca);
    }
}
