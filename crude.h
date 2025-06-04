#ifndef CRUD_H_INCLUDED
#define CRUD_H_INCLUDED


typedef struct {
    int id;
    char nome[100];
    float preco;
    int estoque;
} Produto;

void addProduto();
void listProduto();
void attProduto();
void deleteProduto();

#endif // CRUD_H_INCLUDED
