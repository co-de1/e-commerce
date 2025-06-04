#include <stdio.h>
#include <stdlib.h>
#include "atendimento.h"


// Esta função cadastra reclmação de algum cliente
void cadastrarReclamacao() {
    char nomeCliente[100];
    char reclamacao[500];

    FILE *arquivo = fopen("mensagens.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de reclamações.\n");
        return;
    }

    printf("\nNome do cliente: ");
    getchar(); // limpa buffer do scanf anterior
    fgets(nomeCliente, sizeof(nomeCliente), stdin);
    nomeCliente[strcspn(nomeCliente, "\n")] = '\0'; // remove \n

    printf("Digite sua reclamação:\n");
    fgets(reclamacao, sizeof(reclamacao), stdin);
    reclamacao[strcspn(reclamacao, "\n")] = '\0'; // remove \n

    fprintf(arquivo, "Cliente: %s\nReclamação: %s\n---------------------\n", nomeCliente, reclamacao);

    fclose(arquivo);

    printf("\nReclamação registrada com sucesso!\n");
}

// Esta função cadastra a sugestão de algum cliente
void cadastrarSugestao() {
    char nomeCliente[100];
    char sugestao[500];

    FILE *arquivo = fopen("mensagens.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de sugestões.\n");
        return;
    }

    printf("\nNome do cliente: ");
    getchar(); // limpa o buffer do teclado
    fgets(nomeCliente, sizeof(nomeCliente), stdin);
    nomeCliente[strcspn(nomeCliente, "\n")] = '\0'; // remove o '\n'

    printf("Digite sua sugestão:\n");
    fgets(sugestao, sizeof(sugestao), stdin);
    sugestao[strcspn(sugestao, "\n")] = '\0'; // remove o '\n'

    fprintf(arquivo, "Cliente: %s\nSugestão: %s\n---------------------\n", nomeCliente, sugestao);

    fclose(arquivo);

    printf("\nSugestão registrada com sucesso!\n");
}

// Esta função permite ver o historico de reclmação de algum cliente
void consultarHistoricoMensagens() {
    FILE *arquivo = fopen("mensagens.txt", "r");
    if (arquivo == NULL) {
        printf("Nenhuma mensagem registrada.\n");
        return;
    }

    char linha[512];

    printf("\n>>>>> Histórico de Mensagens <<<<<\n");

    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha);
    }

    fclose(arquivo);
}
