#ifndef PEDIDOS_H_INCLUDED
#define PEDIDOS_H_INCLUDED

#define MAX_NOME 100

typedef struct {
    int id;
    char nome[MAX_NOME];
    float preco;
    int estoque;
} Pedido;

void processarPedido();

#endif // PEDIDOS_H_INCLUDED
