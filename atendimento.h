#ifndef ATENDIMENTO_H_INCLUDED
#define ATENDIMENTO_H_INCLUDED

#define MAX_NOME 100

typedef struct {
    int id;
    char nome[MAX_NOME];
    float preco;
    int estoque;
} Atendimento;

void cadastrarReclamacao();
void cadastrarSugestao();
void consultarHistoricoMensagens();

#endif // ATENDIMENTO_H_INCLUDED
