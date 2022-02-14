#ifndef LISTA_H
#define LISTA_H

#include "evento.h"

typedef struct No No;

    typedef struct caixa{
        cliente* vetor;
        unsigned statusVendedor;
        unsigned fatorAgilidade;
        unsigned identificacao;
        double tempoServico;
    } caixa;


struct No
{
    caixa* Caixa;
    No* prox;
    No* ant;
};

typedef struct lista
{
    No* prim;
    No* ult;
} lista;



lista* criarlista();

void inserirFinalLista(lista* l, caixa* c);

int removerLista(lista* l, int chave);

void fecharCaixa(lista* l, int chave);

int caixaLivre(lista* caixas, int nCaixas);

caixa* criarCaixa(unsigned fatorAgilidade, unsigned medidaDeAgilidade, unsigned identificacao);

void inserirCaixa(caixa* c, cliente* Cliente);

#endif