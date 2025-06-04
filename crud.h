#ifndef PRODUTO_H
#define PRODUTO_H

#define MAX_PRODUTOS 1000
#define MAX_NOME 100

typedef struct {
    int id;
    char nome[MAX_NOME];
    float preco;
    int estoque;
} Produto;

// Declaração da função
void cadastrarProduto();
void listarProdutos();
void atualizarProduto();
void apagarProduto();

#endif
