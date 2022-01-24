#ifndef CAIXA_H
#define CAIXA_H

#include "cliente.h"

typedef struct caixa{
    cliente* vetor;
    char statusVendedor;
    char fatorAgilidade;
    int identificacao;
    int tempoServico;
} caixa;

caixa criarCaixa(char statusVendedor, char fatorAgilidade, int identificacao, int tempoServico);

void inserirCaixa(caixa* c, cliente Cliente);

void mostrarCaixa(caixa c);

#endif